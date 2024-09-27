#!/bin/sh

#Nhập n
echo -n "Nhập n: "
read n

#Kiểm tra n >= 10
until [ $n -ge 10 ]; do
    echo " n phải lớn hơn hoặc bằng 10! Nhập lại!"
    echo "------------------------------------------------\n"

    echo -n "Nhập n: "
    read n
done

#Tổng từ 1 -> n
sum=0 i=1
while [ $i -le $n ]; do
    sum=$(($sum+$i))
    i=$(($i+1))
done 

#Xuất kết quả
echo "Tổng từ 1 đến $n: $sum"

exit 0