import sys
sys.set_int_max_str_digits(1000000)  # Tăng giới hạn lên 10000 chữ số

import module as md

# # TONG CS CONG
# print("Tong CS cong k = 1")
# print("A0: ", md.csc(0, 1))
# print("A1: ", md.csc(1, 1))
# print("A2: ", md.csc(2, 1))
# print("A3: ", md.csc(3, 1))
# print("A4: ", md.csc(4, 1))

# print("Tong: ", md.tong_csc(4, 1))


# # TONG CS NHAN
# print("\n\nTong CS nhan k = 2")
# print("A0: ", md.csn(0, 2))
# print("A1: ", md.csn(1, 2))
# print("A2: ", md.csn(2, 2))
# print("A3: ", md.csn(3, 2))
# print("A4: ", md.csn(4, 2))

# print("Tong: ", md.tong_csn(4, 2))

# KET QUA B
print("\n\nKet qua B: voi n = 100, k = 5")
# print("Tong CS cong: ", md.tong_csc(100, 5))
print("Tong CS nhan: ", md.tong_csn(30, 5))