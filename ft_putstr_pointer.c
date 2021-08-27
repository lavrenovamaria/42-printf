#include "ft_printf.h"

void	ft_putstr_pointer(char *s, t_flags *flag, int i)
{
	i = ft_strlen(s);
	if (i == 0)
		i += 3;
	else
		i += 2;
	if (i < flag->width)
		ft_putchar_space(flag->width - i, flag);
	if (i < flag->minus)
		flag->minus = flag->minus - i;
	else
		flag->minus = 0;
	if (i < flag->precision)
		ft_putchar_zero(flag->precision - i, flag);
	if (i < flag->zero)
		ft_putchar_zero(flag->zero - i, flag);
	ft_put_0x(s, flag);
	while (*s)
		ft_putchar(*(s++), 1, flag);
	if (flag->minus != 0)
		ft_putchar_space(flag->minus, flag);
}
