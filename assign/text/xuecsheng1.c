//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define LENGTH sizeof(struct Goods)
//#define FILENAME1 "stores.txt"
//#define FILENAME2 "packages.txt"
//
///*
//快递员的账号：courier，默认密码：123456
//消费者的账号：consumer，默认密码：123456
//仓库管理人员的账号：manager，默认密码：123456
//*/
//
////角色设计：用户、商品
//struct Goods
//{
//    char name[30];//由于一个汉字占两个字符，快递名字不要超过15个字
//    char ownerName[10];//收货人名字一般为2或3个字
//    char ownerTel[15];//电话号码一般为11位
//    struct Goods * next;//根据输入的数据形成快递链表，存入数据文件中
//};//商品
//
//struct User
//{
//	char account[20];
//	char password[20];
//};
///*struct Consumers{
//    char name[20];
//    char tel[15];
//    char goodsName[20];
//    struct Consumers * next;
//};*///消费者
//
///*struct Courier{
//    char name[20];
//    char tel[15];
//    struct Goods * TSGoods;//快递员手中的暂存快递链表，还未存入快递仓库中
//};*///快递员
//
///*struct Manager{
//    struct  Goods * goods;//快递仓库管理人员管理的仓库快递链表
//};*///快递仓库管理人员
//
////开辟链表。在运行期间存储快递仓库的数据
//struct Goods * goodsStart = NULL;
//struct Goods * goodsEnd = NULL;
//
////开辟链表，在运行期间存储暂存仓库的数据
//struct Goods * goodsTemStart = NULL;
//struct Goods * goodsTemEnd = NULL;
//
////主函数，程序入口
//int main()
//{
//	//函数声明
//    void save(struct Goods *goods, char fileName[], char fileOpenWay[]);
//    void read(char fileName[]);
//    void add(char addWay[]);
//    void find(char name[],char ownerName[],char ownerTel[]);
//    void change(char name[],char ownerName[],char ownerTel[],char oldOwnerName[],char oldOwnerTel[]);
//    void send(char name[],char ownerName[],char ownerTel[]);
//    void getGoods(char ownerName[],char ownerTel[]);
//    void create();
//    int validation(char account[],char password[],char fileName[]);
//    void statistics(char ownerName[],char ownerTel[]);
//    void changePassword(char account[],char newPassword[],char fileName[]);
//
//    //构造菜单界面的变量
//    int welcome;
//    for(welcome=0;welcome<11;welcome++)
//	{
//    	if(welcome==5)
//		{
//    	printf("**                                                欢迎进入快递管理系统                                                **");
//		} else if(welcome==8)
//		{
//			printf("**                                                                                         programmed by 于卓冉       **");
//		} else if(welcome==9)
//		{
//			printf("**                                                                                            计算机类三班            **");
//		}
//		else
//		printf("**                                                                                                                    **");
//	}
//
//
//    int count;
//    printf("*****************************您是否是第一次操作本程序，如果是请按1进行数据初始化，不是请按2*****************************\n");
//    printf("                                                              ------温馨提示：在本程序中，请您以换行的方式输入每一个数据");
//    scanf("%d", &count);
//    if (count == 1)
//	{
//		create();
//        goto A;
//    } else if (count == 2)
//	{
//        goto B;
//    }
//
//    A:
//    for(welcome=0;welcome<11;welcome++)
//	{
//    	if(welcome==5)
//		{
//    		printf("**                                  请依次进行快递仓库、快递员暂存快递初始化                                          **");
//    		printf("                                                                            ------提示：所有初始化信息将被存入数据文件中");
//		} else
//		{
//			printf("**                                                                                                                    **");
//		}
//	}
//
//    //先进行商品仓库的初始化
//    add("goods");
//    goodsEnd = goodsStart;
//
//    //暂存快递初始化
//    add("goodsTem");
//    goodsTemEnd = goodsTemStart;
//
//    /*
//	将初始化的仓库快递链表数据输出到文件中
//	打开方式为“a”，无法进行读，只能进行写入
//	*/
//    save(goodsStart, FILENAME1, "a");
//
//    //将初始化的暂存快递链表数据输出到文件中
//    save(goodsTemStart, FILENAME2, "a");
//
//    //设计菜单
//    B:for(welcome=0;welcome<12;welcome++)
//	{
//    	if(welcome==3)
//		{
//    		printf("********************************************|       快递管理系统菜单      |*********************************************");
//		} else if(welcome==4)
//		{
//			printf("********************************************|                             |*********************************************");
//		} else if(welcome==5)
//		{
//			printf("********************************************|       选择快递员请按1       |*********************************************");
//		} else if(welcome==6)
//		{
//			printf("********************************************|       选择消费者请按2       |*********************************************");
//		} else if(welcome==7)
//		{
//			printf("********************************************|  选择快递仓库管理人员请按3  |*********************************************");
//		} else if(welcome==8)
//		{
//			printf("********************************************-------------------------------*********************************************");
//		} else
//		{
//			printf("************************************************************************************************************************");
//		}
//	}
//
//	//四个变量用于进入不同的身份与功能
//    int number, number1, number2, number3;
//    scanf("%d", &number);
//    if (number == 1)
//	{
//    	printf("**                                         请输入您的账户和密码进行身份验证：                                         **");
//	    char account[20];
//        char password[20];
//        scanf("%s",account);
//	    scanf("%s",password);
//	    if(validation(account,password,"courier.txt")==0)
//		{
//	    	goto B;
//		}
//    	C:for(welcome=0;welcome<12;welcome++)
//		{
//    	if(welcome==2)
//		{
//    		printf("**                                                  您现在是快递员                                                    **");
//		} else if(welcome==4)
//		{
//			printf("**                                          |       选择送快递请按1       |                                           **");
//		} else if(welcome==5)
//		{
//			printf("**                                          |  选择查看手中快递情况请按2  |                                           **");
//		} else if(welcome==6)
//		{
//			printf("**                                          |      选择返回菜单请按3      |                                           **");
//		} else if(welcome==7)
//		{
//			printf("**                                          |      选择修改密码请按4      |                                           **");
//		}
//		  else if(welcome==8)
//		{
//			printf("**                                          -------------------------------                                           **");
//		} else
//		{
//			printf("**                                                                                                                    **");
//		}
//	}
//        scanf("%d", &number1);
//        if (number1 == 1)
//		{
//            char name[30];
//            char ownerName[10];
//            char ownerTel[15];
//            printf("**                                 请依次输入您要送的快递名称、收货者名字、手机号码：                                 **\n");
//            scanf("%s",name);
//            scanf("%s",ownerName);
//            scanf("%s",ownerTel);
//            send(name,ownerName,ownerTel);
//            goto C;
//        } else if (number1 == 2)
//		{
//            read(FILENAME2);
//            goto C;
//        } else if(number1==3)
//		{
//			goto B;
//		} else if(number1==4)
//		{
//			char account[20];
//			char newPassword[20];
//		    printf("**                                             请输入您的账户和新的密码：                                             **");
//		    scanf("%s",account);
//		    scanf("%s",newPassword);
//		    changePassword(account,newPassword,"courier.txt");
//		    goto B;
//		}
//    } else if (number == 2)
//	{
//    	printf("**                                         请输入您的账户和密码进行身份验证：                                         **");
//	    char account[20];
//        char password[20];
//        scanf("%s",account);
//	    scanf("%s",password);
//	    if(validation(account,password,"consumer.txt")==0)
//		{
//	    	goto B;
//		}
//    	D:for(welcome=0;welcome<12;welcome++)
//		{
//    	if(welcome==2)
//		{
//    		printf("**                                                  您现在是消费者                                                    **");
//		} else if(welcome==4)
//		{
//			printf("**                                          |       选择取快递请按1       |                                           **");
//		} else if(welcome==5)
//		{
//			printf("**                                          |      选择购买商品请按2      |                                           **");
//		} else if(welcome==6)
//		{
//			printf("**                                          |    选择查询快递情况请按3    |                                           **");
//		} else if(welcome==7)
//		{
//			printf("**                                          |      选择返回菜单请按4      |                                           **");
//		} else if(welcome==8)
//		{
//			printf("**                                          |      选择修改密码请按5      |                                           **");
//		}
//		 else if(welcome==9)
//		{
//			printf("**                                          -------------------------------                                           **");
//		} else
//		{
//			printf("**                                                                                                                    **");
//		}
//		}
//        scanf("%d", &number2);
//        if (number2 == 1)
//		{
//            char ownerName[10];
//            char ownerTel[15];
//            printf("**                                            请输入您的名字及电话号码：                                              **");
//            scanf("%s",ownerName);
//            scanf("%s",ownerTel);
//            getGoods(ownerName,ownerTel);
//            goto D;
//        } else if (number2 == 2)
//		{
//			//将购买的商品的数据先添加到暂存快递链表中
//            add("goodsTem");
//
//            //只是将链表尾的数据输出到文件中。用“a+”或“a”的方式打开文件，进行追加数据
//            save(goodsTemEnd, FILENAME2, "a+");
//
//            goto D;
//        } else if(number2 == 3)
//		{
//            char name[30];
//            char ownerName[10];
//            char ownerTel[15];
//            printf("**                                    请依次输入您的快递名称、您的名字、手机号码：                                    **");
//            scanf("%s",name);
//            scanf("%s",ownerName);
//            scanf("%s",ownerTel);
//            find(name,ownerName,ownerTel);
//            goto D;
//        } else if(number2==4)
//        {
//        	goto B;
//		} else if(number2==5)
//		{
//			char account[20];
//			char newPassword[20];
//		    printf("**                                             请输入您的账户和新的密码：                                             **");
//		    scanf("%s",account);
//		    scanf("%s",newPassword);
//		    changePassword(account,newPassword,"consumer.txt");
//		    goto B;
//		}
//    } else if (number == 3)
//	{
//    	printf("**                                         请输入您的账户和密码进行身份验证：                                         **");
//	    char account[20];
//        char password[20];
//        scanf("%s",account);
//	    scanf("%s",password);
//	    if(validation(account,password,"manager.txt")==0)
//		{
//	    	goto B;
//		}
//    	E:for(welcome=0;welcome<12;welcome++)
//		{
//    	if(welcome==2)
//		{
//    		printf("**                                             您现在是快递仓库管理人员                                               **");
//		} else if(welcome==4)
//		{
//			printf("**                                      |     选择查看仓库中快递情况请按1     |                                       **");
//		} else if(welcome==5)
//		{
//			printf("**                                      |     选择改变仓库中快递信息请按2     |                                       **");
//		} else if(welcome==6)
//		{
//			printf("**                                      |  选择统计一个消费者的快递数量请按3  |                                       **");
//		} else if(welcome==7)
//		{
//			printf("**                                      |          选择返回菜单请按4          |                                       **");
//		} else if(welcome==8)
//		{
//			printf("**                                      |          选择修改密码请按5          |                                       **");
//		}
//		  else if(welcome==9)
//		{
//			printf("**                                      ---------------------------------------                                       **");
//		} else
//		{
//			printf("**                                                                                                                    **");
//		}
//		}
//        //printf("与消费者沟通，将仓库中的快递输出请按3");
//        scanf("%d", &number3);
//        if (number3 == 1)
//		{
//            read(FILENAME1);
//            goto E;
//        } else if(number3 == 2)
//		{
//        	char name[30];
//            char ownerName[10];
//            char ownerTel[15];
//            char oldOwnerName[10];
//            char oldOwnerTel[15];
//            printf("请输入快递名称、原收货者的名字及电话号码、现收货者的名字及电话号码：\n");
//			scanf("%s",name);
//			scanf("%s",oldOwnerName);
//			scanf("%s",oldOwnerTel);
//            scanf("%s",ownerName);
//            scanf("%s",ownerTel);
//            change(name,ownerName,ownerTel,oldOwnerName,oldOwnerTel);
//            goto E;
//        } else if(number3==3)
//		{
//			char ownerName[10];
//            char ownerTel[15];
//            printf("请输入您要统计的收货者的名字及电话号码：\n");
//            scanf("%s",ownerName);
//            scanf("%s",ownerTel);
//            statistics(ownerName,ownerTel);
//            goto E;
//		} else if(number3==4)
//		{
//			goto B;
//		} else if(number3==5)
//		{
//			char account[20];
//			char newPassword[20];
//		    printf("**                                             请输入您的账户和新的密码：                                             **");
//		    scanf("%s",account);
//		    scanf("%s",newPassword);
//		    changePassword(account,newPassword,"manager.txt");
//		    goto B;
//		}
//    }
//}
//
////1、定义函数save，向文件输出商品链表的数据。（链表向磁盘文件输出数据）
////三个参数变量：商品链表、文件名、文件的打开方式
//void save(struct Goods * goods,char fileName[],char fileOpenWay[])
//{
//    FILE * fp;
//    struct Goods * goods1 = goods;
//    if((fp=fopen(fileName,fileOpenWay))==NULL)
//	{
//        printf("cannot open file\n");
//        return;
//    }
//    while(goods1!=NULL)
//	{
//        fprintf(fp,"%s %s %s\n",goods1->name,goods1->ownerName,goods1->ownerTel);
//        goods1 = goods1->next;
//    }
//    fclose(fp);
//}
//
////2、定义函数read，从文件中读取商品数据并打印。（磁盘文件向终端输入数据）
////一个参数变量：文件名，可以读取不同的文件信息
//void read(char fileName[])
//{
//    FILE * fp;
//    //由于读取下来是要结构体方式存储，所以要开辟一个结构体大小的空间。
//    struct Goods * goods = (struct Goods *) malloc(LENGTH);
//    //此时必须用“a+”，需要读取文件信息
//    if((fp= fopen(fileName,"a+"))==NULL)
//	{
//        printf("cannot open file\n");
//        exit(0);
//    }
//    printf("****                                       以下是您所查阅的快递信息：                                               ****");
//    //此函数极其重要，由于打开方式为“a+”，指针会指向文本末尾，通过fseek函数将文件指针指向开头，可以进行全部文件信息的读取
//    fseek(fp,0,0);
//    while(fscanf(fp,"%s%s%s\n",&goods->name,&goods->ownerName,&goods->ownerTel)!=EOF)
//	{
//	//关于文件输入输出的格式化问题，需要仔细研究。目前知道fscanf函数遇到第一个空格字符结束，进行下一个变量的格式化输入。可以利用这个特点进行输入输出
//        //快递的名字不要超过15个字！！！
//		printf("****    快递名字为：%-30s    ,收货者名字为：%8s     ,收货者电话号码为：%-11s    ****",
//		goods->name,goods->ownerName,goods->ownerTel);
//    }
//    fclose(fp);
//}
//
////3、向商品链表中添加商品。（增）
////一个参数变量：向哪个链表中添加信息
//void add(char addWay[])
//{
//    struct Goods * goods1=(struct Goods *)malloc(LENGTH);
//    goods1->next=NULL;
//    printf("**                               请依次输入快递的名称、收货者的名字以及手机号码                                       **");
//    scanf("%s",goods1->name);
//    scanf("%s",goods1->ownerName);
//    scanf("%s",goods1->ownerTel);
//    if(strcmp(addWay,"goods")==0)
//	{
//        if(goodsStart==NULL)
//		{
//            printf("快递仓库初始化成功\n");
//            goodsStart=goods1;
//        }
//        goodsEnd=goods1;
//    } else if(strcmp(addWay,"goodsTem")==0)
//	{
//        printf("商品购买成功，您的快递已交给快递员处理\n");//买快递
//        if(goodsTemStart==NULL)
//		{
//            goodsTemStart=goods1;
//        } else
//		{
//            goodsTemEnd->next=goods1;
//        }
//        goodsTemEnd=goods1;
//    }
//}
//
////4、根据快递名字、所有者名字和电话号码查询快递情况。（查）
//void find(char name[],char ownerName[],char ownerTel[])
//{
//	//所要查询的只有一个快递，但仓库却有两个，所以需要两个文件指针
//    FILE * fp;
//    FILE * fp1;
//    struct Goods * goods = (struct Goods *) malloc(LENGTH);
//    struct Goods * goods1 = (struct Goods *)malloc(LENGTH);
//    if((fp= fopen(FILENAME1,"a+"))==NULL)
//	{
//        printf("cannot open file\n");
//        exit(0);
//    }
//    if((fp1=fopen(FILENAME2,"a+"))==NULL)
//	{
//        printf("cannot open file\n");
//        exit(0);
//    }
//    fseek(fp,0,0);
//    while(fscanf(fp,"%s%s%s\n",goods->name,goods->ownerName,goods->ownerTel)!=EOF)
//	{
//        if(strcmp(goods->ownerName,ownerName)==0&&strcmp(goods->name,name)==0&& strcmp(goods->ownerTel,ownerTel)==0)
//		{
//            printf("您的快递已到达快递点，请及时领取\n");
//            fclose(fp);
//            return;
//        }
//    }
//    fseek(fp1,0,0);
//    while(fscanf(fp1,"%s%s%s\n",goods1->name,goods1->ownerName,goods1->ownerTel)!=EOF)
//	{
//        if(strcmp(goods1->ownerName,ownerName)==0&&strcmp(goods1->name,name)==0&& strcmp(goods1->ownerTel,ownerTel)==0)
//		{
//            printf("您的快递仍在运送中，请您耐心等待\n");
//            fclose(fp1);
//            return;
//        }
//    }
//    fclose(fp);
//    fclose(fp1);
//    printf("您没有正在配送和已送达的快递\n");
//}
//
////5、改变快递的所有者或者电话号码（改）
////三个变量：快递名、新的收货人的名字及新的电话号码。
////本功能的想法是： 根据快递名查询到旧的收货人的信息和电话号码，再将其更改并更新
//void change(char name[],char ownerName[],char ownerTel[],char oldOwnerName[],char oldOwnerTel[])
//{
//	struct Goods * linkedList(char fileName[]);
//	void save(struct Goods * goods,char fileName[],char fileOpenWay[]);
//
//	//旧的链表数据
//    struct Goods * goods = linkedList(FILENAME1);
//
//    //保存链表头，用于更新文件
//    struct Goods * head = goods;
//
//    //删除原有文件。此方法很重要，必须先得到原有文件数据形成链表，然后删除文件，再遍历链表进行比较和替换。最后再重新建立一个新的文件
//    remove(FILENAME1);
//
//    while(goods!=NULL)
//	{
//        if(strcmp(goods->name,name)==0&&strcmp(goods->ownerName,oldOwnerName)==0&&strcmp(goods->ownerTel,oldOwnerTel)==0)
//		{
//			//字符串替换
//            strcpy(goods->ownerName,ownerName);
//            strcpy(goods->ownerTel,ownerTel);
//
//            //新的链表信息保存到文件中
//            save(head,FILENAME1,"a");
//
//            printf("已修改此快递的相应信息\n");
//            return;
//        }
//        goods=goods->next;
//    }
//    printf("没有此快递的信息，无法修改\n");
//}
//
////6、读取文件数据，形成快递链表。主要用于比较之后删除数据以及改变数据。(很关键的方法)
////一个参数变量：文件名
//struct Goods * linkedList(char fileName[])
//{
//	struct Goods * head=NULL;
//	struct Goods * p1,* p2;
//	p1=p2=(struct Goods *)malloc(LENGTH);
//	FILE * fp;
//	if((fp=fopen(fileName,"a+"))==NULL)
//	{
//		printf("file open error!");
//		exit(0);
//	}
//	fseek(fp,0,0);
//	//将文件数据取出形成链表
//	while(fscanf(fp,"%s%s%s\n",p1->name,p1->ownerName,p1->ownerTel)!=EOF)
//	{
//		if(head==NULL)
//		{
//			head=p1;
//		}
//		else
//		{
//			p2->next=p1;
//		}
//		p2=p1;
//		p1=(struct Goods *)malloc(LENGTH);
//	}
//	p2->next=NULL;
//	fclose(fp);
//	return head;
//}
//
////7、送快递。需要根据输入的信息将暂存仓库快递信息删除、同时增加仓库快递信息 。（删）
////三个参数变量：快递名、收货人名字、电话号码。
////本方法功能是根据正确信息将快递员手中最先购买的一个快递送往快递仓库
//void send(char name[],char ownerName[],char ownerTel[])
//{
//	struct Goods * linkedList(char fileName[]);
//	void save(struct Goods *goods, char fileName[], char fileOpenWay[]);
//
//	//快递仓库数据链表
//	struct Goods * goods = linkedList(FILENAME1);
//
//	//暂存快递数据链表
//	struct Goods * goodsTem = linkedList(FILENAME2);
//
//	//保存链表头，用于向文件中存储新的链表信息
//	struct Goods * goodsHead = goods;
//	struct Goods * goodsTemHead = goodsTem;
//
//	//开辟空间，用于存储遍历过程的前节点
//	struct Goods * goodsTemPrev = (struct Goods *)malloc(LENGTH);
//
//	//头节点相同
//	if(strcmp(goodsTem->ownerName,ownerName)==0&&strcmp(goodsTem->name,name)==0&& strcmp(goodsTem->ownerTel,ownerTel)==0)
//	{
//		goodsTemHead=goodsTem->next;
//		goodsTem->next=NULL;
//		while(goods->next!=NULL)
//		{
//			goods=goods->next;
//		}
//		goods->next=goodsTem;
//		remove(FILENAME1);
//		remove(FILENAME2);
//		save(goodsTemHead,FILENAME2,"a");
//		save(goodsHead,FILENAME1,"a");
//		printf("快递已送达快递仓库\n");
//		return;
//	}
//
//	//中间或尾部节点相同
//	while(goodsTem!=NULL)
//	{
//		goodsTemPrev=goodsTem;
//		goodsTem=goodsTem->next;
//		if(goodsTem==NULL)
//		{
//			printf("送快递失败\n");
//			return;
//		} else
//		{
//			if(strcmp(goodsTem->ownerName,ownerName)==0&&strcmp(goodsTem->name,name)==0&& strcmp(goodsTem->ownerTel,ownerTel)==0)
//			{
//				goodsTemPrev->next=goodsTem->next;
//				goodsTem->next=NULL;
//				while(goods->next!=NULL)
//				{
//					goods=goods->next;
//				}
//				goods->next=goodsTem;
//				remove(FILENAME1);
//		        remove(FILENAME2);
//		        save(goodsTemHead,FILENAME2,"a");
//		        save(goodsHead,FILENAME1,"a");
//		        printf("快递已送达快递仓库\n");
//		        return;
//			}
//		}
//	}
//}
//
////8、取快递。删除快递仓库中相应的快递数据。
////两个参数变量：收货人名字、电话号码
////本方法的功能是根据正确信息删除掉快递仓库中相对应的快递信息，即取走快递
//void getGoods(char ownerName[],char ownerTel[])
//{
//	struct Goods * linkedList(char fileName[]);
//
//	//统计取走的快递数量
//	int count=0;
//
//	//得到旧仓库快递信息，形成链表。
//	struct Goods * goods = linkedList(FILENAME1);
//
//	//保存链表头，用于建立新文件
//	struct Goods * head = goods;
//
//	//开辟空间，用于存储遍历过程的后节点
//	struct Goods * goodsAfter = (struct Goods *)malloc(LENGTH);
//
//	//第一个数据即相同
//	/*if(strcmp(goods->ownerName,ownerName)==0&& strcmp(goods->ownerTel,ownerTel)==0) {
//		head=goods->next;
//		remove(FILENAME1);
//		save(head,FILENAME1,"a");
//	}*/
//	while(goods!=NULL)
//	{
//		//头结点数据相同
//		if(strcmp(head->ownerName,ownerName)==0&& strcmp(head->ownerTel,ownerTel)==0)
//		{
//			head=goods->next;
//			goods=goods->next;
//			count++;
//			continue;
//		}
//		//后续节点数据相同 ，注意NULL值的判断，遇到NULL值即可中止循环
//		goodsAfter=goods->next;
//		if(goodsAfter==NULL)
//		{
//			break;
//		}
//		if(strcmp(goodsAfter->ownerName,ownerName)==0&& strcmp(goodsAfter->ownerTel,ownerTel)==0)
//		{
//			goods->next=goodsAfter->next;
//			count++;
//			continue;
//		}else
//		{
//			goods=goods->next;
//			goodsAfter=goodsAfter->next;
//			if(goodsAfter==NULL)
//			{
//				break;
//			}
//		}
//	}
//	//更新文件信息时，一定要先删除文件，再将新的链表输出到文件中去
//	remove(FILENAME1);
//	save(head,FILENAME1,"a");
//	if(count>0) {
//		printf("您已取走所购买的所有快递\n");
//	} else {
//		printf("您输入的信息有错误，请重新操作\n");
//	}
//}
//
////9、依次创建快递员的账户密码、消费者的账户密码、管理员的账户密码
//void create()
//{
//	//这三个身份的账号与密码进行手动创建 ，分别存储到一个文件中。防止身份的混淆
//	struct User courier={"courier","123456"};
//	struct User consumer={"consumer","123456"};
//	struct User manager={"manager","123456"};
//	FILE * fp;
//	FILE * fp1;
//	FILE * fp2;
//    if((fp=fopen("courier.txt","a"))==NULL)
//	{
//        printf("cannot open file\n");
//        return;
//    }
//    if((fp1=fopen("consumer.txt","a"))==NULL)
//	{
//        printf("cannot open file\n");
//        return;
//    }
//    if((fp2=fopen("manager.txt","a"))==NULL)
//	{
//        printf("cannot open file\n");
//        return;
//    }
//    fprintf(fp,"%s %s\n",courier.account,courier.password);
//    fprintf(fp1,"%s %s\n",consumer.account,consumer.password);
//    fprintf(fp2,"%s %s\n",manager.account,manager.password);
//    fclose(fp);
//    fclose(fp1);
//    fclose(fp2);
//}
//
////10、进行身份的验证
////三个参数变量：账号、密码、文件名字
//int validation(char account[],char password[],char fileName[])
//{
//	FILE * fp;
//	struct User user;
//	if((fp=fopen(fileName,"a+"))==NULL)
//	{
//        printf("cannot open file\n");
//        return 0;
//    }
//    fseek(fp,0,0);
//    while((fscanf(fp,"%s%s\n",user.account,user.password))!=EOF)
//	{
//        if(strcmp(user.account,account)==0&&strcmp(user.password,password)==0)
//		{
//        	printf("您的身份验证成功\n");
//        	fclose(fp);
//		    return 1;
//		}
//    }
//    printf("您的身份验证失败，请重新进行验证\n");
//    fclose(fp);
//    return 0;
//}
//
////11、仓库管理人员统计一个人的快递的数量
////两个参数变量：收货人名字、电话号码
//void statistics(char ownerName[],char ownerTel[])
//{
//	struct Goods * linkedList(char fileName[]);
//
//    //计数
//	int count;
//
//	//快递仓库链表
//	struct Goods * goods=linkedList(FILENAME1);
//
//	while(goods!=NULL)
//	{
//		if(strcmp(ownerName,goods->ownerName)==0&&strcmp(ownerTel,goods->ownerTel)==0)
//		{
//			count++;
//		}
//		goods=goods->next;
//	}
//	printf("您所统计的消费者的快递数量为：%d\n",count);
//}
//
////12、修改账户的密码信息
////三个参数变量：账户、新密码以及身份
//void changePassword(char account[],char newPassword[],char fileName[])
//{
//	FILE * fp;
//	if((fp=fopen(fileName,"a+"))==NULL)
//	{
//		printf("file open error!");
//		exit(0);
//	}
//	struct User user;
//	fseek(fp,0,0);
//	while((fscanf(fp,"%s%s",user.account,user.password))!=EOF)
//	{
//		//账号比较 ,因为在修改密码之前已经进行了身份验证，所以只需要比较账号即可
//		if(strcmp(user.account,account)==0)
//		{
//			strcpy(user.password,newPassword);
//			fclose(fp);
//	        //删除原有数据
//	        remove(fileName);
//
//	        if((fp=fopen(fileName,"a"))==NULL)
//	        {
//		        printf("file open error!");
//		        exit(0);
//	        }
//	            fprintf(fp,"%s %s",user.account,user.password);
//	            fclose(fp);
//	           printf("您的密码修改成功，请您牢记您的新密码\n");
//	           return;
//		}
//	}
//	printf("您的账户输入错误，请重新操作\n");
//}
