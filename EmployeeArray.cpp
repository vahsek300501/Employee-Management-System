#include "EmployeeArray.h"

//constructor
EmployeeArray::EmployeeArray () {           //basic constructor called every time
    m_Array=new Employee [10];
    m_totalCount=10;
    m_crntPos=0;
    m_autoId=0;
}

EmployeeArray::EmployeeArray(const string& filename) //constructor to open with a file
{
    m_Array=new Employee [2];
    m_totalCount=2;
    m_crntPos=0;
    m_autoId=0;
    loadArrayFromFile(filename);
}

//constructor to declare array and copy the data of other array by reference
EmployeeArray::EmployeeArray(const EmployeeArray & p_Array) {

    m_Array=new Employee[p_Array.m_crntPos*2];
    m_totalCount=p_Array.m_crntPos*2;
    m_crntPos=0;
    m_autoId=0;

    for(int i=0;i<p_Array.m_crntPos;i++) {
        m_Array[i]=p_Array[i];
        m_crntPos=m_crntPos+1;
        m_autoId++;
    }
}
//constructor to declare array and copy the data of other array by pointer
EmployeeArray::EmployeeArray(Employee * p_Array , const int p_Count) {

    m_Array=new Employee[p_Count*2];
    m_totalCount=p_Count*2;
    m_crntPos=0;
    m_autoId=0;

    for(int i=0;i<p_Count;i++) {
        m_Array[i]=p_Array[i];
        m_crntPos=m_crntPos+1;
        m_autoId++;
    }
}

//destructor
EmployeeArray::~EmployeeArray()         //basic destructor for final termination
{
    delete [] m_Array;
    m_Array=NULL;
    m_totalCount=0;
    m_crntPos=0;
    m_autoId=0;
}

//assignment operators
Employee& EmployeeArray::operator[] (const int& p_index) const {     //operator to access array
    if(p_index < m_crntPos)
        return m_Array[p_index];
    throw string("ERROR");
}

bool EmployeeArray::operator == (const EmployeeArray& p_Array) {    //operator to compare two arrays
    if(m_crntPos == p_Array.getCount()) {
        for(int i=0;i<m_crntPos;i++) {
            if(m_Array[i] == p_Array[i]) {
                continue;
            }
            else {
                return false;
            }
        }
    }
    else {
        return false;
    }

    return true;
}

void EmployeeArray::operator = (const EmployeeArray& p_Array) {     //operator to overwrite two arrays
    delete [] m_Array;
    m_Array=NULL;
    m_crntPos=p_Array.m_crntPos;
    m_totalCount=p_Array.m_totalCount;
    m_Array = new Employee[m_totalCount];

    for(int i=0;i<m_crntPos;i++) {
        m_Array[i]=p_Array[i];
    }
}

//getters
int EmployeeArray::getEmployeeIndex(const Employee& p_emp)  const {    //function to get employee index by passing employee
    for(int i=0;i<m_crntPos;i++) {
        if(m_Array[i]==p_emp) {
            return i;
        }
    }

    return -1;
}

int EmployeeArray::getEmployeeIndexById(const int& p_Id) const {       //function to get employee index by passing Id
    for(int i=0;i<m_crntPos;i++) {
        if(m_Array[i].getId() == p_Id) {
            return i;
        }
    }

    return -1;
}

//function to get employee index by passing name
int EmployeeArray::getEmployeeIndexByName(const std::string& p_name) const {
    for(int i=0;i<m_crntPos;i++) {
        if(m_Array[i].getName().compare(p_name) == 0) {
            return i;
        }
    }
    return -1;
}

int EmployeeArray::getEmployeeIndexByAdhar(const int& p_Adhar) const {
    for(int i=0;i<m_crntPos;i++) {
        if(m_Array[i].getAdhar()==p_Adhar) {
            return i;
        }
    }
    return -1;
}

