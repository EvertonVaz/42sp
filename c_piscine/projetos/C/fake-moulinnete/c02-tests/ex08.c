/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:50:42 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/06 19:34:52 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strlowcase(char *str);

int	main(void)
{
	char str1[] = "abcdefghi";
	char str2[] = "AbcDefGhI";
	char str3[] = "ABCDEFGHI";

	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	printf("str3: %s\n", str3);
	ft_strlowcase(str1);
	ft_strlowcase(str2);
	ft_strlowcase(str3);
	printf("str1_low: %s\n", str1);
	printf("str2_low: %s\n", str2);
	printf("str3_low: %s\n", str3);

	printf("-- Exercicio 08: ");
	char to_lower0[] = "SAHDUFUASddaAFEAD";
	char to_lower1[] = "adsiEAFEASDFAD0-=+[]asdifAFeajafielIJIHHIJ";

	if (ft_strlowcase(to_lower0) != to_lower0)
		printf("KO, wrong return");
	else if (ft_strlowcase(to_lower1) != to_lower1)
		printf("KO, wrong return");
	else if (strcmp(to_lower0, "sahdufuasddaafead") != 0)
		printf("KO, expected got %s", to_lower0);
	else if (strcmp(to_lower1, "adsieafeasdfad0-=+[]asdifafeajafielijihhij") != 0)
		printf("KO, expected adsieafeasdfad0-=+[]asdifafeajafielijihhij got %s", to_lower1);
	else
		printf("OK");

	printf("\n");

	return (0);
}
