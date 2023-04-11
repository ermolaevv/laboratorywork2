#include <stdio.h>
#include <windows.h>
#include <math.h>
#include "my_module.h"

/*

a = 1
b = 2
h = 0.1
n = 10

------------

a = 50
b = 51
h = 0.1
n = 10

*/

int main()
{
	programInfo myInfo;
	int op, op1, loop_flag;

	myInfo.x = NULL;
	myInfo.fx = NULL;
	myInfo.fprx = NULL;

	initSegment(&myInfo);
	system("cls");
	while (1)
	{
		printf("Choose function/operation:\n"
				"1. Exp\n"
				"2. Sin\n"
				"3. Cos\n"
				"4. Ln\n"
				"9. Resize segment\n"
				"0. Exit\n"
		"Enter operation: ");
		scanf_s("%d", &op);

		switch (op)
		{
		case 1:
			system("cls");
			myInfo.func2 = exp;
			loop_flag = 1;
			while (loop_flag)
			{
				printf("Choose a realization of Exp:\n"
						"1. Simple Exp\n"
						"2. Static Exp\n"
						"3. Fast Exp\n"
						"0. To main menu\n"
						"Enter operation: ");
				scanf_s("%d", &op1);
				switch (op1)
				{
				case 1:
					system("cls");
					myInfo.func1 = my_exp;
					break;
				case 2:
					system("cls");
					myInfo.func1 = my_exp2;
					break;
				case 3:
					system("cls");
					myInfo.func1 = fast_exp;
					break;
				case 0:
					system("cls");
					loop_flag = 0;
					break; 
				default:
					system("cls");
					printf("Operation not found!\n\n");
					continue;
				}

				if (loop_flag)
				{
					setArrayValues(&myInfo);
					print(&myInfo);
				}
			}
			break;
		case 2:
			system("cls");
			myInfo.func2 = sin;
			loop_flag = 1;
			while (loop_flag)
			{
				printf("Choose a realization of Sin:\n"
					"1. Sin\n"
					"2. Sin without period\n"
					"0. To main menu\n"
					"Enter operation: ");
				scanf_s("%d", &op1);
				switch (op1)
				{
				case 1:
					system("cls");
					myInfo.func1 = my_sin;
					break;
				case 2:
					system("cls");
					myInfo.func1 = fast_sin;
					break;
				case 0:
					system("cls");
					loop_flag = 0;
					break;
				default:
					system("cls");
					printf("Operation not found!\n\n");
					continue;
				}

				if (loop_flag)
				{
					setArrayValues(&myInfo);
					print(&myInfo);
				}
			}
			break;
		case 3:
			system("cls");
			myInfo.func2 = cos;
			loop_flag = 1;
			while (loop_flag)
			{
				printf("Choose a realization of Cos:\n"
					"1. Cos\n"
					"2. Cos without period\n"
					"0. To main menu\n"
					"Enter operation: ");
				scanf_s("%d", &op1);
				switch (op1)
				{
				case 1:
					system("cls");
					myInfo.func1 = my_cos;
					break;
				case 2:
					system("cls");
					myInfo.func1 = fast_cos;
					break;
				case 0:
					system("cls");
					loop_flag = 0;
					break;
				default:
					system("cls");
					printf("Operation not found!\n\n");
					continue;
				}

				if (loop_flag)
				{
					setArrayValues(&myInfo);
					print(&myInfo);
				}
			}
			break;
		case 4: 
			system("cls");
			myInfo.func2 = log;
			loop_flag = 1;
			while (loop_flag)
			{
				printf("Choose a realization of Ln:\n"
					"1. Ln(1+x), x in (-1;1]\n"
					"2. ln((1+x)/(1-x))\n"
					"0. To main menu\n"
					"Enter operation: ");
				scanf_s("%d", &op1);
				switch (op1)
				{
				case 1:
					system("cls");
					myInfo.func1 = my_ln;
					break;
				case 2:
					system("cls");
					myInfo.func1 = my_ln2;
					break;
				case 0:
					system("cls");
					loop_flag = 0;
					break;
				default:
					system("cls");
					printf("Operation not found!\n\n");
					continue;
				}

				if (loop_flag)
				{
					setArrayValues(&myInfo);
					print(&myInfo);
				}
			}
			break;

		case 9:
			system("cls");
			initSegment(&myInfo);
			break;
		case 0:
			system("cls");
			printf("@Vladislav Ermolaev");
			return 0;
		default:
			system("cls");
			printf("Operation not found!\n\n");
		}

	}

	free(myInfo.x);
	free(myInfo.fx);
	free(myInfo.fprx);
}
