import Rectangle as rc
import Student as st
import BankAccount as ba

hcn = rc.Rectangle(5,10)
print("Diện tích hình chữ nhật:", hcn.area())
print("Chu vi hình chữ nhật:", hcn.perimeter())
print()

sv = st.Student("Nguyễn Văn A", 7)
sv.display()
print("Result:", sv.is_pass())
print()

tk = ba.BankAccount("Trần Thị B", 1000)
tk.display()
tk.deposit(500)
tk.withdraw(200)