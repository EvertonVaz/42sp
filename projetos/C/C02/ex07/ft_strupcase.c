/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:58:57 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/05 20:13:18 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// • Escreva uma função que deixe todas as letras em maiúsculo.
// • Ela deverá retornar str.

char	*ft_strupcase(char *str);

char	*ft_strupcase(char *str)
{
	while (*str)
	{
		if (!(*str < 'a' || *str > 'z'))
		{	
			*str = *str - 32;
		}
		str++;
	}
	return (str);
}
