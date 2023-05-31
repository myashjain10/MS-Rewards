#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string filename = "list.txt";
    ifstream file(filename);
    string firstword;
    file >> firstword;

    // Open the same file for writing
    ofstream outfile(filename);

    // Write the rest of the file to the same file
    outfile << file.rdbuf();

    // Close both files
    file.close();
    outfile.close();

    cout << "The first word has been removed from the file." << endl;

    
    int len = firstword.length();

    ofstream curfile("currentlist.txt");

    for (int i = len - 1; i >= 0; i--)
    {
        firstword.erase(i, 1);
        curfile << firstword << endl;
    }

    curfile.close();
    system("powershell.exe -ExecutionPolicy Bypass -File RunBingSearch.ps1");
    string just;
    cin >> just;
    return 0;
}
