//Cody Ware
//10/2/18

#include "PhysicsVectorTests.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void PhysicsVectorTests::constructor2D()
{
	double* values = new double[2];
	values[0] = 0.0;
	values[1] = 0.0;

	PhysicsVector test(values, 2);

	Assert::IsTrue(test[0] == 0.0, L"constructor failed");

	Assert::IsTrue(test[1] == 0.0, L"constructor failed");
}

void PhysicsVectorTests::constructorWithValues2D()
{
	double* values = new double[2];
	values[0] = 5.5;
	values[1] = 7.1;

	PhysicsVector test(values, 2);

	Assert::IsTrue(test[0] == 5.5, L"constructorWithValues");

	Assert::IsTrue(test[1] == 7.1, L"constructorWithValues");
}

void PhysicsVectorTests::copyConstructor2D()
{
	double* values = new double[2];
	values[0] = 5.5;
	values[1] = 7.1;

	PhysicsVector test(values, 2);

	PhysicsVector copy(test);

	//make sure they have the right values
	Assert::IsTrue(test[0] == 5.5, L"copyConstructor");

	Assert::IsTrue(test[1] == 7.1, L"copyConstructor");

	Assert::IsTrue(copy[0] == 5.5, L"copyConstructor");

	Assert::IsTrue(copy[1] == 7.1, L"copyConstructor");

	//make sure each has its own memory
	Assert::IsTrue(&test[0] != &copy[0], L"copyConstructor");

	Assert::IsTrue(&test[1] != &copy[1], L"copyConstructor");
}

void PhysicsVectorTests::moveConstructor2D()
{
	double* values = new double[2];
	values[0] = 5.0;
	values[1] = 6.0;

	PhysicsVector test(values, 2);

	PhysicsVector moveHere(std::move(test));

	//make sure they have the righ tvalues
	Assert::IsTrue(test.getNumberOfDimensions() == 0, L"moveConstructor");

	Assert::IsTrue(moveHere[0] == 5.0, L"moveConstructor");

	Assert::IsTrue(moveHere[1] == 6.0, L"moveConstructor");
}

void PhysicsVectorTests::assignmentOperator2D()
{
	double* values = new double[2];
	values[0] = 55;
	values[1] = 10;

	PhysicsVector test(values, 2);

	PhysicsVector assigned = test;

	//make sure they have the righ tvalues
	Assert::IsTrue(test[0] == 55.0, L"assignmentOperator");

	Assert::IsTrue(test[1] == 10.0, L"assignmentOperator");

	Assert::IsTrue(assigned[0] == 55.0, L"assignmentOperator");

	Assert::IsTrue(assigned[1] == 10.0, L"assignmentOperator");

	//make sure each has its own memory
	Assert::IsTrue(&test[0] != &assigned[0], L"assignmentOperator");

	Assert::IsTrue(&test[1] != &assigned[1], L"assignmentOperator");
}

void PhysicsVectorTests::moveAssignmentOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 6;

	PhysicsVector test(values, 2);

	PhysicsVector moveAssignHere = std::move(test);

	//make sure they have the righ tvalues
	Assert::IsTrue(test.getNumberOfDimensions() == 0.0, L"moveAssignmentOperator");

	Assert::IsTrue(moveAssignHere[0] == 5.0, L"moveAssignmentOperator");

	Assert::IsTrue(moveAssignHere[1] == 6.0, L"moveAssignmentOperator");
}

void PhysicsVectorTests::destructor()
{
	PhysicsVector* test;
	if (true) 
	{
		test = new PhysicsVector();
		test->addDimension(1);
		test->addDimension(1);
		test->addDimension(1);

		Assert::IsTrue((*test)[0] == 1, L"destructor");
		Assert::IsTrue((*test)[1] == 1, L"destructor");
		Assert::IsTrue((*test)[2] == 1, L"destructor");

		delete test;
	}

	Assert::IsNull(test[0], L"destructor");
}

void PhysicsVectorTests::additionOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 1;
	values2[1] = 2;

	PhysicsVector plus(values2, 2);

	PhysicsVector sum = orig + plus;

	Assert::IsTrue(sum[0] == 6.0, L"additionOperator 1");

	Assert::IsTrue(sum[1] == 12.0, L"additionOperator 2");

	Assert::IsTrue(&sum[0] != &orig[0], L"additionOperator 3");

	Assert::IsTrue(&sum[1] != &orig[1], L"additionOperator 4");

	Assert::IsTrue(&sum[0] != &plus[0], L"additionOperator 5");

	Assert::IsTrue(&sum[1] != &plus[1], L"additionOperator 6");
}

void PhysicsVectorTests::subtractionOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 1;
	values2[1] = 2;

	PhysicsVector minus(values2, 2);

	PhysicsVector difference = orig - minus;

	Assert::IsTrue(difference[0] == 4.0, L"subtractionOperator");

	Assert::IsTrue(difference[1] == 8.0, L"subtractionOperator");

	Assert::IsTrue(&difference[0] != &orig[0], L"subtractionOperator");

	Assert::IsTrue(&difference[1] != &orig[1], L"subtractionOperator");

	Assert::IsTrue(&difference[0] != &minus[0], L"subtractionOperator");

	Assert::IsTrue(&difference[1] != &minus[1], L"subtractionOperator");
}

void PhysicsVectorTests::multiplyOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 2;
	values2[1] = 2;

	PhysicsVector times(values2, 2);

	PhysicsVector product = orig * times;

	Assert::IsTrue(product[0] == 10.0, L"multiplyOperator");

	Assert::IsTrue(product[1] == 20.0, L"multiplyOperator");

	Assert::IsTrue(&product[0] != &orig[0], L"multiplyOperator");

	Assert::IsTrue(&product[1] != &orig[1], L"multiplyOperator");

	Assert::IsTrue(&product[0] != &times[0], L"multiplyOperator");

	Assert::IsTrue(&product[1] != &times[1], L"multiplyOperator");
}

void PhysicsVectorTests::multiplyByDoubleOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double times = 2;

	PhysicsVector product = orig * times;

	Assert::IsTrue(product[0] == 10.0, L"multiplyByDoubleOperator");

	Assert::IsTrue(product[1] == 20.0, L"multiplyByDoubleOperator");

	Assert::IsTrue(&product[0] != &orig[0], L"multiplyByDoubleOperator");

	Assert::IsTrue(&product[1] != &orig[1], L"multiplyByDoubleOperator");
}

