MAIN = mcc

CC = gcc
CFLAGS := -Wall -std=c11 -O2 -I include

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:%.c=%.o)

all: $(MAIN)

$(MAIN): $(OBJS)
	$(CC) -o $(MAIN) $(CFLAGS) $(OBJS)

debug: CFLAGS += -D_MCC_DEBUG -g3
debug: $(MAIN)

sanitize: CFLAGS += -fsanitize=address
sanitize: debug

clean:
	rm -rf $(MAIN)
	find . -name "*~" -exec rm {} \;
	find . -name "*.o" -exec rm {} \;

format:
	clang-format -i src/*.c include/$(MAIN)/*.h

.PHONY: debug sanitize clean format

