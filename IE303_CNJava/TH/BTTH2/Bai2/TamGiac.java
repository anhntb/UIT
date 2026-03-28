public class TamGiac extends DaGiac {
    @Override
    protected int soDinh() {
        return 3;
    }

    @Override
    protected String tenHinh() {
        return "Tam giac";
    }

    @Override
    protected boolean laHinhHopLe() {
        return tinhDienTich() > 1e-6;
    }

    @Override
    protected String thongBaoKhongHopLe() {
        return "Ba diem thang hang, khong tao thanh tam giac. Vui long nhap lai.";
    }
}
