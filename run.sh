#!/bin/sh

rm -f $(cat config.ini | grep NAME | cut -d '=' -f 2)
./compile.sh
./$(cat config.ini | grep NAME | cut -d '=' -f 2)
