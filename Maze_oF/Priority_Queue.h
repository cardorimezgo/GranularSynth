#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>

// MIN-HEAP
//Root vector at index 1 , null at index 0
class Priority_Queue{
        std::vector<int> heap;

	int parent(int i){
                if(i == 1){
                        return -1;
                }
		return i/2;
	}

	int left(int i){
		return 2 * i;
	}

	int right(int i){
		return 2 * i + 1;
	}

        // swap if child is larger than parent
	void bubble_up(int i){
		while(i != 1 && heap[parent(i)] > heap[i]){
			std::swap(heap[i] , heap[parent(i)]);
			i = parent(i);
		}
	}

        //Recursively ensure that the value of any given node is less
        //than or equal to the values of its children 
        void bubble_down(int i){
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
                        bubble_down(smallest);
                }
        }

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
        int del(){
                if(isEmpty()){
                        throw std::runtime_error("Heap is empty");
                }

                int rootValue = heap[1]; //store the smallest value
                heap[1] = heap.back(); //replace root with last element
                heap.pop_back(); //remove last element of the vector

                bubble_down(0);
                return rootValue;
        }

        //if child larger than parent, push up
        void insert(int val){
                heap.push_back(val);
                bubble_up(heap.size() -1);
        }
	
};

#endif // PRIORITYQUEUE_H
