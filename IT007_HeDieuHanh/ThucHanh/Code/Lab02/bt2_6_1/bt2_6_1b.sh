#!/bin/sh

# Di chuyển tất cả file PNG trong thư mục ảnh ở trên vào thư mục PNG.
mv `find ~/Lab02/OS_LAB2_IMG-main/*.png` ~/PNG
echo "Đã di chuyển toàn bộ file PNG!"

# Xuất ra màn hình số lượng ảnh PNG.
echo -n "Số lượng ảnh PNG: "
ls ~/PNG | wc -l 

exit 0