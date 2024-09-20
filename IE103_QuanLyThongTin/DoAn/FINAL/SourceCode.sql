---------------------------------------------------------------------CREATE DATABASE_TABLE---------------------------------------------------------------------

-- Drop Database QLHangTonKho
Create Database QLHangTonKho
Go

Use QLHangTonKho
go

--CREATE TABLE
--1.NCC
Create Table NCC
(
	MANCC char(6) Primary key,
	TENNCC nvarchar(40) Not null,
	DCHI nvarchar(40) Not null,
	SDT varchar(10) Not null,
	EMAIL nvarchar(30) Not null
)
Go

--2.LOAISP
Create Table LOAISP
(
	MALOAISP char(6) Primary key,
	TENLOAISP nvarchar(40) Not null,
	MOTA ntext
)
Go

--3.SANPHAM
Create Table SANPHAM
(
	MASP char(5) Primary key,
	TENSP nvarchar(40) Not null,
	DVTINH nvarchar(10) Not null,
	SL int default 0, -- Được tính tự động
	GIAGOC money default 0,
	GIABAN money default 0, -- *1.1 GIAGOC
	MANCC char(6) Foreign key References NCC,
	MALOAISP char(6) Foreign key References LOAISP
)
Go

--4.NHANVIEN
Create Table NHANVIEN
(
	MANV char(5) Primary key,
	TENNV nvarchar(30) Not null,
	DCHI nvarchar(40) Not null,
	SDT varchar(10) Not null
)
Go

--5.KHO
Create Table KHO
(
	MAKHO char(6) Primary key,
	TENKHO nvarchar(40) Not null,
	DCHI nvarchar(40) Not null,
	NGQLY char(5) Foreign key References NHANVIEN not null
)
Go

--6.KHACHHANG
Create Table KHACHHANG
(
	MAKH char(5) Primary key,
	TENKH nvarchar(30) Not null,
	DCHI nvarchar(40) Not null,
	SDT varchar(10) Not null,
	EMAIL nvarchar(30) Not null
)
Go

--7.PHIEUNHAPKHO
Create Table PHIEUNHAPKHO
(
	MAPNK char(6) Primary key,
	NGAYNHAP smalldatetime,
	MAKHO char(6) Foreign key References KHO,
	MANV char(5) Foreign key References NHANVIEN
)
Go

--8.CT_PNK
Create Table CT_PNK
(
	MAPNK char(6) Foreign key References PHIEUNHAPKHO,
	MASP char(5) Foreign key References SANPHAM,
	SL int default 0,
	Primary key (MAPNK, MASP)
)
Go

--9.PHIEUXUATKHO
Create Table PHIEUXUATKHO
(
	MAPXK char(6) Primary key,
	NGAYXUAT smalldatetime,
	MAKHO char(6) Foreign key References KHO,
	MAKH char(5) Foreign key References KHACHHANG,
	MANV char(5) Foreign key References NHANVIEN
)
Go

--10.CT_PXK
Create Table CT_PXK
(
	MAPXK char(6) Foreign key References PHIEUXUATKHO,
	MASP char(5) Foreign key References SANPHAM,
	SL int default 0,
	Primary key (MAPXK, MASP)
)
Go

--11.LUUTRU
--Bảng được tạo tự động
Create Table LUUTRU
(
	MAKHO char(6) Foreign key References KHO,
	MASP char(5) Foreign key References SANPHAM,
	SL int default 0
	Primary key (MAKHO, MASP)
)
Go

--12.TAIKHOAN
create table TAIKHOAN
(
	TEN_TK nvarchar(100) primary key,
	TENHIENTHI nvarchar(100) not null,
	MATKHAU nvarchar(1000) not null,
	LOAI_TK int not null default 0 -- 1: quản lý kho || 0:nhân viên kho
)
go



---------------------------------------------------------------------XỬ LÝ THÔNG TIN---------------------------------------------------------------------

-- TRIGGER
-- Trigger kiểm tra giá bán = 1.1 * giá gốc
CREATE TRIGGER trg_CheckGiaBanGiaGoc
ON SANPHAM
FOR INSERT, UPDATE
AS
BEGIN
    -- Biến để lưu trữ kết quả kiểm tra
    DECLARE @ErrorMessage NVARCHAR(4000);

    -- Kiểm tra nếu có bản ghi vi phạm điều kiện
    IF EXISTS (
        SELECT 1
        FROM inserted i
        WHERE i.GIABAN != 1.1 * i.GIAGOC
    )
    BEGIN
        -- Thông báo lỗi và rollback transaction
        SET @ErrorMessage = N'Giá bán phải bằng 1.1 lần giá gốc.';
        RAISERROR (@ErrorMessage, 16, 1);
        ROLLBACK TRANSACTION;
    END
END
GO

