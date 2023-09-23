# simple shell

## Description
This is a simple shell that execute commands and builtins similiar to the sh shell.


## Compilation
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
## Usage
```
./hsh
```
## Commands
### The shell excecute the command in the PATH variable and following buildin command:
```
$ env
$ exit
$ cd
```


## Testing
### interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
### non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Our Team
- [Amira Walid](https://github.com/AmiraWalid1)
- [Nourhan Wael](https://github.com/Nourhan-Wael)
