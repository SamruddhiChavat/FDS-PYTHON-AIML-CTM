class Addition extends Thread {
    int a, b;
    Addition(int a, int b) {
        this.a = a;
        this.b = b;
    }
    public void run() {
        System.out.println("Addition: " + (a + b));
    }
}

class Subtraction extends Thread {
    int a, b;
    Subtraction(int a, int b) {
        this.a = a;
        this.b = b;
    }
    public void run() {
        System.out.println("Subtraction: " + (a - b));
    }
}

class Multiplication extends Thread {
    int a, b;
    Multiplication(int a, int b) {
        this.a = a;
        this.b = b;
    }
    public void run() {
        System.out.println("Multiplication: " + (a * b));
    }
}

class Division extends Thread {
    int a, b;
    Division(int a, int b) {
        this.a = a;
        this.b = b;
    }
    public void run() {
        try {
            System.out.println("Division: " + (a / b));
        } catch (ArithmeticException e) {
            System.out.println("Error: Division by zero!");
        }
    }
}

public class MultithreadedCalculator {
    public static void main(String[] args) {
        int num1 = 20;
        int num2 = 0; // Try changing to non-zero to test

        Addition add = new Addition(num1, num2);
        Subtraction sub = new Subtraction(num1, num2);
        Multiplication mul = new Multiplication(num1, num2);
        Division div = new Division(num1, num2);

        add.start();
        sub.start();
        mul.start();
        div.start();
    }
}
