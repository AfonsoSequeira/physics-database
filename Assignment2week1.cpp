// PHYS 30762 Programming in C++
// Assignment 2 (Week 1)
// Program to compute mean, standard deviation and standard
// error of a set of courses. Data is read from file. 
// The program counts the number of lines in the files and creates an array of that size
// using dynamic memory allocation.

#include<iostream>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<istream>
#include<string.h>
#include<limits>

//function to compute mean from array
double mean (const int& N, double a[]) {
    double sum{0};
    double mu;
    //sum over all values of array
    for (int i{0}; i < N; i++) {
        sum += a[i];
    }
    //get mean
    mu = sum/N;
    return mu;
}

//function to compute standard deviation from array
double standard_deviation (const double& N, double a[], const double& mu) {
    double sum{0};
    double standard_dev{0};
    //sum over array
    for (int i{0}; i < N; i++) {
        sum += pow((a[i] - mu), 2);
    }
    //get standard dev.
    standard_dev = sqrt( (1.0/ (N - 1.0)) * sum);
    return standard_dev;
}

//main function
int main () {
    //ask user for file name
    std::string filename;
    std::cout << "Please input the filename." << std::endl;
    std::cin >> filename;
    std::ifstream my_file{filename}; //open file for reading
    //check if file can be opened
    if (! my_file.good ()) {
        // If not, print error message and exit
        std::cerr <<"Error: file could not be opened."<< std::endl;
        return (1);
    }
    
    //Count number of lines in the file
    int n{0};
    std::string line;
    while(std::getline(my_file, line)) {
        n++;//for each line add 1 
    }
    my_file.close ();//close file

    //create new array with dynamic memory allocation
    double* my_array{new double [n]};

    //open file again
    std::ifstream my_file2{filename};
    int j{0};
    double avg_mark;
    //read in average mark of each course to respective element of array
    while(!my_file2.eof()) {
        my_file2 >> avg_mark;
        my_file2.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        my_array[j] = avg_mark;
        j++;
    }
    //close file
    my_file2.close ();

    //calculate average stand. deviation and standard error of mean 
    double average; double standard_dev; double standard_error_mean;
    average = mean(n , my_array);
    standard_dev = standard_deviation(n, my_array, average);
    standard_error_mean = standard_dev / sqrt(n);
    //print results
    std::cout << std::setprecision(3) << "The average mark on these courses is: " << average
                << ", the standard deviation is " << standard_dev  
                << " and the std. error of the mean is " << standard_error_mean << std::endl;

    //delete new array
    delete[] my_array; 
    return 0;
}