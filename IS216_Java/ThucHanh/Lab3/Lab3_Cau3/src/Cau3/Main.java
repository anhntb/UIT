package Cau3;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Company company = new Company();

        while (true) {
            System.out.println("\n--- MENU ---");
            System.out.println("1. Them nhan vien");
            System.out.println("2. Chon ngau nhien NV de nhan qua"); // nhận quà
            System.out.println("3. Danh sach ten SP moi"); // Danh sách tên nhân viên để đặt cho SP mới
            System.out.println("4. Dat ten cho SP moi"); // Đặt tên sản phẩm mới
            System.out.println("5. Dang ky du lich"); // ĐK đi du lịch
            System.out.println("6. DS 20 nguoi dang ky dau tien duoc di du lich"); // Danh sách 20 người đi du lịch
            System.out.println("7. Them khach hang"); // Thêm thông tin khách hàng và doanh số mua hàng của KH đó
            System.out.println("8. Xem danh sach khach hang theo doanh so giam dan"); // Danh sách KH theo doanh số giảm dần
            System.out.println("0. Thoat");
            System.out.print("Chon: ");
            int choice = sc.nextInt();
            sc.nextLine(); // bỏ dòng

            switch (choice) {
                case 1 -> {
                    System.out.println("Nhap danh sach Nhan Vien (Nhap 0 de Ket thuc)"); // Dừng lại khi nhập 0
                    String name;
                    while (true) {        
                        name = sc.nextLine();
                        if (name.equals("0")) break;
                        company.addEmployee(name);       
                    }           
                }
                case 2 -> {
                    String name = company.pickRandomEmployee();
                    System.out.println("NV duoc chon: " + (name != null ? name : "Khong co nhan vien nao"));
                }
                case 3 -> {
                    System.out.println("Danh sach ten SP moi: " + company.getProductNames());
                }
                case 4 -> {
                    String name = company.getMostCommonEmployeeName();
                    System.out.println("Ten NV pho bien nhat: " + name);
                }
                case 5 -> {
                    System.out.println("Nhap danh sach Nhan Vien DK di du lich (Nhap 0 de Ket thuc)"); // Dừng lại khi nhập 0
                    String name;
                    while (true) {        
                        name = sc.nextLine();
                        if (name.equals("0")) break;
                        company.registerForTrip(name);       
                    }     
                }
                case 6 -> {
                    System.out.println("DS di du lich (max 20 nguoi): " + company.getTripList());
                }
                case 7 -> {
                    String name;
                    int amount;
                    System.out.println("Nhap DS khach hang (Nhap 0 de Ket thuc)"); // Dừng lại khi nhập 0
                    while (true) {        
                        System.out.print("Ten khach hang: ");
                        name = sc.nextLine();
                        if (name.equals("0")) break;
                        
                        System.out.print("So tien mua hang: ");
                        amount = sc.nextInt();
                        company.recordPurchase(name, amount);
                        System.out.println("Da ghi nhan mua hang.\n");
                        
                        sc.nextLine(); // bỏ dòng
                    }
                }
                case 8 -> {
                    System.out.println("Khach hang theo doanh so (Giam dan):");
                    company.displayCustomerSales();
                }
                case 0 -> {
                    System.out.println("Thoat chuong trinh.");
                    return;
                }
                default -> System.out.println("Lua chon khong hop le.");
            }
        }
    }
}

