/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:59:21 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/04 17:01:29 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// função que retorne 1 se a string passada como parâmetro só contiver números
// e retorne 0 se a função contiver outros tipos de caracteres.
// • Ela deverá retornar 1 se str for uma string vazia.

int	ft_str_is_numeric(char *str);

int	ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if ((*str < '0' || *str > '9'))
			return (0);
		str++;
	}
	return (1);
}
