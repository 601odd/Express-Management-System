//
// Created by ODD on 2022/7/11.
//

#ifndef ASSIGN_ASSIGN_H
#define ASSIGN_ASSIGN_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define LENGTH sizeof(struct Goods)
#define FILENAME1 "stores.txt"
#define FILENAME2 "packages.txt"

//快递
struct Goods {
    char name[30];//由于一个汉字占两个字符，快递名字不要超过15个字
    char ownerName[10];//收货人名字一般为2或3个字
    char ownerTel[15];//电话号码一般为11位
    char packageID[10];
    char company[10];

    struct Goods *next;//根据输入的数据形成快递链表，存入数据文件中
};

//出库
typedef struct outStorageOrders{
    int flowOrderNumber[20];
    int pickUpCode[10];
    int packageID[10];
    int managerID[10];
    int consumersTelNom[11];
    char consumersName[10];
    int outGoingOrdersTime[10];
} outOrder;

//入库
typedef struct inStorageOrders{
    int flowOrderNumber[20];
    int CourierID[10];
    int packageID[10];
    int managerID[10];
    int inGoingOrdersTime[10];
} inOrder;

//角色的账号密码(快递员 消费者 管理员)
struct User {
    char account[20];
    char password[20];
};

///消费者
struct Consumers{
    char name[20];
    char tel[15];
    char goodsName[20];
    int pickUpCode[10];
    struct Consumers * next;
};

///快递员
struct Courier{
    char name[20];
    int courierID[20];
    struct Goods * TSGoods;//快递员手中的暂存快递链表，还未存入快递仓库中
};


struct Manager{
    int managerID[10];      //驿站管理员ID
    struct  Goods * goods;//快递仓库管理人员管理的仓库快递链表
};///快递仓库管理人员



//开辟链表。在运行期间存储快递仓库的数据
struct Goods *goodsStart = NULL;
struct Goods *goodsEnd = NULL;

//开辟链表，在运行期间存储暂存仓库的数据
struct Goods *goodsTemStart = NULL;
struct Goods *goodsTemEnd = NULL;


//函数声明
void save(struct Goods *goods, char fileName[], char fileOpenWay[]);

void read(char fileName[]);

void add(char addWay[]);

void find(char name[], char ownerName[], char ownerTel[]);

void change(char name[], char ownerName[], char ownerTel[], char oldOwnerName[], char oldOwnerTel[]);

void send(char name[], char ownerName[], char ownerTel[]);

void getGoods(char ownerName[], char ownerTel[]);

void create();

int validation(char account[], char password[], char fileName[]);

void statistics(char ownerName[], char ownerTel[]);

void changePassword(char account[], char newPassword[], char fileName[]);

#endif //ASSIGN_ASSIGN_H


long courierNumber(int num);