// Base code written by Jan Allbeck, Chris Czyzewicz, Cory Boatright, Tiantian Liu, Benedict Brown, and Adam Mally
// University of Pennsylvania

// At least some C++ compilers do funny things
// to C's math.h header if you don't define this
#define _USE_MATH_DEFINES

#include "vec4.h"
#include "mat4.h"
#include <iostream>
#include <math.h>
using namespace std;

void vec4AddTest() {

	vec4 a = vec4(1.f, 2.f, 3.f, 4.f);
	vec4 b = vec4(2.f, 4.f, 6.f, 8.f);

    std::cout << "vec4AddTest \n";
    std::cout << "\t expected value: \t3.00, 6.00, 9.00, 12.00" << std::endl;
    std::cout << "\t actual value: " << (a + b) << std::endl;
}



void vec4ConstructorDefaultTest() {

    vec4 a = vec4();

    std::cout << "vec4ConstructorDefaultTest \n";
    std::cout << "\t expected value: \t0.00, 0.00, 0.00, 0.00" << std::endl;
    std::cout << "\t actual value: " << a << std::endl;
}

void vec4ConstructorParameterizedTest() {

    vec4 a = vec4(1.2f, 3.f, 5.f, 7.8f); // f suffix makes it float literal instead of double literal

    std::cout << "vec4ConstructorParameterizedTest \n";
    std::cout << "\t expected value: \t1.20, 3.00, 5.00, 7.80" << std::endl;
    std::cout << "\t actual value: " << a << std::endl;
}


void vec4ConstructorCopyTest() {

    vec4 a = vec4(1.2f, 3.f, 5.f, 7.8f);

    vec4 b = vec4(a); // Explit use of copy constructor

    vec4 c(a); // Implicit use of copy constructor

    std::cout << "vec4ConstructorParameterizedTest \n";
    std::cout << "\t expected value (explicit): \t1.20, 3.00, 5.00, 7.80" << std::endl;
    std::cout << "\t actual value (explicit): " << b << std::endl;
    std::cout << "\t expected value (implicit): \t1.20, 3.00, 5.00, 7.80" << std::endl;
    std::cout << "\t actual value (implicit): " << c << std::endl;
}

void vec4OperatorOstreamTest() {

    vec4 a = vec4(1.2f, 3.f, 5.f, 7.8f);

    std::cout << "vec4OperatorOstreamTest \n";
    std::cout << "\t expected output: \t1.20, 3.00, 5.00, 7.80" << std::endl;
    std::cout << "\t actual output:" << a << std::endl;
}

void vec4OperatorEqualsTest() {

    vec4 a = vec4(1.2f, 3.f, 5.f, 7.8f);

    vec4 b = a;

    std::cout << "vec4OperatorEqualsTest \n";
    std::cout << "\t expected output: \t" << a << std::endl;
    std::cout << "\t actual output: \t" << b << std::endl;
}

void vec4OperatorEqualityTest() {

    vec4 twin1 = vec4(1.2f, 3.f, 5.f, 7.8f);

    vec4 twin2 = vec4(1.2f, 3.f, 5.f, 7.8f);

    vec4 someGuy = vec4(0.0f, 5.f, 5.7f, 1.f);

    std::cout << "vec4OperatorEqualityTest \n";
    std::cout << "twin1 == twin2 \n"
                 "\t expected value: \t1 \n"
                 "\t actual value: \t" << (twin1 == twin2) << std::endl;
    std::cout << "twin1 == someGuy \n"
                 "\t expected value: \t0 \n"
                 "\t actual value: \t" << (twin1 == someGuy) << std::endl;
}

void vec4OperatorUnequalityTest() {

    vec4 twin1 = vec4(1.2f, 3.f, 5.f, 7.8f);

    vec4 twin2 = vec4(1.2f, 3.f, 5.f, 7.8f);

    vec4 someGuy = vec4(0.0f, 5.f, 5.7f, 1.f);

    std::cout << "vec4OperatorUnequalityTest \n";
    std::cout << "twin1 == twin2 \n"
                 "\t expected value: \t0 \n"
                 "\t actual value: \t" << (twin1 != twin2) << std::endl;
    std::cout << "twin1 == someGuy \n"
                 "\t expected value: \t1 \n"
                 "\t actual value: \t" << (twin1 != someGuy) << std::endl;
}

