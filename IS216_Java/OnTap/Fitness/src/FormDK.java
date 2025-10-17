import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import java.util.*;

public class FormDK extends JFrame {
    private Connection conn;
    private JTextField txtMaHV, txtTenHV;
    private JList<String> listGoiTap;
    private DefaultTableModel model;
    private JTable table;
    private JButton btnThem;

    private HashMap<String, String> goiTapMap = new HashMap<>(); // TenGoi -> MaGoi

    public FormDK(Connection conn) {
        this.conn = conn;
        initUI();
        loadGoiTap();
    }

    private void initUI() {
        setTitle("Thêm đăng ký gói tập");
        setSize(600, 400);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(new BorderLayout(10, 10));

        JPanel topPanel = new JPanel(new GridLayout(1, 4, 10, 10));
        txtMaHV = new JTextField();
        txtTenHV = new JTextField(); txtTenHV.setEditable(false);
        topPanel.add(new JLabel("Mã Hội viên:"));
        topPanel.add(txtMaHV);
        topPanel.add(new JLabel("Tên Hội viên:"));
        topPanel.add(txtTenHV);

        txtMaHV.addActionListener(e -> loadTenHoiVien());

        JPanel centerPanel = new JPanel(new GridLayout(1, 2, 10, 10));
        listGoiTap = new JList<>();
        JScrollPane listScroll = new JScrollPane(listGoiTap);
        listScroll.setBorder(BorderFactory.createTitledBorder("Các gói tập"));

        model = new DefaultTableModel(new Object[]{"Gói tập đăng ký", "Số buổi đăng ký"}, 0);
        table = new JTable(model);
        JScrollPane tableScroll = new JScrollPane(table);
        tableScroll.setBorder(BorderFactory.createTitledBorder("Gói tập được đăng ký"));

        listGoiTap.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                String selected = listGoiTap.getSelectedValue();
                if (selected != null && !isGoiTapAdded(selected)) {
                    model.addRow(new Object[]{selected, ""});
                }
            }
        });

        centerPanel.add(listScroll);
        centerPanel.add(tableScroll);

        btnThem = new JButton("Thêm");
        btnThem.addActionListener(e -> themDangKy());

        add(topPanel, BorderLayout.NORTH);
        add(centerPanel, BorderLayout.CENTER);
        add(btnThem, BorderLayout.SOUTH);
    }

    private void loadTenHoiVien() {
        String maHV = txtMaHV.getText().trim();
        try {
            PreparedStatement ps = conn.prepareStatement("SELECT TenHV FROM HOIVIEN WHERE MaHV = ?");
            ps.setString(1, maHV);
            ResultSet rs = ps.executeQuery();
            if (rs.next()) {
                txtTenHV.setText(rs.getString("TenHV"));
            } else {
                JOptionPane.showMessageDialog(this, "Không tìm thấy hội viên.");
                txtTenHV.setText("");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void loadGoiTap() {
        try {
            PreparedStatement ps = conn.prepareStatement("SELECT MaGoi, TenGoi FROM GOITAP");
            ResultSet rs = ps.executeQuery();
            DefaultListModel<String> listModel = new DefaultListModel<>();
            while (rs.next()) {
                String maGoi = rs.getString("MaGoi");
                String tenGoi = rs.getString("TenGoi");
                goiTapMap.put(tenGoi, maGoi);
                listModel.addElement(tenGoi);
            }
            listGoiTap.setModel(listModel);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private boolean isGoiTapAdded(String tenGoi) {
        for (int i = 0; i < model.getRowCount(); i++) {
            if (tenGoi.equals(model.getValueAt(i, 0))) return true;
        }
        return false;
    }

    private void themDangKy() {
        String maHV = txtMaHV.getText();
        // if (maHV.isEmpty() || txtTenHV.getText().isEmpty()) {
        //     JOptionPane.showMessageDialog(this, "Vui lòng nhập Mã hội viên hợp lệ.");
        //     return;
        // }

        try {
            for (int i = 0; i < model.getRowCount(); i++) {
                String tenGoi = (String) model.getValueAt(i, 0);
                String soBuoiStr = (String) model.getValueAt(i, 1);
                // if (soBuoiStr == null || soBuoiStr.trim().isEmpty()) {
                //     JOptionPane.showMessageDialog(this, "Vui lòng nhập số buổi cho gói tập: " + tenGoi);
                //     return;
                // }
                int soBuoi = Integer.parseInt(soBuoiStr.trim());
                // if (soBuoi <= 0) {
                //     JOptionPane.showMessageDialog(this, "Số buổi phải > 0 cho gói: " + tenGoi);
                //     return;
                // }

                String maGoi = goiTapMap.get(tenGoi);
                
                // TODO: Xử lý thêm MaDK tự động
                PreparedStatement ps = conn.prepareStatement(
                    "INSERT INTO DANGKY (MaHV, MaGoi, SoBuoiDK, SoBuoiConLai) VALUES (?, ?, ?, ?)"
                );
                ps.setString(1, maHV);
                ps.setString(2, maGoi);
                ps.setInt(3, soBuoi);
                ps.setInt(4, soBuoi);
                ps.executeUpdate();
            }

            JOptionPane.showMessageDialog(this, "Đăng ký thành công!");
            model.setRowCount(0); // clear table sau khi thêm
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Số buổi phải là số nguyên.");
        } catch (SQLException ex) {
            ex.printStackTrace();
            JOptionPane.showMessageDialog(this, "Lỗi khi thêm dữ liệu.");
        }
    }
}
