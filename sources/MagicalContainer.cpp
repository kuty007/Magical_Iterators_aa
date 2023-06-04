//
// Created by asaf7 on 6/4/2023.
//

#include <stdexcept>
#include "MagicalContainer.hpp"

namespace ariel {
    // implementation of MagicalContainer
    MagicalContainer::MagicalContainer() : container() {}

    MagicalContainer::~MagicalContainer() {}

    void MagicalContainer::addElement(int element) {
        this->container.addElement(element);
    }

    void MagicalContainer::removeElement(int element) {
        this->container.removeElement(element);
    }

    int MagicalContainer::size() {
        return this->container.getSize();
    }

    // implementation of AscendingIterator
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container, Node *current) : container(
            container), current(current) {}

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : container(other.container),
                                                                                             current(other.current) {}

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(
            const AscendingIterator &other) {
        this->container = other.container;
        this->current = other.current;
        return *this;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
        if (this->current == nullptr) {
            throw std::out_of_range("out of range");
        }
        this->current = this->current->next;
        return *this;
    }

    int MagicalContainer::AscendingIterator::operator*() {
        if (this->current == nullptr) {
            throw std::out_of_range("out of range");
        }
        return this->current->data;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const {
        return this->current == other.current;
    }

     bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const {
            return !(*this == other);
        }


    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
        return AscendingIterator(this->container, this->container.container.getHead());
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
        return AscendingIterator(this->container, nullptr);
    }

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : container(container),
                                                                                          current(
                                                                                                  container.container.getHead()) {


    }

    // implementation of SideCrossIterator
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container, Node *current) : container(
            container), current(current) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : container(other.container),
                                                                                             current(other.current) {}


    MagicalContainer::SideCrossIterator &
    MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) {
        this->container = other.container;
        this->current = other.current;
        return *this;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
        if (this->current == nullptr) {
            throw std::out_of_range("out of range");
        }
        this->current = this->current->next;
        return *this;
    }

    int MagicalContainer::SideCrossIterator::operator*() {
        if (this->current == nullptr) {
            throw std::out_of_range("out of range");
        }
        return this->current->data;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const {
        return this->current == other.current;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const {
        return !(*this == other);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
        return SideCrossIterator(this->container, this->container.container.getHead());
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
        return SideCrossIterator(this->container, nullptr);
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : container(container),
                                                                                          current(container.container.getHead()) {

    }

    // implementation of PrimeIterator
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container, Node *current) : container(
            container), current(current) {}

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : container(other.container),
                                                                                 current(other.current) {}

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
        this->container = other.container;
        this->current = other.current;
        return *this;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
        if (this->current == nullptr) {
            throw std::out_of_range("out of range");
        }
        this->current = this->current->next_prime;
        return *this;
    }

    int MagicalContainer::PrimeIterator::operator*() {
        if (this->current == nullptr) {
            throw std::out_of_range("out of range");
        }
        return this->current->data;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const{
        return this->current == other.current;
    }

     bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const {
        return !(*this == other);
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
        return {this->container, this->container.container.getHeadPrime()};
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
        return PrimeIterator(this->container, nullptr);
    }

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : container(container),
                                                                                  current(container.container.getHeadPrime()){

    }


} // ariel
