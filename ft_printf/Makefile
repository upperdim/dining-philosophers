# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 19:39:51 by tunsal            #+#    #+#              #
#    Updated: 2023/11/11 21:03:35 by tunsal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				= ft_printf.c ft_putchar.c ft_putnbr.c ft_putsize_base.c ft_putstr.c ft_putunbr_hex.c ft_putunbr_ptr.c ft_putunbr.c
OBJS				= $(SRCS:.c=.o)

NAME				= libftprintf.a
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror

all:				./libft/libft.a $(NAME)

$(NAME):			$(OBJS)
					cp libft/libft.a $(NAME)
					ar -r $(NAME) $(OBJS) 

./libft/libft.a:
					make -C ./libft all

clean:
					make -C ./libft clean
					rm -f $(OBJS)

fclean:				clean
					make -C ./libft fclean
					rm -f $(NAME)

re:					fclean all