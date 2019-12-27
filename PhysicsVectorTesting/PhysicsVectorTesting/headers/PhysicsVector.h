//Cody Ware
//9/24/18

#pragma once  

#include <iostream>
#include <string>
#include "PhysicsHelper.h"
#include "Matrix.h"

enum Axis { X, Y, Z };

class  PhysicsVector
{
public:

	PhysicsVector();
	PhysicsVector(double* dimensionValues, const size_t& numberOfDimensions);
	PhysicsVector(const PhysicsVector& other);
	PhysicsVector(PhysicsVector&& other);
	PhysicsVector& operator=(const PhysicsVector& other);
	PhysicsVector& operator=(PhysicsVector&& other);
	~PhysicsVector();

	double& operator[](const size_t& i) const;
	PhysicsVector operator+(const PhysicsVector& r) const;
	PhysicsVector operator-(const PhysicsVector& r) const;
	PhysicsVector operator*(const PhysicsVector& r) const;
	PhysicsVector operator*(const double& r) const;
	PhysicsVector operator*(const Matrix& mat) const;
	PhysicsVector operator/(const PhysicsVector& r) const;
	PhysicsVector operator/(const double& r) const;
	PhysicsVector& operator+=(const PhysicsVector& r);
	PhysicsVector& operator-=(const PhysicsVector& r);
	PhysicsVector& operator*=(const PhysicsVector& r);
	PhysicsVector& operator*=(const Matrix& mat);
	PhysicsVector& operator*=(const double& r);
	PhysicsVector& operator/=(const PhysicsVector& r);
	PhysicsVector& operator/=(const double& r);
	bool operator==(const PhysicsVector& r) const;
	bool operator!=(const PhysicsVector& r) const;

	double dot(const PhysicsVector& r) const;
	double magnitude() const;
	double magnitudeSquared() const;
	double distance(const PhysicsVector& other) const;
	double distanceSquared(const PhysicsVector& other) const;

	PhysicsVector rotate2D(const double& degrees) const;
	PhysicsVector rotate3D(const double& degrees, Axis axis) const;
	PhysicsVector crossProduct(const PhysicsVector& other) const;
	
	void normalize();
	PhysicsVector normalized() const;
	double angle(const PhysicsVector& other) const;
	PhysicsVector project(const PhysicsVector& direction) const;
	PhysicsVector perpendicular(const PhysicsVector& direction) const;
	PhysicsVector reflect(const PhysicsVector& normal) const;

	size_t getNumberOfDimensions() const;
	void addDimension(const double& newDimensionValue);

private:
	void deepCopy(const PhysicsVector& other);

	double* dimensionValues_;
	size_t numberOfDimensions_;
};

std::ostream& operator<<(std::ostream& os, const PhysicsVector & v);
