SRCS						= philo.c  philosopher.c  args.c  time.c
OBJS						= ft_printf/libftprintf.a

NAME						= philo
CC							= cc
CFLAGS						= -Wall -Wextra -Werror -pthread

all:						$(NAME)

$(NAME):					$(OBJS)

ft_printf/libftprintf.a:
							make -C ./ft_printf all

clean:						
							make -C ./ft_printf clean
							rm -f $(OBJS) $(BONUS_OBJS)

fclean:						clean
							make -C ./ft_printf fclean
							rm -f $(NAME) $(BONUS_NAME)

re:							fclean all
