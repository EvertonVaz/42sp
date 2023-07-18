/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:15:14 by egeraldo          #+#    #+#             */
/*   Updated: 2023/07/18 19:06:40 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ptr;

	ptr = dest;
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	else
	{
		while (n--)
			((unsigned char *)ptr)[n] = ((unsigned char *)src)[n];
		return (dest);
	}
}
