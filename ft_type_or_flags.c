#include "ft_printf.h"

int	ft_type_or_flags(char diff)
{
	char	*flags;
	char	*type;

	flags = "-0.*# +0123456789\0";
	type = "csdiuxXp%\0";
	while (*flags || *type)
	{
		if (*flags == diff)
			return (1);
		else
			flags++;
		if (*type == diff)
			return (2);
		else
			type++;
	}
	return (0);
}
