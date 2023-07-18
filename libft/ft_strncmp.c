/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:16:56 by egeraldo          #+#    #+#             */
/*   Updated: 2023/07/18 20:24:51 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;
	
	i = 0;
	while (*s1 && s1[i] == s2[i] && i < (int)n)
		i++;
	return ((unsigned char *)s1 - (unsigned char *)s2);
}