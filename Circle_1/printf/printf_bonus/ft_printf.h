/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:23:56 by ejachoi           #+#    #+#             */
/*   Updated: 2022/08/24 15:06:01 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
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
	int	total_print_len;
	int	total_print_fail;
	int	flag_receiving_input;
	int	flag_minus;
	int	flag_impos;
}	t_info;

char	*ft_baseset(char type);
char	*ft_strchr(const char *s, int c);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_check_flag(long long nbr, const char type, t_info *info);

int		ft_print_prec(int idx, t_info *info);
int		ft_print_width(t_info *info);
int		ft_print_sign(long long nbr, t_info *info);
int		ft_print_hash(long long nbr, const char type);
int		ft_print_space(long long nbr, t_info *info);

int		ft_print_chr(int c, t_info *info);
int		ft_check_str(char *str, t_info *info);
int		ft_check_nbr(long long nbr, const char type, t_info *info);
int		ft_check_ptr(unsigned long long ptr, char *hex, t_info *info);

int		ft_printf(const char *format, ...);

#endif
