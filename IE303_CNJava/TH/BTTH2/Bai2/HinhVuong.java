public class HinhVuong extends DaGiac {
    @Override
    protected int soDinh() {
        return 4;
    }

    @Override
    protected String tenHinh() {
        return "Hinh vuong";
    }

    @Override
    protected boolean laHinhHopLe() {
        if (tinhDienTich() <= 1e-6) {
            return false;
        }
        Point2D a = dinh.get(0);
        Point2D b = dinh.get(1);
        Point2D c = dinh.get(2);
        Point2D d = dinh.get(3);

        boolean laHinhChuNhat = songSong(a, b, c, d) && songSong(b, c, d, a) && vuongGoc(a, b, c);
        double canh1 = doDaiCanh(0, 1);
        double canh2 = doDaiCanh(1, 2);
        return laHinhChuNhat && bangNhau(canh1, canh2);
    }

    @Override
    protected String thongBaoKhongHopLe() {
        return "Bon diem khong tao thanh hinh vuong. Vui long nhap lai.";
    }
}
