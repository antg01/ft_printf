
# Custom Printf Function in C

## Project Overview

This project implements a custom version of the `printf` function from the standard C library. Named `ft_printf`, this function replicates the basic functionality of the standard `printf` with support for various format specifiers. The function is designed to provide a way to include formatted output capabilities in projects where the standard library is not available or desired.

## Features

### Format Specifiers

Supports `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p`, and `%%`.
  - `%c` prints a single character.
  - `%s` prints a string.
  - `%d` and `%i` print an integer in decimal.
  - `%u` prints an unsigned decimal integer.
  - `%x` and `%X` print unsigned hexadecimal integers (lowercase and uppercase).
  - `%p` prints a pointer address.
  - `%%` prints a percent sign.

### Variable Argument Lists

Uses `va_list` to manage an indeterminate number of arguments.

### Modular Design

The core functionality is split into several helper functions to manage different data types and formatting tasks, making the code organized and modular.

## Usage

To use this custom `printf` function in your C projects, include the header file `ft_printf.h` and source files. Ensure that all dependent functions such as `ft_putchar`, `ft_putstr`, and various number conversion functions are included in your project.

**Example usage:**
```c
#include "ft_printf.h"

int main() {
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Value: %d\n", 42);
    return 0;
}
```

## Building the Project

This project can be built using the included `Makefile` which simplifies the compilation process. To build the project, simply run the `make` command in your terminal. This will compile all source files and create the `libftprintf.a` library file.

**Example of building with `make`:**
```bash
make
```

To clean up object files, you can use:
```bash
make clean
```

To fully clean the project (removing both object files and the library file), use:
```bash
make fclean
```

To recompile the project (clean and all):
```bash
make re
```

