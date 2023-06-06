#include "C03/ex00/ft_strcmp.c"
#include "C03/ex01/ft_strncmp.c"

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int strncmp(const char *str1, const char *str2, size_t n);

int	main(void)
{
	char	*c1;
	char	*c2;
	int		res;

	printf("Exercicio - 00\n");
	c1 = "hello";
	c2 = "hell";
	res = strncmp(c1, c2, 7);
	printf("TESTE AQUI %d\n", res);
	printf("str1 é maior que str2 -> %d\n", ft_strcmp(c1, c2));
	printf("str1 é maior que str2 (função nativa) -> %d\n", strcmp(c1, c2));
	c1 = "hell";
	c2 = "hello";
	res = strncmp(c1, c2, 7);
	printf("TESTE AQUI %d\n", res);
	printf("str1 é menor que str2 -> %d\n", ft_strcmp(c1, c2));
	printf("str1 é menor que str2 (função nativa)-> %d\n", strcmp(c1, c2));
	c1 = "hello";
	c2 = "hello";
	printf("str1 igual a str2 -> %d\n", ft_strcmp(c1, c2));
	printf("str1 igual a str2 (função nativa) -> %d\n", strcmp(c1, c2));
	
	printf("\nExercicio - 01\n");;
	c1 = "hello";
	c2 = "hell";
	res = strncmp(c1, c2, 5);
	printf("str1 é maior que str2 -> %d\n", ft_strncmp(c1, c2, 7));
	printf("str1 é maior que str2 (função nativa) -> %d\n", res);
	c1 = "hell";
	c2 = "hello";
	res = strncmp(c1, c2, 5);
	printf("str1 é menor que str2 -> %d\n", ft_strncmp(c1, c2, 7));
	printf("str1 é menor que str2 (função nativa)-> %d\n", res);
	c1 = "hello";
	c2 = "hello";
	res = strncmp(c1, c2, 5);
	printf("str1 igual a str2 -> %d\n", ft_strncmp(c1, c2, 7));
	printf("str1 igual a str2 (função nativa) -> %d\n", res);
}
