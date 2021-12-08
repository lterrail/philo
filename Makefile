NAME	= philo

SRC	=	main.c \
		init.c	

OBJ		= $(addprefix ./obj/,$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBFTA	= ./Libft/Libft.a
LIBINCL = -I./Libft/includes
LIBLINK	= -L./Libft -lft -pthread

all: obj $(LIBFTA)  $(NAME)

obj:
	mkdir -p ./obj/

./obj/%.o:./src/%.c
	$(CC) $(CFLAGS) $(LIBINCL) -Iincludes -o $@ -c $<

$(LIBFTA):
	make -C ./Libft

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBLINK)

clean:
	rm -rf ./obj/
	make -C ./Libft clean

fclean: clean
	rm -rf $(NAME)
	make -C ./Libft fclean

re: fclean all
