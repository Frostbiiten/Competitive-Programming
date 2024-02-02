#include <iostream>
#include <string>
#include <ios>

using namespace std; 

int main () 
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t; 
    cin >> t; 

    for (int i = 0; i < t; ++i) 
    {
        string s; 
        cout << "feed 1\n"; 
        cin >> s; 
        cout << "feed 2\n"; 
        cin >> s; 
        cout << "feed 3\n"; 
        cin >> s; 
        cout << "feed 5\n"; 
        cin >> s; 
        cout << "feed 4\n"; 
        cin >> s; 
        
        cout << "poop\n"; 

        int j = stoi(s); 

        switch (j) {
            case 1:
                cout << "queueon\n"; 
                break;
            case 4:
                cout << "stackeon\n"; 
                break; 
            default:
                cout << "heapeon\n"; 
                break; 
        }

        cin >> s; 
        if (s == "WRONG_ANSWER") break; 
    }
}