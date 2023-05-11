// Copyright 2021 NNTU-CS
#include "train.h"
void Train::addCage(bool light) {
  if (first == nullptr) {
    Cage * cage = new Cage;
    cage->light = light;
    cage->next = cage;
    cage->prev = cage;
    first = cage;
  } else {
    Cage * cage = new Cage;
    cage->light = light;
    cage->next = first;	
    cage->prev = first->prev;
    first->prev->next = cage;
    first->prev = cage;
  }
}
int Train::getLength() {
  int count = 1;
  Cage* temp = first;
  first->light = true;
  while (first->light == true) {
    count = 1;
    temp = first->next;
    while (temp->light == false) {
      temp = temp->next;
      ++count;
    }
    temp->light = false;
    countOp += 2 * count;
  }
  return count;
}
int Train::getOpCount() {
  return countOp;
}
