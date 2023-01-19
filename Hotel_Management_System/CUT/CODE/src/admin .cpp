#include<iostream>
#include<vector>
#include<fstream>
#include <sstream>
#include<string>
#include <unistd.h>
#include"header.h"
using namespace std ;


/************************************************************************************************
 *
 *  * FUNCTION NAME           : admin_login()
 *
 *  * DESCRIPTION             : This function is for the admin login  by validating the credentials
 *
 *  * RETURN TYPE             : int
 *
 * *********************************************************************************************/


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
                //cout<<"admin_file.txt is opened success\n" ;
        }
	 while(getline(file , buffer))
          {
                        splittedStrings = split(buffer ,',');
          }


          cout
                  <<"Enter Admin Name \n";
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


/************************************************************************************************
 *
 *   * FUNCTION NAME           : admin_function()
 *
 *   * DESCRIPTION             : This function is for the functions by admin like add room,display room,
 *                               view customer,search customer,modify room
 *
 *   * RETURN TYPE             : vector<room>
 *
 *********************************************************************************************/


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
                cout<<"2) Display Available room\n";
                cout<<"3) Modify The Room\n";
                cout<<"4) View Customer\n";
                cout<<"5) Search Customer\n";
                cout<<"6) Exit\n";

                ch = int_ans_choice(1,6);

                switch(ch)
                {
                        case 1:
                                room_data = room_data.addroom(room_data);
                                room_object.push_back(room_data);
                         case 2:
                                system("clear");
                                room_data.display_room(room_object);
                                break;

                        case 3:
                                system("clear");
                                room_object = room_data.modify_room_details(room_object);
                                room_data.save_room_details_into_file(room_object);
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
                                system("clear");
                                exit_flag = 1;

                }

                if(exit_flag == 1)
                break ;
        }

        return room_object ;
}


/************************************************************************************************
 *
 *  FUNCTION NAME           : addroom
 *
 *  PARAMETER               : room_data
 *
 *  DESCRIPTION             : This function is for adding the room.
 *
 *  RETURN TYPE             : int
 *
 ***************************************************************************************/


Room Room::addroom(Room room_data)
{

        ofstream file ;
        char test[10] ;
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
        while(1)
        {
                cin>>test ;
                if(intiger_validation(test))
                {
                        room_data.room_number = stoi(test);
                        break ;
                }
                else
                        cout<<"Please Enter Number only \n";
        }
        file<<room_data.room_number<<",";

        cout<<"Enter Type Ac/NON-AC (A/N) : \n ";
        while(1)
        {
                cin>>room_data.ac ;

                if(alpha_validator(room_data.ac , 0))
                        break ;
                else

                        continue ;
        }
        file<<room_data.ac<<",";

        cout<<"Enter Type Comfort (S/N) : \n";
        while(1)
        {
		 cin>>room_data.type ;
                if(alpha_validator(room_data.type , 1))
                        break ;
                else
                        continue ;
        }
        file<<room_data.type<<",";

        cout<<"Enter Type Size (D/S) : \n";
        while(1)
        {
                cin>>room_data.stype ;
                if(alpha_validator(room_data.stype , 2))
                        break ;
                else
                        continue ;
        }
        file<<room_data.stype<<",";

        cout<<"Enter Daily Rent : \n";
        while(1)
        {
                cin>>test ;
                if(intiger_validation(test))
                {
                        room_data.rent = stoi(test);
                        break ;
                }
                else
                        cout<<"Please Enter Number only \n";
        }
        file<<room_data.rent<<",";
         room_data.status = 0 ;
        file<<room_data.status;
        file<<"\n";
        cout<<"\nRoom Added Successfully ! \n";

	 cout<<"\n";
        file.close();

        return room_data;
}


/************************************************************************************************
 *
 *   *  FUNCTION NAME           : display_room
 *
 *   *  PARAMETER               : room_object
 *
 *   *  DESCRIPTION             : This function is for displaying the available rooms.
 *
 *   *  RETURN TYPE             : void
 *
 ******************************************************************************************/


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

                      design('*');
                }

         design('*');
}

/************************************************************************************************
 *
 *   *  FUNCTION NAME           : modify_room_details
 *
 *   *  PARAMETER               : room_object
 *
 *   *  DESCRIPTION             : This function is for modifying the details of the room.
 *
 *   *  RETURN TYPE             : vector<room>
 *
 ****************************************************************************************/


vector<Room> Room ::modify_room_details(vector<Room> room_object)
{

        int room_no , check_flag = 0;
	 char ch ;
        char test[10] ;

         vector<Room>::iterator i;


        cout<<"enter the room number\n";
        while(1)
        {
                cin>>test ;
                if(intiger_validation(test))
                {
                        room_no  = stoi(test);
                        break ;
                }
                else
                        cout<<"Please Enter Number only \n";
        }

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
                                while(1)
                                {
                                        cin>>i->ac ;

                                        if(alpha_validator(i->ac, 0))
                                                break ;
                                        else
                                                continue ;
                                }
                                cout<<"Enter Type Comfort (S/N) : \n";
                                while(1)
                                {
                                        cin>>i->type;
                                        if(alpha_validator(i->type , 1))
                                                break ;
                                        else
                                                continue ;
                                }
                                cout<<"Enter Type Size (D/S) : \n";
                                while(1)
                                {
                                        cin>>i->stype ;
                                        if(alpha_validator(i->stype, 2))
                                                break ;
                                        else
                                                continue ;
                                }

                                cout<<"Enter Daily Rent : \n";

                                while(1)
                                {
                                        cin>>test ;
                                        if(intiger_validation(test))
                                        {
                                                i->rent = stoi(test);
                                                break ;
					 }
                                        else
                                                cout<<"Please Enter Number only \n";
                                }
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

/************************************************************************************************
 *
 *   *  FUNCTION NAME           : create_vector_for_room_info
 *
 *   *  PARAMETER               :  room_object
 *
 *   *  DESCRIPTION             : This function is for creating the vector for room information
 *
 *   *  RETURN TYPE             : vector<Room>
 *
 ***************************************************************************************/

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
                //cout<<"file reading is success\n";
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

/************************************************************************************************
 *
 *   *  FUNCTION NAME           : save_room_details_into_file
 *
 *   *  PARAMETER               : room_object
 *
 *   *  DESCRIPTION             : This function is for saving the details into the file
 *
 *   *  RETURN TYPE             : void
 *
 ***************************************************************************************/

void Room ::save_room_details_into_file(vector<Room> room_object)
{

        ofstream file ;

        file.open("Room_information.txt",ios::out) ;
        if(!file)
        {
                cout<<"File opening is error \n";
        }
        else
        {
                //cout<<"customer_information.txt is opened success\n" ;
        }

        for(auto i = room_object.begin(); i != room_object.end(); ++i)
        {
                file<<i->room_number<<",";
                file<<i->ac<<",";
                file<<i->type<<",";
                file<<i->stype<<",";
                file<<i->rent<<",";
                file<<i->status<<"\n";

        }

        file.close();
}
	