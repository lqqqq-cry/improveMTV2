#!/bin/bash
echo "build and run commands beginning..."
gcc ./connection.c -c
g++ ./exec_ddta.cpp -c
g++ ./graduation1.cpp -c
g++ ./parse.cpp -c
g++ ./resultSet.cpp -c
g++ ./rewriteSQL.cpp -c
g++ ./utilities.cpp -c
echo "build end."
