NAME  	= console_window
UTEST	= unit_test
SRC		= .
OBJ		= ~/Documents/github/c_libraries/obj
INCLUDE = ~/Documents/github/c_libraries/src
CC		= clang
CFLAG	= -Wall -O2

all: $(UTEST).o $(NAME).o cw_field.o consoleio.o
	$(CC) -o $(UTEST) $(OBJ)/$(UTEST).o $(OBJ)/$(NAME).o $(OBJ)/consoleio.o $(OBJ)/cw_field.o

$(UTEST).o: $(SRC)/$(UTEST).c $(SRC)/$(NAME).h
	$(CC) $(CFLAG) -I $(INCLUDE) -c $(SRC)/$(UTEST).c -o $(OBJ)/$(UTEST).o

$(NAME).o: $(SRC)/$(NAME).c $(SRC)/$(NAME).h $(SRC)/cw_field.h $(SRC)/cw_frame.h $(SRC)/../console.h
	$(CC) $(CFLAG) -I $(INCLUDE) -c $(SRC)/$(NAME).c -o $(OBJ)/$(NAME).o

cw_field.o: $(SRC)/cw_field.c $(SRC)/cw_field.h $(SRC)/../console.h
	$(CC) $(CFLAG) -I $(INCLUDE) -c $(SRC)/cw_field.c -o $(OBJ)/cw_field.o

consoleio.o: $(SRC)/consoleio.c $(SRC)/consoleio.h 
	$(CC) $(CFLAG) -I $(INCLUDE) -c $(SRC)/consoleio.c -o $(OBJ)/consoleio.o

#clean:
#	rm -f $(OBJS)

#fclean:
#	rm -f $(UTEST)

re: fclean all