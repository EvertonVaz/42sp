#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"

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

void	print_char(char arg)
{
	write(1, &arg, 1);
}

void	print_str(char *arg)
{
	write(1, arg, ft_strlen(arg));
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
				args = va_arg(arg, char);
				print_int(args);
			}
			else if (*(format + 1) == 's')
			{
				args = va_arg(arg, char);
				print_int(args);
			}
			format += 2;
		}
		ft_putchar_fd(*format++, 1);
	}
	va_end(arg);
}

int main()
{
	test("n1 = %i, n2 = %c, n4 = %s, n3 = %i", 42, '2', "ola mundo", 3);
}