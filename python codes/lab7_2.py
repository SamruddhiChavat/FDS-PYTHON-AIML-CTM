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
