#pragma once

#include <iostream>
using namespace std;

class Person
{
	char* name;
	uint16_t age;// только +.максимум 16 бит.
	uint32_t sociakid;
public:
	Person(const char* nameP, uint16_t ageP, uint32_t s) :
		name{ nameP? new char[strlen(nameP) + 1]:nullptr }, age{ ageP }, sociakid{ s }{
		if ((nameP)) {
			strcpy_s(name, strlen(nameP) + 1, nameP);//перегрузки
			cout << "Person constructed\n ";
		};

		
		
	}
	Person() :  Person{ nullptr,0,0 }{};

	Person(const char* nameP) : Person{ nameP,0,0 } {//делегирование 
	};
	Person(const char* nameP, uint16_t ageP) :Person{ nameP,ageP,0 } {};
	
	
	~Person() {//дестуктор
		delete[]name;
		cout << "Des  ";
	}
	void Print() {
		if (name) cout << "Name -> " << name;
		else
			cout << "net ";
	}
};

