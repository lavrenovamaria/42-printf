#include "ft_printf.h"

int	ft_save_bonus (char *str, t_flags *flag, int i)
{
	while (str[i] == '+' && *str)
	{
		i++;
		flag->plus = 1;
	}
	while (str[i] == '#' && *str)
	{
		i++;
		flag->sharp = '1';
	}
	while (str[i] == ' ' && *str)
	{
		i++;
		flag->space = 1;
	}
	return (i);
}
