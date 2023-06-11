/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:43:15 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/10 20:54:54 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	mult;
	int	nb;

	i = 0;
	mult = 1;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			mult = -mult;
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb * 10 + (str[i] - '0');
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A'
				&& str[i] <= 'Z'))
			break ;
		i++;
	}
	nb *= mult;
	return (nb);
}

// #include <stdio.h>
// #include <stdlib.h>

// int        main(void)
// {
//     char    *str;

//     str = "    \v   \n   +-+-++-8415a64546";
//     char str2[] = "   ---+--+1234ab567";
//     // str2 = "-1234ab567";
//     printf("%d\n", ft_atoi(str));
//     printf("%d\n", ft_atoi(str2));
// }