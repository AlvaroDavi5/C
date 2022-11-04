#include "robo.h"
#include <math.h>

Robo::~Robo()
{
	// do nothing
}

void Robo::DesenhaRect(GLint height, GLint width, GLfloat R, GLfloat G, GLfloat B)
{
	const GLfloat posX = -(width / 2.0), posY = 0;
	const GLfloat finalPosX = posX + width, finalPosY = posY + height;

	glColor3f(R, G, B);

	glBegin(GL_POLYGON);
	glVertex3f(posX, posY, 0.0);
	glVertex3f(finalPosX, posY, 0.0);
	glVertex3f(finalPosX, finalPosY, 0.0);
	glVertex3f(posX, finalPosY, 0.0);
	glEnd();
}

void Robo::DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B)
{
	const int lineAmount = 18; // 360/20=18
	const GLfloat twicePi = 2.0f * 3.1415;

	glColor3f(R, G, B);

	glBegin(GL_LINE_LOOP);
	for (int i = 1; i <= lineAmount; i++)
	{
		glVertex3f(
				(radius * cos(i * twicePi / lineAmount)),
				(radius * sin(i * twicePi / lineAmount)),
				0.0);
	}
	glEnd();
}

void Robo::DesenhaRoda(GLfloat x, GLfloat y, GLfloat thetaWheel, GLfloat R, GLfloat G, GLfloat B)
{
	glPushMatrix();
	glTranslatef(x, y, 0.0);
	glRotatef(thetaWheel, 0, 0, 1);
	DesenhaCirc(20, R, G, B);
	glPopMatrix();
}

void Robo::DesenhaBraco(GLfloat x, GLfloat y, GLfloat theta1, GLfloat theta2, GLfloat theta3)
{
	// haste 1
	glTranslatef(x, y, 0.0);
	glRotatef(theta1, 0, 0, 1);
	DesenhaRect(paddleHeight, paddleWidth, 0.0, 0.0, 1.0);

	// haste 2
	glTranslatef(0.0, paddleHeight, 0.0);
	glRotatef(theta2, 0, 0, 1);
	DesenhaRect(paddleHeight, paddleWidth, 1.0, 1.0, 0.0);

	// haste 3
	glTranslatef(0.0, paddleHeight, 0.0);
	glRotatef(theta3, 0, 0, 1);
	DesenhaRect(paddleHeight, paddleWidth, 0.0, 1.0, 0.0);
}

void Robo::DesenhaRobo(GLfloat x, GLfloat y, GLfloat thetaWheel, GLfloat theta1, GLfloat theta2, GLfloat theta3)
{
	glPushMatrix();
	glTranslatef(x, y, 0.0);
	DesenhaRect(baseHeight, baseWidth, 1.0, 0.0, 0.0);
	DesenhaBraco(0.0, baseHeight, theta1, theta2, theta3);
	glPopMatrix();

	DesenhaRoda(x - (baseWidth / 2.0), y, thetaWheel, 1.0, 1.0, 1.0);
	DesenhaRoda(x + (baseWidth / 2.0), y, thetaWheel, 1.0, 1.0, 1.0);
}

void Robo::RodaBraco1(GLfloat inc)
{
	this->gTheta1 += inc;
}

void Robo::RodaBraco2(GLfloat inc)
{
	this->gTheta2 += inc;
}

void Robo::RodaBraco3(GLfloat inc)
{
	this->gTheta3 += inc;
}

void Robo::MoveEmX(GLfloat dx)
{
	this->gX += dx;
	this->gThetaWheel += dx / -0.2;
}

float DegreeToRadian(float deg)
{
	const float rad = (deg * M_PI) / 180.0;

	return rad;
}

float RadianToDegree(float rad)
{
	const float deg = (rad * 180.0) / M_PI;

	return deg;
}

void RotatePoint(GLfloat x, GLfloat y, GLfloat angle, GLfloat &xOut, GLfloat &yOut)
{
	float s = sin(angle), c = cos(angle);

	xOut = x + ((xOut - x) * c - (yOut - y) * s);
	yOut = y + ((xOut - x) * s + (yOut - y) * c);
}

Tiro *Robo::Atira()
{
	float basePoint[2] = {this->gX, this->gY + baseHeight};
	RotatePoint(basePoint[0], paddleHeight,
							DegreeToRadian(90 + this->gTheta1),
							basePoint[0], basePoint[1]);
	RotatePoint(basePoint[0], paddleHeight,
							DegreeToRadian(90 + this->gTheta2),
							basePoint[0], basePoint[1]);

	float topPoint[2] = {basePoint[0], basePoint[1]};
	RotatePoint(topPoint[0], paddleHeight,
							DegreeToRadian(90 + this->gTheta3),
							topPoint[0], topPoint[1]);

	float dirVect[2] = {
			topPoint[0] - basePoint[0],
			topPoint[1] - basePoint[1]};
	float dirAngle = atan2(dirVect[1], dirVect[0]);

	cout << " angle: " << RadianToDegree(dirAngle) << " cos: " << cos(dirAngle) << " sin: " << sin(dirAngle) << '\n'
			 << " diff X: " << dirVect[0] << '\t' << "diff Y: " << dirVect[1] << '\n'
			 << " X: " << topPoint[0] << " Y: " << topPoint[1] << endl;

	Tiro *tiro = new Tiro(dirVect[0], dirVect[1], dirAngle);

	return tiro;
}
