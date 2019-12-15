#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <limits.h>
#include <stdlib.h>
#include <dos.h>

#include "Definitions.h"
#include "Employee.h"
#include "EmployeeArray.h"

#define MENU_CODE_EXIT                              0
#define MENU_CODE_MAIN_MENU                         1
#define MENU_CODE_MAIN_MENU_BASE                    10

#define MENU_CODE_MAIN_MENU_ADD                     11

#define MENU_CODE_MAIN_MENU_DELETE                  12
#define MENU_CODE_MAIN_MENU_DELETE_BASE             120
#define MENU_CODE_MAIN_MENU_DELETE_ID               121
#define MENU_CODE_MAIN_MENU_DELETE_NAME             122
#define MENU_CODE_MAIN_MENU_DELETE_INDEX            123
#define MENU_CODE_MAIN_MENU_DELETE_ADHAR            124


#define MENU_CODE_MAIN_MENU_SEARCH                  13
#define MENU_CODE_MAIN_MENU_SEARCH_BASE             130
#define MENU_CODE_MAIN_MENU_SEARCH_ID               131
#define MENU_CODE_MAIN_MENU_SEARCH_NAME             132
#define MENU_CODE_MAIN_MENU_SEARCH_INDEX            133
#define MENU_CODE_MAIN_MENU_SEARCH_ADHAR            134

#define MENU_CODE_MAIN_MENU_EDIT                    14
#define MENU_CODE_MAIN_MENU_EDIT_BASE               140
#define MENU_CODE_MAIN_MENU_EDIT_ID                 141
#define MENU_CODE_MAIN_MENU_EDIT_NAME               142
#define MENU_CODE_MAIN_MENU_EDIT_INDEX              143
#define MENU_CODE_MAIN_MENU_EDIT_ADHAR              144

#define MENU_CODE_MAIN_MENU_PRINT                   15

#define MENU_CODE_MAIN_MENU_ALEAVE                  16
#define MENU_CODE_MAIN_MENU_ALEAVE_BASE             160
#define MENU_CODE_MAIN_MENU_ALEAVE_ID               161
#define MENU_CODE_MAIN_MENU_ALEAVE_NAME             162
#define MENU_CODE_MAIN_MENU_ALEAVE_INDEX            163
#define MENU_CODE_MAIN_MENU_ALEAVE_ADHAR            164

#define MENU_CODE_MAIN_MENU_LEAVE_REPORT            17
#define MENU_CODE_MAIN_MENU_LEAVE_REPORT_BASE       170
#define MENU_CODE_MAIN_MENU_LEAVE_REPORT_ID         171
#define MENU_CODE_MAIN_MENU_LEAVE_REPORT_NAME       172
#define MENU_CODE_MAIN_MENU_LEAVE_REPORT_INDEX      173
#define MENU_CODE_MAIN_MENU_LEAVE_REPORT_ADHAR      174


#define MENU_CODE_MAIN_MENU_LOAD                    18
#define MENU_CODE_MAIN_MENU_WRITE                   19

#define MENU_CODE_MAIN_MENU_EMPLOYEE_REPORT         20



class UserInterface {
public:
    int             start();
private:
    int             PrintStartMenu(int returnFxnCode);

    int             addNewEmployee(int returnFxnCode);

    int             deleteEmployee(int returnFxnCode);
    int             deleteEmployeeByName(int returnFxnCode);
    int             deleteEmployeeById(int returnFxnCode);
    int             deleteEmployeeByAdhar(int returnFxnCode);
    int             deleteEmployeeByIndex(int returnFxnCode);

    int             searchEmployee(int returnFxnCode);
    int             searchEmployeeById(int returnFxnCode);
    int             searchEmployeeByName(int returnFxnCode);
    int             searchEmployeeByIndex(int returnFxnCode);
    int             searchEmployeeByAdhar(int returnFxnCode);

    Employee        getEditDetails();
    int             editEmployee(int returnFxnCode);
    int             editEmployeeById(int returnFxnCode);
    int             editEmployeeByName(int returnFxnCode);
    int             editEmployeeByIndex(int returnFxnCode);
    int             editEmployeeByAdhar(int returnFxnCode);

    int             printArray(int returnFxnCode);

    int             ApplyLeave(int returnFxnCode);
    int             ApplyLeaveById(int returnFxnCode);
    int             ApplyLeaveByName(int returnFxnCode);
    int             ApplyLeaveByIndex(int returnFxnCode);
    int             ApplyLeaveByAdhar(int returnFxnCode);

    int             PrintLeave(int returnFxnCode);
    int             PrintLeaveById(int returnFxnCode);
    int             PrintLeaveByName(int returnFxnCode);
    int             PrintLeaveByIndex(int returnFxnCode);
    int             PrintLeaveByAdhar(int returnFxnCode);

    int             loadArray(int returnFxnCode);
    int             writeArray(int returnFxnCode);

    int             PrintReport(int returnFxnCode);

    EmployeeArray   mainEmpArray;
};


#endif // MAINMENU_H_INCLUDED
