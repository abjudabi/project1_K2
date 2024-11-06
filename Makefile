
all: simulator.exe assembler.exe

FILENAME ?= fibonacci.asm

assembler.exe: assembler.c
	gcc -o assembler.exe assembler.c

assemble: assembler.exe
	./assembler.exe $(FILENAME)

simulator.exe: simulator.c
	gcc -o simulator.exe simulator.c

simulate: simulator.exe
	./simulator.exe $(FILENAME)

clean:
	rm -f *.exe 

help:
	@echo "all: run all files"
	@echo "clean: delete all file that have .exe extention "
	@echo "assemble: run the assembler executable file"
	@echo "simulate: run the simulate executable file"
	@echo "simulator.exe compiles the simulator.c"
	@echo "assembler.exe compiles the assembler.c"
