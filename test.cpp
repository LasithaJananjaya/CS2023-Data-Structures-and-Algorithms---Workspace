FUNCTION mergeSort(array, first, last) BEGIN
IF first < last THEN
mid <- INTEGER((first + last) / 2)
mergeSort(array, first, mid)
mergeSort(array, mid + 1, last)
merge(array, first, mid, last)
END FUNCTION