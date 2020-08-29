void insertionSort(int a[], int n)  {
    int i, key, j;
    // loop through the array
    for (i = 1; i < n; i++) {
        // save the element
        key = a[i];

        // loop through the previous indices
        j = i - 1;
        // go through the list until you reach the first
        // element or you reach a smaller element
        while (j >= 0 && a[j] > key) {
            // push the elements over
            a[j + 1] = a[j];

            j --;
        }
        // insert the new element
        a[j + 1] = key;
    }
}
