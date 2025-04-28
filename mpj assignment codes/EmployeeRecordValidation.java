class AgeNotWithinRangeException extends Exception {
    AgeNotWithinRangeException(String message) {
        super(message);
    }
}

class NameNotValidException extends Exception {
    NameNotValidException(String message) {
        super(message);
    }
}

class Employee {
    int eid;
    String name;
    int age;
    String department;

    Employee(int eid, String name, int age, String department) throws AgeNotWithinRangeException, NameNotValidException {
        if (age < 25 || age > 60) {
            throw new AgeNotWithinRangeException("Age should be between 25 and 60.");
        }

        if (!name.matches("[a-zA-Z\\s]+")) {
            throw new NameNotValidException("Name should contain only alphabets and spaces.");
        }

        this.eid = eid;
        this.name = name;
        this.age = age;
        this.department = department;
    }

    void display() {
        System.out.println("Employee ID: " + eid);
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Department: " + department);
    }
}

public class EmployeeRecordValidation {
    public static void main(String[] args) {
        try {
            Employee e = new Employee(101, "John@123", 24, "IT");
            e.display();
        } catch (AgeNotWithinRangeException | NameNotValidException e) {
            System.out.println("Exception: " + e.getMessage());
        }
    }
}
