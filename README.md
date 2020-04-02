# C_datastructures
some datastructures for c


Collecting some Datastructures for c programming language.                                                                                
__________________________________________________________                                                                                 
linked list                                                                                                                               
  linkedlist_t *create_emptylist();                                                                                                       
  void append(linkedlist_t *mylist, int myvalue);                                                                                         
  void remove_element(linkedlist_t *mylist, int myindex);                                                                                 
  int get(linkedlist_t *mylist, int myindex);                                                                                             
  void delete_linkedlist(linkedlist_t *mylist);                                                                                           
__________________________________________________________       
double linked list                                                                                                                         
  double_linkedlist_t *create_emptylist();                                                                                                 
  void append(double_linkedlist_t *mylist, int myvalue);                                                                                  
  void remove_element(double_linkedlist_t *mylist, int myindex);                                                                          
  int get(double_linkedlist_t *mylist, int myindex);                                                                                      
  void delete_doublelinkedlist(double_linkedlist_t *mylist);                                                                               
__________________________________________________________
binary tree                                                                                                                             
  bin_tree_t *create_bintree();                                                                                                         
  void add_element(bin_tree_t *mytree, element_t *parent_element, int myvalue);                                                         
  element_t *get_element(bin_tree_t *mytree, int myvalue);                                                                              
  element_t *recursive_search(element_t *myelement, int myvalue);                                                                       
  void delete_element(bin_tree_t *mytree, int myvalue);                                                                                 
  element_t *search_for_parent(element_t *root_element, element_t *child_element);                                                      
  void delete_bintree(bin_tree_t *mytree);                                                                                              
  void delete_bintree_element(element_t *root_element);                                                                                 


