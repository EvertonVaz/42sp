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

int	main(void)
{
	int v[9] = {5,1,10,8,11, 8, 80, 18, 13};
	int i = 0;
	while (i < 9)
	{
		printf("%i, ", v[i]);
		i++;
	}
	printf("\n");
	ft_sort_int_tab(v, 9);
	i = 0;
	while (i < 9)
	{
		printf("%i, ", v[i]);
		i++;
	}

	return (0);
}