-- Trigger cập nhật số lượng hàng hóa sau khi nhập kho
CREATE TRIGGER AfterInsertCT_PNK
ON CT_PNK
AFTER INSERT
AS
BEGIN
	-- Kiểm tra sản phẩm đã tồn tại trong kho hay chưa
	IF NOT EXISTS (
		SELECT * 
		FROM LUUTRU
		JOIN INSERTED ON LUUTRU.MASP = INSERTED.MASP
		JOIN PHIEUNHAPKHO ON INSERTED.MAPNK = PHIEUNHAPKHO.MAPNK AND LUUTRU.MAKHO = PHIEUNHAPKHO.MAKHO
	)
	-- Nếu chưa thì khởi tạo với số lượng sản phẩm ban đầu là 0
	BEGIN
		DECLARE @MAKHO CHAR(6), @MASP CHAR(5)
		SELECT @MAKHO = MAKHO, @MASP = INSERTED.MASP
		FROM INSERTED JOIN PHIEUNHAPKHO ON INSERTED.MAPNK = PHIEUNHAPKHO.MAPNK

		INSERT INTO LUUTRU VALUES (@MAKHO, @MASP, 0)
	END

    -- Cập nhật số lượng trong bảng SANPHAM
    UPDATE SANPHAM
    SET SL = SANPHAM.SL + inserted.SL
    FROM SANPHAM
    JOIN inserted ON SANPHAM.MASP = inserted.MASP;

    -- Cập nhật số lượng hàng trong kho tương ứng
    UPDATE LUUTRU
    SET SL = LUUTRU.SL + inserted.SL
    FROM LUUTRU
    JOIN inserted ON LUUTRU.MASP = inserted.MASP
    JOIN PHIEUNHAPKHO ON LUUTRU.MAKHO = PHIEUNHAPKHO.MAKHO AND PHIEUNHAPKHO.MAPNK = inserted.MAPNK;
END
GO

-- Trigger cập nhật số lượng hàng hóa sau khi xuất kho
CREATE TRIGGER AfterInsertCT_PXK
ON CT_PXK
AFTER INSERT
AS
BEGIN
	-- Biến để lưu trữ kết quả kiểm tra
    DECLARE @ErrorMessage NVARCHAR(4000);  

	-- Kiểm tra nếu có bản ghi vi phạm điều kiện
	-- Số lượng hàng hóa phải lớn hơn hoặc bằng số lượng xuất kho
	
    IF EXISTS (
        SELECT 1
        FROM LUUTRU
		JOIN inserted ON LUUTRU.MASP = inserted.MASP
		JOIN PHIEUXUATKHO ON LUUTRU.MAKHO = PHIEUXUATKHO.MAKHO AND PHIEUXUATKHO.MAPXK = inserted.MAPXK
		WHERE inserted.SL > LUUTRU.SL
    )
	OR NOT EXISTS (
		SELECT *
		FROM LUUTRU
		JOIN inserted ON LUUTRU.MASP = inserted.MASP
		JOIN PHIEUXUATKHO ON LUUTRU.MAKHO = PHIEUXUATKHO.MAKHO AND PHIEUXUATKHO.MAPXK = inserted.MAPXK
	)
    BEGIN
        -- Thông báo lỗi và rollback transaction
        SET @ErrorMessage = N'Số lượng sản phẩm trong kho không đủ.';
        RAISERROR (@ErrorMessage, 16, 1);
        ROLLBACK TRANSACTION;
    END
	ELSE
	BEGIN
		-- Cập nhật số lượng trong bảng SANPHAM
		UPDATE SANPHAM
		SET SL = SANPHAM.SL - inserted.SL
		FROM SANPHAM
		JOIN inserted ON SANPHAM.MASP = inserted.MASP;

		-- Cập nhật số lượng hàng trong kho tương ứng
		UPDATE LUUTRU
		SET SL = LUUTRU.SL - inserted.SL
		FROM LUUTRU
		JOIN inserted ON LUUTRU.MASP = inserted.MASP
		JOIN PHIEUXUATKHO ON LUUTRU.MAKHO = PHIEUXUATKHO.MAKHO AND PHIEUXUATKHO.MAPXK = inserted.MAPXK;
	END
END
GO

-- Trigger cập nhật số lượng hàng hóa khi xóa chi tiết phiếu nhập kho
CREATE TRIGGER AfterDeleteCT_PNK
ON CT_PNK
AFTER DELETE
AS
BEGIN
    -- Cập nhật số lượng trong bảng SANPHAM
    UPDATE SANPHAM
    SET SL = SANPHAM.SL - deleted.SL
    FROM SANPHAM
    JOIN deleted ON SANPHAM.MASP = deleted.MASP;

    -- Cập nhật số lượng hàng trong kho tương ứng
    UPDATE LUUTRU
    SET SL = LUUTRU.SL - deleted.SL
    FROM LUUTRU
    JOIN deleted ON LUUTRU.MASP = deleted.MASP
    JOIN PHIEUNHAPKHO ON LUUTRU.MAKHO = PHIEUNHAPKHO.MAKHO AND PHIEUNHAPKHO.MAPNK = deleted.MAPNK;

	PRINT N'XÓA THÀNH CÔNG'
END
GO

