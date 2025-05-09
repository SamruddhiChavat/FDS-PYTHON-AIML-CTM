import pandas as pd

# Sample dataset of IDS alerts
data = {
    'alert_type': ['Login Attempt', 'Brute Force', 'SQL Injection', 'DDoS'],
    'frequency': [50, 120, 30, 200]
}

df = pd.DataFrame(data)

# Basic statistics
mean_freq = df['frequency'].mean()
median_freq = df['frequency'].median()
std_freq = df['frequency'].std()

print(f"Mean Frequency: {mean_freq}")
print(f"Median Frequency: {median_freq}")
print(f"Standard Deviation: {std_freq}")

