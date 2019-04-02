//
//  hideAndSeek.cpp
//  dfsbfs
//
//  Created by 신예지 on 02/04/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

#define MAX 200000

class Queue {
private:
    int head=0, tail=0;
    int size=0;
    int queue[MAX];
public:
    void put(int v){
        queue[tail++] = v;
        //size++;
        //if(size<tail) tail=0;
    }
    int get() {
        int temp = queue[head++];
        //size--;
        //if(size<head) head=0;
        return temp;
    }
    int empty(){
        return head==tail;
    }
    int getTail() {
        return tail;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    
    int temp=n;
    int tail;
    
    Queue queue;
    queue.put(n);
    
    while(temp!=k){
        temp=queue.get();
        queue.put(temp-1);
        if(temp-1==k){
            break;
        }
        queue.put(temp+1);
        if(temp+1==k){
            break;
        }
        queue.put(temp*2);
        if(temp*2==k){
            break;
        }
    }
    tail = queue.getTail();
    
    int num=0;
    int level=0;
    while( !(tail>=num && tail<num+pow(3,level)) ){
        num+=pow(3,level);
        level++;
    }
    
    cout<<level<<endl;
}
