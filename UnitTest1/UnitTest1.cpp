#include "pch.h"
#include "CppUnitTest.h"
#include "../Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string str="s, s, h, r, s, d, (, s, (, f, ), ), f";
			int error;
			Change(str, error);
			Assert::AreEqual(error, 1);
		}
	};
}
