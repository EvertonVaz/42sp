/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:21:30 by egeraldo          #+#    #+#             */
/*   Updated: 2023/07/19 12:31:13 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*calloc(size_t length, size_t size_type)
{
	void	*alloc;
	
	alloc = malloc(length * size_type);
	ft_bzero(alloc, length);
	return (alloc);
}