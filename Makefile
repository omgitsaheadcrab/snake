#! Makefile

.POSIX:

CC = g++
CFLAGS = -g

SRCDIR = src

LIBS = -lncursesw

_OBJ = main.cpp snake.cpp heading.cpp about.cpp
OBJ = $(patsubst %,$(SRCDIR)/%,$(_OBJ))

_DEPS = snake.h heading.h segment.h
DEPS = $(patsubst %,$(SRCDIR)/%,$(_DEPS))

$(SRCDIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

snake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(SRCDIR)/*.o *~ core $(SRCDIR)/*~ 
