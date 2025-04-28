class EvenThread implements Runnable {
    public void run() {
        for (int i = 0; i <= 10; i += 2) {
            System.out.println("Even: " + i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

class OddThread implements Runnable {
    public void run() {
        for (int i = 1; i <= 10; i += 2) {
            System.out.println("Odd: " + i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

public class EvenOddThreads {
    public static void main(String[] args) {
        Thread even = new Thread(new EvenThread());
        Thread odd = new Thread(new OddThread());

        even.start();
        odd.start();
    }
}
