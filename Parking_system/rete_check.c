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
        printf("\n������ �ҷ����⿡ �����Ͽ����ϴ�.\n");
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
                printf("������ȣ : %s\n", car_to_find->license_plate);
                printf("���� �ð� : %d�� %d��\n", car_to_find->into_ptimeH,car_to_find->into_ptimeM );
                printf("�̿� �ð� : %d��\n", chk_timeA- chk_timeB);
                printf("�߻� ��� : %d��\n", fare);

                fclose(fp);
                free(car_to_find);
                return pass;
            }
        }

        fclose(fp);
        free(car_to_find);
        printf("\n������ ã�� �� �����ϴ�.\n");

        return fail;
    }
}
