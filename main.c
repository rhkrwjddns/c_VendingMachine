#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 4
struct vandingMachine
{
    char szGoods[20];
    int nPrice;
    int amount;
    char soldOut[6];
};

void printMenu(struct vandingMachine va[]);
void inputMoney(struct vandingMachine va[]);
void selectMenu(struct vandingMachine va[]);
int nSumMoney=0;    //입금받은 총액, 전역변수


int main()
{
    struct vandingMachine va[SIZE]={{"캔커피",1000,50,"0"},{"핫팩",1000,20,"O"},{"마스크",500,100,"O"},{"그립톡",3000,1,"O"}};
    //1.메뉴와 메뉴개수, 매뉴 가격을 보여준다.
    printMenu(va);

    //2. 요금 을 넣고, 추가입력과 반환여부 확인.
    inputMoney(va);
    //3.메뉴 선택
    selectMenu(va);
    //4.자판기 출력기능

    return 0;
}

void printMenu(struct vandingMachine va[])
{
    printf("***********************************************************************************************************************\n");
    printf("***********************************************************************************************************************\n");
    printf("***********************************************************************************************************************\n");
    printf("***********************************************************************************************************************\n");
    printf("***********************************************************************************************************************\n");
    printf("*****----------**********-------------------**************************************************____________*************\n");
    printf("*****|        |**********|                 |*****/-----===================----＼*************/            ＼***********\n");
    printf("*****| 캔커피 |**********|     핫   팩     |*****|     (,   ,마스크      )     |************|    그립톡    |***********\n");
    printf("*****|        |**********|                 |*****|     (|＼/||＼ (_, |_/ )     |************|              |***********\n");
    printf("*****|        |**********|                 |*****|     (|  `||-＼ _)'| ＼)     |************|              |***********\n");
    printf("*****| %4d원 |**********|      %4d원     |*****|     (       %3d원     )     |************|     %4d원   |***********\n",va[0].nPrice,va[1].nPrice, va[2].nPrice, va[3].nPrice);
    printf("*****|        |**********-------------------*****＼----(=================)-----/************|              |***********\n");
    printf("*****----------*****************************************************************************＼_____________/***********\n");
    printf("******* %4s ***************** %4s ************************ %4s ****************************** %4s *****************\n",va[0].soldOut,va[1].soldOut,va[2].soldOut,va[3].soldOut);
    printf("***********************************************************************************************************************\n");
    printf("***********************************************************************************************************************\n\n");
}

void inputMoney(struct vandingMachine va[])
{
    int nInputMoney=0;  //입금한 금액
    int yesNo=0;    //예, 아니오를 판단할 변수
    while(1)
    {
        printf("현재 투입된 금액 : %d원\n",nSumMoney);
        printf("금액을 투입해 주세요\n0을 입력하여 금액넣기 취소\n(10, 50, 100, 500, 1000, 5000, 10000, 50000)\n");
        scanf("%d",&nInputMoney);
        if(nInputMoney==0)
        {
            goto ask;
        }
        else if (nInputMoney!=50000&&nInputMoney!=10000&&nInputMoney!=5000&&nInputMoney!=1000&&
        nInputMoney!=500&&nInputMoney!=100&&nInputMoney!=50&&nInputMoney!=10)
        {
            system("cls");
            printMenu(va);
            printf("잘못된 금액이 투입되었습니다.\n");
            Sleep(1000);
            system("cls");
            printMenu(va);
            continue;
        }

        else
        {
            ask:    //잘못된 yesNo를 받게 된다면 여기로 돌아오기
            system("cls");
            printMenu(va);
            printf("실행하실 기능을 숫자로 선택해주세요.\n\t메뉴 선택(0)\t금액 추가 투입(1)\t반환(2) : ");
            scanf("%d",&yesNo);
            if(yesNo==0)
            {
                nSumMoney+=nInputMoney;
                yesNo=0;
                selectMenu(va); //그만 넣었으므로, 금액 투입을 그만두고 메뉴선택으로 넘어가기
            }
            else if(yesNo==1)   //계속 투입하므로, 메뉴를 보이면서 총액이 합쳐진 값도 나오게 출력
            {
                nSumMoney+=nInputMoney;
                yesNo=0;
                system("cls");
                printMenu(va);
            }
            else if(yesNo==2)
            {
                printf("잔돈 %d원이 반환되었습니다.\n안녕히 가십시오.",nSumMoney);
                Sleep(3000);
                nSumMoney=0;
                yesNo=0;
                system("cls");
                printMenu(va);
            }
            else    //0, 1, 2가 아닌 값이 들어왔을때, 다시 투입여부를 묻도록 되돌리기
            {
                system("cls");
                printMenu(va);
                printf("현재 투입된 금액 : %d원\n",nSumMoney);
                printf("인식할 수 없는 선택번호입니다.");
                Sleep(1000);
                yesNo=0;
                system("cls");
                printMenu(va);
                goto ask;
            }
        }
    }
    return ;
}

