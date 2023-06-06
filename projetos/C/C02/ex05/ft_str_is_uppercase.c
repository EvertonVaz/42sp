/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:44:11 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/04 18:48:17 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// • Escreva uma função que retorne 1 se a string passada 
// como parâmetro só contiver
// caracteres alfabéticos maiúsculos e retorne 0 
// se a função contiver outros tipos de
// caracteres.
// • Ela deverá retornar 1 se str for uma string vazia

int	ft_str_is_uppercase(char *str);

int	ft_str_is_uppercase(char *str)
{
	while (*str)
	{
		if ((*str < 'A' || *str > 'Z'))
			return (0);
		str++;
	}
	return (1);
}
