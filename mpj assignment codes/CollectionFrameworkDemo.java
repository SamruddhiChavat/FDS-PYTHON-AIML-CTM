import java.util.ArrayList;
import java.util.Collections;

public class CollectionFrameworkDemo {
    public static void main(String[] args) {
        // Create a new ArrayList
        ArrayList<String> list1 = new ArrayList<>();

        // Add elements (String)
        list1.add("Apple");
        list1.add("Banana");
        list1.add("Cherry");
        list1.add("Date");
        list1.add("Elderberry");

        // Print out the collection by position
        System.out.println("Elements in the ArrayList:");
        for (int i = 0; i < list1.size(); i++) {
            System.out.println((i + 1) + ": " + list1.get(i));
        }

        // Search for an element in the ArrayList
        String searchElement = "Cherry";
        if (list1.contains(searchElement)) {
            System.out.println("\nElement '" + searchElement + "' found at position: " + (list1.indexOf(searchElement) + 1));
        } else {
            System.out.println("\nElement '" + searchElement + "' not found.");
        }

        // Reverse elements in the ArrayList
        Collections.reverse(list1);
        System.out.println("\nArrayList after reversing:");
        for (String item : list1) {
            System.out.println(item);
        }

        // Test if ArrayList is empty
        if (list1.isEmpty()) {
            System.out.println("\nArrayList is empty.");
        } else {
            System.out.println("\nArrayList is not empty.");
        }

        // Join two ArrayLists
        ArrayList<String> list2 = new ArrayList<>();
        list2.add("Fig");
        list2.add("Grape");

        ArrayList<String> joinedList = new ArrayList<>(list1);
        joinedList.addAll(list2);

        System.out.println("\nJoined ArrayList:");
        for (String item : joinedList) {
            System.out.println(item);
        }
    }
}
