SRCS =		check_utils.c end_utils.c error_utils.c init_utils.c misc_utils.c philo_act.c thread_utils.c main.c

OBJS =		${SRCS:.c=.o}

NAME =		philo

CC =		clang

CFLAGS =	-Wall -Werror -Wextra

CFLAGSSAN = -Wall -Werror -Wextra -fsanitize=thread -O1

RM =		rm -f

.c.o:
			@${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@echo "Compiling philo"
			@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
			@echo "Compiling philo done"

all:		${NAME}

san:		${OBJS}
			${CC} ${CFLAGSSAN} ${OBJS} -o ${NAME}

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