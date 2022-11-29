#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------


bool cmp1(int value) {
    return value <= 12;
}

bool cmp2(int value) {
    return value == 12;
}

bool cmp3(int value) {
    return value % 2 == 0;
}

int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }
    //std::cout<<"1"<<std::endl;
    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------

    cout << "------------test llpivot------------" << endl;
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);
    Node *smaller = nullptr, *larger = nullptr;

    llpivot(head, smaller, larger, 0);
    cout << "pivot = " << 0 << endl;
    cout << "head list: ";
    print(head);
    cout << "smaller list: ";
    print(smaller);
    cout << "larger list: ";
    print(larger);

    dealloc(head);
    dealloc(smaller);
    dealloc(larger);
    head = smaller = larger = nullptr;

    head = readList(argv[1]);
    cout << "\nOriginal list: ";
    print(head);

    llpivot(head, smaller, larger, 10);
    cout << "pivot = " << 10 << endl;
    cout << "head list: ";
    print(head);
    cout << "smaller list: ";
    print(smaller);
    cout << "larger list: ";
    print(larger);

    dealloc(head);
    dealloc(smaller);
    dealloc(larger);
    head = smaller = larger = nullptr;

    head = readList(argv[1]);
    cout << "\nOriginal list: ";
    print(head);

    llpivot(head, smaller, larger, 20);
    cout << "pivot = " << 20 << endl;
    cout << "head list: ";
    print(head);
    cout << "smaller list: ";
    print(smaller);
    cout << "larger list: ";
    print(larger);

    dealloc(head);
    dealloc(smaller);
    dealloc(larger);
    head = smaller = larger = nullptr;
    

    cout << "\n\n------------test llfilter------------" << endl;
    head = readList(argv[1]);
    cout << "Original list: ";
    print(head);
    head = llfilter(head, cmp1);
    cout << "test cmp1: ";
    print(head);
    dealloc(head);
    head = nullptr;

    head = readList(argv[1]);
    cout << "\nOriginal list: ";
    print(head);
    head = llfilter(head, cmp2);
    cout << "test cmp2: ";
    print(head);
    dealloc(head);
    head = nullptr;

    head = readList(argv[1]);
    cout << "\nOriginal list: ";
    print(head);
    head = llfilter(head, cmp3);
    cout << "test cmp3: ";
    print(head);
    dealloc(head);
    head = nullptr;

    return 0;
}