#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

template <typename T, int Size>
class CircularQueue {
   private:
    T* array;
    int front;
    int rear;
    int currentSize;

   public:
    CircularQueue() : front(0), rear(0), currentSize(0) { array = new T[Size]; }

    ~CircularQueue() { delete[] array; }

    void enqueue(const T& element) {
        array[front] = element;
        front = (front + 1) % Size;
        currentSize++;
    }

    T dequeue() {
        rear = (rear + 1) % Size;
        currentSize--;
        return array[rear];
    }

    T frontElement() const {

        return array[rear];
    }

    bool isEmpty() const { return currentSize == 0; }

    bool isFull() const { return currentSize == Size; }

    void printQueue() const {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        int i = rear;
        int count = 0;
        while (count < currentSize) {
            std::cout << array[i];
            i = (i + 1) % Size;
            count++;
        }
        std::cout << std::endl;
    }
};

int main() {
    try {
        CircularQueue<int, 5> queueint;

        int element1 = 1;
        int element2 = 2;
        int element3 = 3;
        int element4 = 4;

        queueint.enqueue(element1);
        queueint.enqueue(element2);

        std::cout << "Queue elements: ";
        queueint.printQueue();

        queueint.dequeue();
        std::cout << "Queue elements after dequeue: ";
        queueint.printQueue();
        queueint.enqueue(element3);
        queueint.enqueue(element4);
        std::cout << "Queue elements after additional enqueues: ";
        queueint.printQueue();
        queueint.dequeue(); 

        //std::cout<< dequeue();
        std::cout << "Queue elements after dequeue: ";
        queueint.printQueue();



        CircularQueue<char, 5> queuechar;
        char element5 = 'A';
        char element6 = 'B';
        char element7 = 'C';
        char element8 = 'D';
        queuechar.enqueue(element5);
        queuechar.enqueue(element6);

        std::cout << "Queue elements: ";
        queuechar.printQueue();
        char p = queuechar.dequeue();
        std::cout << p;
        queuechar.dequeue();
        std::cout << "Queue elements after dequeue: ";
        queuechar.printQueue();
        queuechar.enqueue(element7);
        queuechar.enqueue(element8);
        std::cout << "Queue elements after additional enqueues: ";
        queuechar.printQueue();
        queuechar.dequeue(); 
        std::cout << "Queue elements after dequeue: ";
        queuechar.printQueue();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}