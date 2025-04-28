interface Motorbike {
    int speed = 80; // in km/h

    void totalDistance();
}

interface Cycle {
    int distance = 120; // in km

    void speed();
}

class TwoWheeler implements Motorbike, Cycle {

    public void totalDistance() {
        System.out.println("Total Distance Travelled: " + distance + " km");
    }

    public void speed() {
        double avgSpeed = (double) distance / 2; // assuming 2 hours of journey
        System.out.println("Average Speed maintained: " + avgSpeed + " km/h");
    }
}

public class TwoWheelerDemo {
    public static void main(String[] args) {
        TwoWheeler tw = new TwoWheeler();
        tw.totalDistance();
        tw.speed();
    }
}
