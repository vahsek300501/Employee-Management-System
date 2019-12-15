#include <iostream>
#include "Definitions.h"
#include "AttendanceArray.h"
using namespace std;

AttendanceArray::AttendanceArray() {
    m_AttendanceArray = new Attendance [10];
    m_countPos=0;
    m_totalCount=10;
}

AttendanceArray::AttendanceArray(const AttendanceArray& p_AtdArr) {
    m_AttendanceArray = new Attendance [p_AtdArr.m_countPos*2];
    m_countPos = 0;
    m_totalCount = p_AtdArr.m_countPos*2;

    for(int i=0;i<p_AtdArr.m_countPos;i++) {
        m_AttendanceArray[i] = p_AtdArr[i];
        m_countPos++;
    }
}

AttendanceArray::~AttendanceArray() {
    delete [] m_AttendanceArray;
    m_AttendanceArray=NULL;
    m_countPos=0;
    m_totalCount=0;
}

//Assignment operator
void AttendanceArray::operator = (const AttendanceArray & p_Atd)
{
    delete [] m_AttendanceArray;
    m_AttendanceArray=NULL;
    m_countPos=p_Atd.m_countPos;
    m_totalCount=p_Atd.m_totalCount;
    m_AttendanceArray = new Attendance[m_totalCount];

    for(int i=0;i<p_Atd.m_countPos;i++) {
        m_AttendanceArray[i] = p_Atd[i];
    }
}


Attendance& AttendanceArray::operator [] (const int num) const{
    if(num < m_countPos) {
        return m_AttendanceArray[num];
    }
    throw("ERROR");
}

Attendance AttendanceArray::getAttandanceByIndex(int indx) {
    for(int i=0;i<m_countPos;i++) {
        if(i == indx) {
            return m_AttendanceArray[i];
        }
    }
    return Attendance();
}

AttendanceArray AttendanceArray::getAttandanceByReason(LeaveReason p_Reason) {

    AttendanceArray tmpArray;

    for(int i=0;i<m_countPos;i++) {
        if(m_AttendanceArray[i].getReason() == p_Reason) {
            if(tmpArray.m_countPos>=tmpArray.m_totalCount) {
                resizeArray();
            }
            tmpArray[tmpArray.m_countPos++] = m_AttendanceArray[i];
        }
    }
    return tmpArray;
}

AttendanceArray AttendanceArray::getAttandanceByDays(int p_days) {

    AttendanceArray tmpArray;
    for(int i=0;i<m_countPos;i++) {
        if(m_AttendanceArray[i].getLeaveCount() == p_days) {
            if(tmpArray.m_countPos>=tmpArray.m_totalCount) {
                resizeArray();
            }
            tmpArray[tmpArray.m_countPos++]=m_AttendanceArray[i];
        }
    }

    return tmpArray;
}

void AttendanceArray::addLeave(Attendance p_Atd) {
    if(m_countPos>=m_totalCount) {
        resizeArray();
    }
    m_AttendanceArray[m_countPos++] = p_Atd;
}

void AttendanceArray::resizeArray() {
    Attendance * tmpArray=new Attendance [m_totalCount*2];
    for(int i=0;i<m_countPos;i++) {
        tmpArray[i]=m_AttendanceArray[i];
    }
    m_countPos=m_countPos*2;
    delete [] m_AttendanceArray;
    m_AttendanceArray=tmpArray;
}


void AttendanceArray::Print() {
    for(int i=0;i<m_countPos;i++) {
        m_AttendanceArray[i].printAttendanceDetails();
        cout<<endl<<endl<<endl;
    }
}
