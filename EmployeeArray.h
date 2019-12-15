#ifndef EMPLOYEEARRAY_H_INCLUDED
#define EMPLOYEEARRAY_H_INCLUDED
#include "Employee.h"

class EmployeeArray {
public:

    //constructor
    EmployeeArray();//basic constructor called every time
    EmployeeArray(const string& filename);  //read all records from the file
    EmployeeArray(const EmployeeArray&);    //constructor to declare array and copy the data of other array by reference
    EmployeeArray(Employee*, const int);    //constructor to declare array and copy the data of other array by pointer

    //destructor
    ~EmployeeArray();                       //destructor for final destruction


    //operators
    Employee&           operator[] (const int&) const; //to get employee at an index
    void                operator =  (const EmployeeArray&);//overwrite employee data
    bool                operator == (const EmployeeArray&); //number of elements, sequence of elements


    //getters
    Employee&           getEmployee (const Employee &) const; //get employee
    Employee&           getEmployeeByName (const std::string &) const; //get employee by name
    Employee&           getEmployeeById (const int &) const; //get employee by Id
    Employee&           getEmployeeByIndex (const int &) const;//returns employee by index
    Employee&           getEmployeeByAdhar (const int &) const;//return employee by adhar


    int                 getEmployeeIndex(const Employee &) const; //get employee
    int                 getEmployeeIndexByName (const std::string &) const; //get employee by name
    int                 getEmployeeIndexById (const int & ) const; //get employee by Id
    int                 getEmployeeIndexByAdhar (const int &) const;//get Employee Index by Adhar

    int                 getCount() const { return m_crntPos; }

    //setters
    void                add (const Employee &); //adds an employee
    void                addEmployeeAtMiddle (const Employee &, const int); //add employee at middle

    //functions
    void                copyElements(Employee *, int ); //copy element for resizing or otherwise

    void                deleteEmp (const Employee &); //delete an employee
    void                deleteById (const int&); //deletes an employee by Id
    void                deleteByName (const std::string &); //deletes employee by name
    void                deleteAtIndex(const int &); //delete employee by index
    void                deleteByAdhar(const int &); //delete by adhar number

    void                printArray (); //print elements by loop

    void                append(const EmployeeArray&);  //concatenate two arrays

    bool                isIdOfEmployeeSame(const int&); //checks the id of employee

    int                 getAutoId() {return ++m_autoId;}        //to generate automatic Id


    //file Handling
    bool                loadArrayFromFile(const string&);       //get data from a file
    bool                writeArrayToFile(const string&);        //if a file is being used, save all the records to that file
    bool                writeChangesToFile(const string&);      //doesn't truncate the file just copy the changes to file
    bool                writeArrayToBinaryFile(const string&);  //write data in the array to binary file
    bool                readArrayFromBinaryFile(const string&); //read data from file and store it in the array
private:

    //private functions
    void                resizeArray();      //to resize array
    void                resizeArray(const int);     //to resize using external parameters

    bool                isCrntIdGreater(const int);  //to check if any Id is greater than current Id

    Employee *      m_Array;
    int             m_crntPos;
    int             m_totalCount;
    int             m_autoId;
};

#endif // EMPLOYEEARRAY_H_INCLUDED
