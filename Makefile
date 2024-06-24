THREADS_FOLDER				= src/threads
THREADS_SRCS				= $(THREADS_FOLDER)/getters_setters.c \
							$(THREADS_FOLDER)/init.c \
							$(THREADS_FOLDER)/join.c \
							$(THREADS_FOLDER)/observer.c \
							$(THREADS_FOLDER)/philo.c \
							$(THREADS_FOLDER)/print_msg.c \
							$(THREADS_FOLDER)/sync.c

UTILS_FOLDER				= src/utils
UTILS_SRCS					= $(UTILS_FOLDER)/args.c \
								$(UTILS_FOLDER)/ft_atoi_l.c \
								$(UTILS_FOLDER)/time.c \
								$(UTILS_FOLDER)/str_is_numeric.c

SRCS_FOLDER					= src
SRCS						= $(THREADS_SRCS) \
								$(UTILS_SRCS) \
								$(SRCS_FOLDER)/main.c

NAME						= philo
CC							= cc
CFLAGS						= -Wall -Wextra -Werror -pthread -Iinclude -g3

all:						$(NAME)

$(NAME):
							$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:						
							rm -f $(OBJS) $(BONUS_OBJS)

fclean:						clean
							rm -f $(NAME) $(BONUS_NAME)

re:							fclean all
