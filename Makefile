# Files
EXEC := eulersolver
SRC := $(wildcard *.c)
OBJ := $(patsubst %.c,%.o,$(SRC))

# Options
CC := gcc
CFLAGS := -O3
LDLIBS := -lm

# Rules
$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDLIBS)
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(LDLIBS)
%.o: foreuler.h

# Phony targets
.PHONY: clobber clean neat echo
clobber: clean
	$(RM) $(EXEC)
clean: neat
	$(RM) $(OBJ)
neat: 
	$(RM) *~ .*~
echo:
	@echo $(OBJ)


