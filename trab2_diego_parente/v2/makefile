CC=g++
CFLAGS=-c -g -Wall
LDFLAGS=


SOURCES=FuncLine.cpp Function.cpp FuncParam.cpp Operator.cpp main.cpp 
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=trabalho2_diego_parente


all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *o $(EXECUTABLE)
