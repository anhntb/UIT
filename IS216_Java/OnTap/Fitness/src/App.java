import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import javax.swing.SwingUtilities;

public class App {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/fitness"; 
        String user = "root";
        String password = "mySQLuser@@5";

        // TODO: Xử lý đóng mở kết nối CSDL
        
        try {
            Connection conn = DriverManager.getConnection(url, user, password);
            System.out.println("Success!");

            // * Form thêm huấn luyện viên
            // SwingUtilities.invokeLater(() -> new FormThemHLV(conn).setVisible(true));
            
            // * Check-in tập luyện
            // SwingUtilities.invokeLater(() -> new FormCheckin(conn).setVisible(true));

            // * Thêm đăng ký gói tập

            
        } catch (SQLException e) {
            System.out.println("Fail!");
            e.printStackTrace();
        }
    }
}