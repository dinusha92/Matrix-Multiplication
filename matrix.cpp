#include <iostream>
#include <chrono>
#include <time.h>
#include <omp.h>
#include <math.h>

using namespace std::chrono;
using namespace std;

#define def_sample 20

void fillValues(double** array, int size);
double** initialize(double** array, int size);
void display(double** array,int size);
double** multiply(double** array_a, double** array_b,double** array_c, int size);

double findAverage(double *time, int size);
int findSampleSize(double std, double average);
double findSD(double* data, int n, double mean);
double runOperation(int size);

int main(int argc, const char* argv[]){

	int size;
	size = atoi(argv[1]);
	double start;
	double end;

	double timeTaken[def_sample];
	double avg=0;
	double sd =0;
	int sample_size =0;
	double *timeFull;
	
	do{
		cout << "matrix size: "<<size << endl; 

		for(int i=0; i<def_sample; i++){

			timeTaken[i]= runOperation(size);
		}
	
		avg = findAverage(timeTaken, def_sample);				//average of the sample
		sd = findSD(timeTaken, def_sample, avg);				//standard deviation
		sample_size = findSampleSize(sd, avg);					//sample size
		timeFull = new double [sample_size];
		cout << "mean              : " << avg << endl;
		cout << "standard deviation: " << sd << endl;
		cout << "Sample Size       : " << sample_size << endl;
	
		for(int i=0; i<sample_size; i++){
			timeFull[i]= runOperation(size);
		}
	
		avg = findAverage(timeFull, sample_size);     	//overall average
		cout <<"Average time: "<<avg << endl <<endl;
		size+=100;
	}while(size<=1000);

}


//method to run the multiplication,initialization,population,delet arrays 
double runOperation(int size){
	double** c_array;
	double** a_array;
	double** b_array;
	c_array = initialize(c_array,size);
	a_array = initialize(a_array,size);
	b_array = initialize(b_array,size);

	fillValues(a_array,size);
	fillValues(b_array,size);

	double start = omp_get_wtime();
	c_array = multiply(a_array,b_array,c_array,size);
	double end = omp_get_wtime();

	delete c_array;
	delete a_array;
	delete b_array;	
	
	return end-start;
}
//method to multiply the matrices A and B
double** multiply(double** array_a, double** array_b,double** array_c, int size){
	for(int i=0; i < size ; i++){
		for(int j=0; j < size; j++){
		array_c[i][j]=0;
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
	srand(time(NULL));
  for(int i=0;i <size; i++){
	for(int j=0; j< size; j++){
		value = 10*((double) rand() / (double)RAND_MAX);
		array[i][j] = value;
	}  
  }
}

// method to find average
double findAverage(double* time, int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += time[i];
    }
    double average = total / size;
    return average;
}

//method to find the sample size
int findSampleSize(double std, double average) {
    double sample;
    double base = (100 * 1.96 * std) / (5 * average);
    sample = pow(base, 2);
    return (int) ceil(sample);
}

//method to find standard deviation
double findSD(double* data, int n , double mean) {
    double deviation = 0.0;
    int i;

    for (i = 0; i < n; ++i)
        deviation += (data[i] - mean) * (data[i] - mean);
    return sqrt(deviation / (n - 1));
}



