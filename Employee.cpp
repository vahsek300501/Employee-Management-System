#include "Employee.h"
#include "string"
#include <stdlib.h>
using namespace std;

Employee::Employee() {
    m_id=-1;
    m_gender=Female;
    m_dept=None;
    m_dob=0;
    m_Salary=0;
    m_Edu=Unknown;
    m_Adhar=0;
}

Employee::Employee(const string& empStrFromFile)
{
    readEmployeeFromFileStr(empStrFromFile);
}



//assignment operators
void Employee::operator = (const Employee & p_emp)
{
    setId(p_emp.getId());
    setName( p_emp.getName());
    setGender(p_emp.getGender());
    setDepartment(p_emp.getDept());
    setDob(p_emp.getDob());
    setEdu(p_emp.getEdu());
    setSalary(p_emp.getSalary());
    setAdhar(p_emp.getAdhar());
    m_Attendance = p_emp.m_Attendance;
}

bool Employee::operator == (const Employee & p_emp)
{
    return m_id == p_emp.m_id; //only check id
}

//functions
int Employee::compareDob(const Employee & p_emp) {
    if(m_dob < p_emp.getDob()) {
        return 1;
    }
    if(m_dob > p_emp.getDob()) {
        return -1;
    }
    return 0;
}

bool Employee::isGenderSame(const Employee& p_emp) {
    return m_gender == p_emp.m_gender;
}

bool Employee::isDepartmentSame(const Employee& p_emp) {
    if(m_dept == p_emp.getDept()) {
        return true;
    }
    else {
        return false;
    }
}

char Employee::getCharDepartment(Department& dept) const
{
    switch(dept) {
    case Developers:
        return 'D';
    case HR:
        return 'H';
    case Administration:
        return 'M';
    case Accounts:
        return 'A';
    default:
        return 'U';
    }
}

void Employee::setDepartment(char str) {
    switch(str){
    case 'D':
        m_dept = Developers;
        break;

    case 'H':
        m_dept = HR;
        break;

    case 'M':
        m_dept=Administration;
        break;

    case 'A':
        m_dept=Accounts;
        break;

    case 'U':
        m_dept=None;
        break;

    default:
        m_dept = None;
        break;
    }
}

void Employee::setEdu(std::string& p_Edu) {
    if(p_Edu.compare("Graduate") == 0) {
        m_Edu = Graduate;
    }
    else if(p_Edu.compare("PostGraduate") == 0) {
        m_Edu = PostGraduate;
    }
    else if(p_Edu.compare("PHD") == 0) {
        m_Edu = PHD;
    }
    else if(p_Edu.compare("PostDoctoral") == 0) {
        m_Edu = PostDoctoral;
    }
    else {
        m_Edu = Unknown;
    }
}

std::string Employee::getDepartmentString() const {
    switch(m_dept) {
    case Developers:
        return "Developer";

    case HR:
        return "HR";

    case Administration:
        return "Administration";

    case Accounts:
        return "Accounts";

    default:
        return "Unknown";
    }
}

std::string Employee::getEduString() const{
    switch(m_Edu) {
    case Graduate:
        return "Graduate";
    case PostGraduate:
        return "PostGraduate";
    case PHD:
        return "PHD";
    case PostDoctoral:
        return "PostDoctoral";
    default:
        return "Unknown";
    }
}

std::string Employee::getGenderString() const {
    switch(m_gender) {
    case Male:
        return "M";
        break;
    default:
        return "F";
        break;
    }
}

int Employee::compareName (const Employee & p_emp) {
    return m_name.compare(p_emp.getName());
}

void Employee::print() const {
    std::cout<<std::endl;
    std::cout<<"Name        : "<< m_name <<std::endl;
    std::cout<<"DoB         : "<< m_dob <<std::endl;
    std::cout<<"Gender      : "<< (m_gender == Male ? "Male" : "Female" )<<std::endl;
    std::cout<<"Department  : "<< getDepartmentString() <<std::endl;
    std::cout<<"ID          : "<< m_id << std::endl;
    std::cout<<"Salary      : "<<m_Salary<<endl;
    std::cout<<"Education   : "<<getEduString()<<endl;
    std::cout<<"Adhar       : "<<m_Adhar<<endl<<endl;
}

void Employee::addLeaveOfEmployee() {
    Attendance tmpAtd;
    tmpAtd.insertAttendanceDetails();
    m_Attendance.addLeave(tmpAtd);
}

//file handling

bool Employee::readEmployeeFromFileStr(const string& empStrFromFile)
{
    if(empStrFromFile.empty())
        return false;

    std::string tmpData;
    stringstream tmpChar(empStrFromFile);
    Gender gender;

    getline(tmpChar, tmpData, ',');
    setName(tmpData);

    getline(tmpChar, tmpData, ',');
    setDob(atoi(tmpData.c_str()));

    getline(tmpChar, tmpData, ',');
    setDepartment(tmpData[0]);

    getline(tmpChar, tmpData, ',');
    setId(atoi(tmpData.c_str()));

    getline(tmpChar, tmpData, ',');
    setSalary(atoi(tmpData.c_str()));

    getline(tmpChar, tmpData, ',');
    setAdhar(atoi(tmpData.c_str()));

    getline(tmpChar , tmpData , ',');
    gender = (tmpData[0] == 'M' ? Male : Female);
    setGender(gender);

    getline(tmpChar, tmpData, ',');
    setEdu(tmpData);
    return true;
}


string Employee::writeEmployeeToFileStr()
{
    std::string tmpEmpString;
    char temp[32] = {};

    tmpEmpString+=m_name;
    tmpEmpString+=",";
    tmpEmpString+=std::string(itoa(m_dob, temp, 10));
    tmpEmpString+=",";
    tmpEmpString+=getCharDepartment(m_dept);
    tmpEmpString+=",";
    tmpEmpString+=std::string(itoa(m_id, temp, 10));
    tmpEmpString+=",";
    tmpEmpString+=std::string(itoa(m_Salary, temp, 10));
    tmpEmpString+=",";
    tmpEmpString+=std::string(itoa(m_Adhar, temp, 10));
    tmpEmpString+=",";
    tmpEmpString+=m_gender == Male ? 'M' : 'F';
    tmpEmpString+=",";
    tmpEmpString+=getEduString();
    tmpEmpString+=",";
    tmpEmpString+='\n';

    return tmpEmpString;
}