void PhysicsVectorTests::equivalenceOperators2D()
{
	double* values = new double[2];
	values[0] = 50;
	values[1] = 70;

	PhysicsVector test(values, 2);

	double* values2 = new double[2];
	values2[0] = 50;
	values2[1] = 70;

	PhysicsVector test2(values2, 2);

	double* values3 = new double[2];
	values3[0] = 50.0000000000000001;
	values3[1] = 70.0000000000000001;

	PhysicsVector test3(values3, 2);

	double* values4 = new double[2];
	values4[0] = 6;
	values4[1] = 7;

	PhysicsVector test4(values4, 2);

	Assert::IsTrue(test == test2, L"equivalenceOperators 1");

	Assert::IsTrue(test == test3, L"equivalenceOperators 2");

	Assert::IsTrue(test != test4, L"equivalenceOperators 3");
}

void PhysicsVectorTests::dotProduct2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 2;
	values2[1] = 3;

	PhysicsVector dot(values2, 2);

	double product = orig.dot(dot);

	Assert::IsTrue(product == 40.0, L"dotProduct");
}

void PhysicsVectorTests::magnitude2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector test(values, 2);

	double magnitude = test.magnitude();

	Assert::IsTrue(magnitude > 11.1 && magnitude < 11.2, L"magnitude");
}

void PhysicsVectorTests::magnitudeSquared2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector test(values, 2);

	double magnitudeSq = test.magnitudeSquared();

	Assert::IsTrue(magnitudeSq == 125.0, L"magnitudeSquared");
}

void PhysicsVectorTests::divideOperator2D()
{
	double* values = new double[2];
	values[0] = 6;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 2;
	values2[1] = 5;

	PhysicsVector divisor(values2, 2);

	PhysicsVector quotient = orig / divisor;

	Assert::IsTrue(quotient[0] == 3.0, L"divideOperator");

	Assert::IsTrue(quotient[1] == 2.0, L"divideOperator");

	Assert::IsTrue(&quotient[0] != &orig[0], L"divideOperator");

	Assert::IsTrue(&quotient[1] != &orig[1], L"divideOperator");

	Assert::IsTrue(&quotient[0] != &divisor[0], L"divideOperator");

	Assert::IsTrue(&quotient[1] != &divisor[1], L"divideOperator");
}

void PhysicsVectorTests::divideByDoubleOperator2D()
{
	double* values = new double[2];
	values[0] = 6;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double divisor = 2;

	PhysicsVector quotient = orig / divisor;

	Assert::IsTrue(quotient[0] == 3.0, L"divideByDoubleOperator");

	Assert::IsTrue(quotient[1] == 5.0, L"divideByDoubleOperator");

	Assert::IsTrue(&quotient[0] != &orig[0], L"divideByDoubleOperator");

	Assert::IsTrue(&quotient[1] != &orig[1], L"divideByDoubleOperator");
}

void PhysicsVectorTests::additionShorthandOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 1;
	values2[1] = 2;

	PhysicsVector plus(values2, 2);

	orig += plus;

	Assert::IsTrue(orig[0] == 6.0, L"additionShorthandOperator");

	Assert::IsTrue(orig[1] == 12.0, L"additionShorthandOperator");

	Assert::IsTrue(&orig[0] != &plus[0], L"additionShorthandOperator");

	Assert::IsTrue(&orig[1] != &plus[1], L"additionShorthandOperator");
}

void PhysicsVectorTests::subtractionShorthandOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 1;
	values2[1] = 2;

	PhysicsVector minus(values2, 2);

	orig -= minus;

	Assert::IsTrue(orig[0] == 4.0, L"subtractionShorthandOperator");

	Assert::IsTrue(orig[1] == 8.0, L"subtractionShorthandOperator");

	Assert::IsTrue(&orig[0] != &minus[0], L"subtractionShorthandOperator");

	Assert::IsTrue(&orig[1] != &minus[1], L"subtractionShorthandOperator");
}

void PhysicsVectorTests::multiplyShorthandOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 2;
	values2[1] = 2;

	PhysicsVector times(values2, 2);

	orig *= times;

	Assert::IsTrue(orig[0] == 10.0, L"multiplyShorthandOperator 1");

	Assert::IsTrue(orig[1] == 20.0, L"multiplyShorthandOperator 2");

	Assert::IsTrue(&orig[0] != &times[0], L"multiplyShorthandOperator 3");

	Assert::IsTrue(&orig[1] != &times[1], L"multiplyShorthandOperator 4");
}

void PhysicsVectorTests::multiplyByDoubleShorthandOperator2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double times = 2;

	orig *= times;

	Assert::IsTrue(orig[0] == 10.0, L"multiplyByDoubleShorthandOperator 1");

	Assert::IsTrue(orig[1] == 20.0, L"multiplyByDoubleShorthandOperator 2");
}

void PhysicsVectorTests::divideShorthandOperator2D()
{
	double* values = new double[2];
	values[0] = 6;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double* values2 = new double[2];
	values2[0] = 2;
	values2[1] = 5;

	PhysicsVector divisor(values2, 2);

	orig /= divisor;

	Assert::IsTrue(orig[0] == 3.0, L"divideShorthandOperator");

	Assert::IsTrue(orig[1] == 2.0, L"divideShorthandOperator");

	Assert::IsTrue(&orig[0] != &divisor[0], L"divideShorthandOperator");

	Assert::IsTrue(&orig[1] != &divisor[1], L"divideShorthandOperator");
}

void PhysicsVectorTests::divideByDoubleShorthandOperator2D()
{
	double* values = new double[2];
	values[0] = 6;
	values[1] = 10;

	PhysicsVector orig(values, 2);

	double divisor = 2;

	orig /= divisor;

	Assert::IsTrue(orig[0] == 3.0, L"divideByDoubleShorthandOperator 1");

	Assert::IsTrue(orig[1] == 5.0, L"divideByDoubleShorthandOperator 2");
}

