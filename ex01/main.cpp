#include <iostream>
#include "Serialize.hpp"

int main()
{
	Data myData;
	myData.dataString = "42 Madrid";
	myData.dataInt = 42;

	unsigned long raw = Serialize::serialize(&myData);
	Data* ptr = Serialize::deserialize(raw);

	std::cout << "Original Data address: " << &myData << std::endl;
	std::cout << "Serialized value: " << raw << std::endl;
	std::cout << "Deserialized Data address: " << ptr << std::endl;

	std::cout << "Comprobando contenido:" << std::endl;
	std::cout << "\tString: " << ptr->dataString << std::endl;
	std::cout << "\tInt: " << ptr->dataInt << std::endl;

	if (ptr == &myData)
		std::cout << "Deserialización correcta" << std::endl;
	else
		std::cout << "Error no apuntan al mismo objeto" << std::endl;
	return 0;
}