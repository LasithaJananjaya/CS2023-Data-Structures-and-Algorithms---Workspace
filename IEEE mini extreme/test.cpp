#include <bits/stdc++.h>

using namespace std;

// Function to trim leading whitespace from a string
string trim_left(const string &);

// Function to trim trailing whitespace from a string
string trim_right(const string &);

// Function to split a string into tokens based on whitespace
vector<string> split_string(const string &);

// Class representing a tree node
class tree_node
{
public:
    int value;
    tree_node *left;
    tree_node *right;
    tree_node(int val)
    {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to perform inorder traversal of a binary tree and store nodes in a vector
void inorder_traversal(tree_node *root, vector<int> &nodes)
{
    if (root == nullptr)
    {
        return;
    }

    inorder_traversal(root->left, nodes);
    nodes.push_back(root->value);
    inorder_traversal(root->right, nodes);
}

// Function to swap the left and right children of nodes at multiples of given queries
vector<vector<int>> swap_nodes(vector<vector<int>> tree_indexes, vector<int> queries)
{
    tree_node *root = new tree_node(1);
    queue<tree_node *> level_queue;
    level_queue.push(root);

    // Build the tree using the given tree indexes
    for (int i = 0; i < tree_indexes.size(); i++)
    {
        tree_node *current = level_queue.front();
        level_queue.pop();

        if (tree_indexes[i][0] != -1)
        {
            current->left = new tree_node(tree_indexes[i][0]);
            level_queue.push(current->left);
        }
        if (tree_indexes[i][1] != -1)
        {
            current->right = new tree_node(tree_indexes[i][1]);
            level_queue.push(current->right);
        }
    }

    vector<vector<int>> output;

    // Process each query and swap nodes accordingly
    for (int i = 0; i < queries.size(); i++)
    {
        int query = queries[i];
        queue<pair<tree_node *, int>> node_level_queue;
        node_level_queue.push(make_pair(root, 1));

        // Traverse the tree level by level and swap nodes at multiples of the query
        while (!node_level_queue.empty())
        {
            tree_node *current = node_level_queue.front().first;
            int level = node_level_queue.front().second;
            node_level_queue.pop();

            if (level % query == 0)
            {
                tree_node *temp = current->left;
                current->left = current->right;
                current->right = temp;
            }

            if (current->left)
            {
                node_level_queue.push(make_pair(current->left, level + 1));
            }
            if (current->right)
            {
                node_level_queue.push(make_pair(current->right, level + 1));
            }
        }

        // Perform inorder traversal and store the nodes in a vector
        vector<int> traversal;
        inorder_traversal(root, traversal);
        output.push_back(traversal);
    }

    return output;
}

int main()
{
    // Open output file
    ofstream output_file(getenv("OUTPUT_PATH"));

    string node_count_input;
    getline(cin, node_count_input);

    // Read the number of nodes in the tree
    int nodeCount = stoi(trim_left(trim_right(node_count_input)));

    // Read the tree indexes
    vector<vector<int>> tree_indexes(nodeCount);

    for (int i = 0; i < nodeCount; i++)
    {
        tree_indexes[i].resize(2);

        string indexesRowInput;
        getline(cin, indexesRowInput);

        vector<string> indexesRow = split_string(trim_right(indexesRowInput));

        for (int j = 0; j < 2; j++)
        {
            int indexesRowItem = stoi(indexesRow[j]);

            tree_indexes[i][j] = indexesRowItem;
        }
    }

    string query_count_input;
    getline(cin, query_count_input);

    // Read the number of queries
    int query_count = stoi(trim_left(trim_right(query_count_input)));

    // Read the queries
    vector<int> queries(query_count);

    for (int i = 0; i < query_count; i++)
    {
        string queryItemInput;
        getline(cin, queryItemInput);

        int queryItem = stoi(trim_left(trim_right(queryItemInput)));

        queries[i] = queryItem;
    }

    // Swap nodes according to the queries
    vector<vector<int>> result = swap_nodes(tree_indexes, queries);

    // Write the result to the output file
    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < result[i].size(); j++)
        {
            output_file << result[i][j];

            if (j != result[i].size() - 1)
            {
                output_file << " ";
            }
        }

        if (i != result.size() - 1)
        {
            output_file << "\n";
        }
    }

    // Close the output file
    output_file << "\n";
    output_file.close();

    return 0;
}

// Function to trim leading whitespace from a string
string trim_left(const string &str)
{
    string trimmed(str);

    trimmed.erase(
        trimmed.begin(),
        find_if(trimmed.begin(), trimmed.end(), not1(ptr_fun<int, int>(isspace))));

    return trimmed;
}

// Function to trim trailing whitespace from a string
string trim_right(const string &str)
{
    string trimmed(str);

    trimmed.erase(
        find_if(trimmed.rbegin(), trimmed.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        trimmed.end());

    return trimmed;
}

// Function to split a string into tokens based on whitespace
vector<string> split_string(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}