void PhysicsVectorTests::distance2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector test(values, 2);

	double* values2 = new double[2];
	values2[0] = 7;
	values2[1] = 2;

	PhysicsVector test2(values2, 2);

	double distance = test.distance(test2);

	double alsoDistance = test2.distance(test);

	const double shouldBeThis = 8.2462112512353212;

	Assert::IsTrue(distance == alsoDistance, L"distance2D");

	Assert::IsTrue(distance == shouldBeThis, L"distance2D");
}

void PhysicsVectorTests::distanceSquared2D()
{
	double* values = new double[2];
	values[0] = 5;
	values[1] = 10;

	PhysicsVector test(values, 2);

	double* values2 = new double[2];
	values2[0] = 7;
	values2[1] = 3;

	PhysicsVector test2(values2, 2);

	double distanceSquared = test.distanceSquared(test2);

	double alsoDistanceSquared = test2.distanceSquared(test);

	Assert::IsTrue(distanceSquared == alsoDistanceSquared, L"distanceSquared");

	Assert::IsTrue(distanceSquared == 53.0, L"distanceSquared");
}

void PhysicsVectorTests::normalize2D()
{
	double* values = new double[2];
	values[0] = 0;
	values[1] = 10;

	PhysicsVector test(values, 2);

	double* values2 = new double[2];
	values2[0] = 10;
	values2[1] = 0;

	PhysicsVector test2(values2, 2);

	double* values3 = new double[2];
	values3[0] = 10;
	values3[1] = 10;

	PhysicsVector test3(values3, 2);

	test.normalize();
	test2.normalize();

	Assert::IsTrue(0.0 == test[0], L"normalize2D 1");
	Assert::IsTrue(1.0 == test[1], L"normalize2D 2");

	Assert::IsTrue(1.0 == test2[0], L"normalize2D 3");
	Assert::IsTrue(0.0 == test2[1], L"normalize2D 4");

	double testNormal = (10.0 * 10.0) + (10.0 * 10.0);
	testNormal = sqrt(testNormal);
	testNormal = 1 / testNormal;
	PhysicsVector normalizedTest3 = test3 * testNormal;

	test3.normalize();

	Assert::IsTrue(normalizedTest3 == test3, L"normalize2D 5");

	PhysicsVector test4 = PhysicsVector(0, 0);

	try
	{
		test4.normalize();
		Assert::IsTrue(false, L"normalize2D 6");
	}
	catch (std::logic_error e)
	{
		Assert::IsTrue(true, L"normalize2D 7");
	}
}

void PhysicsVectorTests::normalized2D()
{
	PhysicsVector test = PhysicsVector();
	test.addDimension(0);
	test.addDimension(10);

	PhysicsVector test2 = PhysicsVector();
	test2.addDimension(10);
	test2.addDimension(0);

	PhysicsVector test3 = PhysicsVector();
	test3.addDimension(10);
	test3.addDimension(10);

	PhysicsVector testNormalized = test.normalized();
	PhysicsVector test2Normalized = test2.normalized();

	Assert::IsTrue(0.0 == testNormalized[0], L"normalized");
	Assert::IsTrue(1.0 == testNormalized[1], L"normalized");

	Assert::IsTrue(1.0 == test2Normalized[0], L"normalized");
	Assert::IsTrue(0.0 == test2Normalized[1], L"normalized");

	Assert::IsTrue(&test[0] != &test2Normalized[0], L"normalized");
	Assert::IsTrue(&test2[0] != &test2Normalized[1], L"normalized");

	double testNormal = (10.0 * 10.0) + (10.0 * 10.0);
	testNormal = sqrt(testNormal);
	testNormal = 1 / testNormal;
	PhysicsVector normalizedTest3 = test3 * testNormal;

	PhysicsVector test3Normalized = test3.normalized();

	Assert::IsTrue(normalizedTest3 == test3Normalized, L"normalized");

	PhysicsVector test4 = PhysicsVector(0, 0);

	try
	{
		PhysicsVector test4Normalized = test4.normalized();
		Assert::IsTrue(false, L"normalized");
	}
	catch (std::logic_error e)
	{
		Assert::IsTrue(true, L"normalized");
	}
}

void PhysicsVectorTests::project2D()
{
	PhysicsVector first = PhysicsVector();
	first.addDimension(5);
	first.addDimension(5);

	PhysicsVector second = PhysicsVector();
	second.addDimension(-3);
	second.addDimension(2);

	PhysicsVector projected = first.project(second);

	Assert::IsTrue(15.0 / 13.0 == projected[0], L"project");
	Assert::IsTrue(-10.0 / 13.0 == projected[1], L"project");
}

void PhysicsVectorTests::outputOperator2D()
{
	PhysicsVector test = PhysicsVector();
	test.addDimension(55);
	test.addDimension(703);

	std::stringstream out;

	out << test;

	std::string testText = "(55, 703)";

	Assert::IsTrue(testText == out.str(), L"outputOperator");
}

void PhysicsVectorTests::perpendicular2D()
{
	PhysicsVector first = PhysicsVector();
	first.addDimension(5);
	first.addDimension(5);

	PhysicsVector second = PhysicsVector();
	second.addDimension(-3);
	second.addDimension(2);

	PhysicsVector perpendicular = first.perpendicular(second);

	Assert::IsTrue(3.84 < perpendicular[0], L"perpendicular");
	Assert::IsTrue(3.86 > perpendicular[0], L"perpendicular");

	Assert::IsTrue(5.75 < perpendicular[1], L"perpendicular");
	Assert::IsTrue(5.77 > perpendicular[1], L"perpendicular");

	PhysicsVector test2 = PhysicsVector();
	test2.addDimension(10.0);
	test2.addDimension(0.0);

	PhysicsVector test3 = PhysicsVector();
	test3.addDimension(5.0);
	test3.addDimension(5.0);

	PhysicsVector perpendicular2 = test3.perpendicular(test2);

	Assert::IsTrue(0.0 == perpendicular2[0], L"perpendicular");
	Assert::IsTrue(5.0 == perpendicular2[1], L"perpendicular");

}

