import java.util.Arrays;
import java.util.Scanner;

public class Bai7 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Nhập mảng A
        System.out.print("Nhap kich thuoc mang A (n): ");
        int n = scanner.nextInt();
        int[] A = new int[n];
        
        System.out.println("Nhap cac phan tu mang A:");
        for (int i = 0; i < n; i++) {
            System.out.print("A[" + i + "]: ");
            A[i] = scanner.nextInt();
        }
        
        // 1. Tạo mảng số nguyên B (kích thước m) với các giá trị ngẫu nhiên
        System.out.print("Nhap kich thuoc mang B (m): ");
        int m = scanner.nextInt();
        int[] B = new int[m];
        
        for (int i = 0; i < m; i++) {
            B[i] = (int) (Math.random() * 100); // Số ngẫu nhiên từ 0-99
        }
        
        // 2. Xuất toàn bộ các phần tử của B ra màn hình
        System.out.println("Mang B: " + Arrays.toString(B));
        
        // 3. Tạo mảng C từ mảng A
        int[] C = Arrays.copyOf(A, A.length);
        System.out.println("Mang C (copy tu A): " + Arrays.toString(C));
        
        // 4. Thay thế phần tử thứ 1 đến 3 của mảng C bằng 3 phần tử cuối của mảng B
        if (C.length >= 3 && B.length >= 3) {
            System.arraycopy(B, B.length - 3, C, 0, 3);
            System.out.println("Mang C sau khi thay the 3 phan tu dau: " + Arrays.toString(C));
        } else {
            System.out.println("Mang C hoac B khong du 3 phan tu de thay the");
        }
        
        // 5. Sắp xếp mảng C tăng dần và xuất ra màn hình
        Arrays.sort(C);
        System.out.println("Mang C sau khi sap xep tang dan: " + Arrays.toString(C));
        
        scanner.close();
    }
}
