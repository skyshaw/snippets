SRC=src
BIN=bin

.PHONY:
2_22:
	flex -o $(BIN)/2_22.c $(SRC)/2_22.lex 
	gcc $(BIN)/2_22.c -o $(BIN)/2_22.o -lfl #use default yywrap in library fl

.PHONY:
2_24:
	flex -o $(BIN)/2_24.c $(SRC)/2_24.lex 
	gcc $(BIN)/2_24.c -o $(BIN)/2_24.o -lfl #use default yywrap in library fl

.PHONY:
calc:
	gcc -g $(SRC)/calc.c -o $(BIN)/calc.o

