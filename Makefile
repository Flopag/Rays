CXX = g++
CXXFLAGS = -I ./includes

SRC = $(wildcard src/**/*.cpp src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = rays

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run:
	make
	./$(TARGET)

valgrind:
	make
	valgrind ./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

force:
	make clean
	make