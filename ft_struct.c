#include "ft_printf.h"

t_flags	ft_struct(void)
{
	t_flags	flag;

	flag.minus = 0;
	flag.zero = 0;
	flag.precision = -1;
	flag.asterisk = 0;
	flag.width = 0;
	flag.plus = 0;
	flag.space = 0;
	flag.sharp = '0';
	flag.count = 0;
	return (flag);
}
