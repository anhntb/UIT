create database Test
use Test

create table Person
(
	id varchar(10) primary key,
	name varchar(50),
	year int
)

--create table Person
--(
--	id varchar(10) primary key,
--	name varchar(50),
--	year numeric check( year>1975)
--)

drop table Person
alter table Person add constraint ChkYear check (year>1975)

INSERT INTO Person
VALUES ('001', 'Nguyen A', 1999),
('002', 'Nguyen B', 1899),
('003', 'Nguyen C', 1980),
('004', 'Nguyen D', 1997),
('005', 'Nguyen E', 1969)

delete from Person

select * from Person


create trigger R1 on Person for insert, update
as
declare @year numeric
begin
	select @year=year from inserted
	if @year<=1975
	begin
		print 'Nam sinh khong hop le'
		rollback transaction
	end
end
--chỉ có tác dụng khi nhập dữ liệu từng dòng

INSERT INTO Person VALUES ('007', 'Nguyen A', 1890)


