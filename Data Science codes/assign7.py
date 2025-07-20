import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Load the dataset
df = pd.read_csv('C:/Users/Samruddhi/Downloads/Data Science codes/cybersecurity_attacks.csv')


# Convert Timestamp to datetime
df['Timestamp'] = pd.to_datetime(df['Timestamp'], dayfirst=True)

# Extract date or month for grouping
df['Month'] = df['Timestamp'].dt.to_period('M')

# Count attack types over time
attack_counts = df.groupby(['Month', 'Attack Type']).size().unstack(fill_value=0)

# Plot
attack_counts.plot(kind='bar', stacked=True, figsize=(14, 6))
plt.title('Attack Types Over Time')
plt.xlabel('Month')
plt.ylabel('Number of Attacks')
plt.xticks(rotation=45)
plt.tight_layout()
plt.show()

# Extract hour
df['Hour'] = df['Timestamp'].dt.hour

# Count connections per hour
hourly_counts = df.groupby('Hour').size()

# Plot
plt.figure(figsize=(10, 5))
sns.lineplot(x=hourly_counts.index, y=hourly_counts.values, marker='o')
plt.title('Connection Counts Per Hour')
plt.xlabel('Hour of Day')
plt.ylabel('Number of Connections')
plt.xticks(range(0, 24))
plt.grid(True)
plt.tight_layout()
plt.show()

num_cols = ['Packet Length', 'Anomaly Scores']  # Add more if available

# Convert to numeric (in case of any parsing issues)
for col in num_cols:
    df[col] = pd.to_numeric(df[col], errors='coerce')

# Drop rows with NaNs
cor_df = df[num_cols].dropna()

# Correlation matrix
corr = cor_df.corr()

# Heatmap
plt.figure(figsize=(8, 6))
sns.heatmap(corr, annot=True, cmap='coolwarm', fmt=".2f")
plt.title('Correlation Between Packet Length, Anomaly Scores, etc.')
plt.tight_layout()
plt.show()
