// Quicksort Algorithm, contains a version taking a function pointer
// to sort by and one without

// Swap two indices in the array
void swap(size_t i, size_t j, size_t arr[]) {
  size_t h = arr[i];
  arr[i] = arr[j];
  arr[j] = h;
}

// Partition for sorting algorithm
size_t partition(size_t length, size_t * arr, size_t (*g)(size_t)){
  size_t lft  = 0,
         pivot = arr[0],
         rght = length;

  while (lft < rght) {

    // Continue until rght or pivot is found
    while ( (lft < rght) && ((*g)(arr[lft]) <= (*g)(pivot)) ) {
      ++lft;
    }

    // Continue until lft or pivot is found
    while ( (lft < rght) && ((*g)(pivot) < (*g)(arr[rght - 1])) ) {
      --rght;
    }

    // Swap the indices
    if (lft < rght) {
      swap(lft++,--rght,arr);
    }
  }

  // Final output
  --lft;
  arr[0] = arr[lft];
  arr[lft] = pivot;

  return lft;
}

// Quicksort array of given length, has option to sort for
// a function
void quickSort(size_t length, size_t *arr, size_t (*g)(size_t)){
  if (length < 2)
    return;
  size_t boundary = partition(length, arr,(*g));
  quickSort(boundary, arr, (*g));
  quickSort(length - boundary - 1, &arr[boundary+1], (*g));
}

// Partition for sorting algorithm
size_t partition(size_t length, size_t * arr){
  size_t lft  = 0,
         pivot = arr[0],
         rght = length;

  while (lft < rght) {

    // Continue until rght or pivot is found
    while ( (lft < rght) && ((arr[lft]) <= (pivot)) ) {
      ++lft;
    }

    // Continue until lft or pivot is found
    while ( (lft < rght) && ((pivot) < (arr[rght - 1])) ) {
      --rght;
    }

    // Swap the indices
    if (lft < rght) {
      swap(lft++,--rght,arr);
    }
  }

  // Final output
  --lft;
  arr[0] = arr[lft];
  arr[lft] = pivot;

  return lft;
}

// Quicksort array of given length, has option to sort for
// a function
void quickSort(size_t length, size_t *arr){
  if (length < 2)
    return;

  size_t boundary = partition(length, arr);
  quickSort(boundary, arr);
  quickSort(length - boundary - 1, &arr[boundary+1]);
}

