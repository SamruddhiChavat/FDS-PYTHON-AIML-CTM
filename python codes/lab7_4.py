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