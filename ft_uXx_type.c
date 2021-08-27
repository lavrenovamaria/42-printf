#include "ft_printf.h"

void	ft_print_flags(t_flags *flag, char *tab, char *res)
{
	if (res[0] != '0' && res[0] != '\0')
	{
		if (flag->sharp != '0')
		{
			if (tab[15] == 'f')
				write(1, "0x", 2);
			else
				write(1, "0X", 2);
			flag->count += 2;
			flag->zero -= 2;
			flag->width -= 2;
			flag->minus -= 2;
		}
	}
}

char	*ft_uXx_type(unsigned int a, t_flags *flag, char *tab)
{
	char	*res;
	long	count;
	long	ost;

	ost = (unsigned int)a;
	count = 0;
	while (a > 0 && count++ >= 0)
		a = a / 16;
	if (count == 0 && flag->precision != 0)
		count = 1;
	res = malloc(sizeof(char) * (count + 1));
	if (res == NULL)
		return (NULL);
	res[count] = '\0';
	if (ost == 0 && flag->precision != 0)
		*res = 48;
	while (count > 0)
	{
		res[--count] = tab[ost % 16];
		ost = ost / 16;
	}
	ft_print_flags(flag, tab, res);
	ft_putstr_precision(res, flag, 0);
	free(res);
	return (NULL);
}
