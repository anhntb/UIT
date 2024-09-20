use QLDT
go


-- 2.1. Một sinh viên chỉ được tham gia một đề tài.
create trigger trg_SV_joinOnly1DT
on SV_DETAI
for insert, update
as
begin
	declare @mssv char(8), @cnt int
	select @mssv = MSSV from inserted
	select @cnt = count(*) from SV_DETAI where @mssv = MSSV

	if (@cnt >= 2)
	begin
		print (N'Một sinh viên chỉ tham gia 1 đề tài!')
		rollback transaction
	end
	else
		print (N'Thành công')
end
go

-- 1. Thực thi
-- Thêm sinh viên vào bảng SINHVIEN
insert into SINHVIEN values ('123', N'Nguyễn Văn A', '0906762255',	'SE103.U32' , N'THỦ ĐỨC')  
insert into SINHVIEN values ('abc', N'Nguyễn Văn B', '0906762255',	'SE103.U32' , N'THỦ ĐỨC')   
select * from SINHVIEN

-- Thành công
insert into SV_DETAI values ('123', '97001')

update SV_DETAI
set MSSV = 'abc',
	MSDT = '97005'
where MSSV = '123'

-- Thất bại
insert into SV_DETAI values ('13520001', '97001')

update SV_DETAI
set MSSV = '13520001'
where MSSV = '13520002'

-- 2. Kiểm tra
select * from SV_DETAI

-- 3. Khôi phục dữ liệu
delete from SV_DETAI where MSSV = 'abc' or MSSV = '123'
delete from SINHVIEN where MSSV = 'abc' or MSSV = '123'

-- 4. Xóa
drop trigger trg_SV_joinOnly1DT
go


-- 2.2. Điểm của đề tài trong thang điểm từ 0 đến 10.
alter table GV_HDDT
add constraint chk_point_hd check(DIEM >= 0 and DIEM <= 10)

alter table GV_PBDT
add constraint chk_point_pb check(DIEM >= 0 and DIEM <= 10)

alter table GV_UVDT
add constraint chk_point_uv check(DIEM >= 0 and DIEM <= 10)
go

-- 1. Thực thi
-- Thành công
update GV_HDDT
set DIEM = 10
where MSGV = '201' and MSDT = '97001'

-- Thất bại
update GV_HDDT
set DIEM = 10.1
where MSGV = '201' and MSDT = '97001'

-- 2. Kiểm tra
select * from GV_HDDT
select * from GV_PBDT
select * from GV_UVDT

-- 3. Khôi phục dữ liệu
update GV_HDDT
set DIEM = 8
where MSGV = '201' and MSDT = '97001'

-- 4. Xóa
alter table GV_HDDT
drop constraint chk_point_hd

alter table GV_PBDT
drop constraint chk_point_pb

alter table GV_UVDT
drop constraint chk_point_uv
go


-- 2.3. GV là chủ tịch hội đồng phải có học vị tiến sĩ.
create trigger trg_chk_TienSi
on HOIDONG
for insert, update
as
begin
	declare @msgv int, @mshv int
	select @msgv = MSGV from inserted
	
	if (exists (select * from GV_HV_CN
				where @msgv = MSGV and (MSHV = 4 or MSHV = 5)))
		print (N'Thành công')
	else
	begin
		print (N'GV là chủ tịch hội đồng phải có học vị tiến sĩ!')
		rollback transaction
	end
end
go

-- 1. Thực thi
-- Thêm học vị Tiến sĩ cho GV có msgv = 204
insert into GV_HV_CN values (204, 4, 2, 2014)
-- Thành công
insert into HOIDONG values (4, 4, '1900-01-01',	'2014-12-06', N'Thật', 204)

-- Thất bại
insert into HOIDONG values (5, 5, '1900-01-01',	'2014-12-06', N'Thật', 201)

-- 2. Kiểm tra
select * from HOIDONG
select * from GV_HV_CN

-- 3. Khôi phục dữ liệu
delete from GV_HV_CN where MSGV = 204 and MSHV = 4
delete from HOIDONG where MSHD = 4

-- 4. Xóa
drop trigger trg_chk_TienSi
go


-- 2.4. Tính số lượng đề tài làm phản biện và số lượng đề tài làm ủy viên của từng GV.
create function cnt_dtpb_dtuv (@msgv int)
returns int
as
begin
	declare @cnt int = 0

	select @cnt = count (*) from GV_PBDT where @msgv = MSGV
	select @cnt += count (*) from GV_UVDT where @msgv = MSGV

	return @cnt
end
go

-- 1. Thực thi
select MSGV, dbo.cnt_dtpb_dtuv(MSGV) as SoLuong
from GIAOVIEN

-- 2. Kiểm tra
select * from GV_PBDT
select * from GV_UVDT

-- 3. Xóa 
drop function dbo.cnt_dtpb_dtuv
go


