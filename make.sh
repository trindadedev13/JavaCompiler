# Licensed under Apache 2.0.
# Developed by Aquiles Trindade (trindadedev).

# variables
PROGRAM_NAME="JavaCompiler"

# cleanup build files
rm -rf build
mkdir build && cd build

# start build
cmake ../
make

# run program in $HOME directory
if [ "$1" = "run" ]; then
  cp $PROGRAM_NAME $HOME
  echo "$PROGRAM_NAME Copied to $HOME"
  $HOME/$PROGRAM_NAME
fi;