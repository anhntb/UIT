---------------------------------E. CURSOR---------------------------

USE QLDT
GO


----------------------------------------------------------------
--Tạo một bảng tên là DETAI_DIEM. Cấu trúc bảng như sau:
--DETAI_DIEM(MSDT, DIEMTB)

CREATE TABLE DETAI_DIEM (
	MSDT CHAR(6) FOREIGN KEY REFERENCES DETAI(MSDT),
	DIEMTB FLOAT
)
GO

--THÊM DỮ LIỆU MSDT CHO BẢNG
INSERT DETAI_DIEM (MSDT)
SELECT MSDT FROM DETAI
GO

--XÓA BẢNG
--DROP TABLE DETAI_DIEM
--GO



---------------------------------------------------------------------
--CAU 1
--1. Viết Cursor tính điểm trung bình cho từng đề tài. Sau đó lưu kết quả vào 
--bảng DETAI_DIEM.

DECLARE P CURSOR FOR SELECT MSDT, AVG(DIEMTONGHOP.DIEM)
					 FROM (SELECT * FROM GV_HDDT UNION
						  SELECT * FROM GV_PBDT UNION
						  SELECT * FROM GV_UVDT) AS DIEMTONGHOP
					 GROUP BY MSDT
OPEN P
DECLARE @MSDT CHAR(6), @DTB FLOAT
FETCH NEXT FROM P INTO @MSDT, @DTB
WHILE (@@FETCH_STATUS = 0)
BEGIN
	UPDATE DETAI_DIEM SET DIEMTB = @DTB WHERE MSDT = @MSDT

	FETCH NEXT FROM P INTO @MSDT, @DTB
END
CLOSE P
DEALLOCATE P

--KIỂM TRA
SELECT * FROM DETAI_DIEM
GO



---------------------------------------------------------------------
--CAU 2
--2. Gom các bước xử lý của Cursor ở câu 1 vào một Stored Procedure.

CREATE PROC TINH_DTB
AS
BEGIN
	DECLARE P CURSOR FOR SELECT MSDT, AVG(DIEMTONGHOP.DIEM)
						 FROM (SELECT * FROM GV_HDDT UNION
							  SELECT * FROM GV_PBDT UNION
							  SELECT * FROM GV_UVDT) AS DIEMTONGHOP
						 GROUP BY MSDT
	OPEN P
	DECLARE @MSDT CHAR(6), @DTB FLOAT
	FETCH NEXT FROM P INTO @MSDT, @DTB
	WHILE (@@FETCH_STATUS = 0)
	BEGIN
		UPDATE DETAI_DIEM SET DIEMTB = @DTB WHERE MSDT = @MSDT

		FETCH NEXT FROM P INTO @MSDT, @DTB
	END
	CLOSE P
	DEALLOCATE P
END

--THỰC THI
EXEC TINH_DTB
GO

--KIỂM TRA
SELECT * FROM DETAI_DIEM
GO

--XÓA
DROP PROC TINH_DTB
GO



------------------------------------------------------------------------------
--CAU 3
--3. Tạo thêm cột XEPLOAI có kiểu là NVARCCHAR(20) trong bảng 
--DETAI_DIEM, viết Cursor cập nhật kết quả xếp loại cho mỗi đề tài như sau
----------------+ "Xuất sắc": điểm trung bình từ 9 đến 10.
----------------+ "Giỏi": điểm trung bình từ 8 đến 9. 
----------------+ "Khá": điểm trung bình từ 7 đến 8. 
----------------+ "Trung bình khá": điểm trung bình từ 6 đến 7.
----------------+ "Trung bình": điểm trung bình từ 5 đến 6.
----------------+ "Yếu": điểm trung bình từ 4 đến 5.
----------------+ "Kém": điểm trung bình dưới 4.

--Thêm cột XEPLOAI có kiểu là NVARCCHAR(20) trong bảng DETAI_DIEM
ALTER TABLE DETAI_DIEM ADD XEPLOAI NVARCHAR(20)
GO

--Cursor cập nhật kết quả xếp loại
DECLARE P CURSOR FOR SELECT MSDT, DIEMTB FROM DETAI_DIEM
OPEN P
DECLARE @MSDT CHAR(6), @DTB FLOAT
FETCH NEXT FROM P INTO @MSDT, @DTB
WHILE (@@FETCH_STATUS = 0)
BEGIN
	DECLARE @XEPLOAI NVARCHAR(20)

	IF (@DTB >= 9)
		SET @XEPLOAI = N'Xuất sắc'
	ELSE IF (@DTB >= 8)
		SET @XEPLOAI = N'Giỏi'
	ELSE IF (@DTB >= 7)
		SET @XEPLOAI = N'Khá'
	ELSE IF (@DTB >= 6)
		SET @XEPLOAI = N'Trung bình khá'
	ELSE IF (@DTB >= 5)
		SET @XEPLOAI = N'Trung bình'
	ELSE IF (@DTB >= 4)
		SET @XEPLOAI = N'Yếu'
	ELSE
		SET @XEPLOAI = N'Kém'

	UPDATE DETAI_DIEM SET XEPLOAI = @XEPLOAI WHERE MSDT = @MSDT

	FETCH NEXT FROM P INTO @MSDT, @DTB
END
CLOSE P
DEALLOCATE P

--KIỂM TRA
SELECT * FROM DETAI_DIEM
GO