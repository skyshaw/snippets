SRC=./src
BIN=./bin
LEX=flex
CPL=gcc

$(TGT):
	if [ ! -e $(BIN) ]; then \
	mkdir $(BIN); \
	fi
	$(LEX) -o $(BIN)/$(TGT).c $(SRC)/$(TGT)
	$(CPL) $(BIN)/$(TGT).c -o $(BIN)/$(TGT).o -lfl

clean:
	rm $(BIN) -r 

