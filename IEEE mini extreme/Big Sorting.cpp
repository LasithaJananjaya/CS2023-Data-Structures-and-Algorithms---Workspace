#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'bigSorting' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY unsorted as parameter.
 */

vector<string> bigSorting(vector<string> unsorted)
{
    // Sorting the vector of strings using a custom comparator
    sort(unsorted.begin(), unsorted.end(), [](const string &string_1, const string &string_2)
         {

        // If lengths of strings are different, return true if the length of 'a' is smaller
        if (string_1.length() != string_2.length())
            return string_1.length() < string_2.length();

        // If lengths are same, return true if 'a' is lexicographically smaller than 'b'
        return string_1 < string_2; });

    return unsorted;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    string n_temp;
    getline(cin, n_temp);
    int n = stoi(ltrim(rtrim(n_temp)));
    vector<string> unsorted(n);
    for (int i = 0; i < n; i++)
    {
        string unsorted_item;
        getline(cin, unsorted_item);
        unsorted[i] = unsorted_item;
    }
    vector<string> result = bigSorting(unsorted);
    for (size_t i = 0; i < result.size(); i++)
    {
        fout << result[i];
        if (i != result.size() - 1)
        {
            fout << "\n";
        }
    }
    fout << "\n";
    fout.close();
    return 0;
}

string ltrim(const string &str)
{
    string s(str);
    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    return s;
}

string rtrim(const string &str)
{
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());
    return s;
}