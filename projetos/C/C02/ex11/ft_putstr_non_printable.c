/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:03:56 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/06 21:13:53 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Escreva uma função que mostre uma string de caracteres na tela. 
// Se essa string contiver caracteres não imprimíveis,
//	eles devem ser mostrados na forma hexadecimal
// (em minúsculo) precedidos por um "backslash".
// • Por exemplo, com este parâmetro:
// Oi\nvoce esta bem?// 
// • A função deverá mostrar:
// Oi\0avoce esta bem?

#include <unistd.h>

void	ft_putstr_non_printable(char *str);

void	ft_putstr_non_printable(char *str)
{
	char	hex_str[3];
	char	*hex_table;

	hex_table = "0123456789abcdef";
	while (*str)
	{
		if (*str < 32 || *str == 127)
		{
			hex_str[0] = '\\';
			hex_str[1] = hex_table[((*str / 16) % 16)];
			hex_str[2] = hex_table[(*str % 16)];
			write(1, hex_str, 3);
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
}
