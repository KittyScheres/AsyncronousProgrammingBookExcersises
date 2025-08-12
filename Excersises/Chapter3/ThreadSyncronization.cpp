#include <iostream>
#include <thread>

namespace Chapter3 {
	namespace ThreadSyncronization {
		void RaceCondition() {
			std::thread t1 = std::thread([](){
				for (int i = 0; i < 100; i++) {
					printf("1 2 3 4\n");
				}
			});

			std::thread t2 = std::thread([]() {
				for (int i = 0; i < 100; i++) {
					printf("5 6 7 8\n");
				}
			});

			t1.join();
			t2.join();
		}
	}
}