#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *lcl;
    Node *rcl;
    Node(int data)
    {
        info = data;
        lcl = NULL;
        rcl = NULL;
    }
    Node();

    Node *createBT(Node *root)
    {
        Node *temp, *prev, *cur;
        char d[10];
        int i;
        temp = new Node;
        cout << "Element Value: ";
        cin >> temp->info;
        temp->lcl = NULL;
        temp->rcl = NULL;
        if (root == NULL)
        {
            return temp;
        }
        cout << "Direction";
        cin >> d;
        prev = NULL;
        cur = NULL;
        for (i = 0; (signed)i < (signed)strlen(d); i++)
        {
            if (cur == NULL)
            {
                break;
            }
            prev = cur;
            if (d[i] == 'L' || d[i] == 'l')
            {
                cur = cur->lcl;
            }
            else
            {
                cur = cur->rcl;
            }
        }
        if (cur != NULL || (signed)i != (signed)strlen(d))
        {
            cout << "Impossible";
            delete temp;
            return root;
        }
        if (d[i - 1] == 'L')
        {
            prev->lcl = temp;
        }
        else
        {
            prev->rcl = temp;
        }
        return root;
    }
};

int main()
{
    Node *root;
    Node temp;
    root = temp.createBT(root);
}