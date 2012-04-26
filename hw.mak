SRC=./src
BIN=./bin
TEST=./test
LEX=flex
CPL=gcc
IN=in
FILE_NAME=`echo $(TGT) | sed -e 's/\(.*\)\..*/\1/g'`

$(TGT):
	if [ ! -e $(BIN) ]; then \
	mkdir $(BIN); \
	fi
	$(LEX) -o $(BIN)/$(TGT).c $(SRC)/$(TGT) && \
	$(CPL) $(BIN)/$(TGT).c -o $(BIN)/$(TGT).o -lfl && \
	$(BIN)/$(TGT).o < $(TEST)/$(FILE_NAME).$(IN)

clean:
	rm $(BIN) -r 

