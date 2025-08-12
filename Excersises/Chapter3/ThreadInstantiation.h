#pragma once

namespace Chapter3 {
	namespace ThreadInstatiation {
		void InstantiateThreads();
		void FunctionPointer();

		class FunctionObject {
		public:
			void operator() ();
		};

		class Object {
		public:
			void Method();
			static void StaticMethod();
		};
	}
}