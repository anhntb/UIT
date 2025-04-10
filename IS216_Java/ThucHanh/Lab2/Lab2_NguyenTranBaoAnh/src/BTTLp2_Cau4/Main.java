package BTTLp2_Cau4;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Xe xeMay = new XeMay();
        Xe xeTai = new XeTai();

        // Đổ xăng
        System.out.println("--- Do xang ---");
        System.out.print("Xe may: ");
        xeMay.doXang(sc.nextDouble());
        System.out.print("Xe tai: ");
        xeTai.doXang(sc.nextDouble());

        // Thêm hàng
        System.out.println("--- Them hang ---");
        System.out.print("Xe may: ");
        xeMay.themHang(sc.nextDouble());
        System.out.print("Xe tai: ");
        xeTai.themHang(sc.nextDouble());
        
        // Bớt hàng
        System.out.println("--- Bot hang ---");
        System.out.print("Xe may: ");
        xeMay.botHang(sc.nextDouble());
        System.out.print("Xe tai: ");
        xeTai.botHang(sc.nextDouble());
        
        // Kiểm tra tải trọng
        System.out.println("--- Tai trong hien tai ---");
        System.out.println("Xe may: " + xeMay.getTaiTrong());
        System.out.println("Xe tai: " + xeTai.getTaiTrong());       

        // Cho xe chạy
        System.out.println("--- Cho xe chay mot quang duong (km) ---");
        System.out.print("Xe may: ");
        xeMay.chay(sc.nextDouble()); 
        System.out.print("Xe tai: ");
        xeTai.chay(sc.nextDouble()); 

        // In kết quả
        System.out.println("--- Luong xang con lai ---");
        System.out.println("Xe may con lai: " + xeMay.getXang() + " lit xang");
        System.out.println("Xe tai con lai: " + xeTai.getXang() + " lit xang");

        // Kiểm tra hết xăng
        System.out.println("--- Kiem tra het xang ---");
        System.out.println("Xe may het xang? " + (xeMay.hetXang() ? "Het" : "Con"));
        System.out.println("Xe tai het xang? " + (xeTai.hetXang() ? "Het" : "Con"));

        sc.close();
    }
}


