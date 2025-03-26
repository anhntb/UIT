/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author NTB Anh
 */
import java.util.Scanner;
import java.util.Arrays;

public class BTVN_Cau6 {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        // TODO code application logic here
        Scanner scanner = new Scanner(System.in);
                
        // Enter array size
        System.out.print("Nhap so dong (n): ");
        int n = scanner.nextInt();
        System.out.print("Nhap so cot (m): ");
        int m = scanner.nextInt();

        int[][] A = new int[n][m];

        // Enter array elements
        System.out.println("Nhap cac phan tu (1-99): ");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int value;
                do {
                    value = scanner.nextInt();
                    if (value < 1 || value >= 100) {
                        System.out.println("Vui long nhap so 1-99!");
                    }
                } while (value < 1 || value >= 100);
                A[i][j] = value;
            }
        }
        scanner.close();

        // Print array
        System.out.println("Mang ban dau:");
        printMatrix(A);
        
        // Find max element and index
        findMax(A);

        // Find prime numbers and replace non-prime with 0
        replaceNonPrimes(A);

        // Sort columns in ascending order
        sortColumns(A);

        // Print array after sort
        System.out.println("Mang sau khi sap xep cot:");
        printMatrix(A);
    }

    // Find max element Funtion
    public static void findMax(int[][] A) {
        int max = A[0][0];
        int rowIndex = 0, colIndex = 0;

        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A[i].length; j++) {
                if (A[i][j] > max) {
                    max = A[i][j];
                    rowIndex = i;
                    colIndex = j;
                }
            }
        }

        System.out.println("Phan tu lon nhat: " + max + " o vi tri [" + rowIndex + "][" + colIndex + "]\n");
    }

    // Check prime number Function
    public static boolean isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    // "Replace non-prime numbers with 0" Function
    public static void replaceNonPrimes(int[][] A) {
        System.out.println("Mang sau khi replace non-prime bang 0:");
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A[i].length; j++) {
                if (!isPrime(A[i][j])) {
                    A[i][j] = 0;
                }
                System.out.print(A[i][j] + "\t");
            }
            System.out.println();
        }
    }

    // Sort columns in ascending order
    public static void sortColumns(int[][] A) {
        for (int j = 0; j < A[0].length; j++) {
            int[] column = new int[A.length];
            for (int i = 0; i < A.length; i++) {
                column[i] = A[i][j];
            }
            Arrays.sort(column);
            for (int i = 0; i < A.length; i++) {
                A[i][j] = column[i];
            }
        }
    }

    // Hàm in mảng
    public static void printMatrix(int[][] A) {
        for (int[] row : A) {
            for (int value : row) {
                System.out.print(value + "\t");
            }
            System.out.println();
        }
    }
}
