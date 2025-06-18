// * Bài 1: Viết hàm nhập vào bán kinh hình tròn và chu vi hình tròn đó.



public class HinhTron {
    
    private double banKinh;

    // * Constructor
    public HinhTron() {
        this.banKinh = 0.0;
    }

    public HinhTron(double banKinh) {
        this.banKinh = banKinh;
    }

    // * Function
    public double tinhChuvi() {
        return 2 * Math.PI * banKinh;
    }
}
