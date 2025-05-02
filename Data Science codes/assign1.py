import pandas as pd

# Load dataset (replace with actual CSV file or log data)
data = pd.read_csv("C:/Users/Samruddhi/Downloads/Data Science codes/logs.csv")

# Convert to pandas DataFrame
df = pd.DataFrame(data)

# Convert columns to numeric (use errors='coerce' to handle any non-numeric values)
df['Packets'] = pd.to_numeric(df['Packets'], errors='coerce')
df['Bytes'] = pd.to_numeric(df['Bytes'], errors='coerce')
df['Flows'] = pd.to_numeric(df['Flows'], errors='coerce')

# Define thresholds for suspicious activity detection
def detect_suspicious_activity(row):
    # Criteria 1: High Traffic Volume (large packets or bytes)
    if row['Bytes'] > 15000:  # Adjust threshold as needed
        return "Suspicious"

    # Criteria 2: High Flows (suspicious if flows > 5)
    if row['Flows'] > 5:
        return "Suspicious"

    # Criteria 3: Unusual Protocol (ICMP often used for DDoS attacks)
    if row['Proto'] == "ICMP":
        return "Suspicious"

    # Criteria 4: Unusual Destination Ports (e.g., SSH - port 22)
    if row['Dst Pt'] == 22:
        return "Suspicious"

    return "Normal"

# Apply the detection function
df['Detected Activity'] = df.apply(detect_suspicious_activity, axis=1)

# Output the results with suspicious activity flagged
print(df)

# Save to CSV if required
df.to_csv("suspicious_activity_log.csv", index=False)
