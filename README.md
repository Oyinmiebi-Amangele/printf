## Custom Printf Function (_printf)

The custom `_printf` function is a simplified implementation of the standard C library's `printf` function. It allows you to format and print text to the standard output according to a format string.

## Usage

The `_printf` function is used in a similar way to the standard `printf` function. It takes a format string as its first argument, followed by any additional arguments that correspond to the format specifiers in the format string.

### Format Specifiers

The `_printf` function supports the following format specifiers:

- `%c`: Print a single character.
- `%s`: Print a null-terminated string.
- `%d`, `%i`: Print a signed integer.
- `%u`: Print an unsigned integer.
- `%o`: Print an unsigned integer in octal format.
- `%x`, `%X`: Print an unsigned integer in hexadecimal format (lowercase or uppercase).
- `%p`: Print a pointer.
