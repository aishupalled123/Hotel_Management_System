/*************************************************************************************************
 * FUNCTION NAME            :  validation.cpp
 *
 * DESCRIPTION              : This file is to check the validations for various functions.
 *
 *********************************************************************************************/

#include<iostream>
#include<cstring>
using namespace std ;

/*************************************************************************************************
 *
 * * FUNCTION NAME            : integer_validat/ion
 *
 * * DESCRIPTION              : This file is to check the validations for integer
 *
 * * PARAMETERS               : str
 *
 * * RETURN                   : int
 * ************************************************************************************************/


int intiger_validation(char *str)
{
        long int num ;

        int len =0 , count = 0;

        num = atoi(str);

        len = strlen(str);

        if(num <= 0)
        {
                return 0;
        }
        else
        {
                do {
                        num /= 10;
                        ++count;

                  }while(num != 0);


                  if(len == count)
                        return 1;
                  else
                        return 0;
        }
}

/*************************************************************************************************
 *
 *  * FUNCTION NAME            : int_ans_choice
 *
 *  *  DESCRIPTION             : This file is to check the validations for integer for answer choice
 *
 *  * PARAMETERS               : n,m
 *
 *  * RETURN                   : int
 ************************************************************************************************/


int int_ans_choice(int n , int m)
{
        int ch;
        char temp[5];

                while(1)
                {
                        cin>>temp ;
                        if(intiger_validation(temp))
                        {
                                ch = stoi(temp);
                                if(ch >= n && ch <= m)
                                {
                                        break;
                                }
                                else
                                        cout<<"enter number with range of"<<n<<","<<m<<"\n";

                        }
                        else
                        {
                                cout<<"enter valid input\n";
                                return -1;
                        }
                }
        return ch;
}

/*************************************************************************************************
 *
 *  * FUNCTION NAME            :  alpha_validator
 *
 *  * DESCRIPTION              : This file is to check the validations for alphabet
 *
 *  * PARAMETERS               : s,flag
 *
 *  * RETURN                   : int
* ************************************************************************************************/


int alpha_validator(char s , int flag)
{
        if(flag == 0)
        {
                if( s== 'a' || s == 'A' ||s== 'n' || s == 'N')
                        return 1;
                 else
                 {
                        cout<<"Enter A for AC Room \n";
                        cout<<"Entert N For Non -Ac Room \n";
                        return 0;
                 }
              }
         else if(flag == 2)
         {
                if( s== 'D' || s == 'd' ||s== 'S' || s == 's')
                        return 1;
                 else
                 {
                        cout<<"Enter D for Double sharing \n";
                        cout<<"Entert S For Single Sharing \n";
                        return 0;
                 }
         }
         else if(flag == 1)
         {
                if( s== 'S' || s == 's' ||s== 'N' || s == 'n')
                        return 1;
                 else
                 {
                        cout<<"Enter S for Luxary Room \n";
                        cout<<"Entert N For Non -Luxary Room \n";
                        return 0;
                 }
         }
         else
                return 0;
}

/*************************************************************************************************
 *
 *  * FUNCTION NAME            : name_validation
 *
 *  * DESCRIPTION              : This file is to check the validations for name.
 *
 *  * PARAMETERS               : s
 *
 *  * RETURN                   : int
 * ************************************************************************************************/

int name_validation(char *s)
{
    for(char *p=s;*p!='\0';p++)
        {
                if((!isalpha(*p)) && (*p!=' '))
                return 0;
        }

        if(strlen(s)>15 || strlen(s) < 3)
        {
                printf("Enter name within the length of 5 to 15\n");
                return 0;
        }

        return 1;
}

/*************************************************************************************************
 *
 *  * FUNCTION NAME            : name_validation
 *
 *  * DESCRIPTION              : This file is to check the validations for name
 *
 *  * PARAMETERS               : s
 *
 *  * RETURN                   : int
 ************************************************************************************************/


