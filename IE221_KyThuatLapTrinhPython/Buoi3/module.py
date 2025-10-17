### FINONACCI ###
def fibonacci(n):
    """Tính số Fibonacci thứ n dùng vòng lặp while (n >= 0)"""
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    a, b = 0, 1
    count = 1
    while count < n:
        a, b = b, a + b
        count += 1
    return b

def tong_fibonacci(n):
    """Tính tổng các số Fibonacci từ F(0) đến F(n)"""
    if n < 0:
        return 0
    a, b = 0, 1
    total = a
    for _ in range(n):
        total += b
        a, b = b, a + b
    return total


### TỔNG CẤP SỐ CỘNG ###
def csc(n, k):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    a, b = 0, 1
    count = 1
    while count < n:
        a, b = b, a + b + k
        count += 1
    return b

def tong_csc(n, k):
    if n < 0:
        return 0
    a, b = 0, 1
    total = a
    for _ in range(n):
        total += b
        a, b = b, a + b + k
    return total


### TỔNG CẤP SỐ NHÂN ###
def csn(n, k):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    a, b = 0, 1
    count = 1
    while count < n:
        a, b = b, (a + k) * b
        count += 1
    return b

def tong_csn(n, k):
    if n < 0:
        return 0
    a, b = 0, 1
    total = a
    for _ in range(n):
        total += b
        a, b = b, (a + k) * b
    return total