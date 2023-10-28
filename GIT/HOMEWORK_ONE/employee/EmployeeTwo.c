#include <string.h>
#include "employee.h"

// NOTE: 5 functions have been defined below

// What does setting a function to static do? 
// functionPtr is the address of the function just use the name
// ()(The second set of parentheses is the arguments of the function call)
static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void *targetPtr, 
                                         int (*functionPtr)(const void *, PtrToConstEmployee)) {
    PtrToConstEmployee endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++) {
        if ((*functionPtr)(targetPtr, ptr) == 0)
            return (PtrToEmployee) ptr;
    }
    return NULL;
}

// The functionPtr will point to one of these comparison functions to perform a check
static int compareEmployeeNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr) {
    // const void *targetPtr ==> typecast as int pointer then dereference
    return *(long *) targetPtr != tableValuePtr->number;
}

static int compareEmployeeName(const void *targetPtr, PtrToConstEmployee tableValuePtr) {
    // const void *targetPtr ==> typecast as char pointer then pass into strcmp()
    return strcmp((char *) targetPtr, tableValuePtr->name);
}

static int compareEmployeePhone(const void *targetPtr, PtrToConstEmployee tableValuePtr) {
    // const void *targetPtr ==> typecast as char pointer then pass into strcmp()
    return strcmp((char *) targetPtr, tableValuePtr->phone);
}

static int compareEmployeeSalary(const void *targetPtr, PtrToConstEmployee tableValuePtr) {
    // const void *targetPtr ==> typecast as double pointer then dereference
    return *(double *) targetPtr != tableValuePtr->salary;
}

// These are called wrappers. These functions are what you will use in your main!
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int size, long number) {
    return searchEmployeeTable(ptr, size, &number, compareEmployeeNumber);
}

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int size, char* name) {
    return searchEmployeeTable(ptr, size, name, compareEmployeeName);
}

PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int size, char* phone) {
    return searchEmployeeTable(ptr, size, phone, compareEmployeePhone);
}

PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int size, double salary) {
    return searchEmployeeTable(ptr, size, &salary, compareEmployeeSalary);
}
