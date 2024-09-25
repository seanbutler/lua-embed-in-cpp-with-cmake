# lua-embed-in-cpp-with-cmake

This is a springboard for lua projects.

The cmake file has been written to download a specific version of lua (set in a variable) which is then compiled and can be linked to your own application in the normal way.


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

