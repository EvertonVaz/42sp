/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:47:16 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/04 16:01:25 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	write_line(char **buffer, char **line, int fd)
{
	int	index;

	index = 1;
	while (*buffer != NULL && index != 0)
	{
		*line = ft_strjoin(*line, *buffer);
		if (ft_strchr(*line, '\n'))
		{
			index = ft_strlen(*line) - ft_strlen(ft_strchr(*line, '\n')) + 1;
			(*line)[index] = '\0';
			*buffer = ft_strchr(*buffer, '\n') + 1;
			break;
		}
		else
			index = read(fd, *buffer, BUFFER_SIZE);
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char 		*line;
	int			i;

	i = 0;
	line = ft_calloc(1, 1);
	if (buffer == NULL)
	{
		buffer = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
		read(fd, buffer, BUFFER_SIZE);
	}
	write_line(&buffer, &line, fd);
	return (line);
}
