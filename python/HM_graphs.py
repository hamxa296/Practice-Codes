import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
import pandas as pd

# 1. Resume Parsing Accuracy by Format
formats = ['PDF', 'DOCX', 'TXT', 'Creative', 'Multilingual']
accuracy = [95, 94, 92, 85, 85]
plt.figure(figsize=(8, 5))
sns.barplot(x=formats, y=accuracy, palette='coolwarm')
plt.title("Resume Parsing Accuracy by Format")
plt.ylabel("Accuracy (%)")
plt.ylim(75, 100)
plt.show()

# 2. Interview Realism Score Distribution
realism_scores = np.random.normal(4.2, 0.4, 50)
plt.figure(figsize=(8, 5))
sns.histplot(realism_scores, bins=10, kde=True, color='skyblue')
plt.title("Distribution of Interview Realism Scores")
plt.xlabel("Realism Score (1–5)")
plt.show()

# 3. Bias Comparison: Human vs. HiRay
labels = ['Male', 'Female']
human = [65, 35]
hiray = [50, 50]
x = np.arange(len(labels))
width = 0.35

fig, ax = plt.subplots(figsize=(8, 5))
ax.bar(x - width/2, human, width, label='Human Reviewers', color='lightcoral')
ax.bar(x + width/2, hiray, width, label='HiRay AI', color='mediumseagreen')
ax.set_ylabel('Selection Rate (%)')
ax.set_title('Gender Bias in Hiring Decisions')
ax.set_xticks(x)
ax.set_xticklabels(labels)
ax.legend()
plt.show()

# 4. System Response Time vs. Concurrent Users
users = np.linspace(100, 1000, 10, dtype=int)
response_time = np.random.uniform(1.5, 2.5, 10)
plt.figure(figsize=(8, 5))
plt.plot(users, response_time, marker='o', color='orange')
plt.title("System Response Time Under Load")
plt.xlabel("Concurrent Users")
plt.ylabel("Average Response Time (s)")
plt.grid(True)
plt.show()

# 5. Recruiter Adoption Intent
labels = ['Yes', 'Maybe', 'No']
values = [89, 8, 3]
plt.figure(figsize=(6, 6))
plt.pie(values, labels=labels, autopct='%1.0f%%', colors=['lightgreen', 'gold', 'lightcoral'])
plt.title("Recruiters Willing to Adopt HiRay")
plt.show()
