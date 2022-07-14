//
// Created by ODD on 2022/7/11.
//
#include "assign.h"

long courierNumber(int num){
    long i,a[20];
    srand(time(0));

    for ( i = 0; i < 20; ++i) {
        a[i] = rand() +2746815412126722155;
    }
    return a[num];
}



//1、定义函数save，向文件输出商品链表的数据。（链表向磁盘文件输出数据）
//三个参数变量：商品链表、文件名、文件的打开方式
void save(struct Goods *goods, char fileName[], char fileOpenWay[]) {
    FILE *fp;
    struct Goods *goods1 = goods;
    if ((fp = fopen(fileName, fileOpenWay)) == NULL) {
        printf("cannot open file\n");
        return;
    }
    while (goods1 != NULL) {
        fprintf(fp, "%s %s %s\n", goods1->name, goods1->ownerName, goods1->ownerTel);
        goods1 = goods1->next;
    }
    fclose(fp);
}

//2、定义函数read，从文件中读取商品数据并打印。（磁盘文件向终端输入数据）
//一个参数变量：文件名，可以读取不同的文件信息
void read(char fileName[]) {
    FILE *fp;
    //由于读取下来是要结构体方式存储，所以要开辟一个结构体大小的空间。
    struct Goods *goods = (struct Goods *) malloc(LENGTH);
    //此时必须用“a+”，需要读取文件信息
    if ((fp = fopen(fileName, "a+")) == NULL) {
        printf("cannot open file\n");
        exit(0);
    }
    system("clear");
    printf("****************以下是您所查阅的快递信息****************\n\n\n");
    //此函数极其重要，由于打开方式为“a+”，指针会指向文本末尾，通过fseek函数将文件指针指向开头，可以进行全部文件信息的读取
    fseek(fp, 0, 0);
    int num = 1;
    if (fscanf(fp, "%s%s%s\n", goods->name, goods->ownerName, goods->ownerTel) == EOF){
        printf("您查询的结果为空\n");
    }else{
        printf("快递ID  快递名\t\t收货人\t\t快递单号\t\t\t电话号码\t\t\n");

    }
    fseek(fp, 0, 0);
    while (fscanf(fp, "%s%s%s\n", goods->name, goods->ownerName, goods->ownerTel) != EOF) {
        //关于文件输入输出的格式化问题，需要仔细研究。目前知道fscanf函数遇到第一个空格字符结束，进行下一个变量的格式化输入。可以利用这个特点进行输入输出
        //快递的名字不要超过15个字！！！
//        printf("%-10s\t %8ld\t %-10ld\t %-10s\t %10d\n",con[i].name,con[i].tele,con[i].num,con[i].address,con[i].location);

        printf("%-6d  %-10s\t%-10s\t%-20ld\t\t%-10s\t\n", num ,goods->name, goods->ownerName,courierNumber(num),goods->ownerTel);
        num++;
    }
    printf("\n\n");
    printf("*********************************************************\n\n\n");

    fclose(fp);
}
    
//3、向商品链表中添加商品。（增）
//一个参数变量：向哪个链表中添加信息
void add(char addWay[]) {
    struct Goods *goods1 = (struct Goods *) malloc(LENGTH);
    goods1->next = NULL;
    printf("请依次输入快递的名称、收货者的名字以及手机号码:\n");
    printf(">>>:");
    scanf("%s", goods1->name);
    scanf("%s", goods1->ownerName);
    scanf("%s", goods1->ownerTel);
    if (strcmp(addWay, "goods") == 0) {
        if (goodsStart == NULL) {
            printf("菜鸟驿站初始化成功\n");
            goodsStart = goods1;
        }
        goodsEnd = goods1;
    } else if (strcmp(addWay, "goodsTem") == 0) {
        printf("快递存储成功 待取件人取走\n");//买快递
        if (goodsTemStart == NULL) {
            goodsTemStart = goods1;
        } else {
            goodsTemEnd->next = goods1;
        }
        goodsTemEnd = goods1;
    }
}

