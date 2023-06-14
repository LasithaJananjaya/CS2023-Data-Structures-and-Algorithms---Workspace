#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'weightedUniformStrings' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER_ARRAY queries
 */

vector<string> weightedUniformStrings(string s, vector<int> queries)
{
    vector<string> result;
    unordered_map<int, bool> reach; // Using unordered_map for constant time lookup

    int value = 0;
    for (int i = 0; i < s.size(); i++)
    {
        // If the current character is different from the previous one, reset the weight
        if (i > 0 && s[i] != s[i - 1])
            value = 0;

        // Add the weight of the current character to the cumulative weight
        value += s[i] - 'a' + 1;

        // Mark the cumulative weight as reachable
        reach[value] = true;
    }

    // Check if each query weight is reachable
    for (int i = 0; i < queries.size(); i++)
    {
        if (reach.find(queries[i]) != reach.end())
            result.push_back("Yes");
        else
            result.push_back("No");
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++)
    {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

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