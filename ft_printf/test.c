#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"

// cspdiuxX% -> Formatos do mandatorio
// Valid format specifiers are:
//    • %c: A character OK
//    • %s: A string OK
//    • %p: A pointer address
//    • %d: Argument will be used as decimal integer (signed or unsigned)
//    • %i: Argument will be used as a signed integer
//    • %u: An unsigned decimal integer
//    • %x or %X: An unsigned hexadecimal integer
//    • %o: An octal unsigned integer
//    • %f, %g or %G: A floating-point number
//    • %e or %E: A floating-point number in scientific (XXXeYY) notation
//    • %b: As a string, interpreting backslash escapes,  except  that  octal
//      	escapes are of the form 0 or 0ooo.
//    %% signifies a literal "%".


int	count_args(char *format)
{
	int count = 0;
	while(*format)
		if(*format++ == '%')
			count++;
	return (count);
}


void	print_int(int arg)
{
	char *test;
	test = ft_itoa(arg);
	write(1, test, ft_strlen(test));
}

void test(char *format, ...)
{
	int count = 0;
	va_list arg;
	int args;

	count = count_args(format);
	va_start(arg, count);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == 'i')
			{
				args = va_arg(arg, int);
				print_int(args);
			}
			else if (*(format + 1) == 'c')
			{
				args = va_arg(arg, int);
				ft_putchar_fd((char)args, 1);
			}
			else if (*(format + 1) == 's')
			{
				args = va_arg(arg, int);
				ft_putstr_fd((char *)args, 1);
			}
			format += 2;
		}
		ft_putchar_fd(*format++, 1);
	}
	va_end(arg);
}

int main()
{
	test("n1 = %i, n2 = %c, n3 = %s\n", 42, '2', "ola mundo");
}