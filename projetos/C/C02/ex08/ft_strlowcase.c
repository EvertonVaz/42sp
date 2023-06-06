/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:09:30 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/06 19:33:40 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// • Escreva uma função que deixe todas as letras em minúsculo.
// • Ela deverá ser prototipada da seguinte maneira:
// • Ela deverá retornar str.

char	*ft_strlowcase(char *str);

char	*ft_strlowcase(char *str)
{
	char	*temp;
	
	temp = str;
	while (*temp)
	{
		if ((*temp >= 'A' && *temp <= 'Z'))
		{	
			*temp += 32;
		}
		temp++;
	}
	return (str);
}
