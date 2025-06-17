package qlkb;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import java.text.SimpleDateFormat;
import java.util.Vector;


public class ThanhToanForm extends JFrame {
    private JTextField txtMaBN, txtTenBN, txtKetLuan, txtYeuCau, txtTongTien;
    private JTable tableDichVu;
    private JCheckBox chkDaThanhToan;
    private JButton btnThanhToan;
    private JSpinner spnNgayKham;

    public ThanhToanForm() {
        setTitle("Thanh toán khám bệnh");
        setSize(700, 300);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        JPanel topPanel = new JPanel(new GridLayout(4, 4, 10, 5));
        txtMaBN = new JTextField();
        txtTenBN = new JTextField(); txtTenBN.setEditable(false);
        txtKetLuan = new JTextField(); txtKetLuan.setEditable(false);
        txtYeuCau = new JTextField(); txtYeuCau.setEditable(false);
        txtTongTien = new JTextField(); txtTongTien.setEditable(false);

        spnNgayKham = new JSpinner(new SpinnerDateModel());
        spnNgayKham.setEditor(new JSpinner.DateEditor(spnNgayKham, "yyyy-MM-dd"));
        
        chkDaThanhToan = new JCheckBox("Đã thanh toán");
        chkDaThanhToan.setEnabled(false);

        topPanel.add(new JLabel("Mã bệnh nhân:"));
        topPanel.add(txtMaBN);
        topPanel.add(new JLabel("Ngày khám:"));
        topPanel.add(spnNgayKham);

        topPanel.add(new JLabel("Tên bệnh nhân:"));
        topPanel.add(txtTenBN);
        topPanel.add(new JLabel("Yêu cầu khám:"));
        topPanel.add(txtYeuCau);

        topPanel.add(new JLabel("Kết luận:"));
        topPanel.add(txtKetLuan);
        topPanel.add(new JLabel("Tổng tiền:"));
        topPanel.add(txtTongTien);
        
        topPanel.add(new JLabel("Danh sách dịch vụ đã khám"));
        topPanel.add(new JLabel(""));
        topPanel.add(chkDaThanhToan);
        topPanel.add(new JLabel(""));
        
        JPanel topPanel2 = new JPanel(new GridLayout(2, 3));
        btnThanhToan = new JButton("Thanh toán");
        topPanel2.add(new JLabel(""));
        topPanel2.add(btnThanhToan);
        topPanel2.add(new JLabel(""));
        topPanel2.add(new JLabel(""));
        topPanel2.add(new JLabel(""));
            
        add(topPanel, BorderLayout.NORTH);
        add(topPanel2, BorderLayout.SOUTH);

        tableDichVu = new JTable();
        JScrollPane scrollPane = new JScrollPane(tableDichVu);
        add(scrollPane, BorderLayout.CENTER);

        txtMaBN.addActionListener(e -> loadTenBenhNhan());
        spnNgayKham.addChangeListener(e -> loadThongTinKham());

        btnThanhToan.addActionListener(e -> thanhToan());

    }

    private void loadTenBenhNhan() {
        try (Connection con = DBConnect.getConnection()) {
            String sql = "SELECT TENBN FROM BENHNHAN WHERE MABN = ?";
            PreparedStatement stmt = con.prepareStatement(sql);
            stmt.setString(1, txtMaBN.getText().trim());
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                txtTenBN.setText(rs.getString("TENBN"));
            } else {
                txtTenBN.setText("");
                JOptionPane.showMessageDialog(this, "Không tìm thấy bệnh nhân");
            }
            rs.close();
            stmt.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    private void loadThongTinKham() {
        try (Connection con = DBConnect.getConnection()) {
            String sql = """
                SELECT kb.YEUCAUKHAM, kb.KETLUAN, kb.THANHTOAN, dv.TENDV, tp.SOLUONG, (tp.SOLUONG * dv.DONGIA) AS THANHTIEN
                FROM KHAMBENH kb
                JOIN THUPHI tp ON kb.MAKB = tp.MAKB
                JOIN DICHVU dv ON dv.MADV = tp.MADV
                WHERE kb.MABN = ? AND kb.NGAYKHAM = ?
            """;

            PreparedStatement stmt = con.prepareStatement(sql);
            stmt.setString(1, txtMaBN.getText().trim());
            java.sql.Date ngayKham = new java.sql.Date(((java.util.Date) spnNgayKham.getValue()).getTime());
            stmt.setDate(2, ngayKham);

            ResultSet rs = stmt.executeQuery();

            DefaultTableModel model = new DefaultTableModel(new String[]{"Tên dịch vụ", "Số lượng", "Thành tiền"}, 0);
            int tongTien = 0;
            boolean found = false;

            while (rs.next()) {
                found = true;
                String yeuCau = rs.getString("YEUCAUKHAM");
                String ketLuan = rs.getString("KETLUAN");
                boolean daThanhToan = rs.getBoolean("THANHTOAN");

                txtYeuCau.setText(yeuCau);
                txtKetLuan.setText(ketLuan);
                chkDaThanhToan.setSelected(daThanhToan);
                //chkDaThanhToan.setEnabled(!daThanhToan);
                btnThanhToan.setEnabled(!daThanhToan);

                Vector<Object> row = new Vector<>();
                row.add(rs.getString("TENDV"));
                row.add(rs.getInt("SOLUONG"));
                int thanhTien = rs.getInt("THANHTIEN");
                row.add(thanhTien);
                tongTien += thanhTien;
                model.addRow(row);
            }

            tableDichVu.setModel(model);
            txtTongTien.setText(String.valueOf(tongTien));

            if (!found) {
                txtYeuCau.setText("");
                txtKetLuan.setText("");
                txtTongTien.setText("0");
                chkDaThanhToan.setSelected(false);
                chkDaThanhToan.setEnabled(false);
                btnThanhToan.setEnabled(false);
                model.setRowCount(0);
                JOptionPane.showMessageDialog(this, "Không có thông tin khám bệnh");
            }

            rs.close();
            stmt.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    private void thanhToan() {
        try (Connection con = DBConnect.getConnection()) {
            String sql = """
                UPDATE KHAMBENH SET THANHTOAN = TRUE
                WHERE MABN = ? AND NGAYKHAM = ?
            """;

            PreparedStatement stmt = con.prepareStatement(sql);
            stmt.setString(1, txtMaBN.getText().trim());
            java.sql.Date ngayKham = new java.sql.Date(((java.util.Date) spnNgayKham.getValue()).getTime());
            stmt.setDate(2, ngayKham);

            int rows = stmt.executeUpdate();
            if (rows > 0) {
                JOptionPane.showMessageDialog(this, "Thanh toán thành công");
                chkDaThanhToan.setSelected(true);
                chkDaThanhToan.setEnabled(false);
                btnThanhToan.setEnabled(false);
            } else {
                JOptionPane.showMessageDialog(this, "Không thể cập nhật trạng thái thanh toán");
            }

            stmt.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