-- Trigger cập nhật số lượng hàng hóa khi xóa chi tiết phiếu xuất kho
CREATE TRIGGER AfterDeleteCT_PXK
ON CT_PXK
AFTER DELETE
AS
BEGIN
    -- Cập nhật số lượng trong bảng SANPHAM
    UPDATE SANPHAM
    SET SL = SANPHAM.SL + deleted.SL
    FROM SANPHAM
    JOIN deleted ON SANPHAM.MASP = deleted.MASP;

    -- Cập nhật số lượng hàng trong kho tương ứng
    UPDATE LUUTRU
    SET SL = LUUTRU.SL + deleted.SL
    FROM LUUTRU
    JOIN deleted ON LUUTRU.MASP = deleted.MASP
    JOIN PHIEUXUATKHO ON LUUTRU.MAKHO = PHIEUXUATKHO.MAKHO AND PHIEUXUATKHO.MAPXK = deleted.MAPXK;

	PRINT N'XÓA THÀNH CÔNG'
END
GO

-- Trigger xóa phiếu nhập kho
CREATE TRIGGER TRG_DeletePNK
ON PHIEUNHAPKHO
INSTEAD OF DELETE
AS
BEGIN
	DECLARE @MAPNK CHAR(6)
	SELECT @MAPNK = deleted.MAPNK FROM deleted

	DELETE FROM CT_PNK WHERE @MAPNK = CT_PNK.MAPNK
	DELETE FROM PHIEUNHAPKHO WHERE MAPNK = @MAPNK

	PRINT N'XÓA THÀNH CÔNG'
END
GO

-- Trigger xóa phiếu xuất kho
CREATE TRIGGER TRG_DeletePXK
ON PHIEUXUATKHO
INSTEAD OF DELETE
AS
BEGIN
	DECLARE @MAPXK CHAR(6)
	SELECT @MAPXK = deleted.MAPXK FROM deleted

	DELETE FROM CT_PXK WHERE @MAPXK = CT_PXK.MAPXK
	DELETE FROM PHIEUXUATKHO WHERE MAPXK = @MAPXK

	PRINT N'XÓA THÀNH CÔNG'
END
GO

-- Trigger xóa sản phẩm
CREATE TRIGGER TRG_DELETE_SANPHAM
ON SANPHAM
INSTEAD OF DELETE
AS
BEGIN
	DECLARE @MASP CHAR(5)
	SELECT @MASP = DELETED.MASP FROM DELETED

	ALTER TABLE CT_PNK NOCHECK CONSTRAINT ALL
	ALTER TABLE CT_PXK NOCHECK CONSTRAINT ALL
	ALTER TABLE LUUTRU NOCHECK CONSTRAINT ALL

	DELETE FROM LUUTRU WHERE MASP = @MASP
	DELETE FROM SANPHAM WHERE MASP = @MASP

	ALTER TABLE CT_PNK CHECK CONSTRAINT ALL
	ALTER TABLE CT_PXK CHECK CONSTRAINT ALL
	ALTER TABLE LUUTRU CHECK CONSTRAINT ALL

	PRINT N'XÓA THÀNH CÔNG'
END
GO

-- Trigger xóa kho
CREATE TRIGGER TRG_DELETE_KHO
ON KHO
INSTEAD OF DELETE
AS
BEGIN
	DECLARE @MAKHO CHAR(6)
	SELECT @MAKHO = DELETED.MAKHO FROM DELETED

	ALTER TABLE PHIEUNHAPKHO NOCHECK CONSTRAINT ALL
	ALTER TABLE PHIEUXUATKHO NOCHECK CONSTRAINT ALL
	ALTER TABLE LUUTRU NOCHECK CONSTRAINT ALL

	DELETE FROM LUUTRU WHERE MAKHO = @MAKHO
	DELETE FROM KHO WHERE MAKHO = @MAKHO

	ALTER TABLE PHIEUNHAPKHO CHECK CONSTRAINT ALL
	ALTER TABLE PHIEUXUATKHO CHECK CONSTRAINT ALL
	ALTER TABLE LUUTRU CHECK CONSTRAINT ALL

	PRINT N'XÓA THÀNH CÔNG'
END
GO

-- Trigger xóa nhà cung cấp
CREATE TRIGGER TRG_DELETE_NCC
ON NCC
INSTEAD OF DELETE
AS
BEGIN
	DECLARE @MANCC CHAR(6)
	SELECT @MANCC = DELETED.MANCC FROM DELETED

	ALTER TABLE SANPHAM NOCHECK CONSTRAINT ALL

	DELETE FROM NCC WHERE MANCC = @MANCC

	ALTER TABLE SANPHAM CHECK CONSTRAINT ALL

	PRINT N'XÓA THÀNH CÔNG'
END
GO

-- Trigger xóa khách hàng
CREATE TRIGGER TRG_DELETE_KH
ON KHACHHANG
INSTEAD OF DELETE
AS
BEGIN
	DECLARE @MAKH CHAR(5)
	SELECT @MAKH = DELETED.MAKH FROM DELETED

	ALTER TABLE PHIEUXUATKHO NOCHECK CONSTRAINT ALL

	DELETE FROM KHACHHANG WHERE MAKH = @MAKH

	ALTER TABLE PHIEUXUATKHO CHECK CONSTRAINT ALL

	PRINT N'XÓA THÀNH CÔNG'
