### Dùng lệnh "cd" để chuyển tới thư mục chứa file này

# 1. Viết chương trình nhập vào một tên tập tin,
# kiểm tra xem tập tin này có tồn tại không,
# nếu có thì đọc và xuất ra toàn bộ nội dung của tập tin này.

import os
from docx import Document

filename = input("Nhập tên tập tin: ")
if os.path.exists(filename):
    if filename.lower().endswith('.txt'):
        with open(filename, 'r', encoding='utf-8') as f:
            content = f.read()
            print("Nội dung tập tin:")
            print(content)
    elif filename.lower().endswith('.docx'):
        doc = Document(filename)
        print("Nội dung tập tin:")
        for para in doc.paragraphs:
            print(para.text)
    else:
        print("Định dạng tập tin không hỗ trợ.")
else:
    print("Tập tin không tồn tại.")