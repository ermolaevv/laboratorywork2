#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include "my_module.h"

void initSegment(programInfo* info)
{
	if (info->x != NULL)
		free(info->x);
	if (info->fx != NULL)
		free(info->fx);
	if (info->fprx != NULL)
		free(info->fprx);

	printf("Enter a: ");
	scanf_s("%lf", &info->a);
	printf("Enter b: ");
	scanf_s("%lf", &info->b);
	printf("Enter h: ");
	scanf_s("%lf", &info->h);
	printf("Enter n: ");
	scanf_s("%d", &info->n);

	info->size = (info->b - info->a) / info->h + 1;
	info->x = (double*)malloc(sizeof(double) * info->size);
	info->fx = (double*)malloc(sizeof(double) * info->size);
	info->fprx = (double*)malloc(sizeof(double) * info->size);
}

void print(programInfo * info)
{
	double delta, maxDelta = 0;
	int maxDeltaIndex = 0;
	printf("ind  |\t  Xi\t| my_func(x) |\tfunc(x)\t|   delta\n");
	for (int i = 0; i < info->size; i++)
	{
		delta = info->fprx[i] - info->fx[i];
		printf("%-*i| %-*.5lf | %-*.5lf | %-*.5lf | %-lf\n", 5, i, 8, info->x[i], 10, info->fprx[i], 8, info->fx[i], delta);
		if (fabs(delta) > maxDelta)
		{
			maxDelta = fabs(delta);
			maxDeltaIndex = i;
		}
	}
	printf("Max delta: %lf\n", maxDelta);
	printf("Max delta index: %i\n\n", maxDeltaIndex);
}

void setArrayValues(programInfo * info)
{
	for (int i = 0; i < info->size; i++)
	{
		info->x[i] = info->a + i * info->h;
		info->fprx[i] = info->func1(info->x[i], info->n);
		info->fx[i] = info->func2(info->x[i]);
	}
}