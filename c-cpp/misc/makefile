ALGO=./algo
BOOST=./boost
BIN=./bin
INCLUDE=/home/skyshaw/Documents/lib/boost/include

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

.PHONY: equal
equal:
	g++ $(ALGO)/equal1.cpp -o $(BIN)/equal.o

.PHONY: mismatch
mismatch:
	g++ $(ALGO)/mismatch1.cpp -o $(BIN)/mismatch.o

.PHONY:
lexico:
	g++ $(ALGO)/lexico1.cpp -o $(BIN)/lexico.o

.PHONY:
copy:
	g++ $(ALGO)/copy1.cpp -o $(BIN)/copy1.o
	g++ $(ALGO)/copy2.cpp -o $(BIN)/copy2.o
	g++ $(ALGO)/copy3.cpp -o $(BIN)/copy3.o

.PHONY:
transform:
	g++ $(ALGO)/transform1.cpp -o $(BIN)/transform1.o
	g++ $(ALGO)/transform2.cpp -o $(BIN)/transform2.o

.PHONY:
swap:
	g++ $(ALGO)/swap1.cpp -o $(BIN)/swap1.o

.PHONY:
fill:
	g++ $(ALGO)/fill1.cpp -o $(BIN)/fill.o

.PHONY:
generate:
	g++ $(ALGO)/gen1.cpp -o $(BIN)/gen.o

.PHONY:
replace:
	g++ $(ALGO)/replace.cpp -o $(BIN)/replace.o

.PHONY:
remove:
	g++ $(ALGO)/remove.cpp -o $(BIN)/remove.o

.PHONY:
remove_copy:
	g++ $(ALGO)/remove_copy.cpp -o $(BIN)/remove_copy.o



.PHONY:
replace_copy:
	g++ $(ALGO)/replace_copy.cpp -o $(BIN)/replace_copy.o

.PHONY:
unique:
	g++ $(ALGO)/unique.cpp -o $(BIN)/unique.o
	g++ $(ALGO)/unique2.cpp -o $(BIN)/unique2.o
	g++ $(ALGO)/unique3.cpp -o $(BIN)/unique3.o

.PHONY:
reverse:
	g++ $(ALGO)/reverse.cpp -o $(BIN)/reverse.o

.PHONY:
rotate:
	g++ $(ALGO)/rotate.cpp -o $(BIN)/rotate.o
	g++ $(ALGO)/rotate_copy.cpp -o $(BIN)/rotate_copy.o

.PHONY:
permutation:
	g++ $(ALGO)/permutation.cpp -o $(BIN)/permutation.o

.PHONY:
shuffle:
	g++ $(ALGO)/shuffle.cpp -o $(BIN)/shuffle.o

.PHONY:
partition:
	g++ $(ALGO)/partition.cc -o $(BIN)/partition.o

.PHONY:
sort:
	g++ $(ALGO)/sort1.cpp -o $(BIN)/sort1.o
	g++ $(ALGO)/sort2.cpp -o $(BIN)/sort2.o

.PHONY:
partial_sort:
	g++ $(ALGO)/partial_sort1.cc -o $(BIN)/partial_sort1.o
	g++ $(ALGO)/partial_sort2.cc -o $(BIN)/partial_sort2.o

.PHONY:
nth_element:
	g++ $(ALGO)/nth_element.cc -o $(BIN)/nth_element.o

.PHONY:
heap:
	g++ $(ALGO)/heap1.cc -o $(BIN)/heap1.o

.PHONY:
bsearch:
	g++ $(ALGO)/bsearch1.cc -o $(BIN)/bsearch.o

.PHONY:
includes:
	g++ $(ALGO)/includes1.cc -o $(BIN)/includes.o

.PHONY:
bound:
	g++ $(ALGO)/bound1.cc -o $(BIN)/bound1.o

.PHONY:
equal_range:
	g++ $(ALGO)/equal_range1.cc -o $(BIN)/equal_range1.o

.PHONY: timer
timer:
	g++ $(BOOST)/timer.cpp -o $(BIN)/timer.o -I$(INCLUDE)

.PHONY:
progress:
	g++ $(BOOST)/progress.cpp -o $(BIN)/progress.o -I$(INCLUDE)

.PHONY:
new_progress:
	g++ $(BOOST)/new_progress_timer.cpp -o $(BIN)/new_progross_timer.o -I$(INCLUDE)

.PHONY:
progress_display:
	g++ $(BOOST)/progress_display.cpp -o $(BIN)/pd.o -I$(INCLUDE)

.PHONY:
result_of:
	g++ $(BOOST)/result_of.cpp -o $(BIN)/result_of.o -I$(INCLUDE) --std=c++0x

.PHONY:
bind:
	g++ $(BOOST)/bind.cpp -o $(BIN)/bind.o -I$(INCLUDE)

.PHONY:
function:
	g++ $(BOOST)/function.cpp -o $(BIN)/function.o -I$(INCLUDE)

.PHONY:
signal:
	g++ $(BOOST)/signal.cpp -o $(BIN)/signal.o -I$(INCLUDE)

.PHONY:
assign:
	g++ $(BOOST)/assign.cc -o $(BIN)/assign.o 

clean:
	rm *.o
