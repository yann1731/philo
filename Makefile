SRCS =		ft_atoi.c main.c check_validity.c check.c checkargsnum.c convertargs.c create_philos.c \
			philo_act.c

OBJS =		${SRCS:.c=.o}

NAME =		philo

CC =		gcc

CFLAGS =	-Wall -Werror -Wextra

RM =		rm -f

.c.o:
			${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean: clean
			${RM} ${NAME}