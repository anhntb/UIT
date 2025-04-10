package BTTLp2_Cau3;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Nhap so robot Pedion: ");
        int a = sc.nextInt();       

        System.out.print("Nhap so robot Zattacker: ");
        int b = sc.nextInt();

        System.out.print("Nhap so robot Carrier: ");
        int c = sc.nextInt();

        Robot[] dsRobots = new Robot[a + b + c];
        int index = 0;
        double mPedion = 20;
        double mZattacker = 50;
        double mCarrier = 30;
        double S = 10;

        double tongNL_Pedion = 0;
        for (int i = 0; i < a; i++) {
            dsRobots[index++] = new Pedion(mPedion, S);
            tongNL_Pedion += dsRobots[index-1].tinhNangLuong();
        }
        
        double tongNL_Zattacker = 0;
        for (int i = 0; i < b; i++) {
            dsRobots[index++] = new Zattacker(mZattacker, S);
            tongNL_Zattacker += dsRobots[index-1].tinhNangLuong();
        }
        
        double tongNL_Carrier = 0;
        for (int i = 0; i < c; i++) {
            dsRobots[index++] = new Carrier(mCarrier, S);
            tongNL_Carrier += dsRobots[index-1].tinhNangLuong();
        }

        index = 0;
        System.out.println("\n--- Thong tin cac robot ---");
        for (Robot robot : dsRobots) {
            System.out.println("Robot " + ++index + ": " + robot.toString());
            System.out.println("Nang luong = " + robot.tinhNangLuong());
            System.out.println("\n----------------------------");
        }
        
        System.out.println("\n--- Loai Robot tieu thu nhieu nang luong nhat ---");
        double NLmax = tongNL_Pedion;
        String loaiRobot = "Pedion";
        if (tongNL_Zattacker > NLmax) {
            NLmax = tongNL_Zattacker;
            loaiRobot = "Zattacker";
        }
        if (tongNL_Carrier > NLmax) {
            NLmax = tongNL_Carrier;
            loaiRobot = "Carrier";
        }
        System.out.println(loaiRobot + ": " + NLmax + " nang luong");
        
        sc.close();
    }
}

