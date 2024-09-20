--CREATE DATABASE
--Drop Database QLHangTonKho
Create Database QLHangTonKho
Go

Use QLHangTonKho


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
--Dùng stored procedure để insert kiểm tra MASP thuộc NCC ở PNK
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
--Dùng stored procedure để insert kiểm tra MASP thuộc NCC ở PXK, và kiểm tra SL đủ đáp ứng
Create Table CT_PXK
(
	MAPXK char(6) Foreign key References PHIEUXUATKHO,
	MASP char(5) Foreign key References SANPHAM,
	SL int default 0,
	Primary key (MAPXK, MASP)
)
Go

--11.LUUTRU
--Bảng được tạo tự động, chỉ có thể xem
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
