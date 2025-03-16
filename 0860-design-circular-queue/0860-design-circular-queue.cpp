class MyCircularQueue {
public:
     int f; // front pointer
    int b; // back pointer
    int c; // capacity
    int s; // size of the queue
    vector<int> arr; // array to store queue elements

    MyCircularQueue(int k) {
        f = 0;
        b = 0;
        c = k;
        s = 0;
        arr = vector<int>(k);
    }
    
    bool enQueue(int value) {
        if (s == c) return false; // Queue is full
        arr[b] = value; // Insert the element at the back
        b = (b + 1) % c; // Update back pointer with wraparound
        s++; // Increase size
        return true;
    }
    
    bool deQueue() {
        if (s == 0) return false; // Queue is empty
        f = (f + 1) % c; // Update front pointer with wraparound
        s--; // Decrease size
        return true;
    }
    
    int Front() {
        if (s == 0) return -1; // Queue is empty
        return arr[f]; // Return the front element
    }
    
    int Rear() {
        if (s == 0) return -1; // Queue is empty
        int rearIndex = (b - 1 + c) % c; // Calculate the rear index considering wraparound
        return arr[rearIndex];
    }
    
    bool isEmpty() {
        return s == 0; // Check if the queue is empty
    }
    
    bool isFull() {
        return s == c; // Check if the queue is full
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */