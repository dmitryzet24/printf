*This project has been created as part of the 42 curriculum by dandrush.*

# ft_printf — Because ft_putnbr() and ft_putstr() aren't enough

## 📝 Project Description

The main objective of **ft_printf** project is to completely recode the standard `printf` function found in the system C library (`libc`). 

Through this project, a critical mechanism of the C language is mastered: **variadic functions**, which allow functions to accept a dynamic (variable) number of arguments. Code compiles into a static library (`.a`) to serve as a core tool for all subsequent low-level C projects.

### Implementation Features:
* **No Buffer Management:** The buffer management of the original `printf` is not replicated.
* **Accurate Byte Counting:** The function accurately returns the total number of successfully printed characters (or `-1` if a critical I/O error occurs).

---

## ⚙️ Compilation and Build Instructions

`Makefile`: Source files are compiled using `cc` along with the mandatory strict error-handling flags: `-Wall -Wextra -Werror`.

### Available Commands:

| Command | Action |
| :--- | :--- |
| `make` / `make all` | Compiles the source C files and generates the static library `libftprintf.a` in the root directory. |
| `make clean` | Removes all temporary object files (`.o`), leaving the repository clean. |
| `make fclean` | Completely wipes the repository, removing both object files (`.o`) and the compiled `libftprintf.a` archive. |
| `make re` | Sequentially executes `fclean` and `all`, forcing a full re-compilation of the entire project from scratch. |
### Linking the Library to Your Projects:
To use `ft_printf` in your own programs, compile your source files together with the library archive like this:
```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o my_program
The -L. flag tells the linker to look for libraries in the current directory, while -lftprintf links the libftprintf.a file.

🛠️ Supported Conversion Specifiers
| Specifier | Data Type	| Behavioral Details & System Handling |
|:----------|:----------|:-------------------------------------|
|%c			|char		|Prints a single character. Due to Type Promotion rules in variadic arguments, it is retrieved via va_arg as an int.|


