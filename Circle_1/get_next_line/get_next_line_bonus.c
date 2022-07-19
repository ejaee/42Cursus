/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:22:28 by ejachoi           #+#    #+#             */
/*   Updated: 2022/07/19 20:41:03 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	is_newline(char *s)
{
	int	idx_nl;

	idx_nl = -1;
	while (s[++idx_nl])
	{
		if (s[idx_nl] == '\n')
			return (idx_nl);
	}
	return (-1);
}

static char	*split_to_line(char **backup, char *buf)
{
	char	*line;
	char	*temp_new_backup;
	int		idx_nl;

	line = NULL;
	idx_nl = is_newline(*backup);
	if (idx_nl == -1)
	{
		if (*backup[0] != '\0')
			line = ft_strndup(*backup, 0, ft_strlen(*backup));
		free(*backup);
		*backup = NULL;
	}
	else
	{
		line = ft_strndup(*backup, 0, idx_nl + 1);
		temp_new_backup = \
		ft_strndup(*backup, idx_nl + 1, ft_strlen(*backup) - idx_nl);
		free(*backup);
		*backup = temp_new_backup;
	}
	free(buf);
	return (line);
}

static char	*get_line(int fd, char **backup, char *buf)
{
	char	*new_backup;
	int		read_byte;
	int		idx_next;

	read_byte = read(fd, buf, BUFFER_SIZE);
	while (read_byte > 0)
	{
		buf[read_byte] = '\0';
		new_backup = ft_strjoin(*backup, buf);
		free(*backup);
		*backup = new_backup;
		idx_next = is_newline(*backup);
		if (idx_next != -1)
			return (split_to_line(backup, buf));
		read_byte = read(fd, buf, BUFFER_SIZE);
	}
	return (split_to_line(backup, buf));
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*backup[OPEN_MAX];

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	if (BUFFER_SIZE <= 0 && read(fd, buf, 0) == -1)
	{
		free(buf);
		return (NULL);
	}
	if (backup[fd] != NULL && is_newline(backup[fd]) != -1)
		return (split_to_line(&backup[fd], buf));
	if (backup[fd] == NULL)
		backup[fd] = ft_strndup("", 0, 0);
	return (get_line(fd, &backup[fd], buf));
}