Employee& EmployeeArray::getEmployee (const Employee& p_emp) const {     //to return employee by passing employee
    for(int i=0; i<m_crntPos; i++) {
        if(m_Array[i] == p_emp) {
            return m_Array[i];
        }
    }

    throw(int(-1));
}

Employee& EmployeeArray::getEmployeeById (const int& p_Id) const {       //to return employee by Id
    for(int i=0; i<m_crntPos; i++) {
        if(m_Array[i].getId() == p_Id) {
            return m_Array[i];
        }
    }

    throw (int(-1));
}

//to return Employee by name
Employee& EmployeeArray::getEmployeeByName(const std::string& p_name) const {
    for(int i=0; i<m_crntPos; i++) {
        if(m_Array[i].getName().compare(p_name) == 0) {
            return m_Array[i];
        }
    }

    throw (int(-1));
}

Employee& EmployeeArray::getEmployeeByAdhar(const int & p_Adhar) const {
    for(int i=0;i<m_crntPos;i++) {
        if(m_Array[i].getAdhar() == p_Adhar) {
            return m_Array[i];
        }
    }

    throw (int(-1));
}

Employee& EmployeeArray::getEmployeeByIndex(const int & p_Index) const {  //return Employee by index
    if(p_Index < m_crntPos)
        return m_Array[p_Index];

    throw (int(-1));
}

//public functions
void EmployeeArray::add(const Employee& p_emp) {        //to add employee at last
    if(m_crntPos>=m_totalCount) {
            resizeArray();
    }

    m_Array[m_crntPos++] = p_emp;
}

void EmployeeArray::addEmployeeAtMiddle(const Employee& p_emp, const int p_Index) {     //to add employee at middle
    if(m_crntPos>=m_totalCount) {
        resizeArray();
    }

    for(int i=m_crntPos;i>=p_Index;i--) {
        m_Array[i+1]=m_Array[i];
    }
    m_Array[p_Index]=p_emp;
}

void EmployeeArray::deleteEmp(const Employee& p_emp) {      //delete employee by passing reference of employee
    int m_tmp_pos=getEmployeeIndex(p_emp);

    if(m_tmp_pos == m_crntPos) {
        m_crntPos--;
        return;
    }
    for(int i=m_tmp_pos;i<=m_crntPos-1;i++) {
        m_Array[i].setName(m_Array[i+1].getName());
        m_Array[i].setDob(m_Array[i+1].getDob());
        m_Array[i].setGender(m_Array[i+1].getGender());
        m_Array[i].setDepartment(m_Array[i+1].getDept());
        m_Array[i].setId(m_Array[i+1].getId());
        m_crntPos=m_crntPos-1;
        return;
    }
}

void EmployeeArray::deleteByName(const std::string& p_name) {       //delete employee by name
    Employee m_tmp_emp;
    m_tmp_emp = getEmployeeByName(p_name);
    EmployeeArray::deleteEmp(m_tmp_emp);
}

void EmployeeArray::deleteById(const int& p_Id) {       //delete employee by Id
    Employee m_tmp_emp;
    m_tmp_emp=EmployeeArray::getEmployeeById(p_Id);
    EmployeeArray::deleteEmp(m_tmp_emp);
}

void EmployeeArray::deleteAtIndex(const int& p_Index) {     //delete employee by index
    Employee m_tmp_emp;
    m_tmp_emp=EmployeeArray::getEmployeeByIndex(p_Index);
    EmployeeArray::deleteEmp(m_tmp_emp);
}

void EmployeeArray::deleteByAdhar(const int& p_Adhar) {
    Employee m_tmp_Emp;
    m_tmp_Emp = getEmployeeByAdhar(p_Adhar);
    EmployeeArray::deleteEmp(m_tmp_Emp);
}

void EmployeeArray::copyElements(Employee * p_array ,int countPos)  //copy elements by pointer
{
    for(int i=0; i<countPos; i++) {
        p_array[i]=m_Array[i];
    }
}

