--------------------------------------A. STORED PROCEDURES VỚI THAM SỐ VÀO------------------------------------
USE QLDT 
GO

-- CTRL + K + C: comment nhieu cau

-----------------------------------------------------------------------------------------------------------
--CAU 1
--1. Tham số vào là MSGV, TENGV, SODT, DIACHI, MSHH, NAMHH.
--Trước khi insert dữ liệu cần kiểm tra MSHH đã tồn tại trong table HOCHAM chưa,--nếu chưa thì trả về giá trị 0.
CREATE PROC PROC_GV_INSERT_MSHH
	@MSGV INT, @TENGV NVARCHAR(30), @DIACHI NVARCHAR(50), 	@SODT VARCHAR(10), @MSHH INT, @NAMHH SMALLDATETIME
AS
BEGIN
	IF NOT EXISTS (SELECT * FROM HOCHAM WHERE MSHH = @MSHH)
	BEGIN
		PRINT N'MSHH CHUA TON TAI'
		RETURN 0
	END

	INSERT INTO GIAOVIEN VALUES (@MSGV, @TENGV, @DIACHI, @SODT, @MSHH, @NAMHH) --nhớ chú ý thứ tự
	PRINT N'THEM THANH CONG'
END
GO

--1.1. THỰC THI
--Thành công
EXEC PROC_GV_INSERT_MSHH @MSGV = 00999, @TENGV = 'DO PHUC', @SODT = '0342343242',
@DIACHI = 'THU DUC', @MSHH = 2, @NAMHH = '2022'
GO

--Thất bại
EXEC PROC_GV_INSERT_MSHH @MSGV = 00999, @TENGV = 'TRAN THI X', @SODT = '0342343242',
@DIACHI = 'HA NOI', @MSHH = 4, @NAMHH = '2010'
GO

--1.2. KIỂM TRA
SELECT * FROM GIAOVIEN
GO

--1.3. KHÔI PHỤC DỮ LIỆU (NẾU CÓ)
DELETE FROM GIAOVIEN WHERE MSGV = 00999
GO

--1.4. XÓA
DROP PROC PROC_GV_INSERT_MSHH
GO



--------------------------------------------------------------------------------------------------------------------------
--CAU 2
--2. Tham số vào là MSGV, TENGV, SODT, DIACHI, MSHH, NAMHH.
--Trước khi insert dữ liệu cần kiểm tra MSGV trong table GIAOVIEN có trùng không,--nếu trùng thì trả về giá trị 0.CREATE PROC PROC_GV_INSERT_MSGV
	@MSGV INT, @TENGV NVARCHAR(30), @DIACHI NVARCHAR(50), 	@SODT VARCHAR(10), @MSHH INT, @NAMHH SMALLDATETIME
AS
BEGIN
	IF EXISTS (SELECT * FROM GIAOVIEN WHERE MSGV = @MSGV)
	BEGIN
		PRINT 'MSGV DA TON TAI'
		RETURN 0
	END

	INSERT INTO GIAOVIEN VALUES (@MSGV, @TENGV, @DIACHI, @SODT, @MSHH, @NAMHH)
	PRINT N'THEM THANH CONG'ENDGO--2.1. THỰC THI
--Thành công
EXEC PROC_GV_INSERT_MSGV @MSGV = 111, @TENGV = 'DO PHUC', @SODT = '0342343242',
@DIACHI = 'THU DUC', @MSHH = 2, @NAMHH = '2022'
GO

--Thất bại
EXEC PROC_GV_INSERT_MSGV @MSGV = 201, @TENGV = 'TRAN THI X', @SODT = '0342343242',
@DIACHI = 'HA NOI', @MSHH = 2, @NAMHH = '2010'
GO

--2.2. KIỂM TRA
SELECT * FROM GIAOVIEN
GO

--2.3. KHÔI PHỤC DỮ LIỆU (NẾU CÓ)
DELETE FROM GIAOVIEN WHERE MSGV = 111
GO--2.4. XÓADROP PROC PROC_GV_INSERT_MSGVGO--------------------------------------------------------------------------------------------------------------------CAU 3--3. Giống (1) và (2) kiểm tra xem MSGV có trùng không? MSHH có tồn tại chưa? 
--Nếu MSGV trùng thì trả về 0. Nếu MSHH chưa tồn tại trả về 1, ngược lại cho insert dữ liệu.CREATE PROCEDURE PROC_GV_INSERT_MSGV_MSHH 	@MSGV INT, @TENGV NVARCHAR(30), @DIACHI NVARCHAR(50), 	@SODT VARCHAR(10), @MSHH INT, @NAMHH SMALLDATETIMEASBEGIN	IF EXISTS (SELECT * FROM GIAOVIEN WHERE MSGV = @MSGV)	BEGIN		PRINT N'MSGV đã tồn tại'		RETURN 0	END	IF NOT EXISTS (SELECT * FROM HOCHAM WHERE MSHH = @MSHH)	BEGIN		PRINT N'MSHH chưa tồn tại'		RETURN 1	END	INSERT INTO GIAOVIEN VALUES (@MSGV, @TENGV, @DIACHI, @SODT, @MSHH, @NAMHH)	PRINT N'Đã thêm thành công'ENDGO--3.1. THỰC THI
--Thành công
EXEC PROC_GV_INSERT_MSGV_MSHH '123', 'NGUYEN VAN A', 'HCM', '0123456789', 2, '1999'
GO

