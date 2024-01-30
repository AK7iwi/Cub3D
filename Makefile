SRCS		=	srcs/cub3D.c					\
				srcs/parsing/check/args.c		\
				srcs/parsing/init/init_data.c	\
				srcs/parsing/init/init_mlx.c	\
				srcs/parsing/parser/parsing.c	\
				srcs/parsing/parser/scene.c		\
				srcs/utils/libft/ft_calloc.c	\
				srcs/utils/libft/ft_putstr.c	\
				srcs/utils/libft/ft_strchr.c	\
				srcs/utils/libft/ft_strlen.c	\
				srcs/utils/exit.c				\
				srcs/utils/free.c				\
				srcs/utils/get_next_line.c		\
				srcs/utils/line.c				\

OBJS		=	$(SRCS:.c=.o)

CC			=	cc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -I ./include # -g -MMD -g3
#CFLAGS		= 	-Wall -Wextra -Werror -g3 -I./srcs/includes

# HEADERS		=	-I ./include

MLX			=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

NAME		=	prog
#NAME		=	cub3D

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@
#%.o: %.c
#	$(CC) $(CFLAGS) $(HEADERS) -I/usr/include -Imlx_linux -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
	@make -C ./mlx_linux
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)	

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re