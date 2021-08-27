#include "ft_printf.h"

int	ft_save_width(char *str, t_flags *flag, int i)
{
	int	digit;

	digit = 0;
	while (ft_is_digit(str[i]) == 1)
	{
		digit = (digit * 10) + (str[i] - 48);
		i++;
	}
	flag->width = digit;
	return (i);
}
