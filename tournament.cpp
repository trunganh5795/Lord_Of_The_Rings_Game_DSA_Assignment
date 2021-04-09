#ifndef _definition_h_
#include "defs.h"
#define _definition_h_
#endif
/*
Author : Truong Ngoc Trung Anh - 2020004
DSA Assignment 2021
Solved By me
*/

//--------------SOLUTION ----------------------//

//Arwen OK
void Arwen(ringsignList *&head, int &size, int size2)
{
	// cout<<444<<endl;
	if (size == 0)
		return;
	if (head == NULL)
		return;
	if (head->pNext == NULL || head->nRingsign == 10)
	{
		if (head->nRingsign == 10)
		{

			ringsignList *tmp = new ringsignList();
			tmp->nRingsign = 1;
			tmp->pNext = head;
			head->nRingsign = 0;
			head = tmp;
			size++;
			return;
		}
		else
		{
			return;
		}
	}
	ringsignList *pre = head;
	// int sizeCopy = size;
	for (int i = 0; i < size2 - 2; i++)
	{
		pre = pre->pNext;
	}
	// cout << "aww2" << pre->pNext->nRingsign << endl;
	if (pre->pNext->nRingsign == 10)
	{
		// cout << "arwen"<<endl;
		pre->pNext->nRingsign = 0;
		pre->nRingsign += 1;
		size2--;
		// cout << "size: " << size2 << endl;
		return Arwen(head, size, size2);
	}
	else
	{
		return;
	}
}
//RemoveAt tested OK
void removeAt(ringsignList *&head, ringsignList *&tail, int index, int &size)
{
	if (index < 0 || index >= size || size == 0)
		return;
	if (size == 1)
	{
		head = NULL;
		tail = NULL;
		size--;
		return;
	}
	if (index == 0)
	{
		ringsignList *tmp = head;
		head = head->pNext;
		tmp->pNext = NULL;
		size--;
		return;
	}
	else if (index == size - 1)
	{
		// cout<<123333333<<endl;
		ringsignList *pre = head;
		for (int i = 0; i < index - 1; i++)
		{
			pre = pre->pNext;
		}
		tail = pre;
		pre->pNext = NULL;
		size--;
		return;
	}
	else
	{
		ringsignList *pre = head;
		for (int i = 0; i < index - 1; i++)
		{
			pre = pre->pNext;
		};
		pre->pNext = pre->pNext->pNext;
		size--;
		return;
	}
	return;
}
bool removeIteam(ringsignList *&head, ringsignList *&tail, int &item, int &size)
{
	// cout << "12312";
	if (head == NULL)
	{
		// cout << "null";
		return 0;
	}

	if (head->nRingsign == item)
	{
		// cout << 123 << endl;
		removeAt(head, tail, 0, size);
		return 1;
	}
	else
	{
		ringsignList *p = head;
		int index = 0;
		for (int i = 0; i < size - 1; i++)
		{

			p = p->pNext;
			// cout << "asda: " << p->nRingsign << " " << item << " ";
			if (p->nRingsign == item)
			{

				index = i + 1;
				removeAt(head, tail, index, size);
				return 1;
			}
		}
		return 0;
	}
	return 1;
	///////////////////////////////////////////////////////////////////////////

	// ringsignList *tmp = head;

	// while (head->nRingsign == item)
	// {
	//     head = head->pNext;
	// }
	// while (tmp->pNext != NULL)
	// {
	//     if (tmp->pNext->nRingsign == item)
	//     {
	//         tmp->pNext = tmp->pNext->pNext;
	//     }
	//     else
	//     {
	//         tmp = tmp->pNext;
	//     }
	// }
	// return 1;
}
void add(ringsignList *&head, ringsignList *&tail, int &item, int &size)
{

	ringsignList *tmp = new ringsignList();
	if (size == 0)
	{
		////
	}
	else
	{
		// cout<<123<<endl;
		tmp->nRingsign = item;
		tmp->pNext = NULL;
		tail->pNext = tmp;
		tail = tmp;
		// cout<<12312312;
		// delete tmp2;
		size++;
		return;
	}
}
double getBaseDamge(int charac, int levelO)
{
	if (charac == 1)
		return 1 * levelO * 10;
	if (charac == 2)
		return 1.8 * levelO * 10;
	if (charac == 3)
		return 4.5 * levelO * 10;
	if (charac == 4)
		return 8.2 * levelO * 10;
	if (charac == 5)
		return 7.5 * levelO * 10;
	if (charac == 6)
		return 9 * levelO * 10;
	if (charac == 9)
		return 0.1 * levelO * 10;
	return 0;
}
void reverseList(ringsignList *&head, ringsignList *&tail)
{
	if (head == NULL || head->pNext == NULL)
		return;
	ringsignList *prev = NULL;
	ringsignList *tempNext = NULL;
	ringsignList *cur = head;
	while (cur)
	{
		tempNext = cur->pNext;
		cur->pNext = prev;
		prev = cur;
		cur = tempNext;
	}
	tail = head;
	head = prev;
	return;
}
ringsignList *combat(knight &theKnight, eventList *pEvent)
{
	int countttt = 0;
	ringsignList *pList = NULL;
	int initHP = theKnight.HP;
	// int initHP = HP;
	int level = theKnight.level;
	int ringSign = theKnight.nInitRingsign;
	pList = new ringsignList();
	ringsignList *head = pList;
	pList->nRingsign = ringSign;
	int position = 1;
	int sizeOfRingsignList = 1;
	int b, levelOf;
	for (; pEvent != NULL; pEvent = pEvent->pNext)
	{
		countttt++;
		b = position % 10;
		levelOf = position > 6 ? (b > 5 ? b : 5) : b;
		int event = pEvent->nEventCode;
		if (event == 0) //sự kiện bằng 0 thì kết thúc hành trình
		{
			return head;
		}
		else if (event == 7 || event == 8)
		{
			if (event == 7)
			{
				// cout<<123<<endl;
				pList->nRingsign += 1;
				if (head->nRingsign == 0)
				{
					ringsignList *tmp = head;
					head = head->pNext;
					tmp->pNext = NULL;
					delete tmp;
					sizeOfRingsignList--;
				}
				Arwen(head, sizeOfRingsignList, sizeOfRingsignList);
			}
			else //Trường hợp gặp 8
			{
				if (theKnight.HP != initHP)
				{
					theKnight.HP = initHP;
					if (initHP != 777 && initHP != 888)
					{
						removeAt(head, pList, sizeOfRingsignList - 1, sizeOfRingsignList);
					}
					if (head == NULL)
					{
						return head;
					}
				}
				else //khi hiệp sĩ gặp sự kiện 8
				{
					//Nothing change when the Knight's HP is full
				}
			}
		}
		else // trường hợp 1 2 3 4 5 6 9
		{
			// Asignif
			int character, takeRingSign;
			if (event < 10)
			{
				character = event;
				takeRingSign = 0;
			}
			else
			{
				character = event / 10;
				takeRingSign = event % 10;
			}

			if (level > levelOf)
			{
				if (character != 9) // trường hop 1 2 3 4 5 6
				{
					if ((character == 3 || character == 6) && initHP == 888)
					{
					}
					else if ((character == 1 || character == 2 || character == 6) && initHP == 999)
					{
					}
					else
					{
						add(head, pList, takeRingSign, sizeOfRingsignList);
					}
				}
				else
				{
					//trường hợp thắng 9
					reverseList(head, pList);
				}
			}
			else if (level < levelOf)
			{ //trường hợp thua
				if ((character == 3 || character == 6) && initHP == 888)
				{
				}
				else if ((character == 1 || character == 2 || character == 6) && initHP == 999)
				{
				}
				else
				{
					double baseDamage = getBaseDamge(character, levelOf);
					theKnight.HP = theKnight.HP - baseDamage;
					if (theKnight.HP <= 0)
						return NULL;
					if ((character == 4 || character == 9 || character == 5) && initHP != 777)
					{
						// cout<<"helllllllllllooooo";
						if (character == 4)
						{ 
							int index = -1;
							int indexOfX = -1;
							for (ringsignList *tmp = head; tmp != NULL; tmp = tmp->pNext)
							{
								index++;
								if (tmp->nRingsign == takeRingSign)
								{
									indexOfX = index;
								}
							}
							// cout<<"indexOfX: "<<indexOfX<<endl;
							if (indexOfX != -1)
							{
								removeAt(head, pList, indexOfX, sizeOfRingsignList);
							}
						}
						else if (character == 5)
						{
							for (int i = 0; i < 3; i++)
							{
								removeAt(head, pList, 0, sizeOfRingsignList);
							}
						}
						else
						{

							//thua 9
							int loop = sizeOfRingsignList;
							for (int i = 0; i < loop; i++)
							{
								// cout << position;
								// cout<<endl<<loop<<endl;
								bool result = removeIteam(head, pList, takeRingSign, sizeOfRingsignList);
								if (!result)
									break;
							}
							if (head == NULL)
								return head;
						}
						if (sizeOfRingsignList == 0)
							return head;
					}
					if (theKnight.HP <= 0)
					{

						cout << endl
							 << "count: " << countttt << endl;
						return head;
					}
				}
			}
		}
		position++;
	}
	cout << endl
		 << "count: " << countttt << endl;
	return head;
}
int checkPalindrome(ringsignList *pRingsign)
{
	int size = 0;
	ringsignList *start = pRingsign;
	ringsignList *end = pRingsign;
	for (; pRingsign != NULL; pRingsign = pRingsign->pNext)
	{
		size++;
	}
	if (size == 0)
		return 0;
	// return size;
	for (int i = 0; i < size - 1; i++)
	{
		end = end->pNext;
	}
	///////////////////////
	for (; size > 1; size -= 2)
	{
		ringsignList *tmp = start;
		if (start == NULL)
		{
			return 0;
		}
		if (start->pNext == NULL)
		{
			return 1;
		}
		for (; tmp->pNext != end; tmp = tmp->pNext)
		{
		}
		if (tmp->pNext->nRingsign != start->nRingsign)
		{
			return 0;
		}
		end = tmp;
		start = start->pNext;
	}
	return 1;
}
