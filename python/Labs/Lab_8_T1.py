import pandas as pd
import matplotlib.pyplot as plt

data=pd.read_csv("C:/Users/hamzz/OneDrive/Documents/GitHub/Practice-Codes/python/Labs/train.csv")
print(data.head(10))
print(data.tail(10))
print(data.isnull().sum())
print(data.duplicated().sum())
print(data.drop_duplicates(inplace=True))
print(data.dropna(inplace=True))
print(data.dtypes)
print(data.nunique())








