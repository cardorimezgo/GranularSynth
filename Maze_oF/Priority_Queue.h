#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>

// MIN-HEAP
class Priority_Queue{

public:

        bool isEmpty() const{
                 return heap.empty();
       }

        //Gets the first element of the tree
        int peek() const{
                if(isEmpty()){
                        throw std::runtime_error("Heap is empty");
                }
                return heap[0];
        }


        //Remove the smallest element from the heap recursively
        int pop(){
                if(isEmpty){
                        throw std::runtime_error("Heap is empty");
                }

                int rootValue = heap[0]; //store the smallest value
                heap[0] = heap.back(); //replace root with last element
                heap.pop_back(); //remove last element of the vector

                heapify_down(0);
                return rootValue;
        }

        //if child larger than parent, push up
        void push(int val){
                heap.push_back(val);
                heapify_up(heap.size -1);
        }

private:
	std::vector<int> heap;

	int parent(int i){
		return i/2;
	}

	int left(int i){
		return 2i;
	}

	int right(int i){
		return 2i + 1;
	}

        // swap if child is larger than parent
	void heapify_up(int i){
		while(i != 0 && heap[parent(i)] > heap[i]){
			std::swap(heap[i] , heap[parent(i)]);
			i = parent(i);
		}
	}

        //Recursively ensure that the value of any given node is less
        //than or equal to the values of its children 
        void heapify_down(int i){
                int l = left(i);
                int r = right(i);
                int smallest = i;

                if(l < heap.size() && heap[l] < heap[i]){
                        smallest = l;
                }
                if(r < heap.size() && heap[r] < smallest){
                        smallest = r;
                }
                if(smallest != i){
                        std::swap(heap[i] , heap[smallest]);
                        heapify_down(smallest);
                }
        }
};

#endif // PRIORITYQUEUE_H
