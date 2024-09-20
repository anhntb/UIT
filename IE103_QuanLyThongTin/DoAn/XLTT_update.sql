use QLHangTonKho
go

-- Trigger cập nhật số lượng hàng hóa sau khi nhập kho
-- drop trigger AfterInsertCT_PNK
CREATE TRIGGER AfterInsertCT_PNK
ON CT_PNK
AFTER INSERT
AS
BEGIN
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

-- ngày nhập xuất kho sẽ được điền tự động bằng getdate()
-- drop trigger trg_CheckNgayNhapNgayXuat
--CREATE TRIGGER trg_CheckNgayNhapNgayXuat
--ON CT_PNK
--FOR INSERT, UPDATE
--AS
--BEGIN
--    -- Biến để lưu trữ kết quả kiểm tra
--    DECLARE @ErrorMessage NVARCHAR(4000);

--    -- Kiểm tra nếu có bản ghi vi phạm điều kiện
--    IF EXISTS (
--        SELECT 1
--        FROM inserted i
--        JOIN PHIEUNHAPKHO pnk ON i.MAPNK = pnk.MAPNK
--        JOIN PHIEUXUATKHO pxk ON pnk.MAKHO = pxk.MAKHO
--        WHERE pnk.NGAYNHAP > (
--            SELECT MIN(pxk.NGAYXUAT)
--            FROM PHIEUXUATKHO pxk
--            WHERE pxk.MAKHO = pnk.MAKHO
--        )
--    )
--    BEGIN
--        -- Thông báo lỗi và rollback transaction
--        SET @ErrorMessage = N'Ngày nhập phải nhỏ hơn hoặc bằng ngày xuất.';
--        RAISERROR (@ErrorMessage, 16, 1);
--        ROLLBACK TRANSACTION;
--    END
--END
--GO

--CREATE TRIGGER trg_CheckGiaGocGiaNhap
--ON CT_PNK
--FOR INSERT, UPDATE
--AS
--BEGIN
--    -- Biến để lưu trữ kết quả kiểm tra
--    DECLARE @ErrorMessage NVARCHAR(4000);

--    -- Kiểm tra nếu có bản ghi vi phạm điều kiện
--    IF EXISTS (
--        SELECT 1
--        FROM inserted i
--        JOIN SANPHAM sp ON i.MASP = sp.MASP
--        WHERE sp.GIAGOC != i.GIANHAP
--    )
--    BEGIN
--        -- Thông báo lỗi và rollback transaction
--        SET @ErrorMessage = N'Giá gốc của sản phẩm phải bằng giá nhập.';
--        RAISERROR (@ErrorMessage, 16, 1);
--        ROLLBACK TRANSACTION;
--    END
--END
--GO

--CREATE TRIGGER trg_CheckGiaXuatGiaBan
--ON CT_PXK
--FOR INSERT, UPDATE
--AS
--BEGIN
--    -- Biến để lưu trữ kết quả kiểm tra
--    DECLARE @ErrorMessage NVARCHAR(4000);

--    -- Kiểm tra nếu có bản ghi vi phạm điều kiện
--    IF EXISTS (
--        SELECT 1
--        FROM inserted i
--        JOIN SANPHAM sp ON i.MASP = sp.MASP
--        WHERE sp.GIABAN != i.GIAXUAT
--    )
--    BEGIN
--        -- Thông báo lỗi và rollback transaction
--        SET @ErrorMessage = N'Giá xuất của sản phẩm phải bằng giá bán.';
--        RAISERROR (@ErrorMessage, 16, 1);
--        ROLLBACK TRANSACTION;
--    END
--END
--GO

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

-- Trigger cập nhật số lượng hàng hóa sau khi xuất kho
-- drop trigger AfterInsertCT_PXK
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
END
GO

-- Trigger xóa phiếu nhập kho
-- DROP TRIGGER DeletePNK
CREATE TRIGGER TRG_DeletePNK
ON PHIEUNHAPKHO
INSTEAD OF DELETE
AS
BEGIN
	DECLARE @MAPNK CHAR(6)
	SELECT @MAPNK = deleted.MAPNK FROM deleted

	DELETE FROM CT_PNK WHERE @MAPNK = CT_PNK.MAPNK
	DELETE FROM PHIEUNHAPKHO WHERE MAPNK = @MAPNK
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
END
GO

-- Trigger thêm mới sản phẩm
CREATE TRIGGER TRGG_INSERT_SANPHAM
ON SANPHAM
AFTER INSERT
AS
BEGIN
	DECLARE @MASP CHAR(5)
	SELECT @MASP = INSERTED.MASP FROM INSERTED

	DECLARE P CURSOR FOR SELECT MAKHO FROM KHO
	OPEN P
		DECLARE @MAKHO CHAR(6)
		FETCH NEXT FROM P INTO @MAKHO
		WHILE (@@FETCH_STATUS = 0)
		BEGIN
			INSERT INTO LUUTRU VALUES (@MAKHO, @MASP, 0)

			FETCH NEXT FROM P INTO @MAKHO
		END
	CLOSE P
	DEALLOCATE P
