# physics-database
A physics course database (Assignment 2 of OOP in C++ course).
A C++ program to store and print physics courses, plus some statistical information. There will be two versions: Week 1 and Week 2.

General guidelines:
- Allow the user to enter an arbitrary number of courses from a file.
- Each line of the file contains a course mark (as a float/double), course code (as an integer, e.g. 30762) and title (as a string, e.g. Object-Oriented Programming in C++), all on a single line.
- The data is available on a file: https://theory.physics.manchester.ac.uk/~mccsnrw/cplusplus/skeleton/ass2/courselist.dat.

Week 1:
 - Write a program to read in these data and compute the mean, standard deviation and standard error of the mean for te coursework marks
 - The code should determine the number of data in the file.
 - You must use new to allocate an array (please don’t use vectors until next week).
 
Week 2:
 - Make a new copy of your code, that now uses vectors for storage.
 - Use a string stream to create a string containing the full course title.
 - Each of these strings should be stored in a vector.
 - Print out full course list using an iterator
 - Your code should be able to print out a list of courses for a particular year, as identified by the first digit of the course code, including mean and standard deviation for  those courses.



