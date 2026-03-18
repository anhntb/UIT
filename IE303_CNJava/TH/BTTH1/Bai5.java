import java.util.Scanner;

public class Bai5 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Nhap chuoi s1: ");
        String s1 = scanner.nextLine();
        
        System.out.print("Nhap chuoi s2: ");
        String s2 = scanner.nextLine();
        
        // 1. Cho biết tổng chiều dài 2 chuỗi s1 và s2
        int tongChieuDai = s1.length() + s2.length();
        System.out.println("Tong chieu dai 2 chuoi: " + tongChieuDai);
        
        // 2. Lấy 3 ký tự đầu tiên chuỗi s1
        if (s1.length() >= 3) {
            String ba_ky_tu_dau_s1 = s1.substring(0, 3);
            System.out.println("3 ky tu dau chuoi s1: " + ba_ky_tu_dau_s1);
        } else {
            System.out.println("Chuoi s1 khong du 3 ky tu");
        }
        
        // 3. Lấy 3 ký tự cuối của chuỗi s2
        if (s2.length() >= 3) {
            String ba_ky_tu_cuoi_s2 = s2.substring(s2.length() - 3);
            System.out.println("3 ky tu cuoi chuoi s2: " + ba_ky_tu_cuoi_s2);
        } else {
            System.out.println("Chuoi s2 khong du 3 ky tu");
        }
        
        // 4. Lấy ký tự thứ 6 của chuỗi s1
        if (s1.length() >= 6) {
            char kyTu6 = s1.charAt(5); // index 5 = ký tự thứ 6
            System.out.println("Ky tu thu 6 cua chuoi s1: " + kyTu6);
        } else {
            System.out.println("Chuoi s1 khong co ky tu thu 6");
        }
        
        // 5. Kiểm tra 2 chuỗi s1 và s2 có bằng nhau không?
        if (s1.equals(s2)) {
            System.out.println("2 chuoi s1 va s2 bang nhau");
        } else {
            System.out.println("2 chuoi s1 va s2 khong bang nhau");
        }
        
        // 6. Cho biết s2 có xuất hiện trong s1 hay không? Nếu có thì ở vị trí nào?
        int viTri = s1.indexOf(s2);
        if (viTri != -1) {
            System.out.println("s2 xuat hien trong s1 tai vi tri: " + viTri);
        } else {
            System.out.println("s2 khong xuat hien trong s1");
        }
        
        scanner.close();
    }
}
