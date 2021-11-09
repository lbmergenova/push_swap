NAME	= libft.a

SRCS	= ft_isalnum.c ft_memcpy.c\
	  	  ft_isalpha.c ft_isprint.c ft_memmove.c\
		  ft_atoi.c ft_isascii.c ft_memset.c\
		  ft_bzero.c ft_isdigit.c ft_memccpy.c\
		  ft_memchr.c ft_memcmp.c ft_strlen.c ft_toupper.c\
		  ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
		  ft_strlcpy.c ft_strlcat.c ft_strnstr.c\
		  ft_calloc.c ft_strdup.c ft_substr.c\
		  ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c\
		  ft_putendl_fd.c ft_putnbr_fd.c ft_strtrim.c\
		  ft_itoa.c ft_split.c\

OBJS	= $(SRCS:.c=.o)

GCC		= gcc

RM		= rm -f

GFLAGS	= -Wall -Wextra -Werror 

.c.o:	libft.h
		$(GCC) $(GFLAGS) -I . -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) libft.h
			ar rcs $(NAME) $?

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(B_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
