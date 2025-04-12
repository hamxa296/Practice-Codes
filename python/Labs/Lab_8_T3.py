import pandas as pd
import matplotlib.pyplot as plt
data=pd.read_csv("C:/Users/hamzz/OneDrive/Documents/GitHub/Practice-Codes/python/Labs/train.csv")

survived_counts = data['Survived'].value_counts()
plt.bar(survived_counts.index, survived_counts.values, color=['red', 'green'])
plt.xticks([0, 1], ['Not Survived', 'Survived'])
plt.title('Survival Count')
plt.ylabel('Count')
plt.show()