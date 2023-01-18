#include<iostream>
#include<vector>
#include<fstream>
#include <sstream>
#include<string>
#include <unistd.h>
#include"header.h"


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

        }

}

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

vector<customer> Customer::customer_function(vector<customer> customer_object , vector<room> &room_object)
{

        int option = 0  , exit_flag = 0;
        Customer customer_data ;

        design('*');
        cout<<"----------"<<"WELCOME TO COUSTOMER MODULE"<<"------------------"<<"\n";
        design('*');

        while(1)
        {
                cout<<"1) Registration Of New customer\n";
                cout<<"2) Book Room\n";
                cout<<"3) Search Room\n";
                cout<<"4) Check Out Room\n";
                cout<<"5) Exit \n";

                cin>>option;

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
                                customer_object = customer_data.check_of_customer(customer_object , room_object);
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
                cout<<"customer_information.txt is opened success\n" ;
        }

        cout<<"Enter the Name\n";
        cin>>customer_data.name;
        file<<customer_data.name<<",";

        cout<<"Enter the Address\n";
        cin>>customer_data.address;
        file<<customer_data.address<<",";


        cout<<"Enter the Number\n";
        cin>>customer_data.phone ;
        file<<customer_data.phone <<",";

        cout<<"Enter the Password\n";
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


        return customer_data ;
}

vector<customer> customer:: book_room(vector<customer> &customer_object , vector<room> &room_object)
{
        int option , check_flag = 0 ;

        char ch ;
        room data ;
        string name ;
        string password ;
        customer customer_data ;

         vector<customer>::iterator i_c;

        cout<<"Enter The Name \n";
        cin>>name ;
        cout<<"Enter the password \n";
        cin>>password ;

        for (i_c = customer_object.begin(); i_c != customer_object.end(); ++i_c)
        {

                if(i_c->name == name )
                {
                        if(i_c->password == password )
                        {
                                check_flag = 1;
                                cout<<"WELL COME ::"<<i_c->name<<"\n";
                                break;
                        }

                }

        }

        if(check_flag == 1)
        {
                cout<<"Enter the From Date DD-MM-YYYY"<<"\n";

                cin>>i_c->from_date[0];
                customer_data.from_date[0] = i_c->from_date[0] ;

                cin>>i_c->from_date[1];
                customer_data.from_date[1] = i_c->from_date[1] ;

                cin>>i_c->from_date[2];
                customer_data.from_date[2] = i_c->from_date[2] ;

                cout<<"Enter the To Date\n";

                cin>>i_c->to_date[0];
                customer_data.to_date[0] = i_c->to_date[0] ;

                cin>>i_c->to_date[1];
                customer_data.to_date[1] = i_c->to_date[1] ;

                cin>>i_c->to_date[2];
                customer_data.to_date[2] = i_c->to_date[2] ;

                design('*');
                data.display_room(room_object);
                design('*');

                cout<<"Please enter Room rumber\n";
                cin>>option ;

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
                                        cout<<"Room Rent is ::"<< i->rent * get_number_of_days(customer_data)<<"\n";

                                        cout<<"Enter the y to confirm the booking\n";
                                        cin>>ch ;

                                        if(ch == 'Y' || ch == 'y')
                                        {
                                                i->status = 1 ;

                                                i_c->room_no = option ;

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

void customer::search_room(vector<customer> customer_object, vector<room> room_object)
{
        int option ;

        cout<<"Please Enter the Room Number \n";
        cin>>option ;

        for(auto i = room_object.begin(); i != room_object.end(); ++i)
        {
                if(i->room_number == option)
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
        }
}

vector<customer> customer ::check_of_customer(vector<customer> &customer_object , vector<room> &room_object)
{
        int option , check_flag = 0 ;

        char ch ;
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
                                cout<<"WELL COME ::"<<i_c->name<<"\n";
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
                                cout<<"Enter the check out Date\n" ;
                                cin>>i_c->to_date[0];
                                cin>>i_c->to_date[1];
                                 cin>>i_c->to_date[2];

                                  i->status = 0 ;
                                  cout<<i_c->name<<"is checked out successfully\n";
                                   break;
                        }

                }

        }
        else
                cout<<"Room Number is Not valid \n";

        return customer_object ;
}

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
           cout<<"customer_information.txt is opened success\n" ;
        }

        for(auto i = customer_object.begin(); i != customer_object.end(); ++i)
        {
                file<<i->name<<",";
                file<<i->address<<",";
                phone[11] ='\0';
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

int Customer::get_number_of_days(Customer customer_data)
{
        if(customer_data.from_date[2] == customer_data.to_date[2] )
        {
                if(customer_data.from_date[1] == customer_data.to_date[1] )
                {
                        if(customer_data.from_date[0] < customer_data.to_date[0])
                           return customer_data.to_date[0] - customer_data.from_date[0];
                         else
                                cout<<"To Date is More than the From Date\n";
                }
        }
        else
                cout<<"Please Enter correct date \n";

                return 0;
}
