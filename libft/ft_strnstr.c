/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:50:19 by egeraldo          #+#    #+#             */
/*   Updated: 2023/07/21 16:20:07 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	len_substr;

	i = 0;
	len_substr = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	while (*big && len_substr <= len--)
	{
		if (ft_strncmp(big, little, len_substr) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
