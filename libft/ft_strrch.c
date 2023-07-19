/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:41:45 by egeraldo          #+#    #+#             */
/*   Updated: 2023/07/19 11:03:15 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	int	n;

	n = ft_strlen((char *)str);
	while (n >= 0)
	{
		if (str[n] == chr)
			return ((char *)&str[n]);
		n--;
	}
	return (0);
}
