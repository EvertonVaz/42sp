/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:41:45 by egeraldo          #+#    #+#             */
/*   Updated: 2023/07/19 18:46:35 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	n;

	n = ft_strlen((char *)s);
	while (n >= 0 && s[n] != (char)c)	
		n--;
	if (s[n] == (char)c)
		return ((char *)&s[n]);
	return (0);
}