void PhysicsVectorTests::angle2D()
{
	PhysicsVector first = PhysicsVector();
	first.addDimension(5);
	first.addDimension(5);

	PhysicsVector second = PhysicsVector();
	second.addDimension(-5);
	second.addDimension(5);

	Assert::IsTrue(90.0 == first.angle(second), L"angle");

	PhysicsVector third = PhysicsVector();
	third.addDimension(2);
	third.addDimension(7);

	PhysicsVector fourth = PhysicsVector();
	fourth.addDimension(-4);
	fourth.addDimension(-1);

	double testAngle2 = third.angle(fourth);

	Assert::IsTrue(testAngle2 > 119.9, L"angle");
	Assert::IsTrue(testAngle2 < 120, L"angle");
}

void PhysicsVectorTests::reflect2D()
{
	PhysicsVector right = PhysicsVector();
	right.addDimension(1);
	right.addDimension(0);

	PhysicsVector up = PhysicsVector();
	up.addDimension(0);
	up.addDimension(1);

	PhysicsVector reflectedLeft = right.reflect(up);

	PhysicsVector rotatedDown = up.reflect(right);

	Assert::IsTrue(-1.0 == reflectedLeft[0], L"reflect");
	Assert::IsTrue(0.0 == reflectedLeft[1], L"reflect");
	Assert::IsTrue(0.0 == rotatedDown[0], L"reflect");
	Assert::IsTrue(-1.0 == rotatedDown[1], L"reflect");
}

void PhysicsVectorTests::rotate2D()
{
	PhysicsVector test = PhysicsVector();
	test.addDimension(5);
	test.addDimension(5);

	PhysicsVector rotatedRight = test.rotate2D(-45.0);

	PhysicsVector rotatedLeft = test.rotate2D(45.0);

	Assert::IsTrue(rotatedRight[1] < 1, L"rotate");
	Assert::IsTrue(rotatedRight[1] >= 0, L"rotate");
	Assert::IsTrue(rotatedLeft[0] < 1, L"rotate");
	Assert::IsTrue(rotatedLeft[0] >= 0, L"rotate");
}

void PhysicsVectorTests::constructor3D()
{
	PhysicsVector test;
	test.addDimension(0);
	test.addDimension(0);
	test.addDimension(0);

	Assert::IsTrue(test[0] == 0.0, L"constructor3D");

	Assert::IsTrue(test[1] == 0.0, L"constructor3D");

	Assert::IsTrue(test[2] == 0.0, L"constructor3D");
}

void PhysicsVectorTests::constructorWithValues3D()
{
	PhysicsVector test;
	test.addDimension(5.5);
	test.addDimension(7.1);
	test.addDimension(9.6);

	Assert::IsTrue(test[0] == 5.5, L"constructorWithValues3D");

	Assert::IsTrue(test[1] == 7.1, L"constructorWithValues3D");

	Assert::IsTrue(test[2] == 9.6, L"constructorWithValues3D");
}

void PhysicsVectorTests::copyConstructor3D()
{
	PhysicsVector test;
	test.addDimension(5.5);
	test.addDimension(7.1);
	test.addDimension(9.6);

	PhysicsVector copy = PhysicsVector(test);

	//make sure they have the right values
	Assert::IsTrue(test[0] == 5.5, L"copyConstructor3D");

	Assert::IsTrue(test[1] == 7.1, L"copyConstructor3D");

	Assert::IsTrue(test[2] == 9.6, L"copyConstructor3D");

	Assert::IsTrue(copy[0] == 5.5, L"copyConstructor3D");

	Assert::IsTrue(copy[1] == 7.1, L"copyConstructor3D");

	Assert::IsTrue(copy[2] == 9.6, L"copyConstructor3D");

	//make sure each has its own memory
	Assert::IsTrue(&test[0] != &copy[0], L"copyConstructor3D");

	Assert::IsTrue(&test[1] != &copy[1], L"copyConstructor3D");

	Assert::IsTrue(&test[2] != &copy[2], L"copyConstructor3D");
}

void PhysicsVectorTests::moveConstructor3D()
{
	PhysicsVector test;
	test.addDimension(5);
	test.addDimension(6);
	test.addDimension(9);

	PhysicsVector moveHere(std::move(test));

	//make sure they have the righ tvalues
	Assert::IsTrue(test.getNumberOfDimensions() == 0, L"moveConstructor3D");

	Assert::IsTrue(moveHere[0] == 5.0, L"moveConstructor3D");

	Assert::IsTrue(moveHere[1] == 6.0, L"moveConstructor3D");

	Assert::IsTrue(moveHere[2] == 9.0, L"moveConstructor3D");
}

void PhysicsVectorTests::assignmentOperator3D()
{
	PhysicsVector test;
	test.addDimension(55);
	test.addDimension(10);
	test.addDimension(6);

	PhysicsVector assigned = test;

	//make sure they have the righ tvalues
	Assert::IsTrue(test[0] == 55.0, L"assignmentOperator3D");

	Assert::IsTrue(test[1] == 10.0, L"assignmentOperator3D");

	Assert::IsTrue(test[2] == 6.0, L"assignmentOperator3D");

	Assert::IsTrue(assigned[0] == 55.0, L"assignmentOperator3D");

	Assert::IsTrue(assigned[1] == 10.0, L"assignmentOperator3D");

	Assert::IsTrue(assigned[2] == 6.0, L"assignmentOperator3D");

	//make sure each has its own memory
	Assert::IsTrue(&test[0] != &assigned[0], L"assignmentOperator3D");

	Assert::IsTrue(&test[1] != &assigned[1], L"assignmentOperator3D");

	Assert::IsTrue(&test[2] != &assigned[2], L"assignmentOperator3D");
}

void PhysicsVectorTests::moveAssignmentOperator3D()
{
	PhysicsVector test;
	test.addDimension(5);
	test.addDimension(6);
	test.addDimension(8);

	PhysicsVector moveAssignHere = std::move(test);

	//make sure they have the righ tvalues
	Assert::IsTrue(test.getNumberOfDimensions() == 0, L"moveAssignmentOperator3D");

	Assert::IsTrue(moveAssignHere[0] == 5.0, L"moveAssignmentOperator3D");

	Assert::IsTrue(moveAssignHere[1] == 6.0, L"moveAssignmentOperator3D");

	Assert::IsTrue(moveAssignHere[2] == 8.0, L"moveAssignmentOperator3D");
}

