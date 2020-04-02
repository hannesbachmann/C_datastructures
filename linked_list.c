# include <stdio.h>
# include <stdlib.h>

// single element with its own value and a pointer on the next element in the list
typedef struct element {
    int value;
    struct element_t *next;
} element_t;

// whole linkedlist with head-element (first element in list) and size (length of the list)
typedef struct linkedlist {
    element_t *head;
    size_t size;
} linkedlist_t;

linkedlist_t *create_emptylist();
void append(linkedlist_t *mylist, int myvalue);
void remove_element(linkedlist_t *mylist, int myindex);
int get(linkedlist_t *mylist, int myindex);
void delete_linkedlist(linkedlist_t *mylist);


linkedlist_t *create_emptylist(){
    linkedlist_t *newlist_ptr = malloc(sizeof(linkedlist_t));
    newlist_ptr->size = 0;
    newlist_ptr->head = NULL;

    return newlist_ptr;
}

void append(linkedlist_t *mylist, int myvalue){
    element_t *newelement_ptr = malloc(sizeof(element_t));
    newelement_ptr->value = myvalue;
    newelement_ptr->next = NULL;

    if (mylist->head == NULL){
        mylist->head = newelement_ptr;
    }else{
        element_t *last_element = mylist->head;
        while (last_element->next != NULL){
            last_element = last_element->next;
        }
        last_element->next = newelement_ptr;
    }
    mylist->size += 1;
}

void remove_element(linkedlist_t *mylist, int myindex){
    element_t *last_element = mylist->head;
    for (int index = 0; index<(myindex - 1); index++){
        last_element = last_element->next;
    }
    element_t *tmp_element = last_element->next;
    last_element->next = tmp_element->next;
    free(tmp_element);
    mylist->size -= 1;
}

int get(linkedlist_t *mylist, int myindex){
    element_t *last_element = mylist->head;
    for (int index = 0; index<(myindex); index++){
        last_element = last_element->next;
    }

    return last_element->value;
}

void delete_linkedlist(linkedlist_t *mylist){
    element_t *last_element = mylist->head;
    while (last_element->next != NULL){
        element_t *tmp_element = last_element->next;
        last_element = tmp_element;
        free(tmp_element);
    }
    free(mylist->head);
    free(mylist);
}
