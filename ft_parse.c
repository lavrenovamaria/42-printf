#include "ft_printf.h"

char	*ft_parse(char *str, va_list *ap, t_flags *flag)
{
	int	i;

	i = 0;
	while (*str)
	{
		i = ft_type_or_flags(*str);
		if (i == 1)
			str = ft_parse_flags(str, flag, ap);
		i = ft_type_or_flags(*str);
		if (i == 2)
		{
			str = ft_parse_type(str, ap, flag);
			while (*str != '%' && *str != '\0')
				ft_putchar(*(str++), 1, flag);
		}
		if (*str != '\0' && *str != '%')
			ft_putchar(*str, 1, flag);
		if (*str == '\0')
			return (str);
		if (*str == '%')
			return (str);
		str++;
	}
	return (str);
}
