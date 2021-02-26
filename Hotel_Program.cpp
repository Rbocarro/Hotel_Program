#include"iostream"
#include"string"
#include"fstream"
#include"conio.h"
using namespace std;

static const int ROOM_SIZE = 10;
string HotelRooms[ROOM_SIZE] = {"Leo Whitefang","Ramlethal Valentine","Ky Kiske","Millia Rage","Chipp Zanuff","Giovanna","Potemkin","Axl Low","Nagoriyuki","Faust"};

void DisplayAllRooms()
{   

    cout << "Room No" << "  Guest Name" << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i <(sizeof(HotelRooms)/sizeof(HotelRooms[0])); i++) 
    {
        cout <<i<<"        "<< HotelRooms[i]<<endl;
        
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
    //Initiliaze();
    int userGuestRoomInput;
    string guestName;
    cout << "Which room do you want to add a guest in?";
    cin >> userGuestRoomInput;
    cin.ignore();
    cout << "Addguest name:";
    getline(cin, HotelRooms[userGuestRoomInput]);
    //HotelRooms[userGuestRoomInput] = guestName;
    //cout <<"Guest:"<<guestName<<"was added in room "<<userGuestRoomInput<<endl
       
}

void RemoveGuest()
{
    int userGuestRoomInput;
    cout << "Which room do you want vacate a guest a guest in?";
    cin >> userGuestRoomInput;
    cout << "\nRemoved "<< HotelRooms[userGuestRoomInput]<<" From Room "<< userGuestRoomInput<<endl;
    HotelRooms[userGuestRoomInput] = "e";  
}
void DisplayEmptyRooms()
{
    cout << "Room No" << "  Guest Name" << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < (sizeof(HotelRooms) / sizeof(HotelRooms[0])); i++)
    {   
        if (HotelRooms[i] == "e")
        {
            cout << i << "        " << HotelRooms[i] << endl;
        }
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
        int UserInput;
        cout << "Hotel Program" << endl;
        cout << "Please choose an option:\n"
            << "1. View all rooms\n"
            << "2. Initialise guest list to empty\n"
            << "3. Add customer to room\n"
            << "4. Display empty Rooms\n"
            << "5. Delete Customer from Room\n"
            << "6. Find room from customer names\n"
            << "7. Store Program Data into file\n"
            << "8. Load Program Data from File\n"
            << "9. View Rooms ordered from customer's name\n\n"
            << "Please Enter your Choice:";

        UserInput=_getch()-48;//idk why but it seems to retunr the acii decimal vaule of numbers
        cout << UserInput << endl;
        switch (UserInput)
        {
        case 1:
            DisplayAllRooms();
            break;
        case 2:
            Initiliaze();
            break;
        case 3:
            AddGuest();
            break;
        case 4:
            DisplayEmptyRooms();
            break;
        case 5:
            RemoveGuest();
            break;
        case 6:
            FindGuestbyName();
            break;
        case 7:
            SaveToGuestListFile();
            break;
        case 8:
            ReadFromGuestListFile();
            break;
        case 9:
            SortGuestByName();
            break;

        default:
            cout << "Wrong Input";
            break;
        }
        char continuechoice;
        cout << "Perform another action?y/n:";
        continuechoice=_getch(); cout << continuechoice;
        if (continuechoice != 'n')
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
