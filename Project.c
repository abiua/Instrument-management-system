#define MaxSize 60 //�ṹ�����������������

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN 20//�ṹ�����ַ����������󳤶ȣ��ɸ��� 
int k=1,n=0,m=0;//nΪ������������,k�����ж��Ƿ��˳�ϵͳ��mΪҪ���ӵ��������� 
 char filename[LEN]={"��������ϵͳ"};

struct{           //����ṹ�� 
	char Num[LEN];//��� 
	char Name[LEN];//���� 
	char Sort[LEN];//��� 
	char Spec[LEN];//��� 
	char Model[LEN];//���� 
	int Data[LEN];//���� 
	char Price[LEN];//�۸� 
	char Quality[LEN];//���� 
}Ins[MaxSize];

void Insert()//����
{
	int i=n,j,flag;//flag���ڵ�����ظ��Ľ��� 
	int key=0;//�����ж�m�Ƿ�Ϸ� 
	printf("������������Ҫ���ӵ���������:\n");
	printf("(���������0�����������������˳�)\n");
	scanf("%d",&m);
	if(m>0)
	{
		do
		{
			flag=1;
			while(flag)
			{
				flag = 0;
				printf("�������%d���������:",i+1);
				scanf("%s",Ins[i].Num);
				for(j=0;j<i;j++)
				{
					if(strcmp(Ins[i].Num,Ins[j].Num)==0)//���ر�� 
					{
						printf("�˱������ϵͳ�У�����������\n");
						flag = 1;
						break;
					}
				}
				
			 } 
		printf("�������%d������������\n",i+1);
		scanf("%s",Ins[i].Name);
	    
		printf("�������%d�����������\n",i+1);
		scanf("%s",Ins[i].Sort);
		
		printf("�������%d�������Ĺ��\n",i+1);
		scanf("%s",Ins[i].Spec);
		
		printf("�������%d���������ͺ�\n",i+1);
		scanf("%s",Ins[i].Model);
		
		printf("�������%d�������Ĺ�������(����:2021 03 21)\n",i+1);
		while(1){
		int year,month,day;
		scanf("%d",&year);
		scanf("%d",&month);
		scanf("%d",&day);
		if(Monitor(year,month,day))//�����������Ƿ�Ϸ����ж� 
		{
			Ins[i].Data[0]=year;
			Ins[i].Data[1]=month;
			Ins[i].Data[2]=day;
			break;
		}
		else
		  printf("���ڸ�ʽ�����������������.\n");
		}
		
		printf("�������%d�������ĵ���\n",i+1);
		scanf("%s",Ins[i].Price);
        
		printf("�������%d������������\n",i+1);
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
	n += m;//������������m�� 
	printf("������Ϣ¼�����\n");
	system("pause");
	system("cls");
}

void Search()//����
{
	system("cls");
	int i,item,flag;//flag�����жϲ�ѯ�������Ƿ����,item�����Ӳ˵�ѡ�� 
	char s1[LEN];
	char s2[LEN];
	while(1)
	{
	printf("------------------\n");
	printf("-----1.����Ų�ѯ-----\n");
	printf("-----2.������ѯ-----\n");
	printf("-----3.�˳����˵�-----\n");
	printf("------------------\n");
		printf("��ѡ��˵����\n");
		scanf("%d",&item);
		flag = 0;
		switch(item)
		{
			case 1:
				printf("��ѡ��Ҫ��ѯ���������:\n");
    			scanf("%s",s1);
    			for(i=0;i<n;i++)
    			  if(strcmp(s1,Ins[i].Num)==0)
    			  {
    				flag = 1;
    				printf("\n------------------------------------------------------------------------------------------------\n");
    				printf("�������\t����\t���\t���\t�ͺ�\t��������(�� �� ��)\t���ۣ���λ��Ԫ��    ����\n");
				    printf("\n------------------------------------------------------------------------------------------------\n");
				    printf("%s\t         %s\t%s\t%s       %s\t      %d.%d.%d\t        %s                   %s\n",&Ins[i].Num,&Ins[i].Name,&Ins[i].Sort,&Ins[i].Spec,&Ins[i].Model,Ins[i].Data[0],Ins[i].Data[1],Ins[i].Data[2],&Ins[i].Price,&Ins[i].Quality ); 
				  }
				if(0 == flag)
				  printf("�ñ�Ų�����!\n");
				system("pause");
				system("cls");  
				break;//�ݴ��� 
		    case 2:
				printf("������Ҫ��ѯ���������:\n");
				scanf("%s",s2);
				for(i = 0;i<n;i++)
				  if(strcmp(s2,Ins[i].Sort) == 0)
				  {
					flag = 1;
					printf("\n------------------------------------------------------------------------------------------------\n");
    				printf("�������\t����\t���\t���\t�ͺ�\t��������(�� �� ��)\t���ۣ���λ��Ԫ��    ����\n");
				    printf("\n------------------------------------------------------------------------------------------------\n");
				    printf("%s\t         %s\t%s\t%s       %s\t      %d.%d.%d\t        %s                   %s\n",&Ins[i].Num,&Ins[i].Name,&Ins[i].Sort,&Ins[i].Spec,&Ins[i].Model,Ins[i].Data[0],Ins[i].Data[1],Ins[i].Data[2],&Ins[i].Price,&Ins[i].Quality );
				  }
				if(flag == 0)
				   printf("����𲻴���!!!\n");
				system("pause");
				system("cls");    
				break;//�ݴ��� 
			case 3:system("cls");return;
			default:printf("����1-3֮��ѡ��\n");
		}
	}
	system("cls");
}

void Change()//�޸�
{
	system("cls");
	int i,item,flag;//item���ڲ˵�ѡ�� 
	char s1[LEN],s2[LEN];//s1���ڴ���������ţ�s2�����û��޸����� 
back:
	flag=0;
	printf("������Ҫ�޸ĵ��������:\n");
	scanf("%s",s1);
	for(i=0;i<n;i++)
	{
		if (strcmp(Ins[i].Num, s1) == 0){/*�Ƚ��ַ����Ƿ����*/
			//num = i;
			flag=1;
			printf("------------------\n");
			printf("1.�޸�����\n");
			printf("2.�޸����\n");
			printf("3.�޸Ĺ��\n");
			printf("4.�޸�����\n");
			printf("5.�޸�����\n");
			printf("6.�޸ļ۸�\n");
			printf("7.�޸��ͺ�\n");
			printf("8.�˳����˵�\n");
			printf("9.�޸���������\n");
			printf("------------------\n");
			while(1)
			{
				printf("��ѡ���Ӳ˵����:");
				scanf("%d",&item);
				switch(item)
				{
					case 1:
						printf("������������:\n");
						scanf("%s",&s2);
						strcpy(Ins[i].Name,s2);
						break;
					case 2:
						printf("�����������:\n");
						scanf("%s",Ins[i].Sort);
						break;
					case 3:
						printf("�������¹��:\n");
						scanf("%s",Ins[i].Spec);
						break;
					case 4:
						printf("������������:\n");
						scanf("%s",Ins[i].Quality);
						break;
					case 5:
						printf("������������(2021 03 21):\n");
						while(1){
		                int year,month,day;
	                  	scanf("%d",&year);
		                scanf("%d",&month);
		                scanf("%d",&day);
		                if(Monitor(year,month,day))//��������Ƿ��ʽ��ȷ����ϸ������תMonitor() 
		                {
			                Ins[i].Data[0]=year;
			                Ins[i].Data[1]=month;
		                 	Ins[i].Data[2]=day;
			                break;
		                }
		                else
		                  printf("���ڸ�ʽ�����������������.\n");//�ݴ��� 
		                }
		                break;
					case 6:
						printf("�������¼۸�:\n");
						scanf("%s",Ins[i].Price);
						break;
					case 7:
						printf("���������ͺ�:\n");
						scanf("%s",Ins[i].Model);
						break;
				    case 8:system("cls");return;
				    case 9:system("cls");goto back; 
				    default:printf("����1-9֮��ѡ��\n");//�ݴ��� 
				}
			}
			printf("�޸���ϣ��뼰ʱ���棡\n");
	}
	}
	if(flag==0){
		printf("û�и�������ţ�����\n");
		goto back; 
    }
}

void Delete()//ɾ��
{
	system("cls"); 
	int i,j,flag = 0;
	char s[LEN];//���ڴ�������ı�ţ����ԱȲ��� 
	char cmp[LEN]={"0"};
	printf("������Ҫɾ�������ı��:\n");
	printf("����0����\n");
	scanf("%s",s);
	if(strcmp(cmp,s) != 0){
	for(i = 0;i<n;i++)
	{
		if(strcmp(s,Ins[i].Num) == 0)//����ȷ��Ҫɾ����λ�� 
		{
	    	for(i;i<n;i++)
			{
				flag = 1;
				Ins[i]=Ins[i+1];//��Ҫɾ���Ŀ�ʼ������ĸ���ǰ��ģ�ֱ��n-1 
			}
		}
	}
	if (0 == flag){
		
		printf("�ñ�Ų�����!!!\n");//�ݴ��� 
	}
	if(1 == flag){
		printf("ɾ���ɹ�!!!\n");//������һ���ظ��Ľṹ�� 
		n--; //����������һ 
	}
	system("pause");
	system("cls");}
	else {system("cls");return;}
}

void Stat()//ͳ��
{
back:
	system("cls");
	int item,i;
	int flag=0;
	char s[LEN];
	printf("--------------\n");
	printf("��ѡ��ͳ�Ʒ�ʽ\n");
	printf("--------------\n");
	printf("----1.����----\n");
	printf("----2.����----\n");
	printf("----3.���----\n");
	printf("----4.����----\n");
	printf("--------------\n");
	while(1){
	scanf("%d",&item);
	switch(item)
	{
		case 1:
			printf("������Ҫͳ�Ƶ�����(2021 03 21)\n");
				while(1){
		               int year,month,day;
		               scanf("%d",&year);
		               scanf("%d",&month);
	               	   scanf("%d",&day);
		               if(Monitor(year,month,day))//�ݴ��� 
	               	   {
	               	   	for(i=0;i<n;i++){
							  
			               if(Ins[i].Data[0]==year&&Ins[i].Data[1]==month&&Ins[i].Data[2]==day)
			               {
			               	printf("\n------------------------------------------------------------------------------------------------\n");
    				        printf("�������\t����\t���\t���\t�ͺ�\t��������(�� �� ��)\t���ۣ���λ��Ԫ��    ����\n");
				            printf("\n------------------------------------------------------------------------------------------------\n");
				            printf("%s\t         %s\t%s\t%s       %s\t      %d.%d.%d\t        %s                   %s\n",&Ins[i].Num,&Ins[i].Name,&Ins[i].Sort,&Ins[i].Spec,&Ins[i].Model,Ins[i].Data[0],Ins[i].Data[1],Ins[i].Data[2],&Ins[i].Price,&Ins[i].Quality );
			               	flag=1;
						   }
		               }
		               }
					   else
					   {
					   	printf("���ڸ�ʽ�����������������.\n");
					   	continue;
						} 
		               if(flag==1)
		                   {system("pause");
		                   goto back;}
		               if(flag==0)
		                   {printf("�޸�������������\n");
		                   system("pause");
		                   goto back;}
		               }
				break;
			if(flag==0)
			printf("û����%sʱ����ϵͳ������\n",&s);//�ݴ��� 
		    break;
		case 2:
			printf("������Ҫͳ�Ƶĵ���\n");
			scanf("%s",s);
			for(i=0;i<n;i++)
			{
				if(strcmp(s,Ins[i].Price)==0)//���ҶԱ� 
				{
					printf("\n------------------------------------------------------------------------------------------------\n");
    				printf("�������\t����\t���\t���\t�ͺ�\t��������(�� �� ��)\t���ۣ���λ��Ԫ��    ����\n");
				    printf("\n------------------------------------------------------------------------------------------------\n");
				    printf("%s\t         %s\t%s\t%s       %s\t      %d.%d.%d\t        %s                   %s\n",&Ins[i].Num,&Ins[i].Name,&Ins[i].Sort,&Ins[i].Spec,&Ins[i].Model,Ins[i].Data[0],Ins[i].Data[1],Ins[i].Data[2],&Ins[i].Price,&Ins[i].Quality );
			        flag=1;
				}
			}
			if(flag==0)
			printf("û�е���Ϊ%s������\n",&s);
		    system("pause");
			goto back;;
		case 3:
			printf("������Ҫͳ�Ƶ����\n");
			scanf("%s",s);
			for(i=0;i<n;i++)
			{
				if(strcmp(s,Ins[i].Sort)==0)//���ҶԱ� 
				{
					printf("\n------------------------------------------------------------------------------------------------\n");
    				printf("�������\t����\t���\t���\t�ͺ�\t��������(�� �� ��)\t���ۣ���λ��Ԫ��    ����\n");
				    printf("\n------------------------------------------------------------------------------------------------\n");
				    printf("%s\t         %s\t%s\t%s       %s\t      %d.%d.%d\t        %s                   %s\n",&Ins[i].Num,&Ins[i].Name,&Ins[i].Sort,&Ins[i].Spec,&Ins[i].Model,Ins[i].Data[0],Ins[i].Data[1],Ins[i].Data[2],&Ins[i].Price,&Ins[i].Quality );
			        flag=1;
				}
			}
			if(flag==0)
			printf("û�����Ϊ%s������\n",&s);//�ݴ��� 
			system("pause");
			goto back;;
		case 4:
			printf("�����������˵�\n");
			system("cls");
		        return;
		default:printf("����1~4֮��ѡ��\n");
	}
	}
}

void Save()//����
{
	int i;
	FILE *fp;
	fp = fopen(filename, "w");
	fprintf(fp,"%d\n",n);//�ȴ������������Ա���������ļ� 
	for (i = 0; i < n; i++){
		fprintf(fp,"%s %s %s %s %s %d %d %d %s %s\n",&Ins[i].Num,&Ins[i].Name,&Ins[i].Sort,&Ins[i].Spec,&Ins[i].Model,Ins[i].Data[0],Ins[i].Data[1],Ins[i].Data[2],&Ins[i].Price,&Ins[i].Quality);
	}
	fclose(fp);
	system("cls");
	printf("����ɹ�������\n");
	system("pause");
}

int Open()//����ϵͳʱ���ļ����ؽ��ṹ���n 
{
	int i;
	FILE *fp;
	fp = fopen(filename, "r");//ֻ����ʽ���ļ� 
	if(fp == NULL)
	{
		printf(" \t\t\tδ��ȡ�ɹ����봢�洴��\n");
		return 0;
	}
	fscanf(fp,"%d\n",&n);//�ȶ�ȡ���������Ա����ʹ�� 
	for (i = 0; i < n; i++){
		fscanf(fp,"%s %s %s %s %s %d %d %d %s %s\n",Ins[i].Num,Ins[i].Name,Ins[i].Sort,Ins[i].Spec,Ins[i].Model,&Ins[i].Data[0],&Ins[i].Data[1],&Ins[i].Data[2],Ins[i].Price,Ins[i].Quality);
	}
	fclose(fp);
	return 1;
}

int Monitor(int x,int y,int z)//������������Ƿ���ȷ��xΪ�꣬yΪ�£�zΪ�� 
{
	int i;
	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//ÿ�µ�������� 
    if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)//�ж�ƽ���꣬���ı�������� 
                month[1] = 29;
    if(x>=1000&&x<=9999&&y>=1&&y<=12&&z>=0)
    {
    	if(z<=month[y-1])
    	return 1;
	}
	return 0;
	}	

void menu()//���˵�ҳ��
{
	system("color f4");
	int i,item,j;
	char Word[20]={"��ӭ������������ϵͳ"};
	char End[12]={"��л����ʹ��"};
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
	printf("------    1.����                                       ------\n");
	printf("------    2.����                                       ------\n");
	printf("------    3.�޸�                                       ------\n");
	printf("------    4.ɾ��                                       ------\n");
	printf("------    5.ͳ��                                       ------\n");
	printf("------    6.����                                       ------\n");
	printf("------    7.�˳�                                       ------\n");
	printf("------    (��ѡ��˵����)                             ------\n");
	printf("-------------------------------------------------------------\n");
	printf("-------------------------------------------------------------\n");
	printf("--------------------------------���ߣ�               --------\n");
	fflush(stdin);
	scanf("%d",&item);
	switch(item)
	{
	  case 1:Insert();break;//���� 
      case 2:Search();break;//���� 
	  case 3:Change();break;//�޸� 
	  case 4:Delete();break;//ɾ�� 
	  case 5:Stat();break;//ͳ�� 
	  case 6:Save();break;//���� 
	  case 7:            //�˳� 
	      system("cls");
	  	back:
	  	  printf("ȷ�������˱����������޸���\n");
	  	  printf("---------1.�������˵�-------\n");
	  	  printf("---------2.�����˳�---------\n");
	  	  scanf("%d",&j);
	  	  switch(j){
	      case 1:          //����ȷ���û��Ѵ���������Ϣ 
	      	 system("cls");
		     break;	
		  
		  case 2:          //�˳� 
		     printf("�����˳�����......\n");
		     for(i=0;i<12;i++)
	         {
		       Sleep(50);
		       printf("%c",End[i]);
	         }
	         printf("\n");
		     k=0;
		     system("pause");
		     break;
		  
		  default :printf("����1~2��ѡ��\n");goto back;
		  }break;
	  default :printf("�������,����1~7ѡ��\n");break;
	}
	}
}

int main()
{
	if(Open())//���ļ� 
	printf("���ļ��ɹ�\n");
	while(k)//�������˵� 
	{
	  menu();
	}
	return 0;
}
