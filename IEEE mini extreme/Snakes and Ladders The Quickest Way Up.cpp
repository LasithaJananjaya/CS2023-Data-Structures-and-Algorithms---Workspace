#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'quickestWayUp' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY ladders
 *  2. 2D_INTEGER_ARRAY snakes
 */

int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    // Create a graph to represent the Snakes and Ladders board
    vector<int> board(101, INT_MAX); // Initialize all squares with infinity (INT_MAX)
    
    // Mark the ladder ends and snake heads on the board
    for (const auto& ladder : ladders) {
        int start = ladder[0];
        int end = ladder[1];
        board[start] = end;
    }
    for (const auto& snake : snakes) {
        int start = snake[0];
        int end = snake[1];
        board[start] = end;
    }
    
    // Perform breadth-first search (BFS) to find the shortest path
    queue<int> q;
    vector<int> dist(101, -1); // Initialize all distances as -1
    dist[1] = 0; // Start from square 1
    q.push(1); // Enqueue the starting square
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        // Roll the dice from 1 to 6
        for (int i = 1; i <= 6; i++) {
            int next = current + i;
            
            // Check if moving beyond square 100
            if (next > 100)
                break;
            
            // Check if there is a ladder or snake at the current square
            if (board[next] != INT_MAX)
                next = board[next];
            
            // If the next square has not been visited yet, enqueue it and update its distance
            if (dist[next] == -1) {
                dist[next] = dist[current] + 1;
                q.push(next);
            }
        }
    }
    
    return dist[100]; // Return the distance to reach square 100
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> ladders(n);

        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            string ladders_row_temp_temp;
            getline(cin, ladders_row_temp_temp);

            vector<string> ladders_row_temp = split(rtrim(ladders_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int ladders_row_item = stoi(ladders_row_temp[j]);

                ladders[i][j] = ladders_row_item;
            }
        }

        string m_temp;
        getline(cin, m_temp);

        int m = stoi(ltrim(rtrim(m_temp)));

        vector<vector<int>> snakes(m);

        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            string snakes_row_temp_temp;
            getline(cin, snakes_row_temp_temp);

            vector<string> snakes_row_temp = split(rtrim(snakes_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int snakes_row_item = stoi(snakes_row_temp[j]);

                snakes[i][j] = snakes_row_item;
            }
        }

        int result = quickestWayUp(ladders, snakes);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}