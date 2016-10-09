=========README=======
120128T D.M.D.M.B.Dissanayake
120452F P.D Pathirana
-----------------------------
File 1:
matrix.cpp file contains the implementation of sequential process

File 2:
advanced.cpp file contains the implementation of parallel process

File 3:
optimized.cpp file contains the optimization of parallel implementation

------------------Use following commands to execute-----------------------------------

Size of the matrix will be automatically incremented by 100 upto 1000.


matrix.cpp multiply A and B matrices.
g++ -fopenmp -std=c++11 matrix.cpp -o matrix 
./matrix 100

advanced.cpp multiply A and B matrices parallely

g++ -fopenmp -std=c++11 advanced.cpp -o advanced
./advanced 100

optized.cpp file
g++ -fopenmp -std=c++11 optimized.cpp -o optimized
./optimized 100