//4、根据快递名字、所有者名字和电话号码查询快递情况。（查）
void find(char name[], char ownerName[], char ownerTel[]) {
    //所要查询的只有一个快递，但仓库却有两个，所以需要两个文件指针
    FILE *fp;
    FILE *fp1;
    struct Goods *goods = (struct Goods *) malloc(LENGTH);
    struct Goods *goods1 = (struct Goods *) malloc(LENGTH);
    if ((fp = fopen(FILENAME1, "a+")) == NULL) {
        printf("cannot open file\n");
        exit(0);
    }
    if ((fp1 = fopen(FILENAME2, "a+")) == NULL) {
        printf("cannot open file\n");
        exit(0);
    }
    fseek(fp, 0, 0);
    while (fscanf(fp, "%s%s%s\n", goods->name, goods->ownerName, goods->ownerTel) != EOF) {
        if (strcmp(goods->ownerName, ownerName) == 0 && strcmp(goods->name, name) == 0 &&
            strcmp(goods->ownerTel, ownerTel) == 0) {
            printf("\n\n\n*******************************************************\n\n\n");
            printf("***\t您的快递已到达快递点，请及时领取!\t***\n\n\n");
            printf("*******************************************************\n\n\n");

            fclose(fp);
            return;
        }
    }
    fseek(fp1, 0, 0);
    while (fscanf(fp1, "%s%s%s\n", goods1->name, goods1->ownerName, goods1->ownerTel) != EOF) {
        if (strcmp(goods1->ownerName, ownerName) == 0 && strcmp(goods1->name, name) == 0 &&
            strcmp(goods1->ownerTel, ownerTel) == 0) {
            printf("\n\n***********************************************\n\n\n");
            printf("***\t您的快递仍在运送中，请您耐心等待 !\t*** \n\n\n\n");
            printf("****************************************************\n\n");
            fclose(fp1);
            return;
        }
    }
    fclose(fp);
    fclose(fp1);
    printf("\n\n\n您没有正在配送和已送达的快递\n\n\n");
}

//5、改变快递的所有者或者电话号码（改）
//三个变量：快递名、新的收货人的名字及新的电话号码。
//本功能的想法是： 根据快递名查询到旧的收货人的信息和电话号码，再将其更改并更新
void change(char name[], char ownerName[], char ownerTel[], char oldOwnerName[], char oldOwnerTel[]) {
    struct Goods *linkedList(char fileName[]);
//    void save(struct Goods * goods,char fileName[],char fileOpenWay[]);

    //旧的链表数据
    struct Goods *goods = linkedList(FILENAME1);

    //保存链表头，用于更新文件
    struct Goods *head = goods;

    //删除原有文件。此方法很重要，必须先得到原有文件数据形成链表，然后删除文件，再遍历链表进行比较和替换。最后再重新建立一个新的文件
    remove(FILENAME1);

    while (goods != NULL) {
        if (strcmp(goods->name, name) == 0 && strcmp(goods->ownerName, oldOwnerName) == 0 &&
            strcmp(goods->ownerTel, oldOwnerTel) == 0) {
            //字符串替换
            strcpy(goods->ownerName, ownerName);
            strcpy(goods->ownerTel, ownerTel);

            //新的链表信息保存到文件中
            save(head, FILENAME1, "a");
            printf("**********************************************************\n\n\n");
            printf("***\t\t已修改此快递的相应信息\t\t***\n\n\n");
            printf("**********************************************************\n\n");

            return;
        }
        goods = goods->next;
    }
    printf("没有此快递的信息，无法修改\n");
}

//6、读取文件数据，形成快递链表。主要用于比较之后删除数据以及改变数据。(很关键的方法)
//一个参数变量：文件名
struct Goods *linkedList(char fileName[]) {
    struct Goods *head = NULL;
    struct Goods *p1, *p2;
    p1 = p2 = (struct Goods *) malloc(LENGTH);
    FILE *fp;
    if ((fp = fopen(fileName, "a+")) == NULL) {
        printf("file open error!");
        exit(0);
    }
    fseek(fp, 0, 0);
    //将文件数据取出形成链表
    while (fscanf(fp, "%s%s%s\n", p1->name, p1->ownerName, p1->ownerTel) != EOF) {
        if (head == NULL) {
            head = p1;
        } else {
            p2->next = p1;
        }
        p2 = p1;
        p1 = (struct Goods *) malloc(LENGTH);
    }
    p2->next = NULL;
    fclose(fp);
    return head;
}

