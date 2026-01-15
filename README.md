*This project has been created as part of the 42 curriculum by ryatan*

---

# get_next_line

---

## Project Description

This aim of this project is the create a function; get_next_line(). This function returns a line from a file specified for each call. 

The prototype of the function is as follows: 

```c
char *get_next_line(int fd)
```
Stateful processing is achieved in this project by using a static variable to preserve the state between calls.

#### helper functions

```c
char    *ft_read_line(int fd, char **storage
```

```c
void    ft_append_storage(char *data, char **storage)
```

```c
void    *ft_scan_storage(char match, char **storage)
```

```c
void    ft_remove_from_strorage(char **storage)
```
---

## Instruction
Compile the program into an executable:
```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o gnl
```
and run
```bash
./gnl
```
You could also use

---
## Resources
---
