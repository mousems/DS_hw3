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

    int c;
    int quit=1;
    while(quit){
        cout << "Next? (1)Insert (2)Remove (3)Quit >> ";
        cin >> c;
        switch(c){
            case 1:
                
                int tmp;
                cout << "      (1)Insert >> ";
                cin >> tmp;
                nodecount++;
                nodes[nodecount] = tmp;
                do_heapify(nodes, nodecount);
                debug(nodes, nodecount);
                break;

            case 2:
                if (nodecount==0){
                    cout << "      (2)Remove :no more nodes.\n";
                }else{
                    for (int i = 1; i < nodecount; ++i){
                        nodes[i]=nodes[i+1];
                    }
                    nodecount--;
                    do_heapify(nodes, nodecount);
                    debug(nodes, nodecount);
                }
                break;

            case 3:
                quit=0;
                break;
        }
    }
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