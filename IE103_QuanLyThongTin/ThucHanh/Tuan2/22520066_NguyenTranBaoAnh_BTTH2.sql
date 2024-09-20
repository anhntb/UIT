--------------------------------PHẦN 1--------------------------------
----------------------------------------------------------------------
--TẠO CƠ SỞ DỮ LIỆU
CREATE DATABASE QLDT;
GO

USE QLDT;
GO

--USE master ;  
--GO  
--DROP DATABASE QLDT ;  
--GO  

------------------------------------
CREATE TABLE SINHVIEN
(
	MSSV CHAR(8) PRIMARY KEY,
	TENSV NVARCHAR(30) NOT NULL,
	SODT VARCHAR(10),
	LOP CHAR(10) NOT NULL,
	DIACHI NCHAR(30) NOT NULL
)
select*from SINHVIEN;
-------------------------------------
CREATE TABLE DETAI
(
	MSDT CHAR(6) PRIMARY KEY,
	TENDT NVARCHAR(30) NOT NULL
)
select*from DETAI;
-------------------------------------
CREATE TABLE HOCVI
(
	MSHV INT, 
	TENHV nvarchar(20) NOT NULL,
	PRIMARY KEY(MSHV)
)
select*from HOCVI;
--------------------------------------
CREATE TABLE HOCHAM
(
	MSHH int, 
	TENHH nvarchar(20) NOT NULL,
	PRIMARY KEY(MSHH)
)
select*from HOCHAM;
-------------------------------------
CREATE TABLE SV_DETAI
(
	MSSV char(8), 
	MSDT char(6),
	PRIMARY KEY(MSSV, MSDT)
)
ALTER TABLE SV_DETAI ADD
CONSTRAINT FK_SVDT_SV FOREIGN KEY(MSSV) REFERENCES SINHVIEN(MSSV),
CONSTRAINT FK_SVDT_DT FOREIGN KEY(MSDT) REFERENCES DETAI(MSDT);
select*from SV_DETAI;
-------------------------------------
CREATE TABLE GIAOVIEN
(
	MSGV	int, 
	TENGV	nvarchar(30) NOT NULL, 
	DIACHI	nvarchar(50) NOT NULL, 
	SODT	varchar(10) NOT NULL, 
	MSHH	int, 
	NAMHH	smalldatetime NOT NULL,
	PRIMARY KEY(MSGV)
)
ALTER TABLE GIAOVIEN ADD CONSTRAINT FK_GV_HH FOREIGN KEY(MSHH) REFERENCES HOCHAM(MSHH);
select*from GIAOVIEN;
------------------------------------
CREATE TABLE CHUYENNGANH
(
	MSCN int, 
	TENCN nvarchar(30) NOT NULL,
	PRIMARY KEY(MSCN)
)
select*from CHUYENNGANH;
-------------------------------------
CREATE TABLE GV_HV_CN
(
	MSGV	int, 
	MSHV	int, 
	MSCN	int, 
	NAM		smalldatetime NOT NULL,
	PRIMARY KEY(MSGV, MSHV, MSCN)
)
ALTER TABLE GV_HV_CN ADD
CONSTRAINT FK__GV FOREIGN KEY(MSGV) REFERENCES GIAOVIEN(MSGV),
CONSTRAINT FK__HV FOREIGN KEY(MSHV) REFERENCES HOCVI(MSHV),
CONSTRAINT FK__CN FOREIGN KEY(MSCN) REFERENCES CHUYENNGANH(MSCN);
select*from GV_HV_CN;

--------------------------------------
CREATE TABLE GV_HDDT
(
	MSGV int, 
	MSDT char(6), 
	DIEM float NOT NULL,
	PRIMARY KEY(MSGV, MSDT)
)
ALTER TABLE GV_HDDT ADD
CONSTRAINT FK_HDDT_GV FOREIGN KEY(MSGV) REFERENCES GIAOVIEN(MSGV),
CONSTRAINT FK_HDDT_DT FOREIGN KEY(MSDT) REFERENCES DETAI(MSDT);
select*from GV_HDDT;
--------------------------------------
CREATE TABLE GV_PBDT
(
	MSGV int, 
	MSDT char(6), 
	DIEM float NOT NULL,
	PRIMARY KEY(MSGV, MSDT)
)
ALTER TABLE GV_PBDT ADD
CONSTRAINT FK_PBDT_GV FOREIGN KEY(MSGV) REFERENCES GIAOVIEN(MSGV),
CONSTRAINT FK_PBDT_DT FOREIGN KEY(MSDT) REFERENCES DETAI(MSDT);
select*from GV_PBDT;
-------------------------------------
CREATE TABLE GV_UVDT
(
	MSGV int, 
	MSDT char(6), 
	DIEM float NOT NULL,
	PRIMARY KEY(MSGV, MSDT)
)
ALTER TABLE GV_UVDT ADD
CONSTRAINT FK_UVDT_GV FOREIGN KEY(MSGV) REFERENCES GIAOVIEN(MSGV),
CONSTRAINT FK_UVDT_DT FOREIGN KEY(MSDT) REFERENCES DETAI(MSDT);
select*from GV_UVDT;

-------------------------------------	

CREATE TABLE HOIDONG
(
	MSHD		int, 
	PHONG		int, 
	TGBD		smalldatetime,
	NGAYHD		smalldatetime NOT NULL, 
	TINHTRANG	nvarchar(30) NOT NULL,
	MSGV		int,
	PRIMARY KEY(MSHD)
)
ALTER TABLE HOIDONG ADD CONSTRAINT FK_HD_GV FOREIGN KEY(MSGV) REFERENCES GIAOVIEN(MSGV);
--DROP TABLE HOIDONG
	
