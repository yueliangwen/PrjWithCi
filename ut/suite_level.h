// 共享某个固件环境的所有测试合称为一个“测试套件”。
#include "gtest/gtest.h"

// TestSuite level
class PrjTestSuite : public testing::Test {
public:
	static void SetUpTestCase() {
		// shared_resource_ new
	}
	static void TearDownTestCase() {
		// shared_resource_ delete
	}
	// Some expensive resource shared by all tests.
	static int shared_resource_;
};

int PrjTestSuite::shared_resource_ = 10;

