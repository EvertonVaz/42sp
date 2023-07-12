/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:45:34 by egeraldo          #+#    #+#             */
/*   Updated: 2023/07/10 20:55:49 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src);

char	*ft_strdup(char *src)
{
	int		len;
	char	*new_str;

	len = 0;
	while (src[len] != '\0')
		len++;
	new_str = (char *)malloc(sizeof(char) * len + 1);
	if (new_str == NULL)
		return (NULL);
	len = -1;
	while (src[++len] != '\0')
		new_str[len] = src[len];
	new_str[len] = '\0';
	return (new_str);
}
