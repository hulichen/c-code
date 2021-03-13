#include"slist.h"


int main()
{
	SListNode* mylist;
	SListInit(&mylist);
	SLTDateType item, key;
	int pos;
	SListNode* p;
	SListNode* p_os;
	int select = 1;
	while (select)
	{
		printf("********************************************\n");
		printf("* [0] quit_system      [1] push_back       *\n");
		printf("* [2] push_front       [3] show_list       *\n");
		printf("* [4] pop_back         [5] pop_front       *\n");
		printf("* [6] length           [7] insert_val      *\n");
		printf("* [8] delete_val       [9] find            *\n");
		printf("* [10] sort            [11] reverse        *\n");
		printf("* [12] remove_all      [13] clear          *\n");
		printf("********************************************\n");
		printf("��ѡ��:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("������Ҫ���������(��-1����):>");
			while (scanf("%d", &item), item != -1)  //���ű��ʽ
				SListPushBack(&mylist, item);
			break;
		case 2:
			printf("������Ҫ���������(��-1����):>");
			while (scanf("%d", &item), item != -1)  //���ű��ʽ
				SListPushFront(&mylist, item);
			break;
		case 3:
			SListPrint(mylist);
			break;
		case 4:
			SListPopBack(&mylist); // �������βɾ
			break;
		case 5:
			SListPopFront(&mylist);//ͷɾ
			break;
		//case 6:
		//	printf("��Ϊ:>%d\n", SListLength(&mylist));
		//	break;
		case 7:
			p_os  = mylist->next->next;
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			SListInsertAfter(p_os, item);
			break;
		case 8:
			p_os = mylist;
			SListEraseAfter(p_os);
			break;
		case 9:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			p = SListFind(mylist, key);
			if (p == NULL)
				printf("Ҫ���ҵ�ֵ%d������.\n", key);
			else
				printf("Ҫ���ҵ�ֵ%d����.\n", key);
			break;
		//case 10:
		//	SListSort(&mylist);
		//	SListShow(&mylist);
		//	break;
		//case 11:
		//	SListReverse(&mylist);
		//	break;
		//case 12:
		//	printf("������Ҫɾ����ֵ:>");
		//	scanf("%d", &key);
		//	SListRemoveAll(&mylist, key);
		//	break;
		case 13:
			SListDestory(&mylist);
			break;
		default:
			break;
		}
		SListPrint(mylist);
		//system("pause");
		//system("cls");
	}
	//SListDestroy(&mylist);
	return 0;
}
