public class HinhChuNhat extends DaGiac {
    @Override
    protected int soDinh() {
        return 4;
    }

    @Override
    protected String tenHinh() {
        return "Hinh chu nhat";
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

        boolean laHinhBinhHanh = songSong(a, b, c, d) && songSong(b, c, d, a);
        boolean coGocVuong = vuongGoc(a, b, c);
        return laHinhBinhHanh && coGocVuong;
    }

    @Override
    protected String thongBaoKhongHopLe() {
        return "Bon diem khong tao thanh hinh chu nhat. Vui long nhap lai.";
    }
}
