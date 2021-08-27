#include "ft_printf.h"

void	ft_putchar(char ch, int fd, t_flags *flag)
{
	write(fd, &ch, 1);
	flag->count++;
}
