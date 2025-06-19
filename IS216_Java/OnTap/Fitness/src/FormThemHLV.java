import javax.swing.*;
import java.awt.*;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class FormThemHLV extends JFrame {
    private Connection conn;
    private JTextField txtTen, txtCCCD, txtSDT, txtBietDanh;
    private JComboBox<String> cbGioiTinh;
    private JButton btnThem;

    public FormThemHLV(Connection conn) {
        this.conn = conn; // Kết nối CSDL được truyền vào từ App.java
        
        setTitle("Thêm mới Huấn luyện viên (PT)");
        setSize(350, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(new GridLayout(6, 2, 5, 5));

        add(new JLabel("Tên Huấn luyện viên:"));
        txtTen = new JTextField();
        add(txtTen);

        add(new JLabel("Giới tính:"));
        cbGioiTinh = new JComboBox<>(new String[]{"Nam", "Nữ"});
        add(cbGioiTinh);

        add(new JLabel("Số CCCD:"));
        txtCCCD = new JTextField();
        add(txtCCCD);

        add(new JLabel("Số điện thoại:"));
        txtSDT = new JTextField();
        add(txtSDT);

        add(new JLabel("Biệt danh (nickname):"));
        txtBietDanh = new JTextField();
        add(txtBietDanh);

        btnThem = new JButton("Thêm");
        add(btnThem);
        add(new JLabel()); // chỗ trống

        btnThem.addActionListener(e -> themHLV());
    }

    private void themHLV() {
        String ten = txtTen.getText();
        String gioiTinh = cbGioiTinh.getSelectedItem().toString();
        String cccd = txtCCCD.getText();
        String sdt = txtSDT.getText();
        String bietDanh = txtBietDanh.getText();

        // if (ten.isEmpty() || cccd.isEmpty() || sdt.isEmpty()) {
        //     JOptionPane.showMessageDialog(this, "Vui lòng nhập đầy đủ thông tin bắt buộc!");
        //     return;
        // }

        String sql = "INSERT INTO HLV (MaHLV, TenHLV, GioiTinh, CCCD, SoDT, BietDanh) VALUES (?, ?, ?, ?, ?, ?)";

        try (Connection conn = this.conn) {
            // Sinh MaHLV tự động (ví dụ: HLV01, HLV02...)
            String maHLV = taoMaHLV(conn);
            PreparedStatement ps = conn.prepareStatement(sql);
            ps.setString(1, maHLV);
            ps.setString(2, ten);
            ps.setString(3, gioiTinh);
            ps.setString(4, cccd);
            ps.setString(5, sdt);
            ps.setString(6, bietDanh);
            int kq = ps.executeUpdate();
            if (kq > 0) {
                JOptionPane.showMessageDialog(this, "Thêm thành công! Mã HLV: " + maHLV);
                txtTen.setText(""); txtCCCD.setText(""); txtSDT.setText(""); txtBietDanh.setText("");
            } else {
                JOptionPane.showMessageDialog(this, "Thêm thất bại!");
            }
        } catch (SQLException ex) {
            JOptionPane.showMessageDialog(this, "Lỗi kết nối hoặc truy vấn CSDL!\n" + ex.getMessage());
        }
    }

    // Hàm sinh mã HLV tự động dạng HLV01, HLV02...
    private String taoMaHLV(Connection conn) throws SQLException {
        var rs = conn.createStatement().executeQuery("SELECT MaHLV FROM HLV ORDER BY MaHLV DESC LIMIT 1");
        String ma = "HLV01";
        if (rs.next()) {
            String last = rs.getString(1); // ví dụ: HLV05
            int num = Integer.parseInt(last.replaceAll("\\D", "")) + 1;
            ma = String.format("HLV%02d", num);
        }
        return ma;
    }

}
