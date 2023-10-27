// //Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c 
// //gcc employeeMain.c employeeTable.c employeeTwo.c 

#include <string.h>
#include <stdlib.h>
#include "Employee.h"

//*********************************************************************************************************************
// EmployeeMain.c file
//*********************************************************************************************************************
int main(void)
{
    //defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char *phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    //defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; //Declaration

    //Example not found
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1002);
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");

    //Example found
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1011);
    if (matchPtr != NULL)
        printf("Employee ID 1011 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");

    //Example not found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "James Bond");
    if (matchPtr != NULL)
        printf("Employee James Bond is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee James Bond is NOT found in the record\n");

    //Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    //Example not found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-1234");
    if (matchPtr != NULL)
        printf("Employee phone number 909-555-1234 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee phone number 909-555-1234 is NOT found in the record\n");

    //Example found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "213-555-1212");
    if (matchPtr != NULL)
        printf("Employee phone number 213-555-1212 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee phone number 213-555-1212 is NOT found in the record\n");

    //Example not found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 4.51);
    if (matchPtr != NULL)
        printf("Employee salary 4.51 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee salary 4.51 is NOT found in the record\n");

    //Example found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.32);
    if (matchPtr != NULL)
        printf("Employee salary 8.32 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee salary 8.32 is NOT found in the record\n");

    return 0;
}
