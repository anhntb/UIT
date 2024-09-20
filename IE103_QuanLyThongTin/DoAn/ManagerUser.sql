use QLHangTonKho
go

-- Xem
select * from PHIEUNHAPKHO

-- Thêm
INSERT INTO PHIEUNHAPKHO VALUES ('PNK099', '2024-01-01', 'KHO002', 'NV001');

-- Sửa
update PHIEUNHAPKHO
set MAKHO = 'KHO001'
where MAPNK = 'PNK099'

-- Xóa
delete from PHIEUNHAPKHO where MAPNK = 'PNK099'


-- select * from KHO
