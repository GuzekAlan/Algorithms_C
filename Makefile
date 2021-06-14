# Doesn't work
SRC =  $(wildcard src/*.c)
HEAD = $(wildcard inlcude/*.h)
OBJ = $(patsubst %.c,%.o,$(SRC))

run: main.exe clean
	./main.exe

main.exe: main.c algorithms.a $(HEAD)
	gcc main.c algorithms.a -Wall -o main.exe -Iinclude
algorithms.a: $(OBJ)
	ar rcs algorithms.a $(OBJ)
%.o: %.c $(HEAD)
	gcc -c $< -Wall -o $@ -Iinclude

print:
	@echo "Sources: $(SRC)\n"

clean:
	rm $(OBJ)

# use clean and print as parameters for run
# -I$(include_dir) - add this to compiling when you have headers in other files than sources
# makefile runs like bash
# $@ - target	$< - FIRST parameter
# make executes first target from Makefile