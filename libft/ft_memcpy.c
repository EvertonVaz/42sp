/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:34:45 by egeraldo          #+#    #+#             */
/*   Updated: 2023/07/20 14:48:08 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = dest;
	i = -1;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (++i < n)
		((unsigned char *)ptr)[i] = ((unsigned char *)src)[i];
	return (dest);
}
