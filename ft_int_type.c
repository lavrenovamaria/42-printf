#include "ft_printf.h"

long	nbr_zvezda(t_flags *flag, long nb, int c)
{
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-', 1, flag);
	}
	else if (flag->plus == 1)
	{
		ft_putchar('+', 1, flag);
		flag->minus--;
		flag->zero--;
	}
	else if (flag->space == 1 && flag->width <= c)
	{
		ft_putchar_space(1, flag);
		flag->minus--;
		flag->zero--;
	}
	return (nb);
}

void	ft_int_type(int n, t_flags *flag, int c)
{
	long	nb;
	long	factor;

	nb = (long)n;
	if (nb < 0)
		nb = ft_params_decreased(flag, nb);
	else if (flag->plus != 0)
		flag->width--;
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
	nb = nbr_zvezda(flag, nb, c);
	ft_putnbr(nb, flag, factor, c);
	if (flag->minus > c || (flag->minus == 1 && nb == 0))
		ft_minus_nbr(nb, flag, c);
}