END
GO

drop trigger TRGG_INSERT_SANPHAM

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

	DELETE FROM CT_PXK WHERE MASP = @MASP
	DELETE FROM CT_PNK WHERE MASP = @MASP
	DELETE FROM LUUTRU WHERE MASP = @MASP
	DELETE FROM SANPHAM WHERE MASP = @MASP

	ALTER TABLE CT_PNK CHECK CONSTRAINT ALL
	ALTER TABLE CT_PXK CHECK CONSTRAINT ALL
	ALTER TABLE LUUTRU CHECK CONSTRAINT ALL

	PRINT N'XÓA THÀNH CÔNG'
END
GO

-- Trigger thêm mới kho
CREATE TRIGGER TRG_INSERT_KHO
ON KHO
AFTER INSERT
AS
BEGIN
	DECLARE @MAKHO CHAR(6)
	SELECT @MAKHO = INSERTED.MAKHO FROM INSERTED

	DECLARE P CURSOR FOR SELECT MASP FROM SANPHAM
	OPEN P
		DECLARE @MASP CHAR(5)
		FETCH NEXT FROM P INTO @MASP
		WHILE (@@FETCH_STATUS = 0)
		BEGIN
			INSERT INTO LUUTRU VALUES (@MAKHO, @MASP, 0)

			FETCH NEXT FROM P INTO @MASP
		END
	CLOSE P
	DEALLOCATE P
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

	DELETE FROM PHIEUNHAPKHO WHERE MAKHO = @MAKHO
	DELETE FROM PHIEUXUATKHO WHERE MAKHO = @MAKHO
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

	DELETE FROM SANPHAM WHERE MANCC = @MANCC
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

	DELETE FROM PHIEUXUATKHO WHERE MAKH = @MAKH
	DELETE FROM KHACHHANG WHERE MAKH = @MAKH

	ALTER TABLE PHIEUXUATKHO NOCHECK CONSTRAINT ALL

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

	ALTER TABLE PHIEUNHAPKHO NOCHECK CONSTRAINT ALL
	ALTER TABLE PHIEUXUATKHO NOCHECK CONSTRAINT ALL
	ALTER TABLE KHO NOCHECK CONSTRAINT ALL

	PRINT N'XÓA THÀNH CÔNG'
END
GO

-- Function để tính tổng giá trị hàng tồn kho trong một kho
-- drop function CalculateInventoryValue
-- select dbo.CalculateInventoryValue('KHO001')
CREATE FUNCTION CalculateInventoryValue (
    @warehouseId char(6)
)
RETURNS DECIMAL(18, 2)
AS
BEGIN
    DECLARE @totalValue DECIMAL(18, 2);
    SELECT @totalValue = SUM(LUUTRU.SL * SANPHAM.GIABAN)
    FROM LUUTRU
    JOIN SANPHAM ON LUUTRU.MASP = SANPHAM.MASP
    WHERE LUUTRU.MAKHO = @warehouseId;
    RETURN @totalValue;
END
GO

-- Function tổng giá trị hàng nhập kho theo tháng, năm (tham số = 0, thì tính tổng tất cả)
CREATE FUNCTION TongGiaTri_Nhap (
    @month int, @year int
)
RETURNS MONEY
AS
BEGIN
    DECLARE @sumValue MONEY;

	IF (@month = 0 AND @year = 0)
	BEGIN
		SELECT @sumValue = SUM(t2.SL * t3.GIAGOC)
		FROM PHIEUNHAPKHO t1
		JOIN CT_PNK t2 ON t1.MAPNK = t2.MAPNK
		JOIN SANPHAM t3 ON t2.MASP = t3.MASP
	END

	IF (@month != 0 AND @year != 0)
	BEGIN
		SELECT @sumValue = SUM(t2.SL * t3.GIAGOC)
		FROM PHIEUNHAPKHO t1
		JOIN CT_PNK t2 ON t1.MAPNK = t2.MAPNK
		JOIN SANPHAM t3 ON t2.MASP = t3.MASP
		WHERE MONTH(NGAYNHAP) = @month and YEAR(NGAYNHAP) = @year;
	END

	IF (@month = 0 AND @year != 0)
	BEGIN
		SELECT @sumValue = SUM(t2.SL * t3.GIAGOC)
		FROM PHIEUNHAPKHO t1
		JOIN CT_PNK t2 ON t1.MAPNK = t2.MAPNK
		JOIN SANPHAM t3 ON t2.MASP = t3.MASP
		WHERE YEAR(NGAYNHAP) = @year;
	END

	IF (@month != 0 AND @year = 0)
	BEGIN
		SELECT @sumValue = SUM(t2.SL * t3.GIAGOC)
		FROM PHIEUNHAPKHO t1
		JOIN CT_PNK t2 ON t1.MAPNK = t2.MAPNK
		JOIN SANPHAM t3 ON t2.MASP = t3.MASP
		WHERE MONTH(NGAYNHAP) = @month;
	END

    RETURN @sumValue;
