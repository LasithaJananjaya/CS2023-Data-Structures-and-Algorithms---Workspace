#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to remove leading whitespace from a string
string ltrim(const string&);

// Function to remove trailing whitespace from a string
string rtrim(const string&);

// Function to split a string into a vector of substrings based on a delimiter
vector<string> split(const string&);

// Function to calculate the median of a vector of integers
int median2(const vector<int>& F, int D) {
    int p = 0;
    // Iterate through the frequency vector F
    for (size_t i = 0; i < F.size(); i++) {
        p += F[i];
        // Check if the current prefix sum is greater than half of D
        if (p * 2 > D) {
            return 2 * i; // Return the current index as the median
        } 
        // Check if the current prefix sum is equal to half of D
        else if (p * 2 == D) {
            // Iterate from the next index until a non-zero frequency is found
            for (size_t j = i + 1;; j++) {
                if (F[j]) {
                    return i + j; // Return the sum of current and next index as the median
                }
            }
        }
    }
    return -1; // Return -1 if the median is not found
}

// Function to calculate the number of notifications required
int activityNotifications(vector<int> expenditure, int d) {
    const int MAXE = 210;

    int result = 0;
    vector<int> F(MAXE, 0); // Frequency vector to store the count of each expenditure

    // Iterate through the expenditures
    for (size_t i = 0; i < expenditure.size(); i++) {
        if (i >= static_cast<size_t>(d)) {
            // Check if the current expenditure exceeds or equals the median of the previous d expenditures
            if (expenditure[i] >= median2(F, d)) {
                ++result; // Increment the notification count
            }
            F[expenditure[i - d]]--; // Decrease the count of the oldest expenditure in the window
        }
        F[expenditure[i]]++; // Increase the count of the current expenditure
    }

    return result; // Return the total number of notifications
}

int main() {
    string output_path = "output.txt";
    ofstream fout(output_path); // Output file stream to write the result

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]); // Total number of expenditures
    int d = stoi(first_multiple_input[1]); // Number of days for median calculation

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);

    // Convert the expenditure strings to integers and store them in the expenditure vector
    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);
        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d); // Calculate the number of notifications

    cout << result << endl; // Output the result to the console

    fout.close(); // Close the output file stream

    return 0; // Exit the program
}

// Function to remove leading whitespace from a string
string ltrim(const string& str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](int c) {
        return !isspace(c); // Find the first non-whitespace character
    }));
    return s; // Return the string with leading whitespace removed
}

// Function to remove trailing whitespace from a string
string rtrim(const string& str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), [](int c) {
        return !isspace(c); // Find the last non-whitespace character
    }).base(), s.end());
    return s; // Return the string with trailing whitespace removed
}

// Function to split a string into a vector of substrings based on a delimiter
vector<string> split(const string& str) {
    vector<string> tokens;
    size_t start = 0, end = 0;
    while ((end = str.find(' ', start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens; // Return the vector of substrings
}