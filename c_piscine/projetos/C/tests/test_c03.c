// #include "../C03/ex00/ft_strcmp.c"
// #include "../C03/ex01/ft_strncmp.c"
// #include "../C03/ex02/ft_strcat.c"
// #include "../C03/ex03/ft_strncat.c"
// #include "../C03/ex04/ft_strstr.c"
// #include "../C03/ex05/ft_strlcat.c"
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

int	ft_strcmp(char *s1, char *s2);
int	ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
char	*ft_strstr(char *str, char *to_find);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int	main()
{
	int n = 50;
	char str1[] = "teste1";
	char str2[] = "teste2";
	char str3[] = "teste1";
	char str4[] = "teste2";
	char str5[] = "teste strstr";
	char str6[] = "strstr";
	char str7[] = "hello";
	char str8[] = "hello";
	char str9[] = "world";
	char str0[] = "world";

	printf("EXERCICIO 00: %d\n", ft_strcmp(str1, str2));
	printf("EXERCICIO 00: %d\n", strcmp(str1, str2));
	printf("EXERCICIO 01: %d\n", ft_strncmp(str1, str2, n));
	printf("EXERCICIO 01: %d\n", strncmp(str1, str2, n));
	
	printf("EXERCICIO 02: %s\n", ft_strcat(str1, str4));
	printf("EXERCICIO 02: %s\n", strcat(str3, str4));

	printf("EXERCICIO 03: %s\n", strncat(str1, str4, n));
	printf("EXERCICIO 03: %s\n", strncat(str3, str4, n));

	printf("EXERCICIO 04: %s\n", ft_strstr(str5, str6));
	printf("EXERCICIO 04: %s\n", strstr(str5, str6));

	printf("EXERCICIO 05: %i\n", ft_strlcat(str7, str9, n));
	printf("EXERCICIO 05: %zu\n", strlcat(str8, str0, n));
}