import java.util.Scanner;

public class Bai8 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Nhap gia tri n (0 den n): ");
        int n = scanner.nextInt();
        
        // Tạo số bí mật ngẫu nhiên từ 0 đến n
        int soBiMat = (int) (Math.random() * (n + 1));
        
        int min = 0;
        int max = n;
        
        System.out.println("Bat dau tro choi doan so!");
        System.out.println("So bi mat nam trong khoang (" + min + ", " + max + ")");
        
        while (true) {
            // Kiểm tra nếu chỉ còn một số trong khoảng
            if (max - min == 0) {
                System.out.println("Ban da thua! So bi mat la: " + soBiMat);
                break;
            }
            
            System.out.print("(" + min + ", " + max + ")? ");
            int doan = scanner.nextInt();
            
            // Kiểm tra ngoài phạm vi
            if (doan < min || doan > max) {
                System.out.println("Out of range. Try again?");
                continue;
            }
            
            // Kiểm tra đoán đúng
            if (doan == soBiMat) {
                System.out.println("Bingo!");
                break;
            }
            
            // Cập nhật khoảng
            if (doan < soBiMat) {
                min = doan + 1;
                System.out.println("Too small.");
            } else {
                max = doan - 1;
                System.out.println("Too large.");
            }
        }
        
        scanner.close();
    }
}
