/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:41:45 by egeraldo          #+#    #+#             */
/*   Updated: 2023/07/18 19:47:33 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	int	n;

	n = ft_strlen(str);
	while (str[n])
	{
		if (str[n] == chr)
			return (((char *)str)[n]);
		n--;
	}
	return (NULL);
}