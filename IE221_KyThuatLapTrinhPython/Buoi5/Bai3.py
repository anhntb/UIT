# 3. Viết chương trình yêu cầu nhập vào một số nguyên dương từ bàn phím.
# Chương trình kiểm tra xem người dùng có nhập đúng yêu cầu hay không.
# Nếu đúng thì tính căn bậc 2 của số đó, nếu không đúng thì xuất thông báo lỗi.

import math

try:
    n = int(input("Nhập một số nguyên dương: "))
    if n > 0:
        print("Căn bậc 2 của", n, "là:", math.sqrt(n))
    else:
        print("Lỗi: Bạn phải nhập số nguyên dương!")
except ValueError:
    print("Lỗi: Giá trị nhập vào không phải là số nguyên dương!")