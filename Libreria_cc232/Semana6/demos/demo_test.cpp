#include<iostream>

//demo para contar las operaciones de percolateDown
#include "Capitulo6.h"
int main(){
    std::vector<int> base {32, 12, 72, 30, 31, 25, 84, 66 };
    ods::PQ_ComplHeap<int> pq(base);
    std::cout<<"PQComplHeap construido con heapify de Floyd\n";
    std::cout<<"getMax() = "<<pq.getMax()<<"\n\n";
    int cont=0;
    for(int x: {40, 10, 70, 30, 90, 20, 80, 60 }){
        pq.insert(x);
        std::cout<<"insert("<<x<<")\n";
        std::cout<<"max actual = "<<pq.getMax()<<"\n\n";
    }
    while(!pq.empty()){
        int y=pq.delMax();
        std::cout<<"delMax() -> "<<y<<"\n";
    }

    return 0;
}
