CC=gcc
CFLAGS=-I. -Wall
OBJS=main.o linked_list.o
TARGET=main
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm -f $(OBJS) $(TARGET)
main.o: main.c linked_list.h
linked_list.o: linked_list.c linked_list.h
