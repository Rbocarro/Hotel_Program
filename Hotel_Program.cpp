#include"iostream"
#include"string"
#include"fstream"
#include"conio.h"
#include"iomanip"
using namespace std;
static const unsigned short ROOM_SIZE = 10;
string HotelRooms[ROOM_SIZE] = {"Leo Whitefang","Ramlethal Valentine","Ky Kiske","Millia Rage","Chipp Zanuff","Giovanna","Potemkin","Axl Low","Nagoriyuki","Faust"};

void DisplayAllRooms()
{   
    cout << "Room No" << "  Guest Name" << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i <(sizeof(HotelRooms)/sizeof(HotelRooms[0])); i++) 
    {
        cout << setw(2) <<i+1<<setw(10)<<" "<< HotelRooms[i]<<endl;
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
    cout << "Which room do you want to add a guest in?";
    cin >> userGuestRoomInput;
    cin.ignore();
    cout << "Addguest name:";
    getline(cin, HotelRooms[userGuestRoomInput-1]);  
}

void RemoveGuest()
{
    int userGuestRoomInput;
    cout << "Which room do you want vacate a guest a guest in?";
    cin >> userGuestRoomInput;
    cout << "\nRemoved "<< HotelRooms[userGuestRoomInput-1]<<" From Room "<< userGuestRoomInput<<endl;
    HotelRooms[userGuestRoomInput-1] = "e";  
}
void DisplayEmptyRooms()
{
    int emptyCount=0;
    cout << "Room No" << "  Guest Name" << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < (sizeof(HotelRooms) / sizeof(HotelRooms[0])); i++)
    {   
        if (HotelRooms[i] == "e")
        {
            cout <<setw(2)<< i + 1 <<setw(10)<< " " << HotelRooms[i] << endl;
            emptyCount++;
        }
    }
    if (emptyCount == 0)
    {
        cout << "none of the rooms are empty"<<endl;
    }

}

void FindGuestbyName()
{
    string guestName;
    cout << "Enter guest name to find:";
    //cin.ignore();
    getline(cin, guestName);
    cout << "Finding"<<guestName<<endl;
    for (int i = 0; i < (sizeof(HotelRooms) / sizeof(HotelRooms[0])); i++)
    {
        if (HotelRooms[i] == guestName)
        {
            cout << "Guest " << HotelRooms[i] << " Found in Room: " << i<<endl;
            
        }
    }
    
}

void SortGuestByName()
{
    string SortedGuestList[ROOM_SIZE][2];

        for (int i = 0; i < ROOM_SIZE; i++)
        {

            SortedGuestList[i][0] = HotelRooms[i];
            SortedGuestList[i][1] = to_string(i);;
        }


        string tempName;
        string tempRoomNo;

        for (int i = 0; i < ROOM_SIZE; i++)
        {
            for (int j = 1; j < ROOM_SIZE; j++)
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
        cout << "Room No" << "  Guest Name" << endl;
        cout << "---------------------------" << endl;
        for (int i = 0; i < ROOM_SIZE; i++)
        {
            cout << SortedGuestList[i][1] << "        " << SortedGuestList[i][0] << endl;
        }

}

void SaveToGuestListFile()
{
    ofstream GuestList("GuestList.txt");
    
    string GuestName = "";
    if (GuestList.is_open())
    {
        cout << "can Write!\n";


        for(int i = 0; i < (sizeof(HotelRooms) / sizeof(HotelRooms[0])); i++)
        {
            GuestName = HotelRooms[i];
                //GuestList>> HotelRooms[count];
                GuestList << GuestName<<"\n";
            

        }
        cout << "done Write!\n";
    }

    GuestList.close();
}

void ReadFromGuestListFile()
{
   ifstream GuestList("GuestList.txt");
   int count = 0;
   string GuestName="";
   if (GuestList.is_open())
   {
       cout << "can read!\n";

       
       while (!GuestList.eof())
       {
           //GuestList>> HotelRooms[count];
           getline(GuestList,GuestName);
           HotelRooms[count] = GuestName;
           count++;
       }
       cout << "done read!\n";
   }

   GuestList.close();
}



int main()
{
    
    bool isProgramRunning=true;

    while (isProgramRunning)
    {   
        system("cls");
        char UserInput;
        cout << "Hotel Program" << endl;
        cout << "Please choose an option:\n"
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
        UserInput = tolower(_getch()); cout << endl;
        
        switch (UserInput)
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
        char continueChoice;
        cout << "Perform another action? (press n to exit): ";
        continueChoice = tolower(_getch()); cout << endl;
        if (continueChoice != 'n')
        {
            continue;
        }
        else 
        {
            isProgramRunning = false;
        }
    }
    return(0);
}
