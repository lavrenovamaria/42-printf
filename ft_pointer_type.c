#include "ft_printf.h"

void	ft_pointer_type(unsigned long long l, t_flags *flag, int count)
{
	unsigned long long	tmp;
	char				*s;

	tmp = l;
	while (tmp != 0 && count++ >= 0)
		tmp /= 16;
	s = (char *)malloc(count + 1);
	if (!(s))
		return ;
	s[count] = '\0';
	while (l > 0)
	{
		count--;
		if (l % 16 < 10)
			s[count] = l % 16 + '0';
		else
			s[count] = l % 16 + 87;
		l /= 16;
	}
	ft_putstr_pointer(s, flag, 0);
	free(s);
}
