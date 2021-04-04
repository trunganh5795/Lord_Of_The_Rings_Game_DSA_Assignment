#ifndef _definition_h_
#include "defs.h"
#define _definition_h_
#endif

ringsignList *combat(knight &theKnight, eventList *pEvent)
{
    ringsignList *pList = NULL;
    int HP = theKnight.HP;
    int level = theKnight.level;
    int ringSign = theKnight.nInitRingsign;
    // cout << "HP Init: " << HP << endl
    // 	 << "level: " << level << endl
    // 	 << "RingSign Init: " << ringSign << endl
    // 	 << "First Event: " << pEvent->nEventCode << endl;
    pList = new ringsignList();
    ringsignList *head = pList;
    pList->nRingsign = ringSign;
    for (; pEvent != NULL; pEvent = pEvent->pNext)
    {
        cout<<pEvent->nEventCode<<" ";
    }

        return head;
    }
    int checkPalindrome(ringsignList * pRingsign)
    {
        return 0;
    }