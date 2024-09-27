#!/bin/sh

# Di chuyển tất cả file JPG trong thư mục ảnh ở trên vào thư mục PNG.
mv `find ~/Lab02/OS_LAB2_IMG-main/*.jpg` ~/JPG
echo "Đã di chuyển toàn bộ file JPG!"

# Xuất ra màn hình số lượng ảnh JPG.
echo -n "Số lượng ảnh JPG: "
ls ~/JPG | wc -l 

exit 0