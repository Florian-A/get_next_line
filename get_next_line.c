/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:54:16 by f██████           #+#    #+#             */
/*   Updated: 2021/12/21 15:54:49 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int	ft_strchr_i(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	if (s[i] == (unsigned char)c)
		return (i);
	return (-1);
}

int	analyse_buffer(char *buffer, char **line)
{
	char		*s1;
	int			i;
	int			j;

	i = ft_strchr_i(buffer, '\n');
	if (i != -1)
	{
		j = ft_strchr_i(&buffer[i + 1], '\n');
		free(*line);
		if (j != -1)
		{
			*line = ft_strndup(&buffer[i + 1], j + 1);
			s1 = ft_strndup(&buffer[i + 1], BUFFER_SIZE);
			ft_strlcpy(buffer, s1, BUFFER_SIZE);
			free(s1);
			return (1);
		}
		else
			*line = ft_strndup(&buffer[i +1], BUFFER_SIZE);
	}
	return (-1);
}

void	analyse_fd(char *buffer, char **line, int fd)
{
	char	*s1;
	int		read_size;

	read_size = 1;
	while (read_size > 0)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (ft_strchr_i(buffer, '\n') == -1 && read_size != 0)
		{
			s1 = ft_strndup(*line, ft_strlen(*line));
			free(*line);
			*line = ft_strnjoin(s1, buffer, BUFFER_SIZE);
			free(s1);
		}
		else
		{
			s1 = ft_strndup(*line, ft_strlen(*line));
			free(*line);
			*line = ft_strnjoin(s1, buffer, ft_strchr_i(buffer, '\n') + 1);
			free(s1);
			break ;
		}
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE +1];
	char		*line;

	if (read(fd, buffer, 0) < 0)
		return (NULL);
	line = malloc(1 * sizeof(char));
	if (!line)
		return (NULL);
	ft_bzero(line, 1);
	if (analyse_buffer((char *)&buffer, &line) == -1)
		analyse_fd((char *)&buffer, &line, fd);
	if (line[0] == 0 && ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
