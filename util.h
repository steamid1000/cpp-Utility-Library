#pragma once
#include "bits/stdc++.h"

namespace util
{
    template <typename T>
    void swap(T arr[], int i, int j) //^ a simple swapping function
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    //& block of the linked list class and fucntion
    class linkedList //^ I will add the support for other types using template soon
    {

    public:
        int val;
        linkedList *next;

        linkedList() {}

        linkedList(int dat) // creating the first node
        {
            val = dat;
            next = NULL;
        }

        void insert(linkedList *&head, int val) // simple insert function for the linked list
        {
            linkedList *n = new linkedList(val);
            if (head == NULL)
            {
                head = n;
                return;
            }

            linkedList *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = n;
        }
    };

    void displayLinkedList(linkedList *head) // displays the linked list
    {
        while (head != NULL)
        {
            std::cout << head->val << "->";
            head = head->next;
        }

        std::cout << "NULL\n";
    }

    void reverseLL(linkedList *&head) //^ fucntion reverses the linked list in place
    {
        linkedList *prev = NULL;
        linkedList *temp = NULL;
        linkedList *&current = head;

        while (current != NULL)
        {
            temp = current->next; // stores the address of the next node
            current->next = prev; // currents-> will be null
            prev = current;       // prev = current node
            current = temp;       // current will be the next node
        }

        head = prev;
    }

    bool isPalin(std::string input) //^ function to check if a given string is palindrome or not
    {
        int j = input.length() - 1;

        for (int i = 0; i < input.length() / 2; i++)
        {
            if (input[i] != input[j])
                return false;

            j--;
        }

        return true;
    }

    //^ Return true if a palindrome string can be made by re-organizing the given string
    bool canBePalindrome(std::string input)
    {
        std::unordered_map<char, int> occurence;

        for (int i = 0; i < input.length(); i++) //^ Recording the number of occurence of each character
        {
            if (occurence.find(input[i]) == occurence.end())
            {
                occurence.insert(std::make_pair(input[i], 1));
            }
            else
            {
                occurence[input[i]]++;
            }
        }

        //^ If number of odd occurence characters are greater than 1 then we cant make a palindrome out of it

        int oddCharacters = 0;
        int evenCharacters = 0;

        for (auto iter : occurence)
        {
            (iter.second % 2 == 0) ? evenCharacters++ : oddCharacters++;
        }

        if (oddCharacters > 1)
        {
            return false;
        }

        return true;
    }

}

namespace util::sortingAlgorithms
{

    void bubble_sort(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            short swaped = 0; //& will check the number of swaps, if 0 then break
            for (int j = 0; j < size - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr, j, j + 1);
                    swaped++;
                }
            }

            if (swaped == 0)
            {
                return;
            }
        }
    }

    void insertionSort(int arr[], int size, char order = 'a') //^ takes an extra paramater to sort in ascending or desecending order
    {
        for (int i = 1; i < size; i++)
        {
            int temp = arr[i];
            int j = i - 1;
            if (order == 'a')
            {
                while (temp < arr[j] and j >= 0)
                {
                    arr[j + 1] = arr[j];
                    j--;
                }
            }
            else
            {
                while (temp > arr[j] and j >= 0)
                {
                    arr[j + 1] = arr[j];
                    j--;
                }
            }

            arr[j + 1] = temp;
        }
    }

}

namespace util::ArrayFunctions{
template <typename T>
void displayArray(T arr[], int size = 0) //^ displays the array on console
{

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

template <typename T>
bool SearchInArray(T arr[], int size, T element) //^ Can generally be used for int,string and char Arrays or their smaller sub-Arays
{                                                //^ which can be determined by the size you give for searching.
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return true;
        }
    }

    return false;
}

template <typename T>
void displayVector(std::vector<T> vec) //^ Can display vectors of general types
{
    for (auto i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}
}