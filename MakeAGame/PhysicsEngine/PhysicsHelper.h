//Cody Ware
//10/4/18 

#pragma once  

#ifndef PHYSICSENGINE_EXPORTS
#define PHYSICSENGINE __declspec(dllexport)
#else
#define PHYSICSENGINE __declspec(dllimport)
#endif

class PHYSICSENGINE PhysicsHelper
{
public:
	//helper functions
	static double radiansToDegrees(double radians);
	static double degreesToRadians(double degrees);
	static double correctDegrees(double degrees);
	static bool epsilonCompare(double a, double b);

private:
	PhysicsHelper();
	static const int HALF_CIRCLE_IN_DEGREES = 180;
};