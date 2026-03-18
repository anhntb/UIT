import java.util.Scanner;

public class Bai2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Nhap x: ");
        double x = scanner.nextDouble();
        
        System.out.print("Nhap n: ");
        int n = scanner.nextInt();
        
        double sum = 0;
        
        for (int i = 1; i <= n; i++) {
            double tu = Math.pow(x, i);
            double mau = i * (i + 1) / 2.0;
            sum += tu / mau;
        }
        
        System.out.println("S(" + n + ") = " + sum);
        
        scanner.close();
    }
}
