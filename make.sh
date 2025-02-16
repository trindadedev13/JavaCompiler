# cleanup build files
rm -rf build
mkdir build && cd build

# start build 
cmake ../
make

# copy to private dir to be possible run in termux android
cp JavaCompiler ~
echo "Copied to private dir"