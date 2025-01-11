class MyCircularQueue {
    private:
    int *queue;
    int front, rear, size, capacity;
public:
    MyCircularQueue(int k) {
        capacity = k;
        queue = new int[k];
        front = rear = -1;
    }

    
    bool enQueue(int value) {
        if((rear+1)%capacity==front)
      {
        cout<<"queue is full";
        return false;
      }
      if(front==-1&&rear==-1)
      {
        front=rear=0;
      }  
      else 
      {
        rear=(rear+1)% capacity ;
      }
       queue[rear]=value;
      return true;
        }
    
    bool deQueue() {
        if(front==-1&&rear==-1)
        {
            cout<<"queue is empty";
            return false;
        }
        else if(front==rear)
        {
            front=rear=-1;
        }
        else 
        {
            front=(front+1)% capacity ;
        } 
        return true;  
    }
    int Front() {
        if (front == -1) {  // Queue is empty
            cout << "Queue is empty" << endl;
            return -1;
        }
        else {
             return queue[front];
    }
    }
    
    int Rear() {
           if (rear == -1) {  // Queue is empty
            cout << "Queue is empty" << endl;
            return -1;
        }
        return queue[rear];
        }
    
    bool isEmpty() {
     return front == -1;
    }
    
    bool isFull() {
       return (rear + 1) % capacity == front;
    }
     ~MyCircularQueue() {
        delete[] queue; // Free dynamically allocated memory
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