#include "ft_printf.h"

char	*ft_parse_type(char *str, va_list *ap, t_flags *flag)
{
	if (*str == 'c' || *str == '%')
		ft_char_type(str, ap, flag);
	else if (*str == 's')
		ft_string_type(str, ap, flag);
	else if (*str == 'i' || *str == 'd')
		ft_int_type(va_arg(*ap, int), flag, 1);
	else if (*str == 'u')
		ft_uint_type(va_arg(*ap, unsigned int), flag, 1);
	else if (*str == 'p')
		ft_pointer_type(va_arg(*ap, unsigned long long int), flag, 0);
	else if (*str == 'X')
		ft_uXx_type(va_arg(*ap, unsigned int), flag, "0123456789ABCDEF");
	else if (*str == 'x')
		ft_uXx_type(va_arg(*ap, unsigned int), flag, "0123456789abcdef");
	return (++str);
}