//7、送快递。需要根据输入的信息将暂存仓库快递信息删除、同时增加仓库快递信息 。（删）
//三个参数变量：快递名、收货人名字、电话号码。
//本方法功能是根据正确信息将快递员手中最先购买的一个快递送往快递仓库
void send(char name[], char ownerName[], char ownerTel[]) {
    struct Goods *linkedList(char fileName[]);
    void save(struct Goods *goods, char fileName[], char fileOpenWay[]);



    //快递仓库数据链表
    struct Goods *goods = linkedList(FILENAME1);

    //暂存快递数据链表
    struct Goods *goodsTem = linkedList(FILENAME2);

    //保存链表头，用于向文件中存储新的链表信息
    struct Goods *goodsHead = goods;
    struct Goods *goodsTemHead = goodsTem;

    //开辟空间，用于存储遍历过程的前节点
    struct Goods *goodsTemPrev = (struct Goods *) malloc(LENGTH);

    //头节点相同
    if (strcmp(goodsTem->ownerName, ownerName) == 0 && strcmp(goodsTem->name, name) == 0 &&
        strcmp(goodsTem->ownerTel, ownerTel) == 0) {
        goodsTemHead = goodsTem->next;
        goodsTem->next = NULL;
        while (goods->next != NULL) {
            goods = goods->next;
        }
        goods->next = goodsTem;
        remove(FILENAME1);
        remove(FILENAME2);
        save(goodsTemHead, FILENAME2, "a");
        save(goodsHead, FILENAME1, "a");
        system("clear");
        printf("\n\n快递已送达菜鸟驿站!\n\n\n\n");
        return;
    }

    //中间或尾部节点相同
    while (goodsTem != NULL) {
        goodsTemPrev = goodsTem;
        goodsTem = goodsTem->next;
        if (goodsTem == NULL) {
            printf("**************************************************\n\n");
            printf("****\t\t送快递失败\t\t***\n\n\n");
            printf("**************************************************\n\n");

            return;
        } else {
            if (strcmp(goodsTem->ownerName, ownerName) == 0 && strcmp(goodsTem->name, name) == 0 &&
                strcmp(goodsTem->ownerTel, ownerTel) == 0) {
                goodsTemPrev->next = goodsTem->next;
                goodsTem->next = NULL;
                while (goods->next != NULL) {
                    goods = goods->next;
                }
                goods->next = goodsTem;
                remove(FILENAME1);
                remove(FILENAME2);
                save(goodsTemHead, FILENAME2, "a+");
                save(goodsHead, FILENAME1, "a+");
                printf("\n\n快递已送达菜鸟驿站!\n\n\n\n");
                return;
            }
        }
    }
}

//8、取快递。删除快递仓库中相应的快递数据。
//两个参数变量：收货人名字、电话号码
//本方法的功能是根据正确信息删除掉快递仓库中相对应的快递信息，即取走快递
void getGoods(char ownerName[], char ownerTel[]) {
    struct Goods *linkedList(char fileName[]);

    //统计取走的快递数量
    int count = 0;

    //得到旧仓库快递信息，形成链表。
    struct Goods *goods = linkedList(FILENAME1);

    //保存链表头，用于建立新文件
    struct Goods *head = goods;

    //开辟空间，用于存储遍历过程的后节点
    struct Goods *goodsAfter = (struct Goods *) malloc(LENGTH);

    //第一个数据即相同
    /*if(strcmp(goods->ownerName,ownerName)==0&& strcmp(goods->ownerTel,ownerTel)==0) {
        head=goods->next;
        remove(FILENAME1);
        save(head,FILENAME1,"a");
    }*/
    while (goods != NULL) {
        //头结点数据相同
        if (strcmp(head->ownerName, ownerName) == 0 && strcmp(head->ownerTel, ownerTel) == 0) {
            head = goods->next;
            goods = goods->next;
            count++;
            continue;
        }
        //后续节点数据相同 ，注意NULL值的判断，遇到NULL值即可中止循环
        goodsAfter = goods->next;
        if (goodsAfter == NULL) {
            break;
        }
        if (strcmp(goodsAfter->ownerName, ownerName) == 0 && strcmp(goodsAfter->ownerTel, ownerTel) == 0) {
            goods->next = goodsAfter->next;
            count++;
            continue;
        } else {
            goods = goods->next;
            goodsAfter = goodsAfter->next;
            if (goodsAfter == NULL) {
                break;
            }
        }
    }
    //更新文件信息时，一定要先删除文件，再将新的链表输出到文件中去
    remove(FILENAME1);
    save(head, FILENAME1, "a");
    if (count > 0) {
        printf("\n\n您已取走所购买的所有快递\n\n\n");
    } else {
        printf("您输入的信息有错误，请重新操作\n");
    }
}

