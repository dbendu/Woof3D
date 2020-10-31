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