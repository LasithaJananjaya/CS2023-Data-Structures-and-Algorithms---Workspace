#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Function to trim leading whitespaces from a string
string ltrim(const string &);

// Function to trim trailing whitespaces from a string
string rtrim(const string &);

// Function to check if a year is a leap year
bool isLeapYear(int year)
{
    if (year < 1918)
    {
        return year % 4 == 0;
    }
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

// Function to get the date of the Programmer's Day for a given year
string dayOfProgrammer(int year)
{
    if (year == 1918)
    {
        return "26.09.1918";
    }

    // Create a string stream to construct the result string
    ostringstream oss;
    oss << "12.09." << year;
    string result = oss.str();

    // Adjust the day if it's not a leap year
    if (!isLeapYear(year))
    {
        result[1] = '3';
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    // Read the input year from the user
    string year_temp;
    getline(cin, year_temp);

    // Convert the string year to an integer
    int year = stoi(ltrim(rtrim(year_temp)));

    // Get the Programmer's Day for the input year
    string result = dayOfProgrammer(year);

    // Write the result to the output file
    fout << result << "\n";

    fout.close();

    return 0;
}

// Function to trim leading whitespaces from a string
string ltrim(const string &str)
{
    string s(str);

    // Erase leading whitespaces using find_if and not1 functions
    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

// Function to trim trailing whitespaces from a string
string rtrim(const string &str)
{
    string s(str);

    // Erase trailing whitespaces using find_if and not1 functions
    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}