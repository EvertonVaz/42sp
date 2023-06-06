#include "C00/ex00/ft_putchar.c"
#include "C01/ex00/ft_ft.c"
#include "C01/ex01/ft_ultimate_ft.c"
#include "C01/ex02/ft_swap.c"
#include "C01/ex03/ft_div_mod.c"
#include "C01/ex04/ft_ultimate_div_mod.c"
#include "C01/ex05/ft_putstr.c"
#include "C01/ex06/ft_strlen.c"
#include "C01/ex07/ft_rev_int_tab.c"
#include "C01/ex08/ft_sort_int_tab.c"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int a = 5;
	int b = 2;
	int i = 0;
	int div;
	int mod;
	int tab[] = {89, 5, 3, 10, 18, 12, 5};

	ft_ft(&b);
	printf("q0 - %d\n", a);
	ft_swap(&a, &b);
	printf("q2 - a = %d, b = %d\n", a, b);
	ft_div_mod(a, b, &div, &mod);
	printf("q3 - a = %d, b = %d, div = %d, mod = %d\n", a, b, div, mod);
	ft_ultimate_div_mod(&a, &b);
	printf("q4 - a = %d, b = %d\n", a, b);
	
	ft_putstr("q5 - everton\n");
	printf("q6 - %d\n", ft_strlen("everton"));
	ft_rev_int_tab(tab, 7);
	printf("q7 - ");
	while (i < 7)
	{
		printf("%d, ", tab[i]);
		i++;
	}
	i = 0;
	printf("\nq8 - ");
	ft_sort_int_tab(tab, 7);
	while (i < 7)
	{
		printf("%d, ", tab[i]);
		i++;
	}
}