void PhysicsVectorTests::additionOperator3D()
{
	PhysicsVector orig;
	orig.addDimension(5);
	orig.addDimension(10);
	orig.addDimension(2);

	PhysicsVector plus;
	plus.addDimension(1);
	plus.addDimension(2);
	plus.addDimension(25);

	PhysicsVector sum = orig + plus;

	Assert::IsTrue(sum[0] == 6.0, L"additionOperator3D");

	Assert::IsTrue(sum[1] == 12.0, L"additionOperator3D");

	Assert::IsTrue(sum[2] == 27.0, L"additionOperator3D");

	Assert::IsTrue(&sum[0] != &orig[0], L"additionOperator3D");

	Assert::IsTrue(&sum[1] != &orig[1], L"additionOperator3D");

	Assert::IsTrue(&sum[2] != &orig[2], L"additionOperator3D");

	Assert::IsTrue(&sum[0] != &plus[0], L"additionOperator3D");

	Assert::IsTrue(&sum[1] != &plus[1], L"additionOperator3D");

	Assert::IsTrue(&sum[2] != &plus[2], L"additionOperator3D");
}

void PhysicsVectorTests::subtractionOperator3D()
{
	PhysicsVector orig;
	orig.addDimension(5);
	orig.addDimension(10);
	orig.addDimension(6);

	PhysicsVector minus;
	minus.addDimension(1);
	minus.addDimension(2);
	minus.addDimension(3);

	PhysicsVector difference = orig - minus;

	Assert::IsTrue(difference[0] == 4.0, L"subtractionOperator3D");

	Assert::IsTrue(difference[1] == 8.0, L"subtractionOperator3D");

	Assert::IsTrue(difference[2] == 3.0, L"subtractionOperator3D");

	Assert::IsTrue(&difference[0] != &orig[0], L"subtractionOperator3D");

	Assert::IsTrue(&difference[1] != &orig[1], L"subtractionOperator3D");

	Assert::IsTrue(&difference[2] != &orig[2], L"subtractionOperator3D");

	Assert::IsTrue(&difference[0] != &minus[0], L"subtractionOperator3D");

	Assert::IsTrue(&difference[1] != &minus[1], L"subtractionOperator3D");

	Assert::IsTrue(&difference[2] != &minus[2], L"subtractionOperator3D");
}

void PhysicsVectorTests::multiplyOperator3D()
{
	PhysicsVector orig;
	orig.addDimension(5);
	orig.addDimension(10);
	orig.addDimension(15);

	PhysicsVector times;
	times.addDimension(2);
	times.addDimension(3);
	times.addDimension(1);

	PhysicsVector product = orig * times;

	Assert::IsTrue(product[0] == 10.0, L"multiply2Vector3sOperator3D");

	Assert::IsTrue(product[1] == 30.0, L"multiply2Vector3sOperator3D");

	Assert::IsTrue(product[2] == 15.0, L"multiply2Vector3sOperator3D");

	Assert::IsTrue(&product[0] != &orig[0], L"multiply2Vector3sOperator3D");

	Assert::IsTrue(&product[1] != &orig[1], L"multiply2Vector3sOperator3D");

	Assert::IsTrue(&product[2] != &orig[2], L"multiply2Vector3sOperator3D");

	Assert::IsTrue(&product[0] != &times[0], L"multiply2Vector3sOperator3D");

	Assert::IsTrue(&product[1] != &times[1], L"multiply2Vector3sOperator3D");

	Assert::IsTrue(&product[2] != &times[2], L"multiply2Vector3sOperator3D");
}

void PhysicsVectorTests::multiplyByDoubleOperator3D()
{
	PhysicsVector orig;
	orig.addDimension(5);
	orig.addDimension(10);
	orig.addDimension(6);

	double times = 2;

	PhysicsVector product = orig * times;

	Assert::IsTrue(product[0] == 10.0, L"multiplyVector3ByDouble3D");

	Assert::IsTrue(product[1] == 20.0, L"multiplyVector3ByDouble3D");

	Assert::IsTrue(product[2] == 12.0, L"multiplyVector3ByDouble3D");

	Assert::IsTrue(&product[0] != &orig[0], L"multiplyVector3ByDouble3D");

	Assert::IsTrue(&product[1] != &orig[1], L"multiplyVector3ByDouble3D");

	Assert::IsTrue(&product[2] != &orig[2], L"multiplyVector3ByDouble3D");
}

void PhysicsVectorTests::equivalenceOperators3D()
{
	PhysicsVector test;
	test.addDimension(50);
	test.addDimension(70);
	test.addDimension(60);

	PhysicsVector test2;
	test2.addDimension(50);
	test2.addDimension(70);
	test2.addDimension(60);

	PhysicsVector test3;
	test3.addDimension(50.0000000000000001);
	test3.addDimension(70.0000000000000001);
	test3.addDimension(60.0000000000000001);

	PhysicsVector test4;
	test4.addDimension(6);
	test4.addDimension(7);
	test4.addDimension(11);

	Assert::IsTrue(test == test2, L"equivalenceOperators3D");

	Assert::IsTrue(test == test3, L"equivalenceOperators3D");

	Assert::IsTrue(test != test4, L"equivalenceOperators3D");
}

void PhysicsVectorTests::dotProduct3D()
{
	PhysicsVector orig;
	orig.addDimension(5);
	orig.addDimension(10);
	orig.addDimension(3);

	PhysicsVector dot;
	dot.addDimension(2);
	dot.addDimension(3);
	dot.addDimension(4);

	double product = orig.dot(dot);

	Assert::IsTrue(product == 52.0, L"dotProduct3D");
}

void PhysicsVectorTests::magnitude3D()
{
	PhysicsVector test;
	test.addDimension(5);
	test.addDimension(10);
	test.addDimension(12);

	double magnitude = test.magnitude();

	Assert::IsTrue(magnitude == sqrt(269), L"magnitude3D");
}

void PhysicsVectorTests::magnitudeSquared3D()
{
	PhysicsVector test;
	test.addDimension(5);
	test.addDimension(10);
	test.addDimension(12);

	double magnitudeSq = test.magnitudeSquared();

	Assert::IsTrue(magnitudeSq == 269.0, L"magnitudeSquared3D");
}

