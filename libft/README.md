*This project has been created as part of the 42 curriculum by dandrush.*

# Libft
## Description

Libft is the first project of the 42 core curriculum. The goal is to create a personal library of standard C functions. During this project, I re-implemented functions from standard libraries such as <ctype.h>, <string.h>, and <stdlib.h>, as well as additional utility functions for string manipulation, memory management, file descriptor output and linked lists manipulation. These functions serve as the foundation for all future C projects in the curriculum.

The project focuses on understanding the internal mechanics of basic C tools, learning dynamic memory management, and adhering to strict coding standards (The Norm).

## Instructions
### Compilation

The library is compiled using a Makefile. All source files are compiled with the -Wall -Wextra -Werror flags.

- **make:** Compiles the mandatory functions and creates the libft.a library file.

- **make clean:** Removes all object files (.o).

- **make fclean:** Removes object files and the compiled library file (libft.a).

- **make re:** Recompiles the entire project from scratch.

### Usage

To use this library in your own project, include the header file:

```C
#include "libft.h"
```

When compiling your project, link the library by providing the path and the linker flag:
Bash

```bash
cc main.c -L. -lft**
```

## Library Description

The created library libft.a includes the following groups of functions:

- Character Checks (Libc): ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint.

- Character/String Conversion (Libc): ft_toupper, ft_tolower, ft_atoi, ft_itoa.

- Memory Manipulation (Libc): ft_memset, ft_bzero, ft_memcpy, ft_memmove, ft_memchr, ft_memcmp, ft_calloc.

- String Operations (Libc): ft_strlen, ft_strlcpy, ft_strlcat, ft_strchr, ft_strrchr, ft_strncmp, ft_strnstr, ft_strdup.

- ft_substr, ft_strjoin, ft_strtrim — Creating and trimming strings.

- ft_split — Splitting a string into an array of strings based on a delimiter.

- ft_strmapi, ft_striteri — Applying functions to each character of a string.

- ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd — Outputting data to a specific file descriptor.

- ft_lstnew, ft_lstadd_front, ft_lstsize, ft_lstlast, ft_lstadd_back, ft_lstdelone, ft_lstclear, ft_lstiter, ft_lstmap - Linked lists manipulation.


## Resources

- **Man pages** — Official documentation for standard C functions.

- [C Library Reference](https://www.tutorialspoint.com/c_standard_library/index.htm "Practical examples of library functions")

- [Article about File Descriptors](https://medium.com/@tharinduimalka915/linux-file-descriptors-ec945fd36893)

- [Article about Linked Lists](https://www.geeksforgeeks.org/c/linked-list-in-c/)

## AI Usage Disclosure

Artificial Intelligence (LLM) was utilized in this project for the following tasks:

- **Debugging and Testing**: Analysis of tester logs (Francinette, libft-war-machine) to identify edge cases in complex functions like ft_atoi and ft_split.

- **Documentation**: Assistance in structuring this README.md file to comply with the specific requirements of the 42 curriculum.

- **Makefile Optimization**: Guidance on setting up correct dependencies and rules for the library compilation process.

- **Concept explanation**: Since IA chats are good at gathering and structuring text data. NOTE: Gemini was horrible explaning file descriptoprs. Don trust him there.