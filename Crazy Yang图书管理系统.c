/* Code??Crazy Yang
   Debug??Crazy Yang
   ??ƺͺ?ڿ?????Crazy Yang
   ???д??Crazy Yang
   ֧?֣???????????????ҵѧԺ-??????ʵ????*/
                             
							   /* ?????ǰ? */

/* ????????ͳV1.0??????????????????????????-????Ϣ?ഴ?ʵ????紴1601-???????,???????,
   ??????λ????ɾ,??????????һ???????,лл???!! */
/* ????????˴????????е?ug???rror,???ϵ?,??????engziyang97@163.com */
/* ʹ?ָ?: ?????Ҳ??ǰ?,????˳????????????????Լ??Ҫ,?????ļ???з???,???????С?.
   ???ͳ?????2?????,??????????????ֱ?Ӧ????ͼ??????,ʹ???????鹦?.???
   ???????????Ҫ?????fenrari1997 ???????޸?/

                               /* ע??? */
/* ??ʹ?֮ǰ??һ?,?ΪV1.0?汾??????ִ?????????Щ??̫?Ϥ??˻?????,????*/
/* 1.?????????????ʱ??ʱ???????ģ?ϵͳ??״̬,?????"????????....",
     ??Ҫ???,???ȴ??????Ļ?ȥ??ٽ????,??????????*/
/* 2.?????Ϊ?????????,ʹ?getch()һ?಻??Եĺ??,???ر???????س???,
     ??ǿ?????,?????????û??س??? */
/* 3.V1.0ϵͳ?Ŀ???Դ?һǧ??У? */

/*ͷ????*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include <conio.h>

/*?궨??*/ 
#define  ADMIN_password "fenrari1997" /*?????????*/

/*?ṹ????*/
typedef struct bookinfo/*ϵͳͼ??Ϣ */ 
{
    char number[15];/*ͼ???*/
    char name[30];/*ͼ????/
    char author[20];/*??*/
    char press[30];/*?????/ 
    char category[20]; /*??*/ 
    float price;/*????/ 
    int  quantity;/*?ݲ??*/
 	int  time;/*????*/ 
}BOOKINFO;

typedef struct bookgrasp/*???????鼮?Ϣ*/ 
{
	char number[15];/*ͼ???*/
    char name[30];/*ͼ????/
    char author[20];/*??*/
    char press[30];/*?????/ 
    char category[20]; /*??*/ 
    float price;/*????/ 
 	char account[30];/*????D*/
}BOOKGRASP;

typedef struct member/*???????Ϣ */ 
{ 
	char name[30];
	char ID[20];
	char password[30];
	char sex[15];	
	char password_key[30];
}MEMBER; 

/*?˵?????*/
void menu1();
void menu2();
void menu3();
void AboutMe();

/*???ߺ???*/
int compare_password(char password[20]);/*???ȶԺ?? */  
void clock_delay(); /*ʱ???????*/ 
void password_circle();/*?????????*/
void find_account_circle();/*???ʻ????????*/ 

/*????Ϣϵͳ?㼶????*/
int user_account(char account[20]);/*???????Ϣ*/ 
void member_log_up();/*???ע?ắ?*/
int member_log_in(char account[20]);/*?????????*/ 
void ADMIN_watch_member();/*?鿴????Ϣ???*/
void display_memberbook();/*?鿴??ͼ?????????*/
int check_repeat_ID(char id_account[20]);/*????????????*/ 
void find_account();/*?????غ??*/ 

/*ͼ??Ϣϵͳ?㼶????*/
void add_book();/*??????????Ϣ*/
void delete_book();/*????????ƶ????Ϣ???ɾ??*/
void modify_book();/*??????Ϣ*/
void display_book();/*?ʾȫ??ͼ??Ϣ*/
void search_book();/*???????????ͼ?????*/
void borrow_book(char account[20]);/*???/
void return_book(char account[20]);/*???*/
void display_price_lower();/*???ݼ۸?г?ͼ??Ϣ*/
void dispaly_popular();/*ͼ????ӭ???а?/
int check_repeat_book(char number[30]);/*???鼮??*/

