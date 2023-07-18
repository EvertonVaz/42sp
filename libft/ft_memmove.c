/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:15:14 by egeraldo          #+#    #+#             */
/*   Updated: 2023/07/18 18:41:35 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ptr;
	int		i;

	ptr = dest;
	i = -1;
	while (++i < (int)n)
		((unsigned char *)ptr)[i] = ((unsigned char *)src)[i];
	return (dest);
}
