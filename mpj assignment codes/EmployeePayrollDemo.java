abstract class Employee {
    String name;
    int empId;

    Employee(String name, int empId) {
        this.name = name;
        this.empId = empId;
    }

    abstract void calculateSalary();
}

class SalariedEmployee extends Employee {
    double monthlySalary;

    SalariedEmployee(String name, int empId, double monthlySalary) {
        super(name, empId);
        this.monthlySalary = monthlySalary;
    }

    void calculateSalary() {
        System.out.println(name + "'s Salary: " + monthlySalary);
    }
}

class CommissionEmployee extends Employee {
    double salesAmount;
    double commissionRate;

    CommissionEmployee(String name, int empId, double salesAmount, double commissionRate) {
        super(name, empId);
        this.salesAmount = salesAmount;
        this.commissionRate = commissionRate;
    }

    void calculateSalary() {
        double salary = salesAmount * commissionRate;
        System.out.println(name + "'s Salary: " + salary);
    }
}

class HourlyEmployee extends Employee {
    double hoursWorked;
    double hourlyRate;

    HourlyEmployee(String name, int empId, double hoursWorked, double hourlyRate) {
        super(name, empId);
        this.hoursWorked = hoursWorked;
        this.hourlyRate = hourlyRate;
    }

    void calculateSalary() {
        double salary = hoursWorked * hourlyRate;
        System.out.println(name + "'s Salary: " + salary);
    }
}

public class EmployeePayrollDemo {
    public static void main(String[] args) {
        Employee e1 = new SalariedEmployee("Alice", 1, 50000);
        Employee e2 = new CommissionEmployee("Bob", 2, 200000, 0.10);
        Employee e3 = new HourlyEmployee("Charlie", 3, 120, 300);

        e1.calculateSalary();
        e2.calculateSalary();
        e3.calculateSalary();
    }
}