-------------------------------------
CREATE TABLE HOIDONG_GV
(
	MSHD	int, 
	MSGV	int,
	PRIMARY KEY(MSHD, MSGV)
)
--DROP TABLE HOIDONG_GV
ALTER TABLE HOIDONG_GV ADD
CONSTRAINT FK_HDGV_HD FOREIGN KEY(MSHD) REFERENCES HOIDONG(MSHD),
CONSTRAINT FK_GDGV_GV FOREIGN KEY(MSGV) REFERENCES GIAOVIEN(MSGV);
select*from HOIDONG_GV;
--------------------------------------
CREATE TABLE HOIDONG_DT
(
	MSHD		int , 
	MSDT		char(6) , 
	QUYETDINH	nchar(10),
	PRIMARY KEY(MSHD, MSDT)
)
--DROP TABLE HOIDONG_DT
alter table HOIDONG_DT add
constraint FK_HDDT_HDong foreign key(MSHD) references HOIDONG(MSHD),
constraint FK_HDDT_DTai foreign key(MSDT) references DETAI(MSDT);
select*from HOIDONG_DT;

SET DATEFORMAT DMY

--A. Insert table SINHVIEN
INSERT INTO SINHVIEN VALUES
('13520001',N'Nguyễn Văn An','0906762255','SE103.U32',N'THỦ ĐỨC'),
('13520002',N'Phan Tấn Đạt','0975672350','IE204.T21',N'QUẬN 1'),
('13520003',N'Nguyễn Anh Hải','0947578688','IE205.R12',N'QUẬN 9'),
('13520004',N'Phạm Tài','0956757869','IE202.A22',N'QUẬN 1'),
('13520005',N'Lê Thúy Hằng','0976668688','SE304.E22',N'THỦ ĐỨC'),
('13520006',N'Ưng Hồng Ân','0957475898','IE208.F33',N'QUẬN 2');

---B. Insert table DETAI
INSERT INTO DETAI VALUES
('97001',N'Quản lý thư viện'),
('97002',N'Nhận dạng vân tay'),
('97003',N'Bán đấu giá trên mạng'),
('97004',N'Quản lý siêu thị'),
('97005',N'Xử lý ảnh'),
('97006',N'Hệ giải toán thông minh');

---C.Insert table SV_DETAI
INSERT INTO SV_DETAI VALUES
('13520001','97004'),
('13520002','97005'),
('13520003','97001'),
('13520004','97002'),
('13520005','97003'),
('13520006','97005');
--D. Insert table HOCHAM
INSERT INTO HOCHAM VALUES
(1,N'PHÓ GIÁO SƯ'),
(2,N'GIÁO SƯ');
---E. Insert table GIAOVIEN
INSERT INTO GIAOVIEN VALUES(00201,N'Trần Trung',N'Bến Tre','35353535',1,'1996'),
(00202,N'Nguyễn Văn An',N'Tiền Giang','67868688',1,'1996'),
(00203,N'Trần Thu Trang',N'Cần Thơ','74758687',1,'1996'),
(00204,N'Nguyễn Thị Loan',N'TP. HCM','56575868',2,'2005'),
(00205,N'Chu Tiến',N'Hà Nội','46466646',2,'2005');
---F.Insert table HOCVI
INSERT INTO HOCVI VALUES
(1,N'Kỹ sư'),
(2,N'Cử Nhân'),
(3,N'Thạc sĩ'),
(4,N'Tiến sĩ'),
(5,N'Tiến sĩ Khoa học');
---G. Insert table CHUYENNGANH
INSERT INTO CHUYENNGANH VALUES
(1,N'Công nghệ Web'),
(2,N'Mạng xã hội'),
(3,N'Quản lý CNTT'),
(4,N'GIS');
---H. Insert table GV_HV_CN
INSERT INTO GV_HV_CN VALUES
(00201,1,1,'2013'),
(00201,1,2,'2013'),
(00201,2,1,'2014'),
(00202,3,2,'2013'),
(00203,2,4,'2014'),
(00204,3,2,'2014');
---I. Insert table GV_HDDT
INSERT INTO GV_HDDT VALUES
(00201,'97001',8),
(00202,'97002',7),
(00205,'97001',9),
(00204,'97004',7),
(00203,'97005',9);
---J. Insert table GV_PBDT
INSERT INTO GV_PBDT VALUES
(00201,'97005',8),
(00202,'97001',7),
(00205,'97004',9),
(00204,'97003',7),
(00203,'97002',9);
---K. Insert table GV_UVDT
INSERT INTO GV_UVDT VALUES
(00205,'97005',8),
(00202,'97005',7),
(00204,'97005',9),
(00203,'97001',7),
(00204,'97001',9),
(00205,'97001',8),
(00203,'97003',7),
(00201,'97003',9),
(00202,'97003',7),
(00201,'97004',9),
(00202,'97004',8),
(00203,'97004',7),
(00201,'97002',9),
(00204,'97002',7),
(00205,'97002',9),
(00201, '97006', 9),
(00202, '97006', 7),
(00204, '97006', 9);
---L. Insert table HOIDONG
INSERT INTO HOIDONG VALUES
(1,002,'7:00','29/11/2014',N'Thật',00201),
(2,102,'7:00','5/12/2014',N'Thật',00202),
(3,003,'8:00','6/12/2014',N'Thật',00203);
---M. Insert table HOIDONG_GV
INSERT INTO HOIDONG_GV VALUES
(1,00201),
(1,00202),
(1,00203),
(1,00204),
(2,00203),
(2,00202),
(2,00205),
(2,00204),
(3,00201),
(3,00202),
(3,00203),
(3,00204);
---N. Insert table HOIDONG_DT
INSERT INTO HOIDONG_DT VALUES
(1,'97001',N'Được'),
(1,'97002',N'Được'),
(2,'97001',N'Không'),
(2,'97004',N'Không'),
(1,'97005',N'Được'),
(3,'97001',N'Không'),
(3,'97002',N'Được');






----------------------------------------PHẦN 2--------------------------------------
-------------------------------------------------------------------------------------

--------------------------------------A. STORED PROCEDURES VỚI THAM SỐ VÀO------------------------------------

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


--------------------------------------B. STORED PROCEDURES VỚI THAM SỐ VÀO VÀ RA------------------------------------

--------------------------------------------------------------------------------
--CAU 1
--1. Đưa vào TENHV trả ra: Số GV thỏa học vị, nếu không tìm thấy trả về 0.