void PhysicsVectorTests::divideOperator3D()
{
	PhysicsVector orig;
	orig.addDimension(6);
	orig.addDimension(10);
	orig.addDimension(9);

	PhysicsVector divisor;
	divisor.addDimension(2);
	divisor.addDimension(5);
	divisor.addDimension(3);

	PhysicsVector quotient = orig / divisor;

	Assert::IsTrue(quotient[0] == 3.0, L"divide2Vector3sOperator3D");

	Assert::IsTrue(quotient[1] == 2.0, L"divide2Vector3sOperator3D");

	Assert::IsTrue(quotient[2] == 3.0, L"divide2Vector3sOperator3D");

	Assert::IsTrue(&quotient[0] != &orig[0], L"divide2Vector3sOperator3D");

	Assert::IsTrue(&quotient[1] != &orig[1], L"divide2Vector3sOperator3D");

	Assert::IsTrue(&quotient[2] != &orig[2], L"divide2Vector3sOperator3D");

	Assert::IsTrue(&quotient[0] != &divisor[0], L"divide2Vector3sOperator3D");

	Assert::IsTrue(&quotient[1] != &divisor[1], L"divide2Vector3sOperator3D");

	Assert::IsTrue(&quotient[2] != &divisor[2], L"divide2Vector3sOperator3D");
}

void PhysicsVectorTests::divideByDoubleOperator3D()
{
	PhysicsVector orig;
	orig.addDimension(6);
	orig.addDimension(10);
	orig.addDimension(15);

	double divisor = 2;

	PhysicsVector quotient = orig / divisor;

	Assert::IsTrue(quotient[0] == 3.0, L"divideVector3ByDoubleOperator3D");

	Assert::IsTrue(quotient[1] == 5.0, L"divideVector3ByDoubleOperator3D");

	Assert::IsTrue(quotient[2] == 7.5, L"divideVector3ByDoubleOperator3D");

	Assert::IsTrue(&quotient[0] != &orig[0], L"divideVector3ByDoubleOperator3D");

	Assert::IsTrue(&quotient[1] != &orig[1], L"divideVector3ByDoubleOperator3D");

	Assert::IsTrue(&quotient[2] != &orig[2], L"divideVector3ByDoubleOperator3D");
}

void PhysicsVectorTests::additionShorthandOperator3D()
{
	PhysicsVector orig;
	orig.addDimension(5);
	orig.addDimension(10);
	orig.addDimension(19);

	PhysicsVector plus;
	plus.addDimension(1);
	plus.addDimension(2);
	plus.addDimension(1);

	orig += plus;

	Assert::IsTrue(orig[0] == 6.0, L"additionShorthandOperator3D");

	Assert::IsTrue(orig[1] == 12.0, L"additionShorthandOperator3D");

	Assert::IsTrue(orig[2] == 20.0, L"additionShorthandOperator3D");

	Assert::IsTrue(&orig[0] != &plus[0], L"additionShorthandOperator3D");

	Assert::IsTrue(&orig[1] != &plus[1], L"additionShorthandOperator3D");

	Assert::IsTrue(&orig[2] != &plus[2], L"additionShorthandOperator3D");
}

void PhysicsVectorTests::subtractionShorthandOperator3D()
{
	PhysicsVector orig;
	orig.addDimension(5);
	orig.addDimension(10);
	orig.addDimension(25);

	PhysicsVector minus;
	minus.addDimension(1);
	minus.addDimension(2);
	minus.addDimension(5);

	orig -= minus;

	Assert::IsTrue(orig[0] == 4.0, L"subtractionShorthandOperator3D");

	Assert::IsTrue(orig[1] == 8.0, L"subtractionShorthandOperator3D");

	Assert::IsTrue(orig[2] == 20.0, L"subtractionShorthandOperator3D");

	Assert::IsTrue(&orig[0] != &minus[0], L"subtractionShorthandOperator3D");

	Assert::IsTrue(&orig[1] != &minus[1], L"subtractionShorthandOperator3D");

	Assert::IsTrue(&orig[2] != &minus[2], L"subtractionShorthandOperator3D");
}

void PhysicsVectorTests::multiplyShorthandOperator3D()
{
	PhysicsVector orig;
	orig.addDimension(5);
	orig.addDimension(10);
	orig.addDimension(15);

	PhysicsVector times;
	times.addDimension(2);
	times.addDimension(2);
	times.addDimension(2);

	orig *= times;

	Assert::IsTrue(orig[0] == 10.0, L"multiply2Vector3sShorthandOperator3D");

	Assert::IsTrue(orig[1] == 20.0, L"multiply2Vector3sShorthandOperator3D");

	Assert::IsTrue(orig[2] == 30.0, L"multiply2Vector3sShorthandOperator3D");

	Assert::IsTrue(&orig[0] != &times[0], L"multiply2Vector3sShorthandOperator3D");

	Assert::IsTrue(&orig[1] != &times[1], L"multiply2Vector3sShorthandOperator3D");

	Assert::IsTrue(&orig[2] != &times[2], L"multiply2Vector3sShorthandOperator3D");
}

void PhysicsVectorTests::multiplyByDoubleShorthandOperator3D()
{
	PhysicsVector orig;
	orig.addDimension(5);
	orig.addDimension(10);
	orig.addDimension(30);

	double times = 2;

	orig *= times;

	Assert::IsTrue(orig[0] == 10.0, L"multiplyVector3ByDoubleShorthandOperator3D");

	Assert::IsTrue(orig[1] == 20.0, L"multiplyVector3ByDoubleShorthandOperator3D");

	Assert::IsTrue(orig[2] == 60.0, L"multiplyVector3ByDoubleShorthandOperator3D");
}

