package BTTLp2_Cau4;

public class XeTai extends Xe {

    @Override
    public void chay(double quangDuong) {
        double xangTieuThu = (20 + (taiTrong / 100.0) * 1.0) * (quangDuong / 100.0);
        if (xang >= xangTieuThu) {
            xang -= xangTieuThu;
        } else {
            System.out.println("Khong du xang de chay " + quangDuong + " km.");
        }
    }
}