-- 2.5. In ra danh sách tên các sinh viên có điểm trung bình đề tài cao nhất.
create proc topSV_hightestPoint
as
begin
	select MSSV, t1.MSDT, (t2.DIEM + t3.DIEM + t4.DIEM)/3.0 as DTB
	from SV_DETAI t1
	join GV_HDDT t2 on t1.MSDT = t2.MSDT
	join GV_PBDT t3 on t1.MSDT = t3.MSDT
	join GV_UVDT t4 on t1.MSDT = t4.MSDT
	order by DTB desc
end
go

-- 1. Thực thi
exec topSV_hightestPoint

-- 2. Kiểm tra
select * from SV_DETAI

-- 3. Xóa
drop proc topSV_hightestPoint
go


-- 3.1. Tạo ra 3 users: GIANGVIEN, GIAOVU và SINHVIEN, đặt mật khẩu tuỳ ý.
if exists (select * from sys.server_principals where name = 'GIANGVIEN')
begin
    drop login GIANGVIEN
end
create login GIANGVIEN with password = '1'
create user GIANGVIEN for login GIANGVIEN

if exists (select * from sys.server_principals where name = 'GIAOVU')
begin
    drop login GIAOVU
end
create login GIAOVU with password = '1'
create user GIAOVU for login GIAOVU

if exists (select * from sys.server_principals where name = 'SINHVIEN')
begin
    drop login SINHVIEN
end
create login SINHVIEN with password = '1'
create user SINHVIEN for login SINHVIEN
go


-- 3.2. Phân quyền cho các users trên database như sau:
/*
	- GIAOVU có quyền xem và chỉnh sửa (cập nhật) trên tất cả các bảng
	- GIANGVIEN
	+ Có quyền xem trên các bảng có liên quan đến thông tin GV, các đề tài mà GV 
	hướng dẫn, phản biện hay làm uỷ viên, xem thông tin hội đồng và danh sách 
	các đề tài hiện có
	+ Có quyền cập nhật thông tin của mình
	- SINHVIEN có quyền xem thông tin của sinh viên, thông tin của hội đồng và 
	danh sách các đề tài hiện có
	- Tất cả người dùng trên đều không có quyền xoá thông tin
*/

create role GiangVienRole
create role GiaoVuRole
create role SinhVienRole

grant select, update to GiaoVuRole
deny delete to GiaoVuRole

grant select on	DETAI to GiangVienRole
grant select on	GIAOVIEN to GiangVienRole
grant select on	HOCVI to GiangVienRole
grant select on	CHUYENNGANHH to GiangVienRole
grant select on	GV_HV_CN to GiangVienRole
grant select on	HOCHAM to GiangVienRole
grant select on	GV_HDDT to GiangVienRole
grant select on	GV_PBDT to GiangVienRole
grant select on	GV_UVDT to GiangVienRole
grant select on	HOIDONG to GiangVienRole
grant select on	HOIDONG_GV to GiangVienRole
deny delete to GiangVienRole

grant select, update on SINHVIEN to SinhVienRole
deny delete to SinhVienRole

exec sp_addrolemember 'GiaoVuRole', 'GIAOVU'
exec sp_addrolemember 'GiangVienRole', 'GIANGVIEN'
exec sp_addrolemember 'SinhVienRole', 'SINHVIEN'




-- 4.1 Thông tin GV phản biện
create view infoGVPB
as
select distinct t1.MSGV, TENGV, TENHV, TENHH, SODT, DIACHI
from
	(select MSGV, TENGV, TENHH, SODT, DIACHI 
	from GIAOVIEN join HOCHAM on GIAOVIEN.MSHH = HOCHAM.MSHH) as t1
	join
	(select GV_PBDT.MSGV, TENHV
	from GV_PBDT join GV_HV_CN on GV_PBDT.MSGV = GV_HV_CN.MSGV
					join HOCVI on GV_HV_CN.MSHV = HOCVI.MSHV) as t2
	on t1.MSGV = t2.MSGV
go
-- drop view infoGVPB
select * from infoGVPB


-- 4.2 Thông tin hôi đồng đánh giá đề tài
create view infoHOIDONG_DT
as
select HOIDONG.MSHD, TENDT, PHONG, NGAYHD, TENGV as CHUTICH
from HOIDONG join GIAOVIEN on HOIDONG.MSGV = GIAOVIEN.MSGV
				join HOIDONG_DT on HOIDONG.MSHD = HOIDONG_DT.MSHD
				join DETAI on HOIDONG_DT.MSDT = DETAI.MSDT
go

--select HOIDONG_GV.MSHD, t1.MSDT, count(t1.MSGV)
--from HOIDONG_GV join HOIDONG_DT on HOIDONG_GV.MSHD = HOIDONG_DT.MSHD
--				join (select * from
--						GV_HDDT union 
--						select * from
--						GV_PBDT union
--						select * from
--						GV_UVDT) as t1
--				on (t1.MSGV = HOIDONG_GV.MSGV and HOIDONG_DT.MSDT = t1.MSDT)
--group by HOIDONG_GV.MSHD, t1.MSDT
