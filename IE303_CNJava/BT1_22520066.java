import java.util.Scanner;

public class BT1_22520066 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Nhập số giây
        System.out.print("Nhap so giay: ");
        int totalSeconds = sc.nextInt();
            
        // Tính giờ, phút, giây
        int hours = totalSeconds / 3600;
        int minutes = (totalSeconds % 3600) / 60;
        int seconds = totalSeconds % 60;
        
        // In kết quả
        System.out.println("So Gio : " + hours);
        System.out.println("So Phut : " + minutes);
        System.out.println("So Giay : " + seconds);
        
        sc.close();
    }
}