END
GO

-- Trigger xóa nhân viên
CREATE TRIGGER TRG_DELETE_NV
ON NHANVIEN
INSTEAD OF DELETE
AS
BEGIN
	DECLARE @MANV CHAR(5)
	SELECT @MANV = DELETED.MANV FROM DELETED

	ALTER TABLE PHIEUNHAPKHO NOCHECK CONSTRAINT ALL
	ALTER TABLE PHIEUXUATKHO NOCHECK CONSTRAINT ALL
	ALTER TABLE KHO NOCHECK CONSTRAINT ALL

	DELETE FROM NHANVIEN WHERE MANV = @MANV

	ALTER TABLE PHIEUNHAPKHO CHECK CONSTRAINT ALL
	ALTER TABLE PHIEUXUATKHO CHECK CONSTRAINT ALL
	ALTER TABLE KHO CHECK CONSTRAINT ALL

	PRINT N'XÓA THÀNH CÔNG'
END
GO

-- STORED PROCEDURE
-- Stored Procedure để thêm mới một phiếu nhập kho
CREATE PROCEDURE AddPhieuNhapKho (
    @maPNK CHAR(6),
    @maKho CHAR(6),
    @maNV CHAR(5)
)
AS
BEGIN
	DECLARE @ngayNhap SMALLDATETIME
	SET @ngayNhap = GETDATE()

    INSERT INTO PHIEUNHAPKHO (MAPNK, NGAYNHAP, MAKHO, MANV)
    VALUES (@maPNK, @ngayNhap, @maKho, @maNV);
END
GO

-- Stored Procedure để thêm mới chi tiết phiếu nhập kho
CREATE PROCEDURE AddChiTietPNK (
    @maPNK CHAR(6),
    @maSP CHAR(5),
    @soLuong INT
)
AS
BEGIN
    INSERT INTO CT_PNK (MAPNK, MASP, SL)
    VALUES (@maPNK, @maSP, @soLuong);
END
GO

-- Stored Procedure để thêm mới một phiếu xuất kho
CREATE PROCEDURE AddPhieuXuatKho (
    @maPXK CHAR(6),
    @maKho CHAR(6),
    @maKH CHAR(5),
    @maNV CHAR(5)
)
AS
BEGIN
	DECLARE @ngayXuat SMALLDATETIME
	SET @ngayXuat = GETDATE()

    INSERT INTO PHIEUXUATKHO (MAPXK, NGAYXUAT, MAKHO, MAKH, MANV)
    VALUES (@maPXK, @ngayXuat, @maKho, @maKH, @maNV);
END
GO

-- Stored Procedure để thêm mới chi tiết phiếu xuất kho
CREATE PROCEDURE AddChiTietPXK (
    @maPXK CHAR(6),
    @maSP CHAR(5),
    @soLuong INT
)
AS
BEGIN
    INSERT INTO CT_PXK (MAPXK, MASP, SL)
    VALUES (@maPXK, @maSP, @soLuong);
END
GO

-- Chức năng quản lý sản phẩm
-- Thêm mới sản phẩm
CREATE PROCEDURE AddSanPham (
    @maSP CHAR(5),
    @tenSP NVARCHAR(100),
    @dvTinh NVARCHAR(50),
    @giaGoc DECIMAL(18, 2),
    @maNCC CHAR(6),
    @maLoaiSP CHAR(6)
)
AS
BEGIN
	-- Số lượng sản phẩm khi thêm mới được mặc định là 0

	DECLARE @giaBan DECIMAL(18, 2)
	SET @giaBan = @giaGoc*1.1

    INSERT INTO SANPHAM (MASP, TENSP, DVTINH, GIAGOC, GIABAN, MANCC, MALOAISP)
    VALUES (@maSP, @tenSP, @dvTinh, @giaGoc, @giaBan, @maNCC, @maLoaiSP);
END
GO

-- Cập nhật thông tin sản phẩm
CREATE PROCEDURE UpdateSanPham (
    @maSP CHAR(5),
    @tenSP NVARCHAR(100),
    @dvTinh NVARCHAR(50),
    @giaGoc DECIMAL(18, 2),
    @maNCC CHAR(6),
    @maLoaiSP CHAR(6)
)
AS
BEGIN
    UPDATE SANPHAM
    SET TENSP = @tenSP,
        DVTINH = @dvTinh,
        GIAGOC = @giaGoc,
        GIABAN = @giaGoc*1.1,
        MANCC = @maNCC,
        MALOAISP = @maLoaiSP
    WHERE MASP = @maSP;
END
GO

-- Xóa sản phẩm
CREATE PROCEDURE DeleteSanPham (
    @maSP CHAR(5)
)
AS
BEGIN
    DELETE FROM SANPHAM
    WHERE MASP = @maSP;
END
GO

-- Chức năng quản lý kho
-- Thêm mới kho
CREATE PROCEDURE AddKho (
    @maKho CHAR(6),
    @tenKho NVARCHAR(100),
    @dchi NVARCHAR(255),
    @ngQly CHAR(5)
)
AS
BEGIN
    INSERT INTO KHO (MAKHO, TENKHO, DCHI, NGQLY)
    VALUES (@maKho, @tenKho, @dchi, @ngQly);
