NAME		=	philo_bonus


header	=	philo.h

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror  -pthread

RM			=	rm -rf

SRCS		=	main.c parsing/error.c parsing/check_args.c parsing/get_time.c  threads_data/ft_sleep.c threads_data/ft_print.c threads_data/ft_eat.c\
				threads_data/check_death.c threads_data/ft_kill.c 

SRCS_BONUS	=	

OBJS		= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

$(NAME)		: $(OBJS) $(header)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%o:%c $(header)
	$(CC) $(CFLAGS) -c $< -o $@

all			:	$(NAME)

cm			:	all clean

bonus		: $(BONUS)
	
clean		:
			$(RM) $(OBJS) $(OBJS_BONUS)

mc			: all clean

fclean		: clean
			$(RM) $(NAME) $(BONUS)

re			: fclean all