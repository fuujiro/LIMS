/* Code：fuujiro
   Debug：fuujiro
   设计和后期开发：fuujiro
   手册编写：fuujiro
   支持：大连理工大学创新创业学院-软件算法实践班 */
                             
							   /* 开发者前言 */

/* 该图书管理系统V1.0是大连理工大学2016级电气信息类创新实验班 fuujiro 原创,可以随意使用源码,
   但至少署下我的名字尊重一下我的原创,谢谢理解!!! */
/* 如果你发现了代码运行过程中的bug或者error,请联系我,我的邮箱是fuujiro@foxmail.com */
/* 使用指南: 开发者也就是俺,补充了程序猿手册和用户手册,根据自己需要,可自行在文件夹中翻看,这里只做个小述.
   该系统主体分为2个方面,用户界面和管理员界面,分别对应开发图书管理功能,使用者可自行体验功能.另外,
   进入管理员界面,需要的密码是 123456 ，可以自行修改*/

                               /* 注意事项 */
/* 请在使用之前看一下,因为V1.0版本做的实在仓促,又开发了一些不太熟悉的人机交互,望理解 */
/* 1.由于开发者开发时引入时钟库头文件模拟系统载入状态,所以遇到"输入错误,请输入....",
     不要着急,耐心等待字条从屏幕隐去后再进行输入,以免反复报错 */
/* 2.开发者为体现人机交互,使用getch()一类不回显的函数,来回避输入完成后的回车键,
     以增强用户体验,所以请大家不必敲击回车键 */
/* 3.V1.0系统的开发源码一千多行；有点臃肿，见谅！ */

/*头文件区*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

/*宏定义区*/ 
#define  ADMIN_password "123456" /*管理员登录密码*/

/*结构体声明区*/
typedef struct bookinfo/*系统图书信息 */ 
{
    char number[15];/*图书编号*/
    char name[30];/*图书名称*/
    char author[20];/*作者*/
    char press[30];/*出版社*/ 
    char category[20]; /*类别*/ 
    float price;/*单价*/ 
    int  quantity;/*馆藏量*/
 	int  time;/*借书次数*/ 
}BOOKINFO;

typedef struct bookgrasp/*会员借出的书籍信息*/ 
{
	char number[15];/*图书编号*/
    char name[30];/*图书名称*/
    char author[20];/*作者*/
    char press[30];/*出版社*/ 
    char category[20]; /*类别*/ 
    float price;/*单价*/ 
 	char account[30];/*借书者ID*/
}BOOKGRASP;

typedef struct member/*会员个人信息 */ 
{ 
	char name[30];
	char ID[20];
	char password[30];
	char sex[15];	
	char password_key[30];
}MEMBER; 

/*菜单函数区*/
void menu1();
void menu2();
void menu3();
void AboutMe();

/*工具函数区*/
int compare_password(char password[20]);/*密码比对函数 */  
void clock_delay(); /*时间延时函数*/ 
void password_circle();/*密码框装饰函数*/
void find_account_circle();/*找回帐户弹出框函数*/ 

/*会员信息系统层级函数区*/
int user_account(char account[20]);/*个人账户信息*/ 
void member_log_up();/*会员注册函数*/
int member_log_in(char account[20]);/*会员登录函数*/ 
void ADMIN_watch_member();/*查看会员信息函数*/
void display_memberbook();/*查看所有图书借阅信息函数*/
int check_repeat_ID(char id_account[20]);/*检查账户重复性函数*/ 
void find_account();/*账户找回函数*/ 

/*图书信息系统层级函数区*/
void add_book();/*输入新进的图书信息*/
void delete_book();/*根据图书名称对图书信息进行删除*/
void modify_book();/*修改图书信息*/
void display_book();/*显示全部图书信息*/
void search_book();/*根据图书名称显示图书的信息*/
void borrow_book(char account[20]);/*借书*/
void return_book(char account[20]);/*还书*/
void display_price_lower();/*根据价格列出图书信息*/
void dispaly_popular();/*图书受欢迎度排行榜*/
int check_repeat_book(char number[30]);/*查重书籍编号*/

