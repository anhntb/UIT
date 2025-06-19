import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import java.util.*;

public class FormCheckin extends JFrame {
    private Connection conn;
    private JTextField txtMaHV, txtTenHV;
    private JComboBox<String> cbGoiTap, cbHLV;
    private JTextField txtNgayTap, txtGioTap;
    private JButton btnThem;

    private HashMap<String, String> goiTapMap = new HashMap<>();  // TenGoi -> MaGoi
    private HashMap<String, String> hlvMap = new HashMap<>();     // BietDanh -> MaHLV

    public FormCheckin(Connection conn) {
        this.conn = conn;
        initUI();
        loadHLVs();
    }

    private void initUI() {
        setTitle("Check-in tập luyện");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(new GridLayout(7, 2, 5, 5));

        txtMaHV = new JTextField();
        txtTenHV = new JTextField(); txtTenHV.setEditable(false);
        cbGoiTap = new JComboBox<>();
        cbHLV = new JComboBox<>();
        txtNgayTap = new JTextField(java.time.LocalDate.now().toString());
        txtGioTap = new JTextField("18:00");
        btnThem = new JButton("Thêm");

        add(new JLabel("Mã Hội viên:"));
        add(txtMaHV);
        add(new JLabel("Tên Hội viên:"));
        add(txtTenHV);
        add(new JLabel("Tên gói tập:"));
        add(cbGoiTap); 
        add(new JLabel("Huấn luyện viên:"));
        add(cbHLV);
        add(new JLabel("Ngày tập:"));
        add(txtNgayTap);
        add(new JLabel("Giờ tập:"));
        add(txtGioTap);
        add(new JLabel(""));
        add(btnThem);

        txtMaHV.addActionListener(e -> loadHoiVienVaGoiTap());
        btnThem.addActionListener(e -> themCheckin());
    }

    private void loadHoiVienVaGoiTap() {
        try {
            String maHV = txtMaHV.getText();
            PreparedStatement ps = conn.prepareStatement("SELECT TenHV FROM HOIVIEN WHERE MaHV = ?");
            ps.setString(1, maHV);
            ResultSet rs = ps.executeQuery();
            if (rs.next()) {
                txtTenHV.setText(rs.getString("TenHV"));
                loadGoiTap(maHV);
            } else {
                JOptionPane.showMessageDialog(this, "Không tìm thấy hội viên.");
                txtTenHV.setText("");
                cbGoiTap.removeAllItems();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void loadGoiTap(String maHV) {
        cbGoiTap.removeAllItems();
        goiTapMap.clear();
        try {
            PreparedStatement ps = conn.prepareStatement(
                "SELECT DANGKY.MaGoi, GOITAP.TenGoi " +
                "FROM DANGKY JOIN GOITAP ON DANGKY.MaGoi = GOITAP.MaGoi " +
                "WHERE MaHV = ? AND SoBuoiConLai > 0"
            );
            ps.setString(1, maHV);
            ResultSet rs = ps.executeQuery();
            while (rs.next()) {
                String maGoi = rs.getString("MaGoi");
                String tenGoi = rs.getString("TenGoi");
                cbGoiTap.addItem(tenGoi);
                goiTapMap.put(tenGoi, maGoi);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void loadHLVs() {
        try {
            PreparedStatement ps = conn.prepareStatement("SELECT MaHLV, BietDanh FROM HLV");
            ResultSet rs = ps.executeQuery();
            while (rs.next()) {
                String ma = rs.getString("MaHLV");
                String ten = rs.getString("BietDanh");
                cbHLV.addItem(ten);
                hlvMap.put(ten, ma);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void themCheckin() {
        try {
            String maHV = txtMaHV.getText();
            String tenGoi = (String) cbGoiTap.getSelectedItem();
            String bietDanh = (String) cbHLV.getSelectedItem();
            String ngayTap = txtNgayTap.getText();
            String gioTap = txtGioTap.getText();

            // if (tenGoi == null || bietDanh == null) {
            //     JOptionPane.showMessageDialog(this, "Vui lòng chọn đầy đủ gói tập và huấn luyện viên.");
            //     return;
            // }

            String maGoi = goiTapMap.get(tenGoi);
            String maHLV = hlvMap.get(bietDanh);

            // Lấy mã đăng ký
            PreparedStatement psDK = conn.prepareStatement(
                "SELECT MaDK, SoBuoiConLai FROM DANGKY WHERE MaHV = ? AND MaGoi = ?"
            );
            psDK.setString(1, maHV);
            psDK.setString(2, maGoi);
            ResultSet rsDK = psDK.executeQuery();

            if (rsDK.next()) {
                String maDK = rsDK.getString("MaDK");
                int soConLai = rsDK.getInt("SoBuoiConLai");

                if (soConLai <= 0) {
                    JOptionPane.showMessageDialog(this, "Gói tập này đã hết lượt tập.");
                    return;
                }

                // Thêm bản ghi vào bảng TAP
                PreparedStatement psTap = conn.prepareStatement(
                    "INSERT INTO TAP (MaDK, MaHLV, NgayTap, GioTap) VALUES (?, ?, ?, ?)"
                );
                psTap.setString(1, maDK);
                psTap.setString(2, maHLV);
                psTap.setString(3, ngayTap);
                psTap.setString(4, gioTap);
                psTap.executeUpdate();

                // Trừ 1 buổi
                PreparedStatement psUpdate = conn.prepareStatement(
                    "UPDATE DANGKY SET SoBuoiConLai = SoBuoiConLai - 1 WHERE MaDK = ?"
                );
                psUpdate.setString(1, maDK);
                psUpdate.executeUpdate();

                JOptionPane.showMessageDialog(this, "Thêm thành công!");
            } else {
                JOptionPane.showMessageDialog(this, "Không tìm thấy thông tin đăng ký.");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
