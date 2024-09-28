// Design Circular Deque: https://leetcode.com/problems/design-circular-deque/

class MyCircularDeque {
public:
	vector<int> v;
	int front, back, size, capacity;

    MyCircularDeque(int k) {
		v = vector<int>(k, -1);
		front = 0;
		back = 0;
		size = 0;  // To keep the track of the current number of elements
		capacity = k;
    }
    
    bool insertFront(int value) {
        if(isFull()) {
			return false;
		}

        if(front == 0) {
            front = capacity - 1;
        } else {
            front--;
        }

        // Another way is as follows,
        // front--;
        // front = capacity + front;
        // front %= capacity;

        v[front] = value;

        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) {
            return false;
        }

        v[back] = value;

        if(back == capacity - 1) {
            back = 0;
        } else {
            back++;
        }

        // Another way is as follows,
        // back++;
        // back %= capacity;

        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) {
            return false;
        }

        v[front] = -1;

        if(front == capacity - 1) {
            front = 0;
        } else {
            front++;
        }

        // Another way is as follows,
        // front++;
        // front %= capacity;

        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) {
            return false;
        }

        if(back == 0) {
            back = capacity - 1;
        } else {
            back--;
        }

        v[back] = -1;

        size--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) {
            return -1;
        }

        return v[front];
    }
    
    int getRear() {
        if(isEmpty()) {
            return -1;
        }

        if(back == 0) {
            return v[capacity - 1];
        } else {
            return v[back - 1];
        }
    }
    
    bool isEmpty() {
        return (size == 0);
    }
    
    bool isFull() {
        return (size == capacity);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
