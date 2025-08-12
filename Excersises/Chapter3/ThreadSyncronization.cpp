#include <iostream>

#include <syncstream>
#include <thread>

namespace Chapter3 {
	namespace ThreadSyncronization {
		void RaceCondition() {
			std::thread t1 = std::thread([](){
				for (int i = 0; i < 100; i++) {
					std::osyncstream(std::cout) << "1" << "2" << "3" << "4" << std::endl;
				}
			});

			std::thread t2 = std::thread([]() {
				for (int i = 0; i < 100; i++) {
					std::osyncstream(std::cout) << "5" << "6" << "7" << "8" << std::endl;
				}
			});

			t1.join();
			t2.join();
		}
	}
}