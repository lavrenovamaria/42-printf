#include "ft_printf.h"

int	ft_save_zero (char *str, t_flags *flag, int i, va_list *ap)
{
	int	digit;

	digit = 0;
	while (str[i] == '0')
		i++;
	if (str[i] == '*')
	{
		flag->zero = (va_arg(*ap, int));
		if (flag->zero < 0)
		{
			flag->minus = flag->zero * -1;
			flag->zero = 0;
		}
		i++;
	}
	else if (ft_is_digit(str[i]) == 1)
	{
		while (ft_is_digit(str[i]) == 1)
		{
			digit = (digit * 10) + (str[i] - 48);
			i++;
		}
		flag->zero = digit;
	}
	return (i);
}
