
#ifndef HEADER_H
#define HEADER_H

struct Student
{
    int sapId;
    int rollNumber;
    char studentName[50];
    float sgpa[8];
    float cgpa;
};

extern struct Student list[100];
extern int total;

// Function declarations
void add();
void showOne(int i);
void showAll();
void search();
void removeRecord();
void sortBySAP();
void sortByName();

#endif
