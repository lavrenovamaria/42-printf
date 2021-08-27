#include "ft_printf.h"

void	ft_put_0x(char *s, t_flags *flag)
{
	if (ft_strlen(s) != 0)
	{
		write(1, "0x", 2);
		flag->count += 2;
	}
	else
	{
		write(1, "0x0", 3);
		flag->count += 3;
	}
}
