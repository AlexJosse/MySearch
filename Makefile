CC	= gcc

RM	= rm -f

NAME	= mysearch

SRC=	main.c \
	linkedlist.c \
	mysearch.c \
	xfunctions.c

OBJ	= $(SRC:.c=.o)

CFLAGS	= -W -Wall -Wextra

LDFLAGS	= -lncurses

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
