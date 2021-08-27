#include "ft_printf.h"

void	ft_width_nbr(long nb, t_flags *flag, int c)
{
	if (flag->precision > c)
		ft_putchar_space(flag->width - flag->precision, flag);
	else if (flag->precision == 0 && nb != 0)
		ft_putchar_space(flag->width - c, flag);
	else if (flag->precision == 0 && nb == 0)
		ft_putchar_space(flag->width, flag);
	else
		ft_putchar_space(flag->width - c, flag);
}
