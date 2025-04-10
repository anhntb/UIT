package BTTLp1_Cau2;

import java.util.Scanner;

public class HinhChuNhat {
    private double chieuDai;
    private double chieuRong;

    // Constructor 0 tham số
    public HinhChuNhat() {
        this.chieuDai = 0;
        this.chieuRong = 0;
    }
    
    // Constructor 1 tham số
    public HinhChuNhat(double chieuDai) {
        this.chieuDai = chieuDai;
        this.chieuRong = 0;
    }
    
    // Constructor 2 tham số
    public HinhChuNhat(double chieuDai, double chieuRong) {
        this.chieuDai = chieuDai;
        this.chieuRong = chieuRong;
    }

    // Getter
    public double getChieuDai() {
        return chieuDai;
    }

    public double getChieuRong() {
        return chieuRong;
    }

    // Setter
    public void setChieuDai(double chieuDai) {
        this.chieuDai = chieuDai;
    }

    public void setChieuRong(double chieuRong) {
        this.chieuRong = chieuRong;
    }

    // Tính diện tích
    public double dienTich() {
        return chieuDai * chieuRong;
    }

    // Tính chu vi
    public double chuVi() {
        return 2 * (chieuDai + chieuRong);
    }
    
    // Nhập thông tin hình chữ nhật
    public void input() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhap chieu dai: ");
        this.chieuDai = scanner.nextDouble();

        System.out.print("Nhap chieu rong: ");
        this.chieuRong = scanner.nextDouble();
    }

    // Xuất thông tin hình chữ nhật
    @Override
    public String toString() {
        return "Chieu dai: " + chieuDai + "\nChieu rong: " + chieuRong +
               "\nDien tich: " + dienTich() + "\nChu vi: " + chuVi();
    }

    public static void main(String[] args) {
        HinhChuNhat hcn = new HinhChuNhat();
        hcn.input();
        System.out.println("\nThong tin hinh chu nhat:");
        System.out.println(hcn);
    }
}
