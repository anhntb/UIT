package BTTLp2_Cau4;

public class XeMay extends Xe {

    @Override
    public void chay(double quangDuong) {
        double xangTieuThu = (2 + (taiTrong / 10.0) * 0.1) * (quangDuong / 100.0);
        if (xang >= xangTieuThu) {
            xang -= xangTieuThu;
        } else {
            System.out.println("Khong du xang de chay " + quangDuong + " km.");
        }
    }
}