CREATE PROC PROC_COUNT_SOGV 
	@TENHV NVARCHAR(20), @SOGV INT OUTPUT
AS
BEGIN
	IF NOT EXISTS (SELECT * FROM HOCVI WHERE TENHV = @TENHV)
	BEGIN
		PRINT N'TENHV CHUA TON TAI'
		RETURN 0
	END

	SELECT @SOGV = COUNT(DISTINCT MSGV)
	FROM GV_HV_CN, HOCVI
	WHERE HOCVI.MSHV = GV_HV_CN.MSHV AND TENHV = @TENHV
	PRINT N'THANH CONG'
END
GO

--1.1 THỰC THI VÀ KIỂM TRA
DECLARE @SOGV INT, @TENHV NVARCHAR(20)
SET @TENHV = N'Kỹ sư'

EXEC PROC_COUNT_SOGV @TENHV , @SOGV OUTPUT
PRINT N'SỐ GV CÓ HỌC VỊ ' + @TENHV + N' LÀ ' + CAST(@SOGV AS VARCHAR) --không thực hiện nếu @SOGV = NULL, vì những cái đi cùng NULL => fail
GO

--1.2 XÓA
DROP PROC PROC_COUNT_SOGV 
GO



----------------------------------------------------------------------------------------------------------------
--CAU 2
--2. Đưa vào MSDT cho biết: Điểm trung bình của đề tài, nếu không tìm thấy trả về 0.

CREATE PROCEDURE PROC_DETAI_AGV
	@MSDT CHAR(6), @AGV FLOAT OUTPUT
AS
BEGIN
	IF NOT EXISTS (SELECT * FROM DETAI WHERE MSDT = @MSDT)
	BEGIN
		PRINT 'DE TAI KHONG TON TAI'
		RETURN 0
	END
	
	--SOGV_CHAMDIEM: số lượng giáo viên đã chấm điểm
	--TONGDIEM: tổng điểm của đề tài
	DECLARE @SOGV_CHAMDIEM INT = 0, @TONGDIEM FLOAT = 0

	--BANG GV_HDDT
	IF EXISTS (SELECT * FROM GV_HDDT WHERE MSDT = @MSDT)
	BEGIN
		SELECT @SOGV_CHAMDIEM = COUNT(*), @TONGDIEM = SUM(DIEM)
		FROM GV_HDDT
		WHERE MSDT = @MSDT
	END
	
	--BANG GV_PBDT
	IF EXISTS (SELECT * FROM GV_PBDT WHERE MSDT = @MSDT)
	BEGIN
		SELECT @SOGV_CHAMDIEM += COUNT(*), @TONGDIEM += SUM(DIEM)
		FROM GV_PBDT
		WHERE MSDT = @MSDT
	END
	
	--BANG GV_UVDT
	IF EXISTS (SELECT * FROM GV_UVDT WHERE MSDT = @MSDT)
	BEGIN
		SELECT @SOGV_CHAMDIEM += COUNT(*), @TONGDIEM += SUM(DIEM)
		FROM GV_UVDT
		WHERE MSDT = @MSDT
	END

	--TINH DIEM TRUNG BINH
	SELECT @AGV = @TONGDIEM / @SOGV_CHAMDIEM
END
GO

--2.1. THỰC THI
DECLARE @MSDT CHAR(6), @AGV FLOAT
SET @MSDT = '97005'

EXEC PROC_DETAI_AGV @MSDT, @AGV OUTPUT
PRINT N'DIEM TRUNG BINH CUA DE TAI ' + @MSDT + ': ' + CAST(@AGV AS VARCHAR)
GO

--2.2. KIỂM TRA
DECLARE @MSDT CHAR(6)
SET @MSDT = '97005'

SELECT * FROM GV_HDDT WHERE MSDT = @MSDT
SELECT * FROM GV_PBDT WHERE MSDT = @MSDT
SELECT * FROM GV_UVDT WHERE MSDT = @MSDT
GO

--2.3. KHÔI PHỤC DỮ LIỆU (NẾU CÓ)


--2.4. XÓA
DROP PROC PROC_DETAI_AGV
GO



------------------------------------------------------------------------------------------------------------------------------------
--CAU 3
--3. Đưa vào TENGV trả ra: SDT của giáo viên đó, nếu không tìm thấy trả về 0.
--Nếu trùng tên thì có báo lỗi không? Tại sao? Làm sao để hiện thông báo có bao 
--nhiêu giáo viên trùng tên và trả về các SDT.

--Nếu trùng tên giáo viên thì không báo lỗi, vì tên giáo viên không phải là khóa chính nên có thể trùng nhau.

CREATE PROC PROC_TENGV_SDT
	@TENGV NVARCHAR(30), @SODT VARCHAR(10) OUTPUT
AS
BEGIN
	IF NOT EXISTS (SELECT * FROM GIAOVIEN WHERE TENGV = @TENGV)
	BEGIN
		PRINT 'TEN GIAO VIEN KHONG TON TAI'
		RETURN 0
	END

	ELSE
	BEGIN
		DECLARE @SOGV_TRUNG_SDT INT
		SELECT @SOGV_TRUNG_SDT = COUNT(SODT) 
		FROM GIAOVIEN WHERE TENGV = @TENGV

		IF @SOGV_TRUNG_SDT > 1
		BEGIN
			PRINT N'CÓ ' + CAST(@SOGV_TRUNG_SDT AS VARCHAR) + ' GIÁO VIÊN TRÙNG TÊN!'
			SELECT SODT, MSGV FROM GIAOVIEN WHERE TENGV = @TENGV --in ra bảng các SDT của tên giáo viên đó
		END
		ELSE
			SELECT @SODT = SODT FROM GIAOVIEN WHERE TENGV = @TENGV
	END
END
GO

