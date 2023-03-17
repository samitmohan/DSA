def heapify(arr, size, i):
    # build max heap
    largest = i
    left = 2 * i
    right = 2 * i + 1
    if (left <= size and arr[largest] < arr[left]):
        largest = left
    if (right <= size and arr[largest] < arr[right]):
        largest = right

    if largest != i: # if largest is not at top of max heap -> make it at top.
        arr[largest], arr[i] = arr[i], arr[largest]
        # call for remaining nodes
        heapify(arr, size, largest)

def heapsort(arr, n):
    size = n
    while size > 1: # while not all elements are sorted
        # swap first and last element of heap
        arr[size], arr[1] = arr[1], arr[size]
        # decrease size by 1 (only care about size - 1 elements now)
        size -= 1
        heapify(arr, size, 1)

def main():
    arr = [5,4,3,2,1]
    heapsort(arr, 5)
    print(arr)

main()