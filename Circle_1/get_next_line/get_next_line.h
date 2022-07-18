/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:31:39 by choiejae          #+#    #+#             */
/*   Updated: 2022/07/18 11:30:30 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   1024
# endif

# include <unistd.h>
# include <stdlib.h>

int ft_strlen(const char *s);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strndup(const char *src, int start, int num);

#endif
