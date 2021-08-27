#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		format;
	t_flags	flag;
	char	*len;

	len = ft_strdup((char *)fmt);
	flag = ft_struct();
	format = 0;
	va_start(ap, fmt);
	format += ft_print_to_percent(&ap, len, &flag);
	va_end(ap);
	free(len);
	return (flag.count);
}