void EmployeeArray::printArray() {          //to print array
    for(int i = 0; i < m_crntPos; i++)
        m_Array[i].print();
}

void EmployeeArray::append(const EmployeeArray& p_Array) {          //to concatenate two arrays
    int m_tmp_index=0;
    if(m_totalCount-m_crntPos<= p_Array.getCount()) {
        resizeArray(p_Array.getCount());
    }

    for(int i=m_crntPos+1;m_tmp_index<=p_Array.getCount();i++) {
        m_Array[i]=p_Array[m_tmp_index];
        m_tmp_index++;
    }
}

bool EmployeeArray::isIdOfEmployeeSame(const int& p_id) {
    for(int i=0; i<m_crntPos; i++) {
        if(p_id == m_Array[i].getId()) {
            return true;
        }
    }
    return false;
}

//file handling
bool EmployeeArray::loadArrayFromFile(const string& filename)
{
    int tmp=-1;
    std::string tmpLine;
    ifstream inFile;
    inFile.open(filename.c_str());

    if(!inFile.is_open()) {
        cout<<"file failed to open!!! "<<endl;
        return false;
    }

    int cnt = 0;
    getline(inFile , tmpLine);
    do {
        if(cnt > 0) {
            getline(inFile , tmpLine);
        }
        Employee tmpEmp;
        if(tmpEmp.readEmployeeFromFileStr(tmpLine)) {
            if(isIdOfEmployeeSame(tmpEmp.getId()) == true) {
                cout<<"Warning!!! Same Id "<< tmpEmp.getId()<<endl;
                cnt++;
                cout<<endl<<endl<<"press 0 to continue"<<endl<<endl;
                cin>>tmp;
                continue;
            }

            add(tmpEmp);

            if(m_autoId < tmpEmp.getId()){
                m_autoId=tmpEmp.getId();
            }
        }

        cnt++;
    }while(inFile.eof() == false);

    inFile.close();
    return true;
}

bool EmployeeArray::writeArrayToFile(const string& filename) {

    ofstream outFile;
    std::string empStringTmp;
    outFile.open(filename.c_str() , std::ofstream::out | std::ofstream::trunc);

    if(!outFile.is_open()) {            //check if the file opens or not
        cout<<"file failed to open!!! "<<endl;
        return false;
    }

    if(m_crntPos == 0) {            //if the size of array is 0 then it will not write anything
        cout<<"No array to copy!!"<<endl;
        return false;
    }

    for(int i=0;i<m_crntPos;i++) {
        empStringTmp=m_Array[i].writeEmployeeToFileStr();
        outFile.write(empStringTmp.c_str(),empStringTmp.size());
    }
    outFile.close();
    return true;
}

bool EmployeeArray::writeArrayToBinaryFile(const string& filename) {

    ofstream fout;
    fout.open(filename.c_str(),std::ofstream::binary|std::ofstream::out);
    if(&fout.tellp == 0) {
        cout<<"file is empty"<<endl;
        for(int i=0;i<m_crntPos;i++) {
            fout.write((char*)&m_Array[i],sizeof(Employee));
        }
    }
    return true;
}

//private functions
void EmployeeArray::resizeArray() {             //resizing function
    Employee * newArray=new Employee [m_totalCount*2];
    copyElements(newArray, m_totalCount);
    m_totalCount=m_totalCount*2;
    delete [] m_Array;
    m_Array=newArray;
}

void EmployeeArray::resizeArray(const int p_Size ) {    //resizing function using external parameter
    Employee * newArray=new Employee [m_totalCount+p_Size*2];
    copyElements(newArray, m_totalCount);
    m_totalCount=m_totalCount+p_Size*2;
    delete [] m_Array;
    m_Array=newArray;
}

bool EmployeeArray::isCrntIdGreater(const int p_id) {
    if(p_id > m_autoId) {
        return true;
    }
    return false;
}


