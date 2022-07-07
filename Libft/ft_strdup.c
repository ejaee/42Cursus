#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dst;

 	len = ft_strlen(s1);
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, len + 1);
	return (dst);
}