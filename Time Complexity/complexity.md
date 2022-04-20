Time Complexity Notes.
Function that gives us relationship of how time will grow as input grows.

O Notation -> Asymptotic Upper Bound  (Mostly used)
Omega Notation -> Asymptotic Lower Bound
Theta Notation -> Asymptotic Tight Bound (In between)

To find -> keep a counter = 0, increment the counter after every loop and sum the counter
for (int i = 0; i < N; i /= 2) = N + N / 2 + N / 4 + N / 8 + .... = O(N)

# Problems
https://www.interviewbit.com/courses/programming/topics/time-complexity/

# Videos

https://www.youtube.com/watch?v=fZc3ijGM0aM&list=PLMCXHnjXnTnszR6YSo1tQK2BMr15cC9Zh&index=1&ab_channel=GauravSen

https://www.youtube.com/watch?v=Xe9aq1WLpjU&list=PLMCXHnjXnTnszR6YSo1tQK2BMr15cC9Zh&index=2&ab_channel=GauravSen

https://www.youtube.com/watch?v=MTl8djZFWE0&list=PLMCXHnjXnTnszR6YSo1tQK2BMr15cC9Zh&index=7&ab_channel=GauravSen

https://www.youtube.com/watch?v=-3Lt-EwR_Hw&list=PLMCXHnjXnTnuX59JRYLwyr6IFkuqTr0oa&index=9&ab_channel=GauravSen

https://www.youtube.com/watch?v=mV3wrLBbuuE&t=2s&ab_channel=KunalKushwaha

# Complexity in standard languages

C’s qsort() – Quicksort
    Best Case Time Complexity- O(NlogN)
    Average Case Time Complexity- O(NlogN)
    Worse Case Time Complexity- O(N2)
    Auxiliary Space- O(log N)
    Stable- Depends on the implementation of the comparator function
    Adaptive- No

C++’s sort() – Introsort (Hybrid of Quicksort, Heap Sort and Insertion Sort)
    Best Case Time Complexity- O(NlogN)
    Average Case Time Complexity- O(NlogN)
    Worse Case Time Complexity- O(NlogN)
    Auxiliary Space- O(logN)
    Stable- No
    Adaptive- No

C++’s stable_sort() – Mergesort
    Best Case Time Complexity- O(NlogN)
    Average Case Time Complexity- O(NlogN)
    Worse Case Time Complexity- O(NlogN)
    Auxiliary Space- O(N)
    Stable- Yes
    Adaptive- Yes

Java 6’s Arrays.sort() – Quicksort
    Best Case Time Complexity- O(NlogN)
    Average Case Time Complexity- O(NlogN)
    Worse Case Time Complexity- O(N2)
    Auxiliary Space- O(logN)
    Stable- Depends
    Adaptive- No

Java 7’s Arrays.sort() – Timsort (Hybrid of Mergesort and Insertion Sort)
    Best Case Time Complexity- O(N)
    Average Case Time Complexity- O(NlogN)
    Worse Case Time Complexity- O(NlogN)
    Auxiliary Space- O(N)
    Stable- Yes
    Adaptive- Yes

Java’s Collections.sort() – Mergesort
    Best Case Time Complexity- O(NlogN)
    Average Case Time Complexity- O(NlogN)
    Worse Case Time Complexity- O(NlogN)
    Auxiliary Space- O(N)
    Stable- Yes
    Adaptive- Yes

Python’s sorted() – Timsort (Hybrid of Mergesort and Insertion Sort)
    Best Case Time Complexity- O(N)
    Average Case Time Complexity- O(NlogN)
    Worse Case Time Complexity- O(NlogN)
    Auxiliary Space- O(N)
    Stable- Yes
    Adaptive- Yes

Python’s sort() – Timsort (Hybrid of Mergesort and Insertion Sort)
    Best Case Time Complexity- O(N)
    Average Case Time Complexity- O(NlogN)
    Worse Case Time Complexity- O(NlogN)
    Auxiliary Space- O(N)
    Stable- Yes
    Adaptive- Yes
