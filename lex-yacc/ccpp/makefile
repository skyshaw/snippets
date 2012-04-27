SRC=src
BIN=bin
GCC=gcc
CFLAGS= -Wall -Wextra -Werror
FLEX=flex
BISON=bison

.PHONY:
2_22:
	$(FLEX) -o $(BIN)/2_22.c $(SRC)/2_22.lex 
	$(GCC) $(BIN)/2_22.c -o $(BIN)/2_22.o -lfl #use default yywrap in library fl 

.PHONY:
2_24:
	$(FLEX) -o $(BIN)/2_24.c $(SRC)/2_24.lex 
	$(GCC) $(BIN)/2_24.c -o $(BIN)/2_24.o -lfl #use default yywrap in library fl

.PHONY:
calc:
	$(GCC) -g $(SRC)/calc.c -o $(BIN)/calc.o $(CFLAGS)

.PHONY:
calc2:
	$(BISON) -d $(SRC)/calc2.y -o $(BIN)/calc2.c
	$(GCC) $(BIN)/calc2.c -o $(BIN)/calc2.o $(CFLAGS)

	

