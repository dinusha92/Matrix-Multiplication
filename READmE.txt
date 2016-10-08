Description
matrix.cpp file contains the implementation of sequential process
advanced.cpp file contains the implementation of parallel process

Both files have to be started using following commands.
Size of the matrix will be automatically incremented by 100 upto 1000.


matrix.cpp multiply A and B matrices.
g++ -fopenmp -std=c++11 matrix.cpp -o matrix 
./matrix 100

advanced.cpp multiply A and B matrices parallely

g++ -fopenmp -std=c++11 advanced.cpp -o advanced
./advanced 100
