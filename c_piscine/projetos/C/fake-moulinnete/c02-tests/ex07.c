/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:50:42 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/06 19:23:39 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strupcase(char *str);

int	main(void)
{
	char str1[] = "abcdefghi";
	char str2[] = "AbcDefGhI";
	char str3[] = "asdaosOAISDNsaodiasnOSIDAH129683asd11#!@$#(*)#";

	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	printf("str3: %s\n", str3);
	ft_strupcase(str1);
	ft_strupcase(str2);
	ft_strupcase(str3);
	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	printf("str3: %s\n", str3);

	printf("-- Exercicio 07: ");
	char to_upper0[] = "aBbasdsadfSDAFasdf";
	char to_upper1[] = "aice!3$fasdFEDad";


	if (ft_strupcase(to_upper0) != to_upper0)
		printf("KO1, wrong return1");
	else if (ft_strupcase(to_upper1) != to_upper1)
		printf("KO2, wrong return2");
	else if (strcmp(to_upper0, "ABBASDSADFSDAFASDF") != 0)
		printf("KO3, expected ABBASDSADFSDAFASDF got %s", to_upper0);
	else if (strcmp(to_upper1, "AICE!3$FASDFEDAD") != 0)
		printf("KO4, expected AICE!3$FASDFEDAD got %s", to_upper1);
	else
		printf("OK");


	printf("\n");
	return (0);
}
