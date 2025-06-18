// * Bài tập Thực hành tại lớp Lab 1
// * Done: 1 2 

import java.util.Scanner;

public class App {

    // * Bài 2: Tính a/b
    public static double tinhThuong(double a, double b) {
        if (b == 0) {
            System.out.println("Loi: Khong the chia cho 0");
            return Double.NaN; // Trả về NaN nếu b là 0
        }
        return a / b;
    }

    public static void main(String[] args) {
        Scanner sc =  new Scanner(System.in);

        // * Bài 1
        System.out.println("\n===Bai 1===");
        System.out.print("Nhap ban kinh: ");
        HinhTron ht = new HinhTron(sc.nextDouble());
        System.out.println("Chu vi hinh tron: " + ht.tinhChuvi());

        // * Bài 2
        System.out.println("\n===Bai 2===");
        System.out.print("Nhap a: ");
        double a = sc.nextDouble();
        System.out.print("Nhap b: ");   
        double b = sc.nextDouble();
        System.out.printf("Thuong a/b: %.3f", tinhThuong(a, b));
        
        sc.close();
    }
}