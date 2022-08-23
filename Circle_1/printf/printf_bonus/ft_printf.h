/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:23:56 by ejachoi           #+#    #+#             */
/*   Updated: 2022/08/23 19:35:51 by ejachoi          ###   ########.fr       */
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
	int	hash;
	int	zero;
	int	space;
	int	sign;
	int	left;
	int	width;
	int	prec;
	int	print_len;
	int	padding_len;
	int	flag_sep_zero;
	int	flag_minus;
	int	total_print_len;
	int	total_print_fail;
}	t_info;

/*
*****************************   MAIN FUNCTION   *******************************
*/

int		ft_printf(const char *format, ...);
int		parse_percent(const char **format, va_list *ap, t_info *info);
void	init_info(t_info *info);
void	check_info(const char c, t_info *info);
int		check_type(const char c, va_list *ap, t_info *info);

/*
*****************************   PRINT FUNCTION   *******************************
*/

int		ft_print_chr(int c, t_info *info);
int		ft_print_str(char *str, t_info *info);
int		ft_print_str2(char *str, t_info *info);
size_t	ft_strlen(const char *s);

int		ft_print_nbr(long long nbr, const char type, t_info *info);
int		ft_print_left_nbr(long long nbr, const char type, t_info *info);
int		ft_print_right_nbr(long long nbr, const char type, t_info *info);
int		ft_strlen_base(long long nbr, int type, t_info *info);
int		ft_putnbr_base(long long nbr, char *base, int base_size, t_info *info);

int		ft_print_ptr(unsigned long long ptr, char *hex, t_info *info);
int		ft_print_ptr2(unsigned long long ptr, char *hex, t_info *info);
int		ft_ptrlen_base(unsigned long long ptr);
int		ft_putptr_base(unsigned long long nbr, char *base, t_info *info);

/*
*****************************   UTILS FUNCTION   *******************************
*/

int		ft_print_flag(long long nbr, const char type, t_info *info);
char	*ft_baseset(char type);
char	*ft_strchr(const char *s, int c);
int		ft_isdigit(int c);

/*
*****************************   BONUS FUNCTION   *******************************
*/

int		ft_print_prec(int idx, t_info *info);
int		ft_print_width(t_info *info);
int		ft_print_sign(long long nbr, t_info *info);
int		ft_print_hash(long long nbr, const char type);
int		ft_print_space(long long nbr, t_info *info);

#endif
