# !/bin/sh

make

sudo cp libkanlib.so /usr/lib
sudo mkdir -p /usr/include/kanlib
sudo cp include/*.h /usr/include/kanlib
