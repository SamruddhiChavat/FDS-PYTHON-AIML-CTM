class Employee {
    String empName;
    double salary;

    Employee(String empName, double salary) {
        this.empName = empName;
        this.salary = salary;
    }

    void displaySalary() {
        System.out.println(empName + "'s Salary before increment: " + salary);
    }
}

class FullTimeEmployee extends Employee {
    FullTimeEmployee(String empName, double salary) {
        super(empName, salary);
    }

    void calculateSalary() {
        salary += salary * 0.50;
        System.out.println(empName + "'s Salary after 50% increment: " + salary);
    }
}

class InternEmployee extends Employee {
    InternEmployee(String empName, double salary) {
        super(empName, salary);
    }

    void calculateSalary() {
        salary += salary * 0.25;
        System.out.println(empName + "'s Salary after 25% increment: " + salary);
    }
}

public class HierarchicalInheritanceDemo {
    public static void main(String[] args) {
        FullTimeEmployee fte = new FullTimeEmployee("Charlie", 40000);
        InternEmployee intern = new InternEmployee("Dave", 15000);

        fte.displaySalary();
        fte.calculateSalary();

        System.out.println();

        intern.displaySalary();
        intern.calculateSalary();
    }
}
