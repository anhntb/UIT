#!/bin/sh

# Yêu cầu người dùng nhập vào họ và tên (không dấu), 
# tạo ra thư mục có tên tương ứng với thông tin người dùng vừa nhập
echo -n "Nhập họ và tên (không dấu): "
read name

mkdir ~/Lab02/"$name"
echo "Đã tạo thư mục thành công!"

exit 0