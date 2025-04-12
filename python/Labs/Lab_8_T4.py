import pandas as pd
import matplotlib.pyplot as plt
data=pd.read_csv("C:/Users/hamzz/OneDrive/Documents/GitHub/Practice-Codes/python/Labs/train.csv")

male_survived = data[data['Sex'] == 'male']['Survived'].value_counts()
female_survived = data[data['Sex'] == 'female']['Survived'].value_counts()

labels = ['Not Survived', 'Survived']
x = [0, 1]
width = 0.35

plt.bar([i - width/2 for i in x], male_survived.sort_index(), width=width, label='Male', color='blue')
plt.bar([i + width/2 for i in x], female_survived.sort_index(), width=width, label='Female', color='pink')

plt.xticks(x, labels)
plt.ylabel('Count')
plt.title('Survival by Gender')
plt.legend()
plt.show()

print("Count:\n", data.groupby('Sex')['Survived'].count())
print("Min:\n", data.groupby('Sex')['Survived'].min())
print("Max:\n", data.groupby('Sex')['Survived'].max())
print("Mean (Survival Rate):\n", data.groupby('Sex')['Survived'].mean())