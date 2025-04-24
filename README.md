# C Assignment: Data Operations Console Program

Welcome to your **C-based console data manager**! This program allows users to perform common operations on an array of integers — like inserting, updating, deleting, sorting, and searching — via a simple command-line interface.

## Features

- ✅ **Initialize** data manually
- ✅ **Insert** a new value
- ✅ **Update** a specific index
- ✅ **Delete** a value by index
- ✅ **Sort** the array in ascending order
- ✅ **Search** for a specific value
- ✅ **Display** current data
- ✅ **Exit** the program gracefully

## How It Works

The program maintains an internal array of integers and allows users to manipulate it through a simple menu-based interface. Each operation is tied to a number that you input when prompted.

## Getting Started

### 1. Clone the repository
```bash
git clone https://github.com/itzmac777/c_assignment_1.git
cd c_assignment_1
```
### 2. Compile the program
```bash
gcc main.c -o data_manager
```
### 2(i). For moduler programm
```bash
gcc .\c_assignment_1.c utils.c -o data_manager
```
### 3. Run the program
```bash
./data_manager
```
### 4. Preview
When you run the program, you will see the following menu to choose operations:

```plaintext
Which operation you wanna perform?
0. Init
1. Insert
2. Update
3. Delete
4. Sort
5. Search
6. Display
7. Exit
Your choice -->
```

## Code Structure

main() – Entry point, shows menu

init() – Initialize array with user input

insert() – Append a value to the array

update() – Replace value at a specific index

delete() – Remove a value by index

sort() – Sort array (Selection sort)

search() – Search for a value

print_data() – Display the current array

run_command() – Executes the correct function based on user input

## Notes

Enter 404 at any time during the init phase to exit early.

The program uses sleep() to simulate processing delays and improve user experience.

No dynamic memory allocation is used; it uses a fixed-size array (data[100]).
