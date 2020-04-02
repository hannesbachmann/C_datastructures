# include <stdio.h>
# include <stdlib.h>

// single element with its own value and a pointer on the next element in the list
typedef struct element {
    int value;
    struct element_t *previous;
    struct element_t *next;
} element_t;

// whole linkedlist with head-element (first element in list) and size (length of the list)
typedef struct double_linkedlist {
    element_t *head;
    size_t size;
} double_linkedlist_t;

double_linkedlist_t *create_emptylist();
void append(double_linkedlist_t *mylist, int myvalue);
void remove_element(double_linkedlist_t *mylist, int myindex);
int get(double_linkedlist_t *mylist, int myindex);
void delete_doublelinkedlist(double_linkedlist_t *mylist);

double_linkedlist_t *create_emptylist(){
    double_linkedlist_t *newlist_ptr = malloc(sizeof(double_linkedlist_t));
    newlist_ptr->size = 0;
    newlist_ptr->head = NULL;

    return newlist_ptr;
}

void append(double_linkedlist_t *mylist, int myvalue){
    element_t *newelement_ptr = malloc(sizeof(element_t));
    newelement_ptr->value = myvalue;
    newelement_ptr->next = NULL;

    if (mylist->head == NULL){
        mylist->head = newelement_ptr;
        newelement_ptr->previous = NULL;
    }else{
        element_t *last_element = mylist->head;
        while (last_element->next != NULL){
            last_element = last_element->next;
        }
        newelement_ptr->previous = last_element;
        last_element->next = newelement_ptr;
    }
    mylist->size += 1;
}

void remove_element(double_linkedlist_t *mylist, int myindex){
    element_t *last_element = mylist->head;
    for (int index = 0; index<(myindex - 1); index++){
        last_element = last_element->next;
    }
    element_t *tmp_element = last_element->next;
    last_element->next = tmp_element->next;
    last_element = last_element->next;
    last_element->previous = tmp_element->previous;
    free(tmp_element);
    mylist->size -= 1;
}

int get(double_linkedlist_t *mylist, int myindex){
    element_t *last_element = mylist->head;
    for (int index = 0; index<(myindex); index++){
        last_element = last_element->next;
    }

    return last_element->value;
}

void delete_doublelinkedlist(double_linkedlist_t *mylist){
    element_t *last_element = mylist->head;
    while (last_element->next != NULL){
        element_t *tmp_element = last_element->next;
        last_element = tmp_element;
        free(tmp_element);
    }
    free(mylist->head);
    free(mylist);
}
