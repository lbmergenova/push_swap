NAME	= push_swap
NAME_B	= checker

SRCS	= push_swap.c get_data.c get_data_utils.c\
			get_stack.c list.c\
			operations.c operations_n.c\
			choice_move.c sorting_three.c\
			ft_qsort_recursive.c\
			go_move_0.c go_move.c utils.c\

BNS		= checker.c checker_operations.c\
			get_data.c get_data_utils.c ft_qsort_recursive.c\
			list.c operations.c utils.c\
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\

LIB 	= ./libft/libft.a

HEADER  = push_swap.h ./libft/libft.h

RM		= rm -f
		 
OBJS	= $(SRCS:.c=.o)
BOBJS	= $(BNS:.c=.o)

GCC		= gcc

GFLAGS	= -Wall -Wextra -Werror

$(NAME):	$(OBJS) $(HEADER)
			$(MAKE) -C ./libft
			$(GCC) $(GFLAGS) $(OBJS) $(LIB) -o ${NAME}

bonus:		$(BOBJS) $(HEADER) get_next_line/get_next_line.h
			$(MAKE) -C ./libft
			$(GCC) $(GFLAGS) $(BOBJS) $(LIB) -o ${NAME_B}

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(BOBJS)
			$(MAKE) clean -C ./libft

fclean:		clean
			$(RM) $(NAME) checker ./libft/libft.a

re:			fclean all

.PHONY:		all clean fclean re	
