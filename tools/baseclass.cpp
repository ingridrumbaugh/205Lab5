#include "baseclass.h"

// Initialize the static variable that tracks
// number of objects created.
int BaseClass::idCnt = 0;

BaseClass::BaseClass()
{



    // Uniquely identify the object.
    id = idCnt;

    // Increment the created object count.
    idCnt++;

    // Be carefull of the ordering here.
   // SHOW_WHERE;


}
