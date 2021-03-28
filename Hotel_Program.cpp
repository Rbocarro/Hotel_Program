// Hotel Program by Reuben Bocarro studnet no:17868017
#include"iostream"
#include"string"
#include"fstream"
#include"conio.h"
#include"iomanip"
using namespace std;
static const unsigned short NO_OF_ROOMS = 10;
string HotelRooms[NO_OF_ROOMS] = {"Leo Whitefang","Ramlethal Valentine","Ky Kiske","Millia Rage","Chipp Zanuff","Giovanna","Potemkin","Axl Low","Nagoriyuki","Faust"};

void DisplayAllRooms()
{   
    cout << "Room No" << "     Guest Name" << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i <(sizeof(HotelRooms)/sizeof(HotelRooms[0])); i++) 
    {
        cout << setw(7) <<i+1<<setw(5)<<" "<< HotelRooms[i]<<endl;
    }
}

void Initiliaze()
{
    for (int i = 0; i < (sizeof(HotelRooms) / sizeof(HotelRooms[0])); i++)
    {
        HotelRooms[i] = "e";
    }
    cout<<"guestList Initialised\n";
}

void AddGuest()
{   
    int userGuestRoomInput;
    cout << "Which room do you want to add a guest in?(1-10)";
    cin >> userGuestRoomInput;
    cin.ignore();
    cout << "Add guest name:";
    getline(cin, HotelRooms[userGuestRoomInput-1]);  
}

void RemoveGuest()
{
    int userGuestRoomInput;
    cout << "Which room number do you want vacate a guest a guest in?(1-10):";
    cin >> userGuestRoomInput;
    cout << "\nRemoved "<< HotelRooms[userGuestRoomInput-1]<<" From Room "<< userGuestRoomInput<<endl;
    HotelRooms[userGuestRoomInput-1] = "e";  
}
void DisplayEmptyRooms()
{
    bool emptyCount=false;
    cout << "Room No" << "    Guest Name" << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < (sizeof(HotelRooms) / sizeof(HotelRooms[0])); i++)
    {   
        if (HotelRooms[i] == "e")
        {
            cout <<setw(7)<< i + 1 <<setw(5)<< " " << HotelRooms[i] << endl;
            emptyCount=true;
        }
    }
    if (!emptyCount)
        cout << "none of the rooms are empty"<<endl;
}

void FindGuestbyName()
{
    string guestName;
    bool guestFound=false;
    cout << "Enter guest name to find:";
    //cin.ignore();
    getline(cin, guestName);
    cout << "Finding "<<guestName<<endl;
    for (int i = 0; i < (sizeof(HotelRooms) / sizeof(HotelRooms[0])); i++)
    {
        if (HotelRooms[i] == guestName)
        {
            cout << "Guest " << HotelRooms[i] << " Found in Room: " << i+1<<endl;
            guestFound=true;
            
        }
    }
    if (!guestFound)
        cout<< "Guest " << guestName << " could not be found  " <<endl;    
}

void SortGuestByName()
{
    string SortedGuestList[NO_OF_ROOMS][2],
           tempName,
           tempRoomNo;
        for (int i = 0; i < NO_OF_ROOMS; i++)
        {
            SortedGuestList[i][0] = HotelRooms[i];
            SortedGuestList[i][1] = to_string(i);;
        }
    
        for (int i = 0; i < NO_OF_ROOMS; i++)
        {
            for (int j = 1; j < NO_OF_ROOMS; j++)
            {
                if (SortedGuestList[j - 1][0] > SortedGuestList[j][0])
                {
                    tempName = SortedGuestList[j - 1][0];
                    tempRoomNo = SortedGuestList[j - 1][1];

                    SortedGuestList[j - 1][0] = SortedGuestList[j][0];
                    SortedGuestList[j - 1][1] = SortedGuestList[j][1];

                    SortedGuestList[j][0] = tempName;
                    SortedGuestList[j][1] = tempRoomNo;
                }
            }
        }
        cout << "Sorted Array\n";
        cout << "Room No" << "     Guest Name" << endl;
        cout << "---------------------------" << endl;
        for (int i = 0; i < NO_OF_ROOMS; i++)
        {
            cout <<setw(5)<< stoi(SortedGuestList[i][1])+1 <<setw(5)<<" " << SortedGuestList[i][0] << endl;
        }
}

void SaveToGuestListFile()
{
    ofstream GuestList("GuestList.txt");
    string GuestName = "";
    if (GuestList.is_open())
    {
        cout << "can write to file!\n";
        for(int i = 0; i < (sizeof(HotelRooms) / sizeof(HotelRooms[0])); i++)
        {
            GuestName = HotelRooms[i];
            GuestList << GuestName<<"\n";
        }
        cout << "done Writing to file!\n";
    }
    else  cout << "File Write Error!\n";

    GuestList.close();
}

void ReadFromGuestListFile()
{
   ifstream GuestList("GuestList.txt");
   int count = 0;
   string GuestName="";
   if (GuestList.is_open())
   {
       cout << "can read from file!\n";
       while (!GuestList.eof())
       {
           getline(GuestList,GuestName);
           HotelRooms[count] = GuestName;
           count++;
       }
       cout << "done reading from file!\n";
   }
   else  cout << "File Read Error!\n";
   GuestList.close();
}

int main()
{    
    bool isProgramRunning=true;

    while (isProgramRunning)
    {   
        system("cls");
        char userInput, continueChoice;
        cout << "Hotel Program" << endl
             << "Please choose an option:\n"
             << "V. View all rooms\n"
             << "I. Initialise guest list to empty\n"
             << "A. Add customer to room\n"
             << "E. Display empty Rooms\n"
             << "D. Delete Customer from Room\n"
             << "F. Find room from customer names\n"
             << "S. Store Program Data into file\n"
             << "L. Load Program Data from File\n"
             << "O. View Rooms ordered from customer's name\n\n"
             << "Please Enter your Choice:";
        userInput = tolower(_getch()); cout << endl;
        
        switch (userInput)
        {
        case 'v':
            DisplayAllRooms();
            break;
        case 'i':
            Initiliaze();
            break;
        case 'a':
            AddGuest();
            break;
        case 'e':
            DisplayEmptyRooms();
            break;
        case 'd':
            RemoveGuest();
            break;
        case 'f':
            FindGuestbyName();
            break;
        case 's':
            SaveToGuestListFile();
            break;
        case 'l':
            ReadFromGuestListFile();
            break;
        case 'o':
            SortGuestByName();
            break;
        default:
            cout << "Wrong Input\n";
            break;
        }
        cout << "Perform another action? (press n to exit): ";
        continueChoice = tolower(_getch()); cout << endl;
        if (continueChoice != 'n')
            continue;
        else 
            isProgramRunning = false;
    }
    return(0);
}
