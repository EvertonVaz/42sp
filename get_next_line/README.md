<h1 align="center"> GET_NEXT_LINE</h1>

<div align="center">
	<p>
	<a href="https://github.com/EvertonVaz/42sp/tree/main/get_next_line" target="_blank">
		<img height=170 src="https://game.42sp.org.br/static/assets/achievements/get_next_linem.png" hspace = "10">
	</a>
	</p>
	<p>
		<a href="https://github.com/JaeSeoKim/badge42"><img src="https://badge42.vercel.app/api/v2/clk1frjdc004908mhk2togjaz/project/3227385" alt="egeraldo's 42 get_next_line Score" /></a>
	</p>
</div>
<div>
O objetivo principal deste projeto é criar uma função em C que permite ler uma linha terminando com um caractere de nova linha ('\n') de um arquivo, sem conhecer seu tamanho de antemão.

## Detalhes Técnicos

1. **Função**: A função a ser desenvolvida deve ser prototipada da seguinte maneira: `char *get_next_line(int fd);` onde `fd` é o descritor de arquivo de onde a linha será lida.

2. **Retorno**: A função deve retornar um `char *` que aponta para a linha que foi lida do arquivo. Se o final do arquivo foi atingido, ou se ocorreu um erro, NULL deve ser retornado.

3. **Uso**: A função não é um programa autônomo e seus arquivos precisam ser incluídos e compilados em outro projeto. Aqui está um exemplo de como usar esta função em um código:

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;
	(void)argc;
	fd = open(argv[1], O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

 ```cc -Wall -Wextra -Werror -D BUFFER_SIZE=xx main.c arquivo.txt```
 
4. **Compilação**: O programa deve ser compilado com a flag '-D BUFFER_SIZE=xx', que será usada como o tamanho do buffer para as chamadas de leitura na função get_next_line. Este valor será modificado pelos avaliadores e pela moulinette.
	

6. **Comportamento Indefinido**: O comportamento de get_next_line ao ler de arquivos binários é indefinido. Você pode fazer isso funcionar de acordo, mas não é necessário nem faz parte do ponto de bônus.

7. **Parte Bônus**: Capacidade de gerenciar vários descritores de arquivo com get_next_line. Por exemplo, se os descritores de arquivo 3, 4 e 5 estiverem acessíveis para leitura, você pode chamar get_next_line uma vez em 3, uma vez em 4, novamente em 3 e depois em 5 etc sem perder o fio de leitura em qualquer um dos descritores.

Este projeto é essencial para aprender sobre alocação de memória, e quando liberar e alocar memória para evitar vazamentos. É um projeto relativamente simples, mas desafiador, que serve como uma ferramenta essencial para projetos futuros.
</div>
