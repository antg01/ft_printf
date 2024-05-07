NAME = libftprintf.a
OBJS = ${SRCS:.c=.o}
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
SRCS = ft_printf.c print_str.c print_number.c print_hex.c convert_base.c

all: ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
