# My solutions to some problems in codeforces.com.

#### All the problems have the same name as in the site.

Most problems are done in C++ except for the ones where there is an inherent need for big numbers (in that case I use Python)

##### To add your own solutions (in C++):

- Clone this repository
- Create your solution under `src` directory (for example `mySolution.cpp`)
- Run `cmake -S src -B build . -D FILE=mySolution`
- Run `make -C build`
- Done! You can test you program with an input by creating an `input.txt` and running `./build/output < input.txt`
