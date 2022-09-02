#include <iostream>
using namespace std;

int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int tr[10];
int visited[10];
int N = 3, R = 2;


int cnt = 1;

void SWAP(int i, int j)
{
	int t = arr[i];  arr[i] = arr[j]; arr[j] = t;
}

void print_arr1()
{
	printf("[%d] : ", cnt++);
	for (int i = 0; i < R; i++)
		cout << tr[i] << " ";
	cout << endl;
}

void print_arr2()
{
	printf("[%d] : ", cnt++);
	for (int i = 0; i < R; i++)
		cout << arr[i] << " ";
	cout << endl;
}


void perm3(int k)
{
	if (k == R) print_arr1();
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (visited[i]) continue;

			tr[k] = arr[i];
			visited[i] = 1;
			perm3(k + 1);
			visited[i] = 0;
		}
	}
}

void perm2(int k)
{
	if (k == R) print_arr2();
	else
	{
		for (int i = k; i < N; i++)
		{
			SWAP(k, i);
			perm2(k + 1);
			SWAP(k, i);
		}
	}
}


void perm1(int n, int r)
{
	if (r == 0) print_arr1();
	else
	{
		for (int i = n - 1; i >= 0; i--)
		{
			SWAP(i, n - 1);
			tr[r - 1] = arr[n - 1];
			perm1(n - 1, r - 1);
			SWAP(i, n - 1);
		}
	}
}

void perm_i()
{
	for (int x1 = 0; x1 < N; x1++)
		for (int x2 = 0; x2 < N; x2++) if (x2 != x1)
		{
			tr[0] = arr[x1], tr[1] = arr[x2];
			print_arr1();
		}
}

int main()
{
	perm_i();

	printf("=================\n"); cnt = 1;
	perm1(N, R);

	printf("=================\n"); cnt = 1;
	perm2(0);

	printf("=================\n"); cnt = 1;
	perm3(0);

	return 0;
}