int main()
{
	int flag1=1,flag2=1,flag3=1;/* flag是判断条件,flag为 1 时为真，为 0 时为假 */
	char choice1,choice2,choice3;
	FILE *p1,*p2,*p3;
	
	system("title 电创1601-fuujiro");
   
    if((p1=fopen("library.txt","r"))==NULL)/*p1是图书管理系统的书籍信息文件指针*/ 
    {
      	p1=fopen("library.txt","w");
      	fclose(p1);
    }
	if((p2=fopen("infomember.txt","r"))==NULL)/*p2是图书管理系统的会员个人信息文件指针*/ 
	{
		p2=fopen("infomember.txt","w");
		fclose(p2);
	}
	if( (p3=fopen("memberbook.txt","r"))==NULL)/*p3是图书管理系统的会员书籍信息文件指针*/ 
	{
		p3=fopen("memberbook.txt","w");
		fclose(p3);
	}
	
	while(flag1)
	{
		system("cls");
		menu1();/*调出主菜单 */ 

  		printf("\n");
  		printf("请您选择(1-5):");
  		choice1=getch();
  		while(choice1!='1'&&choice1!='2'&&choice1!='3'&&choice1!='4'&&choice1!='5')
  			choice1=getch();
  		printf("%c",choice1);
  		fflush(stdin);

  		if(choice1=='1')/*会员登录*/ 
		{
			int flag=0;
			char account1[20],account_choice;
			system("cls");
			password_circle();
			fflush(stdin);
			gets(account1);
			flag=member_log_in(account1);/*账户登录函数*/ 
			if(flag==2)
			{
				system("cls");
				password_circle();
				fflush(stdin);
				gets(account1);
				flag=member_log_in(account1);/*账户登录函数*/	
			} 
			if(flag==1)
			{
    		while(flag2&&flag3){
    		system("cls");
			menu2();
    		printf("\n");
    		printf("请您选择(1-8):");
    		choice2=getch();
    		while(choice2!='1'&&choice2!='2'&&choice2!='3'&&choice2!='4'&&choice2!='5'&&choice2!='6'&&choice2!='7'&&choice2!='8')
  				choice2=getch();
  			printf("%c",choice2);

   			switch(choice2)
    		{
    			case '1':search_book(); break;
    			case '2':borrow_book(account1); break;
    			case '3':return_book(account1); break;
    			case '4':display_book(); break;
    			case '5':display_price_lower();break;
    			case '6':dispaly_popular();break; 
    			case '7':if(user_account(account1))
    						{
								printf("\n\n\t\t\t登录信息改变，请重新登录...");
       		       	  	 		clock_delay();
       		       	  	 		flag3=0;
							}
						 break;
    			case '8':flag2=0;
					     printf("\n\n\t\t\t正在退出用户界面...");
       		       	  	 clock_delay();
						 break;
				default:break;/*虽然压根不会读到default情况，但是怕后来开发者漏掉新加的case的while处理，所以加上*/
    				}
				}
			}else{
				system("cls"); 
				find_account_circle();/*装饰弹出框函数*/ 
				fflush(stdin);
				account_choice=getch();
				while(account_choice!='Y'&&account_choice!='y'&&account_choice!='N'&&account_choice!='n')
      	    		account_choice=getch();
      			printf("%c",account_choice);
				printf("\n");
				if(account_choice=='Y'||account_choice=='y')
					find_account();/*账户找回函数*/ 	
			}
			flag2=1,flag3=1;
		}
	
		else if(choice1=='2')/*会员注册*/ 
		{
			system("cls");
			printf("\n\n\n\t\t\t正在进入用户注册界面...");
			clock_delay();
     	   member_log_up();  
		}
	 
		else if(choice1=='3')/*管理员登录*/ 
		{
			if(compare_password(ADMIN_password))
			{
				printf("\n\n\t\t\t\t  --输入密码正确!--\n\n\t\t\t\t==正在进入管理员界面==\n");
     	  	 	clock_delay(); 
				while(flag2){
				system("cls");
				menu3();
				printf("\n");
				printf("请您选择(1-8):");
				choice3=getch();
				while(choice3!='1'&&choice3!='2'&&choice3!='3'&&choice3!='4'&&choice3!='5'&&choice3!='6'&&choice3!='7'&&choice3!='8')
  					choice3=getch();
  				printf("%c",choice3);
		
 				switch(choice3)
				{
					case '1':add_book(); break;
					case '2':delete_book(); break;
   					case '3':modify_book(); break;
   					case '4':search_book(); break;
   					case '5':display_book(); break;
   					case '6':ADMIN_watch_member();break; 
   					case '7':display_memberbook();break;
   					case '8':flag2=0;
					     	 printf("\n\n\t\t\t正在退出管理员界面...");
         	     	  		 clock_delay();
							 break;
   					default:break;/*虽然压根不会读到default情况，但是怕后来开发者漏掉新加的case的while处理，所以加上*/
   					}
  				}
  			} 
  			else{
  				printf("\n\n\t\t\t\t  --输入密码错误!--\n");
     		   	clock_delay();
			}
			flag2=1; 
 		}
 	
 		else if(choice1=='4')/*关于coder*/ 
 		{
			AboutMe();
		}
	
 		else if(choice1=='5')/*退出系统*/
 		{
 			flag1=0;
		}
	}
	fflush(stdin);
	system("cls");
	printf("你已经安全退出系统!(按任意键关闭界面)\n\n\t欢迎您的再次使用!\n\n\t永远爱你的Fenrari!\n\n");
	getch();
	return 0;
}

void menu1()
{
	system("color E9");
	printf("\n\n");
	printf("\t\t\t *=======================================*\n");
	printf("\t\t\t|  * - * - * Crazy Yang - LIMS * - * - *  |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [1]   会员登录                     | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [2]   会员注册                     | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [3]   管理员登录                   | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [4]   关于最新版本                 | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [5]   退出系统                     | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n");
	printf("\t\t\t *=======================================*\n");
}
void menu2()
{
	system("color BC");
	printf("\n\n");
	printf("\t\t\t *=====================================*\n");
    printf("\t\t\t| | * - * - * -会-员-界-面- * - * - * | |\n");
    printf("\t\t\t| *                                   * |\n");
    printf("\t\t\t| |  [1]   查找图书信息               | |\n");
    printf("\t\t\t| *  [2]   借阅图书                   * |\n");
    printf("\t\t\t| |  [3]   归还图书                   | |\n");
    printf("\t\t\t| *  [4]   书库所有图书信息           * |\n");
    printf("\t\t\t| |  [5]   价位书籍推荐               | |\n");
    printf("\t\t\t| *  [6]   图书受欢迎度排行榜         * |\n");
    printf("\t\t\t| |  [7]   您的账户信息               | |\n");
    printf("\t\t\t| *  [8]   退出用户界面               * |\n");
    printf("\t\t\t| |                                   | |\n");
    printf("\t\t\t| * - * - * - * - * - * - * - * - * - * |\n");
	printf("\t\t\t *=====================================*\n");
}
void menu3()
{
	system("color 1D");
	printf("\n\n");
	printf("\t\t\t *======================================*\n");
	printf("\t\t\t| | * - * - * 管-理-员-界-面 * - * - * | |\n");
	printf("\t\t\t| *                                    * |\n");
	printf("\t\t\t| |  [1]   添加图书                    | |\n");
	printf("\t\t\t| *  [2]   删减图书                    * |\n");
	printf("\t\t\t| |  [3]   修改图书信息                | |\n");
	printf("\t\t\t| *  [4]   查找图书信息                * |\n");
	printf("\t\t\t| |  [5]   显示全部图书信息            | |\n");
	printf("\t\t\t| *  [6]   显示所有会员信息            * |\n");
	printf("\t\t\t| |  [7]   显示所有借阅信息            | |\n");
	printf("\t\t\t| *  [8]   退出管理员界面              * |\n");
	printf("\t\t\t| |                                    | |\n");
	printf("\t\t\t| * - * - * - * - * -- * - * - * - * - * |\n");
	printf("\t\t\t *======================================*\n");
}
void AboutMe()
{
	system("cls");
	printf("Code:  fuujiro\n");
	printf("Debug: fuujiro\n");
	printf("\n\n\t\t使用帮助请查看用户手册或程序猿手册!");
	printf("\n\n");
 	printf(" ^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^**^*^*^*^*^*^*^*^*^\n");
	printf(" | Fenrari做的图书馆这个版本让大家见笑了,里面可能会有些傻傻的地方或者bug! |\n");
	printf(" * 如果大家发现了,一定要联系我哦!我的邮箱是fengziyang97@163.com,笔芯!!!   *\n");
	printf(" |                                ^_^                                     |\n");
	printf(" ^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^**^*^*^*^*^*^*^*^*^\n");
	printf("\n\n按任意键退出.");
	getch();
}

