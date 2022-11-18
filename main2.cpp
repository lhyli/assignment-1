#include <string>
#include <iostream>
#include "list.h"

using namespace std;


int main()
{  
    List staff;
    Iterator pos;
    staff.push_back("A");
    staff.push_front("B");
    staff.push_back("C");
    staff.push_back("D");
    staff.push_front("E");
    staff.push_front("F");
    staff.push_back("G");
    
    
    cout << "******* Initial List *******\n" ;
    for (pos = staff.begin(); !pos.equals(staff.end()); pos.next())
        cout << pos.get() << "\n";

    // reverse the list
    cout << "******* Reverse List *******\n" ;
    staff.reverse();
    for (pos = staff.begin(); !pos.equals(staff.end()); pos.next())
        cout << pos.get() << "\n";

    // swap two elements
    Iterator pos1, pos2;
    pos1 = staff.begin();
    pos2 = staff.end();
    pos1.next();
    pos1.next();
    pos2.previous();
    pos2.previous();
     
    cout << "******* After Swapping *******\n" ;
    cout << "Returned iterator points to: " << pos1.get() << endl;
    cout << "Returned iterator points to: " << pos2.get() << endl;
    staff.swap(pos1,pos2);
    for (pos = staff.begin(); !pos.equals(staff.end()); pos.next())
        cout << pos.get() << "\n";
    cout << "Returned iterator points to: " << pos1.get() << endl;
    cout << "Returned iterator points to: " << pos2.get() << endl;
    
    
    // erase one element
    pos1 = staff.erase(pos1);
    cout << "******* After Erasing *******\n" ;
    for (pos = staff.begin(); !pos.equals(staff.end()); pos.next())
        cout << pos.get() << "\n";
    cout << "Returned iterator points to: " << pos1.get() << endl;
    
    return 0;
}

