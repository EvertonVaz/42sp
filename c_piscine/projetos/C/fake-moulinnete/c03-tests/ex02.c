/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:14:17 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/06 21:26:23 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char *src;
	char *dest;
	char *ft_src;
	char *ft_dest;
	char *result;
	char *ft_result;
	char str0[] = "string";
	char str1[] = "string1";

	src = calloc(7, sizeof(char));
	dest = calloc(12, sizeof(char));
	ft_src = calloc(7, sizeof(char));
	ft_dest = calloc(12, sizeof(char));
	strcpy(src, "galera");
	strcpy(dest, "alo ");
	strcpy(ft_src, "galera");
	strcpy(ft_dest, "alo ");
	result = strcat(dest, src);
	ft_result = ft_strcat(ft_dest, ft_src);
	if (ft_dest != ft_result)
		printf("KO, return value of ft_strcar is different of ft_dest. ft_strcar=%p ft_dest=%p\n", ft_result, ft_dest);
	else if (strcmp(result, ft_result) != 0)
		printf("KO, value returned from strcmp with ft_strcat and strcat is different of zero(%d).\n", strcmp(result, ft_result));
	else
		printf("OK.\nresult: %s\n", ft_result);
	
	printf("-- Exercício 02: ");
	char buffer0[100];
	char buffer1[100];

	int i = 0;
	while (i < 100)
	{
		buffer0[i] = 'a';
		buffer1[i] = 'a';
		++i;
	}


	strcpy(buffer0, str1);
	strcpy(buffer1, str1);

	if (strcat(buffer1, str0), buffer0 != ft_strcat(buffer0, str0))
		printf("KO, test00 wrong return\n");
	else if (strcmp(buffer0, buffer1) != 0)
		printf("KO, test00 expected %s got %s\n", buffer1, buffer0);
	else if (strcat(buffer1, "ba ba ta ta"), buffer0 != ft_strcat(buffer0,  "ba ba ta ta"))
		printf("KO, test00 wrong return\n");
	else if (strcmp(buffer0, buffer1) != 0)
		printf("KO, test00 expected %s got %s\n", buffer1, buffer0);
	else
		printf("OK\n");

	return (0);
}
