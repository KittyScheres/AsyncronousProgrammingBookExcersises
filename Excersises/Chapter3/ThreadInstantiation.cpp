#include "ThreadInstantiation.h"
#include <iostream>
#include <thread>

namespace Chapter3 {
	namespace ThreadInstatiation {

		void InstantiateThreads() {
			auto lambda = []() {
				printf("I am a lambda from a variable\n");
			};

			std::thread t1 = std::thread(FunctionPointer);
			std::thread t2 = std::thread(lambda);
			std::thread t3 = std::thread([]() { printf("I am an imbeded lambda\n"); });
			std::thread t4{ FunctionObject() };
			Object object = Object();
			std::thread t5 = std::thread(&Object::Method, &object);
			std::thread t6 = std::thread(&Object::StaticMethod);

			uint32_t numberOfAvailableThreads = std::thread::hardware_concurrency();
			printf("Number of currently available threads is %u\n", numberOfAvailableThreads);

			t1.join();
			t2.join();
			t3.join();
			t4.join();
			t5.join();
			t6.join();
		}

		void FunctionPointer() {
			printf("I am a function pointer\n");
		}

		void FunctionObject::operator() () {
			printf("I am a () operator on an object\n");
		}

		void Object::Method() {
			printf("I am an object method\n");
		}
		
		void Object::StaticMethod() {
			printf("I am a static method\n");
		}

	}
}