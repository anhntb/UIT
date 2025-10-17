# Bài tập 2: Ghi danh sách số vào file và đọc lại tổng
# Viết chương trình:
#   Nhập vào danh sách các số nguyên từ người dùng.
#   Ghi các số đó vào file numbers.txt, mỗi số trên một dòng.
#   Đọc lại file, tính tổng các số và in ra kết quả.
#   Xử lý ngoại lệ nếu có lỗi khi đọc hoặc ghi file.

def write_numbers_to_file(file_path, numbers):
    try:
        with open(file_path, mode='w', encoding='utf-8') as file:
            for number in numbers:
                file.write(f"{number}\n")
    except Exception as e:
        print(f"Lỗi khi ghi file: {e}")

def read_numbers_and_sum(file_path):
    try:
        with open(file_path, mode='r', encoding='utf-8') as file:
            sum = 0
            for num in file:
                sum += int(num.strip())
            print(f"Tổng các số trong file: {sum}")
    except FileNotFoundError:
        print(f"Lỗi: Không tìm thấy tệp '{file_path}'")

# Di chuyển đến thư mục "Buoi6" để chạy chương trình
file_path = 'numbers.txt'
# Kiểm tra chuỗi nhập hợp lệ
numbers_input = input("Nhập danh sách số nguyên, cách nhau bởi dấu cách: ")
try:
    numbers = list(map(int, numbers_input.split()))
    write_numbers_to_file(file_path, numbers)
    read_numbers_and_sum(file_path) 
except ValueError:
    print("Lỗi: Vui lòng nhập đúng định dạng số nguyên.")