#include <GL/glut.h>
#include <time.h>
#include <cstdlib>
#include "scene.h"
#include "castle.h"
#include "character.h"
#include "algorithm"
#include <string>

float char1_x = 0;
float char2_x = 0;
float dragon_x = 0;

int scene1()
{
	glClearColor(0.2, 0.6, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Drawing grass
	glColor3f(0.678, 1.0, 0.184);
	glBegin(GL_QUADS);
	glVertex2f(-20.0, 0.0);
	glVertex2f(-20.0, -20.0);
	glVertex2f(20.0, -20.0);
	glVertex2f(20.0, 0.0);
	glEnd();

	//Drawing castle
	glLoadIdentity();
	glPushMatrix();
		glScalef(2.0, 2.0, 2.0);
		glTranslatef(-1.0, -2.0, 0.0);
		drawCastle();
	glPopMatrix();

	drawSun(18.0, 18.0, 3.5);

	//Drawing character1
	glPushMatrix();
	glTranslatef(-15.0 + char1_x * 0.1, -6.0, 0.0);
	glScalef(1.25, 1.25, 1.25);
	drawCharacter1();
	glPopMatrix();

	//Drawing character2
	glPushMatrix();
	glTranslatef(-10.0 + char2_x * 0.1, -6.0, 0.0);
	glScalef(1.25, 1.25, 1.25);
	drawCharacter2();
	glPopMatrix();


	glutSwapBuffers();

	if (char1_x == 100) {
		return 1;
	}
	
	char1_x += 1;
	char2_x += 1;

	return 0;
}

int scene2()
{
	glClearColor(0.0, 0.0, 0.6, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	// Drawing grass
	glColor3f(0.678, 1.0, 0.184);
	glBegin(GL_POLYGON);
	glVertex2f(-20.0, 6.0);
	glVertex2f(-20.0, -20.0);
	glVertex2f(20.0, -20.0);
	glVertex2f(20.0, 6.0);

	glEnd();

	// Drawing a very big moon
	drawMoon(0.0, 28.0, 20.0);

	// Drawing the castle
	glPushMatrix();
		glScalef(0.5, 0.5, 0.5);
		glTranslatef(-17.0, 4.0, 0.0);
		drawCastle();
	glPopMatrix();
	

	// Drawing the dragon
	int verticalP = 7.0 - dragon_x * 0.075;
	if(verticalP < -5.0)
		verticalP = -5.0;
	glPushMatrix();
		glScalef(-1.0, 1.0, 1.0);
		drawDragon(-13.0 + dragon_x * 0.05, verticalP, 2.5);
	glPopMatrix();

	dragon_x += 1.0f;
	glutSwapBuffers();
	if (dragon_x >= 100) {
		return 1;
	}

	return 0;
	
}

int scene3()
{
	srand(240);
	glClearColor(0.678, 1.0, 0.184, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	
	glPushMatrix();
	glTranslatef(10.0, 9.0, 0.0);
	drawDragonMouth(0.0, 0.0, 1.0, 40.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(11.8, 9.0, 0.0);
	drawFireball(0.0, 0.0, 1.0, 230.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15.0, 15.0, 0.0);
	glScalef(0.8, 0.8, 0.8);
	drawCastle();
	glPopMatrix();


	drawTree(-4.0, -3.0, 1.0);
	drawTree(16.0, 5.0, 1.0);
	drawTree(4.0, 17.0, 1.0);
	drawTree(-8.0, -7.0, 1.0);
	drawTree(-14.0, 6.0, 1.0);

	drawFlame(rand() % 41 - 20, rand() % 41 - 20, (rand() % 10) + 1.0);
	drawFlame(rand() % 41 - 20, rand() % 41 - 20, (rand() % 10) + 1.0);
	drawFlame(rand() % 41 - 20, rand() % 41 - 20, (rand() % 10) + 1.0);
	drawFlame(rand() % 41 - 20, rand() % 41 - 20, (rand() % 10) + 1.0);
	drawFlame(rand() % 41 - 20, rand() % 41 - 20, (rand() % 10) + 1.0);

	glPushMatrix();
	glTranslatef(-5.0 + char1_x * 0.02, -8.0, 0.0);
	glScalef(0.5, 0.5, 0.5);
	drawCharacter1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(7.0 + char2_x * 0.01, -4.0, 0.0);
	glScalef(0.5, 0.5, 0.5);
	drawCharacter2();
	glPopMatrix();


	glutSwapBuffers();

	if (char2_x >= 600) {
		return 1;
	}
	
	char2_x += 10.0f;
	char1_x -= 10.0f;

	return 0;

}

int scene4()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	int count = 0;
	while (count < 10000) {
		count++;
	}
	


	glutSwapBuffers();
	return 1;
}

int scene5()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glutSwapBuffers();
	return 1;
}

int scene6()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glutSwapBuffers();
	return 1;
}

int scene7()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glutSwapBuffers();
	return 1;
}

