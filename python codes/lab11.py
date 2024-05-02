import tkinter as tk
from datetime import datetime

def calculate_age():
    dob = dob_entry.get()
    try:
        dob_date = datetime.strptime(dob, "%Y-%m-%d")
        today = datetime.today()
        age = today.year - dob_date.year - ((today.month, today.day) < (dob_date.month, dob_date.day))
        age_label.config(text="Your age is: " + str(age))
    except ValueError:
        age_label.config(text="Invalid date format. Please enter in YYYY-MM-DD.")


root = tk.Tk()
root.title("Age Calculator")

dob_label = tk.Label(root, text="Enter your date of birth (YYYY-MM-DD):")
dob_label.pack()
dob_entry = tk.Entry(root)
dob_entry.pack()

calculate_button = tk.Button(root, text="Calculate Age", command=calculate_age)
calculate_button.pack()

age_label = tk.Label(root, text="")
age_label.pack()

root.mainloop()
