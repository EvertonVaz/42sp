/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex09.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 22:53:06 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/06 19:37:42 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcapitalize(char *str);

int	main(void)
{
	char str1[] = "alo maluco 42beleza!";
	char str2[] = "ALO MALUCO 42BELEZA!";
	char str3[] = "alo+ma|uco a2beleza!";
	char str4[] = "ALO+MALUCO*a2BELEZA!";
	char str5[] = "^uIv#= =9Hf~2y@F3A)FTzBgF";
	char str6[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	printf("str1: %s\n", str1);
	ft_strcapitalize(str1);
	printf("str1_c: %s\n", str1);
	printf("str2: %s\n", str2);
	ft_strcapitalize(str2);
	printf("str2_c: %s\n", str2);
	printf("str3: %s\n", str3);
	ft_strcapitalize(str3);
	printf("str3_c: %s\n", str3);
	printf("str4: %s\n", str4);
	ft_strcapitalize(str4);
	printf("str4_c: %s\n", str4);
	printf("str5: %s\n", str5);
	ft_strcapitalize(str5);
	printf("str5_c: %s\n", str5);
	printf("str6: %s\n", str6);
	ft_strcapitalize(str6);
	printf("str6_c: %s\n", str6);

	printf("-- Exercicio 09: ");
	char cap0[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char cap1[] = "voT{r^+t,^~,@ f>lC9h.sn99";

	if (ft_strcapitalize(cap0) != cap0)
		printf("KO, wrong return");
	else if (strcmp(cap0, "Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un") != 0)
		printf("KO, expected Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un got %s", cap0);
	if (ft_strcapitalize(cap1) != cap1)
		printf("KO, wrong return");
	else if (strcmp(cap1, "Vot{R^+T,^~,@ F>Lc9h.Sn99") != 0)
		printf("KO, expected Vot{R^+T,^~,@ F>Lc9h.Sn99 got %s", cap1);
	else
		printf("OK");

	printf("\n");
	return (0);
}
