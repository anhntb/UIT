import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public abstract class DaGiac extends HinhHoc {
    private static final double EPS = 1e-6;
    protected final List<Point2D> dinh;

    public DaGiac() {
        this.dinh = new ArrayList<>();
    }

    protected abstract int soDinh();

    protected abstract String tenHinh();

    protected boolean laHinhHopLe() {
        return true;
    }

    protected String thongBaoKhongHopLe() {
        return "Toa do vua nhap khong thoa man dieu kien cua hinh. Vui long nhap lai.";
    }

    @Override
    public void nhap(Scanner scanner) {
        while (true) {
            dinh.clear();
            System.out.println("Nhap " + soDinh() + " dinh cho " + tenHinh() + ":");

            for (int i = 0; i < soDinh(); i++) {
                System.out.print("  Dinh " + (i + 1) + " - x: ");
                double x = scanner.nextDouble();
                System.out.print("  Dinh " + (i + 1) + " - y: ");
                double y = scanner.nextDouble();
                dinh.add(new Point2D(x, y));
            }

            if (laHinhHopLe()) {
                break;
            }

            System.out.println(thongBaoKhongHopLe());
        }
    }

    @Override
    public void xuat() {
        System.out.println("Thong tin " + tenHinh() + ":");
        for (int i = 0; i < dinh.size(); i++) {
            System.out.println("  Dinh " + (i + 1) + ": " + dinh.get(i));
        }
        System.out.printf("  Chu vi: %.2f%n", tinhChuVi());
        System.out.printf("  Dien tich: %.2f%n", tinhDienTich());
    }

    @Override
    public void tinhTien(double dx, double dy) {
        for (Point2D p : dinh) {
            p.translate(dx, dy);
        }
    }

    @Override
    public void thuPhong(double factor) {
        for (Point2D p : dinh) {
            p.scale(factor);
        }
    }

    @Override
    public void quay(double degree) {
        for (Point2D p : dinh) {
            p.rotate(degree);
        }
    }

    @Override
    public double tinhChuVi() {
        double chuVi = 0.0;
        for (int i = 0; i < dinh.size(); i++) {
            Point2D a = dinh.get(i);
            Point2D b = dinh.get((i + 1) % dinh.size());
            chuVi += a.distanceTo(b);
        }
        return chuVi;
    }

    @Override
    public double tinhDienTich() {
        double tong = 0.0;
        for (int i = 0; i < dinh.size(); i++) {
            Point2D a = dinh.get(i);
            Point2D b = dinh.get((i + 1) % dinh.size());
            tong += a.getX() * b.getY() - b.getX() * a.getY();
        }
        return Math.abs(tong) / 2.0;
    }

    protected double doDaiCanh(int i, int j) {
        return dinh.get(i).distanceTo(dinh.get(j));
    }

    protected boolean songSong(Point2D a, Point2D b, Point2D c, Point2D d) {
        double ux = b.getX() - a.getX();
        double uy = b.getY() - a.getY();
        double vx = d.getX() - c.getX();
        double vy = d.getY() - c.getY();
        return Math.abs(ux * vy - uy * vx) < EPS;
    }

    protected boolean vuongGoc(Point2D a, Point2D b, Point2D c) {
        double ux = b.getX() - a.getX();
        double uy = b.getY() - a.getY();
        double vx = c.getX() - b.getX();
        double vy = c.getY() - b.getY();
        return Math.abs(ux * vx + uy * vy) < EPS;
    }

    protected boolean bangNhau(double a, double b) {
        return Math.abs(a - b) < EPS;
    }
}
