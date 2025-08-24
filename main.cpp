#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <filesystem>
using namespace std;
// CS210 Project Three
// Bryant Cole
// 8/14/2025

class menuPrint { //class for printing out the menu in main
    public:
    void printMenu();
    
    private:
    string menu = "";
    
};
void menuPrint::printMenu() { //definition of member function
        menu.append("*******Corner Grocer*******\n");
        menu.append(" Pick a menu option 1-3. 4 exits the program.\n\n");
        menu.append(" Option 1: Enter the item you want to search and we'll tell you how many have been purchased.\n\n");
        menu.append(" Option 2: The frequency of all items purchased arranged in a list.\n\n");
        menu.append(" Option 3: Like option 2, but the frequency of all items purchased will be arranged in a histogram.\n\n");
        menu.append(" Option 4: Prompt exit of the program..\n\n");
        
        cout << menu;
    }


int findFromBackup(const string& query, const string& path = "frequency.dat") { //// Looks through our backup files and returns the count for each item.
    ifstream in(path); // Opens the backup file 
    if (!in.is_open()) return 0;// returns from the function if open fails and returns 0

    string name; // name for item
    int count; //count for frequency
    while (in >> name >> count) {
        if (name == query) return count; //count from backup file returned only used as a backup
    }
    return 0; // not found
}
string starz(int num) { // stars variable that takes a paraments int num from the item count
    string temp = ""; //variable used to append asteriks based on the item count for a histogram 
    for (int i = 0; i < num; i++)  // for loop for iteration based on num from items
        temp.append("*"); //Asteriks added for histogram
    return temp; // returns the number of asteriks that were appended
}


int main()
{
    string item;//items to be counted   
    map<string, int> freq; //mapping to hold item frequencies
    int num = 0; // num initialized to zero for item counting
    
    ifstream InputStream;//Opens Project 3 input file for item counting 
    InputStream.open("CS210_Project_Three_Input_File.txt");//test files opened
    
   if (!InputStream.is_open()) { //if IS cannot be opened
        cout << "Error: Unable to open file." << endl; //Tells user that input stream cannot be opened
        return 1; 
    }
     
    while (getline(InputStream, item)) { // reading each line from file
        if (!item.empty() && item.back() == '\r') { //so loop doesnt overwrite first character of word
            item.pop_back();
        }
        if (item.empty()) continue; //will skip blank lines 
        ++freq[item]; //increment the count for item
        
    }
    
    //backup file frequency.dat
    ofstream out("frequency.dat"); //opens file for output if it doesnt exist it is created
    if (!out.is_open()) { // if file cannot be opened, it will be said
        cout << "Could not create frequency.dat" << endl; //tells user we cannot open
    } else { 
        for (const auto& kv : freq) {
            out << kv.first << ' ' << kv.second << '\n'; //write to the file
        }
       
       out.close(); //flushes data and releases the file
       
        }
        
    menuPrint menu; //creates object menu from menuPrint class
    menu.printMenu(); //calls method printMenu()
    
    cin >> num; //console input integer for feed from user
    
    while (num != 4) { // Loop will continue until the user puts 4 which exits the program
    
        if (num == 1) {
        cout << "Enter item to search for." << endl;// num == 1 lists items to search and prints frequency.
        string temp = "";// temp is empty for user to lookup specific item
        int num_temp = 0; //num_temp is empty for number of items for each item to be recorded
        cin >> temp;// user input for menu option
        num_temp = findFromBackup(temp); //Goes through list and looks for parameter
        //Prints item name that user looked up and number of times it appears
        cout << temp << ": " << num_temp << endl;
        }
        
        else if (num == 2) {// Frequency of items purchased arranged in a list
            ifstream in;
            in.open("frequency.dat");
            if (!in.is_open())// if "in" is not open
                cout << "Frequency could not open." << endl;
                else {
                    for (const auto& kv : freq) {
                        cout << kv.first << ' ' << kv.second <<'\n';
                    }
                    
                }
                in.close();// closes the backup file stream
        }
    
        else if (num == 3) { // Frequency of items purchased arranged in a histogram
            ifstream in;
            in.open("frequency.dat");
            if (!in.is_open())
                cout << "Frequency could not open." << endl;
                else {
                    for (const auto& kv : freq) {
                        cout << kv.first << ' ' << starz(kv.second) <<'\n'; //write to the file and prints out number in asteriks
                    }
                    
                }
        }
        
        else if (num == 4) { //breaks out of loop and exits program
            break;
        }
        cout << "Thank you! Have a nice day!" << endl; //prints after every loop
        cin >> num;//makes sure user can always input menu option
    }
    
    
    return 0;
}


