import pandas as pd

# Load the dataset
df = pd.read_csv('C:/Users/Samruddhi/Downloads/Data Science codes/Malware dataset.csv')  # replace with actual dataset path
print(df.head())

# Handling Missing Values
print("Missing values:\n", df.isnull().sum())
df = df.dropna()  # or df.fillna(value)

# Handling Duplicate Values
print("Duplicates before removal:", df.duplicated().sum())
df = df.drop_duplicates()

# Handling Categorical Values
print(df.dtypes)
# Convert categorical columns using one-hot encoding or label encoding
df = pd.get_dummies(df, drop_first=True)  # one-hot encoding

from sklearn.preprocessing import MinMaxScaler, StandardScaler

# Assuming df contains only numerical columns after encoding
scaler_norm = MinMaxScaler()
df_normalized = scaler_norm.fit_transform(df)

scaler_std = StandardScaler()
df_standardized = scaler_std.fit_transform(df)
