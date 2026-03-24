CC = gcc 
CFLAGS = -std=c99 -Werror -Wall -Wextra -pedantic
SRCS = src/fibo.c
OBJS = fibo.o
TARGET = fibonacci


all: $(TARGET) 

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) -lm

%.o : src/%.c
	$(CC) -c $(CFLAGS) $< -o $@ 

clean:
	$(RM) $(TARGET)
	$(RM) *.o
