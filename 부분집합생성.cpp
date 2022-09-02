
// �κ� ���� ����, �ݺ�, ���̳ʸ� ī����, ���

#include <iostream>
using namespace std;

int a[21];
int N = 3;
int cnt = 1;

void reset()
{
	cout << "----------------------------" << endl;
	cnt = 1;
}

void Print()
{
	printf("[%d] : {", cnt++);
	for (int i = 1; i <= N; i++)
		if (a[i]) printf(" %d ", i);
	printf("}\n");
}

void power_set_i()
{
	for (int x1 = 0; x1 < 2; x1++)
	{
		a[1] = x1;
		for (int x2 = 0; x2 < 2; x2++)
		{
			a[2] = x2;
			for (int x3 = 0; x3 < 2; x3++)
			{
				a[3] = x3;
				Print();
			}
		}
	}
}

void power_set_b()
{
	for (int i = 0; i < (1 << N); i++)
	{
		printf("[%d] : {", cnt++);

		for (int j = 0; j < N; j++)
			if (i&(1 << j))
				printf(" %d ", j + 1);

		printf("}\n");
	}
}

void power_set_r(int k)
{
	if (k == N) Print();
	else
	{
		k++;
		for(int i=0; i<2; i++){
			a[k]=i;
			power_set_r(k);
		}
//		a[k] = 1; power_set_r(k);
//		a[k] = 0; power_set_r(k);
	}
}


int main()
{
	printf("�κ����� �ݺ���\n");
	power_set_i();
	reset();
	printf("�κ����� ���̳ʸ� ī����\n");
	power_set_b();
	reset();
	printf("�κ����� ��͹�\n");
	power_set_r(0);
	
	return 0;
}



