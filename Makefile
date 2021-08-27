SRCS = ft_printf.c ft_char_type.c ft_int_type.c ft_is_digit.c ft_minus_nbr.c ft_params_decreased.c ft_parse_flags.c \
ft_parse_type.c ft_parse.c ft_pointer_type.c ft_print_to_percent.c ft_put_0x.c ft_putchar_space.c ft_putchar_zero.c \
ft_putchar.c ft_putnbr.c ft_putstr_fd.c ft_putstr_pointer.c ft_putstr_precision.c ft_save_asterisk.c ft_save_minus.c \
ft_save_precision.c ft_save_width.c ft_save_zero.c ft_strdup.c ft_string_type.c ft_strlen.c ft_struct.c \
ft_type_or_flags.c ft_uint_type.c ft_uXx_type.c ft_width_nbr.c ft_zero_nbr.c ft_zero_Xx.c ft_save_bonus.c

OBJS = ${SRCS:.c=.o}

NAME =  libftprintf.a

LIBC = ar rc

LIBN = ranlib

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

INC = includes

HEADER = ./ft_printf.h

.c.o:	${HEADER}
			${CC}	${CFLAGS}	-c	$<	-o	${<:.c=.o}	-I	${INC}

${NAME}:	${OBJS}
			${LIBC}	${NAME}	${OBJS}
			${LIBN}	${NAME}

all:		${NAME}

clean:
			${RM}	${OBJS}

fclean: 	clean
			${RM}	${NAME}

re: 		fclean all

.PHONY: 		all clean fclean re bonus .c.o
