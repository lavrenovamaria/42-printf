#include "ft_printf.h"

int	ft_print_to_percent(va_list *ap, char *fmt, t_flags *flag)
{
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1) != '%')
			fmt = ft_parse(++fmt, ap, flag);
		else if (*fmt != '%')
		{
			while (*fmt != '%' && *fmt)
				ft_putchar(*(fmt++), 1, flag);
		}
		else
		{
			fmt++;
			ft_putchar(*(fmt++), 1, flag);
			while (*fmt != '%' && *fmt)
				ft_putchar(*(fmt++), 1, flag);
		}
		ft_params_decr(flag);
	}
	return (0);
}
