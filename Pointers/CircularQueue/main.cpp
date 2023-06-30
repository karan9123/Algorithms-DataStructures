#include "circular_queue.h"

int main()
{
    CircularQueue cq(5);
    cq.enqueue(1);
    cq.print();

    cq.enqueue(2);
    cq.print();

    cq.enqueue(3);
    cq.print();

    cq.enqueue(4);
    cq.print();

    cq.enqueue(5);
    cq.print();

    cq.enqueue(6);
    cq.print();

    cq.dequeue();
    cq.print();

    cq.dequeue();
    cq.print();

    cq.enqueue(6);
    cq.print();

    cq.enqueue(7);
    cq.print();

    cq.enqueue(8);
    cq.print();


    cq.dequeue();
    cq.print();

    cq.dequeue();
    cq.print();

    cq.dequeue();
    cq.print();

    cq.dequeue();
    cq.print();

    cq.dequeue();
    cq.print();

    cq.dequeue();
    cq.print();


    cq.enqueue(8);
    cq.print();

    cq.dequeue();
    cq.print();

    cq.enqueue(9);
    cq.print();

    return 0;
}
