#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "TestLinkedList.c"
#include "TestArrayList.c"
#include "TestStack.c"
#include "TestComparator.c"
#include "TestIterator.c"
#include "TestHashMap.c"
#include "TestPriorityQueue.c"
#include "TestSet.c"
int main(){


    testLinkedList();
    testArrayList();
    testStack();
    testComparator();
    testIterator();
    testHashMap();
    testPriorityQueue();
    testSet();


return 1;

}


