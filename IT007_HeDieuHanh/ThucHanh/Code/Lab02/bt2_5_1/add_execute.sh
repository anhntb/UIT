#!/bin/sh

#Cấp quyền thực thi cho tất cả file trong thư mục hiện hành, cho tất cả người dùng
for file in *; do
    chmod +x $file
done
exit 0