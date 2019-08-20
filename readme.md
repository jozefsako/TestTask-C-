# Install header files and library for cURL
sudo apt-get install aptitude libcurl4-openssl-dev

# Compile and run the code
g++ Main.cpp -o Main -lcurl
./main

# Or Use makefile
make clean
make all
./main
