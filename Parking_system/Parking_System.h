
#ifndef __PARKING_SYSTEM_H__
#define __PARKING_SYSTEM_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct parking_car
{
    int id;
    char license_plate[20];
    int into_ptimeH, into_ptimeM;
}car;

typedef enum test_values {
    pass = 1,
    fail = 0
}test_values;


test_values rate_check(int id);
//test_values searchbook(int id);


test_values into_parking(int id, char license_plate[], int into_ptimeH, int into_ptimeM);
//test_values addition(int id,char name[],char author[]);


test_values leave_parking(int id);
//test_values deletebook(int id);



test_values view_parking(void);
//test_values viewbook(void);

#endif
#pragma once
