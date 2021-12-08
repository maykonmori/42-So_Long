NAME = so_long

NAME_BONUS = so_long_bonus

HEADER = so_long.h

HEADER = so_long_bonus.h

FOLDER = ./src/

FOLDER_BONUS = ./src_bonus/

SRC =	$(addprefix $(FOLDER), \
		so_long.c \
		start.c \
		verify_map.c \
		render_game.c \
		move.c \
		exit.c \
		so_long_utils.c \
		free_solong.c \
		error.c)

SRC_BONUS =		$(addprefix $(FOLDER_BONUS), \
				so_long.c \
				start.c \
				verify_map.c \
				render_game.c \
				move.c \
				exit.c \
				so_long_utils.c \
				free_solong.c \
				error.c \
				load_hero.c)


OBJS	= ${SRC:%.c=%.o}

OBJS_BONUS = ${SRC_BONUS:.c=.o}

CC = gcc

LIB = -lbsd -lmlx -lXext -lX11 -lm -lz

LIBFT = ./libft/libft.a

CFLAGS = -Wall -Werror -Wextra

.c.o:
	@$(CC) $(CFLAGS) -lmlx -c $< -o $@

all:$(NAME)
bonus: $(NAME_BONUS)


$(NAME): $(OBJS)
	@make -C ./libft
	@rm -f $(NAME)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB) $(LIBFT)

$(NAME_BONUS): $(OBJS_BONUS)
	@make -C ./libft
	@rm -f $(NAME_BONUS)
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIB) $(LIBFT)

$(LIBFT):
	@make -C ./libft

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C ./libft

re: fclean all
