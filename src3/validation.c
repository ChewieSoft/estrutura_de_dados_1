#include "validation.h"


bool is_number_digit_check(char key[])
{
    for(int position = 0; position < strlen(key); position++)
    {
        if(isdigit(key[position])==0)
        {
            return false;
        }
    }
    return true;
}
