# include <stdio.h>
# include <stdlib.h>

typedef struct element{
    int value;
    struct element *right_child;
    struct element *left_child;
}element_t;

typedef struct bin_tree{
    element_t *root;
    int size;
}bin_tree_t;

bin_tree_t *create_bintree();
void add_element(bin_tree_t *mytree, element_t *parent_element, int myvalue);
element_t *get_element(bin_tree_t *mytree, int myvalue);
element_t *recursive_search(element_t *myelement, int myvalue);
void delete_element(bin_tree_t *mytree, int myvalue);
element_t *search_for_parent(element_t *root_element, element_t *child_element);
void delete_bintree(bin_tree_t *mytree);


bin_tree_t *create_bintree(){
    bin_tree_t *new_bintree = malloc(sizeof(bin_tree_t));
    new_bintree->root = NULL;
    new_bintree->size = 0;
    return new_bintree;
}

void add_element(bin_tree_t *mytree, element_t *parent_element, int myvalue){
    element_t *new_element = malloc(sizeof(element_t));
    new_element->value = myvalue;
    new_element->right_child = NULL;
    new_element->left_child = NULL;

    if (mytree->root == NULL){
        mytree->root = new_element;
    }else{
        if (parent_element->left_child == NULL){
            parent_element->left_child = new_element;
        }else{
            parent_element->right_child = new_element;
        }
    }
    mytree->size += 1;
}

element_t *recursive_search(element_t *myelement, int myvalue){
    if (myelement->value == myvalue){
        return myelement;
    }else{
        if (recursive_search(myelement->left_child, myvalue) != NULL){
            return recursive_search(myelement->left_child, myvalue);
        }else if (recursive_search(myelement->left_child, myvalue) != NULL){
            return recursive_search(myelement->right_child, myvalue);
        }else{
            return NULL;
        }
    }
}

element_t *get_element(bin_tree_t *mytree, int myvalue){
    element_t *last_element = recursive_search(mytree->root, myvalue);
    return last_element;
}

element_t *search_for_parent(element_t *root_element, element_t *child_element){
    if ((root_element->left_child == child_element) || (root_element->right_child == child_element)){
        return root_element;
    }else{
        if (search_for_parent(root_element->left_child, child_element) != NULL){
            return search_for_parent(root_element->left_child, child_element);
        }else if (search_for_parent(root_element->right_child, child_element) != NULL){
            return search_for_parent(root_element->right_child, child_element);
        }else{
            return NULL;
        }
    }
}

void delete_element(bin_tree_t *mytree, int myvalue){
    element_t *element_to_delete = get_element(mytree, myvalue);
    if ((element_to_delete->left_child == NULL) && (element_to_delete->right_child == NULL)){
        element_t *parent_element = search_for_parent(mytree->root, element_to_delete);
        if (parent_element->left_child == element_to_delete){
            parent_element->left_child = NULL;
        }
        if (parent_element->right_child == element_to_delete){
            parent_element->right_child = NULL;
        }
        free(element_to_delete);
        mytree->size -= 1;
    }
}

void delete_bintree(bin_tree_t *mytree){
    element_t *root_element = mytree->root;
    for (int i=0; i<mytree->size; i++){
        delete_bintree_element(root_element);
    }
    free(mytree);
}

void delete_bintree_element(element_t *root_element){
    if (root_element->left_child != NULL){
        delete_bintree(root_element->left_child);
    }else if (root_element->right_child != NULL){
        delete_bintree(root_element->right_child);
    }else{
        free(root_element);
    }
}


