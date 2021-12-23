#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

//cs24 append function
void StudentRoll::insertAtTail(const Student &s) {
  //Node *newNode = new Node;
  //head->s = new Student(s);
  if(head == nullptr){
    head = new Node;
    tail = head;
    head->s = new Student(s);
    head->next = nullptr;
  }
  else{
    Node *newNode = head;
    while(newNode->next){
      newNode = newNode->next;
    }
    newNode->next = new Node;
    newNode->next->s = new Student(s);
    newNode->next->next = nullptr;
  }
}

//cs24 reoptimized for returning string variable
std::string StudentRoll::toString() const {
  Node *newNode = head;
  std::string str = "";
  str += '[';
  while(newNode != nullptr){
      str += newNode->s->toString();
      if(newNode->next){
        str += ',';
      }
      newNode = newNode->next;
    }
  str += ']';
  return str;
}

//copy constructor
StudentRoll::StudentRoll(const StudentRoll &orig) {
  head = tail = NULL;
  Node *newNode = orig.head;
  while(newNode != nullptr){
    insertAtTail(*newNode->s);
    newNode = newNode->next;
  }
}

//destructor
StudentRoll::~StudentRoll() {
  Node *newNode = head;
  while(newNode != nullptr){
    Node *temp;
    temp = newNode;
    newNode = newNode->next;
    delete temp->s;
    delete temp;
  }
  head = nullptr;
}

//assignment operator
StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {

  if (&right == this) 
    return (*this);

  Node *NewNode = head;
    while(NewNode != nullptr){
    Node *temp;
    temp = NewNode;
    NewNode = NewNode->next;
    delete temp->s;
    delete temp;
  }
  head = nullptr;

  Node *newNode = right.head;
  while(newNode){
    insertAtTail(*newNode->s);
    newNode = newNode->next;
  }

  return (*this); 
}





