package Xe;

public abstract class Xe {
    protected double xang;      // Lít xăng hiện tại
    protected double taiTrong;  // Tổng khối lượng hàng (kg)

    // Constructor 0 tham số
    public Xe() {
        this.xang = 0;
        this.taiTrong = 0;
    }
    
    // Constructor 1 tham số
    public Xe(double xang) {
        this.xang = xang;
        this.taiTrong = 0;
    }
    
    // Constructor 2 tham số
    public Xe(double xang, double taiTrong) {
        this.xang = xang;
        this.taiTrong = taiTrong;
    }
    
    // Getter
    public double getXang() {
        return xang;
    }
    
    public double getTaiTrong() {
        return taiTrong;
    }
    
    // Setter
    public void setXang(double xang) {
        this.xang = xang;
    }
    
    public void setTaiTrong(double taiTrong) {
        this.taiTrong = taiTrong;
    }

    // Đổ xăng
    public void doXang(double soLit) {
        this.xang += soLit;
    }

    // Thêm 1 lượng hàng
    public void themHang(double khoiLuong) {
        this.taiTrong += khoiLuong;
    }

    // Bớt một lượng hàng
    public void botHang(double khoiLuong) {
        this.taiTrong = Math.max(0, this.taiTrong - khoiLuong); // Đảm bảo giá trị tải trọng luôn >= 0
    }

    // Cho xe chạy 1 đoạn đường
    public abstract void chay(double quangDuong);  // km

    // Kiểm tra xe hết xăng hay chưa
    public boolean hetXang() {
        return xang <= 0;
    }
}
