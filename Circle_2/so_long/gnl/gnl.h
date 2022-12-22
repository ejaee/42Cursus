/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:06:26 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/22 11:46:55 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../Libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1024
# endif

static char	*buf_join(char *des, char *src, size_t slen, int *error);
char		*get_next_line(int fd);

#endif
