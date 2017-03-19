CC = g++
CFLAGS = -std=c++11 -Wall -Wextra -fPIC -g3
LDFLAGS =

EXECUTABLE = wololo

SOURCES = 92.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)

all: $(EXECUTABLE)
clean:
	rm $(EXECUTABLE) $(OBJECTS)
run:
	./wololo

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: all clean run
