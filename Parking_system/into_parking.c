#define _CRT_SECURE_NO_WARNINGS
#include"Parking_System.h"


test_values into_parking(int id, char license_plate[], int into_ptimeH, int into_ptimeM)
{



    FILE* fp = NULL;
    fp = fopen("parking_car.dat", "ab+");

    if (fp == NULL)
    {
        printf("\n데이터 불러오기에 실패하였습니다.\n");
        return fail;
    }
    else {

        car* newCar = NULL;
        newCar = malloc(sizeof(car));

        newCar->id = id;
        strcpy(newCar->license_plate, license_plate);
        newCar->into_ptimeH = into_ptimeH;
        newCar->into_ptimeM = into_ptimeM;

        fwrite(newCar, sizeof(car), 1, fp);
        fclose(fp);
        free(newCar);

        return pass;
    }

}
