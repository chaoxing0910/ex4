#include<stdio.h> 
void Merge(int a[],int b[], int start, int mid, int end){
    int left = start, right=mid+1, tmp = start;
    while(left<mid+1 && right<end+1){
        if(a[left] > a[right])
            b[tmp++] = a[right++];
        else
            b[tmp++] = a[left++];
    }
    while(left < mid+1)
        b[tmp++] = a[left++];
    while(right < end+1)
        b[tmp++] = a[right++];
    for(left=start; left<=end; left++)
        a[left] = b[left];
}
void MergeSort(int a[], int b[], int start, int end){
    int mid;
    if(start < end){
        mid = start + (end-start) / 2;
        MergeSort(a, b, start, mid);
        MergeSort(a, b, mid+1, end);
        Merge(a, b, start, mid, end);
    }
}
int main(){
	int a[8] = {13, 5, 2, 10, 22, 18, 8, 4};
    int i, b[8];
    MergeSort(a, b, 0, 7);
    for(i=0; i<8; i++)
        printf("%d ", a[i]);
    return 0;
}
