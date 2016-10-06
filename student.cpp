#include "student.h"
/*
student::student()
{

}
*/

bool Student::isValidToAdd() const
{
    /*
    Adding a new student requires:
    -name

    */

    /*
     *
     *if (qstr.trimmed().isEmpty())
     * */

   bool hasNames = !(Name.trimmed().isEmpty());
   // bool hasNames = !(Name.trimmed().isEmpty())
    if(hasNames)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/*
bool Student::isEmpty() const
{
    if(Name.empty() )
    {
        return true;
    }
    else
    {
        return false;
    }
}
*/
