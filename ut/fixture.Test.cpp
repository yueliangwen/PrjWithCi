#include "suite_level.h"
#include "gtest/gtest.h"

// Tests SharedResource.
TEST(TestFixtureNormal, SharedResource) {
	EXPECT_EQ(10, PrjTestSuite::shared_resource_);
}

class GTestFixtureCustom : public PrjTestSuite {
protected:
	virtual void SetUp() {
		// case level member init
		caseLevel_ = 100;
	}

	virtual void TearDown() {
		// case level member delete
	}

	int caseLevel_;
};

TEST_F(GTestFixtureCustom, SharedResource) {
	EXPECT_EQ(10, shared_resource_);
}

TEST_F(GTestFixtureCustom, CaseLevelMember) {
	EXPECT_EQ(100, caseLevel_);
}

