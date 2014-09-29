BIN = dictionary
cc = g++
OBJ = dictionary.o

$(BIN): $(OBJ)
	$(cc) $(OBJ) -o $(BIN)

.cpp.o:
	$(cc) -c $<

clean:
	rm *.o $(BIN)

