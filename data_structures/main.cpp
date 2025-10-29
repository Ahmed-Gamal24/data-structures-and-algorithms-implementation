#include<iostream>

#include "queue_list_based.h"

int main(){

    clsQueue<int> q;
    q.enqueue(1);
    std::cout << q.hasData();

   

    return 0;
}