#include<iostream>
#include<vector>
#include<fstream>
#include <sstream>
#include<string>
#include <unistd.h>
#include"header.h"

/****************************************************************************************************
 *
 *   * FUNCTION NAME            : create_vector_for_customer_info
 *
 *   * PARAMETER                : customer_object
 *
 *   * DESCRIPTION              : This function is for creating vector for customer information.
 *
 *   * RETURN                   : vector<Customer>
 *
 * ****************************************************************************************************/


vector<Customer> Customer ::create_vector_for_customer_info(vector<Customer> customer_object)
{
        fstream file ;
        string buffer , test;
        Customer DataFromFile;

        std::vector<std::string> splittedStrings , splittedStrings2;

        file.open("customer_information.txt",ios::in);
        if(!file)
        {
                cout<<"file opening is error\n";
        }
        else
        {
                //cout<<"file reading is success\n";
                while(getline(file , buffer))
                {
                        //cout<<buffer<<"\n";
			splittedStrings = split(buffer ,',');
                        if(splittedStrings.size() ==  9)
                        {



                                 DataFromFile.name = splittedStrings[0];
                                 //cout<<"name"<<DataFromFile.name<<"\n";

                                DataFromFile.address = splittedStrings[1];
                                DataFromFile.phone = splittedStrings[2];
                                DataFromFile.password = splittedStrings[3];

                                splittedStrings2 = split(splittedStrings[4] ,'-');

                                DataFromFile.from_date[0] = stoi(splittedStrings2[0]);
                                DataFromFile.from_date[1] = stoi(splittedStrings2[1]);
                                DataFromFile.from_date[2] = stoi(splittedStrings2[2]);

                                splittedStrings2 = split(splittedStrings[5] ,'-');

                                DataFromFile.to_date[0] = stoi(splittedStrings2[0]);
                                DataFromFile.to_date[1] = stoi(splittedStrings2[1]);
                                DataFromFile.to_date[2] = stoi(splittedStrings2[2]);

                                DataFromFile.room_no = stoi(splittedStrings[6]);
                                DataFromFile.payment_advance = stoi(splittedStrings[7]);
                                DataFromFile.reg_id = stoi(splittedStrings[8]);

                                customer_object.push_back(DataFromFile);
                        }
                }
        }

        return customer_object ;
}


/****************************************************************************************************
 *
 *   * FUNCTION NAME            : view_customer
 *
 *   * PARAMETER                : customer_object
 *
 *   * DESCRIPTION              : This function is for viewing customer information.
 *
 *   * RETURN                   : void
 *
 ****************************************************************************************************/

void Customer ::view_customer(vector<customer> customer_object)
{

        for (auto i = customer_object.begin(); i!= customer_object.end(); ++i)
        {
                cout<<"NAME OF THE CUSTOMER ::"<<i->name<<"\n";
                cout<<"Address ::"<<i->address <<"\n";
                cout<<"Phone Number::"<<i->phone<<"\n";
                cout<<"Registration-ID::"<<i->reg_id <<"\n";
                cout<<"Start Date ::"<<i->from_date[0]<<"-"<<i->from_date[1]<<"-"<<i->from_date[2] <<"\n";
                cout<<"End Date ::"<<i->to_date[0]<<"-"<<i->to_date[1]<<"-"<<i->to_date[2] <<"\n";

                design('*');
        }

}

/****************************************************************************************************
 *
 *   * FUNCTION NAME            : search_customer
 *
 *   * PARAMETER                : customer_object
 *
 *   * DESCRIPTION              : This function is for searching customer
 *
 *   * RETURN                   : void
 *
 *
 *****************************************************************************************************/


