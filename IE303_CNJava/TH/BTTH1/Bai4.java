import java.util.Scanner;

public class Bai4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Nhap so nguyen duong n: ");
        int n = scanner.nextInt();
        
        if (n <= 0) {
            System.out.println("Vui long nhap so nguyen duong!");
            scanner.close();
            return;
        }
        
        // 1. Liệt kê các ước số của n
        System.out.print("Cac uoc so cua " + n + ": ");
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
        
        // 2. Cho biết n có bao nhiêu chữ số
        int soChuSo = String.valueOf(n).length();
        System.out.println("So " + n + " co " + soChuSo + " chu so");
        
        // 3. Kiểm tra n phải là số đối xứng không
        String str = String.valueOf(n);
        String strReverse = new StringBuilder(str).reverse().toString();
        if (str.equals(strReverse)) {
            System.out.println("So " + n + " la so doi xung");
        } else {
            System.out.println("So " + n + " khong phai la so doi xung");
        }
        
        // 4. Kiểm tra n là số chính phương không
        int sqrt = (int) Math.sqrt(n);
        if (sqrt * sqrt == n) {
            System.out.println("So " + n + " la so chinh phuong");
        } else {
            System.out.println("So " + n + " khong phai la so chinh phuong");
        }
        
        scanner.close();
    }
}
