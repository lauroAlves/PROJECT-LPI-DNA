CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

SRC = main.cpp DNAProfile.cpp Database.cpp Output.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = dna_profiler

all: $(EXEC)

$(EXEC): $(OBJ)
    $(CXX) $(OBJ) -o $(EXEC)

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f $(OBJ) $(EXEC)
