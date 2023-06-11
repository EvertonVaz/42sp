/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:24:33 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/11 16:28:58 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < ' ' || base[i] > '~')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	is_negative(int base_div, int nbr, char *base)
{
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putnbr_base(-(nbr / base_div), base);
	}
	else
	{
		ft_putchar('-');
		nbr = -nbr;
		ft_putnbr_base(nbr, base);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_div;
	int	test;

	base_div = ft_strlen(base);
	if (!check_base(base))
		return ;
	if (nbr < 0)
	{
		is_negative(base_div, nbr, base);
	}
	if (nbr > 2)
		ft_putnbr_base(nbr / base_div, base);
	if (nbr % base_div < 0)
	{
		test = nbr % base_div * -1;
		ft_putchar(base[test]);
	}
	else
		ft_putchar(base[nbr % base_div]);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("teste do teste, octal\n");
// 	ft_putnbr_base(-2147483648, "ev rton!");
// 	printf("\nteste01, binario\n");
// 	ft_putnbr_base(2147483647, "ab");
// 	printf("\nteste02, octal\n");
// 	ft_putnbr_base(-12345, "poneyvif");
// 	printf("\nteste03, decimal\n");
// 	ft_putnbr_base(-2147483648, "0123456789");
// 	printf("\n");
// 	ft_putnbr_base(2147483647, "abcdefghij");
// 	printf("\nteste04, hexadecimal\n");
// 	ft_putnbr_base(-12345, "0123456789ABCDEF");
// 	return (0);
// }