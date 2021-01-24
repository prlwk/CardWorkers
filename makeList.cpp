#include "makeList.h"
void makeList(Array<Worker>& worker, Array<String>& List)
{
	int counter=0;
	int count;
	Array<String> TIME(worker.GetSize());
	for (int i = 0; i < worker.GetSize(); i++)
	{
		count = 0;
		for (int j = 0; j < i; j++)
		{
			if (worker[i].getPosition() == worker[j].getPosition())
			{
				count++;
				break;
			}
		}
		if (count == 0)
		{
			TIME[counter] = worker[i].getPosition();
			counter++;
		}
	}
	Array<String> TIME1(counter);
	for (int i = 0; i < counter; i++)
		TIME1[i] = TIME[i];
	List = TIME1;
}