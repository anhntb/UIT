use QLDT
go

create view ThongKeDiem_GVUV as
select gvuv.MSDT, TENDT, gvuv.MSGV, TENGV, DIEM
from GV_UVDT gvuv, GIAOVIEN gv, DETAI dt
where gvuv.MSDT = dt.MSDT and gvuv.MSGV = gv.MSGV
order by gvuv.MSDT asc
OFFSET 0 ROWS

select * from ThongKeDiem_GVUV
