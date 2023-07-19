/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:57:31 by egeraldo          #+#    #+#             */
/*   Updated: 2023/07/19 11:03:12 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int chr)
{
	while (*str)
	{
		if (*str == chr)
			return ((char *)str);
		str++;
	}
	return (0);
}
