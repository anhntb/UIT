package BT;
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author NTB Anh
 */
import java.util.Scanner;

public class BTrenLop_Cau7 {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        
        int n;
        try ( // TODO code application logic here
            Scanner scanner = new Scanner(System.in)) {
            System.out.print("Nhap so nguyen duong: ");
            n = scanner.nextInt();
        }

        if (n <= 1) {
            System.out.println(n + " khong phai la so nguyen to.");
            return;
        }

        boolean isPrime = true;
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            System.out.println(n + " la so nguyen to.");
        } else {
            System.out.println(n + " khong phai la so nguyen to.");
        }
    }
}
