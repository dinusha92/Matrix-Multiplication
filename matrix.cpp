#include <iostream>
#include <chrono>
#include <time.h>
#include <omp.h>
using namespace std::chrono;
using namespace std;

void fillValues(double** array, int size);
double** initialize(double** array, int size);
void display(double** array,int size);
double** multiply(double** array_a, double** array_b,double** array_c, int size);
int main(int argc, const char* argv[]){

	int size;
	size = atoi(argv[1]);
	double start;
	double end;
	double** c_array;
	double** a_array;
	double** b_array;
	
	c_array = initialize(c_array,size);
	a_array = initialize(a_array,size);
	b_array = initialize(b_array,size);
	
	fillValues(a_array,size);
	fillValues(b_array,size);
	//cout <<"size "<< size<<endl;
	//cout <<"random " << 10*((double) rand() / (double)RAND_MAX)<<endl;
	//cout <<"A"<<endl;
	//display(a_array,size);
	//cout <<"B" <<endl;
	//display(b_array,size);
	start = omp_get_wtime();
	c_array = multiply(a_array,b_array,c_array,size);
	end = omp_get_wtime();
	cout << "time taken " << (end - start);
	//cout <<" C = A x B" << endl;
	//display(c_array,size);


}

//method to multiply the matrices A and B
double** multiply(double** array_a, double** array_b,double** array_c, int size){
	for(int i=0; i < size ; i++){
		for(int j=0; j < size; j++){
			for(int k=0; k< size; k++){
				array_c[i][j] += array_a[i][k]*array_b[k][j];
			}
		}
	}
	return array_c;
}

// method to initialize the matices
double ** initialize(double** array, int size){
	array = new double *[size];
	for(int i=0; i<size; i++){
		array[i] = new double[size];
	}
	return array;
}

// method to print the matrices
void display(double** array,int size){
  for(int i=0;i <size; i++){
	for(int j=0; j< size; j++){
		cout << array[i][j] << " ";
	}
	cout <<endl;  
  }
}

//method to give values to matrices
void fillValues(double** array, int size){
	double value = 0;
	//double** arr = array;
  for(int i=0;i <size; i++){
	for(int j=0; j< size; j++){
		value = 10*((double) rand() / (double)RAND_MAX);
		array[i][j] = value;
	}  
  }
}

// method to find average
float findAverage(float* time, int size) {
    float total = 0;
    for (int i = 0; i < size; i++) {
        total += time[i];
    }
    float average = total / size;
    return average;
}

//method to find the sample size
int findSampleSize(float std, float average) {
    double sample;
    double base = (100 * 1.96 * std) / (5 * average);
    sample = pow(base, 2);
    return (int) ceil(sample);
}

//method to find standard deviation
float std(float* data, int n) {
    float mean = 0.0, sum_deviation = 0.0;
    int i;
    for (i = 0; i < n; ++i) {
        mean += data[i];
    }
    mean = mean / n;
    for (i = 0; i < n; ++i)
        sum_deviation += (data[i] - mean) * (data[i] - mean);
    return sqrt(sum_deviation / (n - 1));
}



