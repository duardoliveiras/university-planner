# Planner

## Project Description

This C++ application is designed to manage schedules after they have been elaborated. This app include various functionalities related to schedules, such as modifying, searching, viewing, sorting, listing, among others.

## Install and Run the Project

To open the program, open the terminal and run the following command 
```make && ./a.out```

## Colaboration

> Bernardo Jose Ponce Figueirado de Brito, up

> Clarisse Maria Teixeira de Carvalho, up202008444

> Eduardo Oliveira Silva, up

## Features

* Create class:
  
  > Create student;
  
  > Create uc;

* Read Database:
  
  > Read classes_per_uc.csv;
  
  > Read classes.csv;
  
  > Read studennts_classes.csv;

* Create menu;

* Schedule managents system - functions:
  
  > Consult schedule of given student or class;
  
  > Consult the students within a given class, course or year;
  
  > Consult the number of students registered in at least n UCs;
  
  > Consult the class/year/UC occupation (sorting by UC, ascending or descending order, …):

  > Consult class/year/UC sortig by UC;

  > Consult class/year/UC sortig by Alfabetic ascending;

  > Consult class/year/UC sortig by Alfabetic descending;

  > Consult class/year/UC sortig by day of week;

  > Consult class/year/UC sortig by time of the day;
  
  > Consult the UCs with the greatest number of students;

* Requests:
  
  > Add;
  
  > Remove;
  
  > Switch;

* Store all changes in the database;

* Print:

  > Print database;
  
  > Print total schedule;

  > Print partial schedule;

  > Print specific UC;
  
  > Print other information (see functios);

* PDF;

* Presentation.



## Restrictions 

> Note that a student’s schedule may overlap classes if they are neither TP nor PL. That is, there may be overlapping classes between T and TP, between T and T, and between T and PL.

> For UC changes, consider the following rules:
  1.A student cannot be registered in more than 7 UCs at any given time;
  2.There must be at least one class with a vacancy in the new UC;
  3.The resulting schedule will not conflict with the student’s original schedule.

> For class changes, consider the following rules:
  1.A student cannot be in more than one class at once for a given UC;
  2.A class can only accept a new student if its capacity has not been exceeded. Consider that there is a maximum capacity Cap for classes;
  3.A class can only accept a new student if the balance between class occupation is not disturbed. The balance of class occupation is maintained when the difference between the number of students in any class is less than or equal to 4;
  4.There is no conflict between the student’s schedule and the new class’s schedule.

> Undo requests can be accepected or denied 

## Other information

Note: Everytime you add a file, add to Makefile too
//Povoar - https://www.mockaroo.com/

Dead line: 3 nov 2023


