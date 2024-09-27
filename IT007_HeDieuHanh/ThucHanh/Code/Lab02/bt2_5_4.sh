#!/bin/sh

#Nhập chuỗi
echo -n "Nhập chuỗi: "
read string

#Kiểm tra chuỗi nhập vào có tồn tại trong một [fileName].txt 
#trong thư mục hiện hành hay không.
for file in *.txt; do
    if grep -l "$string" $file; then
        echo "Chuỗi \"$string\" có tồn tại trong \"$file\""
    else
        echo "Chuỗi \"$string\" không tồn tại trong \"$file\""
    fi
done
exit 0