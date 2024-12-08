#include <stdio.h>
#define max 5
#include <stdlib.h>

/*
void merge(int p[],int id[], int d[], int l, int m, int r)
{
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r - m;
    int pL[n1], pR[n2];
    int dL[n1], dR[n2];
    int L[n1], R[n2];

    for (i = 0; i < n1; i++){
        pL[i] = p[l + i];
        dL[i] = d[l + i];
        L[i] = id[l+i]; 
    }

    for (j = 0; j < n2; j++){
        pR[j] = p[m + 1 + j];
        dR[j] = d[m + 1 + j];
        R[j] = id[m + 1 + j];    
    }

    i=0;
    j=0;
    k=l;

    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) { 
            p[k] = pL[i];
            d[k] = dL[i];
            id[k] = L[i];  
            i++;
        }
        else {    
            p[k] = pR[j];
            d[k] = dR[j];
            id[k] = R[j];    
            j++;
        }
        k++;
    }

    while (i < n1) {    
        p[k] = pL[i];
        d[k] = dL[i];
        id[k] = L[i];     
        i++;
        k++;
    }

    while (j < n2) { 
        p[k] = pR[j];
        d[k] = dR[j];
        id[k] = R[j];
        j++;
        k++;
    }
}*/
void merge(int p[], int id[], int d[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int pL[n1], pR[n2];
    int dL[n1], dR[n2];
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        pL[i] = p[l + i];
        dL[i] = d[l + i];
        L[i] = id[l + i];
    }

    for (j = 0; j < n2; j++) {
        pR[j] = p[m + 1 + j];
        dR[j] = d[m + 1 + j];
        R[j] = id[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (pL[i] > pR[j] || (pL[i] == pR[j] && dL[i] <= dR[j])) {
            p[k] = pL[i];
            d[k] = dL[i];
            id[k] = L[i];
            i++;
        }
        else {
            p[k] = pR[j];
            d[k] = dR[j];
            id[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        p[k] = pL[i];
        d[k] = dL[i];
        id[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        p[k] = pR[j];
        d[k] = dR[j];
        id[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int p[],int d[], int id[], int l, int r)
{
    if (l < r) {
        int m = l + (r-l) / 2;
        mergeSort(p, d, id, l, m);
        mergeSort(p, d, id, m + 1, r);
        merge(p, d, id, l, m, r);
    }
}

int main(){
    int id[] = {1, 2, 3, 4, 5};
    int p[max]={20,60,40,100,80};
    int d[max]={2,2,1,3,4};

    mergeSort(p, d, id, 0, max - 1);
    printf("\nSorted Array: ");
    for(int i=0;i<max;i++)
        printf("%d ",p[i]);

    int slot_count[max];
    int job_id[max];
    for (int i = 0; i < max; i++) {
        slot_count[i] = 0;
        job_id[i] = -1;
    }

    int totalProfit = 0;
    printf("\nJob Sequence: ");

    for (int i = 0; i < max; i++) {
        for (int j = d[i]; j >= 1; j--) {
            if (slot_count[j - 1] == 0) {
                slot_count[j - 1] = 1;
                job_id[j - 1] = id[i];
                totalProfit += p[i];
                break;
            } else {
                if (p[i] > p[job_id[j - 1] - 1]) {
                    totalProfit -= p[job_id[j - 1] - 1];
                    totalProfit += p[i];
                    job_id[j - 1] = id[i];
                }
            }
        }
    }

    for (int i = 0; i < max; i++) {
        if (job_id[i] != -1) {
            printf("%d ", job_id[i]);
        }
    }

    printf("\nTotal Profit: %d\n", totalProfit);

    return 0;
}