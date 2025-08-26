#include "Serialize.hpp"

Serialize::Serialize() {}
Serialize::Serialize(Serialize const & src) { *this = src; }
Serialize & Serialize::operator=(Serialize const & rhs) {
	if (this != &rhs) {}
	return (*this);
}
Serialize::~Serialize() {}
unsigned long Serialize::serialize(Data* ptr) { return reinterpret_cast<unsigned long>(ptr); }
Data* Serialize::deserialize(unsigned long raw) { return reinterpret_cast<Data*>(raw); }