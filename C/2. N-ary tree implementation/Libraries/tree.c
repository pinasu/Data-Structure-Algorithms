#include "../Headers/tree.h"
#include "../Headers/compare.h"

/*Constant string max length*/
#define STRING_LENGTH 50

/* Function to print a given n-ary tree */
void print_tree(Node tree){
  if(tree == NULL)
    return;

  printf("%s - ", (char*)tree->value);
  Node child = tree->child;
  while(child){
    printf("%s ", (char*)child->value);
    child = child->brother;
  }
  printf("\n");
  child = tree->child;
  while(child){
    print_tree(child);
    child = child->brother;
  }
}

/* Node constructor */
Node new_node(void* value){
  Node tmp = (Node)malloc(sizeof(struct _node));
  tmp->value = value;
  tmp->father = NULL;
  tmp->child = NULL;
  tmp->brother = NULL;
  return tmp;
}

/* Function to get given node child */
Node get_child(Node node){
  return node->child;
}

/* Function to get given node brother */
Node get_brother(Node node){
  return node->brother;
}

/* Function to get max degree of a given tree */
int max_degree(Node node){
  int children = 0, count = 0, max = 0;
  Node child = get_child(node);

  if(child == NULL)
    return 0;

  while(child){
    count = max_degree(child);
    if(count > max)
      max = count;

    child = get_brother(child);
    children++;
  }

  if(children > max)
    max = children;

  return max;
}

/* Function to check if given tree is binary or not */
int is_binary(Node node){
  int children = 0, count = 0;
  Node tmp = get_child(node);

  if(tmp == NULL)
    return 0;

  while(tmp){
    count = is_binary(tmp);
    if(count == -1)
      return -1;
    tmp = get_brother(tmp);
    children++;
  }

  if(children > 2)
    return -1;

  return 0;
}

/* Function to return total number of nodes of given tree */
int num_nodes(Node node){
  int count = 0;
  Node tmp = get_child(node);

  if(node->value != NULL)
    count = count + 1;

  if(tmp == NULL)
    return count;

  while(tmp){
    count += num_nodes(tmp);
    tmp = get_brother(tmp);
  }

  return count;
}

/* Function to return max depth of given tree */
int depth(Node node){
  int count = 0, max = 0;
  Node child = get_child(node);

  if(child == NULL)
    return max;

  while(child){
    count = depth(child)+1;

    if(count > max)
      max = count;

    child = get_brother(child);
  }

  return max;
}

/* Function to return binary tree of given n-ary tree */
Node get_binary(Node node, compare c){
  Ord_Arraylist arraylist = new_ordarraylist(5, c);

  get_array_ord(node, arraylist);

  return get_binary_aux(arraylist, 0, get_ff(arraylist)-1, NULL);
}

/* Function helper to return binary tree of given n-ary tree */
Node get_binary_aux(Ord_Arraylist arraylist, int start, int end, Node father){
  int mid = (start + end)/2;
  Node current = new_node(get_index(arraylist, mid));

  current->father = father;

  if(end==start+1){
      Node dummy = new_node("[dummy]");
      current->child = dummy;
      dummy->father = current;
      dummy->child = NULL;
      dummy->brother = get_binary_aux(arraylist, mid+1, end, current);
  }
  else if(start==end){
      current->child = NULL;
  }
  else{
      current->child = get_binary_aux(arraylist, start, mid-1, current);
      current->child->brother = get_binary_aux(arraylist, mid+1, end, current);
  }

  return current;
}

/* Function to get ordered arraylist of given n-ary tree */
void get_array_ord(Node node, Ord_Arraylist arraylist){
  Node child = get_child(node);

  insert_ordarraylist(node->value, arraylist);

  if(child == NULL)
    return;

  while(child){
    get_array_ord(child, arraylist);
    child = get_brother(child);
  }
}

/* Function to read from file */
void read_file(Node* tree, compare c){
  //Other file is called multywaytree_1.csv
  FILE* fp = fopen("../../../multywaytree_2.csv", "r");
  char ch;
  char tmp[STRING_LENGTH];
  int i = 0;

  while(fscanf(fp, "%c", &ch) > 0){
    if(ch == '\n'){
      tmp[i] = '\0';
      manage_insert(tmp, tree, c);
      i = 0;
    }
    else{
      tmp[i] = ch;
      i++;
    }
  }
  fclose(fp);
}

/* Function to manage tree insert of binary tree */
void manage_insert(char* str, Node* tree, compare c){
  char* token;
  Arraylist family;
    int i;
    char* tmp_str;

    i = 0;
    tmp_str = NULL;
    family = new_arraylist(5);
    token = strtok(str, ",");

    while(token != NULL){
      tmp_str = (char*)malloc(sizeof(char)*20);
      strcpy(tmp_str, token);
    insert_arraylist(tmp_str, family);
    token = strtok(NULL, ",");
    i++;
  }

  insert_nary(tree, (char**)family->array, family->ff, c);

  free_arraylist(family);
}

/* Function to insert family into binary tree */
void insert_nary(Node* ptree, char** family, int len, compare c){
  int i;
  Node iter = NULL, child = NULL, tree = NULL, father = NULL, brother = NULL;

  tree = *ptree;
  i = 0;

  if(tree == NULL){
    father = new_node((void*)family[i]);
    *ptree = father;
  }
  else
    father = find_father(tree, (void*)family[i], c);

  if(father == NULL)
    return;

  i++;
  if(i < len){
    child = new_node((void*)family[i]);
    child->father = father;
  }
  i++;
  iter = child;
  while(i < len){
    brother = new_node(family[i]);
    iter->brother = brother;
    brother->father = father;
    iter = brother;
    i++;
  }
  father->child = child;
}

/* Function to return given node pointer */
Node find_father(Node tree, void* father, compare c){
  Node found = NULL, child = NULL;

  if(tree->value != NULL){
    if(c(tree->value, father) == 0){
      return tree;
    }

    child = get_child(tree);
    while(child != NULL && found == NULL){
      found = find_father(child, father, c);
      child = get_brother(child);
    }
  }

  return found;
}

/* Function to clean given n-ary tree */
void clean(Node root){
  if(root != NULL){
    Node child = root->child;
    while(child){
      clean(child);
      child = get_brother(child);
    }
    root->father = NULL;
    root->child = NULL;
    root->brother = NULL;
    free(root);
  }
}
