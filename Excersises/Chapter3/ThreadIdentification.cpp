#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

namespace Chapter3 {
	namespace ThreatIdentification {
		void SleepThread() {
			std::this_thread::sleep_for(1s);
		}

		void CreateAndIdentifyThread() {
			std::thread t1 = std::thread(SleepThread);
			std::cout << "Thread ID: " << t1.get_id() << std::endl;
			t1.join();
		}
	}
}