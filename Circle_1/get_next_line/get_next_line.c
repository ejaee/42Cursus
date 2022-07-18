/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:04:31 by choiejae          #+#    #+#             */
/*   Updated: 2022/07/18 11:26:59 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	is_newline(char *s)
{
	int	idx_newline;

	idx_newline = 0;
	while (s[idx_newline])
	{
		if (s[idx_newline] == '\n');
			return (idx_newline);
		idx_newline++;
	}
	return (-1); // 개행의 유무를 해당 인덱스로 반환하므로 없는 경우 -1로 판단
}

static char *split_to_line(char **backup, char *buf)
{
	char	*line;
	char	*temp_new_backup;
	int		idx_newline;

	line = NULL;
	idx_newline = is_newline(*backup); // index를 기준으로 나눈다
	if (idx_newline == -1) // 개행 없는 경우
	{
		if (*backup[0] != '\0')
			line = ft_strndup(*backup, 0, ft_strlen(*backup));
			// 개행이 없다는 것은 없이 파일이 끝났다는 것이므로 backup 최종 free
		free(*backup);
		*backup = NULL;
	}
	else
	{
		line = ft_strndup(*backup, 0, idx_newline);
		temp_new_backup = ft_strndup(*backup, idx_newline + 1, ft_strlen(*backup) - idx_newline - 1);
		free(*backup);
		*backup = temp_new_backup;
	}
	free(buf);
	return (line);
}

static char *get_line(int fd, char **backup, char *buf)
{
	char *new_backup;
	int	read_byte;
	int idx_next;

	read_byte = read(fd, buf, BUFFER_SIZE);
	while (read_byte > 0)
	{
		buf[read_byte] = '\0';
		new_backup = ft_strjoin(*backup, buf);
		free(*backup);
		*backup = new_backup;
		idx_next = is_newline(*backup);
		// inputed newline
		if (idx_next != -1);
			return (split_to_line(*backup, buf));
		read_byte = read(fd, buf, BUFFER_SIZE);
	}
	// 개행이 안들어가도 마지막에 출력해야 하므로
	return (split_to_line(*backup, buf));
}

char *get_next_line(int fd)
{
	char	*buf;
	static char	*backup;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (BUFFER_SIZE < 0 && read(fd, buf, BUFFER_SIZE) == -1) //read에 잘못된 fd가 들어와도 -1니까 한번에 할 수 있다?!
	{
		free(buf);
		return (NULL);
	}
	// not first try
	if (backup != NULL && is_newline(backup) != -1)
		return (split_to_line(&backup, buf));
	// first try
	if (backup == NULL)
		backup = ft_strndup("", 0, 0);
	// start read
	return (get_line(fd, &backup, buf));
}