void Customer ::search_customer(vector<customer> customer_object)
{
        string name ;
        int check_flag = 0;
        cout<<"Enter the Customer Name\n";
        cin>>name ;

        for (auto i = customer_object.begin(); i!= customer_object.end(); ++i)
        {
                if(i->name == name)
                {
                        cout<<"NAME OF THE CUSTOMER ::"<<i->name<<"\n";
                        cout<<"Address ::"<<i->address <<"\n";
                        cout<<"Phone Number::"<<i->phone<<"\n";
                        cout<<"Registration-ID::"<<i->reg_id <<"\n";
                        cout<<"Start Date ::"<<i->from_date[0]<<"-"<<i->from_date[1]<<"-"<<i->from_date[2] <<"\n";
                        cout<<"End Date ::"<<i->to_date[0]<<"-"<<i->to_date[1]<<"-"<<i->to_date[2] <<"\n";

                        check_flag = 1;
                }
        }

        if(check_flag == 0)
                cout<<name<<"is not listed in Data Base \n";

}


/****************************************************************************************************
 *
 *   * FUNCTION NAME            : create_vector_for_customer_function
 *
 *   * PARAMETER                : customer_object
 *
 *   * DESCRIPTION              : This function is for creating vector for customer function.
 *
  *   * RETURN                   : vector<Customer>
 *
 *****************************************************************************************************/

vector<customer> Customer::customer_function(vector<customer> customer_object , vector<room> &room_object)
{

     int option = 0  , exit_flag = 0;
        Customer customer_data ;

        design('*');
        cout<<"----------"<<"WELCOME TO CUSTOMER MODULE"<<"------------------"<<"\n";
        design('*');

        while(1)
        {
                cout<<"1) Registration Of New customer\n";
                cout<<"2) Book Room\n";
                cout<<"3) Search Room\n";
                cout<<"4) Check Out Room\n";
                cout<<"5) Exit \n";

                option = int_ans_choice(1,5);

                switch(option)
                {
                        case 1:
                                system("clear");
                                customer_data = customer_data.registration_new_customer(customer_data , room_object);
                                customer_object.push_back(customer_data);
                                break ;
                        case 2:
                                system("clear");
                                customer_object =customer_data.book_room(customer_object , room_object);
                                save_customer_info_to_file(customer_object , 1 );
                                break ;
                        case 3:
				 system("clear");
                                customer_data.search_room(customer_object , room_object);
                                break ;
                        case 4:
                                 system("clear");
                                customer_object = customer_data.check_out_customer(customer_object , room_object);
                                break;
                        case 5:
                                exit_flag = 1;
                                break;

                }

                if(exit_flag == 1)
                break;
        }

        return customer_object ;
}

int registration_number_genaration()
{
        int rand_num;
        srand(time(0));
        rand_num = rand();

        return rand_num;
}


/****************************************************************************************************
 *
 *   * FUNCTION NAME            : registration_new_customer
 *
 *   * PARAMETER                : room_object, customer_data
 *
 *   * DESCRIPTION              : This function is for creating vector for customer information.
 *
 *   * RETURN                   : vector<Customer>
 *
 ****************************************************************************************************/

Customer Customer::registration_new_customer(Customer customer_data , vector<room> room_object)
{

        int option;
        char ch ;

        ofstream file ;

        file.open("customer_information.txt",ios::app) ;
        if(!file)
        {
                cout<<"File opening is error \n";
         }
        else
        {
                //cout<<"customer_information.txt is opened success\n" ;
        }

        cout<<"Enter the Name\n";
        while(1)
        {
                cin>>customer_data.name;
                if(name_validation(customer_data.name))
                        break ;
                else
                {
                        cout<<"Enter only Characters \n";
                        continue ;
                }

        }
        file<<customer_data.name<<",";

        cout<<"Enter the Address\n";
        cin>>customer_data.address;
        file<<customer_data.address<<",";
	cout<<"Enter the Number\n";
        while(1)
        {
                cin>>customer_data.phone ;
                if(phone_validation(customer_data.phone))
                        break ;
                else
                        cout<<"Please enter correct phone number \n";
        }
        file<<customer_data.phone <<",";


        customer_data.password = getpass("Enter the password:"); ;
         file<<customer_data.password<<",";

        customer_data.from_date[0] = customer_data.from_date[1]  = customer_data.from_date[2] = 0;
        customer_data.to_date[0] = customer_data.to_date[1] = customer_data.to_date[2] = 0 ;

        file<<customer_data.from_date[0]<<"-"<<customer_data.from_date[1] <<"-"<<customer_data.from_date[2] <<",";
        file<<customer_data.to_date[0]<<"-"<<customer_data.to_date[1] <<"-"<<customer_data.to_date[2] <<",";

        customer_data.room_no = 0 ;
        file<<customer_data.room_no <<",";

        customer_data.payment_advance   = 0 ;
        file<<customer_data.payment_advance <<",";

        customer_data.reg_id = registration_number_genaration();
        file<<customer_data.reg_id<<"\n";

        file.close();

        cout<<"Registration is successfull \n";

        return customer_data ;
}

