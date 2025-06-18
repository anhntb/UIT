/**
 * * Viết chương trình cho phép nhập thông tin sinh viên bao gồm tên và địa chỉ.
 * * Chương trình sẽ in ra thông tin sinh viên đã nhập.
 */

import java.util.Scanner;

public class SinhVien {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name = "";
        String address = "";

        System.out.print("Enter your name: ");
        name = sc.nextLine();
        System.out.print("Enter your address: ");
        address = sc.nextLine();

        System.out.println("\nStudent's Information");
        System.out.println("Name: " + name);
        System.out.print("Enter your address: " + address);

        sc.close();
    }    
}

