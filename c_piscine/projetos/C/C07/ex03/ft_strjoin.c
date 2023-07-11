/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:01:04 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/14 16:35:38 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++ != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src, int size)
{
	char	*temp;

	temp = dest;
	if (size > 1)
	{
		while (*dest)
			dest++;
	}
	
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (temp);
}

int	alloc_len(char **strs, char *sep, int size)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < size)
	{
		count += ft_strlen(strs[i]);
		if ((i != size - 1))
			count += ft_strlen(sep);
		i++;
	}
	return (count + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		i;

	if (size == 0)
		return ((char *)malloc(1));
	arr = (char *)malloc(alloc_len(strs, sep, size));
	i = 0;
	while (i < size)
	{
		ft_strcat(arr, strs[i], i+1);
		if ((i != size - 1))
			ft_strcat(arr, sep, i+2);
		i++;
	}
	return (arr);
}

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int index;
	char **strs = malloc(10);
	char *separator;
	char *result;
	int	len;

	strs[0] = "abc";
	strs[1] = "def";
	strs[2] = "ghi";
	strs[3] = "jkl";
	separator = " | ";

	index = 0;
	while (index <= 4)
	{
		result = ft_strjoin(index, strs, separator);
		len = ft_strlen(result);
		printf("result with size = %d : $ %s $ and len : %i\n", index, result, len);
		free(result);
		index++;
	}
	return (0);
}