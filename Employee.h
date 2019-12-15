#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "Definitions.h"
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "AttendanceArray.h"
#include "Attendance.h"

using namespace std;
class Employee {
public:

    Employee() ;
    Employee(bool isNull) { m_id = -1; }
    Employee(const string& empStrFromFile);
   // ~Employee();

    //Assignment operators
    void                operator = (const Employee &);
    bool                operator == (const Employee &); //only check id

   //functions
    int                 compareName (const std::string &); //Compare name
    int                 compareName (const Employee &); //Compare name
    int                 compareDob (const Employee &); //Compare dob

    bool                isGenderSame (const Employee &); //returns true if gender is same
    bool                isDepartmentSame (const Employee &); //returns true if gender is same
    bool                isNullEmployee() const { return m_id < 0; } //checks if the employee is null

    //getters
    int                 getId() const { return m_id; }
    int                 getSalary() const { return m_Salary; }
    int                 getAdhar() const { return m_Adhar; }
    std::string         getName() const { return m_name; }
    Gender              getGender() const {return m_gender;}
    Department          getDept() const {return m_dept;}
    Education           getEdu() const {return m_Edu;}
    time_t              getDob() const {return m_dob;}
    std::string         getEduString() const;
    std::string         getDepartmentString() const;
    char                getCharDepartment(Department&) const;
    std::string         getGenderString() const;
    AttendanceArray     getAttendanceArray() {return m_Attendance;}

    //setters
    void                setId(const int p_id) { p_id >=0 ? m_id = p_id : m_id = 0;}
    void                setName(const std::string& p_name) { m_name = p_name; }
    void                setSalary(const int p_Salary) { m_Salary = p_Salary; }
    void                setAdhar(const int p_Adhar) { m_Adhar = p_Adhar; }
    void                setGender(Gender p_gender) {m_gender = p_gender;}
    void                setEdu(Education p_Edu) { m_Edu = p_Edu; }
    void                setEdu(std::string&);
    void                setDob(time_t p_dob) {m_dob = p_dob;}
    void                setDepartment(Department p_dept) {m_dept = p_dept;}
    void                setDepartment(char dept);
    void                setDepartment(std::string p_dept);

    //file Handling
    bool                readEmployeeFromFileStr(const string& empStrFromFile);
    string              writeEmployeeToFileStr();

    //functions
    void                print() const;
    void                addLeaveOfEmployee();
private:


    int                                    m_id;
    unsigned long long int                 m_Salary;
    unsigned long long int                 m_Adhar;
    std::string                            m_name;
    AttendanceArray                        m_Attendance;
    Gender                                 m_gender;
    Department                             m_dept;
    time_t                                 m_dob;
    Education                              m_Edu;
};


#endif // EMPLOYEE_H_INCLUDED
