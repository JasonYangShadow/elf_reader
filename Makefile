target = elf_reader
objects := $(patsubst %.c, %.o, $(wildcard *.c))

make: $(objects)
	cc -o $(target) $(objects)

.PHONY: clean
clean:
	-rm -rf *.o $(target)
