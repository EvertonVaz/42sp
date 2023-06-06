/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:05:08 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/04 18:43:12 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// função que retorne 1 se o parametro so conter letras minusculas
// e retorne 0 se a função contiver outros tipos de caracteres
// Ela deverá retornar 1 se str for uma string vazia.

int	ft_str_is_lowercase(char *str);

int	ft_str_is_lowercase(char *str)
{
	while (*str)
	{
		if ((*str < 'a' || *str > 'z'))
			return (0);
		str++;
	}
	return (1);
}
