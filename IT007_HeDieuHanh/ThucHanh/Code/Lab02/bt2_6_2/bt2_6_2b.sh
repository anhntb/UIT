#!/bin/sh

# Đọc file text monhoc.txt ở trên, ở trong thư mục vừa tạo ở câu a, 
# với mỗi môn học, tạo ra một thư mục có tên tương ứng với mã môn đó.
for maMH in `cat ~/Lab02/monhoc.txt`; do
    mkdir ~/Lab02/$maMH
    echo "Đã tạo thư mục $maMH"
done

exit 0