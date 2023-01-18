#include<vector>
#include<string>

#define NAME_SIZE 100
#define PHONE_NUMBER 10
#define DATE 3
#define SIZE 2

using namespace std;
typedef class room
{

        public :
        friend class customer ;

        class room addroom(class room);
        void display_room(vector<room> );
        vector<room> modify_room_details(vector<room>);
        vector<room> delete_room_details(vector<room>);
        vector<room> create_vector_for_room_info(vector<room>);

        private  :
                char type;
                char stype;
                char ac ;
                int room_number ;
                int rent ;
                int status ;

}Room;

typedef class customer
{
        public :
        class customer registration_new_customer(class customer , vector<room>);
        vector<customer> customer_function(vector<customer> , vector<room> &);
        vector<customer> book_room(vector<customer> &, vector<room> &);
        int get_number_of_days(customer) ;
        void search_room(vector<customer> , vector<room>);
        vector<customer> check_of_customer(vector<customer> & , vector<room> & );
[9:20 pm, 17/01/2023] Swathi Gowda: vector<room> admin_function(vector<room> , vector<customer> &);
        void save_customer_info_to_file(vector<customer> , int );
        vector<customer> create_vector_for_customer_info(vector<customer>);
        void view_customer(vector<customer> customer_object);
        void search_customer(vector<customer>);

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


}Customer;

std::vector<std::string> split(std::string , char );

int admin_login();
vector<room> admin_function(vector<room> , vector<customer> &);
void design(char ch) ;