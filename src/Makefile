SRCS =		ft_atoi.c main.c check_validity.c check.c checkargsnum.c initargs.c create_philos.c \
			philo_act.c initphilo.c get_ts.c freeall.c takeforks.c checkdeath.c destroy_mutex.c \
			get_start_time.c print.c

OBJS =		${SRCS:.c=.o}

NAME =		philo

CC =		gcc

CFLAGS =	-Wall -Werror -Wextra

RM =		rm -f

.c.o:
			@${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@echo "Compiling philo"
			@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
			@echo "Compiling philo done"

all:		${NAME}

clean:
			@echo "Removing object files"
			@${RM} ${OBJS}
			@echo "Object files removed"

fclean: clean
			@echo "Removing philo binary file"
			@${RM} ${NAME}
			@echo "Removing all files done"
re: fclean all

.PHONY: all clean fclean re