void vec4DotProductTest() {

    vec4 a = vec4(0.f, 1.f, 2.f, 10.f);

    vec4 b = vec4(2.f, 2.f, 2.f, 2.f);

    float c = dot(a, b);

    std::cout << "vec4DotProductTest \n";
    std::cout << "\t expected: \t26.00" << std::endl;
    std::cout << "\t actual: \t\t" << c << std::endl;
}


void vec4CrossProductTest() {

    vec4 a = vec4(0.f, 1.f, 2.f, 10.f);

    vec4 b = vec4(2.f, 2.f, 2.f, 2.f);

    vec4 c = cross(a, b);

    std::cout << "vec4CrossProductTest \n";
    std::cout << "\t expected: \t-2.00, 4.00, -2.00, 0.00" << std::endl;
    std::cout << "\t actual: \t" << c << std::endl;
}



void vec4NormalizeTest() {

    vec4 a = vec4(0.f, 1.f, 2.f, 10.f);

    std::cout << "vec4DotProductTest \n";
    std::cout << "length: \n";
    std::cout << "\t expected output: \t1.00" << std::endl;
    std::cout << "\t actual output:\t " << length(normalize(a)) << std::endl;

    std::cout << "direction: \n" << std::endl;
    std::cout << "\t expected output: " << (a / length(a)) << std::endl;
    std::cout << "\t actual output: " << (normalize(a) / length(normalize(a))) << std::endl;
}










void mat4ConstructorDefaultTest() {

    std::cout << "\n\n\n" << std::endl;

    mat4 a = mat4();

    std::cout << "mat4ConstructorDefaultTest \n"
                 "\t expected value: \n"
                 "\t 1.00, 0.00, 0.00, 0.00\n"
                 "\t 0.00, 1.00, 0.00, 0.00\n"
                 "\t 0.00, 0.00, 1.00, 0.00\n"
                 "\t 0.00, 0.00, 0.00, 1.00\n" << std::endl;
    std::cout << "\t actual value: \n" << a << std::endl;
}




void mat4ConstructorParameterizedTest() {

    vec4 a = vec4(1.2f, 2.2f, 0.2f, 2.2f);
    vec4 b = vec4(3.f, 10.f, 0.f, 10.f);
    vec4 c = vec4(5.f, 5.f, 0.f, 5.f);
    vec4 d = vec4(7.8f, 0.8f, 0.8f, 0.8f);

    mat4 m = mat4(a, b, c, d);


    std::cout << "mat4ConstructorParameterizedTest \n"
                 "\t expected value: \n"
                 "\t 1.20, 3.00, 5.00, 7.80\n"
                 "\t 2.20, 10.00, 5.00, 0.80\n"
                 "\t 0.20, 0.00, 0.00, 0.80\n"
                 "\t 2.20, 10.00, 5.00, 0.80\n"
                 "\t actual value: \n" << m << std::endl;
}


void mat4ConstructorCopyTest() {

    vec4 a = vec4(1.2f, 2.2f, 0.2f, 2.2f);
    vec4 b = vec4(3.f, 10.f, 0.f, 10.f);
    vec4 c = vec4(5.f, 5.f, 0.f, 5.f);
    vec4 d = vec4(7.8f, 0.8f, 0.8f, 0.8f);

    mat4 m = mat4(a, b, c, d);

    mat4 x = mat4(m); // Explit use of copy constructor

    mat4 y(m); // Implicit use of copy constructor

    std::cout << "mat4ConstructorCopyTest \n"
                 "\t expected value: \n"
                 "\t 1.20, 3.00, 5.00, 7.80\n"
                 "\t 2.20, 10.00, 5.00, 0.80\n"
                 "\t 0.20, 0.00, 0.00, 0.80\n"
                 "\t 2.20, 10.00, 5.00, 0.80\n"
                 "\t actual value (explicit copy): \n" << x << std::endl;
    std::cout << "\t actual value (implicit copy): \n" << y << std::endl;
}


void mat4ConstructorDiagTest() {

    mat4 a = mat4(4.20);

    std::cout << "mat4ConstructorDiagTest \n"
                 "\t expected value: \n"
                 "\t 4.20, 0.00, 0.00, 0.00\n"
                 "\t 0.00, 4.20, 0.00, 0.00\n"
                 "\t 0.00, 0.00, 4.20, 0.00\n"
                 "\t 0.00, 0.00, 0.00, 4.20\n" << std::endl;
    std::cout << "\t actual value: \n" << a << std::endl;
}