END
GO

-- Cập nhật thông tin kho
CREATE PROCEDURE UpdateKho (
    @maKho CHAR(6),
    @tenKho NVARCHAR(100),
    @dchi NVARCHAR(255),
    @ngQly CHAR(5)
)
AS
BEGIN
    UPDATE KHO
    SET TENKHO = @tenKho,
        DCHI = @dchi,
        NGQLY = @ngQly
    WHERE MAKHO = @maKho;
END
GO

-- Xóa kho
CREATE PROCEDURE DeleteKho (
    @maKho CHAR(6)
)
AS
BEGIN
    DELETE FROM KHO
    WHERE MAKHO = @maKho;
END
GO

-- Chức năng quản lý nhà cung cấp
-- Thêm mới nhà cung cấp
CREATE PROCEDURE AddNhaCungCap (
    @maNCC CHAR(6),
    @tenNCC NVARCHAR(100),
    @dchi NVARCHAR(255),
    @sdt NVARCHAR(15),
    @email NVARCHAR(100)
)
AS
BEGIN
    INSERT INTO NCC (MANCC, TENNCC, DCHI, SDT, EMAIL)
    VALUES (@maNCC, @tenNCC, @dchi, @sdt, @email);
END
GO

-- Cập nhật thông tin nhà cung cấp
CREATE PROCEDURE UpdateNhaCungCap (
    @maNCC CHAR(6),
    @tenNCC NVARCHAR(100),
    @dchi NVARCHAR(255),
    @sdt NVARCHAR(15),
    @email NVARCHAR(100)
)
AS
BEGIN
    UPDATE NCC
    SET TENNCC = @tenNCC,
        DCHI = @dchi,
        SDT = @sdt,
        EMAIL = @email
    WHERE MANCC = @maNCC;
END
GO

-- Xóa nhà cung cấp
CREATE PROCEDURE DeleteNhaCungCap (
    @maNCC CHAR(6)
)
AS
BEGIN
    DELETE FROM NCC
    WHERE MANCC = @maNCC;
END
GO

-- Chức năng quản lý khách hàng
-- Thêm mới khách hàng
CREATE PROCEDURE AddKhachHang (
    @maKH CHAR(5),
    @tenKH NVARCHAR(100),
    @dchi NVARCHAR(255),
    @sdt NVARCHAR(15),
    @email NVARCHAR(100)
)
AS
BEGIN
    INSERT INTO KHACHHANG (MAKH, TENKH, DCHI, SDT, EMAIL)
    VALUES (@maKH, @tenKH, @dchi, @sdt, @email);
END
GO

-- Cập nhật thông tin khách hàng
CREATE PROCEDURE UpdateKhachHang (
    @maKH CHAR(5),
    @tenKH NVARCHAR(100),
    @dchi NVARCHAR(255),
    @sdt NVARCHAR(15),
    @email NVARCHAR(100)
)
AS
BEGIN
    UPDATE KHACHHANG
    SET TENKH = @tenKH,
        DCHI = @dchi,
        SDT = @sdt,
        EMAIL = @email
    WHERE MAKH = @maKH;
END
GO

-- Xóa khách hàng
CREATE PROCEDURE DeleteKhachHang (
    @maKH CHAR(5)
)
AS
BEGIN
    DELETE FROM KHACHHANG
    WHERE MAKH = @maKH;
END
GO

-- Chức năng quản lý nhân viên
-- Thêm mới nhân viên
CREATE PROCEDURE AddNhanVien (
    @maNV CHAR(5),
    @tenNV NVARCHAR(100),
    @dchi NVARCHAR(255),
    @sdt NVARCHAR(15)
)
AS
BEGIN
    INSERT INTO NHANVIEN(MANV, TENNV, DCHI, SDT)
    VALUES (@maNV, @tenNV, @dchi, @sdt);
END
GO

-- Cập nhật thông tin nhân viên
CREATE PROCEDURE UpdateNhanVien (
    @maNV CHAR(5),
    @tenNV NVARCHAR(100),
    @dchi NVARCHAR(255),
    @sdt NVARCHAR(15)
)
AS
BEGIN
    UPDATE NHANVIEN
    SET TENNV = @tenNV,
        DCHI = @dchi,
        SDT = @sdt
    WHERE MANV = @maNV;
END
GO

-- Xóa nhân viên
CREATE PROCEDURE DeleteNhanVien (
    @maNV CHAR(5)
)
AS
BEGIN
    DELETE FROM NHANVIEN
    WHERE MANV = @maNV;
END
GO

