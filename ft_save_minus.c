#include "ft_printf.h"

int	ft_save_minus (char *str, t_flags *flag, int i, va_list *ap)
{
	int	digit;

	digit = 0;
	while (str[i] == '-')
		i++;
	if (str[i] == '0' && str[i + 1] == '*')
	{
		if (flag->minus < 0)
			flag->minus = flag->minus * -1;
		i++;
	}
	if (str[i] == '*')
	{
		flag->minus = (va_arg(*ap, int));
		if (flag->minus < 0)
			flag->minus = flag->minus * -1;
		i++;
	}
	else if (ft_is_digit(str[i]) == 1)
	{
		while (ft_is_digit(str[i]) == 1)
			digit = (digit * 10) + (str[i++] - 48);
		flag->minus = digit;
	}
	return (i);
}
