#include "linkedListHelpers.h"
#include <iostream>
#include <stack>

using namespace std;

// 1->2->1

// When we don't know the length
bool isPalindrome(Node* head)
{
    stack<int> valStack;
    Node* slow = head;
    Node* fast = head;

    while (slow != nullptr && fast->next != nullptr)
    {
        valStack.push(slow->value);
        fast = fast->next->next;
        slow = slow->next;
    }

    if (fast != nullptr)
    {
        // Ignore the middle element in odd sized lists
        slow = slow->next;
    }

    while(slow != nullptr)
    {
        int val = valStack.top();
        valStack.pop();

        if (val != slow->value)
        {
            return false;
        }

        slow = slow->next;
    }

    return true;
}

// When we know the length
bool isPalindrome(Node* head, int size)
{
    if (head == nullptr || size == 0)
    {
        return false;
    }
    if (size == 1)
    {
        return true;
    }

    stack<int> valStack;
    int middle = size / 2;
    bool isOddSize = size % 2 != 0;
    Node* curr = head;
    for (int i = 0; i < size; ++i)
    {
        if (i < middle)
        {
            valStack.push(curr->value);
        }
        else if (i == middle && isOddSize)
        {
            // do nothing
        }
        else 
        {
            int val = valStack.top();
            valStack.pop();
            if (val != curr->value)
            {
                return false;
            }
        }

        curr = curr->next;
    }

    return true;
}

int main()
{
    vector<int> vec = {1,0,1,0,1};
    Node* list = vectorToLinkedList(vec);
    
    cout << isPalindrome(list, 5) << endl;
    cout << isPalindrome(list) << endl;

    vec = {1,2,1,0,1};
    list = vectorToLinkedList(vec);
    
    cout << isPalindrome(list, 5) << endl;
    cout << isPalindrome(list) << endl;
}
