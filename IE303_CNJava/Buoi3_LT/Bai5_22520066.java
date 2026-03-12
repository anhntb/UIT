package Buoi3_LT;

import java.util.Scanner;

public class Bai5_22520066 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Nhap so hang m cua ma tran M: ");
        int m = sc.nextInt();
        System.out.print("Nhap so cot n cua ma tran M: ");
        int n = sc.nextInt();
        
        double[][] M = new double[m][n];
        
        System.out.println("Nhap cac phan tu cua ma tran M (" + m + "x" + n + "):");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print("M[" + i + "][" + j + "]: ");
                M[i][j] = sc.nextDouble();
            }
        }
        
        System.out.println("\nMa tran M ban dau:");
        inMaTran(M);
        
        // a. Tim phan tu chan duong nho nhat trong ma tran
        System.out.println("\n--- Cau a ---");
        double minChanDuong = timPhanTuChanDuongNhoNhat(M);
        if (minChanDuong != Double.MAX_VALUE) {
            System.out.println("Phan tu chan duong nho nhat: " + minChanDuong);
        } else {
            System.out.println("Khong co phan tu chan duong trong ma tran");
        }
        
        // b. Tinh gia tri trung binh cua cac phan tu nho nhat tren moi cot
        System.out.println("\n--- Cau b ---");
        double tbPhanTuNhoNhatCot = tinhTrungBinhPhanTuNhoNhatMoiCot(M);
        System.out.println("Gia tri trung binh cua cac phan tu nho nhat tren moi cot: " + tbPhanTuNhoNhatCot);
        
        // c. Xoa dong co tong lon nhat trong ma tran
        System.out.println("\n--- Cau c ---");
        double[][] M_afterDelete = xoaDongCoTongLonNhat(M);
        System.out.println("Ma tran sau khi xoa dong co tong lon nhat:");
        inMaTran(M_afterDelete);
        
        // d. Kiem tra ma tran vuong, tam giac tren/duoi
        System.out.println("\n--- Cau d ---");
        kiemTraMaTran(M);
        
        // e. Tao ma tran N va tinh tich M va N
        System.out.println("\n--- Cau e ---");
        double[][] N = new double[n][m];
        System.out.println("Nhap cac phan tu cua ma tran N (" + n + "x" + m + "):");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print("N[" + i + "][" + j + "]: ");
                N[i][j] = sc.nextDouble();
            }
        }
        
        System.out.println("\nMa tran N:");
        inMaTran(N);
        
        double[][] tichMN = tinhTichMaTran(M, N);
        if (tichMN != null) {
            System.out.println("\nTich cua ma tran M va N:");
            inMaTran(tichMN);
            
            // f. Chuyen vi ma tran tich
            System.out.println("\n--- Cau f ---");
            double[][] chuyenViTich = chuyenViMaTran(tichMN);
            System.out.println("Chuyen vi cua ma tran tich:");
            inMaTran(chuyenViTich);
        }
        
        sc.close();
    }
    
    // Ham in ma tran
    public static void inMaTran(double[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.printf("%.2f\t", matrix[i][j]);
            }
            System.out.println();
        }
    }
    
    // a. Tim phan tu chan duong nho nhat
    public static double timPhanTuChanDuongNhoNhat(double[][] matrix) {
        double min = Double.MAX_VALUE;
        boolean found = false;
        
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                // Kiem tra so chan duong (so nguyen duong chia het cho 2)
                if (matrix[i][j] > 0 && matrix[i][j] == (int)matrix[i][j] && (int)matrix[i][j] % 2 == 0) {
                    if (matrix[i][j] < min) {
                        min = matrix[i][j];
                        found = true;
                    }
                }
            }
        }
        
        return found ? min : Double.MAX_VALUE;
    }
    
    // b. Tinh trung binh cac phan tu nho nhat tren moi cot
    public static double tinhTrungBinhPhanTuNhoNhatMoiCot(double[][] matrix) {
        int soCot = matrix[0].length;
        double tong = 0;
        
        for (int j = 0; j < soCot; j++) {
            double minCot = matrix[0][j];
            for (int i = 1; i < matrix.length; i++) {
                if (matrix[i][j] < minCot) {
                    minCot = matrix[i][j];
                }
            }
            tong += minCot;
        }
        
        return tong / soCot;
    }
    
    // c. Xoa dong co tong lon nhat
    public static double[][] xoaDongCoTongLonNhat(double[][] matrix) {
        int dongMax = 0;
        double tongMax = tinhTongDong(matrix, 0);
        
        for (int i = 1; i < matrix.length; i++) {
            double tong = tinhTongDong(matrix, i);
            if (tong > tongMax) {
                tongMax = tong;
                dongMax = i;
            }
        }
        
        System.out.println("Dong co tong lon nhat la dong " + dongMax + " voi tong = " + tongMax);
        
        // Tao ma tran moi khong co dong max
        double[][] maTranMoi = new double[matrix.length - 1][matrix[0].length];
        int idxMoi = 0;
        for (int i = 0; i < matrix.length; i++) {
            if (i != dongMax) {
                maTranMoi[idxMoi] = matrix[i].clone();
                idxMoi++;
            }
        }
        
        return maTranMoi;
    }
    
    // Ham tinh tong mot dong
    public static double tinhTongDong(double[][] matrix, int dong) {
        double tong = 0;
        for (int j = 0; j < matrix[dong].length; j++) {
            tong += matrix[dong][j];
        }
        return tong;
    }
    
    // d. Kiem tra ma tran vuong, tam giac tren/duoi
    public static void kiemTraMaTran(double[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        
        if (rows == cols) {
            System.out.println("M la ma tran vuong (kich thuoc " + rows + "x" + cols + ")");
            
            // Kiem tra tam giac tren
            boolean laTamGiacTren = true;
            for (int i = 1; i < rows; i++) {
                for (int j = 0; j < i; j++) {
                    if (matrix[i][j] != 0) {
                        laTamGiacTren = false;
                        break;
                    }
                }
                if (!laTamGiacTren) break;
            }
            
            // Kiem tra tam giac duoi
            boolean laTamGiacDuoi = true;
            for (int i = 0; i < rows; i++) {
                for (int j = i + 1; j < cols; j++) {
                    if (matrix[i][j] != 0) {
                        laTamGiacDuoi = false;
                        break;
                    }
                }
                if (!laTamGiacDuoi) break;
            }
            
            if (laTamGiacTren) {
                System.out.println("M la ma tran tam giac tren");
            } else if (laTamGiacDuoi) {
                System.out.println("M la ma tran tam giac duoi");
            } else {
                System.out.println("M khong phai la ma tran tam giac");
            }
        } else {
            System.out.println("M khong phai la ma tran vuong");
        }
    }
    
    // e. Tinh tich hai ma tran
    public static double[][] tinhTichMaTran(double[][] M, double[][] N) {
        int rowsM = M.length;
        int colsM = M[0].length;
        int rowsN = N.length;
        int colsN = N[0].length;
        
        if (colsM != rowsN) {
            System.out.println("Khong the nhan hai ma tran (so cot M != so dong N)");
            return null;
        }
        
        double[][] tich = new double[rowsM][colsN];
        
        for (int i = 0; i < rowsM; i++) {
            for (int j = 0; j < colsN; j++) {
                tich[i][j] = 0;
                for (int k = 0; k < colsM; k++) {
                    tich[i][j] += M[i][k] * N[k][j];
                }
            }
        }
        
        return tich;
    }
    
    // f. Chuyen vi ma tran
    public static double[][] chuyenViMaTran(double[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        
        double[][] chuyenVi = new double[cols][rows];
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                chuyenVi[j][i] = matrix[i][j];
            }
        }
        
        return chuyenVi;
    }
}