void selectMenu(struct vandingMachine va[])
{
    char select[10]="";
    system("cls");
    printMenu(va);
    printf("현재 투입된 금액 : %d\n",nSumMoney);
    printf("원하시는 메뉴를 한글로 공백없이 정확히 선택해주세요\n");
    scanf("%s", select);
    if(strcmp(select, va[0].szGoods)==0 && nSumMoney-va[0].nPrice>=0)
    {
        if(va[0].amount==0)
        {
            printf("이미 매진된 상품입니다.");
            Sleep(1000);
            system("cls");
            printMenu(va);
            inputMoney(va);
        }
        else
        {
            printf("선택하신 물품 : %s",va[0].szGoods);
            printf("잔액 : %d",nSumMoney-va[0].nPrice);
            va[0].amount--;
            if(va[0].amount==0) strcpy(va[0].soldOut, "매진");
            nSumMoney=nSumMoney-va[0].nPrice;
            Sleep(2000);
            system("cls");
            printMenu(va);
            inputMoney(va);
        }
    }
    else if(strcmp(select, va[1].szGoods)==0 && nSumMoney-va[1].nPrice>=0)
    {
        if(va[1].amount==0)
        {
            printf("이미 매진된 상품입니다.");
            Sleep(1000);
            system("cls");
            printMenu(va);
            inputMoney(va);
        }
        else
        {
            printf("선택하신 물품 : %s",va[1].szGoods);
            printf("잔액 : %d",nSumMoney-va[1].nPrice);
            va[1].amount--;
            if(va[1].amount==0) strcpy(va[1].soldOut, "매진");
            nSumMoney=nSumMoney-va[1].nPrice;
            Sleep(2000);
            system("cls");
            printMenu(va);
            inputMoney(va);
        }
    }
    else if(strcmp(select, va[2].szGoods)==0 && nSumMoney-va[2].nPrice>=0)
    {
        if(va[2].amount==0)
        {
            printf("이미 매진된 상품입니다.");
            Sleep(1000);
            system("cls");
            printMenu(va);
            inputMoney(va);
        }
        else
        {
            printf("선택하신 물품 : %s",va[2].szGoods);
            printf("잔액 : %d",nSumMoney-va[2].nPrice);
            va[2].amount--;
            if(va[2].amount==0) strcpy(va[2].soldOut, "매진");
            nSumMoney=nSumMoney-va[2].nPrice;
            Sleep(2000);
            system("cls");
            printMenu(va);
            inputMoney(va);
        }
    }
    else if(strcmp(select, va[3].szGoods)==0 && nSumMoney-va[3].nPrice>=0)
    {
        if(va[3].amount==0)
        {
            printf("이미 매진된 상품입니다.");
            Sleep(1000);
            system("cls");
            printMenu(va);
            inputMoney(va);
        }
        else
        {
            printf("선택하신 물품 : %s",va[3].szGoods);
            printf("잔액 : %d",nSumMoney-va[3].nPrice);
            va[3].amount--;
            if(va[3].amount==0) strcpy(va[3].soldOut, "매진");
            nSumMoney=nSumMoney-va[3].nPrice;
            Sleep(2000);
            system("cls");
            printMenu(va);
            inputMoney(va);
        }
    }
    //잔액부족과 존재하지 않는 상품을 선택한 경우.
    else if(nSumMoney-va[0].nPrice<0||nSumMoney-va[1].nPrice<0||
    nSumMoney-va[2].nPrice<0||nSumMoney-va[3].nPrice<0)
    {
        printf("잔액이 부족합니다.");
        Sleep(1000);
        system("cls");
        printMenu(va);
        inputMoney(va);
    }
    else
    {
        printf("해당 상품은 판매하고 있지 않습니다.");
        Sleep(1000);
        system("cls");
        printMenu(va);
        inputMoney(va);
    }
    return ;
}
