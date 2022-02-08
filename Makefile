NAME = fdf.out

HEADERS = fdf.h

SRCS = fdf.c ft_putpixel.c

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
