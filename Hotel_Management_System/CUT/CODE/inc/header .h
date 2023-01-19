/************************************************************************************
 * * FILE NAME          : header.h

 * * DESCRIPTION        : This file consists of function declaration used in various functions

 ************************************************************************************/



#include<vector>
#include<string>

#define NAME_SIZE 100
#define PHONE_NUMBER 10
#define DATE 3
#define SIZE 2
#define YEAR 2023

using namespace std;

/*************************************************************************************
 * CLASS NAME                 : room
 *
 * DESCRIPTION                : This is the class and consists of various variable
 *                              intializations used in the room function
 *
 * *************************************************************************************/



typedef class room
{
        private  :
        char type;
        char stype;
        char ac ;
        int room_number ;
        int rent ;
        int status ;
        int advance;
        int balance;

        public :
        friend class customer ;

        class room addroom(class room);
        void display_room(vector<room> );
        vector<room> modify_room_details(vector<room>);
        vector<room> delete_room_details(vector<room>);
        vector<room> create_vector_for_room_info(vector<room>);
        void save_room_details_into_file(vector<room>);



}Room;

/*******************************************************************************
 *  CLASS NAME                      : customer
 *
 *  DESCRIPTION                     : This is the class consisting of various variables
 *                                    intializations used in customer function
 *
 ***********************************************************************************/


typedef class customer
{
        private :
        //char name[NAME_SIZE] ;
        string name;
        //char address[NAME_SIZE];
        string address ;
        //char phone[PHONE_NUMBER];
        string phone ;
        //char password[NAME_SIZE];
        string password ;

        int from_date[DATE];
        int to_date[DATE];
        int room_no ;
        int reg_id;
        int payment_advance ;
        int booking_id ;

        public :
        class customer registration_new_customer(class customer , vector<room>);
        vector<customer> customer_function(vector<customer> , vector<room> &);
        vector<customer> book_room(vector<customer> &, vector<room> &);
        int get_number_of_days(customer) ;
        void search_room(vector<customer> , vector<room>);
        vector<customer> check_out_customer(vector<customer> & , vector<room> & );
        vector<room> admin_function(vector<room> , vector<customer> &);
        void save_customer_info_to_file(vector<customer> , int );
        vector<customer> create_vector_for_customer_info(vector<customer>);
        void view_customer(vector<customer> customer_object);
        void search_customer(vector<customer>);


}Customer;

std::vector<std::string> split(std::string , char );

int admin_login();
vector<room> admin_function(vector<room> , vector<customer> &);
void design(char ch) ;

int int_ans_choice(int  , int );
int number_validation(int );
int intiger_validation(char *);
int alpha_validator(char , int);
int phone_validation(char *);
int name_validation(char *);
int name_validation(string);
int phone_validation(string );
int date_str_validation(string , char);
int date_month_year_validation(int , int , int);