import java.util.Scanner;

public class ExceptionHandlingDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try {
            System.out.print("Enter first number (n1): ");
            int n1 = Integer.parseInt(sc.nextLine());

            System.out.print("Enter second number (n2): ");
            int n2 = Integer.parseInt(sc.nextLine());

            int[] arr = {n1, n2};

            System.out.println("Accessing 3rd element: " + arr[2]); // Will throw ArrayIndexOutOfBounds

            int result = n1 / n2;
            System.out.println("Division Result: " + result);
        }
        catch (NumberFormatException e) {
            System.out.println("NumberFormatException: Please enter valid integers.");
        }
        catch (ArithmeticException e) {
            System.out.println("ArithmeticException: Division by zero is not allowed.");
        }
        catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("ArrayIndexOutOfBoundsException: Invalid array access.");
        }
        finally {
            System.out.println("Program execution completed.");
        }
    }
}
