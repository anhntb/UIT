public class TuGiac extends DaGiac {
    @Override
    protected int soDinh() {
        return 4;
    }

    @Override
    protected String tenHinh() {
        return "Tu giac";
    }

    @Override
    protected boolean laHinhHopLe() {
        return tinhDienTich() > 1e-6;
    }

    @Override
    protected String thongBaoKhongHopLe() {
        return "Bon diem khong tao thanh tu giac hop le. Vui long nhap lai.";
    }
}
