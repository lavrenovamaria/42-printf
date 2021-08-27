#include "ft_printf.h"

void	ft_minus_nbr(long nb, t_flags *flag, int c)
{
	if (flag->precision > c)
		ft_putchar_space(flag->minus - flag->precision, flag);
	else if (flag->precision == 0 && nb == 0)
		ft_putchar_space(flag->minus, flag);
	else
		ft_putchar_space(flag->minus - c, flag);
}