END
GO

-- Function tổng giá trị hàng xuất kho theo tháng, năm (tham số = 0, thì tính tổng tất cả)
CREATE FUNCTION TongGiaTri_Xuat (
    @month int, @year int
)
RETURNS MONEY
AS
BEGIN
    DECLARE @sumValue MONEY;

	IF (@month = 0 AND @year = 0)
	BEGIN
		SELECT @sumValue = SUM(t2.SL * t3.GIABAN)
		FROM PHIEUXUATKHO t1
		JOIN CT_PXK t2 ON t1.MAPXK = t2.MAPXK
		JOIN SANPHAM t3 ON t2.MASP = t3.MASP
	END

	IF (@month != 0 AND @year != 0)
	BEGIN
		SELECT @sumValue = SUM(t2.SL * t3.GIABAN)
		FROM PHIEUXUATKHO t1
		JOIN CT_PXK t2 ON t1.MAPXK = t2.MAPXK
		JOIN SANPHAM t3 ON t2.MASP = t3.MASP
		WHERE MONTH(NGAYXUAT) = @month and YEAR(NGAYXUAT) = @year;
	END

	IF (@month = 0 AND @year != 0)
	BEGIN
		SELECT @sumValue = SUM(t2.SL * t3.GIABAN)
		FROM PHIEUXUATKHO t1
		JOIN CT_PXK t2 ON t1.MAPXK = t2.MAPXK
		JOIN SANPHAM t3 ON t2.MASP = t3.MASP
		WHERE YEAR(NGAYXUAT) = @year;
	END

	IF (@month != 0 AND @year = 0)
	BEGIN
		SELECT @sumValue = SUM(t2.SL * t3.GIABAN)
		FROM PHIEUXUATKHO t1
		JOIN CT_PXK t2 ON t1.MAPXK = t2.MAPXK
		JOIN SANPHAM t3 ON t2.MASP = t3.MASP
		WHERE MONTH(NGAYXUAT) = @month;
	END

    RETURN @sumValue;
END
GO

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

-- Stored Procedure để tra cứu sản phẩm
CREATE PROCEDURE TraCuuSanPham (
    @tenSP NVARCHAR(100)
)
AS
BEGIN
    SELECT * FROM SANPHAM
    WHERE TENSP LIKE '%' + @tenSP + '%';
END
GO

-- Stored Procedure để tra cứu hóa đơn nhập kho
CREATE PROCEDURE TraCuuPhieuNhapKho (
    @maPNK CHAR(6)
)
AS
BEGIN
    SELECT * FROM PHIEUNHAPKHO 
    WHERE MAPNK = @maPNK;

	SELECT * FROM CT_PNK
	WHERE MAPNK = @maPNK;
END
GO

-- Stored Procedure để tra cứu hóa đơn xuất kho
CREATE PROCEDURE TraCuuPhieuXuatKho (
    @maPXK CHAR(6)
)
AS
BEGIN
    SELECT * FROM PHIEUXUATKHO
    WHERE MAPXK = @maPXK;

	SELECT * FROM CT_PXK
	WHERE MAPXK = @maPXK;
END
GO

-- Cursor để tính tổng số lượng sản phẩm trong tất cả các kho
--DECLARE @totalQuantity INT;
--DECLARE productCursor CURSOR FOR
--SELECT MASP FROM SANPHAM;

--OPEN productCursor;

--FETCH NEXT FROM productCursor INTO @totalQuantity

--WHILE @@FETCH_STATUS = 0
--BEGIN
--    SELECT @totalQuantity = SUM(SL)
--    FROM LUUTRU
--    WHERE MASP = @totalQuantity;

--    FETCH NEXT FROM productCursor INTO @totalQuantity;
--END

--CLOSE productCursor;
--DEALLOCATE productCursor;
--GO

-- Chức năng quản lý sản phẩm
-- Thêm mới sản phẩm
-- số lượng mặc định khi thêm tên sản phẩm mới là 0
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
	@giaBan DECIMAL(18, 2),
    @maNCC CHAR(6),
    @maLoaiSP CHAR(6)
)
AS
BEGIN
    UPDATE SANPHAM
    SET TENSP = @tenSP,
        DVTINH = @dvTinh,
        GIAGOC = @giaGoc,
        GIABAN = @giaBan,
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

---- Xóa nhân viên
--CREATE PROCEDURE DeleteNhanVien (
--    @maNV CHAR(5)
--)
--AS
--BEGIN
--    DELETE FROM NHANVIEN
--    WHERE MANV = @maNV;
--END
--GO
