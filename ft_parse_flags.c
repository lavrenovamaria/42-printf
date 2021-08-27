#include "ft_printf.h"

char	*ft_parse_flags(char *str, t_flags *flag, va_list *ap)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '%' && ft_type_or_flags(*str) != 2)
	{
		if (ft_is_digit(str[i]) == 1 && str[i] != '0')
			i = ft_save_width(str, flag, i);
		if (str[i] == '-')
			i = ft_save_minus(str, flag, i, ap);
		if (str[i] == '.')
			i = ft_save_precision(str, flag, i, ap);
		if (str[i] == '*')
			i = ft_save_asterisk(str, flag, i, ap);
		if (str[i] == '+' || str[i] == '#' || str[i] == ' ')
			i = ft_save_bonus(str, flag, i);
		if (str[i] == '0')
			i = ft_save_zero(str, flag, i, ap);
		if (ft_type_or_flags(str[i]) == 2)
			return (str + i);
		if (ft_type_or_flags(str[i]) != 1)
			i++;
	}
	return (str + i);
}
