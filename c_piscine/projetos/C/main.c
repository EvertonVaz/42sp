#include "C03/ex00/ft_strcmp.c"
#include "C03/ex01/ft_strncmp.c"
#include "C03/ex05/ft_strlcat.c"


#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <bsd/string.h>

int main(void)
{
    char dest1[20] = "Hello";
    char dest2[20] = "Hello";
    char dest3[20] = "Hello";
    char src[10] = "World";
    char src2[10] = "World";
    char src3[10] = "World";
    unsigned int size = 20;
    
    printf("Teste 1: Concatenação bem-sucedida sem estourar o tamanho máximo\n");

    printf("Destino original: %s\n", dest1);
    printf("Destino após ft_strlcat : %u\n", ft_strlcat(dest1, src, size));
    printf("Destino após ft_strlcat_meg: %u\n", ft_strlcat_meg(dest3, src, size));
    printf("Destino após strlcat    : %lu\n", strlcat(dest2, src, size));

    printf("Destino final após ft_strlcat : %s\n", dest1);
    printf("Destino final após ft_strlcat_meg: %s\n", dest3);
    printf("Destino final após strlcat    : %s\n\n", dest2);


    printf("Teste 2: Concatenação com tamanho máximo igual ao tamanho do destino\n");

    printf("Destino original: %s\n", dest1);
    printf("Destino após ft_strlcat : %u\n", ft_strlcat(dest1, src, 10));
    printf("Destino após ft_strlcat_meg: %u\n", ft_strlcat_meg(dest3, src, 10));
    printf("Destino após strlcat    : %lu\n", strlcat(dest2, src, 10));

    printf("Destino final após ft_strlcat  : %s\n", dest1);
    printf("Destino final após ft_strlcat_meg : %s\n", dest3);
    printf("Destino final após strlcat     : %s\n\n", dest2);


    printf("Teste 3: Concatenação com tamanho máximo menor que o tamanho do destino\n");

    printf("Destino original: %s\n", dest1);
    printf("Destino após ft_strlcat : %u\n", ft_strlcat(dest1, src, 5));
    printf("Destino após ft_strlcat_meg: %u\n", ft_strlcat_meg(dest3, src, 5));
    printf("Destino após strlcat    : %lu\n", strlcat(dest2, src, 5));

    printf("Destino final após ft_strlcat : %s\n", dest1);
    printf("Destino final após ft_strlcat_meg: %s\n", dest3);
    printf("Destino final após strlcat    : %s\n\n", dest2);


    printf("Teste 4: Concatenação de string vazia\n");

    char empty_src[1] = "";
    printf("Destino original: %s\n", dest1);
    printf("Destino após ft_strlcat: %u\n", ft_strlcat(dest1, empty_src, size));
    printf("Destino após ft_strlcat: %u\n", ft_strlcat_meg(dest3, empty_src, size));
    printf("Destino após strlcat   : %lu\n", strlcat(dest2, empty_src, size));

    printf("Destino final após ft_strlcat : %s\n", dest1);
    printf("Destino final após ft_strlcat_meg: %s\n", dest3);
    printf("Destino final após strlcat    : %s\n\n", dest2);


    printf("Teste 5: Concatenação com destino vazio\n");
    
    char empty_dest[1];
    char empty_dest2[1];
    char empty_dest3[1];

    printf("Destino original: %s\n", empty_dest);
    
    printf("Destino após ft_strlcat : %u\n", ft_strlcat(empty_dest, src, size));
    printf("Destino após ft_strlcat_meg: %u\n", ft_strlcat_meg(empty_dest3, src2, size));
    printf("Destino após strlcat    : %lu\n", strlcat(empty_dest2, src3, size));

    printf("Destino final após ft_strlcat_meg: %s\n", empty_dest3);
    printf("Destino final após ft_strlcat : %s\n", empty_dest);
    printf("Destino final após strlcat : %s\n\n", empty_dest2);


    return 0;
}