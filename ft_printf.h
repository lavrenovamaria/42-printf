#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		precision;
	int		asterisk;
	int		width;
	int		plus;
	int		space;
	char	sharp;
	int		count;
}				t_flags;

long	nbr_zvezda(t_flags *flag, long nb, int c);
void	ft_putchar(char ch, int fd, t_flags *flag);
void	ft_putchar_zero(int count, t_flags *flag);
void	ft_putchar_space(int count, t_flags *flag);
int		ft_type_or_flags(char diff);
int		ft_is_digit(int ch);
int		ft_save_bonus (char *str, t_flags *flag, int i);
int		ft_save_width(char *str, t_flags *flag, int i);
int		ft_save_precision	(char *str, t_flags *flag, int i, va_list *ap);
int		ft_save_asterisk (char *str, t_flags *flag, int i, va_list *ap);
int		ft_save_zero (char *str, t_flags *flag, int i, va_list *ap);
int		ft_save_minus (char *str, t_flags *flag, int i, va_list *ap);
char	*ft_parse_flags(char *str, t_flags *flag, va_list *ap);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
void	print_flags(t_flags *flag, char *tab, char *res);
void	ft_zero_Xx(t_flags *flag, int i);
void	ft_putstr_precision(char *s, t_flags *flag, int i);
void	ft_put_0x(char *s, t_flags *flag);
void	ft_putstr_pointer(char *s, t_flags *flag, int i);
void	ft_putstr_fd(char *s, t_flags *flag);
void	ft_width_nbr(long nb, t_flags *flag, int c);
void	ft_zero_nbr(long nb, t_flags *flag, int c);
void	ft_minus_nbr(long nb, t_flags *flag, int c);
long	ft_params_decreased(t_flags *flag, long nb);
void	ft_params_decr(t_flags *flag);
void	ft_putnbr(long nb, t_flags *flag, int mn, int c);
void	ft_int_type(int n, t_flags *flag, int c);
void	ft_uint_type(unsigned int n, t_flags *flag, int c);
void	ft_pointer_type(unsigned long long l, t_flags *flag, int count);
char	*ft_uXx_type(unsigned int a, t_flags *flag, char *tab);
char	*ft_char_type(char *str, va_list *ap, t_flags *flag);
char	*ft_string_type(char *str, va_list *ap, t_flags *flag);
char	*ft_parse_type(char *str, va_list *ap, t_flags *flag);
char	*ft_parse(char *str, va_list *ap, t_flags *flag);
int		ft_print_to_percent(va_list *ap, char *fmt, t_flags *flag);
t_flags	ft_struct(void);
int		ft_printf(const char *fmt, ...);

#endif
