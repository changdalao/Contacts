#include"AddressBook.h"
int main()
{
	menu();
	PBook pbook = { 0 };
	while (1)
	{
		printf("请选择>");
		int input = 0;
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			AddBook(&pbook);//	添加
			break;
		case 2:
			Delate(&pbook);//删除
			break;
		case 3:
			FindBook(&pbook);//查找
			break;
		case 4:
			ModifyBook(&pbook);//修改
			break;
		case 5:
			ShownBook(&pbook);//显示
			break;
		case 6:
			Empty(&pbook);
			break;
		case 7:
			SortBook(&pbook);
			break;
		case 0:
			ExitBook();
			return 0;
		default:
			printf("选择错误");
			break;
		}
	}
	system("pause");
	return 0;
}