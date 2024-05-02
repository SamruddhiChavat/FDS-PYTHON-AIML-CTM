import pandas as pd

data = {'Name': ['Alice', 'Bob', 'Charlie', None],
        'Age': [25, 30, None, 42],
        'City': ['New York', 'London', None, 'Paris']}
df = pd.DataFrame(data)
print(df)

df.fillna('N/A', inplace=True)
df['Age'] = pd.to_numeric(df['Age'], errors='coerce') 
df.drop('Name', axis=1, inplace=True) 

df.head(5)
df.isnull()
df.dropna()

print(df)