TARGET = hashing
HEADERS = Sha256.h Block.h BlockChain.h HashMap.h Keys.h
CXX = g++
CXX_FLAGS = -Wall -std=c++11 -Wno-sign-compare

.PHONY: all clean

all: $(TARGET)

Sha256.o: Sha256.cpp Keys.cpp BlockChain.cpp Block.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

main.o: main.cpp $(HEADERS)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(TARGET): Sha256.o main.o
	$(CXX) $(CXX_FLAGS) Sha256.o main.o -o $@

clean:
	rm -rf *.o
	rm -rf $(TARGET)
	
cleantxt:
	rm -rf *.txt
