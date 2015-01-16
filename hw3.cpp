#include <iostream>
#include <cstdlib>
using namespace std;
void debug(int *nodes_in, int size_in);

int main(){
    int nodes[100],nodecount;
    
    cout << "To initial the tree , how many nodes you want to input >> ";

    cin >> nodecount;
    
    cout << "Start input nodes... \n";
    

    for (int i = 1; i <= nodecount; ++i){
        cout << "Node "<< i << " >> ";
        cin >> nodes[i];
    }

    debug(nodes,nodecount);

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