//9、依次创建快递员的账户密码、消费者的账户密码、管理员的账户密码
void create() {
    //这三个身份的账号与密码进行手动创建 ，分别存储到一个文件中。防止身份的混淆
//    struct User courier={"courier","123456"};
//    struct User consumer={"consumer","123456"};
//    struct User manager={"manager","123456"};
//

    struct User courier = {"1", "1"};
    struct User consumer = {"1", "1"};
    struct User manager = {"1", "1"};
    FILE *fp;
    FILE *fp1;
    FILE *fp2;
    if ((fp = fopen("courier.txt", "a")) == NULL) {
        printf("cannot open file\n");
        return;
    }
    if ((fp1 = fopen("consumer.txt", "a")) == NULL) {
        printf("cannot open file\n");
        return;
    }
    if ((fp2 = fopen("manager.txt", "a")) == NULL) {
        printf("cannot open file\n");
        return;
    }
    fprintf(fp, "%s %s\n", courier.account, courier.password);
    fprintf(fp1, "%s %s\n", consumer.account, consumer.password);
    fprintf(fp2, "%s %s\n", manager.account, manager.password);
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
}

//10、进行身份的验证
//三个参数变量：账号、密码、文件名字
int validation(char account[], char password[], char fileName[]) {
    FILE *fp;
    struct User user;
    if ((fp = fopen(fileName, "a+")) == NULL) {
        printf("cannot open file\n");
        return 0;
    }
    fseek(fp, 0, 0);
    while ((fscanf(fp, "%s%s\n", user.account, user.password)) != EOF) {
        if (strcmp(user.account, account) == 0 && strcmp(user.password, password) == 0) {
            system("clear");
            printf("您的身份验证成功 !!\n\n");
            fclose(fp);
            return 1;
        }
    }
    printf("account: %s %s\n",user.account, account);
    printf("password: %s %s",user.password, password);

    printf("您的身份验证失败，请重新进行验证\n");
    fclose(fp);
    return 0;
}

//11、仓库管理人员统计一个人的快递的数量
//两个参数变量：收货人名字、电话号码
void statistics(char ownerName[], char ownerTel[]) {
    struct Goods *linkedList(char fileName[]);

    //计数
    int count = 0;

    //快递仓库链表
    struct Goods *goods = linkedList(   FILENAME1);

    while (goods != NULL) {
        if (strcmp(ownerName, goods->ownerName) == 0 && strcmp(ownerTel, goods->ownerTel) == 0) {
            count++;
        }

        goods = goods->next;
    }
    printf("*********************************************************\n\n\n");
    printf("**\t\t您所统计的消费者的快递数量为：%d\t\t**\n\n\n", count);
    printf("******************************************************\n\n");

}

//12、修改账户的密码信息
//三个参数变量：账户、新密码以及身份
void changePassword(char account[], char newPassword[], char fileName[]) {
    FILE *fp;
    if ((fp = fopen(fileName, "a+")) == NULL) {
        printf("file open error!");
        exit(0);
    }
    struct User user;
    fseek(fp, 0, 0);
    while ((fscanf(fp, "%s%s", user.account, user.password)) != EOF) {
        //账号比较 ,因为在修改密码之前已经进行了身份验证，所以只需要比较账号即可
        if (strcmp(user.account, account) == 0) {
            strcpy(user.password, newPassword);
            fclose(fp);
            //删除原有数据
            remove(fileName);

            if ((fp = fopen(fileName, "a")) == NULL) {
                printf("file open error!");
                exit(0);
            }
            fprintf(fp, "%s %s", user.account, user.password);
            fclose(fp);
            printf("您的密码修改成功，请您牢记您的新密码\n");
            return;
        }
    }
    printf("您的账户输入错误，请重新操作\n");
}