void add_book() /*输入新进的图书信息*/
{
    char choice;
    FILE *p1;
    BOOKINFO newbook;
    int flag;
    system("cls");
    while(1)
      	{
      	flag=0; 
      	fflush(stdin);
		printf("请输入图书编号:");
		gets(newbook.number);
		
		if(check_repeat_book(newbook.number))
		{	
			printf("该图书编号已被使用！");
			printf("\n按任意键重新注册\n\n");
			getch();
			flag=1; 
		}
		else{
			fflush(stdin); 
			printf("请输入书名:");
			gets(newbook.name);
		
			printf("请输入作者:");
			gets(newbook.author);
		
			printf("请输入出版社:");
			gets(newbook.press);
			
			printf("请输入类别(文学/科学/理学/工学/等):");
			gets(newbook.category);
		
			printf("请输入价格:");
			scanf("%f",&newbook.price);
		
			printf("请输入馆藏量:");
			scanf("%d",&newbook.quantity);
		
			printf("请输入借阅次数(新书输入0):");
			scanf("%d",&newbook.time); 
		fflush(stdin);
      	printf("是否保存该条书目(y/n):");
      	choice=getch();
		while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	    choice=getch();
      	printf("%c",choice);
     	if(choice=='Y'||choice=='y')
        {
        	p1=fopen("library.txt","a");
	        fprintf(p1,"%s %s %s %s %s %f %d %d\n",
					newbook.number,newbook.name,newbook.author,newbook.press,
					newbook.category,newbook.price,newbook.quantity,newbook.time);
	        fclose(p1);
        	printf("\n该条书目已添加到library.txt文件中!\n");
       	}
        else
        {
       		printf("\n本条书目未保存!\n");
        }
      	printf("\n\n是否继续添加书目(y/n):");
        choice=getch();
        while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	    choice=getch();
      	printf("%c",choice);
      	printf("\n");
      	} 
     	if(choice=='Y'||choice=='y'||flag==1)
        	continue;
      	else
       	 	break;
      }
}

void display_book()/*显示全部图书信息*/
{
    FILE *p1;
    int n;
    BOOKINFO bookinfo[100];
    int booknumber=0;
    system("cls");
    fflush(stdin);
    p1=fopen("library.txt","r");
    while(!feof(p1))
    {
      	fscanf(p1,"%s %s %s %s %s %f %d %d\n",
				bookinfo[booknumber].number,bookinfo[booknumber].name,bookinfo[booknumber].author,
				bookinfo[booknumber].press,bookinfo[booknumber].category,
				&bookinfo[booknumber].price,&bookinfo[booknumber].quantity,&bookinfo[booknumber].time);
      	booknumber++;
    }
    fclose(p1);
    printf("当前图书馆内有%d目书籍\n\n",booknumber);
    if(bookinfo[0].quantity==0)
    {
      	printf("\n没有任何图书信息!\n\n");
    }
    else
    {
      	n=0;
      	printf("|---------------------------------图书信息---------------------------------|\n");
      	printf("|编号  书名        作者      出版社          类别    单价    馆藏量  借阅数|\n");
      	printf("|                                                                          |\n");
      	while(n<booknumber)
        {
        	printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n",bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
                        bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
        	n++;
        }
      }
    printf("\n\n按任意键返回上一级菜单!\n");
   	getch();
}

void search_book()/*根据图书名称显示图书的信息*/
{
	int flag=1,flag1=1;
	char select;
    char name_compare[30]="";/*name_compare用来存放要查询的书名*/
   	char number_compare[30]=""; /*number_compare用来存放要查询的书籍编号*/
   	char author_compare[30]="";/*author_compare用来存放要查询的作者姓名*/
	char search[30]="";/*search是比对数组,将需要查找的数组读进比对数组*/
	char compare[30]="";/*compare是比对数组,将书库中的数组读进比对数组*/
    int n=0;
    FILE *p1;
    char choice;
    BOOKINFO bookinfo[100];
    int booknumber=0;

    system("cls");
    fflush(stdin);
    p1=fopen("library.txt","r");
    while(!feof(p1))
    {
      	fscanf(p1,"%s %s %s %s %s %f %d %d\n",
				bookinfo[booknumber].number,bookinfo[booknumber].name,bookinfo[booknumber].author,
				bookinfo[booknumber].press,bookinfo[booknumber].category,
				&bookinfo[booknumber].price,&bookinfo[booknumber].quantity,&bookinfo[booknumber].time);
      	booknumber++;
    }
    fclose(p1);

	while(flag)
    {
		system("cls");
    	while(flag1)
		{
			system("cls");
			fflush(stdin);
			printf("您想通过\n\n1.<-图书编号->\n\n2.<-书名->\n\n3.<-作者名->\n\n哪种方式查询图书:");
    		select=getch();
    		printf("%c",select);
			printf("\n\n请您输入查找信息:");		
			switch(select)
			{
				case '1':gets(number_compare);strcpy(search,number_compare);flag1=0;break;
				case '2':gets(name_compare);strcpy(search,name_compare);flag1=0;break;
				case '3':gets(author_compare);strcpy(search,author_compare);flag1=0;break;
				default :
					printf("\n不要输入菜单之外的数字~按任意键继续！");
					fflush(stdin);
            	    getch(); 
			}
		}

	flag1=1;
    if(bookinfo[0].quantity==0)
    {
      	printf("书库中没有任何信息!\n\n");
      	printf("按任意键回到主菜单!\n\n");
      	getch();
      	break;
    }
    else
    {
     	for(n=0;n<booknumber;n++)
      	{
      		switch(select)
      		{
      			case '1':strcpy(compare,bookinfo[n].number);break;
      			case '2':strcpy(compare,bookinfo[n].name);break;
      			case '3':strcpy(compare,bookinfo[n].author);break;
			}
        	if(strcmp(compare,search)==0)
          	{
         		printf("|---------------------------------图书信息---------------------------------|\n");
      			printf("|编号  书名        作者      出版社          类别    单价    馆藏量  借阅数|\n");
      			printf("|                                                                          |\n");
    			printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n",bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
                        bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
       			break;
			}
       	}
   			if(n>=booknumber)
       		printf("\n没有查找符合您要求的书籍!\n");
       		
      		printf("\n\n是否继续查询(y/n):");
      		choice=getch();
     		while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	    	choice=getch();
      		printf("%c",choice);
      		printf("\n");
      		if(choice=='Y'||choice=='y')
       			flag=1;
      		else
      			flag=0;
       		
       }
	}
}

