#include "MainMenu.h"

int UserInterface::start() {
    int menuToShow=MENU_CODE_MAIN_MENU;

    while (menuToShow != MENU_CODE_EXIT) {
        switch(menuToShow) {

        case MENU_CODE_MAIN_MENU:
            menuToShow=PrintStartMenu(MENU_CODE_EXIT);
            break;

        case MENU_CODE_MAIN_MENU_ADD:
            menuToShow=addNewEmployee(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_DELETE:
            menuToShow=deleteEmployee(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_DELETE_ID:
            menuToShow=deleteEmployeeById(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_DELETE_NAME:
            menuToShow=deleteEmployeeByName(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_DELETE_INDEX:
            menuToShow=deleteEmployeeByIndex(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_DELETE_ADHAR:
            menuToShow=deleteEmployeeByAdhar(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_SEARCH:
            menuToShow=searchEmployee(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_SEARCH_ID:
            menuToShow=searchEmployeeById(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_SEARCH_NAME:
            menuToShow=searchEmployeeByName(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_SEARCH_INDEX:
            menuToShow=searchEmployeeByIndex(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_SEARCH_ADHAR:
            menuToShow=searchEmployeeByAdhar(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_EDIT:
            menuToShow=editEmployee(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_EDIT_ID:
            menuToShow=editEmployeeById(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_EDIT_NAME:
            menuToShow=editEmployeeByName(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_EDIT_ADHAR:
            menuToShow=editEmployeeByAdhar(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_PRINT:
            menuToShow=printArray(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_LOAD:
            menuToShow=loadArray(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_WRITE:
            menuToShow=writeArray(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_ALEAVE:
            menuToShow=ApplyLeave(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_ALEAVE_ID:
            menuToShow=ApplyLeaveById(MENU_CODE_MAIN_MENU_ALEAVE);
            break;

        case MENU_CODE_MAIN_MENU_ALEAVE_NAME:
            menuToShow=ApplyLeaveByName(MENU_CODE_MAIN_MENU_ALEAVE);
            break;

        case MENU_CODE_MAIN_MENU_ALEAVE_INDEX:
            menuToShow=ApplyLeaveByIndex(MENU_CODE_MAIN_MENU_ALEAVE);
            break;

        case MENU_CODE_MAIN_MENU_ALEAVE_ADHAR:
            menuToShow=ApplyLeaveByAdhar(MENU_CODE_MAIN_MENU_ALEAVE);
            break;


        case MENU_CODE_MAIN_MENU_LEAVE_REPORT:
            menuToShow=PrintLeave(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_LEAVE_REPORT_ID:
            menuToShow=PrintLeaveById(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_LEAVE_REPORT_NAME:
            menuToShow=PrintLeaveByName(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_LEAVE_REPORT_INDEX:
            menuToShow=PrintLeaveByIndex(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_LEAVE_REPORT_ADHAR:
            menuToShow=PrintLeaveByAdhar(MENU_CODE_MAIN_MENU);
            break;

        case MENU_CODE_MAIN_MENU_EMPLOYEE_REPORT:
            menuToShow=PrintReport(MENU_CODE_MAIN_MENU);
            break;
        }
    }

    return 0;
}

int UserInterface::PrintStartMenu(int returnFxnCode) {

    bool printError=false;
    int base=MENU_CODE_MAIN_MENU_BASE;
    int option=-1;

    while (true) {
        system("CLS");
        cout<<"**************************"<<endl;
        cout<<"EMPLOYEE MANAGEMENT SYSTEM"<<endl;
        cout<<"**************************"<<endl<<endl<<endl<<endl;

        cout<<"choose from the following options"<<endl;
        cout<<"1.  Add Employee"<<endl;
        cout<<"2.  Delete Employee"<<endl;
        cout<<"3.  Search Employee"<<endl;
        cout<<"4.  Edit Employee"<<endl;
        cout<<"5.  Print Array"<<endl;
        cout<<"6.  Apply for Leave"<<endl;
        cout<<"7.  Print Leave Report of an Employee"<<endl;
        cout<<"8.  Load Array From a File"<<endl;
        cout<<"9.  write data to a file"<<endl;
        cout<<"10. Print Employee Report"<<endl;
        cout<<"0.  Exit"<<endl;
        cout<<"***************************"<<endl<<endl;
        if(printError == true) {
            cout<<"INVALID INPUT!!! try again"<<endl;
        }
        else {
            cout<<endl;
        }
        cout<<"choose from option 1-10 and press 0 to exit"<<endl;
        cin>>option;

        if(option>10 || option<0) {
            printError = true;
            continue;
        }
        break;

    }

    if(option == 0) {
        return returnFxnCode;
    }

    return base+option;
}

int UserInterface::addNewEmployee(int returnFxnCode) {
    string Name;
    time_t Dob;
    Gender gender;
    char tmp;
    int Adhar=-1;
    int salary=-1;
    string education;
    int tmp2=-1;

    //getting details
    cout<<"Enter the name of Employee : ";
    cin>>Name;
    cout<<"enter the Dob : ";
    cin>>Dob;
    cout<<"Enter Gender (M/F) : ";
    cin>>tmp;
    gender = (tmp == 'M' ? Male : Female);
    cout<<"Enter the Department(D/H/M/A/U) : ";
    cin>>tmp;
    cout<<"enter your Adhar number : ";
    cin>>Adhar;
    cout<<"enter your salary : ";
    cin>>salary;
    cout<<"enter your highest degree : ";
    cin>>education;


    Employee emp;
    emp.setName(Name);
    emp.setDob(Dob);
    emp.setGender(gender);
    emp.setId(mainEmpArray.getAutoId());
    emp.setDepartment(tmp);
    emp.setAdhar(Adhar);
    emp.setSalary(salary);
    emp.setEdu(education);

    cout<<endl<<endl<<endl;
    cout<<"check the details and press 0 to enter:   "<<endl;
    emp.print();
    cin>>tmp2;

    if(tmp2 != 0) {
        return returnFxnCode;
    }
    mainEmpArray.add(emp);
    return returnFxnCode;
}

int UserInterface::deleteEmployee(int returnFxnCode) {
    bool printError=false;
    int base=MENU_CODE_MAIN_MENU_DELETE_BASE;
    int option=0;

    while(true) {
        cout<<"DELETE OPTIONS"<<endl;
        cout<<"**************"<<endl<<endl;

        cout<<"1. delete by Id"<<endl;
        cout<<"2. delete by Name"<<endl;
        cout<<"3. delete by Index"<<endl;
        cout<<"4. delete by Adhar"<<endl;
        cout<<"0. Back"<<endl;
        cout<<"******************"<<endl<<endl;

        if(printError == true) {
            cout<<"INVALID INPUT!!! try again"<<endl;
        }
        else {
            cout<<endl;
        }
        cout<<"choose from option 1-4 and press 0 to exit"<<endl;
        cin>>option;

        if(option>4 || option<1) {
            printError = true;
        }
        break;
    }

    if(option == 0) {
        return returnFxnCode;
    }

    return base+option;
}

int UserInterface::deleteEmployeeById(int returnFxnCode) {
    int tmpId=-1;
    int index;
    int tmp=0;
    cout<<"enter the id of the Employee you want to delete"<<endl;
    cin>>tmpId;

    index=mainEmpArray.getEmployeeIndexById(tmpId);

    if(index == -1) {
        cout<<"No such Employee exists"<<endl;
        return returnFxnCode;
    }
    cout<<"Press 1 to confirm deletion and 0 to exit"<<endl;
    cout<<endl<<endl<<endl;
    mainEmpArray.getEmployeeByIndex(index).print();
    cout<<endl;
    cin>>tmp;
    if(tmp == 0) {
        return returnFxnCode;
    }
    mainEmpArray.deleteAtIndex(index);
    return returnFxnCode;
}

int UserInterface::deleteEmployeeByName(int returnFxnCode) {
    string tmpName;
    int index;
    int tmp=0;

    cout<<"enter the name of the Employee you want to delete"<<endl;
    cin>>tmpName;

    index=mainEmpArray.getEmployeeIndexByName(tmpName);

    if(index == -1) {
        cout<<"No such Employee exists"<<endl;
        return returnFxnCode;
    }

    cout<<"Press 1 to confirm deletion and 0 to exit"<<endl;
    cout<<endl<<endl<<endl;
    mainEmpArray.getEmployeeByIndex(index).print();
    cout<<endl;
    cin>>tmp;
    if(tmp == 0) {
        return returnFxnCode;
    }
    mainEmpArray.deleteAtIndex(index);
    return returnFxnCode;
}

int UserInterface::deleteEmployeeByIndex(int returnFxnCode) {
    int indexTmp;
    int index;
    int tmp=0;
    cout<<"enter the Index of the Employee you want to delete"<<endl;
    cin>>indexTmp;

    index=mainEmpArray.getEmployeeIndexById(indexTmp);

    if(index == -1) {
        cout<<"No such Employee exists"<<endl;
        return returnFxnCode;
    }
    cout<<"Press 1 to confirm deletion and 0 to exit"<<endl;
    cout<<endl<<endl<<endl;
    mainEmpArray.getEmployeeByIndex(index).print();
    cout<<endl;
    cin>>tmp;
    if(tmp == 0) {
        return returnFxnCode;
    }
    mainEmpArray.deleteAtIndex(index);
    return returnFxnCode;
}

int UserInterface::deleteEmployeeByAdhar(int returnFxnCode) {
    int Adhar=-1;
    int index;
    int tmp=0;
    cout<<"enter the Adhar of the Employee you want to delete"<<endl;
    cin>>Adhar;

    index=mainEmpArray.getEmployeeIndexById(Adhar);

    if(index == -1) {
        cout<<"No such Employee exists"<<endl;
        return returnFxnCode;
    }
    cout<<"Press 1 to confirm deletion and 0 to exit"<<endl;
    cout<<endl<<endl<<endl;
    mainEmpArray.getEmployeeByIndex(index).print();
    cout<<endl;
    cin>>tmp;
    if(tmp == 0) {
        return returnFxnCode;
    }
    mainEmpArray.deleteAtIndex(index);
    return returnFxnCode;
}


int UserInterface::searchEmployee(int returnFxnCode) {
    system("CLS");
    bool printError=false;
    int base=MENU_CODE_MAIN_MENU_SEARCH_BASE;
    int option=0;

    while (true) {
        cout<<"Search options"<<endl;
        cout<<"**************"<<endl<<endl<<endl;

        cout<<"1. Search by Id"<<endl;
        cout<<"2. Search by Name"<<endl;
        cout<<"3. Search by Index"<<endl;
        cout<<"4. Search by Adhar"<<endl;
        cout<<"0. Back"<<endl;
        cout<<"******************"<<endl<<endl;

        if(printError == true) {
            cout<<"INVALID INPUT!!! try again"<<endl;
        }
        else {
            cout<<endl;
        }
        cout<<"choose from option 1-4 and press 0 to exit"<<endl;
        cin>>option;

        if(option>4 || option<1) {
            printError = true;
        }
        break;
    }

    if(option == 0) {
        return returnFxnCode;
    }

    return base+option;
}

int UserInterface::searchEmployeeById(int returnFxnCode) {
    int tmpId=0;
    int tmp=-1;
    cout<<"enter the id you want to search"<<endl;
    cin>>tmpId;

    Employee tmpEmp;
    try {
        tmpEmp=mainEmpArray.getEmployeeById(tmpId);
    }
    catch (int& err) {
        if(err == -1) {
            cout<<"No employee found"<<endl;
            cin>>tmp;
            return returnFxnCode;
        }
    }

    while (true) {
        cout<<"Press 0 to continue"<<endl<<endl;
        tmpEmp.print();
        cout<<endl<<endl;
        cin>>tmp;
        if(tmp == 0 ) {
            break;
        }

    }
    return returnFxnCode;
}

int UserInterface::searchEmployeeByName(int returnFxnCode) {
    string tmpName;
    int tmp=-1;
    cout<<"enter the name of Employee you want to search"<<endl;
    cin>>tmpName;

    Employee tmpEmp;
    try {
        tmpEmp=mainEmpArray.getEmployeeByName(tmpName);
    }
    catch (int& err) {
        if(err == -1) {
            cout<<"No employee found"<<endl;
            return returnFxnCode;
        }
    }
    while (true) {
        cout<<"Press 0 to continue"<<endl<<endl;
        tmpEmp.print();
        cout<<endl<<endl;
        cin>>tmp;
        if(tmp == 0 ) {
            break;
        }

    }
    return returnFxnCode;
}

int UserInterface::searchEmployeeByIndex(int returnFxnCode) {
    int tmpIndex=0;
    int tmp=-1;
    cout<<"enter the index you want to search"<<endl;
    cin>>tmpIndex;

    Employee tmpEmp;

    try {
        tmpEmp=mainEmpArray.getEmployeeByIndex(tmpIndex);
    }
    catch (int& err) {
        if(err == 0) {
            cout<<"No employee found"<<endl;
            return returnFxnCode;
        }
    }

    while (true) {
        cout<<"Press 0 to continue"<<endl<<endl;
        tmpEmp.print();
        cout<<endl<<endl;
        cin>>tmp;
        if(tmp == 0 ) {
            break;
        }

    }
    return returnFxnCode;
}

int UserInterface::searchEmployeeByAdhar(int returnFxnCode) {
    int tmpAdhar=0;
    int tmp=-1;
    cout<<"enter the adhar number that you want to search" <<endl;
    cin>>tmpAdhar;

    Employee tmpEmp;
    try {
        tmpEmp=mainEmpArray.getEmployeeByAdhar(tmpAdhar);
    }
    catch(int& err) {
        if(err == 0) {
            cout<<"No employee found"<<endl;
            return returnFxnCode;
        }
    }

    while (true) {
        cout<<"Press 0 to continue"<<endl<<endl;
        tmpEmp.print();
        cout<<endl<<endl;
        cin>>tmp;
        if(tmp == 0 ) {
            break;
        }

    }
    return returnFxnCode;
}



int UserInterface::editEmployee(int returnFxnCode) {
    bool printError=false;
    int base=MENU_CODE_MAIN_MENU_EDIT_BASE;
    int option;

    while(true) {
        cout<<"EDIT OPTIONS"<<endl;
        cout<<"**************"<<endl<<endl;

        cout<<"1. edit by Id"<<endl;
        cout<<"2. edit by Name"<<endl;
        cout<<"3. edit by Index"<<endl;
        cout<<"4. edit by Adhar"<<endl;
        cout<<"0. Back"<<endl;
        cout<<"******************"<<endl<<endl;

        if(printError == true) {
            cout<<"INVALID INPUT!!! try again"<<endl;
        }
        else {
            cout<<endl;
        }
        cout<<"choose from option 1-4 and press 0 to exit"<<endl;
        cin>>option;

        if(option>4 || option<1) {
            printError = true;
        }
        break;
    }

    if(option == 0) {
        return returnFxnCode;
    }

    return base+option;
}

int UserInterface::editEmployeeById(int returnFxnCode) {
    int tmpId=0;
    int tmpIndx=-1;
    Employee tmpEmp;
    cout<<"enter the Id that you want to edit"<<endl;
    cin>>tmpId;

    tmpIndx=mainEmpArray.getEmployeeIndexById(tmpId);

    if(tmpIndx == -1) {
        cout<<"The Employee doesn't exists"<<endl;
        return returnFxnCode;
    }

    tmpEmp=getEditDetails();
    tmpEmp.setId(mainEmpArray[tmpIndx].getId());
    mainEmpArray[tmpIndx]=tmpEmp;
    return returnFxnCode;
}

int UserInterface::editEmployeeByName(int returnFxnCode) {
    string tmpName;
    int tmpIndx=-1;
    Employee tmpEmp;
    cout<<"enter the Name that you want to edit"<<endl;
    cin>>tmpName;

    tmpIndx=mainEmpArray.getEmployeeIndexByName(tmpName);

    if(tmpIndx == -1) {
        cout<<"The Employee doesn't exists"<<endl;
        return returnFxnCode;
    }

    tmpEmp=getEditDetails();
    tmpEmp.setId(mainEmpArray[tmpIndx].getId());
    mainEmpArray[tmpIndx]=tmpEmp;
    return returnFxnCode;
}

int UserInterface::editEmployeeByIndex(int returnFxnCode) {
    int tmpIndx=-1;
    Employee tmpEmp;
    cout<<"enter the index that you want to edit"<<endl;
    cin>>tmpIndx;

    if(tmpIndx == -1) {
        cout<<"The Employee doesn't exists"<<endl;
        return returnFxnCode;
    }

    tmpEmp=getEditDetails();
    tmpEmp.setId(mainEmpArray[tmpIndx].getId());
    mainEmpArray[tmpIndx]=tmpEmp;
    return returnFxnCode;
}

int UserInterface::editEmployeeByAdhar(int returnFxnCode) {
    int tmpAdhar=0;
    int tmpIndx=-1;
    Employee tmpEmp;
    cout<<"enter the Adhar number that you want to edit"<<endl;
    cin>>tmpAdhar;

    tmpIndx=mainEmpArray.getEmployeeIndexByAdhar(tmpAdhar);

    if(tmpIndx == -1) {
        cout<<"The Employee doesn't exists"<<endl;
        return returnFxnCode;
    }

    tmpEmp=getEditDetails();
    tmpEmp.setId(mainEmpArray[tmpIndx].getId());
    mainEmpArray[tmpIndx]=tmpEmp;
    return returnFxnCode;
}




Employee UserInterface::getEditDetails() {
    string Name;
    time_t Dob;
    Gender gender;
    char tmp;
    int Adhar=-1;
    int salary=-1;
    string education;

    //getting details
    cout<<"Enter the new name of Employee : ";
    cin>>Name;
    cout<<"enter the new Dob : ";
    cin>>Dob;
    cout<<"Enter new Gender (M/F) : ";
    cin>>tmp;
    gender = (tmp == 'M' ? Male : Female);
    cout<<"Enter the new Department(D/H/M/A/U) : ";
    cin>>tmp;
    cout<<"enter the new Adhar number : ";
    cin>>Adhar;
    cout<<"enter the new salary : ";
    cin>>salary;
    cout<<"enter the new highest degree : ";
    cin>>education;


    Employee emp;
    emp.setName(Name);
    emp.setDob(Dob);
    emp.setGender(gender);
    emp.setId(mainEmpArray.getAutoId());
    emp.setDepartment(tmp);
    emp.setAdhar(Adhar);
    emp.setSalary(salary);
    emp.setEdu(education);

    return emp;
}

int UserInterface::printArray(int returnFxnCode) {
    if(mainEmpArray.getCount() == 0) {
        cout<<"ARRAY IS EMPTY!!!"<<endl;
        return returnFxnCode;
    }

    int tmp=-1;
    system("CLS");
    mainEmpArray.printArray();
    cout<<endl<<endl<<endl;
    cout<<"Press any number to exit"<<endl;
    cin>>tmp;
    return returnFxnCode;
}

int UserInterface::loadArray(int returnFxnCode) {
    string tmpString;
    cout<<"enter the name of the file from which you want to load the data"<<endl;
    cin>>tmpString;
    mainEmpArray.loadArrayFromFile(tmpString);
    return returnFxnCode;
}

int UserInterface::writeArray(int returnFxnCode) {
    string tmpString;
    cout<<"enter the name of the file to which you want to write data"<<endl;
    cin>>tmpString;
    mainEmpArray.writeArrayToFile(tmpString);
    return returnFxnCode;
}


int UserInterface::ApplyLeave(int returnFxnCode) {
    system("CLS");
    bool printError=false;
    int base=MENU_CODE_MAIN_MENU_ALEAVE_BASE;
    int option=0;

    while (true) {
        cout<<"LEAVE OPTIONS"<<endl;
        cout<<"**************"<<endl<<endl<<endl;

        cout<<"1. Search by Id"<<endl;
        cout<<"2. Search by Name"<<endl;
        cout<<"3. Search by Index"<<endl;
        cout<<"4. Search by Adhar"<<endl;
        cout<<"0. Back"<<endl;
        cout<<"******************"<<endl<<endl;

        if(printError == true) {
            cout<<"INVALID INPUT!!! try again"<<endl;
        }
        else {
            cout<<endl;
        }
        cout<<"choose from option 1-4 and press 0 to exit"<<endl;
        cin>>option;

        if(option>4 || option<1) {
            printError = true;
        }
        break;
    }

    if(option == 0) {
        return returnFxnCode;
    }

    return base+option;
}

int UserInterface::ApplyLeaveById(int returnFxnCode) {
    int tmpId=-1;
    int tmp=0;
    int tmpIndex;
    cout<<"enter the ID to which you want to add a leave"<<endl;
    cin>>tmpId;
    Employee tmpEmp;
    try{
        tmpEmp=mainEmpArray.getEmployeeById(tmpId);
    }
    catch(int& err) {
        if(err == -1) {
            cout<<"No employee found"<<endl;
            cin>>tmp;
            return returnFxnCode;
        }
    }
    tmpIndex=mainEmpArray.getEmployeeIndexById(tmpId);
    tmpEmp.addLeaveOfEmployee();
    mainEmpArray[tmpIndex]=tmpEmp;
    return returnFxnCode;
}

int UserInterface::ApplyLeaveByName(int returnFxnCode) {
    int tmpIndex=-1;
    int tmp=0;
    string tmpStr;
    cout<<"enter the Name to which you want to add a leave"<<endl;
    cin>>tmpStr;
    Employee tmpEmp;
    try{
        tmpEmp=mainEmpArray.getEmployeeByName(tmpStr);
    }
    catch(int& err) {
        if(err == -1) {
            cout<<"No employee found"<<endl;
            cin>>tmp;
            return returnFxnCode;
        }
    }
    tmpIndex=mainEmpArray.getEmployeeIndexByName(tmpStr);
    tmpEmp.addLeaveOfEmployee();
    mainEmpArray[tmpIndex]=tmpEmp;
    return returnFxnCode;
}

int UserInterface::ApplyLeaveByIndex(int returnFxnCode) {
    int tmpIndex=-1;
    int tmp=0;
    cout<<"enter the index to which you want to add a leave"<<endl;
    cin>>tmpIndex;
    Employee tmpEmp;
    try{
        tmpEmp=mainEmpArray.getEmployeeByIndex(tmpIndex);
    }
    catch(int& err) {
        if(err == -1) {
            cout<<"No employee found"<<endl;
            cin>>tmp;
            return returnFxnCode;
        }
    }
    tmpEmp.addLeaveOfEmployee();
    mainEmpArray[tmpIndex]=tmpEmp;
    return returnFxnCode;
}


int UserInterface::ApplyLeaveByAdhar(int returnFxnCode) {
    int tmpAdhar=-1;
    int tmpIndex;
    int tmp=0;
    cout<<"enter the Adhar to which you want to add a leave"<<endl;
    cin>>tmpAdhar;
    Employee tmpEmp;
    try{
        tmpEmp=mainEmpArray.getEmployeeByAdhar(tmpAdhar);
    }
    catch(int& err) {
        if(err == -1) {
            cout<<"No employee found"<<endl;
            cin>>tmp;
            return returnFxnCode;
        }
    }
    tmpIndex=mainEmpArray.getEmployeeIndexByAdhar(tmpAdhar);
    tmpEmp.addLeaveOfEmployee();
    mainEmpArray[tmpIndex]=tmpEmp;
    return returnFxnCode;
}

int UserInterface::PrintLeave(int returnFxnCode) {
    system("CLS");
    bool printError=false;
    int base=MENU_CODE_MAIN_MENU_LEAVE_REPORT_BASE;
    int option=0;

    while (true) {
        cout<<"LEAVE OPTIONS PRINTS"<<endl;
        cout<<"**************"<<endl<<endl<<endl;

        cout<<"1. Search by Id"<<endl;
        cout<<"2. Search by Name"<<endl;
        cout<<"3. Search by Index"<<endl;
        cout<<"4. Search by Adhar"<<endl;
        cout<<"0. Back"<<endl;
        cout<<"******************"<<endl<<endl;

        if(printError == true) {
            cout<<"INVALID INPUT!!! try again"<<endl;
        }
        else {
            cout<<endl;
        }
        cout<<"choose from option 1-4 and press 0 to exit"<<endl;
        cin>>option;

        if(option>4 || option<1) {
            printError = true;
        }
        break;
    }

    if(option == 0) {
        return returnFxnCode;
    }

    return base+option;
}

int UserInterface::PrintLeaveById(int returnFxnCode) {
    int tmp;
    Employee tmpEmp;
    cout<<"enter the Id of Employee"<<endl;
    cin>>tmp;


    tmpEmp=mainEmpArray.getEmployeeById(tmp);
    cout<<endl<<endl<<"ATTENDENCE REPORT"<<endl;
    AttendanceArray tmpAtdArr=tmpEmp.getAttendanceArray();
    tmpAtdArr.Print();
    cin>>tmp;
    return returnFxnCode;
}

int UserInterface::PrintLeaveByIndex(int returnFxnCode) {
    int tmp;
    Employee tmpEmp;
    cout<<"enter the index of Employee"<<endl;
    cin>>tmp;
    tmpEmp = mainEmpArray.getEmployeeByIndex(tmp);
    cout<<endl<<endl<<"ATTENDENCE REPORT"<<endl;
    AttendanceArray tmpAtdArr=tmpEmp.getAttendanceArray();
    tmpAtdArr.Print();
    cin>>tmp;
    return returnFxnCode;
}

int UserInterface::PrintLeaveByAdhar(int returnFxnCode) {
    int tmp;
    Employee tmpEmp;
    cout<<"enter the Adhar of Employee"<<endl;
    cin>>tmp;
    tmpEmp = mainEmpArray.getEmployeeByAdhar(tmp);
    cout<<endl<<endl<<"ATTENDENCE REPORT"<<endl;
    AttendanceArray tmpAtdArr=tmpEmp.getAttendanceArray();
    tmpAtdArr.Print();
    cin>>tmp;
    return returnFxnCode;
}

int UserInterface::PrintLeaveByName(int returnFxnCode) {
    string Name;
    int tmp;
    cout<<"enter the name that you want to search"<<endl;
    cin>>Name;
    Employee tmpEmp;
    tmpEmp=mainEmpArray.getEmployeeByName(Name);
    cout<<endl<<endl<<"ATTENDANCE REPORT"<<endl;
    AttendanceArray tmpAtdArr=tmpEmp.getAttendanceArray();
    tmpAtdArr.Print();
    cin>>tmp;
    return returnFxnCode;
}

int UserInterface::PrintReport(int returnFxnCode) {
    int tmpId=-1;
    int tmp;
    cout<<"enter the employee id of whom you want to generate the report"<<endl;
    cin>>tmpId;
    Employee tmpEmp;
    AttendanceArray tmpAtdArr;
    system("CLS");
    tmpEmp=mainEmpArray.getEmployeeById(tmpId);
    cout<<"NAME: "<<tmpEmp.getName()<<"          DOB: "<<tmpEmp.getDob()<<"        GENDER: "<<tmpEmp.getGenderString()<<endl<<endl;
    cout<<"ID: "<<tmpEmp.getId()<<"        DEPARTMENT: "<<tmpEmp.getDepartmentString()<<"        ADHAR: "<<tmpEmp.getAdhar()<<endl<<endl;
    cout<<"HIGHEST EDUCATION:       "<<tmpEmp.getEduString()<<"        SALARY: "<<tmpEmp.getSalary()<<endl<<endl<<endl;
    tmpAtdArr=tmpEmp.getAttendanceArray();

    cout<<"ATTENDANCE REPORT:"<<endl<<endl;
    tmpAtdArr.Print();

    cout<<"press 0 to exit"<<endl;
    cin>>tmp;
    return returnFxnCode;
}





