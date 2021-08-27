#include "ft_printf.h"

void	ft_zero_Xx(t_flags *flag, int i)
{
	if (i < flag->zero)
	{
		if (flag->precision == -1)
			ft_putchar_zero(flag->zero - i, flag);
		else if (flag->precision > i)
			ft_putchar_space(flag->zero - flag->precision, flag);
		else
			ft_putchar_space(flag->zero - i, flag);
	}
}
