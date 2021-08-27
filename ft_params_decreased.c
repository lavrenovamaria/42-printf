#include "ft_printf.h"

long	ft_params_decreased(t_flags *flag, long nb)
{
	nb = nb * -1;
	flag->minus--;
	flag->width--;
	flag->zero--;
	return ((long)nb);
}

void	ft_params_decr(t_flags *flag)
{
	flag->minus = 0;
	flag->zero = 0;
	flag->precision = -1;
	flag->asterisk = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->sharp = '0';
	flag->width = 0;
}
