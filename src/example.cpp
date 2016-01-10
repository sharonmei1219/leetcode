#include "gtest/gtest.h"
#include "gmock/gmock.h"
using namespace std;
using ::testing::Return;

class Dependency{
public:
	virtual ~Dependency(){}
	virtual int doSomething(int input) = 0;
};

class Example{
private:
	Dependency *dependency;
public:
	Example(Dependency *dependency);
	int addNumberFromDependency(int input);
};

Example::Example(Dependency * dependency){
	this->dependency = dependency;
}

int Example::addNumberFromDependency(int input){
	return input + dependency->doSomething(input);
}

class MockDependency : public Dependency{
public:
	MOCK_METHOD1(doSomething, int(int input));
};

class TestExampleWithMockDependency : public ::testing::Test{
protected:
	Example * example;
	MockDependency * dependency;
	virtual void SetUp(){
		dependency = new MockDependency();
		example = new Example(dependency);
	}

	virtual void TearDown(){
		delete dependency;
		delete example;
	}
};

TEST_F(TestExampleWithMockDependency, testInputIs1AndDependencyReturns2){
	EXPECT_CALL(*dependency, doSomething(1))
		.Times(1)
		.WillOnce(Return(2));

	int result = example->addNumberFromDependency(1);

	EXPECT_EQ(3, result);
};