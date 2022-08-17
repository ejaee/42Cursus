/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:23:56 by ejachoi           #+#    #+#             */
/*   Updated: 2022/08/17 13:36:20 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

/*
*****************************   MAIN FUNCTION   *******************************
*/

int		ft_printf(const char *format, ...);
int		check_type(const char c, va_list *ap);

/*
*****************************   PRINT FUNCTION   *******************************
*/

int		ft_print_chr(int c);
int		ft_print_str(unsigned char *str);
int		ft_print_nbr(long long nbr, const char type);
int		ft_print_ptr(unsigned long long ptr);

/*
*****************************   UTILS FUNCTION   *******************************
*/

size_t	ft_strlen(const char *s);
int		ft_strlen_base(long long num, int type);
int		ft_putnbr_base(long long nbr, char *type, int base_size);
char	*ft_baseset(char type);

#endif
