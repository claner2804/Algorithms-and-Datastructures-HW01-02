# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -std=c++11

# Target executable
TARGET = main_singlyLinkedList

# Source files
SRCS = main_singlyLinkedList.cpp singlyLinkedList.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	$(RM) $(OBJS) $(TARGET)