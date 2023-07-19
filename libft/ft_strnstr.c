/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:50:19 by egeraldo          #+#    #+#             */
/*   Updated: 2023/07/19 12:19:48 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	int		i;
	size_t	len_substr;

	i = 0;
	len_substr = ft_strlen((char *)substr);
	if (*substr == '\0')
		return ((char *)str);
	while (i + len_substr <= len)
	{
		if (ft_strncmp(&str[i], substr, len_substr) == 0)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
