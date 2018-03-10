#include"AddressBook.h"

void menu()
{
	printf("***************************************\n");
	printf("************小胖墩的通讯录*************\n");
	printf("**0.退出通讯录           1.添加联系人**\n");
	printf("**2.删除联系人           3.查找联系人**\n");
	printf("**4.修改信息             5.显示通讯录**\n");
	printf("**6.清空通讯录           7.按名字排序**\n");
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
	return -1;//不能返回0，有可能查到的联系人是第一个，下标为0，返回0的话，则会将第一个联系人漏掉
}
void ExitBook()//退出
{
	printf("bye!\n");
	Sleep(1000);
}
void ShownBook(PB pbook)//显示
{
	if (pbook->count == 0)
		printf("通讯录为空！\n");
	else
	{
		int i = 0;
		printf("****************************小胖墩的通讯录*************************\n");
		printf("%10s\t%5s\t%6s\t%9s\t%9s\t\n", "姓名", "年龄", "性别", "住址", "联系方式");
		for (i = 0; i < pbook->count; i++)
		{
			printf("%10s\t%4d\t%5s\t%9s\t%10s\t\n", pbook->people[i].name, pbook->people[i].age, pbook->people[i].sex,
				pbook->people[i].address, pbook->people[i].phone);
		}
	}
	
}
void AddBook(PB pbook)//添加
{
	
	if (MAX == pbook->count)
	{
		printf("通讯录已满!\n");
		return;
	}
	else
	{		
		printf("请输入姓名>");
		scanf("%s", pbook->people[pbook->count].name);
		printf("请输入年龄>");
		scanf("%d", &(pbook->people[pbook->count].age));
		printf("请输入性别>");
		scanf("%s", pbook->people[pbook->count].sex);
		printf("请输入住址>");
		scanf("%s", pbook->people[pbook->count].address);
		printf("请输入电话>");
		scanf("%s", pbook->people[pbook->count].phone);
		(pbook->count)++;
	}
}
void Delate(PB pbook)//删除
{
	if (pbook->count <= 0 || pbook->count > MAX) 
	{
		printf("没有联系人，无法执行此操作!\n");
		return;
	}
	else
	{
		printf("请输入你要删除的对象>");
		char name[NAME] = { 0 };
		scanf("%s", name);
		int ret = SearchName(pbook, name);//查找删除对象的下标
		if (ret!=-1)//删除对象即将后面元素依次前移一位
		{
			//优化,删除的对象和最后一个元素交换，数量减1实现删除
			//PeopleList tmp;
			//tmp=pbook->people[ret];
			pbook->people[ret] = pbook->people[pbook->count-1];
			//pbook->people[pbook->count-1] = tmp;
			pbook->count--;
			printf("删除成功!\n");
			SortBook(pbook);
			/*for (int i = ret; i < pbook->count; i++)
			{
				pbook->people[i] = pbook->people[i + 1];
			}
			pbook->count--;*/
		}
		else
			printf("没有此联系人！\n");
	}
}
void FindBook(PB pbook)
{
	if (0 == pbook->count)
	{
		printf("无此联系人!\n");
		return;
	}
	printf("请输入你要查找的对象>");
	char name[10] = { 0 };
	scanf("%s", name);
	int ret = SearchName(pbook, name);
	if (ret!=-1)
	{
		printf("找到了你要查找的对象>\n");
		printf("姓名:%s   年龄:%d  性别:%s  住址:%s  联系方式:%s\n", pbook->people[ret].name,
			       pbook->people[ret].age,pbook->people[ret].sex,pbook->people[ret].address,pbook->people[ret].phone);
	}
	else
	{
		printf("没有此联系人!\n");
		return;
	}
}
void Empty(PB pbook)
{
	pbook->count = 0;
	printf("清空成功！\n");
}
void ModifyBook(PB pbook)
{
	if (0 == pbook->count)
	{
		printf("通讯录为空，无法执行此操作!\n");
		return;
	}
	printf("请输入需要修改的对象>");
	char name[NAME] = { 0 };
	scanf("%s", name);
	int ret=SearchName(pbook, name);
	if (ret != -1)
	{
		int input = 0;
		printf("修改什么内容>\n");
		printf("**1.姓名 2.年龄 3.性别 4.住址 5.联系方式**\n");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			printf("输入新姓名>");
			char NewName[NAME] = { 0 };
			scanf("%s", &NewName);
			strcpy(pbook->people[ret].name,NewName);
			break;
		case 2:
			printf("输入新年龄>");
			int Newage = 0;
			scanf("%d", &Newage);
			pbook->people[ret].age = Newage;
			break;
		case 3:
			printf("输入新性别>");
			char Newsex[SEX] = { 0 };
			scanf("%s", &Newsex);
			strcpy(pbook->people[ret].sex, Newsex);
			break;
		case 4:
			printf("输入新住址>");
			char Newaddres[ADDRESS] = { 0 };
			scanf("%s", &Newaddres);
			strcpy(pbook->people[ret].address, Newaddres);
			break;
		case 5:
			printf("输入新联系方式>");
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
		printf("没有此联系人!\n");
		return;
	}
}
void SortBook(PB pbook)
{
	if (0 == pbook->count)
	{
		printf("通讯录空!\n");
		return;
	}
	for (int i = 0; i < pbook->count; i++)//冒泡排序
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
