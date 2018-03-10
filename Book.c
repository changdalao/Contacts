#include"AddressBook.h"

void menu()
{
	printf("***************************************\n");
	printf("************С�ֶյ�ͨѶ¼*************\n");
	printf("**0.�˳�ͨѶ¼           1.�����ϵ��**\n");
	printf("**2.ɾ����ϵ��           3.������ϵ��**\n");
	printf("**4.�޸���Ϣ             5.��ʾͨѶ¼**\n");
	printf("**6.���ͨѶ¼           7.����������**\n");
	printf("***************************************\n");
}
int SearchName(PB pbook, const char* name)
{
	int i = 0;
	for (; i < pbook->count; i++)
	{
		if (0 == strcmp((pbook->people[i].name), name))
			return i;
	}
	return -1;//���ܷ���0���п��ܲ鵽����ϵ���ǵ�һ�����±�Ϊ0������0�Ļ�����Ὣ��һ����ϵ��©��
}
void ExitBook()//�˳�
{
	printf("bye!\n");
	Sleep(1000);
}
void ShownBook(PB pbook)//��ʾ
{
	if (pbook->count == 0)
		printf("ͨѶ¼Ϊ�գ�\n");
	else
	{
		int i = 0;
		printf("****************************С�ֶյ�ͨѶ¼*************************\n");
		printf("%10s\t%5s\t%6s\t%9s\t%9s\t\n", "����", "����", "�Ա�", "סַ", "��ϵ��ʽ");
		for (i = 0; i < pbook->count; i++)
		{
			printf("%10s\t%4d\t%5s\t%9s\t%10s\t\n", pbook->people[i].name, pbook->people[i].age, pbook->people[i].sex,
				pbook->people[i].address, pbook->people[i].phone);
		}
	}
	
}
void AddBook(PB pbook)//���
{
	
	if (MAX == pbook->count)
	{
		printf("ͨѶ¼����!\n");
		return;
	}
	else
	{		
		printf("����������>");
		scanf("%s", pbook->people[pbook->count].name);
		printf("����������>");
		scanf("%d", &(pbook->people[pbook->count].age));
		printf("�������Ա�>");
		scanf("%s", pbook->people[pbook->count].sex);
		printf("������סַ>");
		scanf("%s", pbook->people[pbook->count].address);
		printf("������绰>");
		scanf("%s", pbook->people[pbook->count].phone);
		(pbook->count)++;
	}
}
void Delate(PB pbook)//ɾ��
{
	if (pbook->count <= 0 || pbook->count > MAX) 
	{
		printf("û����ϵ�ˣ��޷�ִ�д˲���!\n");
		return;
	}
	else
	{
		printf("��������Ҫɾ���Ķ���>");
		char name[NAME] = { 0 };
		scanf("%s", name);
		int ret = SearchName(pbook, name);//����ɾ��������±�
		if (ret!=-1)//ɾ�����󼴽�����Ԫ������ǰ��һλ
		{
			//�Ż�,ɾ���Ķ�������һ��Ԫ�ؽ�����������1ʵ��ɾ��
			//PeopleList tmp;
			//tmp=pbook->people[ret];
			pbook->people[ret] = pbook->people[pbook->count-1];
			//pbook->people[pbook->count-1] = tmp;
			pbook->count--;
			printf("ɾ���ɹ�!\n");
			SortBook(pbook);
			/*for (int i = ret; i < pbook->count; i++)
			{
				pbook->people[i] = pbook->people[i + 1];
			}
			pbook->count--;*/
		}
		else
			printf("û�д���ϵ�ˣ�\n");
	}
}
void FindBook(PB pbook)
{
	if (0 == pbook->count)
	{
		printf("�޴���ϵ��!\n");
		return;
	}
	printf("��������Ҫ���ҵĶ���>");
	char name[10] = { 0 };
	scanf("%s", name);
	int ret = SearchName(pbook, name);
	if (ret!=-1)
	{
		printf("�ҵ�����Ҫ���ҵĶ���>\n");
		printf("����:%s   ����:%d  �Ա�:%s  סַ:%s  ��ϵ��ʽ:%s\n", pbook->people[ret].name,
			       pbook->people[ret].age,pbook->people[ret].sex,pbook->people[ret].address,pbook->people[ret].phone);
	}
	else
	{
		printf("û�д���ϵ��!\n");
		return;
	}
}
void Empty(PB pbook)
{
	pbook->count = 0;
	printf("��ճɹ���\n");
}
void ModifyBook(PB pbook)
{
	if (0 == pbook->count)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ִ�д˲���!\n");
		return;
	}
	printf("��������Ҫ�޸ĵĶ���>");
	char name[NAME] = { 0 };
	scanf("%s", name);
	int ret=SearchName(pbook, name);
	if (ret != -1)
	{
		int input = 0;
		printf("�޸�ʲô����>\n");
		printf("**1.���� 2.���� 3.�Ա� 4.סַ 5.��ϵ��ʽ**\n");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			printf("����������>");
			char NewName[NAME] = { 0 };
			scanf("%s", &NewName);
			strcpy(pbook->people[ret].name,NewName);
			break;
		case 2:
			printf("����������>");
			int Newage = 0;
			scanf("%d", &Newage);
			pbook->people[ret].age = Newage;
			break;
		case 3:
			printf("�������Ա�>");
			char Newsex[SEX] = { 0 };
			scanf("%s", &Newsex);
			strcpy(pbook->people[ret].sex, Newsex);
			break;
		case 4:
			printf("������סַ>");
			char Newaddres[ADDRESS] = { 0 };
			scanf("%s", &Newaddres);
			strcpy(pbook->people[ret].address, Newaddres);
			break;
		case 5:
			printf("��������ϵ��ʽ>");
			char Newphone[PHONE] = { 0 };
			scanf("%s", &Newphone);
			strcpy(pbook->people[ret].phone, Newphone);
			break;
		default:
			break;
		}
	}
	else
	{
		printf("û�д���ϵ��!\n");
		return;
	}
}
void SortBook(PB pbook)
{
	if (0 == pbook->count)
	{
		printf("ͨѶ¼��!\n");
		return;
	}
	for (int i = 0; i < pbook->count; i++)//ð������
	{
		for (int j = i+1; j < pbook->count; j++)
		{
			if (1 == strcmp(pbook->people[i].name, pbook->people[i + 1].name)) 
			{
				PeopleList tmp=pbook->people[i];
				pbook->people[i] = pbook->people[i + 1];
				pbook->people[i + 1] = tmp;
			}
		}	
	}
	ShownBook(pbook);
}
