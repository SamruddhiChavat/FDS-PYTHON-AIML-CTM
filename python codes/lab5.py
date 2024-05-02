def create_dict():
    return {}

def append_dict(dict, key, val):
    dict[key] = val

def remove_from_dict(dict, key):
    if key in dict:
        del dict[key]

def get_value(dict, key):
    return dict.get(key, None)

def update_dict(dict, key, value):
    dict[key] = value

def create_tuple():
    return ()

def append_to_tuple(tup, element):
    return tup + (element,)

def remove_from_tuple(tup, element):
    return tuple(x for x in tup if x != element)

def display_menu():
    print("1. Append to dictionary")
    print("2. Remove from dictionary")
    print("3. Get value from dictionary")
    print("4. Update dictionary")
    print("5. Append to tuple")
    print("6. Remove from tuple")
    print("7. Exit")

def main():
    my_dict = create_dict()
    my_tuple = create_tuple()

    while True:
        display_menu()
        choice = input("Enter your choice: ")

        if choice == '1':
            key = input("Enter key: ")
            val = input("Enter value: ")
            append_dict(my_dict, key, val)
        elif choice == '2':
            key = input("Enter key to remove: ")
            remove_from_dict(my_dict, key)
        elif choice == '3':
            key = input("Enter key to get value: ")
            print("Value:", get_value(my_dict, key))
        elif choice == '4':
            key = input("Enter key to update: ")
            val = input("Enter new value: ")
            update_dict(my_dict, key, val)
        elif choice == '5':
            element = input("Enter element to append to tuple: ")
            my_tuple = append_to_tuple(my_tuple, element)
        elif choice == '6':
            element = input("Enter element to remove from tuple: ")
            my_tuple = remove_from_tuple(my_tuple, element)
        elif choice == '7':
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 7.")

if __name__ == "__main__":
    main()
