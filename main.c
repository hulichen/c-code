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
		printf("请选择:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)  //逗号表达式
				SListPushBack(&mylist, item);
			break;
		case 2:
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)  //逗号表达式
				SListPushFront(&mylist, item);
			break;
		case 3:
			SListPrint(mylist);
			break;
		case 4:
			SListPopBack(&mylist); // 单链表的尾删
			break;
		case 5:
			SListPopFront(&mylist);//头删
			break;
		//case 6:
		//	printf("表长为:>%d\n", SListLength(&mylist));
		//	break;
		case 7:
			p_os  = mylist->next->next;
			printf("请输入要插入的值:>");
			scanf("%d", &item);
			SListInsertAfter(p_os, item);
			break;
		case 8:
			p_os = mylist;
			SListEraseAfter(p_os);
			break;
		case 9:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			p = SListFind(mylist, key);
			if (p == NULL)
				printf("要查找的值%d不存在.\n", key);
			else
				printf("要查找的值%d存在.\n", key);
			break;
		//case 10:
		//	SListSort(&mylist);
		//	SListShow(&mylist);
		//	break;
		//case 11:
		//	SListReverse(&mylist);
		//	break;
		//case 12:
		//	printf("请输入要删除的值:>");
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
