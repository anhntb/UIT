# 2. Viết chương nhập vào tên tập tin nguồn,
# đọc và sao chép nội dung của tập tin sang một nơi khác
# (nội dung file có đuôi là .txt, .ini, .log).

import os
import shutil

src = input("Nhập tên tập tin nguồn: ")
if os.path.exists(src) and src.lower().endswith(('.txt', '.ini', '.log')):
    copy = "Bai2_copy.txt"
    shutil.copyfile(src, copy) # tự tạo tập tin copy, nếu chưa tồn tại
    print(f"Đã sao chép nội dung từ {src} sang {copy}.")
else:
    print("Tập tin nguồn không tồn tại hoặc không đúng định dạng (.txt, .ini, .log).")