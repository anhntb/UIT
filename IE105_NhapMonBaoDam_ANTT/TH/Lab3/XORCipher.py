import itertools

# Hàm giải mã XOR
def xor_decrypt(data, key):
    """Giải mã dữ liệu với XOR cipher và khóa được cung cấp."""
    key = key.encode('utf-8')  # Chuyển khóa thành byte
    decrypted = bytearray()
    
    for i in range(len(data)):
        decrypted.append(data[i] ^ key[i % len(key)])  # XOR từng byte
    
    return decrypted

# Hàm tìm cờ bằng cách thử tất cả các khóa có thể
def find_flag(encrypted_file_path, key_length=6):
    """Thử tất cả các khóa có độ dài 6 để tìm cờ."""
    # Mở tệp đã mã hóa
    with open(encrypted_file_path, 'rb') as f:
        encrypted_data = f.read()
    
    # Các ký tự có thể trong khóa
    alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    
    # Tạo tất cả các kết hợp khóa có độ dài 6
    possible_keys = itertools.product(alphabet, repeat=key_length)
    
    # Thử tất cả các khóa có thể
    for key_tuple in possible_keys:
        key = ''.join(key_tuple)
        decrypted_data = xor_decrypt(encrypted_data, key)
        
        # Thử ghi tệp giải mã ra và kiểm tra xem nó có phải là ảnh JPEG hợp lệ không
        try:
            with open(f"decrypted_{key}.jpg", 'wb') as out_file:
                out_file.write(decrypted_data)
            
            # Kiểm tra xem tệp có phải là ảnh JPEG hợp lệ (bắt đầu bằng header JPEG 0xFFD8)
            if decrypted_data[:3] == b'\xff\xd8\xff':  # Chữ ký JPEG
                print(f"Ảnh hợp lệ tìm thấy với khóa: {key}")
                return key, decrypted_data  # Trả về khóa và dữ liệu giải mã
        
        except Exception as e:
            continue  # Nếu có lỗi, bỏ qua khóa này
    
    return None, None  # Nếu không tìm thấy khóa hợp lệ

# Đường dẫn tới tệp ảnh đã mã hóa
encrypted_file_path = 'crypto01.jpg'

# Thử tìm cờ bằng cách giải mã tệp ảnh
key, decrypted_data = find_flag(encrypted_file_path)

if key:
    print(f"Flag đã tìm thấy! Khóa là: {key}")
else:
    print("Không tìm thấy khóa hợp lệ. Thử các tham số khác.")