-- Chức năng tra cứu
-- Stored Procedure để tra cứu sản phẩm
CREATE PROCEDURE TraCuuSanPham (
    @tenSP NVARCHAR(100),
	@maSP CHAR(5),
	@maNCC CHAR(6),
	@maLSP char(6)
)
AS
BEGIN
	declare @searchSQL nvarchar(1000),
			@whereSQL nvarchar(1000),
			@ParmDefinition nvarchar(1000)

	set @whereSQL = N' where 1=1 '

	if isnull(@tenSP, '') <> ''
	begin
		set @tenSP = '%' + @tenSP + '%'
		set	@whereSQL += N' and TENSP LIKE @tenSP'
	end

	if isnull(@maSP, '') <> ''
		set @whereSQL += N' and MASP = @maSP'

	if isnull(@maNCC, '') <> ''
		set @whereSQL += N' and MANCC = @maNCC'

	if isnull(@maLSP, '') <> ''
		set @whereSQL += N' and MALOAISP = @maLSP'

	set @ParmDefinition = N'@tenSP NVARCHAR(100),
							@maSP CHAR(5),
							@maNCC CHAR(6),
							@maLSP char(6)'
	
	set @searchSQL = N'select * from SANPHAM ' + @whereSQL

	exec sp_executesql @searchSQL, 
					@ParmDefinition,
					@tenSP,
					@maSP,
					@maNCC,
					@maLSP

END
GO

-- Stored Procedure để tra cứu hóa đơn nhập kho
CREATE PROCEDURE TraCuuPhieuNhapKho (
    @maPNK CHAR(6),
	@maKho char(6),
	@maNV char(5),
	@fromDate smalldatetime,
	@toDate smalldatetime
)
AS
BEGIN
    declare @whereSQL nvarchar(1000),
			@ParmDefinition nvarchar(200),
			@searchSQL nvarchar(1000)

	set @whereSQL = N' where 1=1 '

	if isnull(@maPNK, '') <> ''
		set @whereSQL += N' and MAPNK = @maPNK'

	if isnull(@maKho, '') <> ''
		set @whereSQL += N' and MAKHO = @maKho'

	if isnull(@maNV, '') <> ''
		set @whereSQL += N' and MANV = @maNV'

	if isnull(@fromDate, '') <> ''
		set @whereSQL += N' and NGAYNHAP >= @fromDate'

	if isnull(@toDate, '') <> ''
		set @whereSQL += N' and NGAYNHAP <= @toDate'

	set @ParmDefinition = N'@maPNK char(6),
							@maKho char(6),
							@maNV char(5),
							@fromDate smalldatetime,
							@toDate smalldatetime'

	set @searchSQL = N'select * from PHIEUNHAPKHO' + @whereSQL

	exec sp_executesql @searchSQL, @ParmDefinition,
									@maPNK,
									@maKho,
									@maNV,
									@fromDate,
									@toDate
END
GO

-- Stored Procedure để tra cứu hóa đơn xuất kho
CREATE PROCEDURE TraCuuPhieuXuatKho (
    @maPXK CHAR(6),
	@maKho char(6),
	@maKH char(5),
	@maNV char(5),
	@fromDate smalldatetime,
	@toDate smalldatetime
)
AS
BEGIN
    declare @whereSQL nvarchar(1000),
			@ParmDefinition nvarchar(200),
			@searchSQL nvarchar(1000)

	set @whereSQL = N' where 1=1 '

	if isnull(@maPXK, '') <> ''
		set @whereSQL += N' and MAPXK = @maPXK'

	if isnull(@maKho, '') <> ''
		set @whereSQL += N' and MAKHO = @maKho'

	if isnull(@maKH, '') <> ''
		set @whereSQL += N' and MAKH = @maKH'

	if isnull(@maNV, '') <> ''
		set @whereSQL += N' and MANV = @maNV'

	if isnull(@fromDate, '') <> ''
		set @whereSQL += N' and NGAYXUAT >= @fromDate'

	if isnull(@toDate, '') <> ''
		set @whereSQL += N' and NGAYXUAT <= @toDate'

	set @ParmDefinition = N'@maPXK char(6),
							@maKho char(6),
							@maKH char(5),
							@maNV char(5),
							@fromDate smalldatetime,
							@toDate smalldatetime'

	set @searchSQL = N'select * from PHIEUXUATKHO' + @whereSQL

	exec sp_executesql @searchSQL, @ParmDefinition,
									@maPXK,
									@maKho,
									@maKH,
									@maNV,
									@fromDate,
									@toDate
END
GO

-- Stored Procedure để tra cứu sản phẩm trong kho lưu trữ
create proc TraCuuSPTrongKho (
				@maKho char(6),
				@maSP char(5)
)
as
begin
	declare @whereSQL nvarchar(100),
			@ParmDefinition nvarchar(100),
			@searchSQL nvarchar(200)

	set @whereSQL = ' where 1=1 '

	if isnull(@maKho, '') <> ''
		set @whereSQL += ' and MAKHO = @maKho'

	if isnull(@maSP, '') <> ''
		set @whereSQL += ' and MASP = @maSP'

	set @ParmDefinition = N'@maKho char(6),
							@maSP char(5)'

	set @searchSQL = N'select * from LUUTRU' + @whereSQL

	exec sp_executesql @searchSQL,
						@ParmDefinition,
						@maKho,
						@maSP
end
go

