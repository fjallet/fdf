NAME = fdf

NAME_BONUS = bonus

HEADERS = fdf.h

SRCS = fdf.c fdf_utils.c ft_coord.c ft_free.c ft_mlx_event.c ft_point.c ft_putpixel.c \
		ft_vect.c tab_utils.c ft_maptrim.c gnl.c gnl_utils.c \
		ft_iso.c ft_img_utils.c ft_mlx_event_utils.c

BONUS_SRCS = fdf.c fdf_utils.c ft_coord.c ft_free.c ft_mlx_event_bonus.c ft_point.c ft_putpixel.c \
		ft_vect.c tab_utils.c ft_maptrim.c gnl.c gnl_utils.c \
		ft_iso.c ft_img_utils.c ft_mlx_event_utils.c

OBJETS = ${SRCS:.c=.o}

OBJS_BONUS = ${BONUS_SRCS:.c=.o}

CC = gcc

FLAGS = -Wall -Werror -Wextra

MLX = @printf "\n\t\t${B_CYAN}GENERATE mlx library ...\n\n${NONE}" && cd minilibx-linux && make

%.o : %.c
	${CC} ${FLAGS} -I. -c $< -o $@

${NAME}	 : ${OBJETS}
		${MLX}
		@${CC} -o ${NAME} ${OBJETS} -L ./minilibx-linux -lmlx -lXext -lX11 -lm

${NAME_BONUS} : ${OBJS_BONUS}
			${MLX}
			@${CC} -o ${NAME_BONUS} ${OBJS_BONUS} -L ./minilibx-linux -lmlx -lXext -lX11 -lm

all: ${NAME}

bonus : ${NAME_BONUS}

clean :
	rm -f ${OBJETS}

fclean : clean
	rm -f ${NAME}
	rm -f ${NAME_BONUS}

re :  fclean all

PHONY = all clean fclean re
