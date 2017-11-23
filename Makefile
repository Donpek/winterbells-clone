all:
	make build;
	make run;
	make clean;

build: *.h modules/*.h
	gcc winterbells.c modules/*.c winterbells.h modules/*.h -o WinterBells -I/usr/include/SDL2 -lSDL2;

run:
	./WinterBells;

clean:
	rm WinterBells;
