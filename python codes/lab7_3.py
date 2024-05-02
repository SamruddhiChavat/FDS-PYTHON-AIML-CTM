import seaborn as sns
import matplotlib.pyplot as plt
import pandas as pd
data = {
    'Category': ['A', 'B', 'C', 'D', 'E'],
    'Value1': [10, 25, 15, 30, 20],
    'Value2': [5, 15, 10, 20, 12]
}
df = pd.DataFrame(data)
plt.figure(figsize=(8, 5))
sns.scatterplot(x='Value1', y='Value2', data=df, hue='Category', s=100)
plt.title('Scatter Plot')
plt.show()
plt.figure(figsize=(8, 5))
sns.barplot(x='Category', y='Value1', data=df, palette='viridis',legend=False)
plt.title('Bar Chart')
plt.show()

