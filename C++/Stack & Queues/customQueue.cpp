#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

class CustomQueue
{
public:
	int defaultSize = 10;
	int *arr;
	int front;
	int rear;
	int size;

	// Constructor
	CustomQueue()
	{
		// intialise
		arr = new int[defaultSize];
		size = 0;
		front = 0;
		// rear = -1 (because rear + 1 = 0 (initially and it will insert element from 0.))
		rear = -1;
	}

	int *resize()
	{
		int *new_arr = new int[defaultSize * 2];
		for (int i = 0; i < defaultSize; i++)
		{
			new_arr[i] = arr[front % defaultSize];
			front++;
		}
		front = 0;
		rear = size - 1;
		defaultSize = defaultSize * 2;
		return new_arr;
	}

	// Insert
	void push(int data)
	{
		if (size == defaultSize)
		{
			// its full, resize
			arr = resize();
		}
		// else push
		size++;
		// for better memory usage.
		rear = (rear + 1) % defaultSize;
		// now insert data in rear.
		arr[rear] = data;
	}

	// Empty
	bool isEmpty()
	{
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// Remove
	void pop()
	{
		// case -> empty
		if (isEmpty())
		{
			cout << "Queue is empty!" << endl;
			return;
		}
		// else remove from front
		size--;
		// incrememnt front
		front = (front + 1) % defaultSize;
	}

	// Display front
	int Front()
	{
		if (isEmpty())
		{
			// no element
			cout << "Queue is empty" << endl;
			return EXIT_FAILURE;
			// return ;
		}
		// else
		return arr[front];
	}

	// Display rear
	int Rear()
	{
		if (isEmpty())
		{
			// no element
			cout << "Queue is empty" << endl;
			return EXIT_FAILURE;
			// return ;
		}
		// else
		return arr[rear];
	}

	int Size()
	{
		return rear + 1;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	CustomQueue q1;
	q1.push(10);
	q1.push(20);
	q1.push(30);
	q1.push(40);
	q1.push(50);
	cout << q1.Front() << "\n";
	q1.pop();
	cout << q1.Front() << "\n";
	cout << q1.Rear() << "\n";
	cout << q1.size << "\n";

	cout << q1.isEmpty() << endl;

	return 0;
}
