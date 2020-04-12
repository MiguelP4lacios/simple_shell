# Simple Shell Project

<<<<<<< HEAD
This project develope a **UNIX command line interpreter** base in the _sh_ shell.

## Installation

1. Clone the repository to your local files.
2. Compile using the GNU Compiler gcc, and the flags Wall, Werror, Wextra and -pedantic.

> gcc -Wall -Werror -Wextra -pedantic \*.c -o hsh

## Usage

### Interactive Mode

Execute the shell to start.

> ./hsh

Use the same as _sh_ shell.

#### Example of use

```
$ ./hsh
hsh_shell$ /bin/ls
hsh main.c shell.c
hsh_shell$
```

Error in Interactive Mode

```
$ ./hsh
hsh_shell$ HelloWorld
./hsh: 1: HelloWorld: not found
hsh_shell$
```

### Non-Interactive Mode

#### Example of use

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
```

Error in Non-Interactive Mode

```
$ echo "HelloWorld" | ./hsh
$ ./hsh: 1: HelloWorld: not found
$
```

## Features

### Build-in Commands

- exit
- env

Example of use feature (exit)

```
$ ./hsh
hsh_shell$ exit 98
$ echo $?
98
```

### Features

- End of File (Ctrl+d) : Exit Shell
- Accepts arguments for functions
- Check the Path for executable file

## Development

This project was developed without the use of most standard library functions. The heart of the code is in system calls like write and read, and in the management of memory through allocation and liberation with malloc, free and pointers.

## Authors

- Manuel Puerta Villa
- Miguel Palacios
