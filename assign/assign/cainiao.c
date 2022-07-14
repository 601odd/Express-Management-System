
/*
快递员的账号：courier，默认密码：123456
消费者的账号：consumer，默认密码：123456
仓库管理人员的账号：manager，默认密码：123456
*/


#include "assign.h"
#include "function.c"

//主函数，程序入口
int main() {

    //构造菜单界面的变量
    int welcome;
    for (welcome = 0; welcome < 11; welcome++) {
        if (welcome == 5) {
            system("clear");
            printf("******************************************************\n");
            printf("*** \t\t欢迎进入快递管理系统\t\t***\n\n\n\n\n\n\n");
        } else if (welcome == 8) {
            printf("*** \tprogrammed by 欧星远\t");
        } else if (welcome == 9) {
            printf("计科中外4班\t*** \n\n\n");
            printf("******************************************************\n\n\n");
        } else
            printf("\n");
    }


    int count;
    printf("1.进行数据初始化\n"
           "2.已有数据 直接开始运行\n");
    printf(">>>:");
    scanf("%d", &count);
    system("clear");
    if (count == 1) {
        create();
        goto A;
    } else goto B;

    A:
    for (welcome = 0; welcome < 11; welcome++) {
        if (welcome == 5) {
            printf(" 请进行菜鸟驿站快递初始化！\n\n");
        } else {
            printf("");
        }
    }


    //暂存快递初始化
    add("goodsTem");
    goodsTemEnd = goodsTemStart;

    /*
	将初始化的仓库快递链表数据输出到文件中
	打开方式为“a”，无法进行读，只能进行写入
	*/

//    save(goodsStart, FILENAME1, "a");

    //将初始化的暂存快递链表数据输出到文件中
    save(goodsTemStart, FILENAME2, "a");

    //设计菜单



    B:
    for (welcome = 0; welcome < 12; welcome++) {
        if (welcome == 3) {
            system("clear");
            printf("**********************快递管理系统菜单*************************\n\n");
        } else if (welcome == 4) {
            printf("");
        } else if (welcome == 5) {
            printf("\t***\t\t1.选择快递员模式\t\t***\n");
        } else if (welcome == 6) {
            printf("\t***\t\t2.选择消费者模式\t\t***\n");
        } else if (welcome == 7) {
            printf("\t***\t\t3.选择仓库管理员模式\t\t***\n");
        } else if (welcome == 8) {
            printf("\n");
        } else {
            printf("");
        }
    }

    //四个变量用于进入不同的身份与功能
    int number, number1, number2, number3;
    printf(">>>:");
    scanf("%d", &number);
    if (number == 1) {
        printf("请输入您的账户和密码进行身份验证:\n");
        printf(">>>:");
        char account[20];
        char password[20];
        scanf("%s", account);
        scanf("%s", password);
        if (validation(account, password, "courier.txt") == 0) {
            goto B;
        }
        C:
        for (welcome = 0; welcome < 12; welcome++) {
            if (welcome == 2) {

                printf("********************** 您现在是快递员! *************************\n");
            } else if (welcome == 4) {
                printf("\t***\t\t1.选择送快递\t\t***\n");
            } else if (welcome == 5) {
                printf("\t***\t\t2.选择查看手中快递情况\t***\n");
            } else if (welcome == 6) {
                printf("\t***\t\t3.选择返回菜单\t\t***\n");

            }

            else if (welcome == 8) {
                printf("\n\n");
            } else {
            }
        }
        printf(">>>:");
        scanf("%d", &number1);
        if (number1 == 1) {
            char name[30];
            char ownerName[10];
            char ownerTel[15];
            printf("请依次输入您要送的快递名称、收货者名字、手机号码: \n");
            printf(">>>:");
            scanf("%s", name);
            scanf("%s", ownerName);
            scanf("%s", ownerTel);
            send(name, ownerName, ownerTel);
            goto C;
        } else if (number1 == 2) {
            system("clear");
            read(FILENAME2);
            goto C;
        } else if (number1 == 3) {
            goto B;
        } else if (number1 == 4) {
//            char account[20];
//            char newPassword[20];
//            printf("请输入您的账户和新的密码：\n");
//            scanf("%s", account);
//            scanf("%s", newPassword);
//            changePassword(account, newPassword, "courier.txt");
//            goto B;
        }
    } else if (number == 2) {
        printf("请输入您的账户和密码进行身份验证: \n");
        printf(">>>:");
        char account[20];
        char password[20];
        scanf("%s", account);
        scanf("%s", password);
        if (validation(account, password, "consumer.txt") == 0) {
            goto B;
        }
        D:
        for (welcome = 0; welcome < 12; welcome++) {
            if (welcome == 2) {
                printf("**********************您现在是消费者!**********************\n");
            } else if (welcome == 4) {
                printf("\t***\t\t1.选择取快递\t\t***\n");

            }

            else if (welcome == 6) {
                printf("\t***\t\t2.选择查询快递情况\t***\n");

            } else if (welcome == 7) {
                printf("\t***\t\t3.选择返回菜单\t\t***\n");

            }

            else if (welcome == 9) {
                printf("\n\n");
            } else {
            }
        }
        printf(">>>:");

        scanf("%d", &number2);
        if (number2 == 1) {
            char ownerName[10];
            char ownerTel[15];
            printf("请输入您的取件码和手机号:\n");
            printf(">>>:");
            scanf("%s", ownerName);
            scanf("%s", ownerTel);

            getGoods(ownerName, ownerTel);

            goto D;
        }
        else if (number2 == 2) {

            char name[30];
            char ownerName[10];
            char ownerTel[15];
            printf("请依次输入您的快递名称、您的名字、手机号码:\n");
            printf(">>>:");
            scanf("%s", name);
            scanf("%s", ownerName);
            scanf("%s", ownerTel);
            find(name, ownerName, ownerTel);
            goto D;
        } else if (number2 == 3) {
            goto B;
        }

    } else if (number == 3) {
        printf("请输入您的账户和密码进行身份验证：\n");
        printf(">>>:");
        char account[20];
        char password[20];
        scanf("%s", account);
        scanf("%s", password);
        if (validation(account, password, "manager.txt") == 0) {
            goto B;
        }
        E:
        for (welcome = 0; welcome < 12; welcome++) {
            if (welcome == 2) {
                printf("**********************您现在是菜鸟驿站管理人员!**********************\n\n");
            } else if (welcome == 4) {
                printf("\t***\t\t1.选择查看仓库中快递情况\t\t***\n");
            } else if (welcome == 5) {
                printf("\t***\t\t2.选择改变仓库中快递信息\t\t***\n");
            } else if (welcome == 6) {
                printf("\t***\t\t3.选择统计一个消费者的快递数量\t\t***\n");
            } else if (welcome == 7) {
                printf("\t***\t\t4.选择返回菜单\t\t\t\t***\n");
            }

            else if (welcome == 9) {
                printf("\n\n");
            } else {
            }
        }
        printf(">>>:");
        scanf("%d", &number3);
        if (number3 == 1) {
            system("clear");
            read(FILENAME1);
            goto E;
        } else if (number3 == 2) {
            char name[30];
            char ownerName[10];
            char ownerTel[15];
            char oldOwnerName[10];
            char oldOwnerTel[15];
            printf("请输入快递名称、原收货者的名字及电话号码、现收货者的名字及电话号码(以空格隔开):\n");
            printf(">>>:");
            scanf("%s", name);
            scanf("%s", oldOwnerName);
            scanf("%s", oldOwnerTel);
            scanf("%s", ownerName);
            scanf("%s", ownerTel);
            change(name, ownerName, ownerTel, oldOwnerName, oldOwnerTel);
            goto E;
        } else if (number3 == 3) {
            char ownerName[10];
            char ownerTel[15];
            printf("请输入您要统计的收货者的名字及电话号码：\n");
            printf(">>>:");
            scanf("%s", ownerName);
            scanf("%s", ownerTel);
            statistics(ownerName, ownerTel);
            goto E;
        } else if (number3 == 4) {
            goto B;
        } else if (number3 == 5) {
//            char account[20];
//            char newPassword[20];
//            printf("请输入您的账户和新的密码：\n");
//            scanf("%s", account);
//            scanf("%s", newPassword);
//            changePassword(account, newPassword, "manager.txt");
            goto B;
        }
    }
}


