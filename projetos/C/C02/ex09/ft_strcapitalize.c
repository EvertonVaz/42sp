/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:00:29 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/05 21:00:33 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// • Escreva uma função que deixe a primeira letra 
// de cada palavra em maiúsculo e o
// resto da palavra em minúsculo.
// • Uma palavra é uma sequência de caracteres alfanuméricos.
// • Ela deverá retornar str.
// • Por exemplo:
// oi, tudo bem? 42palavras quarenta-e-duas; cinquenta+e+um
// • Deve resultar:
// Oi, Tudo Bem? 42palavras Quarenta-E-Duas; Cinquenta+E+Um

char	*ft_strcapitalize(char *str);

char	*ft_strcapitalize(char *str)
{
	int		next;
	char	c;

	next = 1;
	while (*str)
	{
		c = *str;
		if (next == 1 && *str >= 'a' && *str <= 'z')
			*str -= 32;
		else if (next == 0 && *str >= 'A' && *str <= 'Z')
			*str += 32;
		if ((c < 48 || c > 57) && (c < 'A' || c > 'Z') && (c < 'a' || c > 'z'))
			next = 1;
		else
			next = 0;
		str++;
	}
	return (str);
}
