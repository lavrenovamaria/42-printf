#include "ft_printf.h"

void	ft_putnbr(long nb, t_flags *flag, int mn, int c)
{
	char	a;
	int		cnt;

	cnt = 0;
	if (c < flag->precision)
		ft_putchar_zero(flag->precision - c, flag);
	if (flag->zero > (flag->precision + c + 1) && flag->precision == -1)
		ft_putchar_zero(flag->zero - flag->precision - c - 1, flag);
	if (nb == 0 && flag->zero != 0 && flag->precision == 0)
		ft_putchar_space(0, flag);
	else if (nb == 0 && flag->precision != 0)
		ft_putchar('0', 1, flag);
	else if (nb != 0)
	{
		while (c > cnt++)
		{
			a = nb / mn + 48;
			ft_putchar(a, 1, flag);
			nb = nb % mn;
			mn = mn / 10;
		}
	}
}
