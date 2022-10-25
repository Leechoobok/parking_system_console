#define _CRT_SECURE_NO_WARNINGS
#include"Parking_System.h"

test_values view_parking()
{

    FILE* fp = NULL;
    fp = fopen("parking_car.dat", "rb");

    if (fp == NULL)
    {
        printf("\n데이터 불러오기에 실패하엿습니다.\n");
        return fail;
    }
    else {
        car* car_to_find = (car*)malloc(sizeof(car));
        printf("차량번호\t\t\t입차시간");
        while (fread(car_to_find, sizeof(car), 1, fp) == 1)
        {
            printf("\n%s\t\t\t%d시 %d분", car_to_find->license_plate, car_to_find->into_ptimeH, car_to_find->into_ptimeM);
        }
        fclose(fp);
        free(car_to_find);

        return pass;
    }
}