/****************************************************************************************************
 *
 *   * FUNCTION NAME            : create_vector_for_book_room
 *
 *   * PARAMETER                : customer_object, room_object
 *
 *   * DESCRIPTION              : This function is for creating vector for book room.
 *
 *   * RETURN                   : vector<Customer>
 *
 ****************************************************************************************************/


vector<customer> customer:: book_room(vector<customer> &customer_object , vector<room> &room_object)
{
        int option , check_flag = 0 ;

        char ch ;
        char test[10];
        int i = 0 , rent =0, date = 0, result = 0;
        std::vector<std::string> splittedStrings ;
        room data ;
        string name , strTime ;
        string password ;
        customer customer_data ;

         vector<customer>::iterator i_c;

        cout<<"Enter The Name \n";
        cin>>name ;
        password=getpass("Enter the password:");

        for (i_c = customer_object.begin(); i_c != customer_object.end(); ++i_c)
        {

                if(i_c->name == name )
                {
                        if(i_c->password == password )
                        {
				 check_flag = 1;
                                cout<<"WELLCOME ::"<<i_c->name<<"\n";
                                break;
                        }

                }

        }

        if(check_flag == 1)
        {
               while(1)\
               {
                       cout<<"Enter the From Date DD-MM-YYYY"<<"\n";
                       while(1)
                       {
                             while(1)
                             {
                                    cin>>strTime ;
                                    if(date_str_validation(strTime, '-'))
                                        break;
                                    else
                                        cout<<"Please Enter DD-MM-YYYY format \n";
                             }

                        splittedStrings = split(strTime ,'-');
                        customer_data.from_date[0] = i_c->from_date[0] = stoi(splittedStrings[0]);
                        customer_data.from_date[1] = i_c->from_date[1] = stoi(splittedStrings[1]);
                        customer_data.from_date[2] = i_c->from_date[2] = stoi(splittedStrings[2]);

                        result = date_month_year_validation(i_c->from_date[0] ,i_c->from_date[1] ,i_c->from_date[2] );
                        if(result ==1 )
                              break;
                        else if(result ==-1)
                               cout<<"Please Enter correct year \n";
                        else if(result ==-2)
                                cout<<"Please Enter correct month \n";
                        else if(result ==-3)
                                cout<<"Please Enter correct Date \n";
			 }

                cout<<"Enter To Date DD-MM-YYYY"<<"\n";
                while(1)
                {
                    while(1)
                    {
                        cin>>strTime ;
                        if(date_str_validation(strTime, '-'))
                             break;
                        else
                             cout<<"Please Enter DD-MM-YYYY format \n";
                     }

                 splittedStrings = split(strTime ,'-');
                 customer_data.to_date[0] = i_c->to_date[0] = stoi(splittedStrings[0]);
                 customer_data.to_date[1] = i_c->to_date[1] = stoi(splittedStrings[1]);
                 customer_data.to_date[2] = i_c->to_date[2] = stoi(splittedStrings[2]);

                 result = date_month_year_validation(i_c->from_date[0] ,i_c->from_date[1] ,i_c->from_date[2] );
                 if(result ==1 )
                       break;
                 else if(result ==-1)
                      cout<<"Please Enter correct year \n";
                 else if(result ==-2)
                      cout<<"Please Enter correct month \n";
                 else if(result ==-3)
                      cout<<"Please Enter correct Date \n";
             }

             date = get_number_of_days(customer_data) ;
             if(date == 0)
                    cout<<"Please enter correct Date \n";
             else if(date == -1)
                    cout<<"please enter correct month \n";
             else if(date == -2)
                    cout<<"please enter correct year \n";
             else
                    break ;
        }
	 design('*');
        data.display_room(room_object);
        design('*');

        cout<<"Please enter Room number\n";
        cin>>option;
        for(auto i = room_object.begin(); i != room_object.end(); ++i)
        {
              if(i->room_number == option)
              {
                    cout <<"Room Number ::"<< i->room_number << "\n";

                        if(i->status == 0)
                                {
                                        if(i->ac == 'a' || i->ac == 'A')
                                                cout<<"AC-ROOM "<<"\n";
                                        else
                                                cout<<"NON-AC ROOM"<<"\n";

                                        cout<<"Rent Per Day ::"<<i->rent ;
                                        rent = i->rent * date;
                                        cout<<"Room Rent is ::"<<rent<<"\n";

                                        cout<<"Enter the y to confirm the booking\n";
                                        cin>>ch ;

                                        if(ch == 'Y' || ch == 'y')
                                        {
                                                i->status = 1 ;

                                                i_c->room_no = option ;

                                                cout<<"Enter Advance to Book the Room \n";

                                                cin>>i->advance ;
                                                while(1)
                                                {
                                                        if(i->advance > 0 && i->advance <= rent )
                                                        {
								 i->balance = rent - i->advance ;
                                                                break;
                                                          }
                                                                else
                                                                        cout<<"Enter correct amount \n";
                                                  }
                                                cout<<"Room Booked Successfully\n";
                                        }

                                }
                                else if(i->status == 1)
                                {
                                        cout <<"Room Number ::"<< i->room_number << "\n";
                                        cout<<"Room is Booked\n";
                                  }

                        }

                }
        }
        else
                cout<<"User Name and Password is not match with records\n";

        return customer_object;
}

