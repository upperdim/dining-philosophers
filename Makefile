# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 21:57:44 by tunsal            #+#    #+#              #
#    Updated: 2024/06/24 22:04:24 by tunsal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FOLDER					= src

THREADS_FOLDER				= $(SRCS_FOLDER)/threads
THREADS_SRCS				= $(THREADS_FOLDER)/getters_setters.c \
							$(THREADS_FOLDER)/init.c \
							$(THREADS_FOLDER)/join.c \
							$(THREADS_FOLDER)/observer.c \
							$(THREADS_FOLDER)/philo.c \
							$(THREADS_FOLDER)/print_msg.c \
							$(THREADS_FOLDER)/sync.c

UTILS_FOLDER				= $(SRCS_FOLDER)/utils
UTILS_SRCS					= $(UTILS_FOLDER)/args.c \
								$(UTILS_FOLDER)/free_all.c \
								$(UTILS_FOLDER)/ft_atoi_l.c \
								$(UTILS_FOLDER)/time.c \
								$(UTILS_FOLDER)/str_is_numeric.c

SRCS						= $(THREADS_SRCS) \
								$(UTILS_SRCS) \
								$(SRCS_FOLDER)/main.c

OBJS						= $(SRCS:.c=.o)

NAME						= philo
CC							= cc
CFLAGS						= -Wall -Wextra -Werror -pthread -Iinclude -g3

all:						$(NAME)

$(NAME):					$(OBJS)
							$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:						
							rm -f $(OBJS) $(BONUS_OBJS)

fclean:						clean
							rm -f $(NAME) $(BONUS_NAME)

re:							fclean all
