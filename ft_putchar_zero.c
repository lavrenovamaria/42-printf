#include "ft_printf.h"

void	ft_putchar_zero(int count, t_flags *flag)
{
	while (count-- > 0)
		ft_putchar('0', 1, flag);
}
