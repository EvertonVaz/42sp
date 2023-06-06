/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:03:56 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/05 20:44:52 by egeraldo         ###   ########.fr       */
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

//hex = "0123456789abcdef";
void	ft_putstr_non_printable(char *str)
{
	char	hex_str[3];

	while (*str)
	{
		if (*str < 32 || *str == 127)
		{
			hex_str[0] = '\\';
			hex_str[1] = '0' + ((*str / 16) % 16);
			if (hex_str[1] > '9')
				hex_str[1] += 'a' - '9' - 1;
			hex_str[2] = '0' + (*str % 16);
			if (hex_str[2] > '9')
				hex_str[2] += 'a' - '9' - 1;
			write(1, hex_str, 3);
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
}
