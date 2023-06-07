/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:54:13 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/06 22:09:01 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Reproduzir de forma idêntica o funcionamento da função strlcat (man strlcat).
// • Ela deverá ser prototipada da seguinte maneira:

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	dest_len;
	int	src_len;
	int	total_len;
	int	i;

	while (dest[dest_len] != '\0' && dest_len < size)
	{
		dest_len++;
	}
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	total_len = dest_len + src_len;
	if (dest_len >= size)
		return (total_len);
	while (src[i] != '\0' && dest_len + 1 < size)
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dest[dest_len] = '\0';
	return (total_len);
}
