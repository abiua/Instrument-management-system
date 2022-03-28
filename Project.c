#define MaxSize 60 //结构体最大仪器储存数量

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN 20//结构体内字符型数组的最大长度，可更改 
int k=1,n=0,m=0;//n为现在仪器数量,k用于判断是否退出系统，m为要增加的仪器数量 
 char filename[LEN]={"仪器管理系统"};

struct{           //定义结构体 
	char Num[LEN];//编号 
	char Name[LEN];//名称 
	char Sort[LEN];//类别 
	char Spec[LEN];//规格 
	char Model[LEN];//类型 
	int Data[LEN];//日期 
	char Price[LEN];//价格 
	char Quality[LEN];//数量 
}Ins[MaxSize];

void Insert()//增加
{
	int i=n,j,flag;//flag用于当编号重复的矫正 
	int key=0;//用于判断m是否合法 
	printf("请输入您本次要增加的仪器数量:\n");
	printf("(请输入大于0的整数，输入其它退出)\n");
	scanf("%d",&m);
	if(m>0)
	{
		do
		{
			flag=1;
			while(flag)
			{
				flag = 0;
				printf("请输入第%d个仪器编号:",i+1);
				scanf("%s",Ins[i].Num);
				for(j=0;j<i;j++)
				{
					if(strcmp(Ins[i].Num,Ins[j].Num)==0)//查重编号 
					{
						printf("此编号已在系统中，请重新输入\n");
						flag = 1;
						break;
					}
				}
				
			 } 
		printf("请输入第%d个仪器的名称\n",i+1);
		scanf("%s",Ins[i].Name);
	    
		printf("请输入第%d个仪器的类别\n",i+1);
		scanf("%s",Ins[i].Sort);
		
		printf("请输入第%d个仪器的规格\n",i+1);
		scanf("%s",Ins[i].Spec);
		
		printf("请输入第%d个仪器的型号\n",i+1);
		scanf("%s",Ins[i].Model);
		
		printf("请输入第%d个仪器的购买日期(例如:2021 03 21)\n",i+1);
		while(1){
		int year,month,day;
		scanf("%d",&year);
		scanf("%d",&month);
		scanf("%d",&day);
		if(Monitor(year,month,day))//对日期输入是否合法的判断 
		{
			Ins[i].Data[0]=year;
			Ins[i].Data[1]=month;
			Ins[i].Data[2]=day;
			break;
		}
		else
		  printf("日期格式输入错误，请重新输入.\n");
		}
		
		printf("请输入第%d个仪器的单价\n",i+1);
		scanf("%s",Ins[i].Price);
        
		printf("请输入第%d个仪器的数量\n",i+1);
		scanf("%s",Ins[i].Quality);
		if(flag == 0){
			i++;
		}
	}while(i<n + m);	
	}
	else
		{
			system("pause");
			system("cls");
			return;
		}
	n += m;//仪器数量增加m个 
	printf("仪器信息录入完毕\n");
	system("pause");
	system("cls");
}

void Search()//查找
{
	system("cls");
	int i,item,flag;//flag用于判断查询的仪器是否存在,item用于子菜单选择 
	char s1[LEN];
	char s2[LEN];
	while(1)
	{
	printf("------------------\n");
	printf("-----1.按编号查询-----\n");
	printf("-----2.按类别查询-----\n");
	printf("-----3.退出本菜单-----\n");
	printf("------------------\n");
		printf("请选择菜单编号\n");
		scanf("%d",&item);
		flag = 0;
		switch(item)
		{
			case 1:
				printf("请选择要查询的仪器编号:\n");
    			scanf("%s",s1);
    			for(i=0;i<n;i++)
    			  if(strcmp(s1,Ins[i].Num)==0)
    			  {
    				flag = 1;
    				printf("\n------------------------------------------------------------------------------------------------\n");
    				printf("仪器编号\t名称\t类别\t规格\t型号\t购买日期(年 月 日)\t单价（单位：元）    数量\n");
				    printf("\n------------------------------------------------------------------------------------------------\n");
				    printf("%s\t         %s\t%s\t%s       %s\t      %d.%d.%d\t        %s                   %s\n",&Ins[i].Num,&Ins[i].Name,&Ins[i].Sort,&Ins[i].Spec,&Ins[i].Model,Ins[i].Data[0],Ins[i].Data[1],Ins[i].Data[2],&Ins[i].Price,&Ins[i].Quality ); 
				  }
				if(0 == flag)
				  printf("该编号不存在!\n");
				system("pause");
				system("cls");  
				break;//容错处理 
		    case 2:
				printf("请输入要查询的仪器类别:\n");
				scanf("%s",s2);
				for(i = 0;i<n;i++)
				  if(strcmp(s2,Ins[i].Sort) == 0)
				  {
					flag = 1;
					printf("\n------------------------------------------------------------------------------------------------\n");
    				printf("仪器编号\t名称\t类别\t规格\t型号\t购买日期(年 月 日)\t单价（单位：元）    数量\n");
				    printf("\n------------------------------------------------------------------------------------------------\n");
				    printf("%s\t         %s\t%s\t%s       %s\t      %d.%d.%d\t        %s                   %s\n",&Ins[i].Num,&Ins[i].Name,&Ins[i].Sort,&Ins[i].Spec,&Ins[i].Model,Ins[i].Data[0],Ins[i].Data[1],Ins[i].Data[2],&Ins[i].Price,&Ins[i].Quality );
				  }
				if(flag == 0)
				   printf("该类别不存在!!!\n");
				system("pause");
				system("cls");    
				break;//容错处理 
			case 3:system("cls");return;
			default:printf("请在1-3之间选择\n");
		}
	}
	system("cls");
}

