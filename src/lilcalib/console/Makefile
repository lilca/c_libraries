
SRC     = console_app.c console_window.c cw_field.c consoleio.c
OBJ     = $(SRC:%.c=%.o)
CH		= $(SRC:%.c=%.h)
UTEST	= unit_test
ENVDIR  = ~/Documents/github/c_libraries/
SRCDIR	= .
OBJDIR	= $(ENVDIR)/obj
BINDIR  = $(ENVDIR)/bin 
INCLUDE = $(ENVDIR)//src
CC		= clang
CFLAG	= -Wall -O2 -I $(INCLUDE)

all: $(UTEST).o $(OBJ)
	$(CC) -o $(BINDIR)/$(UTEST) $(OBJ_DIR)/$(OBJ)

%.o: %.c %.h
	$(CC) $(CFLAG) -c $(SRC)/$<



$(UTEST).o: $(SRC)/$(UTEST).c $(SRC)/$(NAME).h
	$(CC) $(CFLAG) -I $(INCLUDE) -c $(SRC)/$(UTEST).c -o $(OBJ)/$(UTEST).o

$(NAME).o: $(SRC)/$(NAME).c $(SRC)/$(NAME).h $(SRC)/cw_field.h $(SRC)/cw_frame.h $(SRC)/../console.h
	$(CC) $(CFLAG) -I $(INCLUDE) -c $(SRC)/$(NAME).c -o $(OBJ)/$(NAME).o

cw_field.o: $(SRC)/cw_field.c $(SRC)/cw_field.h $(SRC)/../console.h
	$(CC) $(CFLAG) -I $(INCLUDE) -c $(SRC)/cw_field.c -o $(OBJ)/cw_field.o

consoleio.o: $*.c $(SRC)/consoleio.h 
	$(CC) $(CFLAG) -I $(INCLUDE) -c $(SRC)/consoleio.c -o $(OBJ)/consoleio.o

#clean:
#	rm -f $(OBJS)

#fclean:
#	rm -f $(UTEST)

re: fclean all