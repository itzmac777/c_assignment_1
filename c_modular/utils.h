#include <stdio.h>
#include <unistd.h>

#define command_count 8
#define command_size 50
#define data_size 100
#define sleep_param 1
#define early_exit 404

void print_command_list();
int print_data(int data[data_size], int size);
int init(int data[data_size], int size);
int insert(int data[data_size], int size);
int update(int data[data_size], int size);
int delete(int data[data_size], int size);
int sort(int data[data_size], int size);
int search(int data[data_size], int size);
int run_command(int operation_index, int data[data_size], int size);