#include "ft_printf.h"

int	ft_save_precision	(char *str, t_flags *flag, int i, va_list *ap)
{
	int	digit;

	digit = 0;
	while (str[i] == '.')
		i++;
	if (str[i] == '*')
	{
		flag->precision = (va_arg(*ap, int));
		if (flag->precision < -1)
			flag->precision = -1;
		i++;
	}
	else if (ft_is_digit(str[i]) == 1)
	{
		while (ft_is_digit(str[i]) == 1)
		{
			digit = (digit * 10) + (str[i] - 48);
			i++;
		}
		flag->precision = digit;
	}
	else
		flag->precision = 0;
	return (i);
}
