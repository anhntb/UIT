use QLHangTonKho
go



-------------------------------------------------------NHÂN VIÊN-------------------------------------------------------


-- CHỨC NĂNG NHẬP/XUẤT KHO
-- Nhập kho
exec AddPhieuNhapKho 
		@maPNK = null,
		@maKho = null,
		@maNV = null

exec AddChiTietPNK
		@maPNK = null,
		@maSP = null,
		@soLuong = 10

-- Xuất kho
exec AddPhieuXuatKho 
		@maPXK = null,
		@maKho = null,
		@maKH = null,
		@maNV = null

exec AddChiTietPXK
		@maPXK = null,
		@maSP = null,
		@soLuong = null

-- CHỨC NĂNG TRA CỨU
-- Tra cứu sản phẩm
exec TraCuuSanPham
		@tenSP = null,
		@maSP = null,
		@maNCC = null,
		@maLSP = null

-- Tra cứu thông tin nhập kho
exec TraCuuPhieuNhapKho
		@maPNK = null,
		@maKho = null,
		@maNV = null,
		@fromDate = null,
		@toDate = null

-- Tra cứu thông tin xuất kho
exec TraCuuPhieuXuatKho
		@maPXK = null,
		@maKho = null,
		@maKH = null,
		@maNV = null,
		@fromDate = null,
		@toDate = null



-------------------------------------------------------QUẢN LÝ-------------------------------------------------------


-- CHỨC NĂNG NHẬP/XUẤT KHO
-- Nhập kho
-- Xuất kho

-- CHỨC NĂNG TRA CỨU
-- Tra cứu sản phẩm
-- Tra cứu thông tin nhập kho
-- Tra cứu thông tin xuất kho

-- Tra cứu sản phẩm trong kho lưu trữ
exec TraCuuSPTrongKho
		@maKho = null,
		@maSP = null

-- Tra cứu nhân viên
exec TraCuuNV
		@maNV = null,
		@tenNV = null,
		@diaChi = null,
		@sdt = null

-- Tra cứu nhà cung cấp
exec TraCuuNCC
		@maNCC = null,
		@tenNCC = null,
		@diaChi = null,
		@sdt = null,
		@email = null

-- Tra cứu khách hàng
exec TraCuuKH
		@maKH = null,
		@tenKH = null,
		@diaChi = null,
		@sdt = null,
		@email = null


-- CHỨC NĂNG QUẢN LÝ SẢN PHẨM
-- GIÁ BÁN = GIÁ GỐC * 1.1
-- Thêm
exec AddSanPham 
    @maSP = null,
    @tenSP = null,
    @dvTinh = null,
    @giaGoc = null,
    @maNCC = null,
    @maLoaiSP = null

-- Xóa
exec DeleteSanPham 
    @maSP = null

-- Sửa
exec UpdateSanPham 
    @maSP = null,
    @tenSP = null,
    @dvTinh = null,
    @giaGoc = null,
    @maNCC = null,
    @maLoaiSP = null

-- CHỨC NĂNG QUẢN LÝ NHÂN VIÊN
-- Thêm
exec AddNhanVien 
    @maNV = null,
    @tenNV = null,
    @dchi = null,
    @sdt = null

-- Xóa
exec DeleteNhanVien 
    @maNV = null

-- Sửa
exec UpdateNhanVien 
    @maNV = null,
    @tenNV = null,
    @dchi = null,
    @sdt = null

-- CHỨC NĂNG QUẢN LÝ KHÁCH HÀNG
-- Thêm
exec AddKhachHang 
    @maKH = null,
    @tenKH = null,
    @dchi = null,
    @sdt = null,
    @email = null

-- Xóa
exec DeleteKhachHang 
    @maKH = null

-- Sửa
exec UpdateKhachHang 
    @maKH = null,
    @tenKH = null,
    @dchi = null,
    @sdt = null,
    @email = null

-- CHỨC NĂNG QUẢN LÝ NHÀ CUNG CẤP
-- Thêm
exec AddNhaCungCap 
    @maNCC = null,
    @tenNCC = null,
    @dchi = null,
    @sdt = null,
    @email = null

-- Xóa
exec DeleteNhaCungCap 
    @maNCC = null

-- Sửa
exec UpdateNhaCungCap 
    @maNCC = null,
    @tenNCC = null,
    @dchi = null,
    @sdt = null,
    @email = null

-- CHỨC NĂNG QUẢN LÝ KHO
-- Thêm
exec AddKho 
    @maKho = null,
    @tenKho = null,
    @dchi = null,
    @ngQly = null

-- Xóa
exec DeleteKho 
    @maKho = null

-- Sửa
exec UpdateKho 
    @maKho = null,
    @tenKho = null,
    @dchi = null,
    @ngQly = null

-- THỐNG KÊ
-- Tổng trị giá của một kho hàng (tính theo giá bán)
select dbo.CalculateInventoryValue('KHO002') as N'Tổng giá trị của kho'

-- Tổng số lượng xuất/nhập kho ( theo tháng, năm )
exec TongSL_Nhap_Xuat
		@thang = null,
		@nam = null

