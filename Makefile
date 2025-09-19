CC := gcc
CFLAGS := -Wall -Wextra -Werror -std=c11

SRCS := main.c hangman.c
OBJS := $(SRCS:.c=.o)

hangman: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c hangman.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) hangman

.PHONY: clean
