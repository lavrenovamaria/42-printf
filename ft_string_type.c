#include "ft_printf.h"

char	*ft_string_type(char *str, va_list *ap, t_flags *flag)
{
	char	*s;

	s = ft_strdup(va_arg(*ap, char *));
	ft_putstr_fd(s, flag);
	free(s);
	return (++str);
}