int name_validation(string s)
{
        const  char* str = s.c_str();

        for(str;*str!='\0';str++)
        {
                if((!isalpha(*str)) && (*str!=' '))
                return 0;
        }

        if(s.length()>15 || s.length() < 3)
        {
                printf("Enter name within the length of 3 to 15\n");
                return 0;
        }

        return 1;
}

/*************************************************************************************************
 *
 *  * FUNCTION NAME            : phone_validation
 *
 *  * DESCRIPTION              : This file is to check the validations for phone number.
 *
 *  * PARAMETERS               : str
 *
 *  *  RETURN                  : int
 ************************************************************************************************/

int phone_validation(char *str)
{

        long int num ;

        int len =0 , count = 0;

        len = strlen(str);

        if(num <= 0 || len < 10 || len > 10)
        {
                return 0;
        }
        else
        {
                num = atoi(str);
                do {

                        num /= 10;
                        ++count;

                  }while(num != 0);

                  if(len == count)
                        return 1;
                  else
                        return 0;
        }
}

/*************************************************************************************************
 *
 *  *  FUNCTION NAME            : phone_validation
 *
 *  * DESCRIPTION               : This file is to check the validations for phone number
 *
 *  *  PARAMETERS               : str
 *
 *  * RETURN                    : int
 ************************************************************************************************/

int phone_validation(string str)
{

        long int num ;

        int len =0 , count = 0;

        len = str.length();

        const  char* str1 = str.c_str();

        if(num <= 0 || len < 10 || len > 10)
        {
                return 0;
        }
        else
        {
          while(str[count] !='\0' && str[count] !='\n' )
                        {
                           if(str[count] >=48 && str[count] <= 57)
                           {
                                ++count;
                           }

                        }

                  if(len == count)
                         return 1;
                  else
                         return 0;
        }
}

/*************************************************************************************************
 *
 *  *  FUNCTION NAME            : date_str_validation
 *
 *  * DESCRIPTION               : This file is to check the validations for date
 *
 *  *  PARAMETERS               : str, ch
 *
 *  * RETURN                    : int
 ************************************************************************************************/

int date_str_validation(string str , char ch)
{
        int i = 0 , count  = 0;;
        while(str[i] !='\0' )
        {
                if((str[i] >= 48 && str[i++] <= 57))
                        continue ;
                else if(str[i++] == ch )
                        count++;
                else
                        return 0 ;
          }

        if(count == 2)
                return 1;
        else
                return 0;

}

/*************************************************************************************************
 *
 *  *  FUNCTION NAME            : date_month_year_validation
 *
 *  * DESCRIPTION               : This file is to check the validations for date, month, year
 *
 *  *  PARAMETERS               : dd, mm, yyyy
 *
 *  * RETURN                    : int
 ************************************************************************************************/


int date_month_year_validation(int dd , int mm , int yyyy)
{
        if(yyyy == 2023)
        {
                if(mm >= 1 && mm <= 12)
                {
                        if((mm  == 2))
                        {
                                if(dd>=1 &&dd <= 28)
                                        return 1;
                                else
                                        return -3;
                        }
                        else if(mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
                        {
                                if(dd>=1 && dd<=31)
                                        return 1;
                                else
                                        return -3;
                        }
                        else if(mm == 4 || mm == 6 || mm == 9 || mm == 11 )
                        {
                                if(dd>=1 && dd<=30)
                                        return 1;
                                else
                                        return -3;
                        }

                }
                return -2;
        }
        else
                return -1;
}

/*************************************************************************************************
 *
 *  * FUNCTION NAME            : number_validation
 *
 *  * DESCRIPTION              : This file is to check the validations for number
 *
 *  * PARAMETERS               : num
 *
 *  * RETURN                   : int
 ************************************************************************************************/

int number_validation(int num)
{
        if(num > 0)
                return 1 ;
        else
                return 0;
}


