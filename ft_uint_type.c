#include "ft_printf.h"

void	ft_uint_type(unsigned int n, t_flags *flag, int c)
{
	long	nb;
	long	factor;

	nb = (unsigned long)n;
	factor = 1;
	while (nb >= 10 && c++ >= 0)
	{
		nb = nb / 10;
		factor = factor * 10;
	}
	nb = (long)n;
	if (c < flag->width || (flag->width == 1 && nb == 0))
		ft_width_nbr(nb, flag, c);
	if (flag->zero > flag->precision && flag->precision != -1)
		ft_zero_nbr(nb, flag, c);
	ft_putnbr(nb, flag, factor, c);
	if (flag->minus > c || (flag->minus == 1 && nb == 0))
	{
		if (flag->precision > c)
			ft_putchar_space(flag->minus - flag->precision, flag);
		else if (flag->precision == 0 && nb == 0)
			ft_putchar_space(flag->minus, flag);
		else
			ft_putchar_space(flag->minus - c, flag);
	}
}
