# _printf

A formatted output conversion C program completed as part of the low-level programming and algorithm track at ALX/Holberton School. The program is a pseudo- recreation of the C standard library function, ```printf```.

**Prototype:** ```int _printf(const char *, ...);```

## Dependencies

The `_printf` function was coded on an Ubuntu 20.04.1 LTS machine with `gcc` version 9.4.0.

## Usage

To use the `_printf` function, assuming the above dependencies have been installed,
compile all `.c` files in the repository and include the header `main.h` with
a main function.

Example `main.c`:

```c
#include "main.h"
int main(void)
{
    _printf("Hello, %s!\n", "world");
    return (0);
}
```

Compilation:

```bash
$ gcc *.c -o printf
$
```

Output:

```bash
$ ./tester
Hello, World!
$
```

## Description

The function `_printf` writes a formatted string to standard output.
The function interpolates variable arguments (accessed via the variable-length argument facilities of `stdarg`)
into the format string at the location of a corresponding conversion specifier.

Prototype: `int _printf(const char *format, ...);`

### Return Value

Upon successful return, `_printf` returns the number of characters printed
(excluding the terminating null byte used to end output to strings). If an
output error is encountered, the function returns `-1`.

### Format of the Argument String

The `format` string argument is a constant character string composed of zero
or more directives: ordinary characters (not `%`) which are copied unchanged
to the output stream; and conversion specifications, each of which results in
fetching zero or more subsequent arguments. Conversion specification is
introduced by the character `%` and ends with a conversion specifier. In
between the `%` character and conversion specifier, there may be (in order)
zero or more _flags_, an optional minimum _field width_, an optional
_precision_ and an optional _length_ modifier. The arguments must correspond
with the conversion specifier, and are used in the order given.

## Examples

**String**

* Input: ```_printf("%s\n", 'This is a string.');```
* Output: ```This is a string.```
**Character**
* Input: ```_printf("The first letter in the alphabet is %c\n", 'A');```
* Output: ```The first letter in the alphabet is A```
**Integer**
* Input: ```_printf("There are %i dozens in a gross\n", 12);```
* Output: ```There are 12 dozens in a gross```
**Decimal:**
* Input: ```_printf("%d\n", 1000);```
* Output:  ```1000```

## Project Requirements

* All files will be compiled on Ubuntu 14.04 LTS
* Programs and functions will be compiled with gcc 4.8.4 using flags -Wall -Werror -Wextra and -pedantic
* Code must follow the [Betty](https://github.com/holbertonschool/Betty/wiki) style
* Global variables are not allowed
* Authorized functions and macros:
  * ```write``` (man 2 write)
  * ```malloc``` (man 3 malloc)
  * ```free``` (man 3 free)
  * ```va_start``` (man 3 va_start)
  * ```va_end``` (man 3 va_end)
  * ```va_copy``` (man 3 va_copy)
  * ```va_arg``` (man 3 va_arg)

## Mandatory Tasks

* [x] Write function that produces output with conversion specifiers ```c```, ```s```, and ```%```.

* [x] Handle conversion specifiers ```d```, ```i```.

## Advanced Tasks

* [x] Handle conversion specifier ```b```.

* [x] Handle conversion specifiers ```u```, ```o```, ```x```, ```X```.
* [x] Use a local buffer of 1024 chars in order to call write as little as possible.
* [ ] Handle conversion specifier ```S```.
* [x] Handle conversion specifier ```p```.
* [ ] Handle flag characters ```+```, space, and ```#``` for non-custom conversion specifiers.
* [ ] Handle length modifiers ```l``` and ```h``` for non-custom conversion specifiers.
* [ ] Handle the field width for non-custom conversion specifiers.
* [ ] Handle the precision for non-custom conversion specifiers.
* [ ] Handle the ```0``` flag character for non-custom conversion specifiers.
* [ ] Handle the custom conversion specifier ```r``` that prints the reversed string.
* [ ] Handle the custom conversion specifier ```R``` that prints the rot13'ed string.
* [ ] All above options should work well together.

## File Descriptions

* **_printf.c:** - defines the  function ```_printf```, which uses the prototype ```int_printf(const char *format, ...);```. The format string is composed of zero or more directives. See ```man 3 printf``` for more details. **_printf** will return the number of characters printed (excluding the null byte used to end output to strings) and will write the output to **stdout**, the standard output stream.
* **main.h:** - contains all function prototypes, macros, and structs used for ```_printf```.
* **handlers.c:** - contains the function ```specifier_handler``` which maps conversion specifiers to a corresponding callback function, and executes
the function that matches the provided specifier.
* **char_converters.c:** - handles all char/string convertions and contains the functions ```convert_str```, and ```convert_char```, which handle the conversion specifiers ```s``` and ```c```, respectively.
* **base_converters.c:** - handles all base conversions and contains the functions ```convert_bin```, ```convert_oct```, ```convert_hex``` and, ```convert_hexa```, which handle the conversion specifiers ```b```, ```o```, ```x```, and ```X```, respectively.
* **int_converters.c:** - handles all integer conversions and contains the functions ```convert_int```, ```convert_uint```, and ```convert_addr```, which handle the conversion specifiers ```i```, ```u```, and ```p```, respectively.
* **misc_converters.c** - handles all miscelleneous convertions and contains the function ```convert_percent```, which handles the conversion specifier ```%```.

## Acknowledgements :pray:

The `_printf` function emulates functionality of the C standard library
function `printf`.

This program was written as part of the curriculum for ALX/Holberton School.
ALX is a remote full-stack software engineering program
that prepares students for careers in the tech industry using project-based
peer learning. For more information, visit [this link](https://www.alxafrica.com/).

## Authors

[Ifedayo Ijabadeniyi](https://github.com/Adeniyii)
[Odusanya Ibukun](https://github.com/Ibkodus116)
