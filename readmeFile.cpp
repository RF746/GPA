This project contains four C programs that demonstrate various functionalities. Follow the instructions below to compile and run each program.

## Program 1: pre.c
This program reads a list of student names and their GPAs from the keyboard. It displays the names of students whose GPAs are above 3.0.

### Compilation:
gcc -o pre pre.c

### Execution:
./pre

### Example Usage:
1. Run the program:
./pre
2. Enter the student names and GPAs:
Susan 3.1
John 2.0
David 3.5
Jessica 3.4
Ctrl-D (press Ctrl-D to terminate the inputs)

Expected Output:
Students with GPA above 3.0:
Susan
David
Jessica

## Program 2: sort.c
This program reads a list of student names from the keyboard and displays them in alphabetical order.

### Compilation:
gcc -o sort sort.c

### Execution:
./sort

### Example Usage:
1. Run the program:
./sort
2. Enter the student names:
Susan
David
Jessica
Ctrl-D (press Ctrl-D to terminate the inputs)

Expected Output:
Sorted student names:
David
Jessica
Susan

## Program 3: pipe.c
This program sets up a parent-to-child pipe. The parent executes the "pre" program and its output is connected to the child's input, which executes the "sort" program.

### Compilation:
gcc -o pipe pipe.c

### Execution:
Ensure that `pre` and `sort` programs are compiled and executable in the same directory.
./pipe

### Example Usage:
1. Run the program:
./pipe
2. Enter the student names and GPAs:
Susan 3.1
John 2.0
David 3.5
Jessica 3.4
Ctrl-D (press Ctrl-D to terminate the inputs)

Expected Output:
David
Jessica
Susan

## Program 4: UNIX Command Executor
This program takes a UNIX command from the command line, forks a child to execute it, and the parent waits for the child to terminate.

### Compilation:
gcc -o prog unix_command_executor.c

### Execution:
./prog <command> [arguments]

### Example Usage:
1. Run the program with a UNIX command:
./prog ls -l

Expected Output:
Parent PID: <parent_pid>
Waiting for child process to terminate...
<output of ls -l command>
Child process terminated.

## Notes
- Ensure you have the necessary permissions to execute the compiled binaries.
- Use `Ctrl-D` to send EOF when entering data for `pre` and `sort` programs.
- Ensure the `pre` and `sort` programs are in the same directory as the `pipe` program when executing `pipe`.
