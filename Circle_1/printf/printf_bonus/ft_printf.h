/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:23:56 by ejachoi           #+#    #+#             */
/*   Updated: 2022/08/21 22:38:51 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# define TYPE "csdiuXxp%"

typedef struct s_info
{
    int hash; // #
    int zero; // 0
    int space; // ' '
    int sign; // +
    int left; // -
    int width; // [max]
    int prec; // .[min]
    int flag; // flag
    int print_len;
    int padding_len;
    int flag_minus;
}   t_info;

/*
*****************************   MAIN FUNCTION   *******************************
*/

int		ft_printf(const char *format, ...);
int		check_type(const char c, va_list *ap, t_info *info);

/*
*****************************   PRINT FUNCTION   *******************************
*/

int		ft_print_chr(int c, t_info *info);
int		ft_print_str(unsigned char *str, t_info *info);
int		ft_print_nbr(long long nbr, const char type, t_info *info);
int		ft_print_ptr(unsigned long long ptr);

/*
*****************************   UTILS FUNCTION   *******************************
*/

size_t	ft_strlen(const char *s);
int		ft_strlen_base(long long nbr, int type, t_info *info);
int	    ft_putnbr_base(long long nbr, char *base, t_info *info);
char	*ft_baseset(char type);

/*
*****************************   BONUS FUNCTION   *******************************
*/

char	*ft_strchr(const char *s, int c);
int	    ft_isdigit(int c);
int	    ft_print_flag(long long nbr, const char type, t_info *info);
int	    ft_print_hash(const char type);

#endif
