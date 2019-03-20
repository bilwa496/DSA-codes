#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
 struct Task
 {
 	int priority;
 	int tid;
 };
 
struct Element
{
	struct Task val;
};

struct Node 
{
	struct Element ele;
	struct Node* next;
};
typedef struct Node node;
struct Queue
{
	node* head;
	node* tail;
	int size;
};
typedef struct Queue queue;
extern int lengthQ(queue* q);
extern queue* addQ(queue* q,struct Element e);
extern struct Element front(queue* q);
extern queue* delQ(queue* q);
extern bool isEmpty(queue* q);
extern queue* newQ();


//defined queue.h

