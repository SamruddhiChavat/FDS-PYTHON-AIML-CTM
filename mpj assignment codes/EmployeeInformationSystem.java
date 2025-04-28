import java.util.Scanner;
class Employee {
    private String empName;
    private int empNumber;
    private String qualification;
    private String address;
    private String contactNumber;
    private double basicSalary;
    private double DA;
    private double TA;
    private double netSalary;

    static int count = 0;

    // Default constructor
    public Employee() {
        empName = "Not Provided";
        empNumber = 0;
        qualification = "Not Provided";
        address = "Not Provided";
        contactNumber = "Not Provided";
        basicSalary = 0.0;
        DA = 0.0;
        TA = 0.0;
        netSalary = 0.0;
        count++;
    }

    // Parameterized constructor
    public Employee(String empName, int empNumber, String qualification, String address, String contactNumber, double basicSalary, double DA, double TA) {
        this.empName = empName;
        this.empNumber = empNumber;
        this.qualification = qualification;
        this.address = address;
        this.contactNumber = contactNumber;
        this.basicSalary = basicSalary;
        this.DA = DA;
        this.TA = TA;
        this.netSalary = basicSalary + DA + TA;
        count++;
    }

    // Copy constructor
    public Employee(Employee other) {
        this.empName = other.empName;
        this.empNumber = other.empNumber;
        this.qualification = other.qualification;
        this.address = other.address;
        this.contactNumber = other.contactNumber;
        this.basicSalary = other.basicSalary;
        this.DA = other.DA;
        this.TA = other.TA;
        this.netSalary = other.netSalary;
        count++;
    }
   
    public void display() {
        System.out.println("Employee Name: " + empName);
        System.out.println("Employee Number: " + empNumber);
        System.out.println("Qualification: " + qualification);
        System.out.println("Address: " + address);
        System.out.println("Contact Number: " + contactNumber);
        System.out.println("Basic Salary: " + basicSalary);
        System.out.println("DA: " + DA);
        System.out.println("TA: " + TA);
        System.out.println("Net Salary: " + netSalary);
    }

    public static int getCount() {
        return count;
    }
}

public class EmployeeInformationSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Using Default Constructor
        System.out.println("Using Default Constructor:");
        Employee e1=new Employee();
        e1.display();

        // Using Parameterized Constructor
        System.out.println("\nUsing Parameterized Constructor:");
        Employee e2=new Employee("John Doe", 101, "B.Tech", "123 Main St", "9876543210", 50000, 10000, 5000);
        e2.display();

        // Using Copy Constructor
        System.out.println("\nUsing Copy Constructor:");
        Employee e3= new Employee(e2);
        e3.display();
        System.out.println("\nTotal Employees: " + Employee.getCount());
    }
}