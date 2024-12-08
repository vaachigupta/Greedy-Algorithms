#include <stdio.h>
#define max 5
#include <stdlib.h>
void merge(float arr[],int p[], int w[], int l, int m, int r)
{
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r - m;
    float L[n1], R[n2];
    int pL[n1], pR[n2];
    int wL[n1], wR[n2];

    for (i = 0; i < n1; i++){
        L[i] = arr[l+i];
        pL[i] = p[l + i];
        wL[i] = w[l + i];
    }

    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
        pR[j] = p[m + 1 + j];
        wR[j] = w[m + 1 + j];
    }

    i=0;
    j=0;
    k=l;

    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            p[k] = pL[i];
            w[k] = wL[i];
            i++;
        }
        else {
            arr[k] = R[j];
            p[k] = pR[j];
            w[k] = wR[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        p[k] = pL[i];
        w[k] = wL[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        p[k] = pR[j];
        w[k] = wR[j];
        j++;
        k++;
    }
}
void mergeSort(float arr[],int p[], int w[], int l, int r)
{
    if (l < r) {
        int m = l + (r-l) / 2;
        mergeSort(arr, p, w, l, m);
        mergeSort(arr, p, w, m + 1, r);
        merge(arr, p, w, l, m, r);
    }
}
int main(){
    int p[max]={30,20,100,90,160};
    int w[max]={5,10,20,30,40};

    int m=60;
    int weight=0;
    float profit=0;
    
    float pw[max];
    for(int i=0; i<max; i++)
    pw[i]=(float)p[i]/w[i];

    int arr_size = sizeof(pw) / sizeof(pw[0]);
    mergeSort(pw, p, w, 0, arr_size - 1);

    for(int i=0; i<max;i++){
        if(m>0 && w[i]<=m){
            m=m-w[i];
            profit=profit+p[i];
            weight=weight+w[i];
        }
        else if(m>0){
        profit=profit+(p[i]*((float)m/w[i]));
        weight += m;
        break;
        }
    }
    printf("Total profit: %.1f\n", profit);
    printf("Total weight: %d\n", weight);
    return 0;

}

