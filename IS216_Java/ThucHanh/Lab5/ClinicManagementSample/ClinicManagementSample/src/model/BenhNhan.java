package model;

import java.util.Date;

public class BenhNhan {
    private String maBN;
    private String tenBN;
    private Date ngaySinh;
    private String diaChi;
    private String dienThoai;
    private boolean gioiTinh;

    public BenhNhan() {}

    // Getters and setters
    public String getMaBN() { return maBN; }
    public void setMaBN(String maBN) { this.maBN = maBN; }
    public String getTenBN() { return tenBN; }
    public void setTenBN(String tenBN) { this.tenBN = tenBN; }
    public Date getNgaySinh() { return ngaySinh; }
    public void setNgaySinh(Date ngaySinh) { this.ngaySinh = ngaySinh; }
    public String getDiaChi() { return diaChi; }
    public void setDiaChi(String diaChi) { this.diaChi = diaChi; }
    public String getDienThoai() { return dienThoai; }
    public void setDienThoai(String dienThoai) { this.dienThoai = dienThoai; }
    public boolean isGioiTinh() { return gioiTinh; }
    public void setGioiTinh(boolean gioiTinh) { this.gioiTinh = gioiTinh; }
}