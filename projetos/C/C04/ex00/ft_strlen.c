/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asd                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:32:32 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/08 17:33:35 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Escreva uma função que contenha o número de caracteres em uma cadeia de
// caracteres e que retorne o número encontrado.

int	ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0' && str++)
	{
		i++;
	}
	return (i);
}
