class Hillstations {
    void location() {
        System.out.println("General Hillstation Location");
    }

    void famousfor() {
        System.out.println("General Hillstation Famous For");
    }
}

class Manali extends Hillstations {
    void location() {
        System.out.println("Manali is located in Himachal Pradesh.");
    }

    void famousfor() {
        System.out.println("Manali is famous for adventure sports and snowfall.");
    }
}

class Shimla extends Hillstations {
    void location() {
        System.out.println("Shimla is located in Himachal Pradesh.");
    }

    void famousfor() {
        System.out.println("Shimla is famous for colonial architecture and pleasant climate.");
    }
}

class Mussoorie extends Hillstations {
    void location() {
        System.out.println("Mussoorie is located in Uttarakhand.");
    }

    void famousfor() {
        System.out.println("Mussoorie is famous for scenic beauty and waterfalls.");
    }
}

public class HillstationsDemo {
    public static void main(String[] args) {
        Hillstations h;

        h = new Manali();
        h.location();
        h.famousfor();

        System.out.println();

        h = new Shimla();
        h.location();
        h.famousfor();

        System.out.println();

        h = new Mussoorie();
        h.location();
        h.famousfor();
    }
}