--3.1. THỰC THI
/*  
INSERT INTO GIAOVIEN VALUES ('123', N'Trần Trung', 'THUDUC', '0123456789', 2, 1999)
SELECT * FROM GIAOVIEN
DELETE FROM GIAOVIEN WHERE MSGV = '123'		
*/
--Thành công
--Trường hợp 1: không bị trùng tên giáo viên
DECLARE @TENGV NVARCHAR(30) = N'Trần Trung',
	@SODT VARCHAR(10)
EXEC PROC_TENGV_SDT @TENGV, @SODT OUTPUT
PRINT 'SDT CUA GIAO VIEN ' + @TENGV + ' LA ' + @SODT
GO
--Trường hợp 2: bị trùng tên giáo viên
INSERT INTO GIAOVIEN VALUES ('123', N'Trần Trung', 'THUDUC', '0123456789', 2, 1999)

DECLARE @TENGV NVARCHAR(30) = N'Trần Trung',
	@SODT VARCHAR(10)
EXEC PROC_TENGV_SDT @TENGV, @SODT OUTPUT
PRINT 'SDT CUA GIAO VIEN ' + @TENGV + ' LA ' + @SODT
GO

--Thất bại
DECLARE @TENGV NVARCHAR(30) = N'NGUYEN VAN A',
	@SODT VARCHAR(10)
EXEC PROC_TENGV_SDT @TENGV, @SODT OUTPUT
PRINT 'SDT CUA GIAO VIEN ' + @TENGV + ' LA ' + @SODT
GO

--3.2. KIỂM TRA
SELECT * FROM GIAOVIEN

--3.3. KHÔI PHỤC DỮ LIỆU (NẾU CÓ)
DELETE FROM GIAOVIEN WHERE MSGV = '123'	

--3.4. XÓA
DROP PROC PROC_TENGV_SDT
GO



---------------------------------------------------------------------------------------------------------
--CAU 4
--4. Đưa vào MSHD cho biết: Điểm trung bình các đề tài của hội đồng đó.

CREATE PROC PROC_HOIDONG_AGV
	@MSHD INT, @AGV FLOAT OUTPUT
AS
BEGIN
	IF NOT EXISTS (SELECT * FROM HOIDONG WHERE MSHD = @MSHD)
	BEGIN
		PRINT 'MSHD KHONG TON TAI'
		RETURN 0
	END

	DECLARE @TONGDIEM FLOAT = 0, @COUNT INT = 0

	--BANG GV_HDDT
	IF EXISTS (SELECT * FROM HOIDONG_GV, GV_HDDT 
					WHERE HOIDONG_GV.MSGV = GV_HDDT.MSGV AND MSHD = @MSHD)
	BEGIN
		SELECT @TONGDIEM = SUM(DIEM), @COUNT = COUNT(*)
		FROM HOIDONG_GV JOIN GV_HDDT ON HOIDONG_GV.MSGV = GV_HDDT.MSGV
		WHERE MSHD = @MSHD
	END

	--BANG GV_PBDT
	IF EXISTS (SELECT * FROM HOIDONG_GV, GV_PBDT 
					WHERE HOIDONG_GV.MSGV = GV_PBDT.MSGV AND MSHD = @MSHD)
	BEGIN
		SELECT @TONGDIEM += SUM(DIEM), @COUNT += COUNT(*)
		FROM HOIDONG_GV JOIN GV_PBDT ON HOIDONG_GV.MSGV = GV_PBDT.MSGV
		WHERE MSHD = @MSHD
	END

	--BANG GV_UVDT
	IF EXISTS (SELECT * FROM HOIDONG_GV, GV_UVDT
					WHERE HOIDONG_GV.MSGV = GV_UVDT.MSGV AND MSHD = @MSHD)
	BEGIN
		SELECT @TONGDIEM += SUM(DIEM), @COUNT += COUNT(*)
		FROM HOIDONG_GV JOIN GV_UVDT ON HOIDONG_GV.MSGV = GV_UVDT.MSGV
		WHERE MSHD = @MSHD
	END

	SELECT @AGV = @TONGDIEM / @COUNT
END
GO

--4.1. THỰC THI
--Thành công
DECLARE @MSHD INT = 2, @AGV FLOAT
EXEC PROC_HOIDONG_AGV @MSHD, @AGV OUTPUT
PRINT 'DIEM TRUNG BINH CAC DE TAI CUA HOI DONG (MSHD: ' 
		+ CAST(@MSHD AS VARCHAR) + ') LA ' + CAST(@AGV AS VARCHAR)
GO

--Thất bại
DECLARE @MSHD INT = 10, @AGV FLOAT
EXEC PROC_HOIDONG_AGV @MSHD, @AGV OUTPUT
PRINT 'DIEM TRUNG BINH CAC DE TAI CUA HOI DONG (MSHD: ' 
		+ CAST(@MSHD AS VARCHAR) + ') LA ' + CAST(@AGV AS VARCHAR)
GO

--4.2. KIỂM TRA
DECLARE @MSHD INT = 2
SELECT * FROM HOIDONG_GV JOIN GV_HDDT ON HOIDONG_GV.MSGV = GV_HDDT.MSGV WHERE MSHD = @MSHD
SELECT * FROM HOIDONG_GV JOIN GV_PBDT ON HOIDONG_GV.MSGV = GV_PBDT.MSGV WHERE MSHD = @MSHD
SELECT * FROM HOIDONG_GV JOIN GV_UVDT ON HOIDONG_GV.MSGV = GV_UVDT.MSGV WHERE MSHD = @MSHD
GO

--4.3. KHÔI PHỤC DỮ LIỆU (NẾU CÓ)


--4.4. XÓA
DROP PROC PROC_HOIDONG_AGV
GO



-----------------------------------------------------------------------------------------------------------------------------
--CAU 5
--5. Đưa vào TENGV cho biết: Số đề tài hướng dẫn, số đề tài phản biện do giáo 
--viên đó phụ trách. Nếu trùng tên thì có báo lỗi không hay hệ thống sẽ đếm tất 
--cả các đề tài của những giáo viên trùng tên đó?

--Nêu trùng tên, hệ thống không báo lỗi, vì tên giáo viên không phải khóa chính. 
--Hệ thống sẽ đếm tất cả các đề tài của từng giáo viên đó (dùng MSGV để phân biệt cho từng GV).

