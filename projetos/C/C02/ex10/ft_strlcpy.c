/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:04:08 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/05 20:37:27 by egeraldo         ###   ########.fr       */
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
	while (src[i] != '\0')
	{
		strlen++;
		i++;
	}
	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (strlen);
}
