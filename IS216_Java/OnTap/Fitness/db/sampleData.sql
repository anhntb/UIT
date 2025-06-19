use fitness;

-- Dữ liệu mẫu cho HOIVIEN
INSERT INTO HOIVIEN VALUES
('HV01', 'Nguyen Van A', 'Nam', '012345678901', '2000-01-01', '0909123456'),
('HV02', 'Tran Thi B', 'Nữ', '012345678902', '2001-02-02', '0909123457');

-- Dữ liệu mẫu cho HLV
INSERT INTO HLV VALUES
('HLV01', 'Le Van C', 'Nam', '012345678903', '0909123458', 'CoachC'),
('HLV02', 'Pham Thi D', 'Nữ', '012345678904', '0909123459', 'CoachD');

-- Dữ liệu mẫu cho GOITAP
INSERT INTO GOITAP VALUES
('GT01', 'Gói cơ bản'),
('GT02', 'Gói nâng cao');

-- Dữ liệu mẫu cho DANGKY
INSERT INTO DANGKY VALUES
('DK01', 'HV01', 'GT01', 10, 8),
('DK02', 'HV02', 'GT02', 20, 18);

-- Dữ liệu mẫu cho TAP
INSERT INTO TAP VALUES
('DK01', 'HLV01', '2024-06-01', '08:00:00'),
('DK01', 'HLV01', '2024-06-03', '08:00:00'),
('DK02', 'HLV02', '2024-06-02', '09:00:00');