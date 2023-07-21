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

void SelectionComp(int a[], int n, unsigned long long &compare) {
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

void Bubble(int a[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void BubbleComp(int a[], int n, unsigned long long &compare) {
    int i, j;
    for (i = 0; ++compare && i < n - 1; i++) {
        for (j = 0; ++compare && j < n - i - 1; j++) {
            if (++compare && a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void Shaker(int a[], int n) {
    int left = 0, right = n - 1, swapped = 1;
    while (left < right && swapped) {
        swapped = 0;
        for (int i = left; i < right; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = 1;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                swapped = 1;
            }
        }
        left++;
    }
}

void ShakerComp(int a[], int n, unsigned long long &compare) {
    int left = 0, right = n - 1, swapped = 1;
    while (++compare && left < right && swapped) {
        swapped = 0;
        for (int i = left; ++compare && i < right; i++) {
            if (++compare && a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = 1;
            }
        }
        right--;
        for (int i = right; ++compare && i > left; i--) {
            if (++compare && a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                swapped = 1;
            }
        }
        left++;
    }
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
    for (int i = n / 2; ++compare && (i > 0); i /= 2) {
        for (int j = i; ++compare && (j < n); j++) {
            int temp = a[j];
            int k;
            for (k = j; (++compare && (k >= i)) && (++compare && (a[k - i] > temp)); k -= i)
                a[k] = a[k - i];
            a[k] = temp;
        }
    }
}

void heapify(int a[], int n, int i) {
    int largest = i;  
    int l = 2 * i + 1;  
    int r = 2 * i + 2; 
 
    if (l < n && a[l] > a[largest])
        largest = l;
 
    if (r < n && a[r] > a[largest])
        largest = r;
 
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void Heap(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
 
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

<<<<<<< Updated upstream
void heapifyComp(int a[], int n, int i, unsigned long long &compare) {
    int largest = i;  
    int l = 2 * i + 1;  
    int r = 2 * i + 2; 
 
    if (++compare && l < n && ++compare && a[l] > a[largest])
        largest = l;
    if (++compare && r < n && ++compare && a[r] > a[largest])
        largest = r;
 
    if (++compare && largest != i) {
        swap(a[i], a[largest]);
        heapifyComp(a, n, largest, compare);
    }
}

void HeapComp(int a[], int n, unsigned long long &compare) {
    for (int i = n / 2 - 1; ++compare && i >= 0; i--)
        heapifyComp(a, n, i, compare);
 
    for (int i = n - 1; ++compare && i > 0; i--) {
        swap(a[0], a[i]);
        heapifyComp(a, i, 0, compare);
    }
}

void merging(int a[], int left, int mid, int right) {
    int nLeft = mid - left + 1; //Số phần tử mảng trái
    int nRight = right - (mid + 1) + 1; //Số phần tử mảng phải
    int index = left; //index của array

    int *leftArr = new int [nLeft];
    int *rightArr = new int [nRight];

    for (int i = 0; i < nLeft; i++)
        leftArr[i] = a[left + i];
    for (int j = 0; j < nRight; j++)
        rightArr[j] = a[mid + 1 + j];

    int i = 0; 
    int j = 0;

    while (i < nLeft && j < nRight) {
        if (leftArr[i] <= rightArr[j])
            a[index++] = leftArr[i++];
        else
            a[index++] = rightArr[j++];
    }

    while (i < nLeft)
        a[index++] = leftArr[i++];

    while (j < nRight) 
        a[index++] = rightArr[j++];

    delete[] leftArr;
    delete[] rightArr;
}

void Merge(int a[], int left, int right) { // Khi gọi hàm, truyền left = 0, right = n - 1
    if (left >= right) 
        return; 

    int mid = left + (right - left)/2;
    Merge(a, left, mid);
    Merge(a, mid + 1, right); 
    merging(a, left, mid, right); 
}

void mergingComp(int a[], int left, int mid, int right, unsigned long long &compare) {
    int nLeft = mid - left + 1; //Số phần tử mảng trái
    int nRight = right - (mid + 1) + 1; //Số phần tử mảng phải
    int index = left; //index của array

    int *leftArr = new int [nLeft];
    int *rightArr = new int [nRight];

    for (int i = 0; ++compare && (i < nLeft); i++)
        leftArr[i] = a[left + i];
    for (int j = 0; ++compare && (j < nRight); j++)
        rightArr[j] = a[mid + 1 + j];

    int i = 0; 
    int j = 0;

    while ((++compare && (i < nLeft)) && (++compare && (j < nRight))) {
        if (++compare && (leftArr[i] <= rightArr[j]))
            a[index++] = leftArr[i++];
        else
            a[index++] = rightArr[j++];
    }

    while (++compare && (i < nLeft))
        a[index++] = leftArr[i++];

    while (++compare && (j < nRight))
        a[index++] = rightArr[j++];

    delete[] leftArr;
    delete[] rightArr;
}

void MergeComp(int a[], int left, int right, unsigned long long &compare) { // Khi gọi hàm, truyền left = 0, right = n - 1
    if (++compare && (left >= right)) 
        return; 

    int mid = left + (right - left)/2;
    MergeComp(a, left, mid, compare);
    MergeComp(a, mid + 1, right, compare); 
    mergingComp(a, left, mid, right, compare); 
}

void Quick(int a[], int left, int right) { // Khi gọi hàm, truyền left = 0, right = n - 1
    int pivot = a[(left + right)/2];
    int i = left, j = right;
    while (i < j) {
        while (a[i] < pivot) 
            i++;
        while (a[j] > pivot) 
            j--;
        if (i <= j)
            swap(a[i++], a[j--]);
    }
    if (left < j) 
        Quick(a, left, j);
    if (i < right) 
        Quick(a, i, right);
}

void QuickComp(int a[], int left, int right, unsigned long long &compare) { //Khi gọi hàm, truyền left = 0, right = n - 1
    int pivot = a[(left + right)/2];
    int i = left, j = right;
    while (++compare && (i < j)) {
        while (++compare && (a[i] < pivot))
            i++;
        while (++compare && (a[j] > pivot))
            j--;
        if (++compare && (i <= j))
            swap(a[i++], a[j--]);
    }
    if (++compare && (left < j)) 
        QuickComp(a, left, j, compare);
    if (++compare && (i < right)) 
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

void CountingComp(int a[], int n, unsigned long long &comp) {
    int maxVal = a[0];
    for (int i = 0; ++comp && i < n; i++)
        if (maxVal < a[i])
            maxVal = a[i];
            
    int *frequency = new int [maxVal + 1];
    for (int i = 0; ++comp && i < maxVal + 1; i++)
        frequency[i] = 0;
    
    for (int i = 0; ++comp && i < n; i++)
        frequency[a[i]]++;
        
    for (int i = 1; ++comp && i <= maxVal; i++)
        frequency[i] += frequency[i - 1];
        
    int *b = new int [n];
    for (int i = n - 1; ++comp && i >= 0; i--){
        b[frequency[a[i]] - 1] = a[i];
        frequency[a[i]]--;
    }
    
    for (int i = 0; ++comp && i < n; i++)
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

void RadixLSDComp(int a[], int n, unsigned long long &comp) {
    int maxVal = a[0];
    
    for (int i = 1; ++comp && i < n; i++)
        if (a[i] > maxVal)
            maxVal = a[i];
            
    int nDigit = 0;
    do {
        nDigit++;
        maxVal/=10;
    }
    while (++comp && maxVal != 0);
    
    int **numTable = new int * [10];
    for (int x = 0; ++comp && x < 10; x++)
        numTable[x] = new int [n];
        
    int expo = 1;
    for (int i = 0; ++comp && i < nDigit; i++){
        int numCount[10] = {0};
            
        for (int j = 0; ++comp && j < n; j++){
            int dgt = a[j] / expo % 10;
            
            numTable[dgt][numCount[dgt]++] = a[j];
        }
        
        int index = 0;
        for (int j = 0; ++comp && j < 10; j++){
            for (int k = 0; ++comp && k < numCount[j]; k++){
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

void FlashComp(int a[], int n, unsigned long long &comp) {
    int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; ++comp && i < m; i++)
		l[i] = 0;
	for (int i = 1; ++comp && i < n; i++)
	{
		if (++comp && a[i] < minVal)
			minVal = a[i];
		if (++comp && a[i] > a[max])
			max = i;
	}
	if (a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; ++comp && i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; ++comp && i < m; i++)
		l[i] += l[i - 1];
	swap(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (++comp && nmove < n - 1)
	{
		while (++comp && j > l[k] - 1)
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}
		flash = a[j];
		if (++comp && k < 0) break;
		while (++comp && j != l[k])
		{
			k = int(c1*(flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	InsertionComp(a, n, comp);
}