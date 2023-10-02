NAME	= test
ENV		= ~/Documents/github/c_libraries/src
SRC		= .
OBJ		= .
INCLUDE = 
CC		= clang
CFLAG	= -Wall -O2

all: test.o
	$(CC) -o $(NAME) $(OBJ)/test.o

test.o: $(SRC)/test.c $(SRC)/escape.h
	$(CC) $(CFLAG) -I $(ENV) -c $(SRC)/test.c -o $(OBJ)/test.o

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all