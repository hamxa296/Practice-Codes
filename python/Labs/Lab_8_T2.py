import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv( "C:/Users/hamzz/OneDrive/Documents/GitHub/Practice-Codes/python/Labs/train.csv")

plt.scatter(data['Age'], data['Fare'], alpha=0.99)
plt.xlabel('Age')
plt.ylabel('Fare')
plt.title('Age vs Fare')
plt.grid(True)
plt.show()
