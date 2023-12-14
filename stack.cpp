#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cctype>

using namespace std;

bool isPalindrome(string word) {
    stack<char> charStack;
    queue<char> charQueue;

    // Convert the word to lowercase (ignore case)
    for (char& c : word) {
        c = tolower(c);
    }

    // Push characters onto the stack and enqueue them into the queue
    for (char c : word) {
        if (isalpha(c)) {
            charStack.push(c);
            charQueue.push(c);
        }
    }

    // Pop characters from the stack and dequeue characters from the queue and compare
    while (!charStack.empty() && !charQueue.empty()) {
        if (charStack.top() != charQueue.front()) {
            return false; // Not a palindrome
        }
        charStack.pop();
        charQueue.pop();
    }

    return true; // Palindrome
}

int main() {
    string word;

    cout << "Enter a word to check if it's a palindrome: ";
    cin >> word;

    if (isPalindrome(word)) {
        cout << word << " is a palindrome." << endl;
    } else {
        cout << word << " is not a palindrome." << endl;
    }

    return 0;
}

