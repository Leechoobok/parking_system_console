#define _CRT_SECURE_NO_WARNINGS
#include "Parking_System.h""

test_values leave_parking(int id)
{
    time_t timer;
    struct tm* t;
    FILE* fp = NULL;
    FILE* ft = NULL;
    fp = fopen("parking_car.dat", "rb");
    ft = fopen("temp.dat", "wb");
    char select_car='\0';

    if (fp == NULL || ft == NULL)
    {
        printf("\n데이터 불러오기에 실패하였습니다.\n");
        return fail;
    }
    else {
        rewind(fp);

        car* leave_car = (car*)malloc(sizeof(car));
        while (fread(leave_car, sizeof(car), 1, fp) == 1)
        {
            if (id != leave_car->id)
            {

                fwrite(leave_car, sizeof(car), 1, ft);


            }
            else {
                int flag = 1;
                while (flag) {
                    printf("%s차량 출차 하시겟습니까?(y/n)",leave_car->license_plate);
                    fflush(stdin);
                    scanf("%c", &select_car);
                    fflush(stdin);
                    if (select_car=='y') {
                        int fare, chk_timeA, chk_timeB;
                        timer = time(NULL);
                        t = localtime(&timer);
                        chk_timeA = (t->tm_hour * 60) + t->tm_min;
                        chk_timeB = (leave_car->into_ptimeH * 60) + leave_car->into_ptimeM;
                        fare = (chk_timeA - chk_timeB) / 10 * 800;
                        printf("출차가 완료되었습니다.이용시간은 %d분 요금은 %d원 입니다.", chk_timeA - chk_timeB, fare);
                        flag = 0;
                    }
                    else if (select_car == 'n') {
                        fwrite(leave_car, sizeof(car), 1, ft);
                        flag = 0;
                    }
                    else {
                        printf("입력이 잘못 되었습니다.");
                        flag = 1;
                    }
                }
            }
        }
        fclose(fp);
        fclose(ft);
        free(leave_car);

        remove("parking_car.dat");
        rename("temp.dat", "parking_car.dat");

        return pass;


    }

}