CREATE PROC PROC_TENGV_DT
	@TENGV NVARCHAR(30),
	@DTHD INT OUTPUT, @DTPB INT OUTPUT
AS
BEGIN
	IF NOT EXISTS (SELECT * FROM GIAOVIEN WHERE TENGV = @TENGV)
	BEGIN
		PRINT N'TEN GIAO VIEN KHONG TON TAI'
		RETURN 0
	END

	DECLARE @GV_TRUNG INT
	SELECT @GV_TRUNG = COUNT(MSGV) FROM GIAOVIEN WHERE TENGV = @TENGV

	IF @GV_TRUNG > 1
	BEGIN
		PRINT N'CÓ ' + CAST(@GV_TRUNG AS VARCHAR) + ' GIÁO VIÊN TRÙNG TÊN!'

		SELECT T1.MSGV, SO_DTDH, SO_DTPB
		FROM
				--BANG GV_HDDT
				(SELECT GV.MSGV, COUNT(MSDT) AS SO_DTDH
				FROM GIAOVIEN GV LEFT JOIN GV_HDDT HD ON GV.MSGV = HD.MSGV
				GROUP BY GV.MSGV) T1
			JOIN
				--BANG GV_PBDT
				(SELECT GV.MSGV, COUNT(MSDT) AS SO_DTPB
				FROM GIAOVIEN GV LEFT JOIN GV_PBDT PB ON GV.MSGV = PB.MSGV
				GROUP BY GV.MSGV) T2
			ON T1.MSGV = T2.MSGV
		WHERE T1.MSGV IN (SELECT MSGV FROM GIAOVIEN WHERE TENGV = @TENGV)
	END

	ELSE
	BEGIN
		SELECT @DTHD = COUNT(HD.MSDT), @DTPB = COUNT(PB.MSDT)
		FROM (GIAOVIEN GV LEFT JOIN GV_HDDT HD ON GV.MSGV = HD.MSGV)
				LEFT JOIN GV_PBDT PB ON GV.MSGV = PB.MSGV
		WHERE TENGV = @TENGV
	END
END
GO

--5.1. THỰC THI
/*  
INSERT INTO GIAOVIEN VALUES ('123', N'Trần Trung', 'THUDUC', '0123456789', 2, 1999)
SELECT * FROM GIAOVIEN
DELETE FROM GIAOVIEN WHERE MSGV = '123'		
*/
--Thành công
--Trường hợp 1: không bị trùng tên giáo viên
DECLARE @TENGV NVARCHAR(30) = N'Trần Trung', 
		@SO_DTHD INT, @SO_DTPB INT
EXEC PROC_TENGV_DT @TENGV, @SO_DTHD OUTPUT, @SO_DTPB OUTPUT
PRINT 'SO LUONG DTHD CUA GIAO VIEN ' + @TENGV + ' LA ' + CAST(@SO_DTHD AS VARCHAR)
PRINT 'SO LUONG DTPB CUA GIAO VIEN ' + @TENGV + ' LA ' + CAST(@SO_DTPB AS VARCHAR)
GO

--Trường hợp 2: bị trùng tên giáo viên
INSERT INTO GIAOVIEN VALUES ('123', N'Trần Trung', 'THUDUC', '0123456789', 2, 1999)

DECLARE @TENGV NVARCHAR(30) = N'Trần Trung', 
		@SO_DTHD INT, @SO_DTPB INT
EXEC PROC_TENGV_DT @TENGV, @SO_DTHD OUTPUT, @SO_DTPB OUTPUT
PRINT 'SO LUONG DTHD CUA GIAO VIEN ' + @TENGV + ' LA ' + CAST(@SO_DTHD AS VARCHAR)
PRINT 'SO LUONG DTPB CUA GIAO VIEN ' + @TENGV + ' LA ' + CAST(@SO_DTPB AS VARCHAR)
GO

--Thất bại
DECLARE @TENGV NVARCHAR(30) = N'NGUYEN VAN A',
		@SO_DTHD INT, @SO_DTPB INT
EXEC PROC_TENGV_DT @TENGV, @SO_DTHD OUTPUT, @SO_DTPB OUTPUT
PRINT 'SO LUONG DTHD CUA GIAO VIEN ' + @TENGV + ' LA ' + CAST(@SO_DTHD AS VARCHAR)
PRINT 'SO LUONG DTPB CUA GIAO VIEN ' + @TENGV + ' LA ' + CAST(@SO_DTPB AS VARCHAR)
GO

--5.2. KIỂM TRA
DECLARE @TENGV NVARCHAR(30) = N'Trần Trung'
SELECT B.MSGV, TENGV, MSDT AS MS_DTHD 
	FROM GV_HDDT A RIGHT JOIN GIAOVIEN B ON A.MSGV = B.MSGV  WHERE TENGV = @TENGV

SELECT B.MSGV, TENGV, MSDT AS MS_DTPB
	FROM GV_PBDT A RIGHT JOIN GIAOVIEN B ON A.MSGV = B.MSGV WHERE TENGV = @TENGV
GO

--5.3. KHÔI PHỤC DỮ LIỆU (NẾU CÓ)
DELETE FROM GIAOVIEN WHERE MSGV = '123'	
GO

--5.4. XÓA
DROP PROC PROC_TENGV_DT
GO


-----------------------------------C. TRIGGER------------------------------------------

---------------------------------------------------------------------------------------------------
--CAU 1
--1. Tạo Trigger thỏa mãn điều kiện khi xóa một đề tài sẽ xóa các thông tin liên quan.

