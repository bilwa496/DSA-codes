#include "node.h"
BOOL IsLower_GM(int id1, int id2)
{
	int member1 = id1%10000;
	 id1/=10000;
	int group1 =  id1%1000;
	id1/=1000;
	int member2 = id2%10000;
	 id2/=10000;
	int group2 =  id2%1000;
	id2/=1000;  
	if(group1==group2)
	{
		if(member1<member2)
		{
			return TRUE;
		}
		else
		{
		return FALSE;
		}
	}
	else if (group1<group2)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
		
}
