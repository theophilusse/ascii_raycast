#!/bin/sh

NAME=$(cat config.ini | grep NAME | cut -d '=' -f 2)
COMPILER=$(cat config.ini | grep COMPILER | cut -d '=' -f 2)
SRC=$(cat config.ini | grep SRC | cut -d '=' -f 2)
HEADER=$(cat config.ini | grep HEADER | cut -d '=' -f 2)
LINK=$(cat config.ini | grep LINK | cut -d '=' -f 2)
OPTION=$(cat config.ini | grep OPTION | cut -d '=' -f 2)

$COMPILER $OPTION $HEADER $SRC -o $NAME $LINK
echo $COMPILER $OPTION $LINK $HEADER $SRC -o $NAME

rm src/*.gch
rm src/*.o
