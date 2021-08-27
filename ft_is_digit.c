#include "ft_printf.h"

int	ft_is_digit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}