CREATE TRIGGER TRG_DELETE_DETAI
ON DETAI
INSTEAD OF DELETE --BEFORE TRIGGER
AS
BEGIN
	DECLARE @MSDT CHAR(6)
	SELECT @MSDT = MSDT FROM DELETED

	--Kiểm tra DETAI có dữ liệu hay không
	IF @@ROWCOUNT = 0
	BEGIN
		PRINT 'BANG DETAI KHONG CO DU LIEU'
		RETURN
	END

	--XOA CAC BANG LIEN QUAN
	DELETE FROM SV_DETAI WHERE MSDT = @MSDT
	DELETE FROM GV_HDDT WHERE MSDT = @MSDT
	DELETE FROM GV_PBDT WHERE MSDT = @MSDT
	DELETE FROM GV_UVDT WHERE MSDT = @MSDT
	DELETE FROM HOIDONG_DT WHERE MSDT = @MSDT

	DELETE FROM DETAI WHERE MSDT = @MSDT

	PRINT N'XOA THANH CONG'
END
GO

--1.1. THỰC THI
--Vô hiệu hóa các ràng buộc liên quan bảng DETAI
ALTER TABLE SV_DETAI NOCHECK CONSTRAINT ALL
ALTER TABLE GV_HDDT NOCHECK CONSTRAINT ALL
ALTER TABLE GV_PBDT NOCHECK CONSTRAINT ALL
ALTER TABLE GV_UVDT NOCHECK CONSTRAINT ALL
ALTER TABLE HOIDONG_DT NOCHECK CONSTRAINT ALL

DELETE FROM DETAI WHERE MSDT = '97001'

--Kích hoạt lại các ràng buộc liên quan bảng DETAI
ALTER TABLE SV_DETAI CHECK CONSTRAINT ALL
ALTER TABLE GV_HDDT CHECK CONSTRAINT ALL
ALTER TABLE GV_PBDT CHECK CONSTRAINT ALL
ALTER TABLE GV_UVDT CHECK CONSTRAINT ALL
ALTER TABLE HOIDONG_DT CHECK CONSTRAINT ALL
GO

--1.2. KIỂM TRA
SELECT * FROM DETAI
SELECT * FROM SV_DETAI
SELECT * FROM GV_HDDT 
SELECT * FROM GV_PBDT
SELECT * FROM GV_UVDT
SELECT * FROM HOIDONG_DT
GO

--1.3. KHÔI PHỤC DỮ LIỆU (NẾU CÓ)
INSERT INTO DETAI VALUES ('97001', N'Quản lý thư viện')
INSERT INTO SV_DETAI VALUES ('13520003', '97001')
INSERT INTO GV_HDDT VALUES ('201', '97001', 8), ('205', '97001', 9)
INSERT INTO GV_PBDT VALUES ('202', '97001', 7)
INSERT INTO GV_UVDT VALUES ('203', '97001', 7), ('204', '97001', 9), ('205', '97001', 8)
INSERT INTO HOIDONG_DT VALUES ('1', '97001', N'Được'), ('2', '97001', N'Không'), ('3', '97001', N'Không')
GO

--1.4. XÓA
DROP TRIGGER TRG_DELETE_DETAI
GO



------------------------------------------------------------------------------------------
--CAU 2
--2. Tạo Trigger thỏa mãn ràng buộc là khi đổi 1 mã số giáo viên (MSGV) thì sẽ 
--thay đổi các thông tin liên quan.

CREATE TRIGGER TRG_UPDATE_GIAOVIEN
ON GIAOVIEN
FOR UPDATE
AS
BEGIN
	DECLARE @MSGV_I INT, @MSGV_D INT
	SELECT @MSGV_I = MSGV FROM INSERTED
	SELECT @MSGV_D = MSGV FROM DELETED

	--Kiểm tra bảng GIAOVIEN có dữ liệu hay không
	IF @@ROWCOUNT = 0
	BEGIN
		PRINT 'BANG GIAOVIEN KHONG CHUA DU LIEU'
		RETURN
	END

	--UPDATE CAC BANG LIEN QUAN
	UPDATE GV_HV_CN SET MSGV = @MSGV_I WHERE MSGV = @MSGV_D
	UPDATE GV_HDDT SET MSGV = @MSGV_I WHERE MSGV = @MSGV_D
	UPDATE GV_PBDT SET MSGV = @MSGV_I WHERE MSGV = @MSGV_D
	UPDATE GV_UVDT SET MSGV = @MSGV_I WHERE MSGV = @MSGV_D
	UPDATE HOIDONG SET MSGV = @MSGV_I WHERE MSGV = @MSGV_D
	UPDATE HOIDONG_GV SET MSGV = @MSGV_I WHERE MSGV = @MSGV_D

	PRINT 'UPDATE MSGV THANH CONG'
END
GO

--2.1. THỰC THI
--Vô hiệu hóa các ràng buộc liên quan bảng GIAOVIEN
ALTER TABLE GV_HV_CN NOCHECK CONSTRAINT ALL
ALTER TABLE GV_HDDT NOCHECK CONSTRAINT ALL
ALTER TABLE GV_PBDT NOCHECK CONSTRAINT ALL
ALTER TABLE GV_UVDT NOCHECK CONSTRAINT ALL
ALTER TABLE HOIDONG NOCHECK CONSTRAINT ALL
ALTER TABLE HOIDONG_GV NOCHECK CONSTRAINT ALL

UPDATE GIAOVIEN SET MSGV = '123' WHERE MSGV = '201'

--Kích hoạt lại các ràng buộc liên quan bảng GIAOVIEN
ALTER TABLE GV_HV_CN CHECK CONSTRAINT ALL
ALTER TABLE GV_HDDT CHECK CONSTRAINT ALL
ALTER TABLE GV_PBDT CHECK CONSTRAINT ALL
ALTER TABLE GV_UVDT CHECK CONSTRAINT ALL
ALTER TABLE HOIDONG CHECK CONSTRAINT ALL
ALTER TABLE HOIDONG_GV CHECK CONSTRAINT ALL
GO

--2.2. KIỂM TRA
SELECT * FROM GIAOVIEN
SELECT * FROM GV_HV_CN
SELECT * FROM GV_HDDT 
SELECT * FROM GV_PBDT
SELECT * FROM GV_UVDT
SELECT * FROM HOIDONG
SELECT * FROM HOIDONG_GV
GO