/****************************************************************************************************
 *
 *   * FUNCTION NAME            : search_room
 *
 *   * PARAMETER                : customer_object, room_object
 *
 *   * DESCRIPTION              : This function is for search room information.
 *
 *   * RETURN                   : void
 *
 ****************************************************************************************************/
void customer::search_room(vector<customer> customer_object, vector<room> room_object)
{
        int option  , check_flag = 0;

        cout<<"Please Enter the Room Number \n";
        cin>>option ;

        for(auto i = room_object.begin(); i != room_object.end(); ++i)
        {
                if(i->room_number == option)
                {
                        check_flag = 1;
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
        }

        if(check_flag == 0)
                cout<<option<<"Room Number is Not Availabel \n";
}

/****************************************************************************************************
 *
 *   * FUNCTION NAME            : create_vector_for_check_out_customer
 *
 *   * PARAMETER                : customer_object, room_object
 *
 *   * DESCRIPTION              : This function is for creating vector for check_out_customer.
 *
 *   * RETURN                   : vector<Customer>
 *
 ****************************************************************************************************/

vector<customer> customer ::check_out_customer(vector<customer> &customer_object , vector<room> &room_object)
{
        int option , check_flag = 0 ;

        char ch ;
        int rent = 0;
        room data ;
        string name ;
        customer customer_data ;

         vector<customer>::iterator i_c;

        cout<<"Enter The Name \n";
        cin>>name ;

        for (i_c = customer_object.begin(); i_c != customer_object.end(); ++i_c)
        {

                if(i_c->name == name )
                {

                                check_flag = 1;
                                cout<<"WELCOME ::"<<i_c->name<<"\n";
                                cout<<"Room Number :: "<<i_c->room_no;
                                break;
                }
	}

        if(check_flag == 1)
        {

                for (auto i = room_object.begin(); i!= room_object.end(); ++i)
                 {

                        if(i_c->room_no  == i->room_number)
                        {
                                loop :
                                cout<<"Pending AMount is ::"<<i->balance <<"\n";
                                cout<<"Please Pay the amount to check out \n";

                                cin>>rent ;

                                if(rent == i->balance)
                                {
                                  i->status = 0 ;
                                  cout<<i_c->name<<"  "<<"is checked out successfully\n";
                                   break;
                                }
                                else
                                {
                                        cout<<"Please Pay Total amount to check out \n";
                                        goto loop;
                                }
                        }

                }

        }
        else
                cout<<"Room Number is Not valid \n";

        return customer_object ;
}

/****************************************************************************************************
 *
 *   * FUNCTION NAME            : save_customer_info_to_file
 *
 *   * PARAMETER                : customer_object, flag
 *
 *   * DESCRIPTION              : This function is for creating save_customer_information_to_file
 *
 *   * RETURN                   : void
 *
 ****************************************************************************************************/

void customer ::save_customer_info_to_file(vector<customer> customer_object , int flag )
{

        ofstream file ;

        file.open("customer_information.txt",ios::out) ;
        if(!file)
        {
                cout<<"File opening is error \n";
        }
        else
        {
                //cout<<"customer_information.txt is opened success\n" ;
        }

        for(auto i = customer_object.begin(); i != customer_object.end(); ++i)
        {
                file<<i->name<<",";
                file<<i->address<<",";
                phone[10] ='\0';
                file<<i->phone<<",";
                file<<i->password<<",";
                file<<i->from_date[0]<<"-"<<i->from_date[1]<<"-"<<i->from_date[2]<<",";
                file<<i->to_date[0]<<"-"<<i->to_date[1]<<"-"<<i->to_date[2]<<",";
                file<<i->room_no<<",";
                file<<i->payment_advance<<",";
                file<<i->reg_id <<"\n";
		
		 }


        file.close();

}

/****************************************************************************************************
 *
 *  * FUNCTION NAME        : get_number_of_days
 *
 *  * PARAMETER            : customer_data
 *
 *  * DESCRIPTION          : This function is for get_number_of_days
 *
 *  * RETURN               : int Customer
 *
 * ****************************************************************************************************/

int Customer::get_number_of_days(Customer customer_data)
{
        if((customer_data.from_date[2] == customer_data.to_date[2]) && (customer_data.from_date[2] == YEAR))
        {
            if((customer_data.from_date[1] == customer_data.to_date[1]) && (customer_data.from_date[1]>=1 &&
                customer_data.from_date[1]<=12) && (customer_data.to_date[1]>=1 && customer_data.to_date[1]<=12))
                {
                    if((customer_data.from_date[0] < customer_data.to_date[0]) && (customer_data.from_date[0] >=1 &&
                     customer_data.from_date[0]<=32) && (customer_data.to_date[0]>=1 && customer_data.to_date[0]<=31))
                           return customer_data.to_date[0] - customer_data.from_date[0];
                         else
                              return 0;
                }
                else if(((customer_data.to_date[1] - customer_data.from_date[1]) == 1 ) && (customer_data.from_date[1]>= 1 &&
                     customer_data.from_date[1]<=12) && (customer_data.to_date[1]>=1 && customer_data.to_date[1]<=12))
                 {
                    if((customer_data.from_date[1]  == 2))
                    {
                        return ((28 -customer_data.from_date[0]) + customer_data.to_date[0] ) +1;
			  }
                else if(customer_data.from_date[1] == 1 || customer_data.from_date[1] == 3 || customer_data.from_date[1] == 5 || customer_data.from_date[1] == 7 ||
                        customer_data.from_date[1] == 8 || customer_data.from_date[1] == 10 || customer_data.from_date[1] == 12)
                   {
                        return ((31-customer_data.from_date[0]) + customer_data.to_date[0] )+1;
                   }
                else if(customer_data.from_date[1] == 4 || customer_data.from_date[1] == 6 || customer_data.from_date[1] == 9 || customer_data.from_date[1] == 11 )
                   {
                        return ((30-customer_data.from_date[0]) + customer_data.to_date[0] )+1;
                   }
                  else
                        return 0;
            }
               else
                      return  -1;
        }
              else
                     return -2;
}
		     
 