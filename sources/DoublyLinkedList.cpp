//
// Created by asaf7 on 6/4/2023.
//
#include <cmath>
#include "DoublyLinkedList.h"

DoublyLinkedList::~DoublyLinkedList() {
    Node* current = this->head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

}

void DoublyLinkedList::addElement(int data) {
    Node* new_node = new Node{data, isPrime(data), nullptr, nullptr, nullptr};
    // if list is empty
    if (this->head == nullptr) {
        this->head = new_node;
        this->tail = new_node;
        this->head_prime = new_node->is_prime ? new_node : nullptr;
        this->size++;
        this->prime_size += new_node->is_prime ? 1 : 0;
        return;
    }
    // if list is not empty add in ascending order to the list and if the new node is prime add it to the prime list and update the pointers if it is already exist do nothing
    Node* current = this->head;
    while (current != nullptr) {
        if (current->data == data) {
            delete new_node;
            return;
        }
        if (current->data > data) {
            if (current == this->head) {
                new_node->next = this->head;
                this->head->prev = new_node;
                this->head = new_node;
                this->size++;
                this->prime_size += new_node->is_prime ? 1 : 0;
                if (new_node->is_prime) {
                    new_node->next_prime = this->head_prime;
                    this->head_prime = new_node;
                }
                return;
            }
            new_node->next = current;
            new_node->prev = current->prev;
            current->prev->next = new_node;
            current->prev = new_node;
            this->size++;
            this->prime_size += new_node->is_prime ? 1 : 0;
            if (new_node->is_prime) {
                new_node->next_prime = current;
                if (current == this->head_prime) {
                    this->head_prime = new_node;
                } else {
                    new_node->prev->next_prime = new_node;
                }
            }
            return;
        }
        current = current->next;
    }
    // if the new node is the biggest in the list
    new_node->prev = this->tail;
    this->tail->next = new_node;
    this->tail = new_node;
    this->size++;
    this->prime_size += new_node->is_prime ? 1 : 0;
    if (new_node->is_prime) {
        new_node->next_prime = nullptr;
        this->tail->next_prime = new_node;
    }
}

Node *DoublyLinkedList::getHeadPrime() {
    return this->head_prime;
}

Node *DoublyLinkedList::getTail() {
    return this->tail;
}

Node *DoublyLinkedList::getHead() {
    return this->head;
}

int DoublyLinkedList::getPrimeSize() {
    return this->prime_size;
}

int DoublyLinkedList::getSize() {
    return this->size;
}

void DoublyLinkedList::removeElement(int element) {
    Node* current = this->head;
    while (current != nullptr) {
        if (current->data == element) {
            if (current == this->head) {
                this->head = current->next;
                if (this->head != nullptr) {
                    this->head->prev = nullptr;
                }
                if (current->is_prime) {
                    this->head_prime = current->next_prime;
                    if (this->head_prime != nullptr) {
                        this->head_prime->prev->next_prime = nullptr;
                        this->head_prime->prev = nullptr;
                    }
                }
                delete current;
                this->size--;
                this->prime_size -= current->is_prime ? 1 : 0;
                return;
            }
            if (current == this->tail) {
                this->tail = current->prev;
                this->tail->next = nullptr;
                if (current->is_prime) {
                    this->tail->next_prime = nullptr;
                }
                delete current;
                this->size--;
                this->prime_size -= current->is_prime ? 1 : 0;
                return;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            if (current->is_prime) {
                current->prev->next_prime = current->next_prime;
                current->next_prime->prev = current->prev;
            }
            delete current;
            this->size--;
            this->prime_size -= current->is_prime ? 1 : 0;
            return;
        }
        current = current->next;


    }

}

bool DoublyLinkedList::isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i < sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
