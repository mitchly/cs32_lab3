#include "student.h"
#include <string>
#include <cstring>
#include <sstream>
#include <cstring>

Student::Student(const char * const name, int perm) {
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
  this->perm = perm;
}

int Student::getPerm() const {
  return perm;
}

const char * const Student::getName() const {
  return name;
}

void Student::setPerm(const int permNumber) {
  this->perm = permNumber;
}

void Student::setName(const char * const name) {
  delete[] this->name;
  this->name = new char[strlen(name)+1];
  strcpy(this->name, name);
}


Student::Student(const Student &orig) {
  this->name = new char[strlen(orig.name) + 1];
  strcpy(this->name, orig.getName());
  this->perm = orig.getPerm();
  
}

Student::~Student() {
  delete[] name;
}

Student & Student::operator=(const Student &right) {
  if (&right == this) 
    return (*this);
  setName(right.getName());
  setPerm(right.getPerm());
  return (*this); 

}

std::string Student::toString() const {
  std::ostringstream oss;
  
  oss << "[" 
      << this->getName() << ","
      << this->getPerm() << "]";
  return oss.str();
}

