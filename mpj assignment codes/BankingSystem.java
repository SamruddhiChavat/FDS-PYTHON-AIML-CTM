import java.util.Scanner;

class InsufficientBalanceException extends Exception {
    InsufficientBalanceException(String message) {
        super(message);
    }
}

class InvalidAmountException extends Exception {
    InvalidAmountException(String message) {
        super(message);
    }
}

class InvalidCidException extends Exception {
    InvalidCidException(String message) {
        super(message);
    }
}

class Customer {
    int cid;
    String cname;
    double amount;

    Customer(int cid, String cname, double amount) throws InvalidAmountException, InvalidCidException {
        if (cid < 1 || cid > 20) {
            throw new InvalidCidException("Customer ID must be between 1 and 20.");
        }
        if (amount < 1000) {
            throw new InvalidAmountException("Initial deposit must be at least Rs. 1000.");
        }
        if (amount < 0) {
            throw new InvalidAmountException("Amount cannot be negative.");
        }
        this.cid = cid;
        this.cname = cname;
        this.amount = amount;
    }

    void deposit(double amt) throws InvalidAmountException {
        if (amt <= 0) {
            throw new InvalidAmountException("Deposit amount must be positive.");
        }
        amount += amt;
        System.out.println("Deposited Rs. " + amt + " successfully!");
    }

    void withdraw(double amt) throws InsufficientBalanceException, InvalidAmountException {
        if (amt <= 0) {
            throw new InvalidAmountException("Withdrawal amount must be positive.");
        }
        if (amt > amount) {
            throw new InsufficientBalanceException("Not enough balance to withdraw.");
        }
        amount -= amt;
        System.out.println("Withdrawn Rs. " + amt + " successfully!");
    }

    void display() {
        System.out.println("Customer ID: " + cid);
        System.out.println("Name: " + cname);
        System.out.println("Balance: Rs. " + amount);
    }
}

public class BankingSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Customer c = null;

        try {
            System.out.print("Enter Customer ID: ");
            int id = sc.nextInt();
            sc.nextLine(); // consume newline
            System.out.print("Enter Name: ");
            String name = sc.nextLine();
            System.out.print("Enter Initial Amount: ");
            double amt = sc.nextDouble();

            c = new Customer(id, name, amt);

            int choice;
            do {
                System.out.println("\n1. Deposit\n2. Withdraw\n3. Display\n4. Exit");
                System.out.print("Enter your choice: ");
                choice = sc.nextInt();

                switch (choice) {
                    case 1:
                        System.out.print("Enter amount to deposit: ");
                        double dep = sc.nextDouble();
                        c.deposit(dep);
                        break;
                    case 2:
                        System.out.print("Enter amount to withdraw: ");
                        double wth = sc.nextDouble();
                        c.withdraw(wth);
                        break;
                    case 3:
                        c.display();
                        break;
                    case 4:
                        System.out.println("Thank you for banking with us!");
                        break;
                    default:
                        System.out.println("Invalid choice!");
                }
            } while (choice != 4);

        } catch (InvalidAmountException | InsufficientBalanceException | InvalidCidException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
