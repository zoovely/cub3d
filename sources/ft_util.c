#include "cub3d.h"

int	ft_strlen(const char *s)
{
	int	count;

	if (s == NULL)
		return (0);
	count = 0;
	while (s[count])
		count += 1;
	return (count);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*new;
	size_t			index;
	unsigned char	*ptr;

	new = (void *)malloc(count * size);
	if (new == NULL)
	{
		printf("Error\n%s\n", strerror(errno));
		return (NULL);
	}
	index = 0;
	ptr = (unsigned char *)new;
	while (index < count * size)
	{	
		ptr[index] = '\0';
		index += 1;
	}
	return (new);
}

int	ft_atoi(const char *str)
{
	long long	result;
	long long	tmp;
	long long	sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		tmp = result;
		result = result * 10 + (*str - '0');
		if (tmp > result && sign < 0)
			return (0);
		if (tmp > result && sign > 0)
			return (-1);
		str++;
	}
	return ((int)(result * sign));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*c1 == *c2 && *c1 != '\0')
		{
			c1++;
			c2++;
			n--;
		}
		else
			return (*c1 - *c2);
	}
	return (0);
}
