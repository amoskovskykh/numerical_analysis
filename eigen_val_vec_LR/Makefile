NAME = lab6
SRC = src/*.c
SRCC = *.c
INC = inc/header.h
INCC = header.h
CFLAGS = -std=c11 -Wall -Werror -Wpedantic -Wextra

all: install clean
install:
	@cp $(SRC) .
	@cp $(INC) .
	@clang $(CFLAGS) -o $(NAME) $(SRCC) -I $(INCC)
uninstall: clean
	@rm -rf $(NAME)
	@rm -rf $(SRCC) 
	@rm -rf $(INCC)
clean:
	@rm -rf $(INCC)
	@rm -rf $(SRCC)
reinstall: uninstall all