void Change()//修改
{
	system("cls");
	int i,item,flag;//item用于菜单选择， 
	char s1[LEN],s2[LEN];//s1用于储存仪器编号，s2用于用户修改输入 
back:
	flag=0;
	printf("请输入要修改的仪器编号:\n");
	scanf("%s",s1);
	for(i=0;i<n;i++)
	{
		if (strcmp(Ins[i].Num, s1) == 0){/*比较字符串是否相等*/
			//num = i;
			flag=1;
			printf("------------------\n");
			printf("1.修改名称\n");
			printf("2.修改类别\n");
			printf("3.修改规格\n");
			printf("4.修改数量\n");
			printf("5.修改日期\n");
			printf("6.修改价格\n");
			printf("7.修改型号\n");
			printf("8.退出本菜单\n");
			printf("9.修改其他仪器\n");
			printf("------------------\n");
			while(1)
			{
				printf("请选择子菜单编号:");
				scanf("%d",&item);
				switch(item)
				{
					case 1:
						printf("请输入新名字:\n");
						scanf("%s",&s2);
						strcpy(Ins[i].Name,s2);
						break;
					case 2:
						printf("请输入新类别:\n");
						scanf("%s",Ins[i].Sort);
						break;
					case 3:
						printf("请输入新规格:\n");
						scanf("%s",Ins[i].Spec);
						break;
					case 4:
						printf("请输入新数量:\n");
						scanf("%s",Ins[i].Quality);
						break;
					case 5:
						printf("请输入新日期(2021 03 21):\n");
						while(1){
		                int year,month,day;
	                  	scanf("%d",&year);
		                scanf("%d",&month);
		                scanf("%d",&day);
		                if(Monitor(year,month,day))//检测日期是否格式正确，详细函数跳转Monitor() 
		                {
			                Ins[i].Data[0]=year;
			                Ins[i].Data[1]=month;
		                 	Ins[i].Data[2]=day;
			                break;
		                }
		                else
		                  printf("日期格式输入错误，请重新输入.\n");//容错处理 
		                }
		                break;
					case 6:
						printf("请输入新价格:\n");
						scanf("%s",Ins[i].Price);
						break;
					case 7:
						printf("请输入新型号:\n");
						scanf("%s",Ins[i].Model);
						break;
				    case 8:system("cls");return;
				    case 9:system("cls");goto back; 
				    default:printf("请在1-9之间选择\n");//容错处理 
				}
			}
			printf("修改完毕！请及时保存！\n");
	}
	}
	if(flag==0){
		printf("没有该仪器编号！！！\n");
		goto back; 
    }
}

void Delete()//删除
{
	system("cls"); 
	int i,j,flag = 0;
	char s[LEN];//用于储存输入的编号，并对比查找 
	char cmp[LEN]={"0"};
	printf("请输入要删除仪器的编号:\n");
	printf("输入0返回\n");
	scanf("%s",s);
	if(strcmp(cmp,s) != 0){
	for(i = 0;i<n;i++)
	{
		if(strcmp(s,Ins[i].Num) == 0)//查找确定要删除的位置 
		{
	    	for(i;i<n;i++)
			{
				flag = 1;
				Ins[i]=Ins[i+1];//从要删除的开始，后面的覆盖前面的，直到n-1 
			}
		}
	}
	if (0 == flag){
		
		printf("该编号不存在!!!\n");//容错处理 
	}
	if(1 == flag){
		printf("删除成功!!!\n");//清空最后一个重复的结构体 
		n--; //仪器数量减一 
	}
	system("pause");
	system("cls");}
	else {system("cls");return;}
}

