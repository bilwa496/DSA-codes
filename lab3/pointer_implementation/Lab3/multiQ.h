#include <stdio.h>
#include <stdlib.h>
#include "que.h"
struct MultQ
{
 struct Task t;
 int size;
 queue* qnum;// array of size num 
 int mqsize;
};
 typedef struct MultQ MultiQ;
 extern MultiQ* createMQ(int num);
