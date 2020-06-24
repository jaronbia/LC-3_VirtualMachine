# Description

A C++ conversion of the LC-3 virtual machine found here (https://justinmeiners.github.io/lc3-vm/)
https://github.com/justinmeiners/lc3-vm

This is a full C++ conversion from the original C code found in the article, using object oriented design. 

# Compile & Run
1) c++ -std=c++17 -o main *.cpp
2) ./main 2048.obj (or any name.obj)

# Future Plans

- I plan to change the IO handling from the C libraries to the
the C++ ones.

- Implementation of the Windows Buffer so the virtual machine can run on Windows.
