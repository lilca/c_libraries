NAME  	= vector
UTEST	= unit_test
SRC		= .
OBJ		= ~/Documents/github/c_libraries/obj
INCLUDE = ~/Documents/github/c_libraries/src
CC		= clang
CFLAG	= -Wall -O2

all: $(UTEST).o $(NAME).o 
	$(CC) -o $(UTEST) $(OBJ)/$(UTEST).o $(OBJ)/$(NAME).o

$(UTEST).o: $(SRC)/$(UTEST).c $(SRC)/../$(NAME).h
	$(CC) $(CFLAG) -I $(INCLUDE) -c $(SRC)/$(UTEST).c -o $(OBJ)/$(UTEST).o

$(NAME).o: $(SRC)/$(NAME).c $(SRC)/../$(NAME).h
	$(CC) $(CFLAG) -I $(INCLUDE) -c $(SRC)/$(NAME).c -o $(OBJ)/$(NAME).o


#clean:
#	rm -f $(OBJS)

#fclean:
#	rm -f $(UTEST)

re: fclean all