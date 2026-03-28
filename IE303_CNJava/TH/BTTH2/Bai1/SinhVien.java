public class SinhVien {
    private int maSoSinhVien;
    private String hoTen;
    private double diemGiaiTich;
    private double diemVatLy;
    private double diemNhapMonLapTrinh;

    public SinhVien(int maSoSinhVien, String hoTen, double diemGiaiTich, double diemVatLy, double diemNhapMonLapTrinh) {
        this.maSoSinhVien = maSoSinhVien;
        this.hoTen = hoTen;
        this.diemGiaiTich = diemGiaiTich;
        this.diemVatLy = diemVatLy;
        this.diemNhapMonLapTrinh = diemNhapMonLapTrinh;
    }

    public int getMaSoSinhVien() {
        return maSoSinhVien;
    }

    public String getHoTen() {
        return hoTen;
    }

    public double getDiemGiaiTich() {
        return diemGiaiTich;
    }

    public double getDiemVatLy() {
        return diemVatLy;
    }

    public double getDiemNhapMonLapTrinh() {
        return diemNhapMonLapTrinh;
    }

    public double getDiemTrungBinh() {
        return (diemGiaiTich + diemVatLy + diemNhapMonLapTrinh) / 3.0;
    }

    public boolean duDieuKienHocBong() {
        return getDiemTrungBinh() >= 8.0 && diemNhapMonLapTrinh >= 9.0;
    }

    public String thongTinRutGon() {
        return String.format(
                "MSSV: %d | Ho ten: %s | Giai tich: %.2f | Vat ly: %.2f | Nhap mon LT: %.2f | DTB: %.2f",
                maSoSinhVien,
                hoTen,
                diemGiaiTich,
                diemVatLy,
                diemNhapMonLapTrinh,
                getDiemTrungBinh()
        );
    }
}