void mat4OperatorOstreamTest() {

    vec4 a = vec4(1.2f, 2.2f, 0.2f, 2.2f);
    vec4 b = vec4(3.f, 10.f, 0.f, 10.f);
    vec4 c = vec4(5.f, 5.f, 0.f, 5.f);
    vec4 d = vec4(7.8f, 0.8f, 0.8f, 0.8f);

    mat4 m = mat4(a, b, c, d);

    std::cout << "mat4OperatorOstreamTest \n"
                 "\t expected value: \n"
                 "\t 1.20, 3.00, 5.00, 7.80\n"
                 "\t 2.20, 10.00, 5.00, 0.80\n"
                 "\t 0.20, 0.00, 0.00, 0.80\n"
                 "\t 2.20, 10.00, 5.00, 0.80\n"
                 "\t actual value: \n" << m << std::endl;
}

void mat4OperatorEqualsTest() {

    vec4 a = vec4(1.2f, 2.2f, 0.2f, 2.2f);
    vec4 b = vec4(3.f, 10.f, 0.f, 10.f);
    vec4 c = vec4(5.f, 5.f, 0.f, 5.f);
    vec4 d = vec4(7.8f, 0.8f, 0.8f, 0.8f);

    mat4 m = mat4(a, b, c, d);

    mat4 m2 = m;

    std::cout << "mat4OperatorEqualsTest \n"
                 "\t expected value: \n"
                 "\t 1.20, 3.00, 5.00, 7.80\n"
                 "\t 2.20, 10.00, 5.00, 0.80\n"
                 "\t 0.20, 0.00, 0.00, 0.80\n"
                 "\t 2.20, 10.00, 5.00, 0.80\n"
                 "\t actual value: \n" << m2 << std::endl;
}

void mat4OperatorEqualityTest() {

    vec4 a = vec4(1.2f, 2.2f, 0.2f, 2.2f);
    vec4 b = vec4(3.f, 10.f, 0.f, 10.f);
    vec4 c = vec4(5.f, 5.f, 0.f, 5.f);
    vec4 d = vec4(7.8f, 0.8f, 0.8f, 0.8f);

    mat4 twin1 = mat4(a, b, c, d);

    vec4 a2 = vec4(1.2f, 2.2f, 0.2f, 2.2f);
    vec4 b2 = vec4(3.f, 10.f, 0.f, 10.f);
    vec4 c2 = vec4(5.f, 5.f, 0.f, 5.f);
    vec4 d2 = vec4(7.8f, 0.8f, 0.8f, 0.8f);

    mat4 twin2 = mat4(a2, b2, c2, d2);

    mat4 someGuy = mat4();

    std::cout << "mat4OperatorEqualityTest \n";
    std::cout << "\t twin1 == twin2 (should be true=1): \t" << (twin1 == twin2) << std::endl;
    std::cout << "\t twin1 == someGuy (should be false=0): \t" << (twin1 == someGuy) << std::endl;
}

void mat4OperatorUnequalityTest() {

    vec4 a = vec4(1.2f, 2.2f, 0.2f, 2.2f);
    vec4 b = vec4(3.f, 10.f, 0.f, 10.f);
    vec4 c = vec4(5.f, 5.f, 0.f, 5.f);
    vec4 d = vec4(7.8f, 0.8f, 0.8f, 0.8f);

    mat4 twin1 = mat4(a, b, c, d);

    vec4 a2 = vec4(1.2f, 2.2f, 0.2f, 2.2f);
    vec4 b2 = vec4(3.f, 10.f, 0.f, 10.f);
    vec4 c2 = vec4(5.f, 5.f, 0.f, 5.f);
    vec4 d2 = vec4(7.8f, 0.8f, 0.8f, 0.8f);

    mat4 twin2 = mat4(a2, b2, c2, d2);

    mat4 someGuy = mat4();

    std::cout << "mat4OperatorUnequalityTest \n";
    std::cout << "\t twin1 != twin2 (should be false=0): \t" << (twin1 != twin2) << std::endl;
    std::cout << "\t twin1 != someGuy (should be true=1): \t" << (twin1 != someGuy) << std::endl;
}