void PhysicsVectorTests::divideShorthandOperator3D()
{
	PhysicsVector orig;
	orig.addDimension(6);
	orig.addDimension(10);
	orig.addDimension(9);

	PhysicsVector divisor;
	divisor.addDimension(2);
	divisor.addDimension(5);
	divisor.addDimension(3);

	orig /= divisor;

	Assert::IsTrue(orig[0] == 3.0, L"divide2Vector3sShorthandOperator3D");

	Assert::IsTrue(orig[1] == 2.0, L"divide2Vector3sShorthandOperator3D");

	Assert::IsTrue(orig[2] == 3.0, L"divide2Vector3sShorthandOperator3D");

	Assert::IsTrue(&orig[0] != &divisor[0], L"divide2Vector3sShorthandOperator3D");

	Assert::IsTrue(&orig[1] != &divisor[1], L"divide2Vector3sShorthandOperator3D");

	Assert::IsTrue(&orig[2] != &divisor[2], L"divide2Vector3sShorthandOperator3D");
}

void PhysicsVectorTests::divideByDoubleShorthandOperator3D()
{
	PhysicsVector orig;
	orig.addDimension(6);
	orig.addDimension(10);
	orig.addDimension(20);

	double divisor = 2;

	orig /= divisor;

	Assert::IsTrue(orig[0] == 3.0, L"divideVector3ByDoubleShorthandOperator3D");

	Assert::IsTrue(orig[1] == 5.0, L"divideVector3ByDoubleShorthandOperator3D");

	Assert::IsTrue(orig[2] == 10.0, L"divideVector3ByDoubleShorthandOperator3D");
}

void PhysicsVectorTests::distance3D()
{
	PhysicsVector test;
	test.addDimension(5);
	test.addDimension(10);
	test.addDimension(20);

	PhysicsVector test2;
	test2.addDimension(7);
	test2.addDimension(3);
	test2.addDimension(6);

	double distance = test.distance(test2);

	double alsoDistance = test2.distance(test);

	Assert::IsTrue(distance == alsoDistance, L"distance3D");

	Assert::IsTrue(distance == sqrt(249.0), L"distance3D");
}

void PhysicsVectorTests::distanceSquared3D()
{
	PhysicsVector test;
	test.addDimension(5);
	test.addDimension(10);
	test.addDimension(20);

	PhysicsVector test2;
	test2.addDimension(7);
	test2.addDimension(3);
	test2.addDimension(6);

	double distance = test.distanceSquared(test2);

	double alsoDistance = test2.distanceSquared(test);

	Assert::IsTrue(distance == alsoDistance, L"distanceSquared3D");

	Assert::IsTrue(distance == 249.0, L"distanceSquared3D");
}

void PhysicsVectorTests::normalize3D()
{
	PhysicsVector test;
	test.addDimension(0);
	test.addDimension(10);
	test.addDimension(0);

	PhysicsVector test2;
	test2.addDimension(10);
	test2.addDimension(0);
	test2.addDimension(0);

	PhysicsVector test3;
	test3.addDimension(0);
	test3.addDimension(0);
	test3.addDimension(10);

	PhysicsVector test4;
	test4.addDimension(4);
	test4.addDimension(6);
	test4.addDimension(8);

	test.normalize();
	test2.normalize();
	test3.normalize();
	test4.normalize();

	Assert::IsTrue(0.0 == test[0], L"normalize3D");
	Assert::IsTrue(1.0 == test[1], L"normalize3D");
	Assert::IsTrue(0.0 == test[2], L"normalize3D");

	Assert::IsTrue(1.0 == test2[0], L"normalize3D");
	Assert::IsTrue(0.0 == test2[1], L"normalize3D");
	Assert::IsTrue(0.0 == test2[2], L"normalize3D");

	Assert::IsTrue(0.0 == test3[0], L"normalize3D");
	Assert::IsTrue(0.0 == test3[1], L"normalize3D");
	Assert::IsTrue(1.0 == test3[2], L"normalize3D");

	Assert::IsTrue(0.371 < test4[0], L"normalize3D");
	Assert::IsTrue(0.557 < test4[1], L"normalize3D");
	Assert::IsTrue(0.742 < test4[2], L"normalize3D");
	Assert::IsTrue(0.372 > test4[0], L"normalize3D");
	Assert::IsTrue(0.558 > test4[1], L"normalize3D");
	Assert::IsTrue(0.743 > test4[2], L"normalize3D");


	PhysicsVector test5;
	test5.addDimension(0);
	test5.addDimension(0);
	test5.addDimension(0);

	try
	{
		test5.normalize();
		Assert::IsTrue(false, L"normalize3D");
	}
	catch (std::logic_error e)
	{
		Assert::IsTrue(true, L"normalize3D");
	}
}

void PhysicsVectorTests::normalized3D()
{
	PhysicsVector test;
	test.addDimension(0);
	test.addDimension(10);
	test.addDimension(0);

	PhysicsVector test2;
	test2.addDimension(10);
	test2.addDimension(0);
	test2.addDimension(0);

	PhysicsVector test3;
	test3.addDimension(0);
	test3.addDimension(0);
	test3.addDimension(10);

	PhysicsVector test4;
	test4.addDimension(4);
	test4.addDimension(6);
	test4.addDimension(8);

	PhysicsVector test1Normalized = test.normalized();
	PhysicsVector test2Normalized = test2.normalized();
	PhysicsVector test3Normalized = test3.normalized();
	PhysicsVector test4Normalized = test4.normalized();

	Assert::IsTrue(0.0 == test1Normalized[0], L"normalized3D");
	Assert::IsTrue(1.0 == test1Normalized[1], L"normalized3D");
	Assert::IsTrue(0.0 == test1Normalized[2], L"normalized3D");

	Assert::IsTrue(1.0 == test2Normalized[0], L"normalized3D");
	Assert::IsTrue(0.0 == test2Normalized[1], L"normalized3D");
	Assert::IsTrue(0.0 == test2Normalized[2], L"normalized3D");

	Assert::IsTrue(0.0 == test3Normalized[0], L"normalized3D");
	Assert::IsTrue(0.0 == test3Normalized[1], L"normalized3D");
	Assert::IsTrue(1.0 == test3Normalized[2], L"normalized3D");

	Assert::IsTrue(0.371 < test4Normalized[0], L"normalized3D");
	Assert::IsTrue(0.557 < test4Normalized[1], L"normalized3D");
	Assert::IsTrue(0.742 < test4Normalized[2], L"normalized3D");
	Assert::IsTrue(0.372 > test4Normalized[0], L"normalized3D");
	Assert::IsTrue(0.558 > test4Normalized[1], L"normalized3D");
	Assert::IsTrue(0.743 > test4Normalized[2], L"normalized3D");


	PhysicsVector test5;
	test5.addDimension(0);
	test5.addDimension(0);
	test5.addDimension(0);

	try
	{
		PhysicsVector throwaway = test5.normalized();
		Assert::IsTrue(false, L"normalized3D");
	}
	catch (std::logic_error e)
	{
		Assert::IsTrue(true, L"normalized3D");
	}
}

