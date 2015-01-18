#include <iostream>
#include <cstdlib>
using namespace std;

void debug(int *nodes_in, int size_in);
void heapify(int *tree, int i, int size_in);
void do_heapify(int *tree, int size_in);

int main(){
    int nodes[100],nodecount;
    
    cout << "To initial the tree , how many nodes you want to input >> ";

    cin >> nodecount;
    
    cout << "Start input nodes... \n";
    

    for (int i = 1; i <= nodecount; ++i){
        cout << "Node "<< i << " >> ";
        cin >> nodes[i];
    }
    do_heapify(nodes, nodecount);
    debug(nodes, nodecount);

    // while(1){
        
    // }
    return 0;
}



void debug(int *nodes_in, int size_in){
    if (size_in>0){
        cout << "Tree:" << nodes_in[1];
        for (int i = 2; i <= size_in; ++i){
            cout << ", " << nodes_in[i] ;
        }
        cout << " \n\n";
    }
}

void heapify(int *tree, int i, int size_in){
    int largest;
    int left = 2*i;
    int right = left+1;

    if(left <= size_in && tree[left]>tree[i]){
        largest = left;
    }else{
        largest = i;
    }

    if(right <= size_in && tree[right]>tree[largest]){
        largest = right;
    }

    if(largest != i){
        int tmp = tree[i];
        tree[i] = tree[largest];
        tree[largest] = tmp;
        heapify(tree, largest, size_in);
    }
}

void do_heapify(int *tree, int size_in){
    for(int i = size_in/2; i>0; --i){
        heapify(tree, i, size_in);
    }
}//buildTree