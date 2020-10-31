#!bin/sh
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
curl -L https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.15.tar.gz -o temp_src/SDL2_ttf-2.0.15.tar.gz
cd temp_src
tar xvzf SDL2_ttf-2.0.15.tar.gz
cd ..
rm -rf temp_src/SDL2_ttf-2.0.15.tar.gz
mkdir -p build_SDL2_ttf
cd build_SDL2_ttf
../temp_src/SDL2_ttf-2.0.15/configure --prefix $(PWD)/../SDL2_lib/
make
make install