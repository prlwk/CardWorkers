#include "oldestWorker.h"
#include <iostream>
#include "Worker.h"
#include "Array.h"
Worker oldestWorker(Array<Worker>& array, const int count)
{
	Worker old = array[0];
	for (int i = 0; i < count; i++)
	{
		if (array[i] > old)
		{
			old = array[i];
		}
	}
	return old;
}