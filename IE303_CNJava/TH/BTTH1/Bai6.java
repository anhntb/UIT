import java.util.Calendar;
import java.util.Scanner;

public class Bai6 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Nhập ngày a
        System.out.print("Nhap ngay a (dd/MM/yyyy): ");
        String[] ngayA = scanner.nextLine().split("/");
        int ngayA_day = Integer.parseInt(ngayA[0]);
        int ngayA_month = Integer.parseInt(ngayA[1]);
        int ngayA_year = Integer.parseInt(ngayA[2]);
        
        // Nhập ngày b
        System.out.print("Nhap ngay b (dd/MM/yyyy): ");
        String[] ngayB = scanner.nextLine().split("/");
        int ngayB_day = Integer.parseInt(ngayB[0]);
        int ngayB_month = Integer.parseInt(ngayB[1]);
        int ngayB_year = Integer.parseInt(ngayB[2]);
        
        // Tạo Calendar cho ngày a và b
        Calendar calA = Calendar.getInstance();
        calA.set(ngayA_year, ngayA_month - 1, ngayA_day);
        
        Calendar calB = Calendar.getInstance();
        calB.set(ngayB_year, ngayB_month - 1, ngayB_day);
        
        // 1. So sánh 2 ngày a và b
        if (calA.equals(calB)) {
            System.out.println("2 ngay a va b bang nhau");
        } else if (calA.before(calB)) {
            System.out.println("Ngay a truoc ngay b");
        } else {
            System.out.println("Ngay a sau ngay b");
        }
        
        // 2. In ra ngày trước và ngày tiếp theo của ngày a
        Calendar ngayTruoc = (Calendar) calA.clone();
        ngayTruoc.add(Calendar.DATE, -1);
        System.out.println("Ngay truoc ngay a: " + ngayTruoc.get(Calendar.DATE) + "/" 
                          + (ngayTruoc.get(Calendar.MONTH) + 1) + "/" 
                          + ngayTruoc.get(Calendar.YEAR));
        
        Calendar ngayTiepTheo = (Calendar) calA.clone();
        ngayTiepTheo.add(Calendar.DATE, 1);
        System.out.println("Ngay tiep theo cua ngay a: " + ngayTiepTheo.get(Calendar.DATE) + "/" 
                          + (ngayTiepTheo.get(Calendar.MONTH) + 1) + "/" 
                          + ngayTiepTheo.get(Calendar.YEAR));
        
        // 3. Cho biết a là ngày thứ mấy trong năm
        int ngayTrongNam = calA.get(Calendar.DAY_OF_YEAR);
        System.out.println("Ngay a la ngay thu " + ngayTrongNam + " trong nam");
        
        // 4. Cho biết tháng chứa a có bao nhiêu ngày
        int soNgayTrongThang = calA.getActualMaximum(Calendar.DAY_OF_MONTH);
        System.out.println("Thang chua a co " + soNgayTrongThang + " ngay");
        
        // 5. Cho biết năm chứa a có phải là năm nhuận không
        boolean laNamNhuan = (ngayA_year % 4 == 0 && ngayA_year % 100 != 0) 
                            || (ngayA_year % 400 == 0);
        if (laNamNhuan) {
            System.out.println("Nam " + ngayA_year + " la nam nhuan");
        } else {
            System.out.println("Nam " + ngayA_year + " khong phai la nam nhuan");
        }
        
        scanner.close();
    }
}
