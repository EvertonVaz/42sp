/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:05:08 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/22 17:46:20 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi_base(char *str, char *base);

int	char_to_int(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i] != '\0')
		if (c == base[i])
			return (i);
	return (-1);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] <= ' ' || base[i] > '~')
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
	return (i);
}

void	pass_whitespace(char *str, int *index, int *signal)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	*index = i;
	*signal = sign;
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	base_size;
	int	digit;
	int	i;

	if ((base_size = check_base(base)) < 2)
		return (0);
	result = 0;
	pass_whitespace(str, &i, &sign);
	while ((digit = char_to_int(str[i], base)) >= 0)
	{
		result = result * base_size + digit;
		i++;
	}
	return (result * sign);
}

#include <stdio.h>

int	main(void)
{
	char str1[] = " ++-+-+-0111";
	char base1[] = "01";
	int result1 = ft_atoi_base(str1, base1);
	printf("Result 1: %d\n", result1);

	char str2[] = "-FF";
	char base2[] = "0123456789ABCDEF";
	int result2 = ft_atoi_base(str2, base2);
	printf("Result 2: %d\n", result2);

	char str3[] = "-12345";
	char base3[] = "0123456789";
	int result3 = ft_atoi_base(str3, base3);
	printf("Result 3: %d\n", result3);

	char str4[] = "-jihga";
	char base4[] = "abcdefghij";
	int result4 = ft_atoi_base(str4, base4);
	printf("Result 3: %d\n", result4);

	return (0);
}