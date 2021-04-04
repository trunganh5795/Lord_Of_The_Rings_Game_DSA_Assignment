#ifndef _definition_h_
#include "defs.h"
#define _definition_h_
#endif

//Arwen OK
void Arwen(ringsignList *&head, int &size)
{
	// cout<<444<<endl;
	if (size == 0)
		return;
	if (head == NULL)
		return;
	if (head->pNext == NULL)
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
	for (int i = 0; i < size - 2; i++)
	{
		pre = pre->pNext;
	}

	if (pre->pNext->nRingsign == 10)
	{
		// cout << "etststs" << endl;
		pre->pNext->nRingsign = 0;
		pre->nRingsign += 1;
		size--;
		return Arwen(head, size);
	}
	else
	{
		return;
	}
}

//RemoveAt tested OK
void removeAt(ringsignList *&head, ringsignList *&tail, int index, int &size)
{
	// cout << "run removeAt";
	if (index < 0 || index >= size || size == 0)
		return;
	if (size == 1)
	{
		head = NULL;
		tail = NULL;
		size--;
		// head = NULL ????
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
		// int nRingsign = pre->pNext->nRingsign;
		pre->pNext = pre->pNext->pNext;
		size--;
		return;
	}
	return;
}

bool removeIteam(ringsignList *&head, ringsignList *&tail, int &item, int &size)
{
	if (head->nRingsign == item)
	{
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
}

void add(ringsignList *&head, ringsignList *&tail, int &item, int &size)
{
	ringsignList *tmp = new ringsignList();
	if (size == 0)
	{
		//    head=tmp;
		//    tail=tmp;
		//    head->nRingsign =item;
		// cout << "size=0" << endl;
		//    size++;
		//    return;
	}
	else
	{
		// cout << "size != 0" << endl;
		tmp->nRingsign = item;
		tmp->pNext = NULL;
		tail->pNext = tmp;
		tail = tmp;
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

void reverseList(ringsignList *&head)
{
	if (head == NULL || head->pNext == NULL)
		return; // it is always suggested to use this condition in LinkedList based questions (improves the time complexity a lot).

	// ringsignList* curr = head;
	// ringsignList* prev = NULL;
	// ringsignList* n;

	// while(curr != NULL){
	// 	n = curr->pNext;
	// 	curr->pNext = prev;
	// 	prev = curr;
	// 	curr = n;
	// }

	ringsignList *prev = NULL;
	ringsignList *tempNext = NULL;
	ringsignList *cur = head;

	while (cur)
	{
		// cout << "reverse" << endl;
		tempNext = cur->pNext;
		cur->pNext = prev;
		prev = cur;
		cur = tempNext;
	}
	head = prev;
	return;
}

ringsignList *combat(knight &theKnight, eventList *pEvent)
{
	// cout << "Ok--------------------" << endl;
	ringsignList *pList = NULL;
	//fighting for honor and love here
	int HP = theKnight.HP;
	int initHP = HP;
	int level = theKnight.level;
	int ringSign = theKnight.nInitRingsign;
	// int event = pEvent->nEventCode;
	pList = new ringsignList();
	ringsignList *head = pList;
	pList->nRingsign = ringSign;
	// pList->nRingsign = ringSign;
	// cout << "HP Init: " << HP << endl
	// 	 << "level: " << level << endl
	// 	 << "RingSign Init: " << ringSign << endl
	// 	 << "First Event: " << pEvent->nEventCode << endl;
	int position = 1;
	int sizeOfRingsignList = 1;
	int b, levelOf;
	for (pEvent; pEvent != NULL; pEvent = pEvent->pNext)
	{

		// tính level của đối thủ position chính là i
		b = position % 10;
		levelOf = position > 6 ? (b > 5 ? b : 5) : b;

		int event = pEvent->nEventCode;
		// cout << "levelOF: " << levelOf << endl;
		// cout << "event: " << event;
		if (event == 0) //sự kiện bằng 0 thì thúc hành trình
		{
			return head;
		}
		else if (event == 7 || event == 8)
		{
			if (event == 7)
			{
				// position++;
				// cout<<"before 7: "<<head->nRingsign;
				pList->nRingsign += 1;
				if (head->nRingsign == 0)
				{
					ringsignList *tmp = head;
					head = head->pNext;
					tmp->pNext = NULL;
					delete tmp;
					sizeOfRingsignList--;
				}
				// cout << head->nRingsign;
				Arwen(head, sizeOfRingsignList);
			}
			else //Trường hợp gặp 8
			{
				if (HP != initHP)
				{
					HP = initHP;
					if (HP != 777 && HP != 888)
					{
						removeAt(head, pList, sizeOfRingsignList - 1, sizeOfRingsignList);
					}

					if (head == NULL)
					{
						return head;
					}
					//--------------------------------------
				}
				else //khi hiệp sĩ gặp sự kiện 7
				{
					//Nothing change when the Knight's HP is full
				}
			}
			// position++;
		}
		else // trường hợp 1 2 3 4 5 6 9
		{

			// Asign
			int character = event / 10;
			int takeRingSign = event % 10;
			// had character , takeRingSign , LevelOf , HP , level , RingSign
			// cout << "character: " << character << endl<< "takeRingSign: " << takeRingSign << endl;
			if (level > levelOf)
			{

				if (character != 9)
				{
					// Hiệp sĩ thắng => takeRingSign
					// ringsignList *gotRing = new ringsignList();
					// gotRing->nRingsign = takeRingSign;
					// gotRing->pNext = NULL;
					// pList->pNext = gotRing;
					// pList = gotRing;
					// sizeOfRingsignList++;
					// cout << "Position: " << sizeOfRingsignList << endl;

					if ((character == 3 || character == 6) && initHP == 888)
					{
					}
					else if ((character == 1 || character == 2 || character == 4 || character == 6) && initHP == 999)
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
					// cout << " thang 9";
					reverseList(head);
				}
			}
			else if (level < levelOf)
			{ //trường hợp thua
				if ((character == 3 || character == 6) && initHP == 888)
				{
				}
				else if ((character == 1 || character == 2 || character == 4 || character == 6) && initHP == 999)
				{
				}
				else
				{
					// cout << "character: " << character << endl;
					double baseDamage = getBaseDamge(character, levelOf);
					HP = HP - baseDamage;
					// cout << "baseDamage" << baseDamage << endl;
					if ((character == 4 || character == 9 || character == 5) && initHP != 777)
					{
						// cout << "heahseaseasdasdasdasdas";
						if (character == 4)
						{
							// cout << "thua 4" << endl;
							int index = -1;
							int indexOfX = -1;
							for (ringsignList *tmp = head; tmp != NULL; tmp = tmp->pNext)
							{
								index++;
								// cout << "index2222222222222222" << endl;
								if (tmp->nRingsign == takeRingSign)
								{
									indexOfX = index;
								}
							}
							// cout << "indexOfX" << indexOfX << endl;
							if (indexOfX != -1)
							{
								removeAt(head, pList, indexOfX, sizeOfRingsignList);
							}
						}
						else if (character == 5)
						{
							//thua 5
							// cout << "thua 5";
							for (int i = 0; i < 3; i++)
							{
								removeAt(head, pList, 0, sizeOfRingsignList);
							}
						}
						else
						{
							//thua 9
							// cout << "thua 9" << endl;
							for (int i = 0; i < 2; i++)
							{
								// cout << position;
								bool result = removeIteam(head, pList, takeRingSign, sizeOfRingsignList);
								if (!result)
									break;
							}
							// removeIteam(head,pList,takeRingSign,position);
							// cout << "position: " << sizeOfRingsignList << endl;
						}
						if (sizeOfRingsignList == 0)
							return head;
					}
					if (HP <= 0)
						return head;
				}
			}

			// cout<<"oksssssssssssssssssssssssssssss";
			//trường hợp 4 5 9
		}
		position++;
	}

	// removeAt(head, position-1, position);
	// cout << "head out: " << head->nRingsign << endl;
	return head;
}

int checkPalindrome(ringsignList *pRingsign)
{
	int size = 0;
    ringsignList *start = pRingsign;
    ringsignList *end = pRingsign;
    for (pRingsign; pRingsign != NULL; pRingsign = pRingsign->pNext)
    {
        size++;
    }
    cout << "size: " << size << endl;
    if (size == 0)
        return 0;
    // return size;
    for (int i = 0; i < size - 1; i++)
    {
        end = end->pNext;
    }
    // cout << "data end: " << end->data << endl;
    // if(start->data!=end->data)
    ///////////////////////
    for (size; size > 1; size-=2)
    {

		int a=0;
        // cout<<"size: "<<size<<endl;
        ringsignList *tmp = start;
        if (start == NULL)
        {
            // cout << "0 element";
            return 0;
        }
        if (start->pNext == NULL)
        {
            // cout << "1 element";
            return 1;
        }
        for (tmp; tmp->pNext != end; tmp = tmp->pNext)
        {
			a=1;
        }
        // cout<<"start->data: "<<start->nRingsign<<endl;
        // cout<<"tmp nRingsign: "<<tmp->pNext->nRingsign<<endl;
        if (tmp->pNext->nRingsign != start->nRingsign)
        {
                // cout<<"kkhac nRingsign"<<endl;
            return 0;
        }
        end=tmp;
        start=start->pNext;
    
    }
    return 1;
}
