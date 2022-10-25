#define _CRT_SECURE_NO_WARNINGS
#include"Parking_System.h"


int main()
{
    time_t timer;
    struct tm* t;
    int id, choice, success;
    int into_ptimeH, into_ptimeM;
    char license_plate[20] ,  into_ptime[20];
    char tmp_id[5] = "\0";
    system("cls");
    system("COLOR 02");
    while (1) {
        printf("\n\t\t\t\t\t*************** 주차관리시스템 ***************\n");
        printf("\n\t\t\t\t\t1. 입차");
        printf("\n\t\t\t\t\t2. 요금조회");
        printf("\n\t\t\t\t\t3. 주차현황");
        printf("\n\t\t\t\t\t4. 출차");
        printf("\n\t\t\t\t\t5. 프로그램 종료");
        printf("\n\t\t\t\t\t**********************************************\n");
        printf("\n\t\t\t\t\t번호를 선택하세요: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            timer = time(NULL);
            t = localtime(&timer);
            printf("\n차량번호를 입력하세요: ");
            scanf("%19s", license_plate);
            strncpy(tmp_id, license_plate + (strlen(license_plate) - 4), 4);
            id = atoi(tmp_id);        //차량번호에서 뒷 4자리를 뽑아내어 id로 저장
            fflush(stdin);
            into_ptimeH = t->tm_hour;
            into_ptimeM = t->tm_min;
            printf("\n입차 시간 :%d시 %d분", into_ptimeH, into_ptimeM);
            success = into_parking(id, license_plate, into_ptimeH, into_ptimeM);
            break;
        case 2:
            printf("\n차량번호 뒷 4자리를 입력해 주세요 : ");
            scanf("%d", &id);
            success = rate_check(id);
            break;
        case 3:
            success = view_parking();
            break;
        case 4:
            printf("\n차량번호 뒷 4자리를 입력해 주세요:");
            scanf("%d", &id);
            success = leave_parking(id);
            break;
        case 5:
            printf("\n\n\n");
            exit(1);
        default:
            printf("\n\t\t\t\t\t\t입력값이 정확하지 않습니다. 다시 입력해주세요\n");
            break;
        }
        if (success == pass)
        {
            printf("\n작업을 완료하였습니다.\n");
        }
        else if (success == fail)
        {
            printf("작업에 실패하였습니다.\n");
        }
        else {
            printf("문제발생\n");
        }
    }
    return 0;
}