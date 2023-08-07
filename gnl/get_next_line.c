/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:47:16 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/07 14:37:09 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*write_line(char **buffer, int fd)
{
	int		index;
	char	*line;

	index = 1;
	line = ft_calloc(256, 1);
	while (*buffer != NULL && index != 0)
	{
		ft_strlcat(line, *buffer, ft_strlen(*buffer));
		if (ft_strchr(line, '\n'))
		{
			index = ft_strlen(line) - ft_strlen(ft_strchr(line, '\n')) + 1;
			line[index] = '\0';
			*buffer = ft_strchr(*buffer, '\n') + 1;
			break;
		}
		else
			index = read(fd, *buffer, BUFFER_SIZE);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char 		*line;
	char		*aux;

	if (buffer == NULL)
	{
		buffer = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
		read(fd, buffer, BUFFER_SIZE);
	}
	aux = write_line(&buffer, fd);
	line = ft_strdup(aux);
	free(aux);
	return (line);
}
