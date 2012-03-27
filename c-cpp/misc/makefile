ALGO=./algo
BIN=./bin

.PHONY: all
all:
	@echo "input your target"

.PHONY: foreach
foreach:
	g++ $(ALGO)/foreach1.cpp -o $(BIN)/foreach1.o
	g++ $(ALGO)/foreach2.cpp -o $(BIN)/foreach2.o
	g++ $(ALGO)/foreach3.cpp -o $(BIN)/foreach3.o

.PHONY: count
count:
	g++ $(ALGO)/count1.cpp -o $(BIN)/count.o

.PHONY: minmax 
minmax:
	g++ $(ALGO)/minmax1.cpp -o $(BIN)/minmax.o

.PHONY: find
find:
	g++ $(ALGO)/find1.cpp -o $(BIN)/find1.o
	g++ $(ALGO)/find2.cpp -o $(BIN)/find2.o

.PHONY: searchn
searchn:
	g++ $(ALGO)/searchn1.cpp -o $(BIN)/searchn1.o

.PHONY: search
search:
	g++ $(ALGO)/search1.cpp -o $(BIN)/search1.o
	g++ $(ALGO)/search2.cpp -o $(BIN)/search2.o

.PHONY: findend
findend:
	g++ $(ALGO)/findend1.cpp -o $(BIN)/findend1.o

.PHONY: findof
findof:
	g++ $(ALGO)/findof1.cpp -o $(BIN)/findof1.o

.PHONY: adjfind
adjfind:
	g++ $(ALGO)/adjfind1.cpp -o $(BIN)/adjfind.o

clean:
	rm *.o
