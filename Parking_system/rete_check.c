#define _CRT_SECURE_NO_WARNINGS
#include"Parking_System.h"



test_values rate_check(int id)
{
    time_t timer;
    struct tm* t;
    FILE* fp = NULL;
    fp = fopen("parking_car.dat", "rb");
    if (fp == NULL)
    {
        printf("\n데이터 불러오기에 실패하였습니다.\n");
        return fail;
    }
    else {

        car* car_to_find = (car*)malloc(sizeof(car));
        while (fread(car_to_find, sizeof(car), 1, fp))
        {
            if (car_to_find->id == id)
            {
                int fare, chk_timeA, chk_timeB;
                timer = time(NULL);
                t = localtime(&timer);
                chk_timeA = (t->tm_hour * 60) + t->tm_min;
                chk_timeB = (car_to_find->into_ptimeH * 60) + car_to_find->into_ptimeM;
                fare = (chk_timeA - chk_timeB) / 10 * 800;
                printf("차량번호 : %s\n", car_to_find->license_plate);
                printf("입차 시간 : %d시 %d분\n", car_to_find->into_ptimeH,car_to_find->into_ptimeM );
                printf("이용 시간 : %d분\n", chk_timeA- chk_timeB);
                printf("발생 요금 : %d원\n", fare);

                fclose(fp);
                free(car_to_find);
                return pass;
            }
        }

        fclose(fp);
        free(car_to_find);
        printf("\n정보를 찾을 수 없습니다.\n");

        return fail;
    }
}
