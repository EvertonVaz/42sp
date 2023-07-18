/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:34:45 by egeraldo          #+#    #+#             */
/*   Updated: 2023/07/18 18:30:46 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
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
