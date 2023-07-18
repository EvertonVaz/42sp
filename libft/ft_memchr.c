/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:34:38 by egeraldo          #+#    #+#             */
/*   Updated: 2023/07/18 20:50:13 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memchr(const void *str, int chr, size_t n)
{
	int		i;
	char	*ptr;

	ptr = (char *)str;
	i = 0;
	while (i < (int)n)
	{
		if (ptr[i] == chr)
			return ((char *)&ptr[i]);
		i++;
	}
	return (NULL);
}
