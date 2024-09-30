import numpy as np
import matplotlib.pyplot as plt
import statistics as st

X = 2 * np.random.rand(100, 1)
y = 4 + 3 * X + np.random.randn(100, 1)



# plt.plot(X,y, '.')
# plt.show()

# plt.scatter(X,y)
# plt.show()

#print(st.correlation(X,y)) #tính hệ số tương quan

X_b = np.c_[np.ones((100, 1)), X] #np.ones: khởi tạo ma trận toàn 1
#print(X_b)
# print(X_b.shape)
# print(y.shape)

#nhân ma trận dùng dấu @, không được dùng *