int main()
{
	int flag1=1,flag2=1,flag3=1;/* flag???????,flagΪ 1 ʱΪ???Ϊ 0 ʱΪ??*/
	char choice1,choice2,choice3;
	FILE *p1,*p2,*p3;
	
	system("title ?紴1601-Fenrari");
   
    if((p1=fopen("library.txt","r"))==NULL)/*p1?ͼ?????ͳ??鼮?Ϣ???ָ?*/ 
    {
      	p1=fopen("library.txt","w");
      	fclose(p1);
    }
	if((p2=fopen("infomember.txt","r"))==NULL)/*p2?ͼ?????ͳ?Ļ??????Ϣ???ָ?*/ 
	{
		p2=fopen("infomember.txt","w");
		fclose(p2);
	}
	if( (p3=fopen("memberbook.txt","r"))==NULL)/*p3?ͼ?????ͳ?Ļ??????Ϣ???ָ?*/ 
	{
		p3=fopen("memberbook.txt","w");
		fclose(p3);
	}
	
	while(flag1)
	{
		system("cls");
		menu1();/*??????˵? */ 

  		printf("\n");
  		printf("??ѡ?(1-5):");
  		choice1=getch();
  		while(choice1!='1'&&choice1!='2'&&choice1!='3'&&choice1!='4'&&choice1!='5')
  			choice1=getch();
  		printf("%c",choice1);
  		fflush(stdin);

  		if(choice1=='1')/*??????*/ 
		{
			int flag=0;
			char account1[20],account_choice;
			system("cls");
			password_circle();
			fflush(stdin);
			gets(account1);
			flag=member_log_in(account1);/*?????????*/ 
			if(flag==2)
			{
				system("cls");
				password_circle();
				fflush(stdin);
				gets(account1);
				flag=member_log_in(account1);/*?????????*/	
			} 
			if(flag==1)
			{
    		while(flag2&&flag3){
    		system("cls");
			menu2();
    		printf("\n");
    		printf("??ѡ?(1-8):");
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
								printf("\n\n\t\t\t????Ϣ?ı䣬??????...");
       		       	  	 		clock_delay();
       		       	  	 		flag3=0;
							}
						 break;
    			case '8':flag2=0;
					     printf("\n\n\t\t\t???????????..");
       		       	  	 clock_delay();
						 break;
				default:break;/*?Ȼѹ????????default?????????????????©??¼ӵ?ase??hile??????????/
    				}
				}
			}else{
				system("cls"); 
				find_account_circle();/*װ????????*/ 
				fflush(stdin);
				account_choice=getch();
				while(account_choice!='Y'&&account_choice!='y'&&account_choice!='N'&&account_choice!='n')
      	    		account_choice=getch();
      			printf("%c",account_choice);
				printf("\n");
				if(account_choice=='Y'||account_choice=='y')
					find_account();/*?????غ??*/ 	
			}
			flag2=1,flag3=1;
		}
	
		else if(choice1=='2')/*???ע??/ 
		{
			system("cls");
			printf("\n\n\n\t\t\t????????ע???...");
			clock_delay();
     	   member_log_up();  
		}
	 
		else if(choice1=='3')/*???????*/ 
		{
			if(compare_password(ADMIN_password))
			{
				printf("\n\n\t\t\t\t  --?????ȷ!--\n\n\t\t\t\t==????????????=\n");
     	  	 	clock_delay(); 
				while(flag2){
				system("cls");
				menu3();
				printf("\n");
				printf("??ѡ?(1-8):");
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
					     	 printf("\n\n\t\t\t????????????..");
         	     	  		 clock_delay();
							 break;
   					default:break;/*?Ȼѹ????????default?????????????????©??¼ӵ?ase??hile??????????/
   					}
  				}
  			} 
  			else{
  				printf("\n\n\t\t\t\t  --???????--\n");
     		   	clock_delay();
			}
			flag2=1; 
 		}
 	
 		else if(choice1=='4')/*???oder*/ 
 		{
			AboutMe();
		}
	
 		else if(choice1=='5')/*???ϵͳ*/
 		{
 			flag1=0;
		}
	}
	fflush(stdin);
	system("cls");
	printf("??????ȫ???ϵͳ!(???????رս??\n\n\t??ӭ???ٴ???!\n\n\t?Զ?????enrari!\n\n");
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
	printf("\t\t\t| |  [1]   ??????                     | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [2]   ???ע??                    | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [3]   ???????                   | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [4]   ????°汾                 | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [5]   ???ϵͳ                     | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n");
	printf("\t\t\t *=======================================*\n");
}
void menu2()
{
	system("color BC");
	printf("\n\n");
	printf("\t\t\t *=====================================*\n");
    printf("\t\t\t| | * - * - * -??Ա-???- * - * - * | |\n");
    printf("\t\t\t| *                                   * |\n");
    printf("\t\t\t| |  [1]   ??????Ϣ               | |\n");
    printf("\t\t\t| *  [2]   ?????                   * |\n");
    printf("\t\t\t| |  [3]   ?黹ͼ?                   | |\n");
    printf("\t\t\t| *  [4]   ?????ͼ??Ϣ           * |\n");
    printf("\t\t\t| |  [5]   ?????????               | |\n");
    printf("\t\t\t| *  [6]   ͼ????ӭ???а?        * |\n");
    printf("\t\t\t| |  [7]   ???˻??Ϣ               | |\n");
    printf("\t\t\t| *  [8]   ?????????              * |\n");
    printf("\t\t\t| |                                   | |\n");
    printf("\t\t\t| * - * - * - * - * - * - * - * - * - * |\n");
	printf("\t\t\t *=====================================*\n");
}
void menu3()
{
	system("color 1D");
	printf("\n\n");
	printf("\t\t\t *======================================*\n");
	printf("\t\t\t| | * - * - * ????Ա-??? * - * - * | |\n");
	printf("\t\t\t| *                                    * |\n");
	printf("\t\t\t| |  [1]   ?????                    | |\n");
	printf("\t\t\t| *  [2]   ɾ??ͼ?                    * |\n");
	printf("\t\t\t| |  [3]   ??????Ϣ                | |\n");
	printf("\t\t\t| *  [4]   ??????Ϣ                * |\n");
	printf("\t\t\t| |  [5]   ?ʾȫ??ͼ??Ϣ            | |\n");
	printf("\t\t\t| *  [6]   ?ʾ??????Ϣ            * |\n");
	printf("\t\t\t| |  [7]   ?ʾ???????            | |\n");
	printf("\t\t\t| *  [8]   ??????????             * |\n");
	printf("\t\t\t| |                                    | |\n");
	printf("\t\t\t| * - * - * - * - * -- * - * - * - * - * |\n");
	printf("\t\t\t *======================================*\n");
}
void AboutMe()
{
	system("cls");
	printf("Code:  Fenrari Yang\n");
	printf("Debug: Fenrari Yang\n");
	printf("\n\n\t\tʹ??????鿴?????????????");
	printf("\n\n");
 	printf(" ^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^**^*^*^*^*^*^*^*^*^\n");
	printf(" | Fenrari?????????汾?????Ц??????????ɵɵ?ĵط????ug! |\n");
	printf(" * ??????????һ??Ҫ??ϵ?Ŷ!??????engziyang97@163.com,???!!!   *\n");
	printf(" |                                ^_^                                     |\n");
	printf(" ^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^**^*^*^*^*^*^*^*^*^\n");
	printf("\n\n?????????.");
	getch();
}

void add_book() /*??????????Ϣ*/
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
		printf("???ͼ???:");
		gets(newbook.number);
		
		if(check_repeat_book(newbook.number))
		{	
			printf("?????????ʹ???");
			printf("\n????????ע??n\n");
			getch();
			flag=1; 
		}
		else{
			fflush(stdin); 
			printf("?????:");
			gets(newbook.name);
		
			printf("?????:");
			gets(newbook.author);
		
			printf("????????");
			gets(newbook.press);
			
			printf("?????(?ѧ/???/???/??ѧ/??:");
			gets(newbook.category);
		
			printf("????۸?");
			scanf("%f",&newbook.price);
		
			printf("????ݲ??:");
			scanf("%d",&newbook.quantity);
		
			printf("?????Ĵ??(????0):");
			scanf("%d",&newbook.time); 
		fflush(stdin);
      	printf("??񱣴???Ŀ(y/n):");
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
        	printf("\n????Ŀ???ӵ?library.txt????!\n");
       	}
        else
        {
       		printf("\n????Ŀδ????\n");
        }
      	printf("\n\n?????????(y/n):");
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

void display_book()/*?ʾȫ??ͼ??Ϣ*/
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
    printf("??ǰͼ?????dĿ???\n\n",booknumber);
    if(bookinfo[0].quantity==0)
    {
      	printf("\nû???????Ϣ!\n\n");
    }
    else
    {
      	n=0;
      	printf("|---------------------------------ͼ??Ϣ---------------------------------|\n");
      	printf("|??  ??        ??      ?????         ??    ????   ?ݲ??  ????|\n");
      	printf("|                                                                          |\n");
      	while(n<booknumber)
        {
        	printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n",bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
                        bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
        	n++;
        }
      }
    printf("\n\n???????????????˵?!\n");
   	getch();
}

void search_book()/*???????????ͼ?????*/
{
	int flag=1,flag1=1;
	char select;
    char name_compare[30]="";/*name_compare?????Ҫ???????*/
   	char number_compare[30]=""; /*number_compare?????Ҫ?????鼮??*/
   	char author_compare[30]="";/*author_compare?????Ҫ?????????*/
	char search[30]="";/*search??ȶ???,???Ҫ??ҵ????????ȶ???*/
	char compare[30]="";/*compare??ȶ???,?????е????????ȶ???*/
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
			printf("??ͨ??\n\n1.<-ͼ???->\n\n2.<-??->\n\n3.<-???->\n\n????ʽ???ͼ?:");
    		select=getch();
    		printf("%c",select);
			printf("\n\n?????????:");		
			switch(select)
			{
				case '1':gets(number_compare);strcpy(search,number_compare);flag1=0;break;
				case '2':gets(name_compare);strcpy(search,name_compare);flag1=0;break;
				case '3':gets(author_compare);strcpy(search,author_compare);flag1=0;break;
				default :
					printf("\n??Ҫ???˵?֮?????~???????????");
					fflush(stdin);
            	    getch(); 
			}
		}

	flag1=1;
    if(bookinfo[0].quantity==0)
    {
      	printf("???????????!\n\n");
      	printf("???????ص???˵?!\n\n");
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
         		printf("|---------------------------------ͼ??Ϣ---------------------------------|\n");
      			printf("|??  ??        ??      ?????         ??    ????   ?ݲ??  ????|\n");
      			printf("|                                                                          |\n");
    			printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n",bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
                        bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
       			break;
			}
       	}
   			if(n>=booknumber)
       		printf("\nû???ҷ????Ҫ???鼮!\n");
       		
      		printf("\n\n???????(y/n):");
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

void delete_book()/*????????ƶ????Ϣ???ɾ??*/
{
    char search[20]="";/*search?????Ҫɾ??????*/
    int n,i;
    FILE *p1;
    char choice;
    BOOKINFO bookinfo[100];
    int booknumber;

    system("cls");
    while(1)
    {
    	fflush(stdin);
        printf("??Ҫɾ????鱾???");
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
        	printf("???????????!\n\n");
        	printf("???????ص???˵?!\n\n");
        	getch();
        	break;
        }/*if???*/
        else
        {
        	for(n=0;n<booknumber;n++)
            if(strcmp(bookinfo[n].name,search)==0)
            {
           		break;
            }
        	if(n>=booknumber)
          		printf("\nû???Ҹ???????!\n");
        	else
            {
           		printf("\n??????Ҫɾ??????Ŀ(Y/N):");
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
           			printf("\nɾ???ɹ?!");
             	}
           		else
              		printf("\n????Ŀû???ɾ??!");
           }
            printf("\n\n???????ɾ?????(y/n):");
         		choice=getch();
         	while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	   		choice=getch();
      		printf("%c",choice);
      		printf("\n");
         	if(choice=='Y'||choice=='y')
           		continue;
         	else
           		break;
        }/*else???*/
      }/*while(1)???*/
    }

