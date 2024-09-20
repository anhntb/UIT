Use TEST_XML
Go

select * from QuanLySV
for xml raw

select * from QuanLySV
for xml raw, elements

-- Cau 1
-- Sinh viên có ID = 1
select ChiTietSV.query('/THONGTINSV/sinhvien[@ID=10]') as SinhVien
from QuanLySV

--SV ở vị trí cuối cùng trong DH CNTT
select ChiTietSV.query('/THONGTINSV/sinhvien[last()]')
from QuanLySV where MSDH = 1

-- Cau 2
-- Trả về tất cả các nút từ nút gốc là THONGTINSV
select ChiTietSV.query('/THONGTINSV/*')
from QuanLySV

-- Cau 3
-- DSSV có ID < 12 và MSDH = 1
select ChiTietSV.query('
for $i in /THONGTINSV/sinhvien
where $i/@ID<12
return $i
')
from QuanLySV where MSDH = 1

-- Cau 4
-- DSSV sắp xếp theo tên với MSDH = 2
select ChiTietSV.query('
for $i in /THONGTINSV/sinhvien
order by $i/@Ten ascending
return $i
')
from QuanLySV where MSDH = 2

-- Cau 5
-- Trả về MSDH và TENDH theo định dạng sau
--<QuanLySV>
--	<ChiTietSV>1 DH CNTT</ChiTietSV>
--</QuanLySV>
select ChiTietSV.query('
<QuanLySV>
	<ChiTietSV>
	{sql:column("MSDH"), sql:column("TenDH")}
	</ChiTietSV>
</QuanLySV>
')
from QuanLySV where MSDH = 1

-- Cau 6
-- Xóa tên các sinh viên trường DH KHTN
update QuanLySV
set ChiTietSV.modify('
delete /THONGTINSV/sinhvien/@Ten
')
where MSDH = 2

-- kiểm tra
select ChiTietSV from QuanLySV where MSDH = 2

-- khôi phục dữ liệu
delete from QuanLySV

insert into QuanLySV values (1,'DH CNTT',
'<THONGTINSV> 
	<sinhvien ID="10" Ten="Nam">
		<monhoc ID="1" Ten="Co So Du Lieu" />
		<monhoc ID="2" Ten="Cau Truc Du Lieu" />
		<monhoc ID="3" Ten="Lap Trinh Mobile" />
	</sinhvien> 
	<sinhvien ID="11" Ten="An"> 
		<monhoc ID="4" Ten="Toan Giai Tich" />
		<monhoc ID="5" Ten="Lap Trinh Java" /> 
		<monhoc ID="6" Ten="He Quan Tri CSDL" />
	</sinhvien> 
	<sinhvien ID="12" Ten="Thanh"> 
		<monhoc ID="7" Ten="Anh Van" /> 
		<monhoc ID="8" Ten="Thiet Ke Web" /> 
		<monhoc ID="9" Ten="An Toan Thong Tin" /> 
	</sinhvien> 
</THONGTINSV>'),
(2,'DH KHTN',
'<THONGTINSV> 
	<sinhvien ID="10" Ten="Khang"> 
		<monhoc ID="1" Ten="Co So Du Lieu" /> 
		<monhoc ID="2" Ten="Cau Truc Du Lieu" /> 
		<monhoc ID="3" Ten="Lap Trinh Mobile" />
	</sinhvien> 
	<sinhvien ID="11" Ten="Vinh"> 
		<monhoc ID="4" Ten="Toan Giai Tich" />
		<monhoc ID="5" Ten="Lap Trinh Java" /> 
		<monhoc ID="6" Ten="He Quan Tri CSDL" />
	</sinhvien> 
	<sinhvien ID="12" Ten="Hoa"> 
		<monhoc ID="7" Ten="Anh Van" /> 
		<monhoc ID="8" Ten="Thiet Ke Web" /> 
		<monhoc ID="9" Ten="An Toan Thong Tin" /> 
	</sinhvien> 
</THONGTINSV>')

--update QuanLySV
--set ChiTietSV.modify('
--insert attribute Ten {"Khang"}
--into (/THONGTINSV/sinhvien)[1]
--')
--where MSDH = 2

--insert attribute Ten {"Vinh"}
--into (/THONGTINSV/sinhvien)[2]

--insert attribute Ten {"Hoa"}
--into (/THONGTINSV/sinhvien)[3]

-- Cau 7
-- Trả về các SV có tên là "Nam" hoặc "Thanh"
select ChiTietSV.query('
for $i in /THONGTINSV/sinhvien
where $i[@Ten="Nam" or @Ten="Thanh"]
return $i
')
from QuanLySV

-- Cau 8 
-- Thay đổi tên SV thứ 2 thành tên "Binh" trong DH CNTT
update QuanLySV
set ChiTietSV.modify('
replace value of (/THONGTINSV/sinhvien/@Ten)[2]
with "Binh"
')
where MSDH = 1

-- kiểm tra
select ChiTietSV from QuanLySV where MSDH = 1

-- khôi phục dữ liệu
update QuanLySV
set ChiTietSV.modify('
replace value of (/THONGTINSV/sinhvien/@Ten)[2]
with "An"
')
where MSDH = 1

-- Cau 9
-- Tồn tại SV có ID = 12 trong DH KHTN (Yes: 1, No: 0)
select ChiTietSV.exist('
/THONGTINSV/sinhvien[@ID=12]
')
from QuanLySV where MSDH = 2

-- Cau 10
-- Tồn tại SV tên "Lan" trong DH CNTT (Yes: 1, No: 0)
-- Và INSERT thêm vào THONGTINSV:
--<sinhvien ID="15" Ten="Lan"> 
--	<monhoc ID="10" Ten="Toan Roi Rac" />
--	<monhoc ID="11" Ten="Lap Trinh C#" /> 
--	<monhoc ID="12" Ten="CSDL Nang Cao" />
--</sinhvien>
select ChiTietSV.exist('
/THONGTINSV/sinhvien[@Ten="Lan"]
')
from QuanLySV where MSDH = 1

update QuanLySV
set ChiTietSV.modify('
insert 
<sinhvien ID="15" Ten="Lan"> 
	<monhoc ID="10" Ten="Toan Roi Rac" />
	<monhoc ID="11" Ten="Lap Trinh C#" /> 
	<monhoc ID="12" Ten="CSDL Nang Cao" />
</sinhvien>
as last (: thêm vào cuối node :)
into (/THONGTINSV)[1]
')
where MSDH = 1

-- kiểm tra
select ChiTietSV from QuanLySV where MSDH = 1

-- khôi phục dữ liệu
update QuanLySV
set ChiTietSV.modify('
delete /THONGTINSV/sinhvien[last()]
')
where MSDH = 1

-- Cau 11*
-- Thực hiện phép nối bằng các lệnh Xquery như một câu truy vấn trong SQL để
-- trả về thông tin là sinh viên nào học khóa học tên là gì, sinh viên nào học môn học gì?
select * from KhoaHoc
select * from KhoaHocMonHoc
select * from MonHoc
select * from SinhVien

declare @SV XML
set @SV = (
	select distinct MSSV, TenSV, TenKhoaHoc, kh.MaKhoaHoc 
	from SinhVien sv join KhoaHoc kh on sv.MaKhoaHoc = kh.MaKhoaHoc,
			KhoaHocMonHoc t1 join MonHoc t2 on t1.MaMonHoc = t2.MaMonHoc
	where kh.MaKhoaHoc = t1.MaKhoaHoc
	for xml path, root('SV_KH_MH')
);
select @SV

select @SV.query('
	let $SinhVien := /SV_KH_MH/row
	return $SinhVien
')



