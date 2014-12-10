#include <iostream>

#include "gtest/gtest.h"

// Project's global event, excute before cases
class PrjEnvironment : public testing::Environment
{
public:
	virtual void SetUp()
	{
		// 内存池初始化
		//std::cout << "PrjEnvironment SetUP" << std::endl;
	}
	virtual void TearDown()
	{
		//std::cout << "PrjEnvironment TearDown" << std::endl;
	}
};

GTEST_API_ int main(int argc, char **argv) {
    //std::cout << "Running main() from gtest_main.cpp" << std::endl;
	testing::AddGlobalTestEnvironment(new PrjEnvironment);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

