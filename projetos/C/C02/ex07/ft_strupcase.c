/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:58:57 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/06 19:32:51 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// • Escreva uma função que deixe todas as letras em maiúsculo.
// • Ela deverá retornar str.

char	*ft_strupcase(char *str);

char	*ft_strupcase(char *str)
{
	char	*temp;
	
	temp = str;
	while (*temp)
	{
		if ((*temp >= 'a' && *temp <= 'z'))
			*temp -= 32;
		temp++;
	}
	return (str);
}
