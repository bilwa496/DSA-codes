		while(temp != NULL)
		{
			node* temp1 = temp;
			node* prev1;
			if(prev->child==NULL)
			{
			
			}

			while(strcmp(temp1->value,x[level-1]) != 0 && temp1 != NULL)
			{
				prev1 = temp1;
				temp1 = temp1->sibling;
			}
			//match found at the level
			if (strcmp(temp1->value,x[level-1]) == 0)
			{
				level++;
				prev = temp1; 
				temp = temp1->child;
				temp1 = temp;
				prev1 = temp1;
				continue;
			}
			//no match found yet insert a new node
			if (temp1==NULL && strcmp(prev1->value,x[level-1]) != 0)
			{
					node* newnode = malloc(sizeof(node));
					temp->value = (char*)(malloc(sizeof(char)*strlen(x[level-1])));
					strcpy(temp1->value,x[level-1]);
					newnode->sibling = NULL;
					newnode->child = NULL;
					prev->sibling = newnode;
					level++;
					temp1 = newnode;
					prev = temp1;
					temp = temp1->child;
					continue;	
			}
