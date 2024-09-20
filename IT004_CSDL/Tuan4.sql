--dense_rank()
--rank()
select count(MAKH) as count from HOADON where MAKH is NULL

drop table HOADON

select * from HOADON



21
select count(MAGV)
from GIAOVIEN
where HOCVI in ("CN","KS","Ths","TS","PTS")
group by MAKHOA


32

select MAHV, TENHV
from HOCVIEN
where MAHV not in(

select MAHV
from KETQUATHI
where LANTHI >= ALL(
	select LANTHI
	from KETQUATHI KQ2
	where KQ2.MAMH = KQ1.MAMH and KQ2.MAHV = KQ1.MAHV
	)
and KETQUA = 'Khong Dat'
)

select MAHV, MAMH, KQUA
from KETQUATHI
where LANTHI >= ALL(
	select LANTHI
	from KETQUATHI KQ2
	where KQ2.MAMH = KQ1.MAMH and KQ2.MAHV = KQ1.MAHV
	)
and KETQUA = 'Khong Dat'


35
select MAHV
from KETQUATHI
join
(
select KQSC. MAMH, MAX(DIEM) as DCN
from
select MAHV, MAMH, DIEM
from KETQUATHI KQ1
where LANTHI >= all(
	select LANTHI
	from KETQUATHI KQ2
	where KQ2.MAMH = KQ1.MAMH and KQ2.MAHV = KQ1.MAHV
	)) KQSC
group by KQSC.MAMH
)
on MAMH = MAMH and DIEM = DCN
