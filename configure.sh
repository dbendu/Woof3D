#!bin/sh
cd allLibs
mkdir -p temp_src
git clone https://github.com/Kain2250/sdl2-2.git temp_src/SDL2-2
mkdir -p build_SDL2
cd build_SDL2
../temp_src/SDL2-2/configure --prefix $(PWD)/../SDL2_lib/
make
make install
cd ..
git clone https://github.com/Kain2250/sdl2_image.git temp_src/SDL2_image
mkdir -p build_SDL2_image
cd build_SDL2_image
../temp_src/SDL2_image/configure --prefix $(PWD)/../SDL2_lib/
make
make install
cd ..
git clone https://github.com/Kain2250/sdl2.git temp_src/SDL2_mixer
mkdir -p build_SDL2_mixer
cd build_SDL2_mixer
../temp_src/SDL2_mixer/configure --prefix $(PWD)/../SDL2_lib/
make
make install

cd ..
git clone https://github.com/SDL-mirror/SDL_ttf.git temp_src/SDL2_ttf
mkdir -p build_SDL2_ttf
cd build_SDL2_ttf
../temp_src/SDL2_ttf/configure --prefix $(PWD)/../SDL2_lib/
make
make install

cd ..
git clone https://github.com/aseprite/freetype2.git temp_src/freetype2
mkdir -p build_freetype2
