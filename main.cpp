#include "LinkedList.h"

using namespace std;

void testLinkedList(){
    LinkedList<int> linkedList = LinkedList<int>();
    cout << "Insert at beginning 12 and 24" << endl;
    linkedList.insertAtBeginning(12);
    linkedList.insertAtBeginning(24);
    linkedList.print();
    cout << "Insert at beginning 13 and insert at end 15 and 16" << endl;
    linkedList.insertAtBeginning(13);
    linkedList.insertAtEnd(15);
    linkedList.insertAtEnd(16);
    linkedList.print();
    cout << "Insert 35 and 60 to positions 5 and 3" << endl;
    linkedList.insertAt(35, 5);
    linkedList.insertAt(60, 3);
    linkedList.print();
    cout << "Remove at 6 position" << endl;
    linkedList.removeAt(6);
    linkedList.print();
    cout << "Remove last element" << endl;
    linkedList.removeLast();
    linkedList.print();
    cout << "Insert values: 1, 2, 3, 4, 5" << endl;
    int r[] = {1,2,3,4,5};
    linkedList.insertValues(r, 5);
    linkedList.print();
    cout << "Swap 3 and 6 positions" << endl;
    linkedList.swapPlaces(3, 6);
    linkedList.print();
    cout << "Reversed List" << endl;
    linkedList.reverse();
    linkedList.print();
}

int main(){
    testLinkedList();
    return 0;
}