--2.3. KHÔI PHỤC DỮ LIỆU (NẾU CÓ)
--Vô hiệu hóa các ràng buộc liên quan bảng GIAOVIEN
ALTER TABLE GV_HV_CN NOCHECK CONSTRAINT ALL
ALTER TABLE GV_HDDT NOCHECK CONSTRAINT ALL
ALTER TABLE GV_PBDT NOCHECK CONSTRAINT ALL
ALTER TABLE GV_UVDT NOCHECK CONSTRAINT ALL
ALTER TABLE HOIDONG NOCHECK CONSTRAINT ALL
ALTER TABLE HOIDONG_GV NOCHECK CONSTRAINT ALL

UPDATE GIAOVIEN SET MSGV = '201' WHERE MSGV = '123'

--Kích hoạt lại các ràng buộc liên quan bảng GIAOVIEN
ALTER TABLE GV_HV_CN CHECK CONSTRAINT ALL
ALTER TABLE GV_HDDT CHECK CONSTRAINT ALL
ALTER TABLE GV_PBDT CHECK CONSTRAINT ALL
ALTER TABLE GV_UVDT CHECK CONSTRAINT ALL
ALTER TABLE HOIDONG CHECK CONSTRAINT ALL
ALTER TABLE HOIDONG_GV CHECK CONSTRAINT ALL
GO

--2.4. XÓA
DROP TRIGGER TRG_UPDATE_GIAOVIEN
GO



---------------------------------------------------------------------------------------------------------
--CAU 3
--3. Tạo Trigger thỏa mãn ràng buộc là một hội đồng không quá 10 đề tài. Dùng 
--“Group by” có được không? Giải thích.

--Có thể sử dụng "Group by"
--Giải thích:
/*
CREATE TRIGGER TRG_HOIDONG_DT_Max10
ON HOIDONG_DT
FOR INSERT, UPDATE
AS
BEGIN
	DECLARE @COUNT INT
	SELECT @COUNT = CNT
	FROM
		(SELECT MSHD, COUNT(*) AS CNT
		FROM HOIDONG_DT
		GROUP BY MSHD) T1, INSERTED T2
	WHERE T1.MSHD = T2.MSHD

	IF @COUNT > 10
	BEGIN
		PRINT N'Lỗi!!! 1 hội đồng tối đa 10 đề tài'
		ROLLBACK TRANSACTION
	END
	ELSE
		PRINT N'THÀNH CÔNG'
END
GO
*/

CREATE TRIGGER TRG_HOIDONG_DT_Max10
ON HOIDONG_DT
FOR INSERT, UPDATE
AS
BEGIN
	IF (SELECT COUNT(*)
		FROM HOIDONG_DT T1, INSERTED T2
		WHERE T1.MSHD = T2.MSHD) > 10
	BEGIN
		PRINT N'Lỗi!!! 1 hội đồng tối đa 10 đề tài'
		ROLLBACK TRANSACTION
	END
	ELSE
		PRINT N'THÀNH CÔNG'
END
GO

--3.1. THỰC THI
--Thành công
UPDATE HOIDONG_DT SET MSDT = '97006' WHERE MSHD = 3 AND MSDT = '97001'

INSERT INTO HOIDONG_DT VALUES(3, '97006', 'SDFD')

--3.2. KIỂM TRA
SELECT * FROM HOIDONG_DT
GO

--3.3. KHÔI PHỤC DỮ LIỆU (NẾU CÓ)
--UPDATE
UPDATE HOIDONG_DT SET MSDT = '97001' WHERE MSHD = 3 AND MSDT = '97006'

--INSERT
DELETE FROM HOIDONG_DT WHERE MSDT = '97006'

--3.4. XÓA
DROP TRIGGER TRG_HOIDONG_DT_Max10
GO



---------------------------------------------------------------------------------
--CAU 4
--4. Tạo Trigger thỏa mãn ràng buộc là một đề tài không quá 2 sinh viên. Dùng 
--“Group by” có được không? Giải thích.

--Có thể dùng "Group by"
--Giải thích:
/*
CREATE TRIGGER TRG_SV_DETAI_Max2
ON SV_DETAI
FOR INSERT, UPDATE
AS
BEGIN
	DECLARE @COUNT INT
	SELECT @COUNT = CNT
	FROM
		(SELECT COUNT(*) AS CNT, MSDT
		FROM SV_DETAI
		GROUP BY MSDT) T1, INSERTED T2
	WHERE T1.MSDT = T2.MSDT

	IF @COUNT > 2
	BEGIN
		PRINT N'Lỗi!!! 1 đề tài chỉ được tối đa 2 sinh viên'
		ROLLBACK TRANSACTION
	END
	ELSE
		PRINT N'THÀNH CÔNG'
END
GO
*/

CREATE TRIGGER TRG_SV_DETAI_Max2
ON SV_DETAI
FOR INSERT, UPDATE
AS
BEGIN
	IF (SELECT COUNT(*)
		FROM SV_DETAI T1, INSERTED T2
		WHERE T1.MSDT = T2.MSDT) > 2
	BEGIN
		PRINT N'Lỗi!!! 1 đề tài chỉ được tối đa 2 sinh viên'
		ROLLBACK TRANSACTION
	END
	ELSE
		PRINT N'THÀNH CÔNG'
END
GO

--4.1. THỰC THI
--Thành công
UPDATE SV_DETAI SET MSDT = '97001' WHERE MSSV = '13520001'

INSERT INTO SV_DETAI VALUES('13520001', '97001')

--Thất bại
UPDATE SV_DETAI SET MSDT = '97005' WHERE MSSV = '13520001'

INSERT INTO SV_DETAI VALUES ('13520001', '97005')

--4.2. KIỂM TRA
SELECT * FROM SV_DETAI 
GO

--4.3. KHÔI PHỤC DỮ LIỆU (NẾU CÓ)
--UPDATE
UPDATE SV_DETAI SET MSDT = '97004' WHERE MSSV = '13520001'

--INSERT
DELETE FROM SV_DETAI WHERE MSDT = '97001' AND MSSV = '13520001'

