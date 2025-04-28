
class Employee {
    String empName, empId, address, mailId;
    long mobileNo;

    Employee(String empName, String empId, String address, String mailId, long mobileNo) {
        this.empName = empName;
        this.empId = empId;
        this.address = address;
        this.mailId = mailId;
        this.mobileNo = mobileNo;
    }

    void display() {
        System.out.println("Employee Name: " + empName);
        System.out.println("Employee ID: " + empId);
        System.out.println("Address: " + address);
        System.out.println("Mail ID: " + mailId);
        System.out.println("Mobile No: " + mobileNo);
    }
}

class Programmer extends Employee {
    double basicPay;

    Programmer(String empName, String empId, String address, String mailId, long mobileNo, double basicPay) {
        super(empName, empId, address, mailId, mobileNo);
        this.basicPay = basicPay;
    }

    void generatePaySlip() {
        double DA = 0.97 * basicPay;
        double HRA = 0.10 * basicPay;
        double PF = 0.12 * basicPay;
        double staffClubFund = 0.001 * basicPay;
        double grossSalary = basicPay + DA + HRA;
        double netSalary = grossSalary - PF - staffClubFund;

        display();
        System.out.println("Gross Salary: " + grossSalary);
        System.out.println("Net Salary: " + netSalary);
    }
}

class TeamLead extends Employee {
    double basicPay;

    TeamLead(String empName, String empId, String address, String mailId, long mobileNo, double basicPay) {
        super(empName, empId, address, mailId, mobileNo);
        this.basicPay = basicPay;
    }

    void generatePaySlip() {
        double DA = 0.97 * basicPay;
        double HRA = 0.10 * basicPay;
        double PF = 0.12 * basicPay;
        double staffClubFund = 0.001 * basicPay;
        double grossSalary = basicPay + DA + HRA;
        double netSalary = grossSalary - PF - staffClubFund;

        display();
        System.out.println("Gross Salary: " + grossSalary);
        System.out.println("Net Salary: " + netSalary);
    }
}

class AssistantProjectManager extends Employee {
    double basicPay;

    AssistantProjectManager(String empName, String empId, String address, String mailId, long mobileNo, double basicPay) {
        super(empName, empId, address, mailId, mobileNo);
        this.basicPay = basicPay;
    }

    void generatePaySlip() {
        double DA = 0.97 * basicPay;
        double HRA = 0.10 * basicPay;
        double PF = 0.12 * basicPay;
        double staffClubFund = 0.001 * basicPay;
        double grossSalary = basicPay + DA + HRA;
        double netSalary = grossSalary - PF - staffClubFund;

        display();
        System.out.println("Gross Salary: " + grossSalary);
        System.out.println("Net Salary: " + netSalary);
    }
}

class ProjectManager extends Employee {
    double basicPay;

    ProjectManager(String empName, String empId, String address, String mailId, long mobileNo, double basicPay) {
        super(empName, empId, address, mailId, mobileNo);
        this.basicPay = basicPay;
    }

    void generatePaySlip() {
        double DA = 0.97 * basicPay;
        double HRA = 0.10 * basicPay;
        double PF = 0.12 * basicPay;
        double staffClubFund = 0.001 * basicPay;
        double grossSalary = basicPay + DA + HRA;
        double netSalary = grossSalary - PF - staffClubFund;

        display();
        System.out.println("Gross Salary: " + grossSalary);
        System.out.println("Net Salary: " + netSalary);
    }
}

public class EmployeeInheritanceDemo {
    public static void main(String[] args) {
        Programmer programmer = new Programmer("Alice", "P001", "Mumbai", "alice@mail.com", 9876543210L, 50000);
        programmer.generatePaySlip();

        System.out.println("\n");

        ProjectManager pm = new ProjectManager("Bob", "PM001", "Pune", "bob@mail.com", 9876509876L, 100000);
        pm.generatePaySlip();
    }
}
