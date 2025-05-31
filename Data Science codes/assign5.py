import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix


from sklearn.metrics import roc_curve, auc
import matplotlib.pyplot as plt

# Load the dataset (update the path as needed)
df = pd.read_csv("C:/Users/Samruddhi/Downloads/Data Science codes/Malware dataset.csv")  # Or the correct CSV filename

# Display the first few rows
#print(df.head())

# Drop irrelevant columns (like 'hash' or any identifier)
df = df.drop(columns=['hash'], errors='ignore')

# Rename the 'classificati' column to 'label' for clarity (if required)
df = df.rename(columns={'classification': 'label'})

# Encode the 'label' column (malware = 1, benign = 0)
df['label'] = df['label'].map({'malware': 1, 'benign': 0})

df.head()

# Separate features and label
X = df.drop(columns=['label'])
y = df['label']

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

# Scale features
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)


# Train model
model = GaussianNB()
model.fit(X_train_scaled, y_train)

# Predict on test set
y_pred = model.predict(X_test_scaled)

# Evaluation

print("\nConfusion Matrix:\n", confusion_matrix(y_test, y_pred))
print("\nClassification Report:\n", classification_report(y_test, y_pred))


# Predict probabilities (needed for ROC curve)
y_probs = model.predict_proba(X_test_scaled)[:, 1]  # Probability for class 1 (malware)

# Compute ROC curve and AUC
fpr, tpr, thresholds = roc_curve(y_test, y_probs)
roc_auc = auc(fpr, tpr)

# Plotting the ROC Curve
plt.figure(figsize=(8, 6))
plt.plot(fpr, tpr, color='blue', label=f"ROC curve (AUC = {roc_auc:.2f})")
plt.plot([0, 1], [0, 1], color='red', linestyle='--', label="Random Guess")
plt.xlabel("False Positive Rate")
plt.ylabel("True Positive Rate")
plt.title("ROC Curve - Naive Bayes Classifier")
plt.legend(loc="lower right")
plt.grid(True)
plt.show()
