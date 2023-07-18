/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:34:45 by egeraldo          #+#    #+#             */
/*   Updated: 2023/07/18 19:21:51 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ptr;
	int		i;

	ptr = dest;
	i = -1;
	while (++i < (int)n)
		((unsigned char *)ptr)[i] = ((unsigned char *)src)[i];
	return (dest);
}