void display_price_lower()/*???ݼ۸?г?ͼ??Ϣ*/
{
    float price;
    FILE *p1;
    int n;
    int count=0;
    BOOKINFO bookinfo[100];
    int booknumber;

    system("cls");
    printf("???????????????????????λ??͵?鼮:");
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
      	printf("\nû???????Ϣ!\n");
    }
    else
    {
      	for(n=0;n<booknumber;n++)
        {
        	if(bookinfo[n].price<=price)
          	count++;
        }
      	if(count==0)
       		printf("????????.1fԪ?۸??͵?????",price);
      	else
        {
        	printf("\n?۸??%.1fԪ?????Ϣ?%d??\n",price,count);
       		printf("|---------------------------------ͼ??Ϣ---------------------------------|\n");
      		printf("|??  ??        ??      ?????         ??    ????   ?ݲ??  ????|\n");
      		printf("|                                                                          |\n");
        	for(n=0;n<booknumber;n++)
          	{
          		if(bookinfo[n].price<=price)
            	printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n",bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
                        bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
          	}
        }
      }
    printf("\n\n???????ص???˵?!\n");
    getch();
    }

void modify_book()
{
	int flag=1,flag1=1,flag2,n;
	char change,choice;
	char number[15];/*ͼ???*/
    char name[30];/*ͼ????/
    char author[20];/*??*/
   	char press[30];/*?????/
	char category[20];/*??*/ 
    int  quantity;/*????*/
    float price;/*????/
    
	char search[30];/*Ҫ??ĵ???*/ 
	FILE *p1;
	BOOKINFO bookinfo[100];
	int booknumber;
    while(flag)
    {
    	flag2=0;
    	system("cls");
    	fflush(stdin);
      	printf("??Ҫ???????鱾?:");
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
        	printf("???????????!\n\n");
        	printf("???????ص???˵?!\n\n");
        	getch();
        	break;
        }
        else
        {
        	for(n=0;n<booknumber;n++)
         		if(strcmp(bookinfo[n].name,search)==0)
            	{
            		printf("\n"); 
         			printf("|---------------------------------ͼ??Ϣ---------------------------------|\n");
      				printf("|??  ??        ??      ?????         ??    ????   ?ݲ??  ????|\n");
      				printf("|                                                                          |\n");
    				printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n",bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
                     	   bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
       				
					while(flag1){
					printf("\n1.?????\n2.??????n3.?????\n4.?????n5.?????\n6.???????n7.????\n\n??Ҫ??ĵ??");
					change=getch();
					while(change!='1'&&change!='2'&&change!='3'&&change!='4'&&change!='5'&&change!='6'&&change!='7')
  						change=getch();
  					printf("%c",change);
           			printf("\n????????:");
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
            			default:break;/*?Ȼѹ????????default?????????????????©??¼ӵ?ase??hile??????????/
					}
				}
			flag1=1;
            break;
            }
        if(n>=booknumber)
           printf("\nû???Ҹ???????!");
        else if(!flag2)
        {
            p1=fopen("library.txt","w");
            for(n=0;n<booknumber;n++)
            fprintf(p1,"%s %s %s %s %s %f %d %d\n",
					bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
					bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
            fclose(p1);
            printf("\n??ĳɹ?!");
        }
        else
        	printf("????ĵ????Ϣ???????????"); 
   		printf("\n??????????y/n):");
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
      	printf("??Ҫ??ĵ?鱾?:");
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
        	printf("\n???????????!\n");
        	printf("???????ص???˵?!\n\n");
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
					
					p3=fopen("memberbook.txt","a");  /*????׷?ӵķ?ʽ??????????????*/ 
					fprintf(p1,"%s %s %s %s %s %f %s\n",
							bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,bookinfo[n].press,
							bookinfo[n].category,bookinfo[n].price,account);
					fclose(p3); 
					break;
				}
            }
        if(n>=booknumber1)
           printf("\nû???Ҹ???????!\n");
        else
        {
            p1=fopen("library.txt","w");
            for(n=0;n<booknumber1;n++)
            fprintf(p1,"%s %s %s %s %s %f %d %d\n",
					bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,bookinfo[n].press,
					bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
            fclose(p1);
            printf("\n?????!\n");
        }
   		printf("\n???????y/n):");
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
      	
		printf("????ĵ???ͼ??Ϣ??:\n"); 
        printf("|----------------------------ͼ??????--------------------|\n");
      	printf("|??  ??        ??      ?????         ??    ????   |\n");
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
      	
      	printf("\n??Ҫ?黹??鱾?:");
      	gets(search);
      	if(bookinfo[0].quantity==0)
        {
        	printf("\n???????????!\n");
        	printf("???????ص???˵?!\n\n");
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
							printf("\n?û????????");
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
        	printf("???û????????!\n"); 
        if(n<booknumber&&flag2==1)
        {
            p1=fopen("library.txt","w");
            for(n=0;n<booknumber;n++)
            fprintf(p1,"%s %s %s %s %s %f %d %d\n",
				bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
				bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
            fclose(p1); 
            printf("\n????ɹ???");
        }
        else
        	printf("\n???ʧ?ܣ?");
        
		fflush(stdin);	
   		printf("\n???????(y/n):");
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

void dispaly_popular()/*ͼ????ӭ???а?/ 
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
      	printf("û???????Ϣ!\n\n");
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
        	
       		printf("|---------------------------ͼ????ӭ???а?----------------------------|\n");
      		printf("|??  ??        ??      ?????         ??    ????   ?ݲ??  ????|\n");
      		printf("|                                                                          |\n");
        	for(n=0;n<booknumber;n++)
          	{
            	printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n",bookinfo[n].number,bookinfo[n].name,bookinfo[n].author,
                        bookinfo[n].press,bookinfo[n].category,bookinfo[n].price,bookinfo[n].quantity,bookinfo[n].time);
          	}
        
      }
    printf("\n\n???????ص???˵?!\n");
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
	
		printf("????ע??ID?:");
		gets(member.ID);
		
		if(check_repeat_ID(member.ID))
		{	
			printf("??D???ע?ᣡ???ע??_^\n");
			printf("????????ע??n\n");
			getch();
			flag=1; 
		}
		else{
			flag=0;
			printf("?????????Ҫ?????):");
			gets(member.password);
			
			printf("????????Կ(?????˻????벻??????):"); 
			gets(member.password_key); 
			
			printf("???????:");
			gets(member.name);
	
			printf("?????Ա??ʿ??male,Ůʿ??female):");
			gets(member.sex);
	
			printf("??񱣴??ע????(y/n):");
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
			printf("\n???˻??ע??????\n");
    	}
    	else
    	{
       		printf("\n????????δ????\n");
    	}
    	printf("\n????ע??Ա(y/n):");
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
				printf("??ǰͼ???????ν????");
				flag=0;
				printf("\n\n??????????\n");
   				getch();
			}
			else{ 		
				for(n=0;n<number;n++)
					if(strcmp(member[n].ID,account)==0)
					{
						i=0;
						printf("\n");
						printf("|---------------------------????Ϣ-------------------------|\n");
    					printf("|??        ???     ID              ??                  |\n");
    					printf("|%-12s%-10s%-16s%-22s%|\n",member[n].name,member[n].sex,member[n].ID,member[n].password);
    					printf("|                                                            |\n");
    					printf("|----------------------------ͼ??????--------------------|\n");
      					printf("|??  ??        ??      ?????         ??    ????   |\n");
      		
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
       				 	printf("\n%s???????ǰ??ĵ?鼮???%d????",member[n].name,count);
        				else if(strcmp(member[n].sex,"female")==0)
        				printf("\n%sŮʿ?????ǰ??ĵ?鼮???%d????",member[n].name,count);
        				else
						printf("\n%s?????ǰ??ĵ?鼮???%d????",member[n].name,count); 
        				
						if(bookgrasp[0].price<=1e-8) 
       				 	printf("\n??ͼ???ڹ??0???????????ġ?\n");
       				 	else
       				 	printf("\n??ͼ???ڹ??%d???????????ġ?\n",booknumber);
        	
						printf("\nPS:??????????y/n):");
						fflush(stdin);
						choice=getch();
						while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	   					choice=getch();
						printf("%c",choice);
						printf("\n");
						if(choice=='Y'||choice=='y')
						{
							printf("\n?????????Կ(user_key):");
							fflush(stdin);
							gets(key);
							if(strcmp(member[n].password_key,key)==0)
							{
								printf("????????");
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
           							printf("\n???Կ???"); 
								}
							}
						else
							flag=0; 
    					}
    					
    				}		 
   	if(flag==1)
   		{
		    printf("\n????ĳɹ???"); 
		    printf("\n??????????\n");
   			getch();
		    return 1;
		}
    else{
   		return 0;
	}
} 

void find_account()/*?????غ??*/
{
	FILE *p2;
	MEMBER member[100];
	int number,n,k=3,flag=1,mark=0;
	char choice='0';
	char vacancy[10]="";
	char search[30],compare[30],new_password[20];

    	system("cls");
    	fflush(stdin);
    	printf("???????:");
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
        	printf("ϵͳ???û???λ???Ϣ!\n\n");
        }
        else
        {
        	for(n=0;n<number;n++)
         		if(strcmp(member[n].name,search)==0)
            	{
            		mark=1;
            		while(flag)
            		{
						printf("????????:");
						fflush(stdin);
						gets(compare);
						if(strcmp(member[n].password_key,compare)==0)
						{
							printf("\n");
							printf("|------------------------------????Ϣ------------------------------|\n");
    						printf("|??        ???     ID                  ??	                     |\n");
    						printf("|%-12s%-10s%-20s%-26s%|\n",member[n].name,member[n].sex,member[n].ID,member[n].password);
						
							printf("\n??????????y/n):");
							fflush(stdin);
							choice=getch();
							while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	    					choice=getch();
							printf("%c",choice);
							printf("\n");
							if(choice=='Y'||choice=='y')
								{
									printf("\n????????");
									fflush(stdin);
									gets(new_password);
									strcpy(member[n].password,new_password);
									flag=0;
								}
							else
								flag=0;	
						}
						else{
							--k;/*???????count*/ 
							if(k!=0)
							{
								printf("\n\n\n\t\t?????????\n\t\t????%d?λ????????룡",k);
								printf("????????????(y/n):");
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
								printf("????????????????????..");
								flag=0;
              	 		}
					}
				}
			}
 		}
 		if(mark==0)
        {
		   	printf("???δע?᱾ϵͳ???!\n");
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
            printf("???ɹ???????˻?!\n");
        	}
        }
    printf("\n\n???????ص???˵?!\n");
    fflush(stdin);
    getch();
} 
 
int member_log_in(char account[15])/*?????????*/
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
				if(compare_password(member[n].password))/* ?????????ȶԺ?? */ 
				{ 
					printf("\n\n\n\t\t\t   ?˶??ȷ?????????????..");
					clock_delay();
      	       	 	return 1;
				}
				else{
					--k;/*???????count*/ 
					if(k!=0)
					{
						printf("\n\n\n\t\t\t   ????????????%d?λ????????룡",k);
						printf("\n\t\t\t   ????????????(y/n):");
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
						printf("\n\n\t\t\t   ????????????????????...");
						fflush(stdin);
   						getch(); 
              	 		return 0;
					}	
				}		
			}
			flag2=1;
   		}
   		else{
   			printf("\n\n\n\t\t\t  ??D??δע???????ע??Ա(y/n):");
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

int compare_password(char *password)/*???ȶԺ?? */ 
{
	int i=0;
	char compare[20],c;
	fflush(stdin);
	printf("\n\t\t\t   ??(password):");
	while((c=getch())!=13)//\r?????????????
	{
	if(c==8&&i>0)
	{
	printf("\b \b");//???*?źʹ??
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
		printf("\a");  //???
		return 1;
		}
	else
		{
		printf("\a");  //???
		return 0;
		}
}

int check_repeat_ID(char *id_account)/*??غ??*/ 
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

void ADMIN_watch_member()/*?鿴????Ϣ???*/
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
	
	printf("ϵͳע??û??%dλ:",number);
	printf("\n\n");
	printf("|-----------------------????Ϣ-----------------------|\n");
    printf("|??      ???   ID            ??  	         ?Կ  |\n");
    for(n=0;n<number;n++)
		printf("|%-10s%-8s%-14s%-16s%-6s%|\n",member[n].name,member[n].sex,
				member[n].ID,member[n].password,member[n].password_key);

    printf("\n\n???????????????˵?!\n");
   	getch();
} 

void display_memberbook()/*?鿴??ͼ?????????*/
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
		printf("??ǰû??????");
	else{ 
	printf("??ǰ???%dλ??????鼮??",booknumber);
	printf("\n");
   	printf("|---------------------------??????Ϣ-----------------------------------|\n");
   	printf("|??  ??        ??      ?????         ??    ????   ???D        |\n");
   	printf("|                                                                          |\n");
    for(n=0;n<booknumber;n++)		
       	printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-14s|\n",bookgrasp[n].number,
				bookgrasp[n].name,bookgrasp[n].author,bookgrasp[n].press,
				bookgrasp[n].category,bookgrasp[n].price,bookgrasp[n].account); 
	} 
	printf("\n\n??????????..");
	fflush(stdin);
	getch(); 
} 

void password_circle()/*?????*/ 
{
	system("cls");
	printf("\n\n\n\t\t\t***================================*** \n");
	printf("\t\t\t                                   \n");
	printf("\t\t\t   ??? (account):");
}

void clock_delay()/*ʱ???????*/
{
	clock_t tm;
	tm=clock();
    while(clock()<tm+1000);
}	

void find_account_circle()/*???˻????????*/
{
	printf("\n\n\n\n");
	printf("\t\t\t===============H-E-L-P===================\n");
	printf("\t\t\t|                                       |\n");
	printf("\t\t\t* ?????Ҫͨ???Կ???˻???(??y/n) *\n");
	printf("\t\t\t|                                       |\n");
	printf("\t\t\t=========================================\n");
	printf("\n\t\t\t??????:");
}

