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
char    *ft_read_line(int fd, char **storage)
```
Reads a line from the text file and stores it into the static variable "storage".

```c
void    ft_append_storage(char *data, char **storage)
```
Adds the scanned line into the storage.

```c
void    *ft_scan_storage(char match, char **storage)
```
Scans the storage after adding to scan for a newline character or terminating character.

```c
void    ft_remove_from_strorage(char **storage)
```

Remove from storage if a newline or terminating character is detected.

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

#### Testing file

```c
#include "get_next_line.h"

int main(void)
{
    return (0);
}
```

```c
#include "get_next_line.h"

int main(int argc, char **argv)
{
    return (0);
}
```
---
## Resources
---