int scene8()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glutSwapBuffers();
	return 1;
}

int scene9()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glutSwapBuffers();
	return 1;
}

int scene10()
{
	// Sky and ground setup
glClearColor(0.6f, 0.8f, 1.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();

// Green ground
glColor3f(0.4f, 0.7f, 0.3f);
glBegin(GL_QUADS);
glVertex2f(-20.0f, 0.0f);
glVertex2f(-20.0f, -20.0f);
glVertex2f(20.0f, -20.0f);
glVertex2f(20.0f, 0.0f);
glEnd();

// ADDED TREES (from Scene 3) ----------------------------------------
drawTree(-14.0f, -3.0f, 1.2f);  // Left background
drawTree(-16.0f, -1.0f, 0.9f);  // Left midground
drawTree(15.0f, -2.0f, 1.1f);   // Right background
drawTree(18.0f, -1.5f, 0.8f);   // Right midground

// DEFEATED DRAGON --------------------------------------------------
glPushMatrix();
glTranslatef(12.0f, -6.0f, 0.0f);
glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
glScalef(1.8f, 1.8f, 1.0f);
drawDragon(0.0f, 0.0f, 1.0f);

// Giant X eyes
glColor3f(1.0f, 0.0f, 0.0f);
glLineWidth(4.0f);
glBegin(GL_LINES);
// Left eye X
glVertex2f(3.0f, 1.0f); glVertex2f(4.0f, 0.4f);
glVertex2f(3.0f, 0.4f); glVertex2f(4.0f, 1.0f);
// Right eye X
glVertex2f(3.0f, 0.3f); glVertex2f(4.0f, -0.3f);
glVertex2f(3.0f, -0.3f); glVertex2f(4.0f, 0.3f);
glEnd();
glPopMatrix();

// VICTORIOUS HEROES ------------------------------------------------
// Hero 1 (jumping)
float jumpHeight = sin(frame * 0.2f) * 0.8f;
glPushMatrix();
glTranslatef(-9.0f, -5.0f + jumpHeight, 0.0f);
glScalef(2.0f, 2.0f, 1.0f);
drawCharacter1();
glPopMatrix();

// Hero 2 
glPushMatrix();
glTranslatef(-4.0f, -5.0f, 0.0f);
glScalef(2.0f, 2.0f, 1.0f);
drawCharacter2();
glPopMatrix();

// ENHANCED VICTORY TEXT --------------------------------------------
glColor3f(1.0f, 0.9f, 0.0f); // Brighter gold color
std::string victoryText = "VICTORY!";

// Calculate centered position (now 20% larger)
float textWidth = victoryText.length() * 1.2f;
glRasterPos2f(-textWidth / 2, 9.0f); // Higher position

// Draw each character with spacing (using larger font)
for (char c : victoryText) {
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
}

glutSwapBuffers();
}

int scene11()
{
	// Sky background
glClearColor(0.7f, 0.9f, 1.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();

// Ground
glColor3f(0.5f, 0.7f, 0.3f);
glBegin(GL_QUADS);
glVertex2f(-20.0f, 0.0f);
glVertex2f(-20.0f, -20.0f);
glVertex2f(20.0f, -20.0f);
glVertex2f(20.0f, 0.0f);
glEnd();

// Background trees
drawTree(-18.0f, -4.0f, 2.5f);
drawTree(10.0f, 10.0f, 3.0f);

// Castle
glPushMatrix();
glTranslatef(0.0f, -5.0f, 0.0f);
glScalef(1.5f, 1.5f, 1.0f);
drawCastle();
glPopMatrix();

// KING AND VILLAGERS (always visible, waiting)
// King (center front)
glPushMatrix();
glTranslatef(0.0f, -7.0f, 0.0f);
glScalef(1.2f, 1.2f, 1.0f);

// Body (royal purple robe)
glColor3f(0.5f, 0.1f, 0.8f);
glBegin(GL_QUADS);
glVertex2f(-1.5f, 2.5f);
glVertex2f(1.5f, 2.5f);
glVertex2f(1.5f, 0.0f);
glVertex2f(-1.5f, 0.0f);
glEnd();

// Crown (gold with jewels)
glColor3f(1.0f, 0.8f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.0f, 3.5f);
glVertex2f(-1.8f, 2.7f);
glVertex2f(-1.2f, 2.7f);
glVertex2f(0.0f, 3.2f);
glVertex2f(1.2f, 2.7f);
glVertex2f(1.8f, 2.7f);
glEnd();
glPopMatrix();

// 10 Villagers (standing behind king)
float villagerColors[10][3] = {
	{0.2f,0.6f,0.9f}, {0.8f,0.4f,0.1f}, {0.3f,0.7f,0.4f},
	{0.9f,0.5f,0.7f}, {0.1f,0.5f,0.8f}, {0.7f,0.8f,0.2f},
	{0.4f,0.3f,0.9f}, {0.9f,0.6f,0.3f}, {0.2f,0.8f,0.6f},
	{0.8f,0.2f,0.5f}
};

for (int i = 0; i < 10; i++) {
	glPushMatrix();
	float x = -4.0f + (i % 5) * 2.0f; // 2 rows of 5
	float y = -7.0f + (i / 5) * 1.5f;
	glTranslatef(x, y, 0.0f);

	// Body
	glColor3fv(villagerColors[i]);
	glBegin(GL_QUADS);
	glVertex2f(-0.8f, 1.5f);
	glVertex2f(0.8f, 1.5f);
	glVertex2f(0.8f, 0.0f);
	glVertex2f(-0.8f, 0.0f);
	glEnd();

	// Head
	glColor3f(1.0f, 0.8f, 0.6f);
	glBegin(GL_QUADS);
	glVertex2f(-0.6f, 2.2f);
	glVertex2f(0.6f, 2.2f);
	glVertex2f(0.6f, 1.5f);
	glVertex2f(-0.6f, 1.5f);
	glEnd();
	glPopMatrix();
}

// HEROES APPROACHING FROM RIGHT
float hero1X = std::min(-1.0f, 17.0f - frame * 0.2f); // Moves from x=15 to x=-1
float hero2X = std::min(1.0f, 15.0f - frame * 0.2f);  // Moves from x=17 to x=1

// Hero 1
glPushMatrix();
glTranslatef(hero1X, -10.0f, 0.0f);
glScalef(0.9f, 0.9f, 1.0f);
drawCharacter1();
glPopMatrix();

// Hero 2
glPushMatrix();
glTranslatef(hero2X, -10.0f, 0.0f);
glScalef(0.9f, 0.9f, 1.0f);
drawCharacter2();
glPopMatrix();

// THANK YOU MESSAGE (appears when heroes arrive)
if (hero1X <= -1.0f) {
	glColor3f(0.0f, 0.0f, 0.0f);
	float textX = -8.5f;
	float textY = 11.5f;
	const char* thanks = "THANK YOU HEROES!";

	glRasterPos2f(textX, textY);
	for (const char* c = thanks; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
		textX += 1.1f;
		glRasterPos2f(textX, textY);
	}
}

glutSwapBuffers();
}

