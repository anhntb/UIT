use QLHangTonKho
go



-------------------------------------------------------NHÂN VIÊN-------------------------------------------------------


-- CHỨC NĂNG NHẬP/XUẤT KHO
-- Nhập kho
select * from SANPHAM where MASP = 'SP001'
select * from LUUTRU where MASP = 'SP001'

exec AddPhieuNhapKho 
		@maPNK = 'PNK090',
		@maKho = 'KHO001',
		@maNV = 'NV010'

exec AddChiTietPNK
		@maPNK = 'PNK090',
		@maSP = 'SP001',
		@soLuong = 10

select * from SANPHAM where MASP = 'SP001'
select * from LUUTRU where MASP = 'SP001'

-- Xuất kho
select * from SANPHAM where MASP = 'SP001'
select * from LUUTRU where MASP = 'SP001'

exec AddPhieuXuatKho 
		@maPXK = 'PXK099',
		@maKho = 'KHO002',
		@maKH = 'KH001',
		@maNV = 'NV001'

exec AddChiTietPXK
		@maPXK = 'PXK099',
		@maSP = 'SP001',
		@soLuong = 41

select * from SANPHAM where MASP = 'SP001'
select * from LUUTRU where MASP = 'SP001'

-- CHỨC NĂNG TRA CỨU
-- Tra cứu sản phẩm
exec TraCuuSanPham
		@tenSP = 'g',
		@maSP = null,
		@maNCC = 'NCC004',
		@maLSP = 'LSP005'

-- Tra cứu thông tin nhập kho
exec TraCuuPhieuNhapKho
		@maPNK = null,
		@maKho = null,
		@maNV = 'NV003',
		@fromDate = '2023-12-01',
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
		@maKho = 'KHO001',
		@maSP = 'SP001'

-- Tra cứu nhân viên
exec TraCuuNV
		@maNV = null,
		@tenNV = N'Văn',
		@diaChi = null,
		@sdt = '03'

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
select * from SANPHAM

exec AddSanPham 
    @maSP = 'SP090',
    @tenSP = N'Bột mì',
    @dvTinh = N'Túi',
    @giaGoc = 30000,
    @maNCC = 'NCC003',
    @maLoaiSP = 'LSP001'

select * from SANPHAM

-- Xóa
exec DeleteSanPham 
    @maSP = 'SP001'
select * from SANPHAM

-- Sửa
select * from SANPHAM where MASP = 'SP002'

exec UpdateSanPham 
    @maSP = 'SP002',
    @tenSP = N'cá basa',
    @dvTinh = 'kg',
    @giaGoc = 30000,
    @maNCC = 'NCC005',
    @maLoaiSP = 'LSP001'

select * from SANPHAM where MASP = 'SP002'


-- CHỨC NĂNG QUẢN LÝ NHÂN VIÊN
-- Thêm

exec AddNhanVien 
    @maNV = 'NV100',
    @tenNV = N'Lê Văn A',
    @dchi = N'THUDUC',
    @sdt = '0123456789'

select * from NHANVIEN


-- Xóa
exec DeleteNhanVien 
    @maNV = 'NV100'

select * from NHANVIEN


-- Sửa
select * from NHANVIEN

exec UpdateNhanVien 
    @maNV = 'NV099',
    @tenNV = N'Trần',
    @dchi = N'HCM',
    @sdt = '0123'

select * from NHANVIEN


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
		@thang = 6,
		@nam = null

