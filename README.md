# A Tiny CMake Project to Embed Lua in C++

This is a springboard for lua projects. The cmake file has been written to download a specific version of lua (set in a variable) which is then compiled and can be linked to your own application in the normal way.

### To Download and Build

~~~
mkdir build
cd build
cmake ../
make
~~~

### To Run


~~~
cd ..
./build/myapp 
~~~


You should then get output something like this

~~~
Hello World (from Lua!)
~~~
 
### More Details

Go to a more complete [discussion with notes](https://www.seanbutler.net/2024/08/26/cmake-lua-cpp-project.html) of this project.
