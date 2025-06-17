package BT;

import java.util.Scanner;

public class BTrenLop_Cau5 {

    public static void main(String args[]) {
        int soDien;
        try ( // TODO code application logic here
            Scanner scanner = new Scanner(System.in)) {
            System.out.print("Nhap so dien (kWh): ");
            soDien = scanner.nextInt();
        }

        int giaBanDau = 2000;
        int giaTren50kw = 2500;
        int giaTren100kw = 3500;
        int tongTien;
        
        if (soDien <= 0) {
            soDien = 0;
        }
        
        if (soDien <= 50) {
            tongTien = soDien * giaBanDau;
        } else if (soDien <= 100) {
            tongTien = 50 * giaBanDau + (soDien - 50) * giaTren50kw;
        } else {
            tongTien = 50 * giaBanDau+ 50 * giaTren50kw + (soDien - 100) * giaTren100kw;
        }

        System.out.println("Tong tien dien: " + tongTien + " dong");
    
    }
}
