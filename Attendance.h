#ifndef ATTENDANCE_H_INCLUDED
#define ATTENDANCE_H_INCLUDED

#include <iostream>
#include "Definitions.h"
using namespace std;

class Attendance {
public:
    Attendance();
    Attendance(const Attendance&);
    ~Attendance();

    void                        operator = (const Attendance & p_Atd);

    //setters
    void                        setLeaveCount(int p_leaveCount) {m_leaveCount = p_leaveCount;}
    void                        setReason(LeaveReason p_Reason) {m_Reason = p_Reason;}
    void                        setDescription(std::string p_des) {m_description = p_des;}

    //getters
    int                         getLeaveCount() {return m_leaveCount;}
    LeaveReason                 getReason() {return m_Reason;}
    string                      getDescription() {return m_description;}
    string                      getReasonString();
    char                        getReasonCharacter();

    //functions
    void                        insertAttendanceDetails();
    void                        copyElements(Attendance & p_Atd);
    void                        printAttendanceDetails();


private:
    void                        setReasonByCharacter(char c);

    int                         m_leaveCount;
    LeaveReason                 m_Reason;
    std::string                 m_description;
};
#endif // ATTENDANCE_H_INCLUDED
