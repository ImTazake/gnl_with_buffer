*This project has been created as part of the 42 curriculum by tisilva.*

# Get Next Line

## Table of Contents

1. [Description](#description)
2. [Instructions](#instructions)
3. [Mandatory Part](#mandatory-part)
4. [Bonus Part](#bonus-part)
5. [Compilation](#compilation)
6. [Testing](#testing)
7. [C Concepts](#c-concepts)
8. [Resources](#resources)

## Description

Get Next Line is a C project focused on file descriptor handling and dynamic memory management.

It implements a function that reads from a file descriptor and returns one line at a time. The implementation uses a static buffer to preserve unread data between function calls.

This project explores concepts such as static variables, buffer management, memory allocation and file input/output.

## Instructions

The project must be compiled using:

- [`-Wall`](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html)
- [`-Wextra`](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html)
- [`-Werror`](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html)

Allowed functions:

- [`read()`](https://man7.org/linux/man-pages/man2/read.2.html)
- [`malloc()`](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [`free()`](https://man7.org/linux/man-pages/man3/free.3.html)

## Mandatory Part

The mandatory part implements `get_next_line()` for reading from a single file descriptor.

The function must:
- Return one line at a time.
- Include the newline character when present.
- Return the remaining content when EOF is reached.
- Return `NULL` when there is nothing left to read or an error occurs.

## Bonus Part

The bonus part extends the mandatory implementation to support multiple file descriptors simultaneously.

Each file descriptor maintains its own independent reading state, allowing lines to be read from different files without losing their positions.

## Compilation

**Mandatory:**

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl
```

**Bonus:**

```bash
cc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
```

## Testing

Run the executable with a file path:

```bash
./gnl file.txt
```

For the bonus:

```bash
./gnl_bonus file1.txt file2.txt file3.txt
```

You can also test different `BUFFER_SIZE` values:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c -o gnl
```

## C Concepts

- [NULL Pointer](https://en.cppreference.com/w/c/types/NULL) — Represents a null pointer, meaning a pointer that does not point to a valid object.
- [EOF (End-of-File)](https://cplusplus.com/reference/cstdio/EOF/) — A macro used by certain input functions to indicate that the end of a file has been reached or an error has occurred.
- [Static Variables](https://en.cppreference.com/w/c/language/static_storage_duration) — Variables that retain their value between function calls.
- [Pointers](https://en.cppreference.com/w/c/language/pointer) — Variables that store memory addresses.
- [Dynamic Memory Allocation](https://en.cppreference.com/w/c/memory) — Concepts related to allocating and freeing memory dynamically.
- [File Descriptors](https://man7.org/linux/man-pages/man2/open.2.html) — Integer identifiers used by the operating system to access open files.

## Resources

- [Linux read manual](https://man7.org/linux/man-pages/man2/read.2.html)
- [Linux malloc manual](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [Linux free manual](https://man7.org/linux/man-pages/man3/free.3.html)
- [GCC Warning Options](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html)
- AI tools were used as support for debugging and identifying potential issues in the code.