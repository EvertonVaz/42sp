/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:21:57 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/07 12:23:10 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	same_sign(int a, int b)
{
	if (a < 0 && b < 0)
		return (0);
	else if (a > 0 && b > 0)
		return (0);
	else if (a == 0 && b == 0)
		return (0);
	return (1);
}

int	ft_strcmp(char *s1, char *s2);

int	ft_strncmp(char *s1, char *s2, unsigned int n);

void	ft_strncmp_test(char *s1, char *s2, unsigned int n)
{
	int res;
	int ft_res;

	res = strncmp(s1, s2, n);
	ft_res = ft_strncmp(s1, s2, n);
	if (res != ft_res)
		printf("> KO, expected: %d, got: %d\n", res, ft_res);
	else
		printf("> OK, result: %d\n", ft_res);
}

int		main(void)
{
	char	*s1 = "abcdefghi";
	char	*s2 = "abcdEfghi";
	char	s3[] = {'a', 'b', -23, 'd', 'e', 'f', 'g', 'h', 'i', '\0'};
	char	*s4 = "abcdefghi";
	char	*s5 = "abcd";
	char	*s6 = "abcdefghijklmn";
	char	*s7 = "";

	int		offset;

	offset = 0;
	printf("[1] Testing strings \"%s\" and \"%s\"\n", s1, s2);
	while (offset < 10)
	{
		ft_strncmp_test(s1, s2, offset);
		offset++;
	}
	offset = 0;
	printf("[2] Testing strings \"%s\" and \"%s\"\n", s1, s3);
	while (offset < 10)
	{
		ft_strncmp_test(s1, s3, offset);
		offset++;
	}
	offset = 0;
	printf("[3] Testing strings \"%s\" and \"%s\"\n", s2, s3);
	while (offset < 10)
	{
		ft_strncmp_test(s2, s3, offset);
		offset++;
	}
	offset = 0;		// Comparing equal strings. Should return 0.
	printf("[4] Testing strings \"%s\" and \"%s\" (same strings)\n", s1, s4);
	while (offset < 10)
	{
		ft_strncmp_test(s1, s4, offset);
		offset++;
	}
	offset = 0;		// Comparing with a shorter string (s5 lenght 5).
	printf("[5] Testing strings \"%s\" and \"%s\"\n", s1, s5);
	while (offset < 10)
	{
		ft_strncmp_test(s1, s5, offset);
		offset++;
	}
	offset = 0;		// Comparing with a longer string (s6 lenght 15).
	printf("[6] Testing strings \"%s\" and \"%s\"\n", s1, s6);
	while (offset < 10)
	{
		ft_strncmp_test(s1, s6, offset);
		offset++;
	}
	offset = 0;		// Comparing with an empty string (s7).
	printf("[7] Testing strings \"%s\" and \"%s\"\n", s1, s7);
	while (offset < 10)
	{
		ft_strncmp_test(s1, s7, offset);
		offset++;
	}
	
	printf("-- Exercício 01: ");
	char str0[] = "string";
	char str1[] = "string1";
	char str2[] = "abcdef";
	char str3[] = "fedcba";
	char str4[] = {-123, -56, 6, 32, 64, 65, 66, 0};

	int ret0 = strcmp(str0, str1);
	int ret1 = ft_strcmp(str0, str1);
	int str0l = strlen(str0);
	int str1l = strlen(str1);

	if (same_sign((ret0 = strncmp(str0, str1, str0l)), (ret1 = ft_strncmp(str0, str1, str0l))))
		printf("KO, test00 expected %i got %i\n", ret0, ret1);
	else if (same_sign((ret0 = strncmp(str2, str3, 0)), (ret1 = ft_strncmp(str2, str3, 0))))
		printf("KO, test01 expected %i got %i\n", ret0, ret1);
	else if (same_sign((ret0 = strncmp(str1, str2, str1l)), (ret1 = ft_strncmp(str1, str2, str1l))))
		printf("KO, test02 expected %i got %i\n", ret0, ret1);
	else if (same_sign((ret0 = strncmp(str2, str3, 2)), (ret1 = ft_strncmp(str2, str3, 2))))
		printf("KO, test03 expected %i got %i\n", ret0, ret1);
	else if (same_sign((ret0 = strncmp(str3, str4, 2)), (ret1 = ft_strncmp(str3, str4, 2))))
		printf("KO, test04 expected %i got %i\n", ret0, ret1);
	else if (same_sign((ret0 = strncmp(str3, str4, 100)), (ret1 = ft_strncmp(str3, str4, 100))))
		printf("KO, test05 expected %i got %i\n", ret0, ret1);
	else if (same_sign((ret0 = strncmp(str0, str1, 100)), (ret1 = ft_strncmp(str0, str1, 100))))
		printf("KO, test06 expected %i got %i\n", ret0, ret1);
	else
		printf("OK\n");
	return (0);
}
