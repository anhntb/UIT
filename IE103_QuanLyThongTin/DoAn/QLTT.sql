use QLHangTonKho
go

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

-- Xác thực cho khách hàng
IF EXISTS(SELECT * FROM sys.server_principals WHERE name = 'CustomerUser')
BEGIN
    DROP LOGIN CustomerUser
END
CREATE LOGIN CustomerUser WITH PASSWORD = '1'
CREATE USER CustomerUser FOR LOGIN CustomerUser

--PHÂN QUYỀN--
-- Tạo các vai trò
CREATE ROLE ManagerRole
CREATE ROLE EmployeeRole
CREATE ROLE CustomerRole

--Nhân viên quản lý có đủ 3 quyển U,I,D đối với tất cả các bảng.
GRANT DELETE, INSERT, SELECT, UPDATE TO ManagerRole

-- --Nhân viên bình thường có đủ 3 quyền đối với bảng PHIEUNHAPKHO, PHIEUXUATKHO, CT_PNK, CT_PXK
GRANT DELETE, INSERT, SELECT, UPDATE ON PHIEUNHAPKHO TO EmployeeRole
GRANT DELETE, INSERT, SELECT, UPDATE ON PHIEUXUATKHO TO EmployeeRole
GRANT DELETE, INSERT, SELECT, UPDATE ON CT_PNK TO EmployeeRole
GRANT DELETE, INSERT, SELECT, UPDATE ON CT_PXK TO EmployeeRole

--Khách hàng không có quyền gì đối với tất cả các bảng--
GRANT SELECT ON SANPHAM TO CustomerRole

-- Gán vai trò cho các user
EXEC sp_addrolemember 'ManagerRole', 'ManagerUser'
EXEC sp_addrolemember 'EmployeeRole', 'EmployeeUser'
EXEC sp_addrolemember 'CustomerRole', 'CustomerUser'
