/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:21:30 by egeraldo          #+#    #+#             */
/*   Updated: 2023/07/19 17:44:18 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;
	size_t	total_size;
	
	total_size = nmemb * size;
	if (!total_size)
		return (malloc(0));	
	if (total_size >= __INT_MAX__ || total_size / nmemb != size)
		return (NULL);
	alloc = malloc(nmemb * size);
	if (!alloc)
		ft_bzero(alloc, nmemb);
	return (alloc);
}