void Stat()//统计
{
back:
	system("cls");
	int item,i;
	int flag=0;
	char s[LEN];
	printf("--------------\n");
	printf("请选择统计方式\n");
	printf("--------------\n");
	printf("----1.日期----\n");
	printf("----2.单价----\n");
	printf("----3.类别----\n");
	printf("----4.返回----\n");
	printf("--------------\n");
	while(1){
	scanf("%d",&item);
	switch(item)
	{
		case 1:
			printf("请输入要统计的日期(2021 03 21)\n");
				while(1){
		               int year,month,day;
		               scanf("%d",&year);
		               scanf("%d",&month);
	               	   scanf("%d",&day);
		               if(Monitor(year,month,day))//容错处理 
	               	   {
	               	   	for(i=0;i<n;i++){
							  
			               if(Ins[i].Data[0]==year&&Ins[i].Data[1]==month&&Ins[i].Data[2]==day)
			               {
			               	printf("\n------------------------------------------------------------------------------------------------\n");
    				        printf("仪器编号\t名称\t类别\t规格\t型号\t购买日期(年 月 日)\t单价（单位：元）    数量\n");
				            printf("\n------------------------------------------------------------------------------------------------\n");
				            printf("%s\t         %s\t%s\t%s       %s\t      %d.%d.%d\t        %s                   %s\n",&Ins[i].Num,&Ins[i].Name,&Ins[i].Sort,&Ins[i].Spec,&Ins[i].Model,Ins[i].Data[0],Ins[i].Data[1],Ins[i].Data[2],&Ins[i].Price,&Ins[i].Quality );
			               	flag=1;
						   }
		               }
		               }
					   else
					   {
					   	printf("日期格式输入错误，请重新输入.\n");
					   	continue;
						} 
		               if(flag==1)
		                   {system("pause");
		                   goto back;}
		               if(flag==0)
		                   {printf("无该日期仪器资料\n");
		                   system("pause");
		                   goto back;}
		               }
				break;
			if(flag==0)
			printf("没有在%s时存入系统的仪器\n",&s);//容错处理 
		    break;
		case 2:
			printf("请输入要统计的单价\n");
			scanf("%s",s);
			for(i=0;i<n;i++)
			{
				if(strcmp(s,Ins[i].Price)==0)//查找对比 
				{
					printf("\n------------------------------------------------------------------------------------------------\n");
    				printf("仪器编号\t名称\t类别\t规格\t型号\t购买日期(年 月 日)\t单价（单位：元）    数量\n");
				    printf("\n------------------------------------------------------------------------------------------------\n");
				    printf("%s\t         %s\t%s\t%s       %s\t      %d.%d.%d\t        %s                   %s\n",&Ins[i].Num,&Ins[i].Name,&Ins[i].Sort,&Ins[i].Spec,&Ins[i].Model,Ins[i].Data[0],Ins[i].Data[1],Ins[i].Data[2],&Ins[i].Price,&Ins[i].Quality );
			        flag=1;
				}
			}
			if(flag==0)
			printf("没有单价为%s的仪器\n",&s);
		    system("pause");
			goto back;;
		case 3:
			printf("请输入要统计的类别\n");
			scanf("%s",s);
			for(i=0;i<n;i++)
			{
				if(strcmp(s,Ins[i].Sort)==0)//查找对比 
				{
					printf("\n------------------------------------------------------------------------------------------------\n");
    				printf("仪器编号\t名称\t类别\t规格\t型号\t购买日期(年 月 日)\t单价（单位：元）    数量\n");
				    printf("\n------------------------------------------------------------------------------------------------\n");
				    printf("%s\t         %s\t%s\t%s       %s\t      %d.%d.%d\t        %s                   %s\n",&Ins[i].Num,&Ins[i].Name,&Ins[i].Sort,&Ins[i].Spec,&Ins[i].Model,Ins[i].Data[0],Ins[i].Data[1],Ins[i].Data[2],&Ins[i].Price,&Ins[i].Quality );
			        flag=1;
				}
			}
			if(flag==0)
			printf("没有类别为%s的仪器\n",&s);//容错处理 
			system("pause");
			goto back;;
		case 4:
			printf("即将返回主菜单\n");
			system("cls");
		        return;
		default:printf("请在1~4之间选择\n");
	}
	}
}

