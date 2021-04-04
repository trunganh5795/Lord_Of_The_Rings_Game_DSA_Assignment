void removeAt(ringsignList *head, int index, int &size){
	    if( index < 0 || index >= size || size == 0 ) return 1;
    if(size ==1){
    head->pNext= NULL;
    delete head;
    return ;
    }
    
    if(index == 0){
            ringsignList* tmp=head;
            int nRingsign = head->nRingsign;
            head = head->pNext;
            tmp->pNext =NULL;
            size--;
            return nRingsign;
    } else if( index == size -1){
    ringsignList* pre=head;
    for(int i=0;i<index-1;i++){
        pre=pre->pNext;
    }
    // tail=pre;
    pre->pNext =NULL;
    size--;
    return ;
    }else{
        ringsignList* pre=head;
        for(int i=0;i<index-1;i++){
        pre=pre->pNext;
        };
        int nRingsign = pre->pNext->nRingsign;
        pre->pNext=pre->pNext->pNext;
        size--;
        return;
    }
    return;
}