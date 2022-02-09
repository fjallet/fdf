NAME = fdf.out

HEADERS = fdf.h

SRCS = fdf.c fdf_utils.c ft_coord.c ft_free.c maptrim.c ft_mlx_event.c ft_point.c ft_putpixel.c \
		ft_split.c ft_splitnum.c ft_vect.c tab_utils.c ft_maptrim.c gnl.c gnl_utils.c

OBJETS = ${SRCS:.c=.o}

CC = gcc

FLAGS = -Wall -Werror -Wextra

%.o : %.c
	${CC} ${FLAGS} -I/usr/local/include/mlx.h -c $< -o $@

${NAME}	 : ${OBJETS}
		${CC} -o ${NAME} ${OBJETS} -lmlx -framework OpenGL -framework AppKit

all: ${NAME}

clean :
	rm -f ${OBJETS}

fclean : clean
	rm -f ${NAME}

re :  fclean all

PHONY = all clean fclean re
