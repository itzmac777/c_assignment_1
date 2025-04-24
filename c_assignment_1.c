#include <stdio.h>
#include <unistd.h>

#define command_count 8
#define command_size 50
#define data_size 100
#define sleep_param 1
#define early_exit 404

// Print available operations
void print_command_list() {
    char command_list[command_count][command_size] = {
        "Init", "Insert", "Update", "Delete",
        "Sort", "Search", "Display", "Exit"
    };

    printf("Which operation you wanna perform?\n");
    for (int i = 0; i < command_count; i++) {
        printf("%d. %s \n", i, command_list[i]);
    }
    printf("Your choice --> ");
}

// Display current data
int print_data(int data[data_size], int size) {
    if (size == 0) {
        printf("No data to display. Press 0 to initialize data\n");
        sleep(sleep_param * 2);
        return size;
    }

    printf("Your current data: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n\n\n");
    sleep(sleep_param * 2);
    return size;
}

// Initialize data array
int init(int data[data_size], int size) {
    int i = 0;

    printf("Tips: Type %d to early exit\n", early_exit);
    printf("Enter your desired size --> ");
    scanf("%d", &size);

    printf("Enter your numbers\n");
    while (i < size) {
        printf("--> ");
        scanf("%d", &data[i]);
        if (data[i] == early_exit) break;
        i++;
    }

    printf("Your data was initialized successfully!\n");
    print_data(data, i);
    return i;
}

// Insert a new number
int insert(int data[data_size], int size) {
    printf("Enter an integer value you wanna insert --> ");
    scanf("%d", &data[size]);

    printf("%d was Inserted Successfully!\n", data[size]);
    size++;
    print_data(data, size);
    return size;
}

// Update a value at specific index
int update(int data[data_size], int size) {
    int index;
    printf("From 0 to %d which index you wanna update? --> ", size - 1);
    scanf("%d", &index);

    if (index < 0 || index >= size) {
        printf("Not a valid index\n");
        sleep(sleep_param * 2);
    } else {
        printf("Enter the value to replace `%d` with --> ", data[index]);
        scanf("%d", &data[index]);
        print_data(data, size);
    }

    return size;
}

// Delete a value at specific index
int delete(int data[data_size], int size) {
    int index;
    print_data(data, size);

    printf("From 0 to %d which index you wanna delete? --> ", size - 1);
    scanf("%d", &index);

    if (index < 0 || index >= size) {
        printf("Not a valid index\n");
        sleep(sleep_param * 2);
    } else {
        for (int k = index; k < size - 1; k++) {
            data[k] = data[k + 1];
        }
        size--;
        print_data(data, size);
    }

    return size;
}

// Sort the data
int sort(int data[data_size], int size) {
    int secondary_size = size;
    int sorted_arr[secondary_size];

    for (int i = 0; i < secondary_size; i++) {
        int smallest_index = 0;
        for (int j = 0; j < size; j++) {
            if (data[j] < data[smallest_index]) {
                smallest_index = j;
            }
        }

        sorted_arr[i] = data[smallest_index];

        // Remove smallest value from original data
        int position = 0;
        for (int k = 0; k < size; k++) {
            if (k != smallest_index) {
                data[position++] = data[k];
            }
        }
        size--;
    }

    // Copy sorted back to original array
    for (int i = 0; i < secondary_size; i++) {
        data[i] = sorted_arr[i];
    }

    print_data(data, secondary_size);
    return secondary_size;
}

// Search for a value
int search(int data[data_size], int size) {
    int query, index = -1;

    printf("Which number you wanna search for? --> ");
    scanf("%d", &query);

    for (int i = 0; i < size; i++) {
        if (data[i] == query) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Your number %d was found at index %d\n\n", query, index);
    } else {
        printf("Your number %d was not found.\n\n", query);
    }

    sleep(sleep_param * 2);
    return size;
}

// Execute selected command
int run_command(int operation_index, int data[data_size], int size) {
    switch (operation_index) {
        case 0: size = init(data, size); break;
        case 1: size = insert(data, size); break;
        case 2: size = update(data, size); break;
        case 3: size = delete(data, size); break;
        case 4: size = sort(data, size); break;
        case 5: size = search(data, size); break;
        case 6: size = print_data(data, size); break;
        default: break;
    }
    return size;
}

// Main program loop
int main() {
    int size = 0;
    int data[data_size];
    int operation = -1;

    printf("You have no data stored. Let's initialize your array.\n");
    printf("Enter 0 to initialize your data\n");

    while (operation != 7) {
        print_command_list();
        scanf("%d", &operation);
        size = run_command(operation, data, size);
    }

    printf("Exiting program....\n");
    sleep(sleep_param * 2);
    return 0;
}
