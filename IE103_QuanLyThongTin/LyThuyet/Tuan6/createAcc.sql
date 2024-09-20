--Tài khoản SQL auth
create login quantrimang with password = 'mk123'
go

--Tài khoản user cho database 'master'
--use master
CREATE USER DB_qtm FOR LOGIN quantrimang
go

--Tài khoản user cho database 'test'
--use test
CREATE USER DB_qtm1 FOR LOGIN quantrimang
go

--Xóa tài khoản user cho database 'master'
--use master
drop user DB_qtm

--Khi thêm, xóa user thì sẽ thêm, xóa cho database hiện hành.
--1 login thì có nhiều database, 1 database chỉ có thể do 1 hoặc 0 user.

use QLDT

create table test
(
	xinchao nvarchar(10)
)

drop table test

drop login quantrimang

use test

insert GIAOVIEN VALUES(1234,567)

select * from GIAOVIEN