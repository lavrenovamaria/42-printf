#include "ft_printf.h"

void	ft_putstr_fd(char *s, t_flags *flag)
{
	int	i;

	if (s == NULL)
		return ;
	i = ft_strlen(s);
	if (flag->precision != -1 && i > flag->precision)
		i = flag->precision;
	if (flag->precision < i && flag->width == 0 \
		&& flag->minus < flag->precision)
		i = flag->precision;
	if (flag->width > i)
		ft_putchar_space(flag->width - i, flag);
	flag->minus = flag->minus - i;
	while (*s && i-- > 0)
		ft_putchar(*(s++), 1, flag);
	while (i-- > 0 || flag->minus-- > 0)
		ft_putchar(' ', 1, flag);
}
