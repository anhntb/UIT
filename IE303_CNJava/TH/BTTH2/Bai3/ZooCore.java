import java.util.ArrayList;
import java.util.Collection;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

abstract class DongVat {
    private final String ten;
    private final String moTa;
    private final String tiengKeu;

    public DongVat(String ten, String moTa, String tiengKeu) {
        this.ten = ten;
        this.moTa = moTa;
        this.tiengKeu = tiengKeu;
    }

    public String getTen() {
        return ten;
    }

    public String getMoTa() {
        return moTa;
    }

    public String getTiengKeu() {
        return tiengKeu;
    }

    public abstract String getLoai();

    public List<String> layDacDiemRieng() {
        List<String> dacDiem = new ArrayList<>();

        if (this instanceof BietChay) {
            dacDiem.add(((BietChay) this).chay());
        }
        if (this instanceof BietGam) {
            dacDiem.add(((BietGam) this).gam());
        }
        if (this instanceof BietBoi) {
            dacDiem.add(((BietBoi) this).boi());
        }
        if (this instanceof BietBo) {
            dacDiem.add(((BietBo) this).bo());
        }
        if (this instanceof BietBay) {
            dacDiem.add(((BietBay) this).bay());
        }

        return dacDiem;
    }

    public void hienThiThongTin() {
        System.out.println("Loai: " + getLoai());
        System.out.println("Ten: " + ten);
        System.out.println("Mo ta: " + moTa);
        System.out.println("Tieng keu: " + tiengKeu);
        System.out.println("Dac diem rieng: " + String.join(", ", layDacDiemRieng()));
    }
}

class Chuong {
    private final String maChuong;
    private final Map<String, Integer> soLuongTheoLoai;
    private final Map<String, DongVat> thongTinLoai;

    public Chuong(String maChuong) {
        this.maChuong = maChuong;
        this.soLuongTheoLoai = new LinkedHashMap<>();
        this.thongTinLoai = new LinkedHashMap<>();
    }

    public String getMaChuong() {
        return maChuong;
    }

    public boolean themDongVat(DongVat dongVat, int soLuong) {
        if (soLuong <= 0) {
            return false;
        }

        String loai = dongVat.getLoai();
        soLuongTheoLoai.put(loai, soLuongTheoLoai.getOrDefault(loai, 0) + soLuong);
        thongTinLoai.putIfAbsent(loai, dongVat);
        return true;
    }

    public boolean xoaDongVatTheoLoai(String loai, int soLuong) {
        if (soLuong <= 0) {
            return false;
        }

        Integer hienTai = soLuongTheoLoai.get(loai);
        if (hienTai == null) {
            return false;
        }

        if (soLuong >= hienTai) {
            soLuongTheoLoai.remove(loai);
            thongTinLoai.remove(loai);
        } else {
            soLuongTheoLoai.put(loai, hienTai - soLuong);
        }
        return true;
    }

    public void hienThiThongTinChuong() {
        System.out.println("\nMa chuong: " + maChuong);
        if (soLuongTheoLoai.isEmpty()) {
            System.out.println("  Chuong hien khong co dong vat nao.");
            return;
        }

        int stt = 1;
        for (Map.Entry<String, Integer> entry : soLuongTheoLoai.entrySet()) {
            String loai = entry.getKey();
            int soLuong = entry.getValue();
            DongVat mau = thongTinLoai.get(loai);

            System.out.println("  --- Loai " + stt + " ---");
            if (mau != null) {
                mau.hienThiThongTin();
            }
            System.out.println("So luong: " + soLuong);
            stt++;
        }
    }
}

class VuonThu {
    private final Map<String, Chuong> danhSachChuong;

    public VuonThu() {
        this.danhSachChuong = new LinkedHashMap<>();
    }

    public boolean themChuong(String maChuong) {
        if (danhSachChuong.containsKey(maChuong)) {
            return false;
        }
        danhSachChuong.put(maChuong, new Chuong(maChuong));
        return true;
    }

    public boolean xoaChuong(String maChuong) {
        return danhSachChuong.remove(maChuong) != null;
    }

    public boolean themDongVatVaoChuong(String maChuong, DongVat dongVat, int soLuong) {
        Chuong chuong = danhSachChuong.get(maChuong);
        if (chuong == null) {
            return false;
        }
        return chuong.themDongVat(dongVat, soLuong);
    }

    public boolean xoaDongVatKhoiChuong(String maChuong, DongVat dongVat, int soLuong) {
        Chuong chuong = danhSachChuong.get(maChuong);
        if (chuong == null) {
            return false;
        }
        return chuong.xoaDongVatTheoLoai(dongVat.getLoai(), soLuong);
    }

    public Collection<Chuong> getDanhSachChuong() {
        return danhSachChuong.values();
    }

    public void hienThiThongTinVuonThu() {
        if (danhSachChuong.isEmpty()) {
            System.out.println("Vuon thu hien chua co chuong nao.");
            return;
        }

        for (Chuong chuong : danhSachChuong.values()) {
            chuong.hienThiThongTinChuong();
        }
    }
}
