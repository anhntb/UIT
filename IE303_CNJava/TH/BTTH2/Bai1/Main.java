import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<SinhVien> danhSachSinhVien = new ArrayList<>();

        System.out.print("Nhap so luong sinh vien: ");
        int n = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < n; i++) {
            System.out.println("\nNhap thong tin sinh vien thu " + (i + 1) + ":");

            System.out.print("Ma so sinh vien: ");
            int mssv = scanner.nextInt();
            scanner.nextLine();

            System.out.print("Ho ten sinh vien: ");
            String hoTen = scanner.nextLine();

            System.out.print("Diem Giai tich: ");
            double diemGiaiTich = scanner.nextDouble();

            System.out.print("Diem Vat ly: ");
            double diemVatLy = scanner.nextDouble();

            System.out.print("Diem Nhap mon lap trinh: ");
            double diemNhapMonLapTrinh = scanner.nextDouble();
            scanner.nextLine();

            SinhVien sinhVien = new SinhVien(mssv, hoTen, diemGiaiTich, diemVatLy, diemNhapMonLapTrinh);
            danhSachSinhVien.add(sinhVien);
        }

        System.out.println("\n=== DANH SACH SINH VIEN DU DIEU KIEN NHAN HOC BONG ===");
        boolean coHocBong = false;
        for (SinhVien sv : danhSachSinhVien) {
            if (sv.duDieuKienHocBong()) {
                System.out.println(sv.thongTinRutGon());
                coHocBong = true;
            }
        }
        if (!coHocBong) {
            System.out.println("Khong co sinh vien nao du dieu kien nhan hoc bong.");
        }

        double diemTrungBinhCaoNhat = -1.0;
        for (SinhVien sv : danhSachSinhVien) {
            diemTrungBinhCaoNhat = Math.max(diemTrungBinhCaoNhat, sv.getDiemTrungBinh());
        }

        System.out.println("\n=== SINH VIEN CO DIEM TRUNG BINH CAO NHAT ===");
        for (SinhVien sv : danhSachSinhVien) {
            if (Math.abs(sv.getDiemTrungBinh() - diemTrungBinhCaoNhat) < 1e-9) {
                System.out.println(sv.thongTinRutGon());
            }
        }

        danhSachSinhVien.sort(Comparator.comparingDouble(SinhVien::getDiemTrungBinh).reversed());

        System.out.println("\n=== TOP 10 SINH VIEN CO DIEM CAO NHAT ===");
        int top = Math.min(10, danhSachSinhVien.size());
        for (int i = 0; i < top; i++) {
            System.out.printf("Top %d: %s%n", i + 1, danhSachSinhVien.get(i).thongTinRutGon());
        }

        scanner.close();
    }
}
