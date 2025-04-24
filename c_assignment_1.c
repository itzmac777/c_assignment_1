#include <stdio.h>
#include <unistd.h> 
#define command_count 8
#define command_size 50
#define data_size 100
#define sleep_param 1
#define early_exit 404


void print_command_list(){
    char command_list[command_count][command_size] = {
        "Init",
        "Insert",
        "Update",
        "Delete",
        "Sort",
        "Search",
        "Display",
        "Exit"
    };
    printf("Which operation you wanna perform?\n");
    for(int i = 0; i < command_count; i++){
        printf("%d. %s \n", i, command_list[i]);
    }
    printf("Your choice --> ");
}


int print_data(int data[data_size], int size){
    if(size == 0){
        printf("No data to display. Press 0 to initialize data\n");
        sleep(sleep_param * 2);
        return size;
    }
    printf("Your current data: ");
    for(int i = 0; i < size; i++){
        printf("%d ", data[i]);
    }
    printf("\n\n\n");
    sleep(sleep_param * 2);
    return size;
}

int init(int data[data_size], int size){
    int i = 0;
    printf("Tips: Type %d to early exit\n", early_exit);
    printf("Enter your desired size --> ");
    scanf("%d", &size);
    printf("Enter your numbers\n");
    while((i < size)){
        printf("--> ");
        scanf("%d", &data[i]);
        if(data[i] == early_exit) break;
        i++;
    }
    printf("Your data was initialized successfully!\n");
    print_data(data, i);
    return i;
}

int insert(int data[data_size], int size){
    printf("Enter a integer value you wanna insert--> ");
    scanf("%d", &data[size]);
    printf("%d was Inserted Successfully!\n", data[size]);
    size++;
    print_data(data, size);
    return size;
}


int update(int data[data_size], int size){
    int index;
    printf("From 0 to %d which index you wanna update? --> ", size - 1);
    scanf("%d", &index);
    if(index < 0 || index > size -1){
        printf("Not a valid index");
        sleep(sleep_param * 2);
        return size;
    } else{
        printf("Enter the value to replace value `%d` with --> ", data[index]);
        scanf("%d", &data[index]);
        print_data(data, size);
        return size;
    }
}

int delete(int data[data_size], int size){
    int index;
    print_data(data, size);
    printf("From 0 to %d which index you wanna delete? --> ", size - 1);
    scanf("%d", &index);
    if(index < 0 || index > size -1){
        printf("Not a valid index");
        sleep(sleep_param * 2);
        return size;
    } else{
        int position = 0;
        for(int k = 0; k < size; k++){
            if(k == index){
                continue;
            } else{
                data[position] = data[k];
                position++;
            }
        }
        size -= 1;
        print_data(data, size);
        return size;
    }
}


int sort(int data[data_size], int size){
    int secondary_size = size;
    int sorted_arr[secondary_size];
    for(int i = 0; i < secondary_size; i++){
        int smallest_index = 0;
        for(int j = 0; j < size; j++){
            if(data[j] < data[smallest_index]){
                smallest_index = j;
            }
        }
        sorted_arr[i] = data[smallest_index];
        int position = 0;
        for(int k = 0; k < size; k++){
            if(k == smallest_index){
                continue;
            } else{
                data[position] = data[k];
                position++;
            }
        }
        size -= 1;
    }
    for(int i = 0; i < secondary_size; i++){
        data[i] = sorted_arr[i];
    }
    print_data(data, secondary_size);
    return secondary_size;
}

int search(int data[data_size], int size){
    int query, index = 0;
    printf("Which number you wanna search for? --> ");
    scanf("%d", &query);
    for(int i = 0; i < size; i++){
        if(data[i] == query){
            index = 1;
            index += i;
            break;
        }
    }
    if(index > 0 && index <= size){
        printf("Your number %d was found on index %d\n\n", query, index - 1);
        sleep(sleep_param * 2);
    } else{
        printf("Your number %d was not found.\n\n", query);
        sleep(sleep_param * 2);
    }
    return size;
}




int run_command(int operation_index,int data[data_size], int size){
    if(operation_index == 0) {
        size = init(data, size);
    }
    if(operation_index == 1) {
        size = insert(data, size);
    };
    if(operation_index == 2) {
        size = update(data, size);
    };
    if(operation_index == 3) {
        size = delete(data, size);
    };
    if(operation_index == 4) {
        size = sort(data, size);
    };
    if(operation_index == 5) {
        size = search(data, size);
    };
    if(operation_index == 6) {
        size = print_data(data, size);
    };
    return size;
}


int main(){
    int size = 0;
    printf("You have no data stored, Lets initialize your array.\n");
    printf("Enter 0 to initialize your data\n");
    int data[data_size], operation; 
    while(operation != 7){
        print_command_list();
        scanf("%d", &operation);
        size = run_command(operation, data, size);
    }
    printf("Exiting program....");
    sleep(sleep_param * 2);
    return 0;
}