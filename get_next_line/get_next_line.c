/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:47:16 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/09 20:31:16 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*after_line(char *line)
{
	int		index;
	char	*backup;
	char	*new_line;

	if (line && ft_strchr(line, '\n'))
	{
		new_line = ft_strchr(line, '\n');
		index = ft_strlen(line) - ft_strlen(new_line) + 1;
		backup = ft_strdup(new_line + 1);
		line[index] = '\0';
		return (backup);
	}
	return (NULL);
}

static char	*get_line(char *backup, char *buffer, int fd)
{
	int		read_line;
	char	*temp;

	read_line = 1;
	temp = NULL;
	while (read_line != 0)
	{
		read_line = read(fd, buffer, BUFFER_SIZE);
		if (read_line == -1)
			return (NULL);
		else if (!read_line)
			return (backup);
		buffer[read_line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (backup);
}

char	*free_buffer(char *buffer, char *line)
{
	free(buffer);
	buffer = NULL;
	if (line)
		return (line);
	else
		return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (0);
	line = get_line(backup, buffer, fd);
	backup = after_line(line);
	if (!ft_strchr(line, '\n'))
	{
		free(backup);
		backup = NULL;
	}
	return (free_buffer(buffer, line));
}
