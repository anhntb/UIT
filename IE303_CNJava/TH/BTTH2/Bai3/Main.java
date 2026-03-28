import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        VuonThu vuonThu = new VuonThu();

        while (true) {
            inMenu();
            int chon = scanner.nextInt();
            scanner.nextLine();

            if (chon == 0) {
                System.out.println("Da thoat chuong trinh.");
                break;
            }

            switch (chon) {
                case 1:
                    themChuong(scanner, vuonThu);
                    break;
                case 2:
                    xoaChuong(scanner, vuonThu);
                    break;
                case 3:
                    themDongVat(scanner, vuonThu);
                    break;
                case 4:
                    xoaDongVat(scanner, vuonThu);
                    break;
                case 5:
                    vuonThu.hienThiThongTinVuonThu();
                    break;
                default:
                    System.out.println("Lua chon khong hop le.");
                    break;
            }
        }

        scanner.close();
    }

    private static void inMenu() {
        System.out.println("\n===== QUAN LY VUON THU =====");
        System.out.println("1. Them chuong");
        System.out.println("2. Xoa chuong theo ma");
        System.out.println("3. Them dong vat vao chuong");
        System.out.println("4. Xoa dong vat khoi chuong");
        System.out.println("5. Hien thi thong tin vuon thu");
        System.out.println("0. Thoat");
        System.out.print("Chon: ");
    }

    private static void themChuong(Scanner scanner, VuonThu vuonThu) {
        System.out.print("Nhap ma chuong: ");
        String maChuong = scanner.nextLine();

        if (vuonThu.themChuong(maChuong)) {
            System.out.println("Them chuong thanh cong.");
        } else {
            System.out.println("Ma chuong da ton tai.");
        }
    }

    private static void xoaChuong(Scanner scanner, VuonThu vuonThu) {
        System.out.print("Nhap ma chuong can xoa: ");
        String maChuong = scanner.nextLine();

        if (vuonThu.xoaChuong(maChuong)) {
            System.out.println("Xoa chuong thanh cong.");
        } else {
            System.out.println("Khong tim thay chuong theo ma da nhap.");
        }
    }

    private static void themDongVat(Scanner scanner, VuonThu vuonThu) {
        System.out.print("Nhap ma chuong muon them dong vat: ");
        String maChuong = scanner.nextLine();

        DongVat dongVat = taoDongVatTheoLoai(scanner);
        if (dongVat == null) {
            System.out.println("Khong tao duoc dong vat.");
            return;
        }

        System.out.print("Nhap so luong can them: ");
        int soLuong = scanner.nextInt();
        scanner.nextLine();

        if (vuonThu.themDongVatVaoChuong(maChuong, dongVat, soLuong)) {
            System.out.println("Them dong vat vao chuong thanh cong.");
        } else {
            System.out.println("Khong tim thay ma chuong hoac so luong khong hop le.");
        }
    }

    private static void xoaDongVat(Scanner scanner, VuonThu vuonThu) {
        System.out.print("Nhap ma chuong: ");
        String maChuong = scanner.nextLine();

        DongVat dongVat = taoDongVatTheoLoai(scanner);
        if (dongVat == null) {
            System.out.println("Loai dong vat khong hop le.");
            return;
        }

        System.out.print("Nhap so luong can xoa: ");
        int soLuong = scanner.nextInt();
        scanner.nextLine();

        if (vuonThu.xoaDongVatKhoiChuong(maChuong, dongVat, soLuong)) {
            System.out.println("Xoa dong vat thanh cong.");
        } else {
            System.out.println("Khong xoa duoc dong vat (sai ma chuong, sai loai hoac so luong khong hop le).");
        }
    }

    private static DongVat taoDongVatTheoLoai(Scanner scanner) {
        System.out.println("\nChon loai dong vat:");
        System.out.println("1. Cho");
        System.out.println("2. Meo");
        System.out.println("3. Ho");
        System.out.println("4. Ca heo");
        System.out.println("5. Ca sau");
        System.out.println("6. Chim cu meo");
        System.out.println("7. Chim bo nong");
        System.out.print("Chon: ");
        int loai = scanner.nextInt();
        scanner.nextLine();

        switch (loai) {
            case 1:
                return new Cho();
            case 2:
                return new Meo();
            case 3:
                return new Ho();
            case 4:
                return new CaHeo();
            case 5:
                return new CaSau();
            case 6:
                return new ChimCuMeo();
            case 7:
                return new ChimBoNong();
            default:
                System.out.println("Loai dong vat khong hop le.");
                return null;
        }
    }
}
