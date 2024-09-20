use QLHangTonKho
go


create view infoNhapKho_2024
as
select sp.MASP, TENSP, sum(case when year(NGAYNHAP) = 2024 then CT_PNK.SL else 0 end) as TongSL_Nhap	
from PHIEUNHAPKHO pnk
	join CT_PNK on pnk.MAPNK = CT_PNK.MAPNK
	right join SANPHAM sp on sp.MASP = CT_PNK.MASP		
	group by sp.MASP, TENSP 
	order by sp.MASP asc offset 0 rows
go

-- select * from infoNhapKho_2024

create view infoXuatKho_2024
as
select sp.MASP, TENSP, sum(case when year(NGAYXUAT) = 2024 then CT_PXK.SL else 0 end) as TongSL_Xuat
from PHIEUXUATKHO pxk
	join CT_PXK on pxk.MAPXK = CT_PXK.MAPXK
	right join SANPHAM sp on sp.MASP = CT_PXK.MASP		
	group by sp.MASP, TENSP
	order by sp.MASP asc offset 0 rows
go

-- select * from infoXuatKho_2024

create view NhapXuat_2024
as
select t1.MASP, t1.TENSP, TongSL_Nhap, TongSL_Xuat
from infoNhapKho_2024 as t1 
	join infoXuatKho_2024 as t2 
		on t1.MASP = t2.MASP
go

-- select * from NhapXuat_2024
