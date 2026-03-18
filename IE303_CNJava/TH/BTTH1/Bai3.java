import java.util.Scanner;

public class Bai3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Nhap canh a: ");
        double a = scanner.nextDouble();
        
        System.out.print("Nhap canh b: ");
        double b = scanner.nextDouble();
        
        System.out.print("Nhap canh c: ");
        double c = scanner.nextDouble();
        
        // Kiểm tra điều kiện tam giác
        if (a + b > c && b + c > a && a + c > b && a > 0 && b > 0 && c > 0) {
            // Tính chu vi
            double chuVi = a + b + c;
            
            // Tính diện tích theo công thức Heron
            double p = chuVi / 2;
            double dienTich = Math.sqrt(p * (p - a) * (p - b) * (p - c));
            
            System.out.println("Chu vi tam giac: " + chuVi);
            System.out.println("Dien tich tam giac: " + dienTich);
        } else {
            System.out.println("Ba canh khong tao thanh tam giac!");
        }
        
        scanner.close();
    }
}