void mat4RotateTest() {

    // Rotate 0 degrees (about x)
    mat4 m0deg = mat4::rotate(0.0, 1.0, 0.0, 0.0);

    // Rotate 74.5 degrees about y
    mat4 m745deg = mat4::rotate(74.5, 0.0, 1.0, 0.0);

    std::cout << "mat4RotateTest \n";
    std::cout << "mat4 m0deg \n"
                 "\t expected value: \n"
                 "\t 1.00, 0.00, 0.00, 0.00\n"
                 "\t 0.00, 1.00, 0.00, 0.00\n"
                 "\t 0.00, 0.00, 1.00, 0.00\n"
                 "\t 0.00, 0.00, 0.00, 1.00\n"
                 "\t actual value: \n" << m0deg << std::endl;
    std::cout << "mat4 m745deg \n"
                 "\t expected value: \n"
                 "\t 0.27, 0.00, 0.96, 0.00\n"
                 "\t 0.00, 1.00, 0.00, 0.00\n"
                 "\t -0.96, 0.00, 0.27, 0.00\n"
                 "\t 0.00, 0.00, 0.00, 1.00\n"
                 "\t actual value: \n" << m745deg << std::endl;
}

void mat4MatrixMultiplyTest() {

    vec4 a = vec4(1.2f, 2.2f, 0.2f, 2.2f);
    vec4 b = vec4(3.f, 10.f, 0.f, 10.f);
    vec4 c = vec4(5.f, 5.f, 0.f, 5.f);
    vec4 d = vec4(7.8f, 0.8f, 0.8f, 0.8f);

    mat4 m = mat4(a, b, c, d);

    std::cout << "mat4MatrixMultiplyTest \n";
    std::cout << "\t expected value: \n"
                 "\t 26.20, 111.60, 60.00, 22.00\n"
                 "\t 27.40, 114.60, 65.00, 29.80\n"
                 "\t 2.00, 8.60, 5.00, 2.20\n"
                 "\t 27.40, 114.60, 65.00, 29.80\n"
                 "\t actual value: \n" << m * m << std::endl;
}

void mat4MatrixVectorMultiplyTest() {

    vec4 a = vec4(1.2f, 2.2f, 0.2f, 2.2f);
    vec4 b = vec4(3.f, 10.f, 0.f, 10.f);
    vec4 c = vec4(5.f, 5.f, 0.f, 5.f);
    vec4 d = vec4(7.8f, 0.8f, 0.8f, 0.8f);

    mat4 m = mat4(a, b, c, d);

    std::cout << "mat4MatrixVectorMultiplyTest \n";


    std::cout << "\t expected value: \n"
                 "\t 26.20, 27.40, 2.00, 27.40\n"
                 "\t actual value: \n" << m * a << std::endl;
}



void mat4VectorMatrixMultiplyTest() {

    vec4 a = vec4(1.2f, 2.2f, 0.2f, 2.2f);
    vec4 b = vec4(3.f, 10.f, 0.f, 10.f);
    vec4 c = vec4(5.f, 5.f, 0.f, 5.f);
    vec4 d = vec4(7.8f, 0.8f, 0.8f, 0.8f);

    mat4 m = mat4(a, b, c, d);

    std::cout << "mat4VectorMatrixMultiplyTest \n";


    std::cout << "\t expected value: \n"
                 "\t 11.60, 47.60, 28.00, 13.04\n"
                 "\t actual value: \n" << a * m << std::endl;
}


int main() {
	// Example test (won't work until you implement vec4's operator+ and operator<<)
	vec4AddTest();
	// Add your own tests here

    vec4ConstructorDefaultTest();
    vec4ConstructorParameterizedTest();
    vec4ConstructorCopyTest();
    vec4OperatorOstreamTest();
    vec4OperatorEqualsTest();
    vec4OperatorEqualityTest();
    vec4OperatorUnequalityTest();
    vec4DotProductTest();
    vec4CrossProductTest();
    vec4NormalizeTest();



    mat4ConstructorDefaultTest();
    mat4ConstructorParameterizedTest();
    mat4ConstructorCopyTest();
    mat4ConstructorDiagTest();
    mat4OperatorOstreamTest();
    mat4OperatorEqualsTest();
    mat4OperatorEqualityTest();
    mat4OperatorUnequalityTest();
    mat4RotateTest();
    mat4MatrixMultiplyTest();
    mat4MatrixVectorMultiplyTest();
    mat4VectorMatrixMultiplyTest();

}
