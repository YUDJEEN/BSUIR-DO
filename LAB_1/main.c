#include <stdio.h>


typedef struct {											// ������ ��������
	char name[16];											// �������� ������
	float cost;												// ���� ������
	char seller[16];										// ��� ��������
} store;

store Jewelery[256];										// ��������� ������
store sortingTempList;										// ��������������� ������ ��� ����������

void sale(int positions) {									// ������� ������ ������
	for (int i = 0; i < positions; i++) {					// ���� ����������� �������� ���������� ���
		printf("\n==================================== SALES ====================================\n");

		printf("\nSold jewelery name: ");
		scanf("%s", Jewelery[i].name);						// ����������� ��� ���������� ������

		printf("\nPrice of %s: ", &Jewelery[i].name);
		scanf("%f", &Jewelery[i].cost);						// ����������� ���� ���������� ������

		printf("\nSeller: ");
		scanf("%s", Jewelery[i].seller);					// ����������� ��� ��������

		printf("\n===============================================================================\n");
	}
}

void bubbleSort(int size) {									// ����������� ����������
	for (int i = 0; i < size - 1; i++)						// ���� ������ ������� > ������� �������� = ������ �� ������� etc...
	{
		for (int j = (size - 1); j > i; j--)
		{
			if (Jewelery[j - 1].cost > Jewelery[j].cost)	// ���� ������� ������� ������ ��������
			{
				sortingTempList = Jewelery[j - 1];			// ������ �� �������
				Jewelery[j - 1] = Jewelery[j];				// ...
				Jewelery[j] = sortingTempList;				// ...
			}
		}
	}
}

void displaySales(int positions) {							// ����� ������
	printf("\n==================================== TOTAL ====================================\n");
	for (int i = 0; i < positions; i++) {
		printf("\n Product name \t %s \n Product cost: \t %.1f EUR\n Seller: \t %s\n", Jewelery[i].name, Jewelery[i].cost, Jewelery[i].seller);
	}
	printf("\n===============================================================================\n");
}

int main(void) {
	printf("How much positions selled?: ");
	int positions;
	scanf("%d", &positions);
	sale(positions);

	bubbleSort(positions);

	displaySales(positions);

	return 0;
}