-- Stored Procedure để tra cứu nhân viên
create proc TraCuuNV (
				@maNV char(5),
				@tenNV nvarchar(100),
				@diaChi nvarchar(100),
				@sdt varchar(10)
)
as
begin
	declare @whereSQL nvarchar(300),
			@ParmDefinition nvarchar(300),
			@searchSQL nvarchar(1000)

	set @whereSQL = N' where 1=1 '

	if isnull(@maNV, '') <> ''
		set @whereSQL += N' and MANV = @maNV'

	if isnull(@tenNV, '') <> ''
	begin
		set @tenNV = '%' + @tenNV + '%'
		set @whereSQL += N' and TENNV like @tenNV'
	end

	if isnull(@diaChi, '') <> ''
	begin
		set @diaChi = '%' + @diaChi + '%'
		set @whereSQL += N' and DCHI like @diaChi'
	end

	if isnull(@sdt, '') <> ''
	begin
		set @sdt = '%' + @sdt + '%'
		set @whereSQL += N' and SDT like @sdt'
	end

	set @ParmDefinition = N'@maNV char(6),
							@tenNV nvarchar(100),
							@diaChi nvarchar(100),
							@sdt varchar(10)'

	set @searchSQL = N'select * from NHANVIEN' + @whereSQL

	exec sp_executesql @searchSQL,
						@ParmDefinition,
						@maNV,
						@tenNV,
						@diaChi,
						@sdt
end
go

-- Stored Procedure để tra cứu nhà cung cấp
create proc TraCuuNCC (
				@maNCC char(6),
				@tenNCC nvarchar(100),
				@diaChi nvarchar(100),
				@sdt varchar(10),
				@email varchar(50)
)
as
begin
	declare @whereSQL nvarchar(300),
			@ParmDefinition nvarchar(300),
			@searchSQL nvarchar(1000)

	set @whereSQL = N' where 1=1 '

	if isnull(@maNCC, '') <> ''
		set @whereSQL += N' and MANCC = @maNCC'

	if isnull(@tenNCC, '') <> ''
	begin
		set @tenNCC = '%' + @tenNCC + '%'
		set @whereSQL += N' and TENNCC like @tenNCC'
	end

	if isnull(@diaChi, '') <> ''
	begin
		set @diaChi = '%' + @diaChi + '%'
		set @whereSQL += N' and DCHI like @diaChi'
	end

	if isnull(@sdt, '') <> ''
	begin
		set @sdt = '%' + @sdt + '%'
		set @whereSQL += N' and SDT like @sdt'
	end

	if isnull(@email, '') <> ''
	begin
		set @email = '%' + @email + '%'
		set @whereSQL += N' and EMAIL like @email'
	end

	set @ParmDefinition = N'@maNCC char(6),
							@tenNCC nvarchar(100),
							@diaChi nvarchar(100),
							@sdt varchar(10),
							@email varchar(50)'

	set @searchSQL = N'select * from NCC' + @whereSQL

	exec sp_executesql @searchSQL,
						@ParmDefinition,
						@maNCC,
						@tenNCC,
						@diaChi,
						@sdt,
						@email
end
go

-- Stored Procedure để tra cứu khách hàng
create proc TraCuuKH (
				@maKH char(5),
				@tenKH nvarchar(100),
				@diaChi nvarchar(100),
				@sdt varchar(10),
				@email varchar(50)
)
as
begin
	declare @whereSQL nvarchar(300),
			@ParmDefinition nvarchar(300),
			@searchSQL nvarchar(1000)

	set @whereSQL = N' where 1=1 '

	if isnull(@maKH, '') <> ''
		set @whereSQL += N' and MAKH = @maKH'

	if isnull(@tenKH, '') <> ''
	begin
		set @tenKH = '%' + @tenKH + '%'
		set @whereSQL += N' and TENKH like @tenKH'
	end

	if isnull(@diaChi, '') <> ''
	begin
		set @diaChi = '%' + @diaChi + '%'
		set @whereSQL += N' and DCHI like @diaChi'
	end

	if isnull(@sdt, '') <> ''
	begin
		set @sdt = '%' + @sdt + '%'
		set @whereSQL += N' and SDT like @sdt'
	end

	if isnull(@email, '') <> ''
	begin
		set @email = '%' + @email + '%'
		set @whereSQL += N' and EMAIL like @email'
	end

	set @ParmDefinition = N'@maKH char(6),
							@tenKH nvarchar(100),
							@diaChi nvarchar(100),
							@sdt varchar(10),
							@email varchar(50)'

	set @searchSQL = N'select * from KHACHHANG' + @whereSQL

	exec sp_executesql @searchSQL,
						@ParmDefinition,
						@maKH,
						@tenKH,
						@diaChi,
						@sdt,
						@email
end
go

