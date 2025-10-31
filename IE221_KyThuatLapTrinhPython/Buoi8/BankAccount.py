# Bài 3 : Quản lý tài khoản ngân hàng
# Yêu cầu:
# - Tạo lớp BankAccount có hai thuộc tính: owner (chủ tài khoản), balance (số dư, mặc định 0).
# - Có các phương thức:
#   + deposit(amount) → nạp tiền.
#   + withdraw(amount) → rút tiền (nếu đủ).
#   + display() → hiển thị thông tin tài khoản.

class BankAccount:
    def __init__(self, owner="", balance=0):
        self.owner = owner
        self.balance = balance

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            print(f"Nạp thành công: {amount}. Số dư hiện tại: {self.balance}")
        else:
            print("Số tiền nạp phải lớn hơn 0.")

    def withdraw(self, amount):
        if amount > self.balance:
            print("Rút tiền thất bại: Số dư không đủ.")
        elif amount <= 0:
            print("Số tiền rút phải lớn hơn 0.")
        else:
            self.balance -= amount
            print(f"Rút thành công: {amount}. Số dư hiện tại: {self.balance}")

    def display(self):
        print(f"Chủ tài khoản: {self.owner} - Số dư: {self.balance}")