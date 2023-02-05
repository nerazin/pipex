NAME	= 	pipex

SRCS 	=	utils/argcheck.c  libft/ft_bzero.c  utils/error.c  \
			utils/getenv.c  srcs/getpaths.c  srcs/getpstruct.c \
			utils/memalloc.c  srcs/mem.c  libft/ft_memset.c \
			srcs/pipex.c  libft/ft_strdup.c  libft/ft_strjoin.c \
			libft/ft_strlen.c  libft/ft_strncmp.c  utils/strnew.c  libft/ft_split.c\
			libft/ft_substr.c  libft/ft_memcpy.c  libft/ft_memmove.c\

OBJS	=	${SRCS:.c=.o}
MAIN	=	srcs/main.c

HEADER	=	-I./includes/

CC		=	clang	
CFLAGS	=	-Wall -Wextra -Werror

.c.o:		%.o : %.c
			@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

$(NAME):	./includes/pipex.h $(SRCS) $(MAIN)
			$(CC) $(HEADER) $(SRCS) $(MAIN) -o ${NAME}

all:		${NAME}

clean:
			@rm -f ${OBJS} ${OBJS_B}

fclean:		clean
			@rm -f $(NAME)

re:			fclean all
