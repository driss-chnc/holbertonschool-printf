# holbertonschool-printf

This project is a pedagogical reimplementation of the `printf` function in C. The goal is to understand how formatted output works internally (format specifiers handling, variadic arguments, low-level output with `write`) by building a simplified version of `printf` and a set of dedicated handler functions for each conversion type. The work focuses on code structuring (separation into multiple source files, use of a common header) and on respecting project constraints (no libc functions like `printf` or `putchar`, exclusive use of `write`, Betty style, etc.).

## Requirements

- Allowed editors: `vi`, `vim`, `emacs`.
- All files are compiled on Ubuntu 20.04 LTS using `gcc` with the flags:
  `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- All source files must end with a new line.
- A `README.md` file is required at the root of the project.
- The code must follow Betty style and documentation rules.
- No global variables are allowed.
- No more than 5 functions per file.
- The prototypes of all functions must be declared in `main.h`.
- All header files must be protected with include guards.
- Do not push any `main.c` file in the root directory of the project.
- Authorized functions include: `write`, `malloc`, `free`, `va_start`, `va_arg`, `va_end`, and `va_copy`.

## Description

This repository contains an implementation of a minimalist `_printf` (educational project). The source files provide support for several format specifiers (characters, strings, signed integers, unsigned integers, hexadecimal, octal, binary, etc.) and utility functions to write characters.  
The project intentionally does not handle flags (`+`, `#`, `0`, …), field width, precision, or length modifiers, in order to focus on the core mechanism: parsing the format string and dispatching to the appropriate handler functions.

## Compilation

To compile the sources (example):

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o a.out
```

## Files and roles

- `_printf.c`: entry point of the `_printf` function. It parses the format string, detects `%` sequences, and dispatches each specifier to the right handler. This file is usually the most delicate one because a small mistake in index handling or in the way arguments are forwarded can break several format cases at once.
- `_putchar.c`: utility function used to write a single character to standard output. It centralizes the `write` call and keeps the rest of the code simpler. A common pitfall here is forgetting that every handler depends on this function, so any bug in `_putchar` affects all the output.
- `main.c`: test / demo program used to validate the behavior of `_printf`. It is useful for checking edge cases and comparing the custom implementation with the standard `printf`. It should not be pushed in the root directory for the final submission if it contains a `main` function, because the grading system provides its own test file.
- `main.h`: central header file of the project. It contains the prototypes of all functions and the required includes. This file is important because a missing prototype or include can cause compilation errors with strict flags such as `-Werror`.
- `print_binary.c`: handler for the binary specifier (`%b`). It converts an unsigned integer to base 2. One common difficulty is handling `0` correctly and avoiding leading zeros.
- `print_char.c`: handler for the character specifier (`%c`). It retrieves a value from `va_list` and prints a single character. A frequent trap is remembering that the argument is promoted to `int` when passed through variadic arguments, so it must be read with `va_arg(args, int)`.
- `print_hexadecimal_maj.c`: handler for uppercase hexadecimal (`%X`). It prints unsigned values in base 16 using `A-F`. The main difficulty is converting remainders above 9 into letters and printing digits in the correct order.
- `print_hexadecimal.c`: handler for lowercase hexadecimal (`%x`). It behaves like the uppercase version, but uses `a-f`. A common issue is mixing uppercase and lowercase output or forgetting the case conversion rule.
- `print_integer.c`: handler for signed integers (`%d`, `%i`). It must manage negative values, print the sign, and convert the number digit by digit. This file often requires extra care for edge cases such as `0` or very large negative values.
- `print_modulo.c`: handler for `%%`, which prints a literal percent sign. This one is small but important because it does not consume an argument from `va_list`. Forgetting that detail can shift the whole argument list and break later specifiers.
- `print_string.c`: handler for strings (`%s`). It prints each character until the null terminator. A common problem is handling `NULL` safely, since dereferencing it would cause a crash.
- `print_unsigned_octal.c`: handler for unsigned integers in octal (`%o`). It converts values to base 8. The main challenge is the same as for the other base conversions: correct digit extraction and correct output order.
- `print_unsigned.c`: handler for unsigned integers (`%u`). It prints non-negative values without a sign. The tricky part is handling the full unsigned range correctly while keeping the logic consistent with the signed integer version.

## Notes

- Does not include explanations about `a.out` or `main.doc`, as requested.
- This is an educational project: some implementations are intentionally simplified and focused on understanding (variadic functions, format parsing, handler-based design).
- The architecture based on small specialized functions makes the code easier to extend (new specifiers) and to read.

## Usage

- To test: compile and run `./a.out` (or your chosen binary) and inspect the output.
- To extend: add new handler functions (for extra format specifiers), declare them in `main.h`, and connect them inside `_printf.c` where the character after `%` is analyzed.