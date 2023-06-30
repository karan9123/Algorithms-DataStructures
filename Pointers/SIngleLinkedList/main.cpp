#include <iostream>
#include "linked_list.h"

int main() {
    LinkedList temp(35);

    temp.insertBegining(30);
    temp.insertBegining(20);
    temp.insertBegining(10);
    temp.insertEnd(40);
    temp.insertEnd(50);
    temp.printList();
    std::cout << std::endl;
    temp.deleteNode(30);
    temp.printList();
    std::cout << std::endl;
    return 0;
}
