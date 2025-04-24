#include "utils.h"

// Print available operations


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
