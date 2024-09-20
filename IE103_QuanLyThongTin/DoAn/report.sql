use QLHangTonKho
go

create view GIATRIHANGNHAP2024_view as
select SANPHAM.MASP, TENSP, SUM(case when CT_PNK.SL is null then 0 else CT_PNK.SL*GIAGOC end) as TongGiaTri
from PHIEUNHAPKHO
join CT_PNK on PHIEUNHAPKHO.MAPNK = CT_PNK.MAPNK
right join SANPHAM on CT_PNK.MASP = SANPHAM.MASP
where year(NGAYNHAP) = 2024 or CT_PNK.SL is null
group by SANPHAM.MASP, SANPHAM.TENSP
order by TongGiaTri asc offset 0 rows
go
--drop view GIATRIHANGXUAT2024_view
--drop view GIATRIHANGNHAP2024_view
select * from GIATRIHANGNHAP2024_view

create view GIATRIHANGXUAT2024_view as
select SANPHAM.MASP, TENSP, SUM(case when CT_PXK.SL is null then 0 else CT_PXK.SL*GIABAN end) as TongGiaTri
from PHIEUXUATKHO
join CT_PXK on PHIEUXUATKHO.MAPXK = CT_PXK.MAPXK
right join SANPHAM on CT_PXK.MASP = SANPHAM.MASP
where year(NGAYXUAT) = 2024 or CT_PXK.SL is null
group by SANPHAM.MASP, SANPHAM.TENSP
order by TongGiaTri asc offset 0 rows
go

select * from GIATRIHANGXUAT2024_view