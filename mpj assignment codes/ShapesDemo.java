class Shapes {
    double area;

    Shapes(double radius) { // Circle
        area = Math.PI * radius * radius;
    }

    Shapes(int side) { // Square
        area = side * side;
    }

    Shapes(int length, int breadth) { // Rectangle
        area = length * breadth;
    }

    void findArea(double radius) {
        area = Math.PI * radius * radius;
        System.out.println("Area of Circle: " + area);
    }

    void findArea(int side) {
        area = side * side;
        System.out.println("Area of Square: " + area);
    }

    void findArea(int length, int breadth) {
        area = length * breadth;
        System.out.println("Area of Rectangle: " + area);
    }
}

public class ShapesDemo {
    public static void main(String[] args) {
        Shapes circle = new Shapes(5.0);
        System.out.println("Constructor Area of Circle: " + circle.area);

        Shapes square = new Shapes(4);
        System.out.println("Constructor Area of Square: " + square.area);

        Shapes rectangle = new Shapes(4, 5);
        System.out.println("Constructor Area of Rectangle: " + rectangle.area);

        System.out.println();
        Shapes shape = new Shapes(0); // Dummy for method overloading
        shape.findArea(6.0); // Circle
        shape.findArea(6); // Square
        shape.findArea(3, 7); // Rectangle
    }
}
