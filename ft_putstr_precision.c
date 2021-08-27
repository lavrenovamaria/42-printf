#include "ft_printf.h"

void	ft_putstr_precision(char *s, t_flags *flag, int i)
{
	i = ft_strlen(s);
	if (i < flag->width)
	{
		if (flag->precision > i)
			ft_putchar_space(flag->width - flag->precision, flag);
		else
			ft_putchar_space(flag->width - i, flag);
	}
	if (i < flag->minus)
	{
		if (flag->precision < i)
			flag-> minus = flag->minus - i;
		else
			flag->minus = flag->minus - flag->precision;
	}
	else if (flag->minus <= i)
		flag->minus = 0;
	ft_zero_Xx(flag, i);
	if (i < flag->precision)
		ft_putchar_zero(flag->precision - i, flag);
	while (*s && i-- > 0)
		ft_putchar(*(s++), 1, flag);
	if (flag->minus > 0)
		ft_putchar_space(flag->minus, flag);
}
