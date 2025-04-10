package BTTLp1_Cau1;

import java.util.Scanner;

public class Pointer {
    private double x;
    private double y;

    // Constructor 0 tham số
    public Pointer() {
        this.x = 0;
        this.y = 0;
    }

    // Constructor 1 tham số
    public Pointer(double x) {
        this.x = x;
        this.y = 0;
    }

    // Constructor 2 tham số
    public Pointer(double x, double y) {
        this.x = x;
        this.y = y;
    }

    // Getter
    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }
    
    // Setter
    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

    // Tính khoảng cách giữa hai điểm
    public double distanceTo(Pointer other) {
        double dx = this.x - other.x;
        double dy = this.y - other.y;
        return Math.sqrt(dx * dx + dy * dy);
    }

    // Hàm nhập tọa độ từ bàn phím
    public void input() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhap hoanh do x: ");
        this.x = scanner.nextDouble();

        System.out.print("Nhap tung do y: ");
        this.y = scanner.nextDouble();
    }
    
    // In ra thông tin
    public void output() {
        System.out.printf("(%.2f, %.2f)", x, y);
    }

    public static void main(String[] args) {
        Pointer p1 = new Pointer();
        Pointer p2 = new Pointer();
        System.out.print("---Pointer 1---\n");
        p1.input();
        System.out.print("---Pointer 2---\n");
        p2.input();
        System.out.println("Pointer 1: ");
        p1.output();
        System.out.println("\nPointer 2: ");
        p2.output();
        System.out.println("\nKhoang cach giua 2 diem: " + p1.distanceTo(p2));
    }
}
