NAME  	= console_window
UTEST	= unit_test
SRC		= .
OBJ		= .
INCLUDE = ~/Documents/github/c_libraries/src
CC		= clang
CFLAG	= -Wall -O2

all: $(UTEST).o $(NAME).o
	$(CC) -o $(UTEST) $(OBJ)/$(UTEST).o $(OBJ)/$(NAME).o $(OBJ)/consoleio.o

$(UTEST).o: $(SRC)/$(UTEST).c $(SRC)/$(NAME).h
	$(CC) $(CFLAG) -I $(INCLUDE) -c $(SRC)/$(UTEST).c -o $(OBJ)/$(UTEST).o

$(NAME).o: $(SRC)/$(NAME).c $(SRC)/$(NAME).h $(SRC)/cw_frame.h $(SRC)/consoleio.h
	$(CC) $(CFLAG) -I $(INCLUDE) -c $(SRC)/$(NAME).c -o $(OBJ)/$(NAME).o

cw_frame.o: $(SRC)/cw_frame.c $(SRC)/cw_frame.h 
	$(CC) $(CFLAG) -I $(INCLUDE) -c $(SRC)/cw_frame.c -o $(OBJ)/cw_frame.o

cw_field.o: $(SRC)/cw_field.c $(SRC)/cw_field.h 
	$(CC) $(CFLAG) -I $(INCLUDE) -c $(SRC)/cw_field.c -o $(OBJ)/cw_field.o

consoleio.o: $(SRC)/consoleio.c $(SRC)/consoleio.h 
	$(CC) $(CFLAG) -I $(INCLUDE) -c $(SRC)/consoleio.c -o $(OBJ)/consoleio.o

#clean:
#	rm -f $(OBJS)

#fclean:
#	rm -f $(UTEST)

re: fclean all