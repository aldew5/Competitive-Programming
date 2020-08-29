int partition(int A[], int low, int high){
    int pivot = A[high];
    int i = (low -1);

    for (int j = low; j < high; j++){
        if (A[j] < pivot){
            i ++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[high]);
    return (i + 1);
}
ll quicksort(int A[], int low, int high){
    if (low < high){
        int pivot = partition(A, low, high);
        quicksort(A, low, pivot -1);
        quicksort(A, pivot + 1, high);
    }
    return compare;
}
