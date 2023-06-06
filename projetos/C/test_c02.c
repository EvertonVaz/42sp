#include "C00/ex00/ft_putchar.c"
#include "C01/ex06/ft_strlen.c"
#include "C02/ex00/ft_strcpy.c"
#include "C02/ex01/ft_strncpy.c"
#include "C02/ex02/ft_str_is_alpha.c"
#include "C02/ex03/ft_str_is_numeric.c"
#include "C02/ex04/ft_str_is_lowercase.c"
#include "C02/ex05/ft_str_is_uppercase.c"
#include "C02/ex06/ft_str_is_printable.c"
#include "C02/ex07/ft_strupcase.c"
#include "C02/ex08/ft_strlowcase.c"
#include "C02/ex09/ft_strcapitalize.c"
#include "C02/ex10/ft_strlcpy.c"
#include "C02/ex11/ft_putstr_non_printable.c"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	main(void)
{
	char src[] = "oi, tudo bem? 42palavras quarenta-e-duas; cinquenta+e+um\n";
	char test_isalpha1[] = "Abc";
	char test_isalpha2[] = "Abc123";
	char test_isnumeric1[] = "0123456789";
	char test_isnumeric2[] = "0123456789abC";
	char test_strcpy[100];
	char dest[strlen(src)];
	char *test_no_print = "Oi\nvoce esta bem? \v, \f";
	int t;

	ft_strcpy(test_strcpy, src);
	printf("EX00 - %s\n", test_strcpy);

	ft_strncpy(test_strcpy, src, 25);
	printf("EX01 - %s\n\n", test_strcpy);

	printf("EX02 - retorno 1 -> %d\n", ft_str_is_alpha(test_isalpha1));
	printf("EX02 - retorno 0 -> %d\n\n", ft_str_is_alpha(test_isalpha2));

	printf("EX03 - retorno 1 -> %d\n", ft_str_is_numeric(test_isnumeric1));
	printf("EX03 - retorno 0 -> %d\n\n", ft_str_is_numeric(test_isnumeric2));

	printf("EX04 - retorno 0 -> %d - %s\n", ft_str_is_lowercase(test_isalpha1), test_isalpha1);
	ft_strlowcase(test_isalpha1); // TESTE DO EX08
	printf("EX04 - retorno 1 -> %d - %s,  e EX08\n\n", ft_str_is_lowercase(test_isalpha1), test_isalpha1);

	printf("EX05 - retorno 0 -> %d - %s\n", ft_str_is_uppercase(test_isalpha1), test_isalpha1);
	ft_strupcase(test_isalpha1); // TESTE DO EX07
	printf("EX05 - retorno 1 -> %d - %s,  e EX07\n\n", ft_str_is_uppercase(test_isalpha1), test_isalpha1);

	printf("EX06 - retorno 0 -> %d\n", ft_str_is_printable(src));
	printf("EX06 - retorno 1 -> %d\n\n", ft_str_is_printable(test_isnumeric2));

	ft_strcapitalize(src);
	printf("EX09 - %s\n", src);

	t = ft_strlcpy(dest, src, 10);
	printf("EX10 - %i - %s\n\n", t, dest);

	printf("EX11: \n");

	ft_putstr_non_printable(test_no_print);
	printf("\n");
}
