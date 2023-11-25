NAME = libftprintf.a

SRCS = \
		ft_printf.c fonctions1.c fonctions2.c check_flags.c\

BSRCS = \
		fonctions_diese.c fonctions_plus.c \
		fonctions_space.c fonctions_moins.c fonctions_moins2.c \
		fonctions_point.c fonctions_point2.c fonctions_number_space.c \
		fonctions_0.c fonctions_0_point.c fonctions_0_point2.c \

SRC_ALL = ${SRCS} ${BSRCS}
OBJS = ${SRCS:.c=.o}
OBJS_ALL = ${SRC_ALL:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror


%.o : %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS} $?

all: ${NAME} bonus

bonus : ${OBJS_ALL}
	ar rcs ${NAME} ${OBJS_ALL} $?

clean:
	rm -f ${OBJS_ALL}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
