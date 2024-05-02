'''def create_lst():
    return []

def append_n(lst, n):
    lst.append(n)

def pop_lst(lst):
    lst.pop()

def insert_by_index(lst, index, n):
    lst.insert(index, n)

def count_n(lst, n):
    print("Number of items in the list are", lst.count(n))

def reverse_lst(lst):
    lst.reverse()

def remove_n(lst, n):
    lst.remove(n)

def sort_lst(lst):
    lst.sort()

def display_menu():
    print("1. Append to the list")
    print("2. Pop from the list")
    print("3. Insert by index")
    print("4. Count occurrences of an item")
    print("5. Reverse the list")
    print("6. Remove an item from the list")
    print("7. Sort the list")
    print("8. Display the list")
    print("9. Exit")

def main():
    lst1 = create_lst()

    while True:
        display_menu()
        choice = input("Enter your choice: ")

        if choice == '1':
            item = input("Enter item to append: ")
            append_n(lst1, item)
        elif choice == '2':
            pop_lst(lst1)
        elif choice == '3':
            index = int(input("Enter index: "))
            item = input("Enter item to insert: ")
            insert_by_index(lst1, index, item)
        elif choice == '4':
            item = input("Enter item to count: ")
            count_n(lst1, item)
        elif choice == '5':
            reverse_lst(lst1)
        elif choice == '6':
            item = input("Enter item to remove: ")
            remove_n(lst1, item)
        elif choice == '7':
            sort_lst(lst1)
        elif choice == '8':
            print("List:", lst1)
        elif choice == '9':
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 9.")

if __name__ == "__main__":
    main()

'''
# Taking user input for list elements
input_str = input("Enter elements separated by spaces: ")
user_list = [int(x) for x in input_str.split()]  # Converting input to list of integers

# Accessing Elements
print("First element:", user_list[0])  # Accessing the first element
print("Last element:", user_list[-1])  # Accessing the last element

# Slicing
print("Slice from index 1 to 3:", user_list[1:4])  # Slicing from index 1 to 3 (exclusive)

# Appending Elements
new_element = int(input("Enter an element to append: "))
user_list.append(new_element)  # Appending the input element to the end of the list

# Inserting Elements
index = int(input("Enter the index to insert: "))
new_value = int(input("Enter the value to insert: "))
user_list.insert(index, new_value)  # Inserting value at specified index

# Removing Elements
value_to_remove = int(input("Enter the value to remove: "))
user_list.remove(value_to_remove)  # Removing the specified value from the list

# Popping Elements
popped_element = user_list.pop()  # Removing and returning the last element

# Concatenating Lists
additional_elements = input("Enter additional elements separated by spaces for concatenation: ")
additional_list = [int(x) for x in additional_elements.split()]  # Converting input to list of integers
new_list = user_list + additional_list  # Concatenating two lists

# Printing the modified list and popped element
print("Modified list:", user_list)
print("Popped element:", popped_element)
print("Concatenated list:", new_list)

