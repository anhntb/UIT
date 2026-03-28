import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\n===== MENU CHINH =====");
            System.out.println("1. Muc 1: Nhap 2 diem A, B va tinh khoang cach AB");
            System.out.println("2. Muc 2: Lam viec voi cac hinh da giac");
            System.out.println("0. Thoat chuong trinh");
            System.out.print("Chon chuc nang: ");

            int chon = scanner.nextInt();
            scanner.nextLine();

            if (chon == 0) {
                System.out.println("Da thoat chuong trinh.");
                break;
            }

            switch (chon) {
                case 1:
                    xuLyMuc1(scanner);
                    break;
                case 2:
                    xuLyMuc2(scanner);
                    break;
                default:
                    System.out.println("Lua chon khong hop le.");
                    break;
            }
        }

        scanner.close();
    }

    private static void xuLyMuc1(Scanner scanner) {
        System.out.println("\n--- MUC 1: TINH KHOANG CACH AB ---");

        System.out.print("Nhap xA: ");
        double xA = scanner.nextDouble();
        System.out.print("Nhap yA: ");
        double yA = scanner.nextDouble();

        System.out.print("Nhap xB: ");
        double xB = scanner.nextDouble();
        System.out.print("Nhap yB: ");
        double yB = scanner.nextDouble();

        Point2D a = new Point2D(xA, yA);
        Point2D b = new Point2D(xB, yB);

        System.out.printf("Khoang cach AB = %.2f%n", a.distanceTo(b));
    }

    private static void xuLyMuc2(Scanner scanner) {
        DaGiac hinh = taoHinhTheoLuaChon(scanner);
        if (hinh == null) {
            return;
        }

        hinh.nhap(scanner);
        System.out.println("\nHinh vua nhap:");
        hinh.xuat();

        System.out.print("\nNhap dx de tinh tien: ");
        double dx = scanner.nextDouble();
        System.out.print("Nhap dy de tinh tien: ");
        double dy = scanner.nextDouble();
        hinh.tinhTien(dx, dy);
        System.out.println("Sau khi tinh tien:");
        hinh.xuat();

        System.out.print("\nNhap he so thu phong (vd 2.0 la phong to, 0.5 la thu nho): ");
        double factor = scanner.nextDouble();
        hinh.thuPhong(factor);
        System.out.println("Sau khi thu phong:");
        hinh.xuat();

        System.out.print("\nNhap goc quay (do): ");
        double degree = scanner.nextDouble();
        hinh.quay(degree);
        System.out.println("Sau khi quay:");
        hinh.xuat();
    }

    private static DaGiac taoHinhTheoLuaChon(Scanner scanner) {
        System.out.println("\n--- MUC 2: CHON LOAI HINH ---");
        System.out.println("1. Tam giac");
        System.out.println("2. Tu giac");
        System.out.println("3. Hinh binh hanh");
        System.out.println("4. Hinh chu nhat");
        System.out.println("5. Hinh vuong");
        System.out.print("Chon loai hinh: ");

        int loai = scanner.nextInt();

        switch (loai) {
            case 1:
                return new TamGiac();
            case 2:
                return new TuGiac();
            case 3:
                return new HinhBinhHanh();
            case 4:
                return new HinhChuNhat();
            case 5:
                return new HinhVuong();
            default:
                System.out.println("Loai hinh khong hop le.");
                return null;
        }
    }
}
