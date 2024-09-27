#!/bin/sh

# Nhập tên
echo -n "Nhập tên: "
read ten

# Vòng lặp để nhập MSSV hợp lệ
while true; do
  # Nhập MSSV
  echo -n "\nNhập MSSV: "
  read mssv

  # Kiểm tra MSSV
  if [ $mssv = 22520066 ]; then
    break
  else
    echo "Sai MSSV! Nhập lại!"
    echo "--------------------------------------------"
  fi
done

# In kết quả
echo "\n\nTên: $ten"
echo "MSSV: $mssv"

exit 0