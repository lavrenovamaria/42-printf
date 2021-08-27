#include "ft_printf.h"

char	*ft_char_type(char *str, va_list *ap, t_flags *flag)
{
	if (*str == 'c' || *str == '%')
	{
		if (flag->zero > 1)
			ft_putchar_zero(flag->zero - 1, flag);
		if (flag->width > 1)
			ft_putchar_space(flag->width - 1, flag);
		if (*str == '%')
			ft_putchar('%', 1, flag);
		else
			ft_putchar((char)va_arg(*ap, int), 1, flag);
		if (flag->minus > 1)
			ft_putchar_space(flag->minus - 1, flag);
	}
	return (++str);
}
