# Bài tập 3: Gộp nội dung từ nhiều file và ghi vào file mới
# Viết chương trình đọc nội dung từ 3 file văn bản: file1.txt, file2.txt, file3.txt
# Sau đó gộp nội dung của cả 3 file lại thành một file mới merged.txt.
# Nếu bất kỳ file nào không tồn tại, hãy bỏ qua file đó và thông báo cho người dùng.

def merge_files(file_list, merged_file):
    with open(merged_file, 'w', encoding='utf-8') as outfile:
        for filename in file_list:
            try:
                with open(filename, 'r', encoding='utf-8') as infile:
                    content = infile.read()
                    outfile.write(content + '\n')  # Ghi nội dung và xuống dòng sau mỗi file
            except FileNotFoundError:
                print(f"File {filename} không tồn tại, bỏ qua.")
    print(f"Nội dung đã được gộp vào {merged_file}")

# Di chuyển đến folder "Buoi6" trước khi chạy đoạn mã này
file_list = ['file1.txt', 'file2.txt', 'file3.txt']
merged_file = 'merged.txt'
merge_files(file_list, merged_file)