# Bài 1 (Cơ bản): Lớp Hình chữ nhật
# Yêu cầu:
# - Tạo lớp Rectangle có hai thuộc tính: width (chiều rộng) và height (chiều cao).
# - Có hai phương thức:
#   + area() → trả về diện tích.
#   + perimeter() → trả về chu vi

class Rectangle:
    def __init__(self, width = 0, height = 0):
        self.width = width
        self.height = height

    def area(self):
        return self.width * self.height
    
    def perimeter(self):
        return 2 * (self.width + self.height)
    
