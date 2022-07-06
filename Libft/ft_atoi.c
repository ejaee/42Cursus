#include "libft.h"

int ft_atoi(const char *str)
{
    int     sign;
    int     res;

    sign = 1;
    res = 0;
    while ((9 <= *str && *str <= 13) || *str == 32)
        str++;
    if (*str == '-')
    {
        str++;
        sign *= -1;
    }
    else if (*str == '+')
        str++;
    while (*str && ('0' <= *str && *str <= '9'))
    {
        res = res * 10 + (*str - '0');
        str++;
    }
    return (sign * res);
}