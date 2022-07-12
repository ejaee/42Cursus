/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.idx_str                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:57:11 by ejachoi           #+#    #+#             */
/*   Updated: 2022/07/12 16:09:16 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read_file(int fd, char *save_line)
{
	char	*buffer;
	int		read_bytes;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
	{
		if (save_line) // 두번째부터는 정적변수가 NULL이 아니다
			free(save_line);
		return (NULL);
	}
	while (!ft_strchr(save_line, '\n')) // '\n'이 포함될 때까지 buf to (static)save
	{
		read_bytes = read(fd, save_line, BUFFER_SIZE);
		if (read_bytes == 0)
			break ;
		else if (read_bytes == -1)
		{
			free(save_line);
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		save_line = ft_strjoin(save_line, buffer);
	}
	free(buffer);
	return (save_line);
}

char	*ft_edit_line(char *save)
{
	int		idx;
	char	*str;

	idx = 0;
	if (!save[idx])	//???
		return (NULL);
	while (save[idx] && save[idx] != '\n') // \n이 없는경우도 있으니까 && \n전까지 이동
		idx++;
	str = (char *)malloc(sizeof(char) * (idx + 2)); // \n자리 \0자리 2칸
	if (!str)
		return (NULL);
	idx = 0;
	while (save[idx] && save[idx] != '\n') // idx 초기화 되었으니까 다시
	{
		str[idx] = save[idx]; // \n 전까지 str에 저장
		idx++;
	}
	if (save[idx] == '\n') // 그냥 save[idx] 하면 \n이 없는데 들어갈 수 있다.
	{
		str[idx] = save[idx]; // save's \n 를 str로 전달
		idx++;	// 또 돌 필요가 있나? >> \n\n?? 그럴 수 있네 save에 \n이 여러개있을 수 있다
	}
	str[idx] = '\0';
	return (str);
}

char	*ft_backup_file(char *save) // \n\0까지 또는 \0까지 저장된 문자열
{
	int		idx;
	int		idx_str;
	char	*str;

	idx = 0;
	while (save[idx] && save[idx] != '\n')	// 동적할당을 위한 크기구하기
		idx++;
	if (!save[idx])	// 백업 더이상 할 필요가 없으니까! 반복문 마지막의 경우
	{
		free(save); // 완벽하게 출력하고 최종 free
		return (NULL);
	}
	// memmove로 해결?
	// 현재 idx 는 개행문자에 위치 || 마지막에 \n이 없는 line에서
	str = (char *)malloc(sizeof(char) * (ft_strlen(save) - idx + 1));
	if (!str)
	{
		free(save);
		return (NULL);
	}
	idx++;
	idx_str = 0;
	while (save[idx])
		str[idx_str++] = save[idx++];
	str[idx_str] = '\0';
	free(save);
	return (str);
}

char	*get_next_line(int fd)
{
	static char *backup;
	char	*res_line;

	if (fd < 0 || BUFFER_SIZE < 1)
	 	return (NULL);
	backup = ft_read_file(fd, backup);
	if (!backup)
		return (NULL);
	res_line = ft_edit_line(backup);
	backup = ft_backup_file(backup);
	return (res_line);
}
