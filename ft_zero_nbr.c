#include "ft_printf.h"

void	ft_zero_nbr(long nb, t_flags *flag, int c)
{
	if (flag->precision > c)
		ft_putchar_space(flag->zero - flag->precision, flag);
	else if (nb == 0 && flag->precision == 0)
		ft_putchar_space(flag->zero, flag);
	else if (nb == 0)
		ft_putchar_space(flag->zero - c, flag);
	else
		ft_putchar_space(flag->zero - c, flag);
}
