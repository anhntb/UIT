# Bài 2 : Lớp Sinh viên
# Yêu cầu:
# - Tạo lớp Student có hai thuộc tính: name, score.
# - Có hai phương thức:
#   + display() → in tên và điểm.
#   + is_pass() → trả về 'Đậu' nếu điểm ≥ 5, ngược lại 'Rớt'.

class Student:
    def __init__(self, name="", score=0):
        self.name = name
        self.score = score

    def display(self):
        print(f"Full Name: {self.name} - Score: {self.score}")

    def is_pass(self):
        return "Đậu" if self.score >= 5 else "Rớt"