--Thất bại
--1. Trùng MSGV
EXEC PROC_GV_INSERT_MSGV_MSHH '203', 'NGUYEN VAN A', 'HCM', '0123342789', 2, '1998'
GO
--2. MSHH không tồn tại
EXEC PROC_GV_INSERT_MSGV_MSHH '123', 'NGUYEN VAN A', 'HCM', '0123342789', 4, '1998'
GO

--3.2. KIỂM TRA
SELECT * FROM GIAOVIEN
GO

--3.3. KHÔI PHỤC DỮ LIỆU (NẾU CÓ)
DELETE FROM GIAOVIEN WHERE MSGV = 123
GO

--3.4. XÓA
DROP PROC PROC_GV_INSERT_MSGV_MSHH
GO



-----------------------------------------------------------------------------------------------------------------
--CAU 4
--4. Đưa vào MSDT cũ, TENDT mới. Hãy cập nhật tên đề tài mới với mã đề tài cũ không đổi 
--nếu không tìm thấy trả về 0, ngược lại cập nhật và trả về 1.

CREATE PROCEDURE PROC_DETAI_UPDATE_TENDT
	@MSDT CHAR(6), @TENDT NVARCHAR(30)
AS
BEGIN
	IF NOT EXISTS (SELECT * FROM DETAI WHERE MSDT = @MSDT)
	BEGIN
		PRINT N'MSDT không tồn tại'
		RETURN 0
	END

	ELSE
	BEGIN
		UPDATE DETAI SET TENDT = @TENDT WHERE MSDT = @MSDT
		PRINT N'Đã cập nhật tên đề tài thành công'
		RETURN 1
	END
END
GO

--4.1. THỰC THI
--Thành công
EXEC PROC_DETAI_UPDATE_TENDT '97001', 'QUAN LY THONG TIN'
GO

--Thất bại
EXEC PROC_DETAI_UPDATE_TENDT '97009', 'QUAN LY THONG TIN'
GO

--4.2. KIỂM TRA
SELECT * FROM DETAI
GO

--4.3. KHÔI PHỤC DỮ LIỆU (NẾU CÓ)
UPDATE DETAI SET TENDT = N'Quản lý thư viện' WHERE MSDT = '97001'
GO

--4.4. XÓA
DROP PROC PROC_DETAI_UPDATE_TENDT
GO



-------------------------------------------------------------------------------------------------------
--CAU 5
--5. Tham số đưa vào MSSV, TENSV mới, DIACHI mới. Hãy cập nhật sinh viên trên với MSSV không đổi,
--nếu không tìm thấy trả về 0, ngược lại cập nhật và trả về 1.

CREATE PROC PROC_SV_UPDATE_TENSV_DIACHI
	@MSSV CHAR(8), @TENSV NVARCHAR(30), @DIACHI NCHAR(50)
AS
BEGIN
	IF EXISTS (SELECT * FROM SINHVIEN WHERE MSSV = @MSSV)
	BEGIN
		UPDATE SINHVIEN
		SET TENSV = @TENSV, DIACHI = @DIACHI
		WHERE MSSV = @MSSV

		PRINT N'Đã cập nhật thành công'
		RETURN 1
	END

	ELSE
	BEGIN
		PRINT N'MSSV không tồn tại'
		RETURN 0
	END
END
GO

--5.1. THỰC THI
--Thành công
EXEC PROC_SV_UPDATE_TENSV_DIACHI '13520001', 'NGUYEN VAN A', 'THU DUC'
GO

--Thất bại
EXEC PROC_SV_UPDATE_TENSV_DIACHI '12345678', 'NGUYEN VAN A', 'THU DUC'
GO

--5.2. KIỂM TRA
SELECT * FROM SINHVIEN 
GO

--5.3. KHÔI PHỤC DỮ LIỆU (NẾU CÓ)
UPDATE SINHVIEN 
SET TENSV = N'Nguyễn Văn An', DIACHI = N'THỦ ĐỨC'
WHERE MSSV = '13520001'
GO

--5.4. XÓA
DROP PROC PROC_SV_UPDATE_TENSV_DIACHI
GO