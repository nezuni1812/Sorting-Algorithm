#include <iostream>

using namespace std;

void Selection(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) 
            if (a[j] < a[minIndex]) 
                minIndex = j;
        swap(a[i], a[minIndex]);
    }
}

void SelectionComp(int a[], int n, unsigned long long &compare){
    for (int i = 0; ++compare && i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; ++compare && j < n; ++j) 
            if (++compare && a[j] < a[minIndex]) 
                minIndex = j;
        swap(a[i], a[minIndex]);
    }
}

void Insertion(int a[], int n){
    for (int i = 1; i < n; ++i) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void InsertionComp(int a[], int n, unsigned long long &compare){
    for (int i = 1; ++compare && i < n; ++i) {
        int key = a[i];
        int j = i - 1;
        while (++compare && j >= 0 && ++compare && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void Bubble() {

}

void BubbleComp() {

}

void Shaker() {

}

void ShakerComp() {

}

void Shell(int a[], int n) {
    for (int i = n / 2; i > 0; i /= 2) {
        for (int j = i; j < n; j++) {
            int temp = a[j];
            int k;
            for (k = j; k >= i && a[k - i] > temp; k -= i)
                a[k] = a[k - i];
            a[k] = temp;
        }
    }
}

void ShellComp(int a[], int n, unsigned long long &compare) {
    for (int i = n / 2; ++compare && i > 0; i /= 2) {
        for (int j = i; ++compare && j < n; j++) {
            int temp = a[j];
            int k;
            for (k = j; ++compare && k >= i && ++compare && a[k - i] > temp; k -= i)
                a[k] = a[k - i];
            a[k] = temp;
        }
    }
}

void Heap() {

}

void HeapComp() {

}

void Merge() {

}

void MergeComp() {

}

void Quick(int a[], int left, int right) { // Khi gọi hàm, truyền left = 0, right = n - 1
    int pivot = a[(left + right)/2];
    int i = left, j = right;
    while (i < j) {
        while (a[i] < pivot) 
            i++;
        while (a[j] > pivot) 
            j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (left < j) 
        Quick(a, left, j);
    if (i < right) 
        Quick(a, i, right);
}

void QuickComp(int a[], int left, int right, unsigned long long &compare) { //Khi gọi hàm, truyền left = 0, right = n - 1
    int pivot = a[(left + right)/2];
    int i = left, j = right;
    while (++compare && i < j) {
        while (++compare && a[i] < pivot) 
            i++;
        while (++compare && a[j] > pivot) 
            j--;
        if (++compare && i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (++compare && left < j) 
        QuickComp(a, left, j, compare);
    if (++compare && i < right) 
        QuickComp(a, i, right, compare);
}

void Counting(int a[], int n) {
    int maxVal = a[0];
    for (int i = 0; i < n; i++)
        if (maxVal < a[i])
            maxVal = a[i];
            
    int *frequency = new int [maxVal + 1];
    for (int i = 0; i < maxVal + 1; i++)
        frequency[i] = 0;
    
    for (int i = 0; i < n; i++)
        frequency[a[i]]++;
        
    for (int i = 1; i <= maxVal; i++)
        frequency[i] += frequency[i - 1];
        
    int *b = new int [n];
    for (int i = n - 1; i >= 0; i--){
        b[frequency[a[i]] - 1] = a[i];
        frequency[a[i]]--;
    }
    
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}

void RadixLSD(int a[], int n) {
    int maxVal = a[0];
    
    for (int i = 1; i < n; i++)
        if (a[i] > maxVal)
            maxVal = a[i];
            
    int nDigit = 0;
    do {
        nDigit++;
        maxVal/=10;
    }
    while (maxVal != 0);
    
    int **numTable = new int * [10];
    for (int x = 0; x < 10; x++)
        numTable[x] = new int [n];
        
    int expo = 1;
    for (int i = 0; i < nDigit; i++){
        int numCount[10] = {0};
            
        for (int j = 0; j < n; j++){
            int dgt = a[j] / expo % 10;
            
            numTable[dgt][numCount[dgt]++] = a[j];
        }
        
        int index = 0;
        for (int j = 0; j < 10; j++){
            for (int k = 0; k < numCount[j]; k++){
                a[index++] = numTable[j][k];
            }
        }
        
        expo*=10;
    }
    
    for (int i = 0; i < 10; i++)
        delete[] numTable[i];
        
    delete[] numTable;
    
}

void Flash(int a[], int n) {
    int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m; i++)
		l[i] = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[max])
			max = i;
	}
	if (a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];
	swap(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k])
		{
			k = int(c1*(flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	Insertion(a, n);
}