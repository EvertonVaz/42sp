/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:47:16 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/08 20:57:45 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	write_line(char **buffer, char **line, int fd)
{
	int		index;
	char	*aux;

	index = 1;
	aux = ft_calloc(1, 1);
	while (index > 0)
	{
		aux = ft_strjoin(aux, *buffer);
		if (ft_strchr(aux, '\n'))
		{
			index = ft_strlen(aux) - ft_strlen(ft_strchr(aux, '\n')) + 1;
			aux[index] = '\0';
			*buffer = ft_strchr(*buffer, '\n') + 1;
			*line = ft_strdup(aux);
			free(aux);
			return ;
		}
		else
			index = read(fd, *buffer, BUFFER_SIZE);
	}
	*line = ft_strdup(aux);
	free(aux);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char 		*line;
	char		*temp;

	temp = NULL;
	if (buffer == NULL)
	{
		buffer = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
		read(fd, buffer, BUFFER_SIZE);
		temp = buffer;
	}
	write_line(&buffer, &line, fd);
	if (!ft_strchr(line, '\0'))
	{
		free(temp);
		buffer = NULL;
	}
	return (line);
}
