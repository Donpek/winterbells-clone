all:
	make build;
	make run;
	make clean;

build: *.h modules/*.h game-objects/*.h
	gcc winterbells.c modules/*.c game-objects/*.c winterbells.h modules/*.h game-objects/*.h -o WinterBells -I/usr/include/SDL2 -lSDL2;

run:
	./WinterBells;

clean:
	rm WinterBells;
