# Bài tập 1: Đọc file và đếm số dòng, số từ, số ký tự
# Viết chương trình Python để đọc nội dung từ một tệp văn bản (data.txt) và:
#   Đếm số dòng trong tệp
#   Đếm tổng số từ
#   Đếm tổng số ký tự (bao gồm cả dấu cách)
#   Nếu file không tồn tại, hãy xử lý ngoại lệ và in thông báo lỗi.

def count_file_contents(file_path):
    try:
        with open(file_path, mode = 'r', encoding= 'utf-8') as file:
            content = file.read()
            lines = content.splitlines()
            num_lines = len(lines)
            num_words = len(content.split())
            num_chars = len(content)

            print(f"Số dòng: {num_lines}")
            print(f"Số từ: {num_words}")
            print(f"Số ký tự: {num_chars}")

    except FileNotFoundError:
        print(f"Lỗi: Không tìm thấy tệp '{file_path}'")

file_path = 'data.txt'
count_file_contents(file_path) # Di chuyển đến thư mục chứa file data.txt để chạy chương trình