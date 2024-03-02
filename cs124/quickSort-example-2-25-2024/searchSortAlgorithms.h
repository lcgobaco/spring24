    
// QuickSort 
template <typename T>
void swap(T list[], int first, int second);
template <typename T>
int partition(T list[], int first, int last);
template <typename T>
void recQuickSort(T list[], int first, int last);
template <typename T>
void quickSort(T list[], int length);


template <typename T>
void swap(T list[], int first, int second) {
    T temp;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
} //end swap

template <typename T>
int partition(T list[], int first, int last) {
    T pivot;

    int index, smallIndex;

    swap(list, first, (first + last) / 2);

    pivot = list[first];
    smallIndex = first;

    for (index = first + 1; index <= last; index++)
        if (list[index] < pivot)
        {
            smallIndex++;
            swap(list, smallIndex, index);
        }

    swap(list, first, smallIndex);

    return smallIndex;
} //end partition

template <typename T>
void recQuickSort(T list[], int first, int last) {
    int pivotLocation;

    if (first < last) {
        pivotLocation = partition(list, first, last);
        recQuickSort(list, first, pivotLocation - 1);
        recQuickSort(list, pivotLocation + 1, last);
    }
} //end recQuickSort

template <typename T>
void quickSort(T list[], int length) {
    recQuickSort(list, 0, length - 1);
} //end quickSort





template <typename T>
int partitionMedian(T list[], int first, int last)
{
	T pivot;

	int index, smallIndex;

	swap(list, first, medianLoc(list, first, (first + last) / 2, last));

	pivot = list[first];
	smallIndex = first;

	for (index = first + 1; index <= last; index++)
		if (list[index] < pivot)
		{			
			smallIndex++;
			swap(list, smallIndex, index);
		}

	swap(list, first, smallIndex);

	return smallIndex;
}

template <typename T>
int medianLoc(T list[], int first, int middle, int last)
{
	if ((list[first] <= list[middle] && list[middle] <= list[last]) ||
		(list[first] >= list[middle] && list[middle] >= list[last]))
		return middle;
	else
		if ((list[middle] <= list[first] && list[first] <= list[last]) ||
			(list[middle] >= list[first] && list[first] >= list[last]))
				return first;
		else
			return last;
}

template <typename T>
int seqSearch(const T list[], int length, const T& item)
{
    int loc;
    bool found = false;

    loc = 0;

    while (loc < length && !found)
        if (list[loc] == item)
            found = true;
        else
            loc++;

    if (found)
        return loc;
    else
        return -1;
} //end seqSearch

template <typename T>
int binarySearch(const T list[], int length, 
                 const T& item)
{
    int first = 0;
    int last = length - 1;
    int mid;

    bool found = false;

    while (first <= last && !found)
    {
        mid = (first + last) / 2;

        if (list[mid] == item)
            found = true;
        else if (list[mid] > item)
            last = mid - 1;
        else
            first = mid + 1;
    }

    if (found)
        return mid;
    else 
        return -1;
} //end binarySearch

template <typename T>
void bubbleSort(T list[], int length)
{
    for (int iteration = 1; iteration < length; iteration++)
    {
        for (int index = 0; index < length - iteration;
                            index++)
        {
            if (list[index] > list[index + 1])
            {
                T temp = list[index];
                list[index] = list[index + 1];
                list[index + 1] = temp;
            }
        }
    }
} //end bubbleSort

template <typename T>
void selectionSort(T list[], int length)
{
    int loc, minIndex;

    for (loc = 0; loc < length; loc++)
    {
        minIndex = minLocation(list, loc, length - 1);
        swap(list, loc, minIndex);
    }
} //end selectionSort

template <typename T>
int minLocation(T list[], int first, int last)
{
    int loc, minIndex;

    minIndex = first;

    for (loc = first + 1; loc <= last; loc++)
        if (list[loc] < list[minIndex])
            minIndex = loc;

    return minIndex;
} //end minLocation
