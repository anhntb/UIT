public class HinhBinhHanh extends DaGiac {
    @Override
    protected int soDinh() {
        return 4;
    }

    @Override
    protected String tenHinh() {
        return "Hinh binh hanh";
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

        return songSong(a, b, c, d) && songSong(b, c, d, a);
    }

    @Override
    protected String thongBaoKhongHopLe() {
        return "Bon diem khong tao thanh hinh binh hanh. Vui long nhap lai.";
    }
}
