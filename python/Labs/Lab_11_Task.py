import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans

df = pd.read_csv('C:/Users/hamzz/OneDrive/Documents/GitHub/Practice-Codes/python/Labs/Mall_Customers.csv')

print("\nFirst 10 rows of the dataset:")
print(df.head(10))
print("\nShape of the dataset:", df.shape)

print("\nDataset information:")
print(df.info())

print("\nMissing values in each column:")
print(df.isnull().sum())

df['Gender'] = df['Gender'].map({'Male': 0, 'Female': 1})

df = df.drop('CustomerID', axis=1)

relevant_columns = ['Gender', 'Age', 'Annual Income (k$)', 'Spending Score (1-100)']
df_clustering = df[relevant_columns]

plt.figure(figsize=(15, 10))

plt.subplot(2, 3, 1)
gender_counts = df['Gender'].value_counts()
plt.bar(gender_counts.index, gender_counts.values)
plt.title('Gender Distribution')
plt.xlabel('Gender (0=Male, 1=Female)')
plt.ylabel('Count')

plt.subplot(2, 3, 2)
plt.hist(df['Age'], bins=20, edgecolor='black')
plt.title('Age Distribution')
plt.xlabel('Age')
plt.ylabel('Count')

plt.subplot(2, 3, 3)
plt.scatter(df['Age'], df['Spending Score (1-100)'], alpha=0.6)
plt.title('Age vs Spending Score')
plt.xlabel('Age')
plt.ylabel('Spending Score (1-100)')

plt.subplot(2, 3, 4)
plt.scatter(df['Annual Income (k$)'], df['Spending Score (1-100)'], alpha=0.6)
plt.title('Annual Income vs Spending Score')
plt.xlabel('Annual Income (k$)')
plt.ylabel('Spending Score (1-100)')

plt.subplot(2, 3, 5)
male_scores = df[df['Gender'] == 0]['Spending Score (1-100)']
female_scores = df[df['Gender'] == 1]['Spending Score (1-100)']
plt.boxplot([male_scores, female_scores], labels=['Male', 'Female'])
plt.title('Spending Score by Gender')
plt.ylabel('Spending Score (1-100)')

plt.tight_layout()
plt.show()

print("\nPersonal Observation:")
print("From the scatter plots, it appears that younger customers (20-40 years) tend to have higher spending scores,")
print("while middle-aged customers (40-60 years) show more moderate spending patterns.")

X = df[['Annual Income (k$)', 'Spending Score (1-100)']]

kmeans = KMeans(n_clusters=3, random_state=42)
kmeans.fit(X)

df['Cluster'] = kmeans.predict(X)

print("\nNumber of customers in each cluster:")
print(df['Cluster'].value_counts().sort_index())

print("\nCluster centers:")
print(kmeans.cluster_centers_)

plt.figure(figsize=(10, 6))

colors = ['blue', 'green', 'purple']
for i in range(3):
    cluster_data = df[df['Cluster'] == i]
    plt.scatter(cluster_data['Annual Income (k$)'], 
                cluster_data['Spending Score (1-100)'], 
                c=colors[i], 
                label=f'Cluster {i}',
                alpha=0.6)

plt.scatter(kmeans.cluster_centers_[:, 0], 
            kmeans.cluster_centers_[:, 1], 
            s=200, 
            c='red', 
            marker='X', 
            label='Cluster Centers')

plt.title('Customer Segments based on Annual Income and Spending Score')
plt.xlabel('Annual Income (k$)')
plt.ylabel('Spending Score (1-100)')
plt.legend()
plt.show()

print("\nCluster Analysis:")
print("1. High Income & High Spenders: Cluster 1 appears to be the high-income, high-spending group")
print("   with customers having both high annual income and high spending scores.")
print("\n2. Low Income & Low Spenders: Cluster 0 represents the low-income, low-spending group")
print("   with customers having both lower annual income and lower spending scores.")

plt.figure(figsize=(10, 6))
for i in range(3):
    cluster_data = df[df['Cluster'] == i]
    plt.scatter(cluster_data['Age'], 
                cluster_data['Spending Score (1-100)'], 
                c=colors[i], 
                label=f'Cluster {i}',
                alpha=0.6)

plt.title('Customer Segments based on Age and Spending Score')
plt.xlabel('Age')
plt.ylabel('Spending Score (1-100)')
plt.legend()
plt.show()
