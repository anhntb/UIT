	--DATABASE--
create database QLBH

--drop database QLBH

use QLBH


	--TABLE--


create table KHACHHANG 
(
	MAKH char(4) constraint PK_KH primary key, 
	HOTEN varchar(40),
	DCHI varchar(50),
	SODT varchar(20), 
	NGSINH smalldatetime,
	DOANHSO money, 
	NGDK smalldatetime
)

create table NHANVIEN 
(
	MANV char(4) primary key,
	HOTEN varchar(40),
	SODT varchar(20),
	NGVL smalldatetime
)

create table SANPHAM 
(
	MASP char(4) primary key,
	TENSP varchar(40),
	DVT varchar(20),
	NUOCSX varchar(40),
	GIA money
)

create table HOADON 
(
	SOHD int primary key,
	NGHD smalldatetime,
	MAKH char(4) references KHACHHANG (MAKH), 
	MANV char(4),
	TRIGIA money,
	foreign key (MANV) references NHANVIEN (MANV)
)

create table CTHD 
(
	SOHD int foreign key references HOADON (SOHD),
	MASP char(4) references SANPHAM (MASP),
	SL int
)

