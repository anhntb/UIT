use QUANLYBANHANG
go

drop view DoanhThuNV_2006

select * from DoanhThuNV_2006

create view DoanhThuNV_2006 as
select month(NGHD) as Thang, nv.MANV, HOTEN, 
	sum(case when nv.MANV = hd.MANV then TRIGIA else 0 end) as Tong
from NHANVIEN nv, HOADON hd
where year(NGHD) = 2006
group by nv.MANV, HOTEN, month(NGHD)
order by Thang asc offset 0 rows