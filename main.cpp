#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

// Comment #1: Define a constant for the maximum number of GPA entries.
const int MAX_GPA_COUNT = 35;

void readGPAsFromFile(vector<double>&);
void outputGPAs(const vector<double>&);
void swapGPAs();
void fillGPAs();
bool findGPA(const vector<double>&, double);

int main()
{
    // Comment #2: Declare an array to hold GPA values.
    vector<double> gpaList;

    // Comment #3: Read GPA values from the file into the array.
    readGPAsFromFile(gpaList);

    // Comment #4: Output the GPA values to the console.
    outputGPAs(gpaList);

    // Comment #5: Check if the GPA list is empty and output the result.
    cout << endl << "Is the GPA list empty? " << (gpaList.empty() ? "Yes" : "No") << endl;

    cout << "Front: " << gpaList.front() << endl;
    cout << "Back: " << gpaList.back() << endl;

    cout << endl << "Sorting the GPA list in the descending order." << endl;
    sort(gpaList.rbegin(), gpaList.rend());
    outputGPAs(gpaList);

    cout << endl << "Sorting the GPA list in the ascending order." << endl;
    sort(gpaList.begin(), gpaList.end());
    outputGPAs(gpaList);

    cout << endl << "Swapping two GPA lists." << endl;
    swapGPAs();

    cout << endl << "Filling the GPA list with 4.0." << endl;
    fillGPAs();

    cout << endl << "Finding a GPA in the list." << endl;
    double gpaToFind = 3.75;
    cout << "Is " << gpaToFind << " in the GPA list? " 
         << (findGPA(gpaList, gpaToFind) ? "Yes" : "No") << endl;

    cout << endl << "STD::Array data: " << gpaList.data() << endl;

    return 0;
}

// Comment #6: Function to read GPA values from a file into the gpaList array.
void readGPAsFromFile(vector<double>& gpaList)
{
    // Comment #7: Open the input file.
    ifstream inputFile("gpas.txt");
    
    // Comment #8: Read GPA values from the file into the array.
    for (int i = 0; i < gpaList.size(); ++i)
    {
        inputFile >> gpaList[i];
    }

    // Comment #9: Close the input file.
    inputFile.close();
}

void outputGPAs(const vector<double>& gpaList)
{
    // Comment #10: Output the GPA values to the console.
    for (int i = 0; i < gpaList.size(); ++i)
    {
        cout << fixed << setprecision(2) << gpaList.at(i) << endl;
    }
}

void swapGPAs()
{
    /* vector<double> gpaList1 = {3.5, 3.7, 3.9, 4.1};
    vector<double> gpaList2 = {2.5, 2.7, 2.9, 3.1};

    cout << "Before swap:" << endl;
    for (int i = 0; i < gpaList1.size(); ++i) cout << gpaList1[i] << " ";
    cout << endl;
    for (int i = 0; i < gpaList2.size(); ++i) cout << gpaList2[i] << " ";
    cout << endl;

    // Comment #11: Swap the contents of the two GPA lists.
    gpaList1.swap(gpaList2);

    cout << "After swap:" << endl;
    for (int i = 0; i < gpaList1.size(); ++i) cout << gpaList1[i] << " ";
    cout << endl;
    for (int i = 0; i < gpaList2.size(); ++i) cout << gpaList2[i] << " ";
    cout << endl; */
}

void fillGPAs()
{
    vector<double> gpaList(4);

    // Comment #12: Fill the GPA list with the value 4.
    fill(gpaList.begin(), gpaList.end(), 4);
    for (int i = 0; i < gpaList.size(); ++i) cout << gpaList[i] << " ";
    cout << endl;
}

bool findGPA(const vector<double>& gpaList, double gpa)
{
    for (int i = 0; i < gpaList.size(); ++i)
    {
        // Comment #13: Check if the specified GPA exists in the list.
        if (gpa == gpaList[i]) return true;
    }

    return false;
}