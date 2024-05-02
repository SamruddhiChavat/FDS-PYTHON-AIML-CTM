class StudentInfo:
    def __init__(self, name, roll_number):
        self.name = name
        self.roll_number = roll_number

    def display_info(self):
        print("Name:", self.name)
        print("Roll Number:", self.roll_number)


class StudentMarks(StudentInfo):
    def __init__(self, name, roll_number):
        self.name = name
        self.roll_number = roll_number
        self.subject_marks = []

    def input_marks(self):
        for i in range(3):
            mark = int(input(f"Enter marks for subject {i+1}: "))
            self.subject_marks.append(mark)

    def calculate_result(self):
        total_marks = sum(self.subject_marks)
        average_marks = total_marks / 3
        if average_marks >= 40 and all(mark >= 33 for mark in self.subject_marks):
            return "Pass"
        else:
            return "Fail"


def main():
    name = input("Enter student name: ")
    roll_number = input("Enter student roll number: ")

    student = StudentMarks(name, roll_number)
    student.input_marks()
    student.display_info()
    result = student.calculate_result()
    print("Result:", result)


if __name__ == "__main__":
    main()
















'''class Student:
    def __init__(self):
        self.subject_marks = []

    def input_marks(self):
        for i in range(3):
            mark = int(input(f"Enter marks for subject {i+1}: "))
            self.subject_marks.append(mark)

    def calculate_result(self):
        total_marks = sum(self.subject_marks)
        average_marks = total_marks / 3
        if average_marks >= 40 and all(mark >= 33 for mark in self.subject_marks):
            return "Pass"
        else:
            return "Fail"


def main():
    stud = Student()
    stud.input_marks()
    result = stud.calculate_result()
    print("Result:", result)


if __name__ == "__main__":
    main()
















class student():
    def __init__(self):
        self.subject_marks=[]

    def input_marks(self):
        for i in range(3):
            mark=float(input("Enter marks of subject [i+1]: "))
            self.subject_marks.append(mark)

    def calc_result(self):
        total_marks=sum(self.subject_marks)
        av_marks=total_marks/3
        if av_marks >=40 and all(mark >=33 for mark in self.subject_marks):
            return "PASS"
        else:
            return "FAIL"

def main():
    stud=student()
    stud.input_marks()
    result=student.calc_result()
    print("Results: ",result)

if __name__=="__main__":
     main()


'''