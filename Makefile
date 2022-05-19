CC = g++
CFLAG = -g -lncurses -lpthread -lglog -lgflags -lgtest
PWD = $(shell pwd)
SRC = $(shell find ./src/ -name "*.cpp")
INC = -I$(PWD)/include
PROM = clearn
OBJ = $(PROM).o
OSRC = $(shell find ./ -name "*.o")

$(PROM) : $(OBJ)
	$(CC) $(OSRC) -o $(PROM) $(CFLAG)

$(OBJ) : $(SRC)
	$(CC) -c $(SRC) $(INC) $(CFLAG) -std=c++11
clean:
	rm -rf $(PROM) *.o