void PhysicsVectorTests::project3D()
{
	PhysicsVector first = PhysicsVector();
	first.addDimension(3);
	first.addDimension(4);
	first.addDimension(-3);

	PhysicsVector second;
	second.addDimension(2);
	second.addDimension(0);
	second.addDimension(6);

	PhysicsVector projected = second.project(first);

	Assert::IsTrue(-18.0 / 17.0 == projected[0], L"project3D");
	Assert::IsTrue(-24.0 / 17.0 == projected[1], L"project3D");
	Assert::IsTrue(18.0 / 17.0 == projected[2], L"project3D");
}

void PhysicsVectorTests::outputOperator3D()
{
	PhysicsVector test;
	test.addDimension(55);
	test.addDimension(703);
	test.addDimension(5.5);

	std::stringstream out;

	out << test;

	std::string testText = "(55, 703, 5.5)";

	Assert::IsTrue(testText == out.str(), L"outputOperator3D");
}

void PhysicsVectorTests::perpendicular3D()
{
	PhysicsVector first;
	first.addDimension(5);
	first.addDimension(5);
	first.addDimension(11);

	PhysicsVector second = PhysicsVector();
	second.addDimension(-3);
	second.addDimension(2);
	second.addDimension(8);

	PhysicsVector perpendicular = first.perpendicular(second);

	Assert::IsTrue(8.3 > perpendicular[0], L"perpendicular3D");
	Assert::IsTrue(8.2 < perpendicular[0], L"perpendicular3D");

	Assert::IsTrue(2.9 > perpendicular[1], L"perpendicular3D");
	Assert::IsTrue(2.8 < perpendicular[1], L"perpendicular3D");

	Assert::IsTrue(2.4 > perpendicular[2], L"perpendicular3D");
	Assert::IsTrue(2.3 < perpendicular[2], L"perpendicular3D");

	PhysicsVector test2;
	test2.addDimension(10.0);
	test2.addDimension(0.0);
	test2.addDimension(0.0);
	PhysicsVector test3;
	test3.addDimension(5.0);
	test3.addDimension(5.0);
	test3.addDimension(5.0);

	PhysicsVector perpendicular2 = test3.perpendicular(test2);

	Assert::IsTrue(0.0 == perpendicular2[0], L"perpendicular3D");
	Assert::IsTrue(5.0 == perpendicular2[1], L"perpendicular3D");
	Assert::IsTrue(5.0 == perpendicular2[2], L"perpendicular3D");
}

void PhysicsVectorTests::angle3D()
{
	PhysicsVector first;
	first.addDimension(5);
	first.addDimension(5);
	first.addDimension(5);

	PhysicsVector second = PhysicsVector();
	second.addDimension(-5);
	second.addDimension(5);
	second.addDimension(5);

	double test1 = first.angle(second);

	Assert::IsTrue(70.52877 < test1, L"angle3D");
	Assert::IsTrue(70.52878 > test1, L"angle3D");

	PhysicsVector third;
	third.addDimension(2);
	third.addDimension(7);
	third.addDimension(3);

	PhysicsVector fourth = PhysicsVector();
	fourth.addDimension(-4);
	fourth.addDimension(-1);
	fourth.addDimension(-3);

	double test2 = third.angle(fourth);

	Assert::IsTrue(126.70982 < test2, L"angle3D");
	Assert::IsTrue(126.70983 > test2, L"angle3D");
}

void PhysicsVectorTests::reflect3D()
{
	PhysicsVector a;
	a.addDimension(5);
	a.addDimension(0);
	a.addDimension(5);

	PhysicsVector b;
	b.addDimension(0);
	b.addDimension(5);
	b.addDimension(0);

	PhysicsVector ab = a.reflect(b);

	PhysicsVector ba = b.reflect(a);

	Assert::IsTrue(-5.0 == ab[0], L"reflect3D");
	Assert::IsTrue(0.0 == ab[1], L"reflect3D");
	Assert::IsTrue(-5.0 == ab[2], L"reflect3D");
	Assert::IsTrue(0.0 == ba[0], L"reflect3D");
	Assert::IsTrue(-5.0 == ba[1], L"reflect3D");
	Assert::IsTrue(0.0 == ba[2], L"reflect3D");
}

void PhysicsVectorTests::crossProduct3D()
{
	PhysicsVector right;
	right.addDimension(5);
	right.addDimension(0);
	right.addDimension(0);
	PhysicsVector up;
	up.addDimension(0);
	up.addDimension(5);
	up.addDimension(0);
	PhysicsVector into;
	into.addDimension(0);
	into.addDimension(0);
	into.addDimension(25);

	Assert::IsTrue(into[0] == right.crossProduct(up)[0], L"crossProduct3D");
	Assert::IsTrue(into[1] == right.crossProduct(up)[1], L"crossProduct3D");
	Assert::IsTrue(into[2] == right.crossProduct(up)[2], L"crossProduct3D");
}

void PhysicsVectorTests::accessOperator()
{
	PhysicsVector test;
	test.addDimension(5);
	test.addDimension(6);
	test.addDimension(7);

	const double x = test[0];

	Assert::IsTrue(x == 5, L"accessOperator");

	test[1]++;

	double y = test[1];
	y++;

	Assert::IsTrue(y == 8, L"accessOperator");

}

void PhysicsVectorTests::getAndAddDimensions()
{
	PhysicsVector test;
	test.addDimension(5);
	test.addDimension(6);
	test.addDimension(7);

	Assert::IsTrue(test[1] == 5, L"getAndAddDimensions");
	Assert::IsTrue(test[1] == 5, L"getAndAddDimensions");
	Assert::IsTrue(test[1] == 5, L"getAndAddDimensions");

	Assert::IsTrue(test.getNumberOfDimensions() == 3, L"getAndAddDimensions");
}