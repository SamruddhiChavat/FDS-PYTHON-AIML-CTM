#1

import pandas as pd
df=pd.read_csv('students_data.csv')
print("Basic Information about dataframe:")
print(df.info())
print("\nSummary Statistics:")
print(df.describe())
print("\nDisplay top five rows:")
print(df.head())
print("\nDisplay bottom five rows:")
print(df.tail())

#2
import pandas as pd
import matplotlib.pyplot as plt

data = {'Name': ['Alice', 'Bob', 'Charlie', 'David'],
    	'Age': [25, 30, 35, 28],
    	'Salary': [50000, 60000, 75000, 48000]}
df = pd.DataFrame(data)

plt.bar(df['Name'], df['Salary'])
plt.xlabel('Name')
plt.ylabel('Salary')
plt.title('Salary Distribution')

plt.show()



#3
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




#4
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



#5
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

dataset=pd.read_csv("WorldCupMatches.csv")

dataset.head(10)
dataset.tail(7)
dataset.shape
(4572,20)
dataset.describe()
print(dataset)

print(dataset[0:5]['City'])