--4.4. XÓA
DROP TRIGGER TRG_SV_DETAI_Max2
GO



-----------------------------------------------------------------------------------
--CAU 5
--5. Tạo Trigger thỏa mãn ràng buộc là một giáo viên muốn có học hàm PGS 
--phải là tiến sĩ.

CREATE TRIGGER TRG_GIAOVIEN_PGS
ON GIAOVIEN
FOR UPDATE
AS
BEGIN
	IF (SELECT MSHH FROM INSERTED) = 1 
		AND
		(SELECT MSHV
		FROM GV_HV_CN T1, INSERTED T2
		WHERE T1.MSGV = T2.MSGV) != 4
	BEGIN
		PRINT N'Lỗi! Học hàm PGS (MSHH 1) thì phải là Tiến sĩ (MSHV 4)'
		ROLLBACK TRANSACTION
	END
	ELSE
		PRINT N'THÀNH CÔNG'
END
GO

--5.1. THỰC THI
--Thành công
UPDATE GV_HV_CN SET MSHV = 4 WHERE MSGV = '204'

UPDATE GIAOVIEN SET MSHH = 1 WHERE MSGV = '204'

--Thất bại
UPDATE GIAOVIEN SET MSHH = 1 WHERE MSGV = '204'


--5.2. KIỂM TRA
SELECT * FROM GIAOVIEN
SELECT * FROM GV_HV_CN
GO

--5.3. KHÔI PHỤC DỮ LIỆU (NẾU CÓ)
UPDATE GV_HV_CN SET MSHV = 3 WHERE MSGV = '204'
UPDATE GIAOVIEN SET MSHH = 2 WHERE MSGV = '204'

--5.4. XÓA
DROP TRIGGER TRG_GIAOVIEN_PGS
GO


--------------------------------D. FUNCTION----------------------------------------

--------------------------------------------------------
--CAU 1
--1. Viết hàm tính điểm trung bình của một đề tài. Giá trị trả về là điểm trung
--bình ứng với mã số đề tài nhập vào

CREATE FUNCTION CALC_AVGSCORE (@MSDT CHAR(6)) RETURNS FLOAT
AS
BEGIN
	DECLARE @DTB FLOAT
	IF NOT EXISTS (SELECT * FROM DETAI WHERE MSDT = @MSDT)
		SET @DTB = 0
	ELSE
	BEGIN
		SELECT @DTB = AVG(DIEMTONGHOP.DIEM)
		FROM (SELECT * FROM GV_HDDT UNION
			 SELECT * FROM GV_PBDT UNION
			 SELECT * FROM GV_UVDT) AS DIEMTONGHOP
		WHERE MSDT = @MSDT
	END

	RETURN @DTB
END
GO

--1.1 THỰC THI
SELECT DBO.CALC_AVGSCORE('97001') AS DTB
GO

--1.2 KIỂM TRA
SELECT *
FROM (SELECT * FROM GV_HDDT UNION 
	 SELECT * FROM GV_PBDT UNION
	 SELECT * FROM GV_UVDT) AS T
WHERE MSDT = '97001'

--1.3 KHÔI PHỤC DỮ LIỆU (NẾU CÓ)

--1.4 XÓA
DROP FUNCTION DBO.CALC_AVGSCORE
GO



---------------------------------------------------------------------------------
--CAU 2
--2. Trả về kết quả của đề tài theo MSDT nhập vào. Kết quả là DAT nếu như 
--điểm trung bình từ 5 trở lên, và KHONGDAT nếu như điểm trung bình dưới 5.

CREATE FUNCTION KQ_DETAI (@MSDT CHAR(6)) RETURNS VARCHAR(10)
AS
BEGIN
	DECLARE @KQ VARCHAR(10), @DTB FLOAT = 0

	SELECT @DTB = AVG(DIEMTONGHOP.DIEM)
	FROM (SELECT * FROM GV_HDDT UNION
		 SELECT * FROM GV_PBDT UNION
		 SELECT * FROM GV_UVDT) AS DIEMTONGHOP
	WHERE MSDT = @MSDT

	IF @DTB < 5
		SET @KQ = 'KHONGDAT'
	ELSE
		SET @KQ = 'DAT'
	
	RETURN @KQ
END
GO

--2.1 THỰC THI
SELECT DBO.KQ_DETAI('97001') AS KETQUA
GO

--2.2 KIỂM TRA
SELECT AVG(DIEMTONGHOP.DIEM) AS DTB
FROM (SELECT * FROM GV_HDDT UNION
	  SELECT * FROM GV_PBDT UNION
	  SELECT * FROM GV_UVDT) AS DIEMTONGHOP
	WHERE MSDT = '97001'
GO

--2.3 KHÔI PHỤC DỮ LIỆU (NẾU CÓ)

--2.4 XÓA
DROP FUNCTION DBO.KQ_DETAI
GO



------------------------------------------------------------------------
--CAU 3
--3. Đưa vào MSDT, trả về mã số và họ tên của các sinh viên thực hiện đề tài.

CREATE FUNCTION SV_THUCHIEN_DT (@MSDT CHAR(6)) 
					RETURNS @SV TABLE (MSSV CHAR(8),
									   TENSV NVARCHAR(30))
AS
BEGIN
	INSERT @SV
	SELECT T1.MSSV, TENSV
	FROM SV_DETAI T1, SINHVIEN T2
	WHERE T1.MSDT = @MSDT AND T1.MSSV = T2.MSSV
	
	RETURN
END
GO

--3.1 THỰC THI
SELECT * FROM DBO.SV_THUCHIEN_DT('97001')
GO

--3.2 KIỂM TRA
SELECT T1.MSSV, TENSV
FROM SV_DETAI T1, SINHVIEN T2
WHERE T1.MSDT = '97001' AND T1.MSSV = T2.MSSV
GO

--3.3 KHÔI PHỤC DỮ LIỆU (NẾU CÓ)

--3.4 XÓA
DROP FUNCTION DBO.SV_THUCHIEN_DT
GO


---------------------------------E. CURSOR---------------------------

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
