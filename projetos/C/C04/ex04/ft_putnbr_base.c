/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:24:33 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/10 21:22:08 by egeraldo         ###   ########.fr       */
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
		if (base[i] == '-' || base[i] == '+' || base[i] < '!' || base[i] > '~')
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

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;
	int	base_div;

	base_div = ft_strlen(base);
	if (!check_base(base))
		return ;
	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			write(1, "-2", 2);
			nbr = 147483648;
		}
		else
		{
			ft_putchar('-');
			nbr = -nbr;			
		}
	}
	i = 0;
	if (nbr > 1)
		ft_putnbr_base(nbr / base_div, base);
	ft_putchar(nbr % base_div + '0');
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("teste do teste, octal\n");
// 	ft_putnbr_base(-12345, "everton!");
// 	printf("\nteste01, binario\n");
// 	ft_putnbr_base(12345, "01");
// 	printf("\nteste02, octal\n");
// 	ft_putnbr_base(-12345, "poneyvif");
// 	printf("\nteste03, decimal\n");
// 	ft_putnbr_base(12345, "0123456789");
// 	printf("\nteste04, hexadecimal\n");
// 	ft_putnbr_base(-12345, "0123456789ABCDEF");
// 	return (0);
// }