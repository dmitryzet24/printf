*This project has been created as part of the 42 curriculum by dandrush.*

# ft_printf — Because ft_putnbr() and ft_putstr() aren't enough

## Project Description

The main objective of **ft_printf** project is to completely recode the standard `printf` function found in the system C library (`libc`). 

Through this project, a critical mechanism of the C language is mastered: **variadic functions**, which allow functions to accept a dynamic (variable) number of arguments. Code compiles into a static library (`.a`) to serve as a core tool for all subsequent low-level C projects.

## Implementation Features:**
* **No Buffer Management:** The buffer management of the original `printf` is not replicated.
* **Accurate Byte Counting:** The function accurately returns the total number of successfully printed characters (or `-1` if a critical I/O error occurs).

---

## Compilation and Build Instructions

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
```
The -L. flag tells the linker to look for libraries in the current directory, while -lftprintf links the libftprintf.a file.

## Supported Conversion Specifiers
| Specifier | Data Type	| Behavioral Details & System Handling |
|:---|:---|:---|
|%c			|char		|Prints a single character. Due to Type Promotion rules in variadic arguments, it is retrieved via va_arg as an int.|
|%s	    |char * |Prints a string of characters. If a NULL pointer is passed, it outputs (null) safely, preventing segmentation faults.|
|%p	    |void *	|Prints a memory address pointer in hexadecimal format using lowercase characters, prefixed with 0x. Handles a NULL pointer by displaying (nil).|
|%d	    |int	  |Prints a signed decimal number (Base 10). Properly manages extreme boundary values such as INT_MIN.|
|%i	    |int	  |Prints a signed integer in Base 10 (identical to %d output).|
|%u	    |unsigned int	|Prints an unsigned decimal number. Negative bits are interpreted following two's complement rules.|
|%x	    |unsigned int	|Converts and prints numbers in hexadecimal format (Base 16) using lowercase characters (0123456789abcdef).|
|%X	    |unsigned int	|Converts and prints numbers in hexadecimal format (Base 16) using uppercase characters (0123456789ABCDEF).|
|%%	    |None	  |Prints a single literal percent sign character %.|

## Algorithms & Data Structures
1. Architectural Pattern: Flag Dispatching

The project avoids bulky data structures since the mandatory part requires a linear parser. Instead, a Single-pass parsing algorithm is utilized across the format string:

 - The function iterates through the string. Standard characters are instantly passed to the system call write(1, ...).

 - When a % token is encountered, control is transferred to an internal dispatcher function, ft_format(). This matches the character trailing the percent sign against the array of supported specifiers and invokes the corresponding atomic printing sub-function.

2. Number Conversion Mathematics

To convert numbers into decimal and hexadecimal bases, a recursive integer division and modulo algorithm is implemented:

 - The target number is recursively divided by the base (10 or 16) until a single digit remains.

 - During the stack unwinding phase, the remainders are converted into characters using ASCII table offsets (for Base 10: n % 10 + '0', for Base 16: index mapping from a static string matrix like "0123456789abcdef").

 - This mathematical approach eliminates the need to allocate dynamic heap memory via malloc for text buffers, completely ruling out memory leaks and significantly reducing runtime overhead.

3. Preventing Data Type Overflows

To display memory addresses accurately via the %p specifier, the integer type uintptr_t (from <stdint.h>) is chosen. Standard data types like unsigned int or unsigned long can vary between 4 and 8 bytes depending on system architectures, which would cause truncation of a 64-bit pointer address (8 bytes). uintptr_t guarantees perfect parity with the pointer size of the target system architecture.

## Usecase in push_swap

Having a custom libftprintf.a library drastically simplifies debugging and operational logging in subsequent comprehensive projects, such as push_swap.

In push_swap, your application must manage two stacks (a and b) and print exact instructions (sa, pb, ra, rra, etc.). ft_printf optimizes this process in several ways:
  1. Inline Instruction Output with Operation Counters:
   - Instead of writing redundant, multi-line blocks like:
    ```C
      write(1, "pb\n", 3);
      count++;
    ```
  - You can aggregate operation outputs cleanly in one line:
    ```C
    op_count += ft_printf("%s\n", "pb");
    ```
  2. Visualizing Stack State (Debugging):
	When tracking the sorting flow of complex sorting routines (e.g., Radix or the Turk Algorithm), visualizing stack data splits becomes necessary. ft_printf allows you to render a clear terminal debugging interface in a single execution line:

	```C
	ft_printf("Stack A [%i] -> Top: %d | Bottom: %d | Node Ptr: %p\n", index, stack_a->value, stack_a->prev->value, stack_a);
	```
This prevents you from having to daisy-chain distinct ft_putstr and ft_putnbr functions for every minor attribute inside a doubly-linked list node.

## Resources & AI Disclosure
Reference Material and Documentation:

**Canonical Manuals: **Linux Man-pages (man 3 printf, man stdarg). This provided exhaustive details regarding expected behaviors, required return metrics, and edge cases representing undefined behavior.

**The C Standard (ISO/IEC 9899):** Technical documentation covering Type Promotion rules applied whenever handling parameters passed through the ellipsis (...) token into variadic scopes.

## AI Disclosure Statement:

In strict compliance with Chapter III (AI Instructions) of the 42 School project guidelines, the utilization of artificial intelligence code-generation models to produce the functional logic of this software was completely excluded.

**Development Process:** Every line of code from start to finish was designed, architecturalized, and written manually. The core mechanisms of the va_start, va_arg, and va_end macros were studied by examining memory alignment inside the call stack frame. All emerging bugs (such as handling INT_MIN arithmetic signs or the 0x0 address layout) were resolved independently using targeted main test instances and diff-checking outputs against the system printf.
**Verification:** The codebase verified cleanly against the Francinette testing suite (printfTester by Tripouille), delivering full OK markings across all standard types. The code structure is thoroughly understood and ready for peer-to-peer evaluations.
