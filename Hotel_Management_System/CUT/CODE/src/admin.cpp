#include<iostream>
#include<vector>
#include<fstream>
#include <sstream>
//#include<cstring>
#include<string>
#include <unistd.h>
#include"header.h"
using namespace std ;

int admin_login()
{
        fstream file ;
        string buffer , test;

        string name , password ;

        std::vector<std::string> splittedStrings ;

        file.open("admin_file.txt",ios::in) ;
        if(!file)
        {
                cout<<"File opening is error \n";
                return 0 ;
        }
        else
        {
                //cout<<"admin_file.txt is opened successfully\n" ;
        }
          while(getline(file , buffer))
          {
                        splittedStrings = split(buffer ,',');
          }


          cout<<"Enter Admin Name \n";
          cin>>name ;

          password  = getpass("Enter the password:");

           if(name == splittedStrings[0])
          {
                if(password == splittedStrings[1])
                {
                        return 1;
                }
                else
                        return 0;
          }
          else
                return 0 ;


}

vector<room> admin_function(vector<room> room_object , vector<Customer> &customer_object  )
{
        int ch , exit_flag = 0;


        Room room_data ;
        Customer customer ;
        design('*');
        cout<<"----------"<<"WELCOME TO ADMIN MODULE"<<"------------------"<<"\n";
        design('*');
        while(1)
        {
                cout<<"1) Add The room\n";
                cout<<"2) Display Avilable room\n";
                cout<<"3) Modify The Room\n";
                cout<<"4) View Customer\n";
                cout<<"5) Search Customer\n";
                cout<<"6) Exit\n";

                cin>>ch ;

                switch(ch)
                {
                        case 1:room_data = room_data.addroom(room_data);
                                room_object.push_back(room_data);
                                break;
                        case 2:
                                system("clear");
                                room_data.display_room(room_object);
                                break;

                        case 3:
                                system("clear");
                                room_object = room_data.modify_room_details(room_object);
                                break ;

                        case 4:
                                system("clear");
                                 customer.view_customer(customer_object);
                                break ;
                        case 5:
                                system("clear");
                                customer.search_customer(customer_object);
                                break ;

                        case 6:
                                exit_flag = 1;

                }

                if(exit_flag == 1)
                break ;
        }

        return room_object ;
}

Room Room::addroom(Room room_data)
{

        ofstream file ;

        file.open("Room_information.txt",ios::app) ;
        if(!file)
        {
                cout<<"File opening is error \n";

        }
        else
        {
                //cout<<"Room_information.txt is opened success\n" ;
        }

        cout<<"enter the room number\n";
        cin>>room_data.room_number ;
        file<<room_data.room_number<<",";
        cout<<"Enter Type Ac/NON-AC (A/N) : \n ";
        cin>>room_data.ac ;
        file<<room_data.ac<<",";
        cout<<"Enter Type Comfort (S/N) : \n";
        cin>>room_data.type ;
        file<<room_data.type<<",";
        cout<<"Enter Type Size (D/S) : \n";
        cin>>room_data.stype ;
        file<<room_data.stype<<",";
        cout<<"Enter Daily Rent : \n";
        cin>>room_data.rent ;
        file<<room_data.rent<<",";

        room_data.status = 0 ;
        file<<room_data.status;
        file<<"\n";
        cout<<"\nRoom Added Successfully ! \n";

        file.close();

        return room_data;
}

void Room ::display_room(vector<Room> room_object)
{
       design('*');

                for (auto i = room_object.begin(); i != room_object.end(); ++i)
                {

                        if(i->status == 0)
                        {
                                cout <<"Room Number ::"<< i->room_number << "\n";

                                if(i->ac == 'a' || i->ac == 'A')
                                        cout<<"AC-ROOM "<<"\n";
                                else
                                        cout<<"NON-AC ROOM"<<"\n";

                                if(i->type == 'S' ||i->type == 's' )
                                        cout<<"STANDARD ROOM\n";
                                else
                                        cout<<"NON - STANDARD ROOM\n";

                                if(i->type == 'D' ||i->type == 'D' )
                                        cout<<"DOUBLE SHARING \n";
                                else
                                        cout<<"SINGLE SHARING \n";
                                cout<<"Rent Per Day ::"<<i->rent<<"\n" ;

                        }
                        else
                        {
                                cout <<"Room Number ::"<<i->room_number << "\n";
                                cout<<"Room is already Booked \n";
                        }
                }

         design('*');
}

vector<Room> Room ::modify_room_details(vector<Room> room_object)
{
     int room_no , check_flag = 0;

        char ch ;

         vector<Room>::iterator i;


        cout<<"enter the room number\n";
        cin>>room_no ;
        for (i = room_object.begin(); i != room_object.end(); ++i)
        {
                if(i->room_number == room_no )
                {
                        check_flag = 1;
                        cout <<"Room Number ::"<< i->room_number << "\n";
                        if(i->ac == 'a' || i->ac == 'A')
                                cout<<"AC-ROOM "<<"\n";
                        else
                                cout<<"NON-AC ROOM"<<"\n";
                        cout<<"Rent Per Day ::"<<i->rent<<"\n";
                        if(i->status == 0)
                                cout<<"Room is Available"<<"\n";
                        else
                                cout<<"Room is Booked"<<"\n";


                        cout<<"Enter y to modify\n";
                        cin>>ch ;
                        if(ch == 'y' || ch == 'Y')
                        {
                                cout<<"Enter Type Ac/NON-AC (A/N) : \n ";
                                cin>>i->ac ;
                                cout<<"Enter Type Comfort (S/N) : \n";
                                cin>>i->type ;
                                cout<<"Enter Type Size (D/S) : \n";
                                cin>>i->stype ;
                                cout<<"Enter Daily Rent : \n";
                                cin>>i->rent ;
                        }
                }
        }

        return room_object ;
}

std::vector<std::string> split(std::string strToSplit, char delimeter)
{
    int num ;
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delimeter))
    {

         splittedStrings.push_back(item);
    }
    return splittedStrings;
}

vector<Room> Room ::create_vector_for_room_info(vector<Room> room_object)
{
        fstream file ;
        string buffer , test;
        Room DataFromFile;

        std::vector<std::string> splittedStrings ;

        file.open("Room_information.txt",ios::in);
        if(!file)
        {
                cout<<"file opening is error\n";
        }
        else
        {
                cout<<"file reading is success\n";
                while(getline(file , buffer))
                {
                        splittedStrings = split(buffer ,',');
                        if(splittedStrings.size() ==  6)
                        {

                                DataFromFile.room_number = stoi(splittedStrings[0]) ;
                                //cout<<"DataFromFile.room_number"<<DataFromFile.room_number <<"\n";

                                 DataFromFile.ac     =     splittedStrings[1][0];
                                 DataFromFile.type   =     splittedStrings[2][0];
                                 DataFromFile.stype  =     splittedStrings[3][0];
                                 DataFromFile.rent   =     stoi(splittedStrings[4]);
                                 DataFromFile.status =     stoi(splittedStrings[5]);

                                 room_object.push_back(DataFromFile);
                        }
                }
        }

        return room_object ;
}
