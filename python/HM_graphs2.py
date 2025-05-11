import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Sample data: satisfaction scores out of 100
data = pd.DataFrame({
    'Platform': ['Mobile', 'Desktop'],
    'MeanSatisfaction': [82.5, 75.2],
    'StdDev': [5.3, 6.8]  # optional, for error bars
})

# Create the bar plot
plt.figure(figsize=(7, 5))
sns.barplot(x='Platform', y='MeanSatisfaction', data=data, palette='Set2', ci=None)

# Optionally add error bars (standard deviation)
plt.errorbar(x=[0, 1], y=data['MeanSatisfaction'], yerr=data['StdDev'], fmt='none', c='black', capsize=5)

plt.title('User Satisfaction by Platform (Mobile vs. Desktop)', fontsize=14)
plt.ylabel('Mean Satisfaction Score')
plt.ylim(0, 100)
plt.grid(axis='y', linestyle='--', alpha=0.7)
plt.tight_layout()
plt.show()
