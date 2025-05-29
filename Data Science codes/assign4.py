import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import LabelEncoder

# Simulated Network Traffic Data (Replace with actual dataset)
data = {
    "Src_IP": ["192.168.1.1", "192.168.1.2", "10.0.0.1", "172.16.0.5", "192.168.1.1"],
    "Dst_IP": ["10.0.0.2", "172.16.0.6", "192.168.1.3", "10.0.0.3", "172.16.0.6"],
    "Bytes": [2000, 5000, 1000, 70000, 1500],  # Bytes transferred
    "Packets": [5, 12, 3, 180, 4]  # Packets sent (Target)
}

df = pd.DataFrame(data)

# Convert IPs to numerical values
encoder = LabelEncoder()
df["Src_IP"] = encoder.fit_transform(df["Src_IP"])
df["Dst_IP"] = encoder.fit_transform(df["Dst_IP"])

# Features (X) and Target (y)
X = df[["Src_IP", "Dst_IP", "Bytes"]]
y = df["Packets"]

# Train Linear Regression Model
model = LinearRegression()
model.fit(X, y)

# Predict the number of packets
df["Predicted_Packets"] = model.predict(X)

# Calculate error
df["Error"] = np.abs(df["Packets"] - df["Predicted_Packets"])

# Set threshold (95th percentile)
threshold = np.percentile(df["Error"], 95)
df["Anomaly"] = df["Error"] > threshold  # Flag anomalies

# Print Anomalies
print("Suspicious Traffic Detected:\n", df[df["Anomaly"]])

# Plot Results
plt.figure(figsize=(10, 5))
plt.scatter(df.index, df["Error"], label="Error", color="blue")
plt.axhline(y=threshold, color="r", linestyle="--", label="Anomaly Threshold")
plt.scatter(df[df["Anomaly"]].index, df[df["Anomaly"]]["Error"], color="red", label="Anomalies")
plt.legend()
plt.xlabel("Index")
plt.ylabel("Prediction Error")
plt.title("Network Traffic Anomaly Detection")
plt.show()