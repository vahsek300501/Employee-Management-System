#include <iostream>
#include "Attendance.h"
using namespace std;

Attendance::Attendance() {
    m_leaveCount=0;
    m_Reason=NoneOfTheAbove;
}

Attendance::~Attendance() {
    m_leaveCount=0;
    m_Reason=NoneOfTheAbove;
}

//copy constructor
Attendance::Attendance(const Attendance& p_Atd) {
    m_leaveCount = p_Atd.m_leaveCount;
    m_Reason = p_Atd.m_Reason;
    m_description = p_Atd.m_description;
}

void Attendance::operator=(const Attendance & p_Atd) {
    m_leaveCount = p_Atd.m_leaveCount;
    m_Reason = p_Atd.m_Reason;
    m_description = p_Atd.m_description;
}

std::string Attendance::getReasonString() {
    switch(m_Reason) {
    case Medical:
        return "Medical";
        break;

    case Pregnancy:
        return "Pregnancy";
        break;

    case Emergency:
        return "Emergency";
        break;

    default:
        return "NoneOfTheAbove";
    }
}

char Attendance::getReasonCharacter() {

    switch(m_Reason) {
    case Medical:
        return 'M';
        break;

    case Pregnancy:
        return 'P';
        break;

    case Emergency:
        return 'E';
        break;

    default:
        return 'N';

    }
}

void Attendance::copyElements(Attendance & p_Atd) {
    p_Atd.m_leaveCount = m_leaveCount;
    p_Atd.m_Reason = m_Reason;
    p_Atd.m_description = m_description;
}

void Attendance::insertAttendanceDetails() {
    char reason;
    cout<<"enter the number of days you want to take leave"<<endl;
    cin>>m_leaveCount;
    cout<<"choose the reason for leave(M/P/E/N)"<<endl;
    cin>>reason;
    setReasonByCharacter(reason);
    cout<<"enter the description of leave(in one word)"<<endl;
    cin>>m_description;
}

void Attendance::printAttendanceDetails() {
    cout<<"Number of days of leave applied:        "<<m_leaveCount<<endl;
    cout<<"Reason for leave:                       "<<getReasonString()<<endl;
    cout<<"Description of leave:                   "<<m_description<<endl<<endl;
}

void Attendance::setReasonByCharacter(char c) {
    switch(c) {
    case 'M':
        m_Reason=Medical;
        break;

    case 'P':
        m_Reason=Pregnancy;
        break;

    case 'E':
        m_Reason=Emergency;
        break;

    default:
        m_Reason=NoneOfTheAbove;
        break;
    }
}
