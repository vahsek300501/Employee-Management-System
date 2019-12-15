#ifndef ATTENDACEARRAY_H_INCLUDED
#define ATTENDACEARRAY_H_INCLUDED

#include <iostream>
#include "Definitions.h"
#include "Attendance.h"
using namespace std;

class AttendanceArray {
public:
    //constructor
    AttendanceArray();
    AttendanceArray(const AttendanceArray&);

    //destructor
    ~AttendanceArray();

    //operators
    Attendance&         operator [] (const int num) const;
    void                operator = (const AttendanceArray & p_Atd);   //assignment operator

    //getters
    Attendance          getAttandanceByIndex (int indx);
    AttendanceArray     getAttandanceByReason (LeaveReason p_Reason);
    AttendanceArray     getAttandanceByDays (int p_dayCount);
    int                 getTotalHolidays () {return m_countPos;}
    int                 getcrntCount() {return m_countPos;}

    //functions

    void                addLeave (Attendance p_Atd);
    void                Print();



private:
    void                resizeArray();



    int                 m_countPos;
    int                 m_totalCount;
    Attendance *        m_AttendanceArray;
};


#endif // ATTENDACEARRAY_H_INCLUDED
