#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ifstream file ("name.txt");

    // Handle is file open or not.
    if(file.is_open())
    {
        cout << "Reading success!\n\n";
    }

    // Input Method 1.
    /* vector<string> names;

    string input; // Or char type.

    while(file >> input) // return file.
    {
        names.push_back(input);
    }
    
    for(auto //string name : names) // Range base for loop. You can enter data type or use auto to automatically identify.
    {
        cout << name << endl;
    } */

    // Input Method 2 with get().
    /* char temp = file.get();
    cout << temp << endl; */

    // Input function 3 with getline().
    string line;
    getline(file, line);
    cout << line << endl;;
    return 0;
}