import pandas as pd
import numpy as np
from sklearn.cluster import KMeans
from sklearn.metrics import classification_report

# 1. Load your data (update path as needed)
df = pd.read_csv("C:/Users/Samruddhi/Downloads/Data Science codes/network_traffic1.csv")


X             = df.drop(columns=['IsAnomaly'])
y_true        = df['IsAnomaly']
best_k        = 5   # from your grid‐search result
km            = KMeans(n_clusters=best_k, random_state=42).fit(X)
clusters_best = km.labels_

# 1) Compute true‐anomaly rate per cluster
rates_best = {c: y_true[clusters_best == c].mean()
              for c in range(best_k)}

# 2) Either pick a cutoff (e.g. average rate)…
cutoff      = np.mean(list(rates_best.values()))  
anom_clusts = [c for c,r in rates_best.items() if r > cutoff]

#  OR pick the top‑N clusters by rate—
#  e.g. the two clusters with the highest anomaly‐rates:
# anom_clusts = sorted(rates_best, key=rates_best.get, reverse=True)[:2]

print("Clusters flagged as anomalies:", anom_clusts)

# 3) Build predictions
y_pred_multi = pd.Series(clusters_best).map(lambda c: 1 if c in anom_clusts else 0)

# 4) Evaluate
print("\nClassification Report (multi‐cluster):\n")
print(classification_report(y_true, y_pred_multi, digits=4))
