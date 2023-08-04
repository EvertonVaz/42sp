/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:47:16 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/03 21:15:11 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (buffer == NULL)
			buffer = (char *)ft_calloc(BUFFER_SIZE * i, sizeof(char));
		else
			{
				line = ft_strjoin(line, *&buffer);
				if (ft_strchr(line, '\n'))
				{
					index = ft_strlen(line) - ft_strlen(ft_strchr(line, '\n')) + 1;
					line[index] = '\0';
					buffer = ft_strchr(buffer, '\n') + 1;
					return (line);
				}
				else
					read(fd, buffer, BUFFER_SIZE * i);
			}
	}
	return (NULL);
}

#include <stdio.h>
int main()
{
	int fd = open("test", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s",get_next_line(fd));
}