#include "stdafx.h"
#include "CppUnitTest.h"

#include "../G1/Time.cpp"
#include "../G1/Vector2.cpp"
#include "../G1/Segment.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace G1UnitTests
{		
	TEST_CLASS(Vector2UnitTest1)
	{
	public:
		TEST_METHOD(equal_1)
		{
			Vector2 v1(1.f, 1.f);
			Vector2 v2(1.f, 1.f);

			if (v1.equal(v2, 0.f))
				Assert::IsTrue(true);
			else
				Assert::IsTrue(false);
		}

		TEST_METHOD(equal_2)
		{
			Vector2 v1(1.005f, 1.005f);
			Vector2 v2(1.f, 1.f);

			if (v1.equal(v2, 0.01f))
				Assert::IsTrue(true);
			else 
				Assert::IsTrue(false);
		}

		TEST_METHOD(equal_3)
		{
			Vector2 v1(1.0101f, 1.005f);
			Vector2 v2(1.f, 1.f);

			if (v1.equal(v2, 0.01f))
				Assert::IsTrue(false);
			else
				Assert::IsTrue(true);
		}
	};

	TEST_CLASS(SegmentUnitTest1)
	{
	public:
		TEST_METHOD(point_relative_segment_1)
		{
			Vector2 p1(0.f, 0.f);
			Vector2 p2(0.f, 10.f);
			Vector2 p(5.f, 5.f);

			G1::Segment seg(p1, p2);

			Assert::IsTrue( seg.pointRelativeLine(p) > 0.f );
		}

		TEST_METHOD(point_relative_segment_2)
		{
			Vector2 p1(0.f, 0.f);
			Vector2 p2(0.f, 10.f);
			Vector2 p(-5.f, 5.f);

			G1::Segment seg(p1, p2);

			Assert::IsTrue(seg.pointRelativeLine(p) < 0.f);
		}

		TEST_METHOD(point_relative_segment_3)
		{
			Vector2 p1(0.f, 0.f);
			Vector2 p2(0.f, 10.f);
			Vector2 p(0.f, 5.f);

			G1::Segment seg(p1, p2);

			Assert::IsTrue(seg.pointRelativeLine(p) == 0.f);
		}

		TEST_METHOD(test_malloc)
		{
			int* nr = (int*)malloc(2);

			*nr = 4;

		}

	};
}