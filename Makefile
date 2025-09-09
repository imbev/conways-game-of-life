CFLAGS = \
	-std=c23 \
	-pedantic \
	-I ./include \
	-I ./vendor/include
LDLIBS = \
	-L ./vendor/lib \
	-lm \
	-lSDL3
OBJ = \
	vendor/lib/libSDL3.a \
	src/color.o \
	src/tile.o

.PHONY: clean clean-all

gol: gol.c $(OBJ)

src/color.o: src/color.c
src/tile.o: src/tile.c

./vendor/sdl.tar.gz:
	mkdir -p ./vendor
	curl -L -o ./vendor/sdl.tar.gz https://github.com/libsdl-org/SDL/archive/refs/tags/release-3.2.22.tar.gz

./vendor/lib/libSDL3.a: ./vendor/sdl.tar.gz
	mkdir -p ./vendor/build/sdl ./vendor/include ./vendor/lib
	-rm -rf ./vendor/build/sdl/.
	-rm -rf SDL*
	tar -xf ./vendor/sdl.tar.gz
	cp -r SDL*/. ./vendor/build/sdl/
	cp -r SDL*/include/SDL3 ./vendor/include
	rm -rf SDL*
	cd ./vendor/build/sdl/ && \
		cmake . -DSDL_STATIC=ON -DSDL_SHARED=off
	cd ./vendor/build/sdl/ && \
		cmake --build . --config Release
	cp ./vendor/build/sdl/libSDL3.a ./vendor/lib/
	rm -rf ./vendor/build/sdl/

clean:
	-rm gol ./src/*.o

clean-vendor:
	-rm -rf ./vendor