-- Stored Procedure để tính tổng số lượng nhập/xuất kho
create proc TongSL_Nhap_Xuat (
				@thang int,
				@nam int
)
as
begin
	declare @whenNhap nvarchar(100),
			@whenXuat nvarchar(100),
			@ParmDefinition nvarchar(100),
			@stamentSQL nvarchar(1000)

	set @whenNhap = ''
	set	@whenXuat = ''

	if @thang is not null
	begin
		set @whenNhap += ' and month(NGAYNHAP) = @thang'
		set @whenXuat += ' and month(NGAYXUAT) = @thang'
	end

	if @nam is not null
	begin
		set @whenNhap += ' and year(NGAYNHAP) = @nam'
		set @whenXuat += ' and year(NGAYXUAT) = @nam'
	end

	set @ParmDefinition = N'@thang int,
							@nam int'

	set @stamentSQL = N'select t1.MASP, t1.TENSP, TongSL_Nhap, TongSL_Xuat
						from
							(select sp.MASP, TENSP, 
									sum(case when CT_PNK.SL is not null '+@whenNhap+' then CT_PNK.SL else 0 end) as TongSL_Nhap	
							from PHIEUNHAPKHO pnk
								join CT_PNK on pnk.MAPNK = CT_PNK.MAPNK
								right join SANPHAM sp on sp.MASP = CT_PNK.MASP		
							group by sp.MASP, TENSP) as t1
						join
							(select sp.MASP, TENSP, 
									sum(case when CT_PXK.SL is not null '+@whenXuat+' then CT_PXK.SL else 0 end) as TongSL_Xuat
							from PHIEUXUATKHO pxk
								join CT_PXK on pxk.MAPXK = CT_PXK.MAPXK
								right join SANPHAM sp on sp.MASP = CT_PXK.MASP		
							group by sp.MASP, TENSP) as t2
						on t1.MASP = t2.MASP'

	exec sp_executesql @stamentSQL,
						@ParmDefinition,
						@thang,
						@nam
end
go

-- FUNCTION
-- Function để tính tổng giá trị hàng tồn kho trong một kho
CREATE FUNCTION CalculateInventoryValue (
    @warehouseId char(6)
)
RETURNS DECIMAL(18, 2)
AS
BEGIN
    DECLARE @totalValue DECIMAL(18, 2) = 0;
    SELECT @totalValue = SUM(LUUTRU.SL * SANPHAM.GIABAN)
    FROM LUUTRU
    JOIN SANPHAM ON LUUTRU.MASP = SANPHAM.MASP
    WHERE LUUTRU.MAKHO = @warehouseId;
    RETURN @totalValue;
END
GO


---------------------------------------------------------------------QUẢN LÝ THÔNG TIN---------------------------------------------------------------------

--BACK UP--
--BACKUP DATABASE QLHangTonKho TO DISK = 'D:\Quản lý thông tin - IE103\BACK_UP\QLHTK.BAK'
--RESTORE--
--RESTORE DATABASE QLHangTonKho FROM DISK = 'D:\Quản lý thông tin - IE103\BACK_UP\QLHTK.BAK'
--IMPORT--
--EXPORT--

--XÁC THỰC--
-- Xác thực cho nhân viên quản lý
IF EXISTS(SELECT * FROM sys.server_principals WHERE name = 'ManagerUser')
BEGIN
    DROP LOGIN ManagerUser
END
CREATE LOGIN ManagerUser WITH PASSWORD = '1'
CREATE USER ManagerUser FOR LOGIN ManagerUser

-- Xác thực cho nhân viên bình thường
IF EXISTS(SELECT * FROM sys.server_principals WHERE name = 'EmployeeUser')
BEGIN
    DROP LOGIN EmployeeUser
END
CREATE LOGIN EmployeeUser WITH PASSWORD = '1'
CREATE USER EmployeeUser FOR LOGIN EmployeeUser

--PHÂN QUYỀN--
-- Tạo các vai trò
CREATE ROLE ManagerRole
CREATE ROLE EmployeeRole

--Nhân viên quản lý có đủ 3 quyển U,I,D đối với tất cả các bảng.
GRANT ALTER, DELETE, INSERT, SELECT, UPDATE, EXECUTE TO ManagerRole

--Nhân viên bình thường có quyền thêm đối với bảng PHIEUNHAPKHO, PHIEUXUATKHO, CT_PNK, CT_PXK
GRANT INSERT, SELECT ON PHIEUNHAPKHO TO EmployeeRole
GRANT INSERT, SELECT ON PHIEUXUATKHO TO EmployeeRole
GRANT INSERT, SELECT ON CT_PNK TO EmployeeRole
GRANT INSERT, SELECT ON CT_PXK TO EmployeeRole
GRANT SELECT ON SANPHAM TO EmployeeRole

GRANT EXECUTE ON AddPhieuNhapKho TO EmployeeRole
GRANT EXECUTE ON AddPhieuXuatKho TO EmployeeRole
GRANT EXECUTE ON AddChiTietPNK TO EmployeeRole
GRANT EXECUTE ON AddChiTietPXK TO EmployeeRole

GRANT EXECUTE ON TraCuuSanPham TO EmployeeRole
GRANT EXECUTE ON TraCuuPhieuNhapKho TO EmployeeRole
GRANT EXECUTE ON TraCuuPhieuXuatKho TO EmployeeRole

-- Gán vai trò cho các user
EXEC sp_addrolemember 'ManagerRole', 'ManagerUser'
EXEC sp_addrolemember 'EmployeeRole', 'EmployeeUser'
