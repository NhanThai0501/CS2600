// //Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c 
// //gcc employeeMain.c employeeTable.c employeeTwo.c 

#include <string.h>
#include <stdlib.h>
#include "Employee.h"

//*********************************************************************************************************************
// EmployeeTable.c file
//*********************************************************************************************************************
Employee EmployeeTable[] = 
{
    {1001, "Daphne Borromeo",     "909-555-2134", 8.78},
    {1011, "Tammy Franklin",      "213-555-1212", 4.50},
    {1140, "Dorris Perl",         "310-555-1215", 7.80},
    {4011, "Tony Bobcat",         "909-555-1235", 6.34},
    {5045, "Brian Height",        "714-555-2749", 8.32}
};

const int EmployeeTableEntries = sizeof(EmployeeTable)/sizeof(EmployeeTable[0]);

//*********************************************************************************************************************
// EmployeeOne.c file
//*********************************************************************************************************************
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber)
{
    const PtrToConstEmployee endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++) //search until end of table  ptr++ will increment by what??
    {
        if (ptr->number == targetNumber) //check if it equals the Employee number
            return (PtrToEmployee)ptr;   //return location of the number to callee.
    }

    return NULL; //this will only happen if no Employee number matches in loop above
}

//Essentially the same functionality as above but comparing strings to check if equal

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char *targetName)
{

    const PtrToConstEmployee endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++)
    {
        if (strcmp(ptr->name, targetName) == 0)
            return (PtrToEmployee)ptr;
    }

    return NULL;
}

PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int tableSize, char *targetPhone)
{

    const PtrToConstEmployee endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++)
    {
        if (strcmp(ptr->phone, targetPhone) == 0)
            return (PtrToEmployee)ptr;
    }

    return NULL;
}

PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetSalary)
{

    const PtrToConstEmployee endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++)
    {
        if (ptr->salary == targetSalary)
            return (PtrToEmployee)ptr;
    }

    return NULL;
}

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