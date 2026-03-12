package Buoi3_LT;

public class Bai3_22520066 {
    public static void main(String[] args) {
        int rows = 23;
        int cols = 35;
        
        // Tọa độ hình chữ nhật đỏ
        int redStartRow = 4;
        int redEndRow = 18;
        int redStartCol = 6;
        int redEndCol = 28;
        
        // Vẽ từng hàng
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Kiểm tra xem có nằm trong vùng đỏ không
                if (i >= redStartRow && i <= redEndRow && j >= redStartCol && j <= redEndCol) {
                    // Tính tọa độ tương đối so với góc trên bên trái của hình chữ nhật đỏ
                    int relRow = i - redStartRow;
                    int relCol = j - redStartCol;
                    
                    // Kiểm tra xem có phải ngôi sao vàng không
                    if (isYellowStar(relRow, relCol)) {
                        System.out.print("*");  // Ô vàng - in khoảng trắng
                    } else {
                        System.out.print("=");  // Ô đỏ - in dấu +
                    }
                } else {
                    // Vùng trắng - bỏ qua (in khoảng trắng)
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
    
    // Hàm kiểm tra xem vị trí có phải là ngôi sao vàng không
    private static boolean isYellowStar(int row, int col) {
        // Mảng 2D định nghĩa hình dạng ngôi sao (1 = vàng, 0 = đỏ)
        int[][] star = {
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,1,1,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        };
        
        // Kiểm tra nếu tọa độ nằm trong phạm vi của mảng star
        if (row >= 0 && row < star.length && col >= 0 && col < star[0].length) {
            return star[row][col] == 1;
        }
        return false;
    }
}
