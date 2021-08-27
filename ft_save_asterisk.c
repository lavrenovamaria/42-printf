#include "ft_printf.h"

int	ft_save_asterisk (char *str, t_flags *flag, int i, va_list *ap)
{
	while (str[i] == '*')
		i++;
	flag->width = (va_arg(*ap, int));
	if (flag->width < 0)
	{
		flag->minus = flag->width * -1;
		flag->width = 0;
	}
	return (i);
}
