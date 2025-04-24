import pandas as pd
import matplotlib.pyplot as plt
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import classification_report

df = pd.read_csv("C:/Users/hamzz/OneDrive/Documents/GitHub/Practice-Codes/python/Labs/diabetes_dataset.csv")
df.drop("id",axis=1,inplace=True)
df=df.dropna()
df.fillna(0,inplace=True)
df = df.drop(["Sex", "Ethnicity", "Physical_Activity_Level", "Alcohol_Consumption", "Smoking_Status"], axis=1)
X = df.drop("Family_History_of_Diabetes", axis=1)
y = df["Family_History_of_Diabetes"]
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
model = LogisticRegression()
model.fit(X_train,y_train)
y_predicted=model.predict(X_test)
print(classification_report(y_test, y_predicted))