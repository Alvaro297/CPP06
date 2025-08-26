#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

#include <iostream>
#include "Data.hpp"

class Serialize {
	private:
		Serialize();
		Serialize(Serialize const & src);
		Serialize & operator=(Serialize const & rhs);
		~Serialize();
	public:
		static unsigned long serialize(Data* ptr);
		static Data* deserialize(unsigned long raw);

};
#endif