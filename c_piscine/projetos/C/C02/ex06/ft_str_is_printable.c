/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:48:56 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/04 18:53:23 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// • Escreva uma função que retorne 1 
// se a string passada como parâmetro só contiver
// caracteres imprimíveis e retorne 0 
// se a função contiver outros tipos de caracteres.
// • Ela deverá retornar 1 se str for uma string vazia.

int	ft_str_is_printable(char *str);

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if ((*str < ' ' || *str > '~'))
			return (0);
		str++;
	}
	return (1);
}
