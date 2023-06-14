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

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (*str++ != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*temp;

	temp = dest;
	while (*dest)
	{
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
		count += ft_strlen2(strs[i]);
		i++;
	}
	count += ft_strlen2(sep);
	return (count);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		i;

	arr = malloc(alloc_len(strs, sep, size));
	if (size == 0)
		return ((char *)malloc(1));
	i = 0;
	while (i < size)
	{
		ft_strcat(arr, strs[i]);
		if ((i != size - 1))
			ft_strcat(arr, sep);
		i++;
	}
	return (arr);
}

/* #include <stdio.h>

int	main(void)
{
	int index;
	char **strs;
	char *separator;
	char *result;
	int size = 4;
	char *arr;

	strs[0] = "abc";
	strs[1] = "def";
	strs[2] = "ghi";
	strs[3] = "jkl";
	separator = ", ";

	index = 0;
	while (index <= 4)
	{
		result = ft_strjoin(index, strs, separator);
		printf("result with size = %d : $%s$\n", index, result);
		free(result);
		index++;
	}
	return (0);
} */