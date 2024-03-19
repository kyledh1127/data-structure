#include <iostream>
#include <string>
using namespace std;

struct node {
    int data;
    node* next;
};


class singlelinkedlist {
private:
    node* head;
    node* tail;
public:
    singlelinkedlist() {
        head = NULL;
        tail = NULL;
    }


    void append(int data) {
        node* newNode = new node;
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void print() {
        node* curNode = head;
        while (curNode != NULL) {
            cout << curNode->data << " ";
            curNode = curNode->next;
        }
        cout << endl;
    }

    void insertion(int e, int v) {
        node* curNode = head;
        node* preNode = NULL;
        while ( curNode->data != e) {
            preNode = curNode;
            curNode = curNode->next;
        }
        node* newNode = new node;
        newNode->data = v;
   
        if (preNode != NULL) {
           
            preNode->next = newNode;
            newNode->next = curNode;
        }
        else {

            newNode->next = head;
            head = newNode;
        }
    }

    void sum(singlelinkedlist& ll, singlelinkedlist& ll2) {
        ll.tail->next = ll2.head;
        tail = ll2.head;
        print();
    }
    //void deletion() {
    //    node* curNode = head;
    //    while (curNode != NULL) {
    //        node* preNode = curNode->next;
    //        delete curNode;
    //        curNode = preNode;
    //    }
    //    head = NULL;
    //    tail = NULL;
    //}

};



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int M;
    cin >> M;

    for (int i = 0; i < M; ++i) {
        int N1, N2;
        cin >> N1;

        singlelinkedlist ll;
        for (int j = 0; j < N1; ++j) {
            int X1;
            cin >> X1;
            ll.append(X1);
        }

        cin >> N2;

        singlelinkedlist ll2;
        for (int j = 0; j < N2; ++j) {
            int X2;
            cin >> X2;
            ll2.append(X2);
        }

        ll.sum(ll,ll2);

        int e, v;
        cin >> e >> v;
        ll.insertion(e, v);
        ll.print();
        // 테스트 케이스마다 생성된 링크드 리스트는 이 시점에서 자동으로 소멸됩니다.
    }

    return 0;
}

//#include <iostream>
//#include <string>
//using namespace std;
//
//class Node {
//   int elem;
//   Node* next;
//
//   friend class S_LinkedList;
//};
//
//class S_LinkedList {
//public:
//   S_LinkedList();
//   int List_size();
//   bool Empty();
//   void Print();
//   void Append(int elem);
//   void Merge(S_LinkedList& list1, S_LinkedList& list2);
//   int FindElem(int num);
//   void Insert(int num, int insertion);
//
//private:
//   Node* head;
//   Node* tail;
//};
//
//S_LinkedList::S_LinkedList() {
//   head = new Node;
//   tail = new Node;
//
//   head = NULL;
//   tail = NULL;
//}
//
//bool S_LinkedList::Empty() {
//   return (head == NULL && tail == NULL);
//}
//
//int S_LinkedList::List_size() {
//   int list_size = 0;
//
//   if (Empty()) {
//      return list_size;
//   }
//   else {
//      Node* cur_node = head;
//      while (cur_node->next != NULL) {
//         list_size++;
//         cur_node = cur_node->next;
//      }
//      list_size++;
//      return list_size;
//   }
//}
//
//void S_LinkedList::Print() {
//   if (Empty()) {
//      cout << "empty" << endl;
//   }
//   else {
//      Node* cur_node = head;
//      while (cur_node->next != NULL) {
//         cout << cur_node->elem << ' ';
//         cur_node = cur_node->next;
//      }
//      cout << cur_node->elem << endl;
//   }
//}
//
//void S_LinkedList::Append(int elem) {
//   Node* new_node = new Node;
//   new_node->elem = elem;
//   new_node->next = NULL;
//
//   if (Empty()) {
//      head = new_node;
//      tail = new_node;
//   }
//   else {
//      tail->next = new_node;
//      tail = tail->next;
//   }
//}
//
//int S_LinkedList::FindElem(int num) {
//   Node* cur_node;
//
//   cur_node = head;
//   while (1) {
//      if (num == cur_node->elem) {
//         return cur_node->elem;
//      }
//      cur_node = cur_node->next;
//   }
//}
//
//void S_LinkedList::Insert(int num, int insertion) {
//   Node* cur_node;
//   Node* new_node = new Node;
//   new_node->elem = insertion;
//   new_node->next = NULL;
//
//   cur_node = head;
//   while (1) {
//      if (cur_node == head && cur_node->elem == FindElem(num)) {
//         new_node->next = cur_node;
//         head = new_node;
//         break;
//      }
//      if (cur_node->next->elem == FindElem(num)) {
//         new_node->next = cur_node->next;
//         cur_node->next = new_node;
//         break;
//      }
//      cur_node = cur_node->next;
//   }
//}
//
//void S_LinkedList::Merge(S_LinkedList& list1, S_LinkedList& list2) {
//   list1.tail->next = list2.head;
//}
//
//int main() {
//   int M = 0, n = 0, n1 = 0, m = 0;
//   cin >> M;
//
//   while (M--) {
//      S_LinkedList list1 = S_LinkedList();
//      S_LinkedList list2 = S_LinkedList();
//      cin >> n;
//
//      for (int i = 0; i < n; i++) {
//         cin >> m;
//         list1.Append(m);
//      }
//
//      cin >> n;
//
//      for (int i = 0; i < n; i++) {
//         cin >> m;
//         list2.Append(m);
//      }
//
//      list1.Merge(list1, list2);
//      list1.Print();
//
//      cin >> n >> n1;
//
//      list1.Insert(n, n1);
//      list1.Print();
//   }
//}