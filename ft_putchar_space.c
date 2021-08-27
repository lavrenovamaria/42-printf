#include "ft_printf.h"

void	ft_putchar_space(int count, t_flags *flag)
{
	while (count-- > 0)
		ft_putchar(' ', 1, flag);
}
