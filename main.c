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
int nSumMoney=0;    //�Աݹ��� �Ѿ�, ��������


int main()
{
    struct vandingMachine va[SIZE]={{"ĵĿ��",1000,50,"0"},{"����",1000,20,"O"},{"����ũ",500,100,"O"},{"�׸���",3000,1,"O"}};
    //1.�޴��� �޴�����, �Ŵ� ������ �����ش�.
    printMenu(va);

    //2. ��� �� �ְ�, �߰��Է°� ��ȯ���� Ȯ��.
    inputMoney(va);
    //3.�޴� ����
    selectMenu(va);
    //4.���Ǳ� ��±��

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
    printf("*****|        |**********|                 |*****/-----===================----��*************/            ��***********\n");
    printf("*****| ĵĿ�� |**********|     ��   ��     |*****|     (,   ,����ũ      )     |************|    �׸���    |***********\n");
    printf("*****|        |**********|                 |*****|     (|��/||�� (_, |_/ )     |************|              |***********\n");
    printf("*****|        |**********|                 |*****|     (|  `||-�� _)'| ��)     |************|              |***********\n");
    printf("*****| %4d�� |**********|      %4d��     |*****|     (       %3d��     )     |************|     %4d��   |***********\n",va[0].nPrice,va[1].nPrice, va[2].nPrice, va[3].nPrice);
    printf("*****|        |**********-------------------*****��----(=================)-----/************|              |***********\n");
    printf("*****----------*****************************************************************************��_____________/***********\n");
    printf("******* %4s ***************** %4s ************************ %4s ****************************** %4s *****************\n",va[0].soldOut,va[1].soldOut,va[2].soldOut,va[3].soldOut);
    printf("***********************************************************************************************************************\n");
    printf("***********************************************************************************************************************\n\n");
}

void inputMoney(struct vandingMachine va[])
{
    int nInputMoney=0;  //�Ա��� �ݾ�
    int yesNo=0;    //��, �ƴϿ��� �Ǵ��� ����
    while(1)
    {
        printf("���� ���Ե� �ݾ� : %d��\n",nSumMoney);
        printf("�ݾ��� ������ �ּ���\n0�� �Է��Ͽ� �ݾ׳ֱ� ���\n(10, 50, 100, 500, 1000, 5000, 10000, 50000)\n");
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
            printf("�߸��� �ݾ��� ���ԵǾ����ϴ�.\n");
            Sleep(1000);
            system("cls");
            printMenu(va);
            continue;
        }

        else
        {
            ask:    //�߸��� yesNo�� �ް� �ȴٸ� ����� ���ƿ���
            system("cls");
            printMenu(va);
            printf("�����Ͻ� ����� ���ڷ� �������ּ���.\n\t�޴� ����(0)\t�ݾ� �߰� ����(1)\t��ȯ(2) : ");
            scanf("%d",&yesNo);
            if(yesNo==0)
            {
                nSumMoney+=nInputMoney;
                yesNo=0;
                selectMenu(va); //�׸� �־����Ƿ�, �ݾ� ������ �׸��ΰ� �޴��������� �Ѿ��
            }
            else if(yesNo==1)   //��� �����ϹǷ�, �޴��� ���̸鼭 �Ѿ��� ������ ���� ������ ���
            {
                nSumMoney+=nInputMoney;
                yesNo=0;
                system("cls");
                printMenu(va);
            }
            else if(yesNo==2)
            {
                printf("�ܵ� %d���� ��ȯ�Ǿ����ϴ�.\n�ȳ��� ���ʽÿ�.",nSumMoney);
                Sleep(3000);
                nSumMoney=0;
                yesNo=0;
                system("cls");
                printMenu(va);
            }
            else    //0, 1, 2�� �ƴ� ���� ��������, �ٽ� ���Կ��θ� ������ �ǵ�����
            {
                system("cls");
                printMenu(va);
                printf("���� ���Ե� �ݾ� : %d��\n",nSumMoney);
                printf("�ν��� �� ���� ���ù�ȣ�Դϴ�.");
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
    printf("���� ���Ե� �ݾ� : %d\n",nSumMoney);
    printf("���Ͻô� �޴��� �ѱ۷� ������� ��Ȯ�� �������ּ���\n");
    scanf("%s", select);
    if(strcmp(select, va[0].szGoods)==0 && nSumMoney-va[0].nPrice>=0)
    {
        if(va[0].amount==0)
        {
            printf("�̹� ������ ��ǰ�Դϴ�.");
            Sleep(1000);
            system("cls");
            printMenu(va);
            inputMoney(va);
        }
        else
        {
            printf("�����Ͻ� ��ǰ : %s",va[0].szGoods);
            printf("�ܾ� : %d",nSumMoney-va[0].nPrice);
            va[0].amount--;
            if(va[0].amount==0) strcpy(va[0].soldOut, "����");
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
            printf("�̹� ������ ��ǰ�Դϴ�.");
            Sleep(1000);
            system("cls");
            printMenu(va);
            inputMoney(va);
        }
        else
        {
            printf("�����Ͻ� ��ǰ : %s",va[1].szGoods);
            printf("�ܾ� : %d",nSumMoney-va[1].nPrice);
            va[1].amount--;
            if(va[1].amount==0) strcpy(va[1].soldOut, "����");
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
            printf("�̹� ������ ��ǰ�Դϴ�.");
            Sleep(1000);
            system("cls");
            printMenu(va);
            inputMoney(va);
        }
        else
        {
            printf("�����Ͻ� ��ǰ : %s",va[2].szGoods);
            printf("�ܾ� : %d",nSumMoney-va[2].nPrice);
            va[2].amount--;
            if(va[2].amount==0) strcpy(va[2].soldOut, "����");
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
            printf("�̹� ������ ��ǰ�Դϴ�.");
            Sleep(1000);
            system("cls");
            printMenu(va);
            inputMoney(va);
        }
        else
        {
            printf("�����Ͻ� ��ǰ : %s",va[3].szGoods);
            printf("�ܾ� : %d",nSumMoney-va[3].nPrice);
            va[3].amount--;
            if(va[3].amount==0) strcpy(va[3].soldOut, "����");
            nSumMoney=nSumMoney-va[3].nPrice;
            Sleep(2000);
            system("cls");
            printMenu(va);
            inputMoney(va);
        }
    }
    //�ܾ׺����� �������� �ʴ� ��ǰ�� ������ ���.
    else if(nSumMoney-va[0].nPrice<0||nSumMoney-va[1].nPrice<0||
    nSumMoney-va[2].nPrice<0||nSumMoney-va[3].nPrice<0)
    {
        printf("�ܾ��� �����մϴ�.");
        Sleep(1000);
        system("cls");
        printMenu(va);
        inputMoney(va);
    }
    else
    {
        printf("�ش� ��ǰ�� �Ǹ��ϰ� ���� �ʽ��ϴ�.");
        Sleep(1000);
        system("cls");
        printMenu(va);
        inputMoney(va);
    }
    return ;
}
