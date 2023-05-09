#include <iostream>
// #include "linkedlist.cpp"
using namespace std;

struct Node
{

    /* data */
    string user_name;
    string password;
    Node *link;
};

struct LinkedList
{

    Node *head = NULL;
    Node *tail = NULL;

    int length = 0;

    void insert(string user_name, string password)
    {
        if (head == NULL)
        {
            Node *temp;
            temp = new Node;
            temp->user_name = user_name;
            temp->password = password;

            temp->link = NULL;
            head = temp;
            length++;
        }
        else
        {

            Node *temp;
            Node *prev;
            Node *tail;

            temp = new Node;
            temp->user_name = user_name;
            temp->password = password;
            temp->link = NULL;
            tail = head;
            while (true)
            {

                if (tail->link == NULL)
                {
                    break;
                }
                else
                {
                    tail = tail->link;
                }
            }
            tail->link = temp;
            length++;
        }
    }

    void search(string user_name)
    {
        Node *temp = head;
        for (int i = 0; i < length; i++)
        {
            if (temp->user_name == user_name)
            {
                cout << "Password: " << temp->password << "\n";
            }
            else
            {
                temp = temp->link;
            }
        }
    }

    void print_list()
    {
        if (head == NULL)
        {
            cout << "[]" << endl;
        }
        else
        {
            Node *temp = head;
            cout << "[";
            while (temp != NULL)
            {
                cout << temp->user_name << ", ";
                temp = temp->link;
            }
            cout << "]" << endl;
        }
    }
};

struct HashTable
{
    int MAX_LENGTH = 4;
    int MAX_CHAIN_LENGTH = 2;
    LinkedList *password = new LinkedList[MAX_LENGTH];
    bool isFull()
    {
        bool full = true;
        int count = 0;
        for (int i = 0; i < MAX_LENGTH; i++)
        {
            if (password[i].head == NULL)
            {
                full = false;
            }
        }
        return full;
    }
    int hashfunc(string user_name)
    {
        int sum = 0;
        int hash = 0;
        for (int i = 0; i < user_name.length(); i++)
        {
            sum += int(user_name[i]);
        }
        hash = sum % MAX_LENGTH;

        return hash;
    }
    bool is_slot_empty(int hash)
    {
        bool empty;
        if (password[hash].head == NULL)
        {
            empty = true;
        }
        else
        {
            empty = false;
        }
        return empty;
    }
    void insert(string user_name, string user_password)
    {
        int hash;
        bool empty;
        hash = hashfunc(user_name);
        empty = is_slot_empty(hash);
        if (password[hash].length < MAX_CHAIN_LENGTH)
        {
            password[hash].insert(user_name.data(), user_password.data());
        }
        else
        {
            cout << "Linked List reached MAX CAP!\n";
        }
    }
    void print_hashtable()
    {
        for (int i = 0; i < MAX_LENGTH; i++)
        {
            cout << "[" << i << "]-->";
            password[i].print_list();
        }
    }
    void hash_lookup(string user_name)
    {
        int hash;
        bool empty;
        hash = hashfunc(user_name);
        empty = is_slot_empty(hash);
        // add your code below
        if (!empty)
        {
            password[hash].search(user_name);
        }
        else
        {
            cout << "User not found!" << endl;
        }
    }
};

int main()
{
    HashTable *hashtbl = new HashTable;
    cout << hashtbl->isFull() << "\n";
    int command = 0;
    string user_name;
    string password;
    while (command != -1)
    {
        /* code */
        cout << "Type command: ";
        cin >> command;
        switch (command)
        {
        case 1:
            /* insert the new item*/
            cout << "Enter user name: ";
            cin >> user_name;
            cout << "Enter password to be saved: ";
            cin >> password;
            hashtbl->insert(user_name, password);
            break;
        case 2:
            /* hash lookup password*/
            cout << "Enter user name to look up password:";
            cin >> user_name;
            hashtbl->hash_lookup(user_name);
            break;
        case 3:
            hashtbl->print_hashtable();
            break;
        case -1:
            /* hash lookup password*/
            hashtbl->print_hashtable();
            cout << "Exiting...\n";
            break;
        }
    }
    return 0;
}
