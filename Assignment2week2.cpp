//Assignment 2 Week 2 (Week 2)
//Afonso Sequeira 101390191
// This program is similar to Week 1 but now uses vector instead of arrays.

#include<iostream>
#include<sstream>
#include<vector>
#include<fstream>
#include<cmath>
#include<limits>
#include<algorithm>
#include<cstring>
#include<utility>
#include<iomanip>

//function to calculate the mean of an array of numbers from a vector
double mean (const std::vector<double>& vec) {
    double sum{0};
    double mu;
    //sum over all values of vector
    for (int i{0}; i < vec.size(); i++) {
        sum += vec[i];
    }
    //calculate mean
    mu = sum/(vec.size());
    return mu;
}

//function to calculate standard deviation of array of numbers from vector
double standard_deviation (const std::vector<double>& vec , double& mu) {
    double sum{0};
    double standard_dev{0};
    for (int i{0}; i < vec.size(); i++) {
        sum += pow((vec[i] - mu), 2);
    }
    //calculate standard deviation
    standard_dev = sqrt( (1.0/ (vec.size() - 1.0)) * sum);
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

    //create vectors to hold marks, code, titles
    std::vector<double> course_marks;
    std::vector<int> course_codes;
    std::vector<std::string> course_names;
    //create vector to hold full course info as string
    std::vector<std::string> course_list;

    //create temporary variables and string stream
    double course_mark;
    int course_code;
    std::string course_name;
    std::stringstream output_stream;

    //while stream is good (avoids copying last line twice)
    while((my_file >> course_mark).good()) {
        my_file >> course_code; 
        getline(my_file, course_name); 
        //create string stream with full course info
        output_stream << "PHYS" << course_code << course_name;
        course_marks.push_back(course_mark);
        course_codes.push_back(course_code);
        course_names.push_back(course_name);
        course_list.push_back(output_stream.str());
        //clear string stream
        output_stream.str("");
    }
    //print out full course list using iterator
    std::vector <std::string>:: iterator vector_iterator ;
    std::cout << "The full list of courses in this file is: " << std::endl;
    for( vector_iterator = course_list.begin() ; vector_iterator < course_list.end() ; ++ vector_iterator ){
        std ::cout << *vector_iterator <<std :: endl;
    }

    //create vector to hold marks, codes, titles and full info for specified courses
    std::vector<double> year_course_marks;
    std::vector<std::string> year_course_list;
    std::vector<int> year_course_codes;
    std::vector<std::string> year_course_names;

    //Ask user to choose a year (1,2,3,4) and check input
    std::string user_year;
    std::cout << "Choose year (1,2,3,4)" << std::endl;
    std::cin >> user_year;
    while(std :: cin.fail () || (user_year != "1" & user_year != "2" & user_year != "3" & user_year != "4")) {
        //if input not correct print message and ask again
        std::cout << "Choose appropriate year (1,2,3,4)" << std::endl;
        std::cin >> user_year;
    }
    for (size_t i{}; i < course_list.size(); i++) {
        //check if first number in course code is the same as input from user
        if (course_list[i].substr(4,1) ==user_year) {
            //transfer elements from full list vectors into new vectors
            year_course_list.push_back(course_list[i]);
            year_course_marks.push_back(course_marks[i]);
            year_course_codes.push_back(course_codes[i]);
            year_course_names.push_back(course_names[i]);
        }
    }

    //Ask user to choose how to sort the selected data
    std::string user_sort;
    std::cout << "Choose to sort by course code (c) or title (a):" << std::endl;
    std::cin >> user_sort;
    //check input is good
    while(std :: cin.fail () || (user_sort != "c" & user_sort != "a" )) {
        std::cout << "Choose either (c/a)" << std::endl;
        std::cin >> user_sort;
    }
    //if by course code, use vector of strings and sort using iterators
    if (user_sort == "c") {
        std::vector <std::string>:: iterator vector_begin { year_course_list.begin()};
        std::vector <std::string>:: iterator vector_end { year_course_list.end()};
        std::vector <std::string>:: iterator vector_iterator ;
        sort(vector_begin, vector_end);
        for( vector_iterator = vector_begin ; vector_iterator < vector_end ; ++ vector_iterator ){
            std ::cout <<* vector_iterator <<std :: endl;
        }
    }
    //if by title, create pair structure and sort according to year_course_names
    else {
        std::vector<std::pair<std::string, int>>  myPair(year_course_codes.size());
        for (size_t i = 0; i < year_course_codes.size(); i++) {
            //make pair with course title and course code
            myPair[i] = std::make_pair(year_course_names[i], year_course_codes[i]);
        }
        sort(myPair.begin(), myPair.end());
        std::ostringstream ostream;
        //use ostringstream and print out list
        for (size_t i = 0; i < myPair.size(); i++) {
            ostream << "PHYS " << std::get<1>(myPair[i]) << std::get<0>(myPair[i]);
            std::cout << ostream.str() <<std::endl;
            ostream.str("");
        }
    }

    //calculate mean, stand. dev. and stand. err. of mean for selected courses
    double average; double standard_dev; double standard_error_mean;
    average = mean(year_course_marks);
    standard_dev = standard_deviation(year_course_marks, average);
    standard_error_mean = standard_dev / sqrt(year_course_marks.size());
    //print results
    std::cout << std::setprecision(3) << "The average mark on these courses is: " << average
                << " and the standard deviation is " << standard_dev  
                << " and the std. error of the mean is " << standard_error_mean << std::endl;
    return 0;
}