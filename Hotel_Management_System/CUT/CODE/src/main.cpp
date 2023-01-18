#include<iostream>
#include<vector>
#include<fstream>
#include <sstream>
#include<string>
#include <set>
#include<stdlib.h>
#include"header.h"
#define ZERO 0
#define THIRTY 30


using namespace std ;
void design(char ch)
{
        for(int i = ZERO ; i < THIRTY ; i++)
                cout<<ch;
        cout<<"\n";
}

int main()
{

        vector<room> room_object;
        vector<Customer> customer_object;

        Customer c_data ;
        Room  R_data ;
        int ch , exit_flag = ZERO ;

        room_object = R_data.create_vector_for_room_info(room_object);
        customer_object = c_data.create_vector_for_customer_info(customer_object);
        design('*');

        cout<<"-----------"<<"WELCOME TO HOTEL MANGMENT SYSTEM------"<<"\n";


        while(1)
        {
                design('*');
                cout<<"1) Admin Module\n";
                cout<<"2) Customer Module\n";
                cout<<"3) Logout\n";
                design('*');
                cin>>ch ;

                switch(ch)
                {
                        case 1: if(admin_login())
                                {
                                        system("clear");
                                        room_object = admin_function(room_object , customer_object);
                                }
                                else
                                        cout<<"Please Enter correct user name and password\n";
                                break ;
                        case 2:
                                system("clear");
                                customer_object = c_data.customer_function( customer_object,room_object );
                                break ;
                        case 3:
                                exit_flag = 1 ;
                                break ;
                }

                if(exit_flag == 1)
                        break ;
        }

}