void Save()//储存
{
	int i;
	FILE *fp;
	fp = fopen(filename, "w");
	fprintf(fp,"%d\n",n);//先储存仪器数量以便后续加载文件 
	for (i = 0; i < n; i++){
		fprintf(fp,"%s %s %s %s %s %d %d %d %s %s\n",&Ins[i].Num,&Ins[i].Name,&Ins[i].Sort,&Ins[i].Spec,&Ins[i].Model,Ins[i].Data[0],Ins[i].Data[1],Ins[i].Data[2],&Ins[i].Price,&Ins[i].Quality);
	}
	fclose(fp);
	system("cls");
	printf("保存成功！！！\n");
	system("pause");
}

int Open()//运行系统时打开文件加载进结构体和n 
{
	int i;
	FILE *fp;
	fp = fopen(filename, "r");//只读方式打开文件 
	if(fp == NULL)
	{
		printf(" \t\t\t未读取成功，请储存创建\n");
		return 0;
	}
	fscanf(fp,"%d\n",&n);//先读取仪器数量以便后续使用 
	for (i = 0; i < n; i++){
		fscanf(fp,"%s %s %s %s %s %d %d %d %s %s\n",Ins[i].Num,Ins[i].Name,Ins[i].Sort,Ins[i].Spec,Ins[i].Model,&Ins[i].Data[0],&Ins[i].Data[1],&Ins[i].Data[2],Ins[i].Price,Ins[i].Quality);
	}
	fclose(fp);
	return 1;
}

int Monitor(int x,int y,int z)//检查日期输入是否正确，x为年，y为月，z为日 
{
	int i;
	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//每月的最大天数 
    if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)//判断平闰年，并改变二月天数 
                month[1] = 29;
    if(x>=1000&&x<=9999&&y>=1&&y<=12&&z>=0)
    {
    	if(z<=month[y-1])
    	return 1;
	}
	return 0;
	}	

void menu()//主菜单页面
{
	system("color f4");
	int i,item,j;
	char Word[20]={"欢迎来到仪器管理系统"};
	char End[12]={"感谢您的使用"};
	while(k)
	{
	printf("-------------------------------------------------------------\n");
	printf("-------------------------------------------------------------\n");
	printf("------              ");
	for(i=0;i<20;i++)
	{
		Sleep(20);
		printf("%c",Word[i]);
	}
	printf("               ------\n"); 
	printf("------    1.新增                                       ------\n");
	printf("------    2.查找                                       ------\n");
	printf("------    3.修改                                       ------\n");
	printf("------    4.删除                                       ------\n");
	printf("------    5.统计                                       ------\n");
	printf("------    6.储存                                       ------\n");
	printf("------    7.退出                                       ------\n");
	printf("------    (请选择菜单编号)                             ------\n");
	printf("-------------------------------------------------------------\n");
	printf("-------------------------------------------------------------\n");
	printf("--------------------------------作者：               --------\n");
	fflush(stdin);
	scanf("%d",&item);
	switch(item)
	{
	  case 1:Insert();break;//增加 
      case 2:Search();break;//查找 
	  case 3:Change();break;//修改 
	  case 4:Delete();break;//删除 
	  case 5:Stat();break;//统计 
	  case 6:Save();break;//储存 
	  case 7:            //退出 
	      system("cls");
	  	back:
	  	  printf("确定储存了本次仪器的修改吗？\n");
	  	  printf("---------1.返回主菜单-------\n");
	  	  printf("---------2.继续退出---------\n");
	  	  scanf("%d",&j);
	  	  switch(j){
	      case 1:          //用于确保用户已储存新增信息 
	      	 system("cls");
		     break;	
		  
		  case 2:          //退出 
		     printf("即将退出程序......\n");
		     for(i=0;i<12;i++)
	         {
		       Sleep(50);
		       printf("%c",End[i]);
	         }
	         printf("\n");
		     k=0;
		     system("pause");
		     break;
		  
		  default :printf("请在1~2中选择\n");goto back;
		  }break;
	  default :printf("输入错误,请在1~7选择\n");break;
	}
	}
}

int main()
{
	if(Open())//打开文件 
	printf("打开文件成功\n");
	while(k)//运行主菜单 
	{
	  menu();
	}
	return 0;
}
