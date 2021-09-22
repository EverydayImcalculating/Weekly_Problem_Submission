#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main() 
{
    cout << "Enter your file name : ";
    string filename;
    cin >> filename; 

    ofstream textfile (filename.c_str(), ios::app); // std::ios::app Continue write not overwrite. 
    // If you want to overwrite just remove std::ios::app.
    // Basically way to open file is file.open()
    if (textfile.is_open())
    {
        cout << "Write Success.\n";
    } else 
    {
        cout << "Error cannot access the file!\n";
    }

    vector<string> names;
    names.push_back("Ford");
    names.push_back("Oey");
    names.push_back("Nui");

    for(string name : names)
    {
        textfile << name << endl;
    }

    textfile.close();
    return 0;
}