void delete_book()/*根据图书名称对图书信息进行删除*/
{
    char search[20]="";/*search用来存放要删除的书名*/
    int n,i;
    FILE *p1;
    char choice;
    BOOKINFO bookinfo[100];
    int booknumber;

    system("cls");
    while(1)
    {
    	fflush(stdin);
        printf("输入要删除的书本名称:");
      	gets(search);
     	p1=fopen("library.txt","r");
      	booknumber=0;
      	while(!feof(p1))
        {
        	fscanf(p1,"%s %s %s %s %s %f %d %d\n",
				bookinfo[booknumber].number,bookinfo[booknumber].name,bookinfo[booknumber].author,
				bookinfo[booknumber].press,bookinfo[booknumber].category,
				&bookinfo[booknumber].price,&bookinfo[booknumber].quantity,&bookinfo[booknumber].time);
        	booknumber++;
        }
     	fclose(p1);
      	if(bookinfo[0].quantity==0)
        {
        	printf("书库中没有任何信息!\n\n");
        	printf("按任意键回到主菜单!\n\n");
        	getch();
        	break;
        }/*if结束*/
        else
        {
        	for(n=0;n<booknumber;n++)
            if(strcmp(bookinfo[n].name,search)==0)
            {
           		break;
            }
        	if(n>=booknumber)
          		printf("\n没有查找该书的任何信息!\n");
        	else
            {
           		printf("\n是否确认需要删除该条书目(Y/N):");
           		choice=getch();
             	while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	    		choice=getch();
      			printf("%c",choice);
           		if(choice=='Y'||choice=='y')
             	{
             		for(i=n;i<booknumber-1;i++)
               			bookinfo[i]=bookinfo[i+1];
             		booknumber--;
           			p1=fopen("library.txt","w");
                	for(n=0;n<booknumber;n++)
               		fprintf(p1,"%s %s %s %s %s %f %d %d\n",
						bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
						bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
             		fclose(p1);
           			printf("\n删除成功!");
             	}
           		else
              		printf("\n该条书目没有被删除!");
           }
            printf("\n\n是否继续进行删除操作(y/n):");
         		choice=getch();
         	while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	   		choice=getch();
      		printf("%c",choice);
      		printf("\n");
         	if(choice=='Y'||choice=='y')
           		continue;
         	else
           		break;
        }/*else结束*/
      }/*while(1)结束*/
    }

void display_price_lower()/*根据价格列出图书信息*/
{
    float price;
    FILE *p1;
    int n;
    int count=0;
    BOOKINFO bookinfo[100];
    int booknumber;

    system("cls");
    printf("请输入你的理想价格,我们将推荐比您理想价位稍低的书籍:");
    scanf("%f",&price);
    p1=fopen("library.txt","r");
    booknumber=0;
    while(!feof(p1))
    {
      	fscanf(p1,"%s %s %s %s %s %f %d %d\n",
				bookinfo[booknumber].number,bookinfo[booknumber].name,bookinfo[booknumber].author,
				bookinfo[booknumber].press,bookinfo[booknumber].category,
				&bookinfo[booknumber].price,&bookinfo[booknumber].quantity,&bookinfo[booknumber].time);
      	booknumber++;
    }
    fclose(p1);
    if(bookinfo[0].quantity==0)
    {
      	printf("\n没有任何图书信息!\n");
    }
    else
    {
      	for(n=0;n<booknumber;n++)
        {
        	if(bookinfo[n].price<=price)
          	count++;
        }
      	if(count==0)
       		printf("书库中没有比%.1f元价格更低的图书。",price);
      	else
        {
        	printf("\n价格低于%.1f元的图书信息有%d本\n",price,count);
       		printf("|---------------------------------图书信息---------------------------------|\n");
      		printf("|编号  书名        作者      出版社          类别    单价    馆藏量  借阅数|\n");
      		printf("|                                                                          |\n");
        	for(n=0;n<booknumber;n++)
          	{
          		if(bookinfo[n].price<=price)
            	printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n",bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
                        bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
          	}
        }
      }
    printf("\n\n按任意键回到主菜单!\n");
    getch();
    }

void modify_book()
{
	int flag=1,flag1=1,flag2,n;
	char change,choice;
	char number[15];/*图书编号*/
    char name[30];/*图书名称*/
    char author[20];/*作者*/
   	char press[30];/*出版社*/
	char category[20];/*类别*/ 
    int  quantity;/*藏书量*/
    float price;/*单价*/
    
	char search[30];/*要修改的书名*/ 
	FILE *p1;
	BOOKINFO bookinfo[100];
	int booknumber;
    while(flag)
    {
    	flag2=0;
    	system("cls");
    	fflush(stdin);
      	printf("输入要修改信息的书本名:");
      	gets(search);
      	p1=fopen("library.txt","r");
      	booknumber=0;
      	while(!feof(p1))
        {
        	fscanf(p1,"%s %s %s %s %s %f %d %d\n",
				bookinfo[booknumber].number,bookinfo[booknumber].name,bookinfo[booknumber].author,
				bookinfo[booknumber].press,bookinfo[booknumber].category,
				&bookinfo[booknumber].price,&bookinfo[booknumber].quantity,&bookinfo[booknumber].time);
        	booknumber++;
        }
      	fclose(p1);
      	if(bookinfo[0].quantity==0)
        {
        	printf("书库中没有任何信息!\n\n");
        	printf("按任意键回到主菜单!\n\n");
        	getch();
        	break;
        }
        else
        {
        	for(n=0;n<booknumber;n++)
         		if(strcmp(bookinfo[n].name,search)==0)
            	{
            		printf("\n"); 
         			printf("|---------------------------------图书信息---------------------------------|\n");
      				printf("|编号  书名        作者      出版社          类别    单价    馆藏量  借阅数|\n");
      				printf("|                                                                          |\n");
    				printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n",bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
                     	   bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
       				
					while(flag1){
					printf("\n1.书籍编号\n2.书籍名称\n3.书籍作者\n4.出版社\n5.书籍类别\n6.书籍单价\n7.藏书量\n\n您想要修改的是:");
					change=getch();
					while(change!='1'&&change!='2'&&change!='3'&&change!='4'&&change!='5'&&change!='6'&&change!='7')
  						change=getch();
  					printf("%c",change);
           			printf("\n请输入新的字条:");
           			fflush(stdin);
            		switch(change)
            		{
            			case '1':gets(number);flag1=0;flag2=check_repeat_book(number);
									if(!flag2)
										strcpy(bookinfo[n].number,number);
								break;
            			case '2':gets(name);strcpy(bookinfo[n].name,name);flag1=0;break;
            			case '3':gets(author);strcpy(bookinfo[n].author,author);flag1=0;break;
            			case '4':gets(press);strcpy(bookinfo[n].press,press);flag1=0;break;
            			case '5':gets(category);strcpy(bookinfo[n].category,category);flag1=0;break;
            			case '6':scanf("%f",&price);bookinfo[n].price=price;flag1=0;break;
            			case '7':scanf("%d",&quantity);bookinfo[n].quantity=quantity;flag1=0;break;
            			default:break;/*虽然压根不会读到default情况，但是怕后来开发者漏掉新加的case的while处理，所以加上*/
					}
				}
			flag1=1;
            break;
            }
        if(n>=booknumber)
           printf("\n没有查找该书的任何信息!");
        else if(!flag2)
        {
            p1=fopen("library.txt","w");
            for(n=0;n<booknumber;n++)
            fprintf(p1,"%s %s %s %s %s %f %d %d\n",
					bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
					bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
            fclose(p1);
            printf("\n修改成功!");
        }
        else
        	printf("您想修改的图书信息与馆内信息重复。"); 
   		printf("\n是否继续进行修改(y/n):");
        choice=getch();
        while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	    choice=getch();
      	printf("%c",choice);
      	printf("\n");
        if(choice=='Y'||choice=='y')
            flag=1;
        else
            flag=0;
    	}
	}
}

void borrow_book(char account[20])
{
	FILE *p1,*p3;
	BOOKINFO bookinfo[100];
	char search[30],choice;
	int flag=1,n;
	int booknumber1;
	system("cls");

    while(flag)
    {
      	printf("输入要借阅的书本名:");
      	gets(search);
      	p1=fopen("library.txt","r");
      	booknumber1=0;
      	while(!feof(p1))
        {
        	fscanf(p1,"%s %s %s %s %s %f %d %d\n",
				bookinfo[booknumber1].number,bookinfo[booknumber1].name,bookinfo[booknumber1].author,
				bookinfo[booknumber1].press,bookinfo[booknumber1].category,
				&bookinfo[booknumber1].price,&bookinfo[booknumber1].quantity,&bookinfo[booknumber1].time);
        	booknumber1++;
        }
      	fclose(p1);
	
      	if(bookinfo[0].quantity==0)
        {
        	printf("\n书库中没有任何信息!\n");
        	printf("按任意键回到主菜单!\n\n");
        	getch();
        	break;
        }
        else
        {
        	for(n=0;n<booknumber1;n++)
         		if(strcmp(bookinfo[n].name,search)==0)
            	{
					bookinfo[n].quantity--;
					bookinfo[n].time++;
					
					p3=fopen("memberbook.txt","a");  /*借书以a追加的方式，在文件中增加一本书*/ 
					fprintf(p1,"%s %s %s %s %s %f %s\n",
							bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,bookinfo[n].press,
							bookinfo[n].category,bookinfo[n].price,account);
					fclose(p3); 
					break;
				}
            }
        if(n>=booknumber1)
           printf("\n没有查找该书的任何信息!\n");
        else
        {
            p1=fopen("library.txt","w");
            for(n=0;n<booknumber1;n++)
            fprintf(p1,"%s %s %s %s %s %f %d %d\n",
					bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,bookinfo[n].press,
					bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
            fclose(p1);
            printf("\n借书成功!\n");
        }
   		printf("\n是否继续借书(y/n):");
        choice=getch();
        while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	    choice=getch();
      	printf("%c",choice);
      	printf("\n");
        if(choice=='Y'||choice=='y')
            flag=1;
        else
            flag=0;
    }
}

void return_book(char account[20])
{
	FILE *p1,*p3;
	BOOKINFO bookinfo[100];
	BOOKGRASP bookgrasp[100];
	char search[30],choice;
	int flag=1,flag2=0,n,i,k,j,t=0;
	int booknumber,booknumber2;
	system("cls");
	
    while(flag)
    {
    	flag2=0;
    	fflush(stdin);
      	p1=fopen("library.txt","r");
      	booknumber=0;
      	while(!feof(p1))
        {
        	fscanf(p1,"%s %s %s %s %s %f %d %d\n",
				bookinfo[booknumber].number,bookinfo[booknumber].name,bookinfo[booknumber].author,
				bookinfo[booknumber].press,bookinfo[booknumber].category,
				&bookinfo[booknumber].price,&bookinfo[booknumber].quantity,&bookinfo[booknumber].time);
        	booknumber++;
        }
      	fclose(p1);
      	
    	p3=fopen("memberbook.txt","r");
		booknumber2=0;
		while(!feof(p3))
		{
			fscanf(p3,"%s %s %s %s %s %f %s\n",
					bookgrasp[booknumber2].number,bookgrasp[booknumber2].name,bookgrasp[booknumber2].author,bookgrasp[booknumber2].press,
					bookgrasp[booknumber2].category,&bookgrasp[booknumber2].price,bookgrasp[booknumber2].account);
			booknumber2++;
		}
		fclose(p3);				
      	
		printf("您所借阅的所有图书信息如下:\n"); 
        printf("|----------------------------图书借阅信息--------------------|\n");
      	printf("|编号  书名        作者      出版社          类别    单价    |\n");
        while(t<booknumber2)
       	{
        	if(strcmp(bookgrasp[t].account,account)==0)
        	{
				printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f|\n",bookgrasp[t].number,
						bookgrasp[t].name,bookgrasp[t].author,bookgrasp[t].press,
						bookgrasp[t].category,bookgrasp[t].price);
			}
        	t++;
        }
      	
      	printf("\n输入要归还的书本名:");
      	gets(search);
      	if(bookinfo[0].quantity==0)
        {
        	printf("\n书库中没有任何信息!\n");
        	printf("按任意键回到主菜单!\n\n");
        	getch();
        	break;
        }
        else
        {
        	for(n=0;n<booknumber;n++)
         		if(strcmp(bookinfo[n].name,search)==0)
            	{
						bookinfo[n].quantity++;

						if(bookgrasp[0].price==0)
							printf("\n您没有借书信息。");
						else{
						for(k=0;k<booknumber2;k++)
							if(!strcmp(bookgrasp[k].account,account)&&!strcmp(bookgrasp[k].name,search))
							{
								flag2=1;
								for(i=k;i<booknumber2-1;i++)
               						bookgrasp[i]=bookgrasp[i+1];
               					booknumber2--;
               					break;
               				}
               			
						p3=fopen("memberbook.txt","w");
						for(j=0;j<booknumber2;j++)
						{
							fprintf(p3,"%s %s %s %s %s %f %s\n",
								bookgrasp[j].number,bookgrasp[j].name,bookgrasp[j].author,bookgrasp[j].press,
								bookgrasp[j].category,bookgrasp[j].price,bookgrasp[j].account);
						}
						fclose(p3);
						}
						break;
					}
				} 
        if(n==booknumber||flag2==0)
        	printf("您并没有这条借阅信息!\n"); 
        if(n<booknumber&&flag2==1)
        {
            p1=fopen("library.txt","w");
            for(n=0;n<booknumber;n++)
            fprintf(p1,"%s %s %s %s %s %f %d %d\n",
				bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
				bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
            fclose(p1); 
            printf("\n还书成功！");
        }
        else
        	printf("\n还书失败！");
        
		fflush(stdin);	
   		printf("\n是否继续还书(y/n):");
        choice=getch();
        while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	    choice=getch();
      	printf("%c",choice);
      	printf("\n");
        if(choice=='Y'||choice=='y')
            flag=1;
        else
            flag=0;
	}
}

void dispaly_popular()/*图书受欢迎度排行榜*/ 
{
    FILE *p1;
    int n,i,j,k;
    int count=0;
    BOOKINFO bookinfo[101];
    int booknumber;
    
    system("cls");
    fflush(stdin);
    p1=fopen("library.txt","r");
    booknumber=0;
    while(!feof(p1))
    {
      	fscanf(p1,"%s %s %s %s %s %f %d %d\n",
				bookinfo[booknumber].number,bookinfo[booknumber].name,bookinfo[booknumber].author,
				bookinfo[booknumber].press,bookinfo[booknumber].category,
				&bookinfo[booknumber].price,&bookinfo[booknumber].quantity,&bookinfo[booknumber].time);
      	booknumber++;
    }
    fclose(p1);
    
    if(bookinfo[0].quantity==0)
    {
      	printf("没有任何图书信息!\n\n");
    }
    else
    {
      	for(i=0;i<booknumber-1;i++)
      	{
      		k=i;
      		for(j=i+1;j<booknumber;j++)
      			if(bookinfo[j].time>bookinfo[k].time)
      				k=j;
      		if(k!=i)
      		{
      			bookinfo[100]=bookinfo[i];
      			bookinfo[i]=bookinfo[k];
      			bookinfo[k]=bookinfo[100];
      		}
      	}
        	
       		printf("|---------------------------图书受欢迎度排行榜-----------------------------|\n");
      		printf("|编号  书名        作者      出版社          类别    单价    馆藏量  借阅数|\n");
      		printf("|                                                                          |\n");
        	for(n=0;n<booknumber;n++)
          	{
            	printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n",bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
                        bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
          	}
        
      }
    printf("\n\n按任意键回到主菜单!\n");
    getch();
}

int check_repeat_book(char number[30])
{
	FILE *p1;
	BOOKINFO bookinfo[100];
	int flag1=0,flag2=1,n,booknumber;
	
    p1=fopen("library.txt","r");
   	booknumber=0;
    while(!feof(p1))
    {
        fscanf(p1,"%s %s %s %s %s %f %d %d\n",
				bookinfo[booknumber].number,bookinfo[booknumber].name,bookinfo[booknumber].author,
				bookinfo[booknumber].press,bookinfo[booknumber].category,
				&bookinfo[booknumber].price,&bookinfo[booknumber].quantity,&bookinfo[booknumber].time);
       	booknumber++;
    }
    fclose(p1);
	for(n=0;n<booknumber;n++)
    	if(strcmp(bookinfo[n].number,number)==0)
    	{
    	    flag1=1;
			break;
		}
		if(flag1)
		{
			return 1;
   		}
   		else{
            return 0;
		}
}

void member_log_up()
{
	char choice1,choice2;
	int flag=1; 
	FILE *p2;
	MEMBER member;
	
	while(1)
	{
		system("cls");
		fflush(stdin);
	
		printf("输入您想注册的ID名:");
		gets(member.ID);
		
		if(check_repeat_ID(member.ID))
		{	
			printf("该ID已被注册！请重新注册^_^\n");
			printf("按任意键重新注册\n\n");
			getch();
			flag=1; 
		}
		else{
			flag=0;
			printf("输入您的密码(不要告知他人):");
			gets(member.password);
			
			printf("输入找回密码的密钥(以免忘记账户或密码不能登陆！):"); 
			gets(member.password_key); 
			
			printf("输入您的姓名:");
			gets(member.name);
	
			printf("输入您的性别(男士输入male,女士输入female):");
			gets(member.sex);
	
			printf("是否保存这次注册信息(y/n):");
    		choice1=getch();
    		while(choice1!='Y'&&choice1!='y'&&choice1!='N'&&choice1!='n')
      	    	choice1=getch();
      	    printf("%c",choice1);
 			printf("\n");
   	 	if(choice1=='Y'||choice1=='y')
    	{
        	p2=fopen("infomember.txt","a");
	    	fprintf(p2,"%s %s %s %s %s\n",member.ID,member.password,
					member.password_key,member.name,member.sex);
	    	fclose(p2);
			printf("\n您的账户已注册成功！\n");
    	}
    	else
    	{
       		printf("\n您的注册信息未保存!\n");
    	}
    	printf("\n是否继续注册会员(y/n):");
        choice2=getch();
        while(choice2!='Y'&&choice2!='y'&&choice2!='N'&&choice2!='n')
      	    choice2=getch();
      	printf("%c",choice2);
      	printf("\n");
    	}
     	if(choice2=='Y'||choice2=='y'||flag==1)
        	continue;
      	else
       	 	break;
	}
}

int user_account(char account[20])
{
	FILE *p2,*p3;
	int n,number,booknumber,flag=0,i,flag2=1,count=0;
	char new_password[20],key[30],choice;
	MEMBER member[100];
	BOOKGRASP bookgrasp[100];
	system("cls");
	
	p2=fopen("infomember.txt","r");	
	number=0;	
	while(!feof(p2))
	{
		fscanf(p2,"%s %s %s %s %s\n",member[number].ID,member[number].password,
				member[number].password_key,member[number].name,member[number].sex);
		number++;
	}
	fclose(p2);
	
	p3=fopen("memberbook.txt","r");
			booknumber=0;
			while(!feof(p3))
			{
				fscanf(p3,"%s %s %s %s %s %f %s\n",
						bookgrasp[booknumber].number,bookgrasp[booknumber].name,bookgrasp[booknumber].author,bookgrasp[booknumber].press,
						bookgrasp[booknumber].category,&bookgrasp[booknumber].price,bookgrasp[booknumber].account);
				booknumber++;
			}
			fclose(p3);
			if(bookgrasp[0].price<=1e-8)
			{
				printf("当前图书馆未有任何借书信息");
				flag=0;
				printf("\n\n按任意键返回!\n");
   				getch();
			}
			else{ 		
				for(n=0;n<number;n++)
					if(strcmp(member[n].ID,account)==0)
					{
						i=0;
						printf("\n");
						printf("|---------------------------个人信息-------------------------|\n");
    					printf("|姓名        性别      ID              密码                  |\n");
    					printf("|%-12s%-10s%-16s%-22s%|\n",member[n].name,member[n].sex,member[n].ID,member[n].password);
    					printf("|                                                            |\n");
    					printf("|----------------------------图书借阅信息--------------------|\n");
      					printf("|编号  书名        作者      出版社          类别    单价    |\n");
      		
      					while(i<booknumber)
       				 	{
        					if(strcmp(bookgrasp[i].account,account)==0)
        					{
							printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f|\n",bookgrasp[i].number,
									bookgrasp[i].name,bookgrasp[i].author,bookgrasp[i].press,
									bookgrasp[i].category,bookgrasp[i].price);
							count++;
							}
        					i++;
        				}
        				if(strcmp(member[n].sex,"male")==0) 
       				 	printf("\n%s先生，您当前借阅的书籍共有%d本。",member[n].name,count);
        				else if(strcmp(member[n].sex,"female")==0)
        				printf("\n%s女士，您当前借阅的书籍共有%d本。",member[n].name,count);
        				else
						printf("\n%s，您当前借阅的书籍共有%d本。",member[n].name,count); 
        				
						if(bookgrasp[0].price<=1e-8) 
       				 	printf("\n而图书馆内共有0本书籍正在被借阅。\n");
       				 	else
       				 	printf("\n而图书馆内共有%d本书籍正在被借阅。\n",booknumber);
        	
						printf("\nPS:是否需要修改密码(y/n):");
						fflush(stdin);
						choice=getch();
						while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	   					choice=getch();
						printf("%c",choice);
						printf("\n");
						if(choice=='Y'||choice=='y')
						{
							printf("\n请输入修改密码的密钥(user_key):");
							fflush(stdin);
							gets(key);
							if(strcmp(member[n].password_key,key)==0)
							{
								printf("请输入新密码：");
								fflush(stdin);
								gets(new_password);
								strcpy(member[n].password,new_password);
								flag=1;
								p2=fopen("infomember.txt","w");
            					for(n=0;n<number;n++)
            					fprintf(p2,"%s %s %s %s %s\n",member[n].ID,member[n].password,
										member[n].password_key,member[n].name,member[n].sex);
           						fclose(p2);
           						}
           						else{
           							printf("\n输入密钥错误!"); 
								}
							}
						else
							flag=0; 
    					}
    					
    				}		 
   	if(flag==1)
   		{
		    printf("\n密码修改成功！"); 
		    printf("\n按任意键返回!\n");
   			getch();
		    return 1;
		}
    else{
   		return 0;
	}
} 

void find_account()/*账户找回函数*/
{
	FILE *p2;
	MEMBER member[100];
	int number,n,k=3,flag=1,mark=0;
	char choice='0';
	char vacancy[10]="";
	char search[30],compare[30],new_password[20];

    	system("cls");
    	fflush(stdin);
    	printf("输入您的姓名:");
    	gets(search);
      	p2=fopen("infomember.txt","r");
      	number=0;
      	while(!feof(p2))
        {
        	fscanf(p2,"%s %s %s %s %s\n",member[number].ID,member[number].password,
					member[number].password_key,member[number].name,member[number].sex);
        	number++;
        }
      	fclose(p2);
      	if(strcmp(member[0].ID,vacancy)==0)
        {
        	printf("系统中还没有任何会员信息!\n\n");
        }
        else
        {
        	for(n=0;n<number;n++)
         		if(strcmp(member[n].name,search)==0)
            	{
            		mark=1;
            		while(flag)
            		{
						printf("请输入您的密钥:");
						fflush(stdin);
						gets(compare);
						if(strcmp(member[n].password_key,compare)==0)
						{
							printf("\n");
							printf("|------------------------------个人信息------------------------------|\n");
    						printf("|姓名        性别      ID                  密码	                     |\n");
    						printf("|%-12s%-10s%-20s%-26s%|\n",member[n].name,member[n].sex,member[n].ID,member[n].password);
						
							printf("\n是否需要修改密码(y/n):");
							fflush(stdin);
							choice=getch();
							while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	    					choice=getch();
							printf("%c",choice);
							printf("\n");
							if(choice=='Y'||choice=='y')
								{
									printf("\n请输入新密码：");
									fflush(stdin);
									gets(new_password);
									strcpy(member[n].password,new_password);
									flag=0;
								}
							else
								flag=0;	
						}
						else{
							--k;/*密码输入次数count*/ 
							if(k!=0)
							{
								printf("\n\n\n\t\t您的密码输入有误!\n\t\t您还有%d次机会重新输入密码！",k);
								printf("您是否要继续输入密码(y/n):");
								fflush(stdin);
								while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	    						choice=getch();
      							printf("%c",choice);
      							printf("\n");
								if(choice=='Y'||choice=='y')
									flag=1;
								else
									flag=0;
							}	
							else{
								printf("您输入次数已用完！正在退回主界面...");
								flag=0;
              	 		}
					}
				}
			}
 		}
 		if(mark==0)
        {
		   	printf("您并未注册本系统会员!\n");
        } 
        else
        {
        	if(choice!='0'&&choice!='n'&&choice!='N')
			{
            p2=fopen("infomember.txt","w");
            for(n=0;n<number;n++)
            	fprintf(p2,"%s %s %s %s %s\n",member[n].ID,member[n].password,
						member[n].password_key,member[n].name,member[n].sex);
            fclose(p2);
            printf("您已成功找回/修改账户!\n");
        	}
        }
    printf("\n\n按任意键回到主菜单!\n");
    fflush(stdin);
    getch();
} 
 
int member_log_in(char account[15])/*会员登录函数*/
{
	FILE *p2;
	MEMBER member[100];
	char choice1,choice2;
	int flag1=0,flag2=1,n,k=3;
	int number;
	
    p2=fopen("infomember.txt","r");
   	number=0;
    while(!feof(p2))
    {
        fscanf(p2,"%s %s %s %s %s\n",member[number].ID,member[number].password,
					member[number].password_key,member[number].name,member[number].sex);
       	number++;
    }
    fclose(p2);
	for(n=0;n<number;n++)
    	if(strcmp(member[n].ID,account)==0)
    	{
    	    flag1=1;
			break;
		}
		if(flag1)
		{
			while(flag2)
			{
				if(compare_password(member[n].password))/* 调用会员密码比对函数 */ 
				{ 
					printf("\n\n\n\t\t\t   核对正确！正在进入会员界面...");
					clock_delay();
      	       	 	return 1;
				}
				else{
					--k;/*密码输入次数count*/ 
					if(k!=0)
					{
						printf("\n\n\n\t\t\t   您的密码输入有误!还有%d次机会重新输入密码！",k);
						printf("\n\t\t\t   您是否要继续输入密码(y/n):");
						fflush(stdin);
						choice1=getch();
						while(choice1!='Y'&&choice1!='y'&&choice1!='N'&&choice1!='n')
      	    				choice1=getch();
      					printf("%c",choice1);
						printf("\n");
						if(choice1=='Y'||choice1=='y')
							flag2=1;
						else
							return 0;
					}
					else{
						printf("\n\n\t\t\t   您输入次数已用完！按任意键退出...");
						fflush(stdin);
   						getch(); 
              	 		return 0;
					}	
				}		
			}
			flag2=1;
   		}
   		else{
   			printf("\n\n\n\t\t\t  该ID还未注册,是否需要注册会员(y/n):");
			choice2=getch();
			while(choice2!='Y'&&choice2!='y'&&choice2!='N'&&choice2!='n')
      	    	choice2=getch();
      	    printf("%c",choice2);
      	    printf("\n");
      	    if(choice2=='Y'||choice2=='y')
			{
				member_log_up();
				return 2; 
			}
			else
				return 0; 
		}
}

int compare_password(char *password)/*密码比对函数 */ 
{
	int i=0;
	char compare[20],c;
	fflush(stdin);
	printf("\n\t\t\t   密码(password):");
	while((c=getch())!=13)//\r是将光标移到该行首位
	{
	if(c==8&&i>0)
	{
	printf("\b \b");//清除*号和错符
	i--;
	continue;
	}
	if(c!=8)
	{
	compare[i++]=c;
	putchar('*');
	}
	}
	compare[i]='\0';
	if(strcmp(password,compare)==0)
		{
		printf("\a");  //响铃
		return 1;
		}
	else
		{
		printf("\a");  //响铃
		return 0;
		}
}

int check_repeat_ID(char *id_account)/*查重函数*/ 
{
	FILE *p2;
	MEMBER member[100];
	int flag1=0,flag2=1,n,number;
	
    p2=fopen("infomember.txt","r");
   	number=0;
    while(!feof(p2))
    {
        fscanf(p2,"%s %s %s %s %s\n",member[number].ID,member[number].password,
					member[number].password_key,member[number].name,member[number].sex);
       	number++;
    }
    fclose(p2);
	for(n=0;n<number;n++)
    	if(strcmp(member[n].ID,id_account)==0)
    	{
    	    flag1=1;
			break;
		}
		if(flag1)
		{
			return 1;
   		}
   		else{
            return 0;
		}
}

void ADMIN_watch_member()/*查看会员信息函数*/
{
	FILE *p2;
	MEMBER member[100];
	int n,number;
	system("cls");
	fflush(stdin);
	
	p2=fopen("infomember.txt","r");
	number=0;
	while(!feof(p2))
	{
		fscanf(p2,"%s %s %s %s %s\n",member[number].ID,member[number].password,
					member[number].password_key,member[number].name,member[number].sex);
		number++;
	}
	fclose(p2);
	
	printf("系统注册用户有%d位:",number);
	printf("\n\n");
	printf("|-----------------------会员信息-----------------------|\n");
    printf("|姓名      性别    ID            密码  	         密钥  |\n");
    for(n=0;n<number;n++)
		printf("|%-10s%-8s%-14s%-16s%-6s%|\n",member[n].name,member[n].sex,
				member[n].ID,member[n].password,member[n].password_key);

    printf("\n\n按任意键返回上一级菜单!\n");
   	getch();
} 

void display_memberbook()/*查看所有图书借阅信息函数*/
{
	FILE *p3;
	BOOKGRASP bookgrasp[100];
	int booknumber,n;
	system("cls");
	
	p3=fopen("memberbook.txt","r");
	booknumber=0;
	while(!feof(p3))
	{
		fscanf(p3,"%s %s %s %s %s %f %s\n",
				bookgrasp[booknumber].number,bookgrasp[booknumber].name,bookgrasp[booknumber].author,bookgrasp[booknumber].press,
				bookgrasp[booknumber].category,&bookgrasp[booknumber].price,bookgrasp[booknumber].account);
		booknumber++;
	}
	if(bookgrasp[0].price==0.0)
		printf("当前没有借阅信息");
	else{ 
	printf("当前共有%d位会员借阅书籍。",booknumber);
	printf("\n");
   	printf("|---------------------------借阅图书信息-----------------------------------|\n");
   	printf("|编号  书名        作者      出版社          类别    单价    借阅ID        |\n");
   	printf("|                                                                          |\n");
    for(n=0;n<booknumber;n++)		
       	printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-14s|\n",bookgrasp[n].number,
				bookgrasp[n].name,bookgrasp[n].author,bookgrasp[n].press,
				bookgrasp[n].category,bookgrasp[n].price,bookgrasp[n].account); 
	} 
	printf("\n\n输入任意键返回...");
	fflush(stdin);
	getch(); 
} 

void password_circle()/*画框函数*/ 
{
	system("cls");
	printf("\n\n\n\t\t\t***================================*** \n");
	printf("\t\t\t                                   \n");
	printf("\t\t\t   账户 (account):");
}

void clock_delay()/*时间延时函数*/
{
	clock_t tm;
	tm=clock();
    while(clock()<tm+1000);
}	

void find_account_circle()/*找回账户弹出框函数*/
{
	printf("\n\n\n\n");
	printf("\t\t\t===============H-E-L-P===================\n");
	printf("\t\t\t|                                       |\n");
	printf("\t\t\t* 您需不需要通过密钥找回账户？(输入y/n) *\n");
	printf("\t\t\t|                                       |\n");
	printf("\t\t\t=========================================\n");
	printf("\n\t\t\t您的选择是:");
}
