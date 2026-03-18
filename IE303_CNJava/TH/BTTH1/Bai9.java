import java.util.Arrays;
import java.util.Scanner;

public class Bai9 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Nhap so luong cong dan N: ");
        int N = scanner.nextInt();
        
        // Tạo mảng công dân từ 0 đến N-1
        int[] congDan = new int[N];
        for (int i = 0; i < N; i++) {
            congDan[i] = i;
        }
        
        // Xáo trộn mảng để tạo người tiếp xúc ngẫu nhiên
        int[] contacted = new int[N];
        for (int i = 0; i < N; i++) {
            contacted[i] = i;
        }
        
        // Thuật toán xáo trộn Fisher-Yates
        for (int i = N - 1; i > 0; i--) {
            int j = (int) (Math.random() * (i + 1));
            // Swap contacted[i] và contacted[j]
            int temp = contacted[i];
            contacted[i] = contacted[j];
            contacted[j] = temp;
        }
        
        // In ra bảng Id và Contacted
        System.out.print("\nId       ");
        for (int i = 0; i < N; i++) {
            System.out.printf("%3d ", i);
        }
        System.out.println();
        
        System.out.print("Contacted");
        for (int i = 0; i < N; i++) {
            System.out.printf("%3d ", contacted[i]);
        }
        System.out.println();
        
        // Tìm các nhóm lây nhiễm (sử dụng Union-Find hoặc DFS)
        boolean[] visited = new boolean[N];
        int groupCount = 0;
        
        System.out.println();
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                System.out.print("Group " + groupCount + ": ");
                
                // Duyệt chuỗi lây nhiễm
                int current = i;
                while (!visited[current]) {
                    System.out.print(current + " ");
                    visited[current] = true;
                    current = contacted[current];
                }
                
                System.out.println();
                groupCount++;
            }
        }
        
        System.out.println("Number of groups = " + groupCount);
        
        scanner.close();
    }
}
