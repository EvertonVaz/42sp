/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:47:16 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/03 20:56:18 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
eu preciso ler até encontrar o '\n' que será o final da linha
caso exista um \n no texto do arquivo ele estara como '\\n'
entao eu preciso criar um condição de leitura ate chegar nesse caso especifico
apos printar a proxima linha

caso seja de 1 em 1 a gente consegue verificar o caso, caso nao seja como faremos?
*/

/* void test()
{

	while (*buffer != NULL && *buffer != '\n')
	{
		write(1, buffer, 1);
		buffer++;
		i++;
	}
	if (*buffer == '\n' && *++buffer != NULL)
		write(1, "\n", 1);
} */



char	*get_next_line(int fd)
{
	static char *buffer;
	char 		*line;
	int			i;
	int			index;

	i = 0;
	line = ft_calloc(1, 1);
	while (++i <= BUFFER_SIZE)
	{
		buffer = (char *)ft_calloc(BUFFER_SIZE * i, sizeof(char));
		read(fd, buffer, BUFFER_SIZE * i);
		line = ft_strjoin(line, *&buffer);
		if (ft_strchr(line, '\n'))
		{
			index = ft_strlen(line) - ft_strlen(ft_strchr(line, '\n')) + 1;
			line[index] = '\0';
			buffer = ft_strchr(buffer, '\n');
			return (line);
		}
	}
	return (NULL);
}

int main()
{
	get_next_line(open("test", O_RDONLY));
	get_next_line(open("test", O_RDONLY));
}