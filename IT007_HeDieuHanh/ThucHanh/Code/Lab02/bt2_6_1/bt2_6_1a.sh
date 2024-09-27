#!/bin/sh

# Kiểm tra thư mục PNG và JPG đã tồn tại 
# trong thư mục người dùng hay chưa.
# Nếu chưa thì tạo 2 thư mục đó.
if [ -e ~/PNG ]; then
    echo "Thư mục PNG đã tồn tại!"
else
    mkdir ~/PNG
    echo "Tạo thư mục PNG thành công!"
fi

if [ -e ~/JPG ]; then
    echo "Thư mục JPG đã tồn tại!"
else
    mkdir ~/JPG
    echo "Tạo thư mục JPG thành công!"
fi
exit 0