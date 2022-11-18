//#include <string>
//#include <iostream>
//#include "list.h"
//
//using namespace std;
//
//
//int main()
//{
//    List staff;
//    Iterator pos;
//    staff.push_front("Tom");
//    staff.push_front("Jim");
//    staff.push_back("Cam");
//    staff.push_back("Pam");
//
//    cout << "******* Initial List *******\n";
//    for (pos = staff.begin(); !pos.equals(staff.end()); pos.next())
//        cout << pos.get() << "\n";
//
//    // reverse the list
//    cout << "******* Reverse List *******\n";
//    staff.reverse();
//    for (pos = staff.begin(); !pos.equals(staff.end()); pos.next())
//        cout << pos.get() << "\n";
//
//    // swap two elements
//    Iterator pos1, pos2;
//    pos1 = staff.begin();
//    pos2 = staff.end();
//    pos1.next();
//    pos2.previous();
//    staff.swap(pos1, pos2);
//    cout << "******* After Swapping *******\n";
//    for (pos = staff.begin(); !pos.equals(staff.end()); pos.next())
//        cout << pos.get() << "\n";
//
//    // erase one element
//    Iterator pos3 = staff.begin();
//    pos3.next();
//    Iterator pos4 = staff.erase(pos3);
//    cout << "******* After Erasing *******\n";
//    for (pos = staff.begin(); !pos.equals(staff.end()); pos.next())
//        cout << pos.get() << "\n";
//    cout << "Returned iterator points to: " << pos4.get() << endl;
//    return 0;
//}
//
//
