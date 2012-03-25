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

clean:
	rm *.o
