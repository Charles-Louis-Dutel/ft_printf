NAME = libftprintf.a

SRCS = \
		ft_printf.c fonctions.c fonctions2.c

OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rcs $@ $?

bonus : ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
