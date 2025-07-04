create database fitness;
use fitness;

-- Bảng HOIVIEN
CREATE TABLE HOIVIEN (
    MaHV VARCHAR(10) PRIMARY KEY,
    TenHV VARCHAR(50),
    GioiTinh VARCHAR(10),
    CCCD VARCHAR(20),
    NgaySinh DATE,
    SoDT VARCHAR(15)
);

-- Bảng HLV
CREATE TABLE HLV (
    MaHLV VARCHAR(10) PRIMARY KEY,
    TenHLV VARCHAR(50),
    GioiTinh VARCHAR(10),
    CCCD VARCHAR(20),
    SoDT VARCHAR(15),
    BietDanh VARCHAR(30)
);

-- Bảng GOITAP
CREATE TABLE GOITAP (
    MaGoi VARCHAR(10) PRIMARY KEY,
    TenGoi VARCHAR(50)
);

-- Bảng DANGKY
CREATE TABLE DANGKY (
    MaDK VARCHAR(10) PRIMARY KEY,
    MaHV VARCHAR(10),
    MaGoi VARCHAR(10),
    SoBuoiDK INT,
    SoBuoiConLai INT,
    FOREIGN KEY (MaHV) REFERENCES HOIVIEN(MaHV),
    FOREIGN KEY (MaGoi) REFERENCES GOITAP(MaGoi)
);

-- Bảng TAP
CREATE TABLE TAP (
    MaDK VARCHAR(10),
    MaHLV VARCHAR(10),
    NgayTap DATE,
    GioTap TIME,
    PRIMARY KEY (MaDK, MaHLV, NgayTap, GioTap),
    FOREIGN KEY (MaDK) REFERENCES DANGKY(MaDK),
    FOREIGN KEY (MaHLV) REFERENCES HLV(MaHLV)
);