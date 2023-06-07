/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:04:08 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/06 21:13:41 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// • Reproduzir de forma idêntica o funcionamento da função strlcpy
// (man strlcpy).

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size);

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	strlen;
	unsigned int	i;

	strlen = 0;
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (*dest)
	{
		strlen++;
		dest++;
	}
	return (strlen);
}
