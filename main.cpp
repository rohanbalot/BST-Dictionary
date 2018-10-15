/***************************************

        => Dictionary using BST <=
        -> Rohan Balot 335/CO/15
        -> Sahil Gupta 338/CO/15
***************************************/

// C++ Headers
#include <iostream>
#include <iomanip>
#include <new>
#include <string>
#include <fstream>
#include <queue>

// C Headers
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cctype>


using namespace std;

// Defination for Binary Search Tree Node
struct node {
    char word[20];
    char meaning[40];
    node *left, *right;
    node() { }
    node(char *word, char *meaning) {
        strcpy(this->word, word);
        strcpy(this->meaning, meaning);
        this->left = this->right = NULL;
    }
 };


 // Insertion in Binary Search Tree
node* insert(node *root, char *word, char *mean)
{
    if(root == NULL) {
        return new node(word, mean);
    } else {
        if(strcmp(root->word, word) <= 0) {
            root->left = insert(root->left , word, mean);
        } else {
            root->right = insert(root->right, word, mean);
        }
    }
}


// Pre Order Traversal of Binary Search Tree
void preorder(node *root) {
    if(root) {
        cout << root->word << " => " << root->meaning << endl;
        preorder(root->left);
        preorder(root->right);
    }
}

// Inrder Traversal of Binary Search Tree
void inorder(node *root) {
    if(root) {
        inorder(root->left);
        cout << root->word << " => " << root->meaning << endl;
        inorder(root->right);
    }
}

// Post Order Traversal of Binary Search Tree
void postorder(node *root) {
    if(root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->word << " => " << root->meaning << endl;

    }
}

// Query in Binary Search Tree
void look(node *root, char *word) {
    if(root == NULL) {
        cout << "Not found !!\n";
        return;
    }
    if(strcmp(root->word, word) == 0) {
        cout << "Meaning is -> " << root->meaning << '\n';
    } else if(strcmp(root->word, word) < 0) {
        look(root->left, word);
    } else {
        look(root->right, word);
    }
}

// level order traversal for Binary Search Tree
void level(node *root) {
    queue< node* > q;
    q.push(root);
    while(!q.empty()) {
        cout << q.front()->word << " => " << q.front()->meaning << '\n';
        if(q.front()->left)
            q.push(q.front()->left);
        if(q.front()->right)
            q.push(q.front()->right);
        q.pop();
    }
}

int main()
{
    node *root = NULL;
    ifstream fin("data.txt", ios::in);
    char a[21], b[41];
    while(fin >> a) {
        fin.get(b, 40, '\n');
        root = insert(root, a, b);
    }

    /// traversals
    // preorder(root); cout << endl;
    // level(root); cout << endl;
    int ch = 1;
    do {
        printf("1. Enter Word for Query\n");
        printf("2. Enter new Word and Meaning\n");
        printf("3. Exit\n\t");
        cin >> ch;
        switch(ch) {
            case 1: char s[21];
                    // tolower(s);
                    cin >> s;
                    look(root, s);
                    break;
            case 2: cin >> a;
                    cin.get(b, 40, '\n');
                    root = insert(root, a, b);
                    cout << "Dictionary Successfully Updated !!\n";
                    break;
            case 3: exit(EXIT_SUCCESS);
                    break;
            default: cout << "Wrong Choice !!";
                    break;

        }
    } while(ch >= 1 && ch <= 2);
    return 0;
}
