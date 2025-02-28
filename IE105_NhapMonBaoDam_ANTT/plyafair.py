def create_playfair_matrix(key):
    # Xóa các ký tự trùng lặp trong key và thay "J" bằng "I"
    key = ''.join(dict.fromkeys(key.upper().replace('J', 'I')))
    alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"
    matrix = [c for c in key if c in alphabet] + [c for c in alphabet if c not in key]
    return [matrix[i:i + 5] for i in range(0, 25, 5)]  # Chia thành ma trận 5x5

def find_position(matrix, char):
    for row in range(5):
        for col in range(5):
            if matrix[row][col] == char:
                return row, col

def process_text(text):
    text = text.upper().replace('J', 'I')  # Thay J bằng I
    text = ''.join([c for c in text if c.isalpha()])  # Chỉ giữ lại chữ cái
    result = ""
    i = 0
    while i < len(text):
        if i + 1 < len(text) and text[i] == text[i + 1]:
            result += text[i] + "X"
            i += 1
        else:
            result += text[i:i + 2]
            i += 2
    if len(result) % 2 != 0:
        result += "X"
    return result

def encrypt_pair(pair, matrix):
    row1, col1 = find_position(matrix, pair[0])
    row2, col2 = find_position(matrix, pair[1])
    if row1 == row2:  # Cùng hàng
        return matrix[row1][(col1 + 1) % 5] + matrix[row2][(col2 + 1) % 5]
    elif col1 == col2:  # Cùng cột
        return matrix[(row1 + 1) % 5][col1] + matrix[(row2 + 1) % 5][col2]
    else:  # Hình chữ nhật
        return matrix[row1][col2] + matrix[row2][col1]

def decrypt_pair(pair, matrix):
    row1, col1 = find_position(matrix, pair[0])
    row2, col2 = find_position(matrix, pair[1])
    if row1 == row2:  # Cùng hàng
        return matrix[row1][(col1 - 1) % 5] + matrix[row2][(col2 - 1) % 5]
    elif col1 == col2:  # Cùng cột
        return matrix[(row1 - 1) % 5][col1] + matrix[(row2 - 1) % 5][col2]
    else:  # Hình chữ nhật
        return matrix[row1][col2] + matrix[row2][col1]

def playfair_cipher(message, key, mode='encrypt'):
    matrix = create_playfair_matrix(key)  # Tạo ma trận Playfair
    processed_message = process_text(message)  # Xử lý văn bản
    pairs = [processed_message[i:i + 2] for i in range(0, len(processed_message), 2)]
    result = ''
    for pair in pairs:
        if mode == 'encrypt':
            result += encrypt_pair(pair, matrix)
        else:
            result += decrypt_pair(pair, matrix)
    return result

# Chương trình chính
if __name__ == "__main__":
    key = input("Nhập key (khóa): ")
    option = input("Nhập chế độ (encrypt/decrypt): ").strip().lower()
    message = input("Nhập thông điệp: ")

    if option == "encrypt":
        result = playfair_cipher(message, key, mode='encrypt')
        print("Kết quả mã hóa:", result)
    elif option == "decrypt":
        result = playfair_cipher(message, key, mode='decrypt')
        print("Kết quả giải mã:", result)
    else:
        print("Chế độ không hợp lệ.")
