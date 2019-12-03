typedef struct{
  int id;
  char name[15];
  int scorep[3];
}Record;

/* struct declaration */
typedef struct node *NodePointer;

struct node {
  Record data;
  NodePointer next;
};

/* prototype declaration */
NodePointer insert(Record);
NodePointer finditem(int);
void listprint(void);
NodePointer make_1node(Record, NodePointer);

/* Global Variable head */
NodePointer head;
