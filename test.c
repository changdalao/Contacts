#include"AddressBook.h"
int main()
{
	menu();
	PBook pbook = { 0 };
	while (1)
	{
		printf("��ѡ��>");
		int input = 0;
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			AddBook(&pbook);//	���
			break;
		case 2:
			Delate(&pbook);//ɾ��
			break;
		case 3:
			FindBook(&pbook);//����
			break;
		case 4:
			ModifyBook(&pbook);//�޸�
			break;
		case 5:
			ShownBook(&pbook);//��ʾ
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
			printf("ѡ�����");
			break;
		}
	}
	system("pause");
	return 0;
}