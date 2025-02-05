#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include<iostream>

#define PI 3.14159265358979323846
#include <cstdio>

//////////////////////////city view variables/////////////////
float MoveY;
float MoveZ;
float MoveK=900.0f;
float MoveW;
float MoveX = 0.0f;
bool CloudMoving = false;
bool PlaneMoving = true;
bool BoatMoving= false;
bool CarMoving =false;

/////////////////////////////////////////////////

////////////////////////////////seaview variables///////////////////
int currentScenario = 8;
using namespace std;
float sunY = 850.0f;
float moonY = 800.0f;
float angle = 0.0f;
float cloudX = 300;
float birdX = 0.0f;
float rotationAngle = 0.0f;
bool isNight = false;
bool isNightVill = false;
bool isSunset = false;
bool sunMoving = false;
bool isCloudMoving = false;
float carpos = 0.0f;
float carpos2 = 0.0f;
float carSpeed = 1.0f;
bool isGreen = true;  // Turn green light on
bool isRed = false;
int prevMouseX = -1;
bool isMouseMoving = false;
float airplaneX = 0.0f; // Initial X position
float planeSpeed = 1.5f; // Speed of movement
float boatx = 0.0f;

//////////////////////////////////////////////village view variables//////////////////

//bool isNight = false;
float carX = 0.0f;
//float carSpeed = 1.0f;
float cary = 900.0f;
float carSpeed1 = 2.0f;
float bladeAngle = 0.0f;
float meg1x= 0.0f,meg1y= 0.0f  ; //cloud
float meg2x= 0.0f,meg2y= 0.0f  ;
float meg3x= 0.0f,meg3y=  0.0f ;
float meg4x= 0.0f,meg4y=  0.0f ;
float speed = 1.0f; // cloud spreed*/
///////////////////////////////////////////////////////code of village view///////////////////////


void drawCircle(float centerX, float centerY, float radius, int numSegments)
{
    glBegin(GL_TRIANGLE_FAN); // Filled circle
    glVertex2f(centerX, centerY); // Center of the circle
    for (int i = 0; i <= numSegments; ++i)
    {
        float angle = 2.0f * M_PI * i / numSegments; // Angle in radians
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(centerX + x, centerY + y);
    }
    glEnd();
}

//-------------------------------------------------------------------



void updateCar(int value)
{

    carX += carSpeed;

    if (carX > 900) carX = -200;

    // Redisplay and call the function again
    glutPostRedisplay();
    glutTimerFunc(16, updateCar, 0); // Call again in ~16ms (60 FPS)
}
//-------------------------------------------------------------------



void updateCar2(int value)
{

    cary -= carSpeed1;

    if (cary < 0) cary = 1100;


    glutPostRedisplay();
    glutTimerFunc(16, updateCar2, 0); // Call again in ~16ms (60 FPS)
}
//-------------------------------------------------------------------

// Function to draw a circle (windmill pivot)
void drawmillcircle(float x_center, float y_center, float radius)
{
    int triangleAmount = 50;  // Smoothness
    float twicePi = 2.0f * 3.14159265359;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x_center, y_center);  // Center of the circle
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x_center + (radius * cos(i * twicePi / triangleAmount)),
            y_center + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

//-------------------------------------------------------------------
void movewind(int)
{
    if(isNightVill)
    {
        bladeAngle += 20.0f; // Rotate blades
        if (bladeAngle > 360.0f)
        {
            bladeAngle -= 360.0f;
        }
    }
    glutPostRedisplay(); // Redraw screen
    glutTimerFunc(50, movewind, 0); // Call again after 50ms
}
//-------------------------------------------------------------------


void grass1()
{
    glColor3f(0.0f, 1.0f, 0.0f);
    drawCircle(810.0f, 350.0f, 3.5f, 100);

    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);


    glVertex2i(795, 367);
    glVertex2i(809, 347);


    glVertex2i(800, 377);// 2nd part
    glVertex2i(810, 347);


    glVertex2i(805, 387);
    glVertex2i(811, 347);




    glVertex2i(815, 377);
    glVertex2i(810, 347);



    glVertex2i(825, 387);
    glVertex2i(810, 347);



    glVertex2i(832, 387);
    glVertex2i(810, 347);

    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(795, 367,  5.5f, 100);

    glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(805, 387,  5.5f, 100);


    glColor3f(0.0f, 0.0f, 1.0f);
    drawCircle(832, 387,  5.5f, 100);

}

void grass2()
{
    glColor3f(0.0f, 1.0f, 0.0f);
    drawCircle(720.0f, 355.0f, 3.5f, 100);  // Shifted further right

    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);

    glVertex2i(685, 372);
    glVertex2i(719, 352);

    glVertex2i(690, 382);
    glVertex2i(720, 352);

    glVertex2i(695, 392);
    glVertex2i(721, 352);

    glVertex2i(705, 382);
    glVertex2i(720, 352);

    glVertex2i(715, 392);
    glVertex2i(720, 352);

    glVertex2i(722, 392);
    glVertex2i(720, 352);

    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(685, 372, 5.5f, 100);

    glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(695, 392, 5.5f, 100);

    glColor3f(0.0f, 0.0f, 1.0f);
    drawCircle(722, 392, 5.5f, 100);
}

void grass3()
{
    glColor3f(0.0f, 1.0f, 0.0f);
    drawCircle(500.0f, 360.0f, 3.5f, 100);  // Different base position

    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);

    // Left-leaning blades
    glVertex2i(480, 380);
    glVertex2i(500, 350);

    glVertex2i(485, 390);
    glVertex2i(500, 350);

    glVertex2i(490, 400);
    glVertex2i(500, 350);

    // Right-leaning blades
    glVertex2i(510, 390);
    glVertex2i(500, 350);

    glVertex2i(520, 400);
    glVertex2i(500, 350);

    glVertex2i(530, 390);
    glVertex2i(500, 350);

    glEnd();

    // Flowers with different colors
    glColor3f(1.0f, 0.5f, 0.0f);  // Orange
    drawCircle(485, 390, 5.5f, 100);

    glColor3f(1.0f, 0.0f, 1.0f);  // Magenta
    drawCircle(520, 400, 5.5f, 100);

    glColor3f(0.5f, 1.0f, 0.5f);  // Light green
    drawCircle(530, 390, 5.5f, 100);
}


//-------------------------------------------------------------------------
void updatemeg1(int value)
{
    // Move cloud X-axis
    meg1x += speed;

    if (meg1x > 900) meg1x = -720;
    glutPostRedisplay();
    glutTimerFunc(16, updatemeg1, 0); // Call update every 30ms
}
//------------------------------------------------------------------------
//sky
void sky()
{

    if(isNightVill)
    {
        glBegin(GL_QUADS);
        glColor3f(0.1f, 0.1f, 0.3f); // Dark blue for night
        glVertex2i(0, 900);
        glVertex2i(900, 900);
        glVertex2i(900, 400);
        glVertex2i(0, 400);
        glEnd();
    }
    else
    {
        glBegin(GL_QUADS);
        glColor3f(0.6f, 0.9f, 1.0f); // Brighter sky blue
        glVertex2i(0, 900);
        glVertex2i(900, 900);
        glVertex2i(900, 400);
        glVertex2i(0, 400);
        glEnd();

    }

}

//-------------------------------------------------------------------------

//star in night sky
void star()
{

    if (isNightVill)
    {
        glColor3f(1.0f, 1.0f, 1.0f); // White color for stars
        glPointSize(2.5);

        // Draw stars as small points
        glBegin(GL_POINTS);
        glVertex2i(100, 800);
        glVertex2i(200, 850);
        glVertex2i(300, 820);
        glVertex2i(400, 870);
        glVertex2i(500, 800);
        glVertex2i(600, 830);
        glVertex2i(700, 870);
        glVertex2i(800, 810);
        glVertex2i(850, 850);

        glVertex2i(150, 820);
        glVertex2i(250, 880);
        glVertex2i(350, 860);
        glVertex2i(450, 890);
        glVertex2i(550, 880);
        glVertex2i(650, 870);
        glVertex2i(750, 860);
        glVertex2i(850, 890);
        glVertex2i(900, 870);
        glEnd();


        glVertex2i(650, 820);
        glVertex2i(670, 880);
        glVertex2i(690, 860);
        glVertex2i(710, 890);
        glVertex2i(730, 880);
        glVertex2i(750, 870);
        glVertex2i(770, 860);
        glVertex2i(780, 890);
        glVertex2i(800, 870);
        glEnd();



    }
}
//--------------------------------------------------------------
// Mountains - Dark Grayish Color
void mountains()
{
    glBegin(GL_TRIANGLES);
    if(isNightVill)
    {
        glColor3f(0.0f, 0.3f, 0.1f); // Dark green but slightly brighter
    }
    else
    {
        glColor3f(0.0f, 0.5f, 0.0f);
    }

// Left Mountain
    glVertex2i(50, 400);
    glVertex2i(300, 700);
    glVertex2i(550, 400);

// Right Mountain
    glVertex2i(400, 400);
    glVertex2i(700, 750);
    glVertex2i(1000, 400);

    glEnd();

}

//----------------------------------------------------------
//grass color in night
void nightfield()
{

    if(isNightVill)
    {
        glBegin(GL_QUADS);
        glColor3f(0.2f, 0.5f, 0.2f); // night grass color change
        glVertex2i(351, 300);
        glVertex2i(351, 400);
        glVertex2i(900, 400);
        glVertex2i(900, 300);
        glEnd();


        glBegin(GL_QUADS);
        glVertex2i(0, 300);
        glVertex2i(0, 320);
        glVertex2i(900, 320);
        glVertex2i(900, 300);
        glEnd();
    }
}
//----------------------------------------------------------
void road()
{
    // Road
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f); // Pitch road color
    glVertex2i(0, 0);
    glVertex2i(0, 300);
    glVertex2i(900, 300);
    glVertex2i(900, 0);
    glEnd();

    //------------------------------------------------

    // Road divider
    if(isNightVill)glColor3f(0.75f, 0.75f, 0.75f);
    else
    {
        glColor3f(1.0f, 1.0f, 1.0f); // White color

    }

    for (int x = 50; x <= 900; x += 100)   // Adjust x-step for dash spacing
    {
        glBegin(GL_QUADS);
        glVertex2i(x, 140);      // Bottom-left corner of the dash
        glVertex2i(x + 40, 140); // Bottom-right corner of the dash
        glVertex2i(x + 40, 160); // Top-right corner of the dash
        glVertex2i(x, 160);      // Top-left corner of the dash
        glEnd();
    }
}
//------------------------------------------------
// first Car
void redcar()
{
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color for the car body
    glVertex2i(carX + 200, 220);
    glVertex2i(carX + 200, 295);
    glVertex2i(carX + 280, 295);
    glVertex2i(carX + 280, 220);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color for the car body
    glVertex2i(carX + 280, 250);
    glVertex2i(carX + 300, 250);
    glVertex2i(carX + 300, 220);
    glVertex2i(carX + 280, 220);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Black color for wheels
    drawCircle(carX + 220, 210, 20, 100);
    drawCircle(carX + 280, 210, 20, 100);

    glColor3f(0.5f, 0.5f, 0.5f); // Grey color for wheel rim
    drawCircle(carX + 220, 210, 15, 100);
    drawCircle(carX + 280, 210, 15, 100);

    glColor3f(0.0f, 0.0f, 0.0f); // Black color for wheel hub
    glBegin(GL_QUADS);
    glVertex2i(carX + 215, 205);
    glVertex2i(carX + 225, 205);
    glVertex2i(carX + 225, 215);
    glVertex2i(carX + 215, 215);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(carX + 275, 205);
    glVertex2i(carX + 285, 205);
    glVertex2i(carX + 285, 215);
    glVertex2i(carX + 275, 215);
    glEnd();

    glColor3f(0.7f, 0.7f, 0.7f); // Grey color for window
    glBegin(GL_QUADS);
    glVertex2i(carX + 210, 230);
    glVertex2i(carX + 270, 230);
    glVertex2i(carX + 270, 280);
    glVertex2i(carX + 210, 280);
    glEnd();

    if(isNightVill)//if night on the light car
    {
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2i(carX+300,235);
        glVertex2i(carX+315,270);
        glVertex2i(carX+315,215);
        glEnd();

    }
}
//----------------------------------------------------
// Bus Body
void bus()
{
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.9f, 1.0f); // Sky blue bus body
    glVertex2i(cary - 250, 120); // Top-left
    glVertex2i(cary - 120, 120); // Top-right
    glVertex2i(cary - 120, 20);  // Bottom-right
    glVertex2i(cary - 250, 20);  // Bottom-left
    glEnd();

// Windows
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.8f, 0.8f); // Light grey windows
    glVertex2i(cary - 240, 110); // Window 1
    glVertex2i(cary - 210, 110);
    glVertex2i(cary - 210, 80);
    glVertex2i(cary - 240, 80);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.8f, 0.8f); // Light grey windows
    glVertex2i(cary - 200, 110); // Window 2
    glVertex2i(cary - 170, 110);
    glVertex2i(cary - 170, 80);
    glVertex2i(cary - 200, 80);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.8f, 0.8f); // Light grey windows
    glVertex2i(cary - 160, 110); // Window 3
    glVertex2i(cary - 130, 110);
    glVertex2i(cary - 130, 80);
    glVertex2i(cary - 160, 80);
    glEnd();

// Wheels
    glColor3f(0.5f, 0.5f, 0.5f); // Black wheels
    drawCircle(cary - 220, 20, 20, 100); // Front wheel
    drawCircle(cary - 150, 20, 20, 100); // Rear wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(9.5);
    glBegin(GL_POINTS);
    glVertex2i(cary - 220, 20);//point inside wheel
    glVertex2i(cary - 150, 20); //point inside wheel
    glEnd();

    if(isNightVill)//if night on the light Bus
    {
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2i(cary-250,70);
        glVertex2i(cary-290,90);
        glVertex2i(cary-290,50);
        glEnd();




    }
}
//--------------------------------------------------------------
//draw flower tree
void  flowertree()
{
    //main brach( kando)
    glBegin(GL_LINES);
    glColor3f(0.55f, 0.27f, 0.07f);
    glVertex2i(850, 350);
    glVertex2i(850, 450);
    glEnd();
    //------------------------------

    //side brach 1
    glBegin(GL_LINES);
    glColor3f(0.55f, 0.27f, 0.07f);
    glVertex2i(850, 400);
    glVertex2i(870, 450);
    glEnd();

    //side brach 2
    glBegin(GL_LINES);
    glColor3f(0.55f, 0.27f, 0.07f);
    glVertex2i(850, 390);
    glVertex2i(820, 450);
    glEnd();

    //flower left
    glColor3f(1.f, 1.0f, 1.0f);
    drawCircle(810.0f, 450.0f, 20.5f, 100);
    glColor3f(1.f, 1.0f, 0.0f);
    drawCircle(810.0f, 450.0f, 15.5f, 100);

    //flower right
    glColor3f(1.f, 1.0f, 1.0f);
    drawCircle(860.0f, 450.0f, 20.5f, 100);
    glColor3f(1.f, 1.0f, 0.0f);
    drawCircle(860.0f, 450.0f, 15.5f, 100);

}

//-------------------------------------------------------------------------
// tree
void konatree()
{
// Trunk
    glBegin(GL_QUADS);
    glColor3f(0.55f, 0.27f, 0.07f); // Brown color for trunk
    glVertex2i(880, 600); // Top-left
    glVertex2i(900, 600); // Top-right
    glVertex2i(900, 400); // Bottom-right
    glVertex2i(880, 400); // Bottom-left
    glEnd();

// Leaves - Bottom row
    if(isNightVill)
    {
        glColor3f(0.0f, 0.4f, 0.0f);
    } // Dark Green for Night}
    else
    {
        glColor3f(0.0f, 1.0f, 0.0f);   // Green color for leaves
    }
    drawCircle(870.0f, 610.0f, 25.5f, 100); // Left circle
    drawCircle(890.0f, 610.0f, 25.5f, 100); // Middle circle
    drawCircle(910.0f, 610.0f, 25.5f, 100); // Right circle
    drawCircle(850.0f, 610.0f, 25.5f, 100); // Extra left circle

// Leaves - Middle row
    drawCircle(870.0f, 640.0f, 25.5f, 100); // Left circle
    drawCircle(890.0f, 640.0f, 25.5f, 100); // Middle circle
    drawCircle(910.0f, 640.0f, 25.5f, 100); // Right circle
    drawCircle(850.0f, 635.0f, 25.5f, 100); // Extra left circle slightly higher

// Leaves - Top row
    drawCircle(880.0f, 670.0f, 25.5f, 100); // Center circle
    drawCircle(860.0f, 665.0f, 25.5f, 100); // Left circle slightly lower
    drawCircle(900.0f, 665.0f, 25.5f, 100); // Right circle slightly lower
    drawCircle(850.0f, 685.0f, 25.5f, 100); // Far left circle higher

// Leaves - Uppermost layer
    drawCircle(880.0f, 700.0f, 25.5f, 100); // Central top circle
    drawCircle(860.0f, 720.0f, 25.5f, 100); // Left circle
    drawCircle(890.0f, 720.0f, 25.5f, 100); // Middle circle
    drawCircle(920.0f, 720.0f, 25.5f, 100); // Right circle
}
//------------------------------------------------------------
// wind mill base
void windmill()
{
    glBegin(GL_QUADS);
    glColor3f(0.44f, 0.5f, 0.56f);
    glVertex2i(720, 400);
    glVertex2i(720, 650);
    glVertex2i(750, 650);
    glVertex2i(750, 400);
    glEnd();

    // Windmill Pivot (Circular center for blades)
    glColor3f(1.0f, 1.0f, 0.0f); // Dark Gray
    drawmillcircle(735, 650, 12);


    // Windmill Blades (Rotating)
    glPushMatrix();
    glTranslatef(735, 650, 0); // Move pivot to center
    glRotatef(bladeAngle, 0, 0, 1); // Rotate around pivot


    // Blade 1 (Vertical)
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); // White
    glVertex2i(-10, 0);
    glVertex2i(-10, 100);
    glVertex2i(10, 100);
    glVertex2i(10, 0);
    glEnd();

    // Blade 2 (Horizontal)
    glBegin(GL_QUADS);
    glVertex2i(0, -10);
    glVertex2i(100, -10);
    glVertex2i(100, 10);
    glVertex2i(0, 10);
    glEnd();

    // Blade 3 (Downward)
    glBegin(GL_QUADS);
    glVertex2i(-10, 0);
    glVertex2i(-10, -100);
    glVertex2i(10, -100);
    glVertex2i(10, 0);
    glEnd();

    // Blade 4 (Leftward)
    glBegin(GL_QUADS);
    glVertex2i(0, -10);
    glVertex2i(-100, -10);
    glVertex2i(-100, 10);
    glVertex2i(0, 10);
    glEnd();
    glPopMatrix(); // Restore original position
}
//----------------------------------------------------------
// House 1
void house1()
{


    glBegin(GL_QUADS);
// Walls - Light Orange
    if(isNightVill)glColor3f(0.5f, 0.3f, 0.15f);
    else
    {
        glColor3f(1.0f, 0.65f, 0.30f);
    }
    glVertex2i(0,320);
    glVertex2i(0,430);
    glVertex2i(70,430);
    glVertex2i(70,320);
    glEnd();

    glBegin(GL_TRIANGLES);
// Roof - Dark Brown
    if(isNightVill)glColor3f(0.3f, 0.15f, 0.05f);
    else
    {
        glColor3f(0.55f, 0.27f, 0.07f);
    }
    glVertex2i(0, 430);
    glVertex2i(35, 490);
    glVertex2i(70, 430);
    glEnd();

    glBegin(GL_QUADS);
// Side Roof - Dark Brown
    if(isNightVill)glColor3f(0.3f, 0.15f, 0.05f);
    else
    {
        glColor3f(0.55f, 0.27f, 0.07f);
    }
    glVertex2i(70,430);
    glVertex2i(35,490);
    glVertex2i(70,510);
    glVertex2i(135,440);
    glEnd();

    glBegin(GL_QUADS);
// Side Wall - Light Orange
    if(isNightVill)glColor3f(0.5f, 0.3f, 0.15f);
    else
    {
        glColor3f(1.0f, 0.65f, 0.30f);
    }
    glVertex2i(70,430);
    glVertex2i(135,440);
    glVertex2i(135,320);
    glVertex2i(70,320);
    glEnd();

    glBegin(GL_LINES);
// Side Wall Border
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(70,430);
    glVertex2i(70,320);
    glEnd();

// Door - White
    glBegin(GL_QUADS);
    if(isNightVill)
    {
        glColor3f(1.0f, 1.0f, 0.0f);//if night mode the light on
    }
    else
    {
        glColor3f(1.0f, 1.0f, 1.0f);
    }
    glVertex2i(25,320);
    glVertex2i(25,390);
    glVertex2i(45,390);
    glVertex2i(45,320);
    glEnd();

// Window - White
    glBegin(GL_QUADS);
    if(isNightVill)
    {
        glColor3f(1.0f, 1.0f, 0.0f);//if night mode the light on
    }
    else
    {
        glColor3f(1.0f, 1.0f, 1.0f);
    }
    glVertex2i(90,360);
    glVertex2i(90,380);
    glVertex2i(112,380);
    glVertex2i(112,360);
    glEnd();
}

//-------------------------------------------------------
// Tree Trunk (Increased Height)
void house1behindtree()
{
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.3f, 0.1f); // Brown trunk
    glVertex2i(250, 400);  // Bottom left
    glVertex2i(250, 500);  // Increased height (previously 470)
    glVertex2i(270, 500);  // Increased height
    glVertex2i(270, 400);  // Bottom right
    glEnd();

// Tree Leaves (Green Color)
    if(isNightVill)
    {
        glColor3f(0.0f, 0.4f, 0.0f);
    }
    else
    {
        glColor3f(0.0f, 0.7f, 0.0f);
    }
    drawCircle(260, 530, 30, 100); // Moved up (previously 500)
    drawCircle(240, 510, 25, 100); // Moved up (previously 480)
    drawCircle(280, 510, 25, 100); // Moved up (previously 480)

}

//----------------------------------------------------


void house2()
{


    glBegin(GL_QUADS);
// Walls - Light Yellow
    if(isNightVill)
    {
        glColor3f(0.6f, 0.5f, 0.3f);
    }
    else
    {
        glColor3f(1.0f, 0.85f, 0.55f);
    }
    glVertex2i(135,320);
    glVertex2i(135,430);
    glVertex2i(205,430);
    glVertex2i(205,320);
    glEnd();

    glBegin(GL_TRIANGLES);
// Roof - Dark Brown
    if(isNightVill)
    {
        glColor3f(0.3f, 0.15f, 0.05f);
    }
    else
    {
        glColor3f(0.55f, 0.27f, 0.07f);
    }
    glVertex2i(135, 430);
    glVertex2i(170, 490);
    glVertex2i(205, 430);
    glEnd();

    glBegin(GL_QUADS);
// Side Roof - Dark Brown
    if(isNightVill)
    {
        glColor3f(0.3f, 0.15f, 0.05f);
    }
    else
    {
        glColor3f(0.55f, 0.27f, 0.07f);
    }
    glVertex2i(205,430);
    glVertex2i(170,490);
    glVertex2i(205,510);
    glVertex2i(270,440);
    glEnd();

    glBegin(GL_QUADS);
// Side Wall - Light Yellow
    if(isNightVill)
    {
        glColor3f(0.6f, 0.5f, 0.3f);
    }
    else
    {
        glColor3f(1.0f, 0.85f, 0.55f);
    }
    glVertex2i(205,430);
    glVertex2i(270,440);
    glVertex2i(270,320);
    glVertex2i(205,320);
    glEnd();

    glBegin(GL_LINES);
// Side Wall Border
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(205,430);
    glVertex2i(205,320);
    glEnd();

// Door - White
    glBegin(GL_QUADS);
    if(isNightVill)
    {
        glColor3f(1.0f, 1.0f, 0.0f);//if night mode the light on
    }
    else
    {
        glColor3f(1.0f, 1.0f, 1.0f);
    }
    glVertex2i(160,320);
    glVertex2i(160,390);
    glVertex2i(180,390);
    glVertex2i(180,320);
    glEnd();

// Window - White
    glBegin(GL_QUADS);
    if(isNightVill)
    {
        glColor3f(1.0f, 1.0f, 0.0f);//if night mode the light on
    }
    else
    {
        glColor3f(1.0f, 1.0f, 1.0f);
    }
    glVertex2i(225,360);
    glVertex2i(225,380);
    glVertex2i(247,380);
    glVertex2i(247,360);
    glEnd();

}

//---------------------------------------------------------------
// khor(cow)food
void khor()
{

    glBegin(GL_QUADS);
    if(isNightVill)
    {
        glColor3f(0.6f, 0.6f, 0.0f);
    }
    else
    {
        glColor3f(1.0f, 1.0f, 0.0f);
    }
    glVertex2i(270,410);
    glVertex2i(351,410);
    glVertex2i(351,320);
    glVertex2i(270,320);
    glEnd();

    drawCircle(310.0f, 430.0f, 45.0f, 200); //khor head

    glBegin(GL_LINES);
    if(isNightVill)
    {
        glColor3f(0.6f, 0.6f, 0.0f);
    }
    else
    {
        glColor3f(1.0f, 1.0f, 0.0f);
    }
    glVertex2i(280,390);
    glVertex2i(280,320);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(300,390);
    glVertex2i(300,320);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(320,390);
    glVertex2i(320,320);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(340,390);
    glVertex2i(340,320);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(275,380);
    glVertex2i(345,380);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(275,360);
    glVertex2i(345,360);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(275,340);
    glVertex2i(345,340);
    glEnd();
}

//-------------------------------------------------
// Tree 1 (left)
void tree1()
{
    glColor3f(0.8f, 0.4f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2i(450, 400);
    glVertex2i(450, 470);
    glVertex2i(470, 470);
    glVertex2i(470, 400);
    glEnd();

    if(isNightVill)
    {
        glColor3f(0.0f, 0.4f, 0.0f);
    }
    else
    {
        glColor3f(0.0f, 0.7f, 0.0f);
    }
    drawCircle(460, 500, 30, 100);
    drawCircle(440, 480, 25, 100);
    drawCircle(480, 480, 25, 100);
}
//-------------------------------------------------
// Tree 2 (Further Right)
void tree2()
{
    glColor3f(0.8f, 0.4f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2i(650, 400);
    glVertex2i(650, 470);
    glVertex2i(670, 470);
    glVertex2i(670, 400);
    glEnd();

    if(isNightVill)
    {
        glColor3f(0.0f, 0.4f, 0.0f);
    }
    else
    {
        glColor3f(0.0f, 0.7f, 0.0f);
    }
    drawCircle(660, 500, 30, 100);
    drawCircle(640, 480, 25, 100);
    drawCircle(680, 480, 25, 100);

}

// sun draw
void sunmoon()
{
    if(isNightVill==false)
    {
        glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
        drawCircle(400.0f, 850.0f, 75.0f, 100); // Center (0,0), radius 0.5, 100 segments
    }
    else
    {
        glColor3f(1.0f, 1.0f, 1.0f); // white color
        drawCircle(400.0f, 850.0f, 75.0f, 100); // Center (0,0), radius 0.5, 100 segments
    }
}


void clouds()
{
    if(isNightVill)
    {
        glColor3f(0.8f, 0.8f, 0.8f);  // Light gray, slightly darker than white

    }
    else
    {
        glColor3f(1.0f, 1.0f, 1.0f); // white color

    }

//Cloud 1
    drawCircle(meg1x+100,  meg1y+750, 25, 1000);
    drawCircle( meg1x+120, meg1y+775, 25, 1000);
    drawCircle( meg1x+135, meg1y+750, 25, 1000);

// Cloud 2
    drawCircle( meg1x+275,  meg1y+800, 30, 1000);
    drawCircle( meg1x+300,  meg1y+835, 30, 1000);
    drawCircle( meg1x+325,  meg1y+ 800, 30, 1000);

// Cloud 3
    drawCircle( meg1x+525,  meg1y+825, 28, 1000);
    drawCircle( meg1x+550,  meg1y+850, 28, 1000);
    drawCircle( meg1x+575,  meg1y+825, 28, 1000);

// Cloud 4
    drawCircle( meg1x+700,  meg1y+825, 35, 1000);
    drawCircle( meg1x+725,  meg1y+850, 35, 1000);
    drawCircle( meg1x+750,  meg1y+825, 35, 1000);

    glFlush();


}

void displayVillage()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    sky();
    star();
    mountains();
    nightfield();
    road();
    redcar();
    bus();
    flowertree();
    grass1();
    grass2();
    grass3();
    konatree();
    windmill();
    house1();
    house1behindtree();
    house2();
    khor();
    tree1();
    tree2();
    sunmoon();
    clouds();
}



void initVillage()
{
    glClearColor(0.6f, 0.8f, 0.2f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 900.0, 0.0, 900.0); // 0 to 900 coordinate system
    glMatrixMode(GL_MODELVIEW);
}


//////////////////////////////////////////////////////End of village view///////////////////////

///////////////////////////////////////////////////////code of city view/////////////////////////////////
void displayCity()
 {
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

//SKY/////////////

     glBegin(GL_QUADS);
     glColor3ub(128, 223, 255);
     glVertex2f(0,0);
     glVertex2f(900,0);
     glVertex2f(900,900);
     glVertex2f(0,900);
     glEnd();

// Sun//////////
    glColor3ub(242, 255, 0);

    int k;
    GLfloat x = 800.0f;
    GLfloat y = 800.0f;
    GLfloat radius = 50.0f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);  // Center of the sun
        for(k = 0; k <= triangleAmount; k++) {
            glVertex2f(
                x + (radius * cos(k * twicePi / triangleAmount)),
                y + (radius * sin(k * twicePi / triangleAmount))
            );
        }
    glEnd();

//cloud///////

   glPushMatrix();
   glTranslatef(MoveX,0.0f,0.0f);



 glColor3ub(255, 255, 255);

    int f;
     x=500.0f; y=750.0f;radius =30.0f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(f = 0; f <= triangleAmount;f++) {
			glVertex2f(
		            x + (radius * cos(f *  twicePi / triangleAmount)),
			    y + (radius * sin(f * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(255, 255, 255);

    int g;
     x=533.33f; y=750.0f;radius =30.0f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(g = 0; g <= triangleAmount;g++) {
			glVertex2f(
		            x + (radius * cos(g *  twicePi / triangleAmount)),
			    y + (radius * sin(g * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(255, 255, 255);

    int h;
     x=558.33f; y=725.0f;radius =30.0f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(h = 0; h <= triangleAmount;h++) {
			glVertex2f(
		            x + (radius * cos(h *  twicePi / triangleAmount)),
			    y + (radius * sin(h * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(255, 255, 255);

    int l;
     x=520.83f; y=715.0f;radius =30.0f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(l = 0; l <= triangleAmount;l++) {
			glVertex2f(
		            x + (radius * cos(l *  twicePi / triangleAmount)),
			    y + (radius * sin(l * twicePi / triangleAmount))
			);
		}
	glEnd();

//CLOUD2/////

glColor3ub(255, 255, 255);

    int F;
     x=350.0f; y=750.0f;radius =30.0f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(F = 0; F <= triangleAmount;F++) {
			glVertex2f(
		            x + (radius * cos(F *  twicePi / triangleAmount)),
			    y + (radius * sin(F * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(255, 255, 255);


    int G;
     x=383.0f; y=750.0f;radius =30.0f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(G = 0; G <= triangleAmount;G++) {
			glVertex2f(
		            x + (radius * cos(G *  twicePi / triangleAmount)),
			    y + (radius * sin(G * twicePi / triangleAmount))
			);
		}
	glEnd();

int H;
     x=408.0f; y=725.0f;radius =30.0f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(H = 0; H <= triangleAmount;H++) {
			glVertex2f(
		            x + (radius * cos(H *  twicePi / triangleAmount)),
			    y + (radius * sin(H * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3ub(255, 255, 255);

    int L;
     x=370.0; y=715.0f;radius =30.0f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(L = 0; L <= triangleAmount;L++) {
			glVertex2f(
		            x + (radius * cos(L *  twicePi / triangleAmount)),
			    y + (radius * sin(L * twicePi / triangleAmount))
			);
		}
	glEnd();

	glPopMatrix();

glutSwapBuffers();



//LEFT SIDE BLDING 1  //************************


     glBegin(GL_QUADS);
     glColor3ub(204, 51, 0);
     glVertex2f(0.0,350.0);
     glVertex2f(25.0,350.0);
     glVertex2f(25.0,600.0);
     glVertex2f(0.0,600.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(230, 57, 0);
     glVertex2f(25.0,350.0);
     glVertex2f(100.0,350.0);
     glVertex2f(100.0,600.0);
     glVertex2f(25.0,600.0);
     glEnd();



//glass#####
glBegin(GL_QUADS);
     glColor3ub(255, 128, 0);
     glVertex2f(0.0,350.0);
     glVertex2f(20.0,350.0);
     glVertex2f(20.0,595.0);
     glVertex2f(0.0,595.0);
     glEnd();

glBegin(GL_QUADS);
     glColor3ub(230, 115, 0);
     glVertex2f(30.0,350.0);
     glVertex2f(95.0,350.0);
     glVertex2f(95.0,590.0);
     glVertex2f(30.0,590.0);
     glEnd();

//LEFT SIDE BLDING 2/////////


//bldingside

     glBegin(GL_QUADS);
     glColor3ub(191, 191, 191);
     glVertex2f(100.0,350.0);
     glVertex2f(130.0,350.0);
     glVertex2f(130.0,650.0);
     glVertex2f(100.0,650.0);
     glEnd();
//miror 1


glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(105.0,350.0);
     glVertex2f(125.0,350.0);
     glVertex2f(125.0,640.0);
     glVertex2f(105.0,640.0);
     glEnd();

//blding

     glBegin(GL_QUADS);
     glColor3ub(204, 204, 204);
     glVertex2f(130.0,350.0);
     glVertex2f(180.0,350.0);
     glVertex2f(180.0,650.0);
     glVertex2f(130.0,650.0);
     glEnd();

//miror 2
glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(135.0,350.0);
     glVertex2f(175.0,350.0);
     glVertex2f(175.0,640.0);
     glVertex2f(135.0,640.0);
     glEnd();

     //School/////

glBegin(GL_QUADS);
     glColor3ub(255,153,0);
     glVertex2f(200.0,300.0);
     glVertex2f(450.0,300.0);
     glVertex2f(450.0,500.0);
     glVertex2f(200.0,500.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(128,0,0);
     glVertex2f(190.0,500.0);
     glVertex2f(460.0,500.0);
     glVertex2f(460.0,510.0);
     glVertex2f(190.0,510.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,153,0);
     glVertex2f(270.0,510.0);
     glVertex2f(390.0,510.0);
     glVertex2f(390.0,560.0);
     glVertex2f(270.0,560.0);
     glEnd();

     glBegin(GL_TRIANGLES);
     glColor3ub(128,0,0);
     glVertex2f(260.0,560.0);
     glVertex2f(400.0,560.0);
     glVertex2f(330.0,600.0);
     glEnd();


     glColor3ub(0,0,0);
    int U;

	 x=330.0f;  y=535.0f;  radius =20.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(U= 0; U <= triangleAmount;U++) {
			glVertex2f(
		            x + (radius * cos(U *  twicePi / triangleAmount)),
			    y + (radius * sin(U * twicePi / triangleAmount))
			);
		}
	glEnd();

	glBegin(GL_QUADS);
     glColor3ub(128,0,0);
     glVertex2f(280.0,300.0);
     glVertex2f(370.0,300.0);
     glVertex2f(370.0,410.0);
     glVertex2f(280.0,410.0);
     glEnd();

    glBegin(GL_TRIANGLES);
     glColor3ub(128,0,0);
     glVertex2f(260.0,410.0);
     glVertex2f(390.0,410.0);
     glVertex2f(325.0,450.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(150,150,150);
     glVertex2f(300.0,300.0);
     glVertex2f(350.0,300.0);
     glVertex2f(350.0,370.0);
     glVertex2f(300.0,370.0);
     glEnd();
//
glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(210.0,440.0);
     glVertex2f(230.0,440.0);
     glVertex2f(230.0,470.0);
     glVertex2f(210.0,470.0);
     glEnd();

glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(210.0,400.0);
     glVertex2f(230.0,400.0);
     glVertex2f(230.0,430.0);
     glVertex2f(210.0,430.0);
     glEnd();

glBegin(GL_QUADS);
    glColor3ub(0,0,0);
     glVertex2f(210.0,360.0);
     glVertex2f(230.0,360.0);
     glVertex2f(230.0,390.0);
     glVertex2f(210.0,390.0);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(240.0,440.0);
     glVertex2f(260.0,440.0);
     glVertex2f(260.0,470.0);
     glVertex2f(240.0,470.0);
     glEnd();

glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(240.0,400.0);
     glVertex2f(260.0,400.0);
     glVertex2f(260.0,430.0);
     glVertex2f(240.0,430.0);
     glEnd();

glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(240.0,360.0);
     glVertex2f(260.0,360.0);
     glVertex2f(260.0,390.0);
     glVertex2f(240.0,390.0);
     glEnd();
//////2nd
glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(390.0,440.0);
     glVertex2f(410.0,440.0);
     glVertex2f(410.0,470.0);
     glVertex2f(390.0,470.0);
     glEnd();

glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(390.0,400.0);
     glVertex2f(410.0,400.0);
     glVertex2f(410.0,430.0);
     glVertex2f(390.0,430.0);
     glEnd();

glBegin(GL_QUADS);
    glColor3ub(0,0,0);
     glVertex2f(390.0,360.0);
     glVertex2f(410.0,360.0);
     glVertex2f(410.0,390.0);
     glVertex2f(390.0,390.0);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(420.0,440.0);
     glVertex2f(440.0,440.0);
     glVertex2f(440.0,470.0);
     glVertex2f(420.0,470.0);
     glEnd();

glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(420.0,400.0);
     glVertex2f(440.0,400.0);
     glVertex2f(440.0,430.0);
     glVertex2f(420.0,430.0);
     glEnd();

glBegin(GL_QUADS);
    glColor3ub(0,0,0);
     glVertex2f(420.0,360.0);
     glVertex2f(440.0,360.0);
     glVertex2f(440.0,390.0);
     glVertex2f(420.0,390.0);
     glEnd();
////

glBegin(GL_QUADS);
    glColor3ub(51,204,204);
     glVertex2f(210.0,320.0);
     glVertex2f(270.0,320.0);
     glVertex2f(270.0,340.0);
     glVertex2f(210.0,340.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(51,204,204);
     glVertex2f(380.0,320.0);
     glVertex2f(440.0,320.0);
     glVertex2f(440.0,340.0);
     glVertex2f(380.0,340.0);
     glEnd();



     //Hotel//////

     glBegin(GL_QUADS);
     glColor3ub(0,128,128);
     glVertex2f(460.0,300.0);
     glVertex2f(580.0,300.0);
     glVertex2f(580.0,650.0);
     glVertex2f(460.0,650.0);
     glEnd();


     glBegin(GL_QUADS);
     glColor3ub(192,192,192);
     glVertex2f(450.0,630.0);
     glVertex2f(575.0,630.0);
     glVertex2f(575.0,650.0);
     glVertex2f(450.0,650.0);
     glEnd();

      glBegin(GL_QUADS);
     glColor3ub(192,192,192);
     glVertex2f(450.0,600.0);
     glVertex2f(575.0,600.0);
     glVertex2f(575.0,620.0);
     glVertex2f(450.0,620.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(192,192,192);
     glVertex2f(450.0,570.0);
     glVertex2f(575.0,570.0);
     glVertex2f(575.0,590.0);
     glVertex2f(450.0,590.0);
     glEnd();

 glBegin(GL_QUADS);
     glColor3ub(192,192,192);
     glVertex2f(450.0,540.0);
     glVertex2f(575.0,540.0);
     glVertex2f(575.0,560.0);
     glVertex2f(450.0,560.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(192,192,192);
     glVertex2f(450.0,510.0);
     glVertex2f(575.0,510.0);
     glVertex2f(575.0,530.0);
     glVertex2f(450.0,530.0);
     glEnd();

    glBegin(GL_QUADS);
     glColor3ub(192,192,192);
     glVertex2f(450.0,480.0);
     glVertex2f(575.0,480.0);
     glVertex2f(575.0,500.0);
     glVertex2f(450.0,500.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(192,192,192);
     glVertex2f(450.0,450.0);
     glVertex2f(575.0,450.0);
     glVertex2f(575.0,470.0);
     glVertex2f(450.0,470.0);
     glEnd();
     glBegin(GL_QUADS);
     glColor3ub(192,192,192);
     glVertex2f(450.0,420.0);
     glVertex2f(575.0,420.0);
     glVertex2f(575.0,440.0);
     glVertex2f(450.0,440.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(192,192,192);
     glVertex2f(450.0,390.0);
     glVertex2f(575.0,390.0);
     glVertex2f(575.0,410.0);
     glVertex2f(450.0,410.0);
     glEnd();

      glBegin(GL_QUADS);
     glColor3ub(192,192,192);
     glVertex2f(450.0,360.0);
     glVertex2f(575.0,360.0);
     glVertex2f(575.0,380.0);
     glVertex2f(450.0,380.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(192,192,192);
     glVertex2f(450.0,330.0);
     glVertex2f(575.0,330.0);
     glVertex2f(575.0,350.0);
     glVertex2f(450.0,350.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(192,192,192);
     glVertex2f(450.0,300.0);
     glVertex2f(575.0,300.0);
     glVertex2f(575.0,320.0);
     glVertex2f(450.0,320.0);
     glEnd();



 //Land yellow bulding================================================

 glBegin(GL_QUADS);//yellow
     glColor3ub(255, 214, 51);
     glVertex2f(0.0,300.0);
     glVertex2f(400.0,300.0);
     glVertex2f(400.0,360.0);
     glVertex2f(0.0,360.0);
     glEnd();

     glBegin(GL_QUADS);//chai
     glColor3ub(115, 115, 115);
     glVertex2f(10.0,300.0);
     glVertex2f(390.0,300.0);
     glVertex2f(390.0,350.0);
     glVertex2f(10.0,350.0);
     glEnd();

    glBegin(GL_QUADS);//yellow
     glColor3ub(255, 214, 51);
     glVertex2f(10.0,300.0);
     glVertex2f(380.0,300.0);
     glVertex2f(380.0,345.0);
     glVertex2f(10.0,345.0);
     glEnd();

     glBegin(GL_QUADS);//Unknown colour
     glColor3ub(204, 204, 255);
     glVertex2f(10.0,300.0);
     glVertex2f(376.0,300.0);
     glVertex2f(376.0,341.0);
     glVertex2f(10.0,341.0);
     glEnd();


     //GRASS 1
     glBegin(GL_QUADS);
     glColor3ub(102, 153, 0);
     glVertex2f(0.0,285.0);
     glVertex2f(900.0,285.0);
     glVertex2f(900.0,300.0);
     glVertex2f(0.0,300.0);
     glEnd();


     //mati 1
     glBegin(GL_QUADS);
     glColor3ub(102, 51, 0);
     glVertex2f(0.0,280.0);
     glVertex2f(900.0,280.0);
     glVertex2f(900.0,285.0);
     glVertex2f(0.0,285.0);
     glEnd();

   //road
     glBegin(GL_QUADS);
     glColor3ub(115,115,115);
     glVertex2f(0.0,150.0);
     glVertex2f(900.0,150.0);
     glVertex2f(900.0,280.0);
     glVertex2f(0.0,280.0);
     glEnd();


    // Draw white road segments
    glColor3ub(255,255,255);
    for (int x = 31; x <= 900; x += 50) {
        glBegin(GL_QUADS);
        glVertex2f(x, 225);
        glVertex2f(x + 25, 225);
        glVertex2f(x + 29, 228);
        glVertex2f(x + 4, 228);
        glEnd();
    }


     //GRASS 2
     glBegin(GL_QUADS);
     glColor3ub(102, 153, 0);
     glVertex2f(0.0,135.0);
     glVertex2f(900.0,135.0);
     glVertex2f(900.0,146.0);
     glVertex2f(0.0,146.0);
     glEnd();


     //mati 2
     glBegin(GL_QUADS);
     glColor3ub(102, 51, 0);
      glVertex2f(0.0,146.0);
     glVertex2f(900.0,146.0);
     glVertex2f(900.0,150.0);
     glVertex2f(0.0,150.0);
     glEnd();

     //River

     glBegin(GL_QUADS);
     glColor3ub(35,137,218);
     glVertex2f(0.0,0.0);
     glVertex2f(900.0,0.0);
     glVertex2f(900.0,135.0);
     glVertex2f(0.0,135.0);
     glEnd();

     //Boat 1
     glPushMatrix();
     glTranslatef(MoveY,0.0f,0.0f);
     glBegin(GL_QUADS);
     glColor3ub(51,51,51);
     glVertex2f(80.0,10.0);
     glVertex2f(220.0,10.0);
     glVertex2f(260.0,50.0);
     glVertex2f(40.0,50.0);
     glEnd();

      glBegin(GL_QUADS);
     glColor3ub(120,20,20);
     glVertex2f(80.0,50.0);
     glVertex2f(200.0,50.0);
     glVertex2f(200.0,80.0);
     glVertex2f(100.0,80.0);
     glEnd();

     glBegin(GL_TRIANGLES);
     glColor3ub(153,151,0);
     glVertex2f(200.0,50.0);
     glVertex2f(230.0,50.0);
     glVertex2f(200.0,80.0);
     glEnd();


     //Boat 2
     glBegin(GL_QUADS);
     glColor3ub(51,51,51);
     glVertex2f(660.0,10.0);
     glVertex2f(780.0,10.0);
     glVertex2f(810.0,30.0);
     glVertex2f(630.0,30.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,153,0);
     glVertex2f(660.0,30.0);
     glVertex2f(780.0,30.0);
     glVertex2f(760.0,50.0);
     glVertex2f(680.0,50.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(51,51,51);
     glVertex2f(720.0,50.0);
     glVertex2f(730.0,50.0);
     glVertex2f(730.0,70.0);
     glVertex2f(720.0,70.0);
     glEnd();

      glBegin(GL_QUADS);
     glColor3ub(0,128,0);
     glVertex2f(680.0,70.0);
     glVertex2f(750.0,70.0);
     glVertex2f(770.0,110.0);
     glVertex2f(700.0,110.0);
     glEnd();

     glColor3ub(255, 0, 0);
    int R;

	 x=725.0f;  y=90.0f;  radius =10.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(R = 0; R <= triangleAmount;R++) {
			glVertex2f(
		            x + (radius * cos(R *  twicePi / triangleAmount)),
			    y + (radius * sin(R * twicePi / triangleAmount))
			);
		}
	glEnd();

     glPopMatrix();

     //glutSwapBuffers;



     //// Car1
     glPushMatrix();
     glTranslatef(MoveW,0.0f,0.0f);

     glBegin(GL_POLYGON);
     glColor3ub(255,0,0);
     glVertex2f(100.0,170.0);
     glVertex2f(220.0,170.0);
     glVertex2f(220.0,190.0);
     glVertex2f(170.0,220.0);
     glVertex2f(100.0,220.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(110.0,190.0);
     glVertex2f(140.0,190.0);
     glVertex2f(140.0,210.0);
     glVertex2f(110.0,210.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(150.0,190.0);
     glVertex2f(200.0,190.0);
     glVertex2f(170.0,210.0);
     glVertex2f(150.0,210.0);
     glEnd();

      glColor3ub(7, 8, 7);
    int P;

	 x=120.0f;  y=170.0f;  radius =10.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(P = 0; P <= triangleAmount;P++) {
			glVertex2f(
		            x + (radius * cos(P *  twicePi / triangleAmount)),
			    y + (radius * sin(P * twicePi / triangleAmount))
			);
		}
	glEnd();

	 glColor3ub(7, 8, 7);
    int Q;

	 x=190.0f;  y=170.0f;  radius =10.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(Q = 0; Q <= triangleAmount;Q++) {
			glVertex2f(
		            x + (radius * cos(Q *  twicePi / triangleAmount)),
			    y + (radius * sin(Q * twicePi / triangleAmount))
			);
		}
	glEnd();


//car2


     glBegin(GL_POLYGON);
     glColor3ub(0,0,255);
     glVertex2f(350.0,170.0);
     glVertex2f(550.0,170.0);
     glVertex2f(550.0,200.0);
     glVertex2f(500.0,230.0);
     glVertex2f(350.0,230.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(370.0,190.0);
     glVertex2f(400.0,190.0);
     glVertex2f(400.0,220.0);
     glVertex2f(370.0,220.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(420.0,190.0);
     glVertex2f(450.0,190.0);
     glVertex2f(450.0,220.0);
     glVertex2f(420.0,220.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(460.0,190.0);
     glVertex2f(540.0,190.0);
     glVertex2f(500.0,220.0);
     glVertex2f(460.0,220.0);
     glEnd();




    glColor3ub(7, 8, 7);
    int M;

	 x=380.0f;  y=170.0f;  radius =10.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(M = 0; M <= triangleAmount;M++) {
			glVertex2f(
		            x + (radius * cos(M *  twicePi / triangleAmount)),
			    y + (radius * sin(M * twicePi / triangleAmount))
			);
		}
	glEnd();

	 glColor3ub(7, 8, 7);
    int N;

	 x=450.0f;  y=170.0f;  radius =10.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(N = 0; N <= triangleAmount;N++) {
			glVertex2f(
		            x + (radius * cos(N *  twicePi / triangleAmount)),
			    y + (radius * sin(N * twicePi / triangleAmount))
			);
		}
	glEnd();

	 glColor3ub(7, 8, 7);
    int O;

	 x=520.0f;  y=170.0f;  radius =10.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(O = 0; O <= triangleAmount;O++) {
			glVertex2f(
		            x + (radius * cos(O *  twicePi / triangleAmount)),
			    y + (radius * sin(O * twicePi / triangleAmount))
			);
		}
	glEnd();

glPopMatrix();

glutSwapBuffers();

/////Hospital

 glBegin(GL_POLYGON);
     glColor3ub(255,250,250);
     glVertex2f(580.0,300.0);
     glVertex2f(880.0,300.0);
     glVertex2f(880.0,570.0);
     glVertex2f(860.0,570.0);
     glVertex2f(860.0,550.0);
     glVertex2f(620.0,550.0);
     glVertex2f(600.0,570.0);
     glVertex2f(580.0,570.0);

     glEnd();

       glColor3ub(255,250,250);
    int K;

	 x=730.0f;  y=550.0f;  radius =50.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(K = 0; K <= triangleAmount;K++) {
			glVertex2f(
		            x + (radius * cos(K *  twicePi / triangleAmount)),
			    y + (radius * sin(K * twicePi / triangleAmount))
			);
		}
	glEnd();

	 glBegin(GL_QUADS);
     glColor3ub(255,0,0);
     glVertex2f(600.0,300.0);
     glVertex2f(690.0,300.0);
     glVertex2f(690.0,530.0);
     glVertex2f(600.0,530.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,0,0);
     glVertex2f(770.0,300.0);
     glVertex2f(860.0,300.0);
     glVertex2f(860.0,530.0);
     glVertex2f(770.0,530.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(710.0,300.0);
     glVertex2f(750.0,300.0);
     glVertex2f(750.0,400.0);
     glVertex2f(710.0,400.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(610.0,330.0);
     glVertex2f(645.0,330.0);
     glVertex2f(645.0,380.0);
     glVertex2f(610.0,380.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(650.0,330.0);
     glVertex2f(685.0,330.0);
     glVertex2f(685.0,380.0);
     glVertex2f(650.0,380.0);
     glEnd();


     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(610.0,400.0);
     glVertex2f(645.0,400.0);
     glVertex2f(645.0,450.0);
     glVertex2f(610.0,450.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(650.0,400.0);
     glVertex2f(685.0,400.0);
     glVertex2f(685.0,450.0);
     glVertex2f(650.0,450.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(610.0,460.0);
     glVertex2f(645.0,460.0);
     glVertex2f(645.0,510.0);
     glVertex2f(610.0,510.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(650.0,460.0);
     glVertex2f(685.0,460.0);
     glVertex2f(685.0,510.0);
     glVertex2f(650.0,510.0);
     glEnd();


     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(780.0,330.0);
     glVertex2f(815.0,330.0);
     glVertex2f(815.0,380.0);
     glVertex2f(780.0,380.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(820.0,330.0);
     glVertex2f(855.0,330.0);
     glVertex2f(855.0,380.0);
     glVertex2f(820.0,380.0);
     glEnd();


     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(780.0,400.0);
     glVertex2f(815.0,400.0);
     glVertex2f(815.0,450.0);
     glVertex2f(780.0,450.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(820.0,400.0);
     glVertex2f(855.0,400.0);
     glVertex2f(855.0,450.0);
     glVertex2f(820.0,450.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(780.0,460.0);
     glVertex2f(815.0,460.0);
     glVertex2f(815.0,510.0);
     glVertex2f(780.0,510.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(820.0,460.0);
     glVertex2f(855.0,460.0);
     glVertex2f(855.0,510.0);
     glVertex2f(820.0,510.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(695.0,410.0);
     glVertex2f(725.0,410.0);
     glVertex2f(725.0,470.0);
     glVertex2f(695.0,470.0);
     glEnd();

      glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(730.0,410.0);
     glVertex2f(760.0,410.0);
     glVertex2f(760.0,470.0);
     glVertex2f(730.0,470.0);
     glEnd();

      glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(695.0,480.0);
     glVertex2f(725.0,480.0);
     glVertex2f(725.0,540.0);
     glVertex2f(695.0,540.0);
     glEnd();

      glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(730.0,480.0);
     glVertex2f(760.0,480.0);
     glVertex2f(760.0,540.0);
     glVertex2f(730.0,540.0);
     glEnd();

   glBegin(GL_QUADS);
     glColor3ub(255,0,0);
     glVertex2f(725.0, 555.0);
    glVertex2f(735.0, 555.0);
      glVertex2f(735.0, 585.0);
    glVertex2f(725.0, 585.0);
     glEnd();
     glBegin(GL_QUADS);
     glColor3ub(255,0,0);
     glVertex2f(715.0, 565.0);
     glVertex2f(745.0, 565.0);
     glVertex2f(745.0, 575.0);
     glVertex2f(715.0, 575.0);
     glEnd();


     ////LAMP-POST

 glBegin(GL_QUADS);
     glColor3ub(0, 0, 0);
     glVertex2f(185.0,280.0);
     glVertex2f(195.0,280.0);
     glVertex2f(195.0,400.0);
     glVertex2f(185.0,400.0);
     glEnd();

   glBegin(GL_QUADS);
     glColor3ub(0, 0, 0);
     glVertex2f(570.0,280.0);
     glVertex2f(580.0,280.0);
     glVertex2f(580.0,400.0);
     glVertex2f(570.0,400.0);
     glEnd();

      glColor3ub(255,255,255);
    int B;

	 x=190.0f;  y=420.0f;  radius =20.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(B = 0; B <= triangleAmount;B++) {
			glVertex2f(
		            x + (radius * cos(B *  twicePi / triangleAmount)),
			    y + (radius * sin(B* twicePi / triangleAmount))
			);
		}
	glEnd();

	 glColor3ub(255,250,250);
    int A;

	 x=575.0f;  y=400.0f;  radius =20.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(A= 0; A<= triangleAmount;A++) {
			glVertex2f(
		            x + (radius * cos(A *  twicePi / triangleAmount)),
			    y + (radius * sin(A * twicePi / triangleAmount))
			);
		}
	glEnd();


	//TREE 1

    glBegin(GL_POLYGON);
     glColor3ub(153,51,0);
     glVertex2f(870.0,280.0);
     glVertex2f(885.0,280.0);
     glVertex2f(885.0,430.0);
     glVertex2f(870.0,430.0);
     glEnd();

      glColor3ub(0,138,0);
      int a;

	 x=880.0f;  y=460.0f;  radius =40.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(a= 0; a<= triangleAmount;a++) {
			glVertex2f(
		            x + (radius * cos(a *  twicePi / triangleAmount)),
			    y + (radius * sin(a * twicePi / triangleAmount))
			);
		}
	glEnd();

 glColor3ub(0,138,0);
      int b;

	 x=850.0f;  y=420.0f;  radius =40.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(b= 0; b<= triangleAmount;b++) {
			glVertex2f(
		            x + (radius * cos(b *  twicePi / triangleAmount)),
			    y + (radius * sin(b* twicePi / triangleAmount))
			);
		}
	glEnd();


	glColor3ub(0,138,0);
      int c;

	 x=900.0f;  y=420.0f;  radius =40.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(c= 0; c<= triangleAmount;c++) {
			glVertex2f(
		            x + (radius * cos(c*  twicePi / triangleAmount)),
			    y + (radius * sin(c* twicePi / triangleAmount))
			);
		}
	glEnd();

////TREE 2

 glBegin(GL_POLYGON);
     glColor3ub(153,51,0);
     glVertex2f(50.0,280.0);
     glVertex2f(65.0,280.0);
     glVertex2f(65.0,420.0);
     glVertex2f(50.0,420.0);
     glEnd();

      glColor3ub(0,138,0);
      int C;

	 x=60.0f;  y=450.0f;  radius =40.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(C= 0; C<= triangleAmount;C++) {
			glVertex2f(
		            x + (radius * cos(C *  twicePi / triangleAmount)),
			    y + (radius * sin(C * twicePi / triangleAmount))
			);
		}
	glEnd();

 glColor3ub(0,138,0);
      int d;

	 x=30.0f;  y=410.0f;  radius =40.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(d= 0; d<= triangleAmount;d++) {
			glVertex2f(
		            x + (radius * cos(d *  twicePi / triangleAmount)),
			    y + (radius * sin(d* twicePi / triangleAmount))
			);
		}
	glEnd();


	glColor3ub(0,138,0);
      int e;

	 x=80.0f;  y=410.0f;  radius =40.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(e= 0; e<= triangleAmount;e++) {
			glVertex2f(
		            x + (radius * cos(e*  twicePi / triangleAmount)),
			    y + (radius * sin(e* twicePi / triangleAmount))
			);
		}
	glEnd();



glFlush();


 }

////////DISPLAY2//////

 void displayCity2()
{

     glClearColor(0.0,0.0,0.2,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
////sky

     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(0,0);
     glVertex2f(900,0);
     glVertex2f(900,900);
     glVertex2f(0,900);
     glEnd();

     //Moon/////

    glColor3ub(255, 255, 255);

    int k;
    GLfloat x = 100.0f;
    GLfloat y = 800.0f;
    GLfloat radius = 50.0f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);  // Center of the sun
        for(k = 0; k <= triangleAmount; k++) {
            glVertex2f(
                x + (radius * cos(k * twicePi / triangleAmount)),
                y + (radius * sin(k * twicePi / triangleAmount))
            );
        }
    glEnd();

   //star
glPointSize( 2.5 );
    glBegin(GL_POINTS);
    glColor3ub(255, 255, 255);
    glVertex2f(50.0,850.0);
    glVertex2f(30.0,700.0);
    glVertex2f(20.0,750.0);
    glVertex2f(20.0,870.0);
    glVertex2f(20.0,820.0);
    glVertex2f(850.0,850.0);
    glVertex2f(870.0,700.0);
    glVertex2f(880.0,750.0);
    glVertex2f(880.0,870.0);
    glVertex2f(880.0,820.0);
    glVertex2f(500.0,700.0);
    glVertex2f(400.0,750.0);
    glVertex2f(300.0,735.0);
    glVertex2f(350.0,790.0);
    glVertex2f(450.0,750.0);
    glVertex2f(440.0,780.0);
    glVertex2f(520.0,840.0);
    glVertex2f(530.0,870.0);
    glVertex2f(100.0,850);
    glVertex2f(150.0,730.0);
    glVertex2f(200.0,770.0);
    glVertex2f(250.0,650.0);
    glVertex2f(280.0,810.0);
    glVertex2f(330.0,670.0);
    glVertex2f(380.0,830.0);
    glVertex2f(600.0,750.0);
    glVertex2f(660.0,630.0);
    glVertex2f(710.0,755.0);
    glVertex2f(750.0,750.0);
    glVertex2f(790.0,690.0);
    glVertex2f(680.0,850.0);

    glEnd();

    //LEFT SIDE BLDING 1  //************************


     glBegin(GL_QUADS);
     glColor3ub(204, 51, 0);
     glVertex2f(0.0,350.0);
     glVertex2f(25.0,350.0);
     glVertex2f(25.0,600.0);
     glVertex2f(0.0,600.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(230, 57, 0);
     glVertex2f(25.0,350.0);
     glVertex2f(100.0,350.0);
     glVertex2f(100.0,600.0);
     glVertex2f(25.0,600.0);
     glEnd();



//glass#####
glBegin(GL_QUADS);
     glColor3ub(255, 255, 230);
     glVertex2f(0.0,350.0);
     glVertex2f(20.0,350.0);
     glVertex2f(20.0,595.0);
     glVertex2f(0.0,595.0);
     glEnd();

glBegin(GL_QUADS);
     glColor3ub(255, 255, 230);
     glVertex2f(30.0,350.0);
     glVertex2f(95.0,350.0);
     glVertex2f(95.0,590.0);
     glVertex2f(30.0,590.0);
     glEnd();

//LEFT SIDE BLDING 2


//bldingside

     glBegin(GL_QUADS);
     glColor3ub(191, 191, 191);
     glVertex2f(100.0,350.0);
     glVertex2f(130.0,350.0);
     glVertex2f(130.0,650.0);
     glVertex2f(100.0,650.0);
     glEnd();
//miror 1


glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(105.0,350.0);
     glVertex2f(125.0,350.0);
     glVertex2f(125.0,640.0);
     glVertex2f(105.0,640.0);
     glEnd();

//blding

     glBegin(GL_QUADS);
     glColor3ub(204, 204, 204);
     glVertex2f(130.0,350.0);
     glVertex2f(180.0,350.0);
     glVertex2f(180.0,650.0);
     glVertex2f(130.0,650.0);
     glEnd();

//miror 2
glBegin(GL_QUADS);
     glColor3ub(153, 153, 255);
     glVertex2f(135.0,350.0);
     glVertex2f(175.0,350.0);
     glVertex2f(175.0,640.0);
     glVertex2f(135.0,640.0);
     glEnd();


//School/////

glBegin(GL_QUADS);
     glColor3ub(255,153,0);
     glVertex2f(200.0,300.0);
     glVertex2f(450.0,300.0);
     glVertex2f(450.0,500.0);
     glVertex2f(200.0,500.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(128,0,0);
     glVertex2f(190.0,500.0);
     glVertex2f(460.0,500.0);
     glVertex2f(460.0,510.0);
     glVertex2f(190.0,510.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,153,0);
     glVertex2f(270.0,510.0);
     glVertex2f(390.0,510.0);
     glVertex2f(390.0,560.0);
     glVertex2f(270.0,560.0);
     glEnd();

     glBegin(GL_TRIANGLES);
     glColor3ub(128,0,0);
     glVertex2f(260.0,560.0);
     glVertex2f(400.0,560.0);
     glVertex2f(330.0,600.0);
     glEnd();


     glColor3ub(255,250,250);
    int U;

	 x=330.0f;  y=535.0f;  radius =20.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(U= 0; U <= triangleAmount;U++) {
			glVertex2f(
		            x + (radius * cos(U *  twicePi / triangleAmount)),
			    y + (radius * sin(U * twicePi / triangleAmount))
			);
		}
	glEnd();

	glBegin(GL_QUADS);
     glColor3ub(128,0,0);
     glVertex2f(280.0,300.0);
     glVertex2f(370.0,300.0);
     glVertex2f(370.0,410.0);
     glVertex2f(280.0,410.0);
     glEnd();

    glBegin(GL_TRIANGLES);
     glColor3ub(128,0,0);
     glVertex2f(260.0,410.0);
     glVertex2f(390.0,410.0);
     glVertex2f(325.0,450.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(150,150,150);
     glVertex2f(300.0,300.0);
     glVertex2f(350.0,300.0);
     glVertex2f(350.0,370.0);
     glVertex2f(300.0,370.0);
     glEnd();
//
glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(210.0,440.0);
     glVertex2f(230.0,440.0);
     glVertex2f(230.0,470.0);
     glVertex2f(210.0,470.0);
     glEnd();

glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(210.0,400.0);
     glVertex2f(230.0,400.0);
     glVertex2f(230.0,430.0);
     glVertex2f(210.0,430.0);
     glEnd();

glBegin(GL_QUADS);
    glColor3ub(255,255,255);
     glVertex2f(210.0,360.0);
     glVertex2f(230.0,360.0);
     glVertex2f(230.0,390.0);
     glVertex2f(210.0,390.0);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(240.0,440.0);
     glVertex2f(260.0,440.0);
     glVertex2f(260.0,470.0);
     glVertex2f(240.0,470.0);
     glEnd();

glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(240.0,400.0);
     glVertex2f(260.0,400.0);
     glVertex2f(260.0,430.0);
     glVertex2f(240.0,430.0);
     glEnd();

glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(240.0,360.0);
     glVertex2f(260.0,360.0);
     glVertex2f(260.0,390.0);
     glVertex2f(240.0,390.0);
     glEnd();
//////2nd
glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(390.0,440.0);
     glVertex2f(410.0,440.0);
     glVertex2f(410.0,470.0);
     glVertex2f(390.0,470.0);
     glEnd();

glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(390.0,400.0);
     glVertex2f(410.0,400.0);
     glVertex2f(410.0,430.0);
     glVertex2f(390.0,430.0);
     glEnd();

glBegin(GL_QUADS);
    glColor3ub(255,255,255);
     glVertex2f(390.0,360.0);
     glVertex2f(410.0,360.0);
     glVertex2f(410.0,390.0);
     glVertex2f(390.0,390.0);
     glEnd();
glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(420.0,440.0);
     glVertex2f(440.0,440.0);
     glVertex2f(440.0,470.0);
     glVertex2f(420.0,470.0);
     glEnd();

glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(420.0,400.0);
     glVertex2f(440.0,400.0);
     glVertex2f(440.0,430.0);
     glVertex2f(420.0,430.0);
     glEnd();

glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(420.0,360.0);
     glVertex2f(440.0,360.0);
     glVertex2f(440.0,390.0);
     glVertex2f(420.0,390.0);
     glEnd();
////

glBegin(GL_QUADS);
    glColor3ub(51,204,204);
     glVertex2f(210.0,320.0);
     glVertex2f(270.0,320.0);
     glVertex2f(270.0,340.0);
     glVertex2f(210.0,340.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(51,204,204);
     glVertex2f(380.0,320.0);
     glVertex2f(440.0,320.0);
     glVertex2f(440.0,340.0);
     glVertex2f(380.0,340.0);
     glEnd();

     //Hotel

     glBegin(GL_QUADS);
     glColor3ub(0,128,128);
     glVertex2f(460.0,300.0);
     glVertex2f(580.0,300.0);
     glVertex2f(580.0,650.0);
     glVertex2f(460.0,650.0);
     glEnd();


     glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(450.0,630.0);
     glVertex2f(575.0,630.0);
     glVertex2f(575.0,650.0);
     glVertex2f(450.0,650.0);
     glEnd();

      glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(450.0,600.0);
     glVertex2f(575.0,600.0);
     glVertex2f(575.0,620.0);
     glVertex2f(450.0,620.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(450.0,570.0);
     glVertex2f(575.0,570.0);
     glVertex2f(575.0,590.0);
     glVertex2f(450.0,590.0);
     glEnd();

 glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(450.0,540.0);
     glVertex2f(575.0,540.0);
     glVertex2f(575.0,560.0);
     glVertex2f(450.0,560.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(450.0,510.0);
     glVertex2f(575.0,510.0);
     glVertex2f(575.0,530.0);
     glVertex2f(450.0,530.0);
     glEnd();

    glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(450.0,480.0);
     glVertex2f(575.0,480.0);
     glVertex2f(575.0,500.0);
     glVertex2f(450.0,500.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(450.0,450.0);
     glVertex2f(575.0,450.0);
     glVertex2f(575.0,470.0);
     glVertex2f(450.0,470.0);
     glEnd();
     glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(450.0,420.0);
     glVertex2f(575.0,420.0);
     glVertex2f(575.0,440.0);
     glVertex2f(450.0,440.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(450.0,390.0);
     glVertex2f(575.0,390.0);
     glVertex2f(575.0,410.0);
     glVertex2f(450.0,410.0);
     glEnd();

      glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(450.0,360.0);
     glVertex2f(575.0,360.0);
     glVertex2f(575.0,380.0);
     glVertex2f(450.0,380.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(450.0,330.0);
     glVertex2f(575.0,330.0);
     glVertex2f(575.0,350.0);
     glVertex2f(450.0,350.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(450.0,300.0);
     glVertex2f(575.0,300.0);
     glVertex2f(575.0,320.0);
     glVertex2f(450.0,320.0);
     glEnd();

 //Land yellow bulding================================================

 glBegin(GL_QUADS);//yellow
     glColor3ub(255, 214, 51);
     glVertex2f(0.0,300.0);
     glVertex2f(400.0,300.0);
     glVertex2f(400.0,360.0);
     glVertex2f(0.0,360.0);
     glEnd();

     glBegin(GL_QUADS);//chai
     glColor3ub(115, 115, 115);
     glVertex2f(10.0,300.0);
     glVertex2f(390.0,300.0);
     glVertex2f(390.0,350.0);
     glVertex2f(10.0,350.0);
     glEnd();

    glBegin(GL_QUADS);//yellow
     glColor3ub(255, 214, 51);
     glVertex2f(10.0,300.0);
     glVertex2f(380.0,300.0);
     glVertex2f(380.0,345.0);
     glVertex2f(10.0,345.0);
     glEnd();

     glBegin(GL_QUADS);//Unknown colour
     glColor3ub(204, 204, 255);
     glVertex2f(10.0,300.0);
     glVertex2f(376.0,300.0);
     glVertex2f(376.0,341.0);
     glVertex2f(10.0,341.0);
     glEnd();

      //GRASS 1
     glBegin(GL_QUADS);
     glColor3ub(102, 153, 0);
     glVertex2f(0.0,285.0);
     glVertex2f(900.0,285.0);
     glVertex2f(900.0,300.0);
     glVertex2f(0.0,300.0);
     glEnd();


     //mati 1
     glBegin(GL_QUADS);
     glColor3ub(102, 51, 0);
     glVertex2f(0.0,280.0);
     glVertex2f(900.0,280.0);
     glVertex2f(900.0,285.0);
     glVertex2f(0.0,285.0);
     glEnd();

   //road
     glBegin(GL_QUADS);
     glColor3ub(115,115,115);
     glVertex2f(0.0,150.0);
     glVertex2f(900.0,150.0);
     glVertex2f(900.0,280.0);
     glVertex2f(0.0,280.0);
     glEnd();


    // Draw white road segments
    glColor3ub(255,255,255);
    for (int x = 31; x <= 900; x += 50) {
        glBegin(GL_QUADS);
        glVertex2f(x, 225);
        glVertex2f(x + 25, 225);   // Width of the white segment
        glVertex2f(x + 29, 228);
        glVertex2f(x + 4, 228);
        glEnd();
    }

 //GRASS 2
     glBegin(GL_QUADS);
     glColor3ub(102, 153, 0);
     glVertex2f(0.0,135.0);
     glVertex2f(900.0,135.0);
     glVertex2f(900.0,146.0);
     glVertex2f(0.0,146.0);
     glEnd();


     //mati 2
     glBegin(GL_QUADS);
     glColor3ub(102, 51, 0);
      glVertex2f(0.0,146.0);
     glVertex2f(900.0,146.0);
     glVertex2f(900.0,150.0);
     glVertex2f(0.0,150.0);
     glEnd();

     //River

     glBegin(GL_QUADS);
     glColor3ub(15,20,60);
     glVertex2f(0.0,0.0);
     glVertex2f(900.0,0.0);
     glVertex2f(900.0,135.0);
     glVertex2f(0.0,135.0);
     glEnd();

     //Boat 1
     glPushMatrix();
     glTranslatef(MoveY,0.0f,0.0f);
     glBegin(GL_QUADS);
     glColor3ub(51,51,51);
     glVertex2f(80.0,10.0);
     glVertex2f(220.0,10.0);
     glVertex2f(260.0,50.0);
     glVertex2f(40.0,50.0);
     glEnd();

      glBegin(GL_QUADS);
     glColor3ub(120,20,20);
     glVertex2f(80.0,50.0);
     glVertex2f(200.0,50.0);
     glVertex2f(200.0,80.0);
     glVertex2f(100.0,80.0);
     glEnd();

     glBegin(GL_TRIANGLES);
     glColor3ub(153,151,0);
     glVertex2f(200.0,50.0);
     glVertex2f(230.0,50.0);
     glVertex2f(200.0,80.0);
     glEnd();



     //Boat 2
     glBegin(GL_QUADS);
     glColor3ub(51,51,51);
     glVertex2f(660.0,10.0);
     glVertex2f(780.0,10.0);
     glVertex2f(810.0,30.0);
     glVertex2f(630.0,30.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,153,0);
     glVertex2f(660.0,30.0);
     glVertex2f(780.0,30.0);
     glVertex2f(760.0,50.0);
     glVertex2f(680.0,50.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(51,51,51);
     glVertex2f(720.0,50.0);
     glVertex2f(730.0,50.0);
     glVertex2f(730.0,70.0);
     glVertex2f(720.0,70.0);
     glEnd();

      glBegin(GL_QUADS);
     glColor3ub(0,128,0);
     glVertex2f(680.0,70.0);
     glVertex2f(750.0,70.0);
     glVertex2f(770.0,110.0);
     glVertex2f(700.0,110.0);
     glEnd();

     glColor3ub(255, 0, 0);
    int R;

	 x=725.0f;  y=90.0f;  radius =10.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(R = 0; R <= triangleAmount;R++) {
			glVertex2f(
		            x + (radius * cos(R *  twicePi / triangleAmount)),
			    y + (radius * sin(R * twicePi / triangleAmount))
			);
		}
	glEnd();

     glPopMatrix();

     //glutSwapBuffers;




     //// Car1
     glPushMatrix();
     glTranslatef(MoveW,0.0f,0.0f);

     glBegin(GL_POLYGON);
     glColor3ub(255,0,0);
     glVertex2f(100.0,170.0);
     glVertex2f(220.0,170.0);
     glVertex2f(220.0,190.0);
     glVertex2f(170.0,220.0);
     glVertex2f(100.0,220.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,255, 255);
     glVertex2f(110.0,190.0);
     glVertex2f(140.0,190.0);
     glVertex2f(140.0,210.0);
     glVertex2f(110.0,210.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,255, 255);
     glVertex2f(150.0,190.0);
     glVertex2f(200.0,190.0);
     glVertex2f(170.0,210.0);
     glVertex2f(150.0,210.0);
     glEnd();

      glColor3ub(7, 8, 7);
    int P;

	 x=120.0f;  y=170.0f;  radius =10.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(P = 0; P <= triangleAmount;P++) {
			glVertex2f(
		            x + (radius * cos(P *  twicePi / triangleAmount)),
			    y + (radius * sin(P * twicePi / triangleAmount))
			);
		}
	glEnd();

	 glColor3ub(7, 8, 7);
    int Q;

	 x=190.0f;  y=170.0f;  radius =10.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(Q = 0; Q <= triangleAmount;Q++) {
			glVertex2f(
		            x + (radius * cos(Q *  twicePi / triangleAmount)),
			    y + (radius * sin(Q * twicePi / triangleAmount))
			);
		}
	glEnd();


//car2


     glBegin(GL_POLYGON);
     glColor3ub(0,0,255);
     glVertex2f(350.0,170.0);
     glVertex2f(550.0,170.0);
     glVertex2f(550.0,200.0);
     glVertex2f(500.0,230.0);
     glVertex2f(350.0,230.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,255, 255);
     glVertex2f(370.0,190.0);
     glVertex2f(400.0,190.0);
     glVertex2f(400.0,220.0);
     glVertex2f(370.0,220.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,255, 255);
     glVertex2f(420.0,190.0);
     glVertex2f(450.0,190.0);
     glVertex2f(450.0,220.0);
     glVertex2f(420.0,220.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,255, 255);
     glVertex2f(460.0,190.0);
     glVertex2f(540.0,190.0);
     glVertex2f(500.0,220.0);
     glVertex2f(460.0,220.0);
     glEnd();




    glColor3ub(7, 8, 7);
    int M;

	 x=380.0f;  y=170.0f;  radius =10.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(M = 0; M <= triangleAmount;M++) {
			glVertex2f(
		            x + (radius * cos(M *  twicePi / triangleAmount)),
			    y + (radius * sin(M * twicePi / triangleAmount))
			);
		}
	glEnd();

	 glColor3ub(7, 8, 7);
    int N;

	 x=450.0f;  y=170.0f;  radius =10.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(N = 0; N <= triangleAmount;N++) {
			glVertex2f(
		            x + (radius * cos(N *  twicePi / triangleAmount)),
			    y + (radius * sin(N * twicePi / triangleAmount))
			);
		}
	glEnd();

	 glColor3ub(7, 8, 7);
    int O;

	 x=520.0f;  y=170.0f;  radius =10.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(O = 0; O <= triangleAmount;O++) {
			glVertex2f(
		            x + (radius * cos(O *  twicePi / triangleAmount)),
			    y + (radius * sin(O * twicePi / triangleAmount))
			);
		}
	glEnd();


glPopMatrix();

glutSwapBuffers();


/////Hospital////

 glBegin(GL_POLYGON);
     glColor3ub(150,150,150);
     glVertex2f(580.0,300.0);
     glVertex2f(880.0,300.0);
     glVertex2f(880.0,570.0);
     glVertex2f(860.0,570.0);
     glVertex2f(860.0,550.0);
     glVertex2f(620.0,550.0);
     glVertex2f(600.0,570.0);
     glVertex2f(580.0,570.0);

     glEnd();

      glColor3ub(150,150,150);
    int K;

	 x=730.0f;  y=550.0f;  radius =50.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(K = 0; K <= triangleAmount;K++) {
			glVertex2f(
		            x + (radius * cos(K *  twicePi / triangleAmount)),
			    y + (radius * sin(K * twicePi / triangleAmount))
			);
		}
	glEnd();

	 glBegin(GL_QUADS);
     glColor3ub(255,0,0);
     glVertex2f(600.0,300.0);
     glVertex2f(690.0,300.0);
     glVertex2f(690.0,530.0);
     glVertex2f(600.0,530.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,0,0);
     glVertex2f(770.0,300.0);
     glVertex2f(860.0,300.0);
     glVertex2f(860.0,530.0);
     glVertex2f(770.0,530.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(710.0,300.0);
     glVertex2f(750.0,300.0);
     glVertex2f(750.0,400.0);
     glVertex2f(710.0,400.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(610.0,330.0);
     glVertex2f(645.0,330.0);
     glVertex2f(645.0,380.0);
     glVertex2f(610.0,380.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(650.0,330.0);
     glVertex2f(685.0,330.0);
     glVertex2f(685.0,380.0);
     glVertex2f(650.0,380.0);
     glEnd();


     glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(610.0,400.0);
     glVertex2f(645.0,400.0);
     glVertex2f(645.0,450.0);
     glVertex2f(610.0,450.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(650.0,400.0);
     glVertex2f(685.0,400.0);
     glVertex2f(685.0,450.0);
     glVertex2f(650.0,450.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(610.0,460.0);
     glVertex2f(645.0,460.0);
     glVertex2f(645.0,510.0);
     glVertex2f(610.0,510.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(650.0,460.0);
     glVertex2f(685.0,460.0);
     glVertex2f(685.0,510.0);
     glVertex2f(650.0,510.0);
     glEnd();


     glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(780.0,330.0);
     glVertex2f(815.0,330.0);
     glVertex2f(815.0,380.0);
     glVertex2f(780.0,380.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(820.0,330.0);
     glVertex2f(855.0,330.0);
     glVertex2f(855.0,380.0);
     glVertex2f(820.0,380.0);
     glEnd();


     glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(780.0,400.0);
     glVertex2f(815.0,400.0);
     glVertex2f(815.0,450.0);
     glVertex2f(780.0,450.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(820.0,400.0);
     glVertex2f(855.0,400.0);
     glVertex2f(855.0,450.0);
     glVertex2f(820.0,450.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(255,255,255);
     glVertex2f(780.0,460.0);
     glVertex2f(815.0,460.0);
     glVertex2f(815.0,510.0);
     glVertex2f(780.0,510.0);
     glEnd();

     glBegin(GL_QUADS);
    glColor3ub(255,255,255);
     glVertex2f(820.0,460.0);
     glVertex2f(855.0,460.0);
     glVertex2f(855.0,510.0);
     glVertex2f(820.0,510.0);
     glEnd();

     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(695.0,410.0);
     glVertex2f(725.0,410.0);
     glVertex2f(725.0,470.0);
     glVertex2f(695.0,470.0);
     glEnd();

      glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(730.0,410.0);
     glVertex2f(760.0,410.0);
     glVertex2f(760.0,470.0);
     glVertex2f(730.0,470.0);
     glEnd();

      glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(695.0,480.0);
     glVertex2f(725.0,480.0);
     glVertex2f(725.0,540.0);
     glVertex2f(695.0,540.0);
     glEnd();

      glBegin(GL_QUADS);
     glColor3ub(0,0,0);
     glVertex2f(730.0,480.0);
     glVertex2f(760.0,480.0);
     glVertex2f(760.0,540.0);
     glVertex2f(730.0,540.0);
     glEnd();


    glBegin(GL_QUADS);
     glColor3ub(255,0,0);
     glVertex2f(725.0, 555.0);
    glVertex2f(735.0, 555.0);
      glVertex2f(735.0, 585.0);
    glVertex2f(725.0, 585.0);
     glEnd();
     glBegin(GL_QUADS);
     glColor3ub(255,0,0);
     glVertex2f(715.0, 565.0);
     glVertex2f(745.0, 565.0);
     glVertex2f(745.0, 575.0);
     glVertex2f(715.0, 575.0);
     glEnd();



//plane/////

glPushMatrix();
glTranslatef(MoveK,0.0f,0.0f);

     glBegin(GL_QUADS);
     glColor3ub(0, 0, 153);
     glVertex2f(50.0,700.0);
     glVertex2f(250.0,700.0);
     glVertex2f(320.0,770.0);
     glVertex2f(90.0,730.0);
     glEnd();

glPointSize( 5.0 );
    glBegin(GL_POINTS);
    glColor3ub(255, 255, 255);
    glVertex2f(115.0,715.0);
    glVertex2f(175.0,725.0);
    glVertex2f(225.0,725.0);
    glEnd();
glPopMatrix();

glutSwapBuffers();

////LAMP-POST////

 glBegin(GL_QUADS);
     glColor3ub(0, 0, 0);
     glVertex2f(185.0,280.0);
     glVertex2f(195.0,280.0);
     glVertex2f(195.0,400.0);
     glVertex2f(185.0,400.0);
     glEnd();

   glBegin(GL_QUADS);
     glColor3ub(0, 0, 0);
     glVertex2f(570.0,280.0);
     glVertex2f(580.0,280.0);
     glVertex2f(580.0,400.0);
     glVertex2f(570.0,400.0);
     glEnd();

      glColor3ub(255,255,0);
    int L;

	 x=190.0f;  y=420.0f;  radius =20.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(L = 0; L <= triangleAmount;L++) {
			glVertex2f(
		            x + (radius * cos(L *  twicePi / triangleAmount)),
			    y + (radius * sin(L* twicePi / triangleAmount))
			);
		}
	glEnd();

	 glColor3ub(255,250,0);
    int V;

	 x=575.0f;  y=400.0f;  radius =20.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(V = 0; V <= triangleAmount;V++) {
			glVertex2f(
		            x + (radius * cos(V *  twicePi / triangleAmount)),
			    y + (radius * sin(V * twicePi / triangleAmount))
			);
		}
	glEnd();
//TREE1////

	glBegin(GL_POLYGON);
     glColor3ub(0,0,0);
     glVertex2f(870.0,280.0);
     glVertex2f(885.0,280.0);
     glVertex2f(885.0,430.0);
     glVertex2f(870.0,430.0);
     glEnd();

      glColor3ub(0,138,0);
      int a;

	 x=880.0f;  y=460.0f;  radius =40.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(a= 0; a<= triangleAmount;a++) {
			glVertex2f(
		            x + (radius * cos(a *  twicePi / triangleAmount)),
			    y + (radius * sin(a * twicePi / triangleAmount))
			);
		}
	glEnd();

 glColor3ub(0,138,0);
      int b;

	 x=850.0f;  y=420.0f;  radius =40.0f;
	 triangleAmount = 20;

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(b= 0; b<= triangleAmount;b++) {
			glVertex2f(
		            x + (radius * cos(b *  twicePi / triangleAmount)),
			    y + (radius * sin(b* twicePi / triangleAmount))
			);
		}
	glEnd();


	glColor3ub(0,138,0);
      int c;

	 x=900.0f;  y=420.0f;  radius =40.0f;
	 triangleAmount = 20;

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(c= 0; c<= triangleAmount;c++) {
			glVertex2f(
		            x + (radius * cos(c*  twicePi / triangleAmount)),
			    y + (radius * sin(c* twicePi / triangleAmount))
			);
		}
	glEnd();

	//TREE1 star
glPointSize( 5 );
    glBegin(GL_POINTS);
    glColor3ub(255, 255, 255);
    glVertex2f(880.0,460.0);
    glVertex2f(850.0,420.0);
    glVertex2f(900.0,420.0);
    glVertex2f(850.0,450.0);
    glVertex2f(900.0,450.0);
    glVertex2f(880.0,420.0);
    glEnd();

////TREE 2

 glBegin(GL_POLYGON);
     glColor3ub(0,0,0);
     glVertex2f(50.0,280.0);
     glVertex2f(65.0,280.0);
     glVertex2f(65.0,420.0);
     glVertex2f(50.0,420.0);
     glEnd();

      glColor3ub(0,138,0);
      int C;

	 x=60.0f;  y=450.0f;  radius =40.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(C= 0; C<= triangleAmount;C++) {
			glVertex2f(
		            x + (radius * cos(C *  twicePi / triangleAmount)),
			    y + (radius * sin(C * twicePi / triangleAmount))
			);
		}
	glEnd();

 glColor3ub(0,138,0);
      int d;

	 x=30.0f;  y=410.0f;  radius =40.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(d= 0; d<= triangleAmount;d++) {
			glVertex2f(
		            x + (radius * cos(d *  twicePi / triangleAmount)),
			    y + (radius * sin(d* twicePi / triangleAmount))
			);
		}
	glEnd();


	glColor3ub(0,138,0);
      int e;

	 x=80.0f;  y=410.0f;  radius =40.0f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(e= 0; e<= triangleAmount;e++) {
			glVertex2f(
		            x + (radius * cos(e*  twicePi / triangleAmount)),
			    y + (radius * sin(e* twicePi / triangleAmount))
			);
		}
	glEnd();

	//TREE2 star
glPointSize( 5 );
    glBegin(GL_POINTS);
    glColor3ub(255, 255, 255);
    glVertex2f(60.0,450.0);
    glVertex2f(30.0,410.0);
    glVertex2f(80.0,410.0);
     glVertex2f(80.0,450.0);
    glVertex2f(50.0,430.0);
    glVertex2f(80.0,410.0);
    glVertex2f(30.0,450.0);
    glEnd();



glFlush();


 }

 void MoveCar (int value)
 {
    if(CarMoving)
    {
        MoveW+=30;
     if(MoveW>1100)
     {
        MoveW=-200;
     }
    }
     glutPostRedisplay();
     glutTimerFunc(200,MoveCar,0);
 }


 void MoveBoat (int value)
 {
     if(BoatMoving){
         MoveY+=30;
     if(MoveY>1000)
     {
        MoveY=-200;
     }
     }
     glutPostRedisplay();
     glutTimerFunc(250,MoveBoat,0);
 }

void MoveCloud (int value) {
    if (CloudMoving) {
        MoveX += 30;
        if (MoveX >1100){
            MoveX = -200;
        }

        glutPostRedisplay();
    }
    glutTimerFunc(300, MoveCloud, 0);
}




void MovePlane (int value)
 {   if (PlaneMoving){
     MoveK-=30;
     if(MoveK<-100)
     {
        MoveK=900;
     }
     glutPostRedisplay();
 }
     glutTimerFunc(100,MovePlane,0);
 }


 void init(void) {

    glClearColor(1.0, 1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 900, 0, 900);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DisplayBoats(){
    //basement of the boat
    glPushMatrix();
   glTranslatef(boatx,0,0);
glBegin(GL_QUADS);
 glColor4f(0.2f, 0.2f, 0.2f, 1.0f); // Charcoal Gray
glVertex2f(300,60);
glVertex2f(390,60);
glVertex2f(366,30);
glVertex2f(324,30);
glEnd();

glBegin(GL_QUADS);
glColor4f(0.5f, 0.4f, 0.2f, 1.0f);
glVertex2f(310,60);
glVertex2f(310,90);
glVertex2f(330,90);
glVertex2f(330,60);
glEnd();
//glasss///////
glBegin(GL_QUADS);
if(isNight){
    glColor4f(0.9f, 0.8f, 0.6f, 0.5f); // Slightly warmer, with light coming through

}else{
      glColor4f(0.8f, 0.8f, 0.8f, 0.5f); // Frosted Glass
}
glVertex2f(315,65);
glVertex2f(315,80);
glVertex2f(325,80);
glVertex2f(325,65);
glEnd();

glBegin(GL_QUADS);
glColor4f(0.1f, 0.15f, 0.3f, 1.0f);
glVertex2f(330,60);
glVertex2f(330,105);
glVertex2f(360,105);
glVertex2f(360,60);
glEnd();

glBegin(GL_QUADS);
if(isNight){
    glColor4f(0.9f, 0.8f, 0.6f, 0.5f); // Slightly warmer, with light coming through

}else{
      glColor4f(0.8f, 0.8f, 0.8f, 0.5f); // Frosted Glass
}
glVertex2f(340,60);
glVertex2f(340,90);
glVertex2f(350,90);
glVertex2f(350,60);
glEnd();
glPopMatrix();
}

void updateBoat(int value) {
    boatx += 0.5f; // Adjust speed as needed
  //  boaty +=0.5f;

    // Reset position if the boat moves out of bounds
    if (boatx > 900) {
        boatx = -100; // Reset to the left side of the screen
    }

    glutPostRedisplay();
     glutTimerFunc(15, updateBoat, 0);
}


void DisplayAirplane() {
    glPushMatrix();
    glTranslatef(airplaneX, 0, 0); // Move the airplane
    glBegin(GL_POLYGON);
   glColor3f(0.9f, 0.9f, 0.9f);  // Light Gray (Bright enough to be visible)

    glVertex2f(120,810);//1
    glVertex2f(130,810);//2
    glVertex2f(141,788);//3
    glVertex2f(135,760);//4
    glVertex2f(120,810);//5
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(120,810);//1
    glVertex2f(130,810);//2
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
 glVertex2f(130,810);//2
    glVertex2f(141,788);//3
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
 glVertex2f(120,810);//1
 glVertex2f(135,760);//4
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.6f, 0.8f);  // Soft blue tint
    glVertex2f(141,788);//1
    glVertex2f(200,810);//2
    glVertex2f(220,780);//3
     glVertex2f(135,760);//4
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(141,788);//1
    glVertex2f(200,810);//2
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
       glVertex2f(200,810);//2
    glVertex2f(220,780);//3
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(220,780);//3
     glVertex2f(135,760);//4
    glEnd();

    glBegin(GL_TRIANGLES);
     glColor3f(1.0f, 0.9f, 0.6f); // Warm yellow-orange
    glVertex2f(200,810);//2
    glVertex2f(200,790);//2
    glVertex2f(213,790);//2
  glEnd();
          glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
     glVertex2f(213,790);//2
    glVertex2f(130,763);//4
    glEnd();
 glPopMatrix();
}

void updateAriplane(int value) {
    if (isNight) {
        airplaneX += planeSpeed; // Move right
        if (airplaneX > 900) { // Reset when it goes out of bounds
            airplaneX = -200;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(15, updateAriplane, 0); // Call update every 16ms (approx 60 FPS)
}

void DisplayCar() {/////////////----------------------------------------->Car
    glPushMatrix();
    glTranslatef(carpos, 0.0f, 0.0f);
    if(isNight){
        glColor3f(0.5f, 0.0f, 0.0f);  // Dark red (burgundy) at night
    }else{
        glColor3f(1.0, 0.0, 0.0); // Red car body
    }

    glBegin(GL_POLYGON);
        glVertex2f(60,195);//1
        glVertex2f(60,230);//2
        glVertex2f(80, 230);//3
        glVertex2f(95,255);//4
        glVertex2f(135,255);//5
        glVertex2f(150,230);//6
        glVertex2f(170,230);//7
        glVertex2f(170, 195);   // 8

    glEnd();
    //first car front flesh
    glBegin(GL_QUADS);
if (isNight) {
    glColor4f(1.0f, 1.0f, 0.0f, 0.6f);  // Yellow with some transparency for glowing effect
} else {
     glColor4f(0.6, 0.8, 1.0, 0.5);
}

    glVertex2f(170,212);
    glVertex2f(170,217);
    glVertex2f(165,217);
    glVertex2f(165,212);
    glEnd();

// glass of the car
    glBegin(GL_QUADS);
    if(isNight){
   glColor3f(0.56f, 0.56f, 0.24f);  // Olive yellow
    }else{
        glColor4f(0.6, 0.8, 1.0, 0.5);
    }
    glVertex2f(85,230);
    glVertex2f(112,230);
    glVertex2f(112,250);
    glVertex2f(95,250);
    glEnd();

    glBegin(GL_QUADS);
    if(isNight){
   glColor3f(0.56f, 0.56f, 0.24f);  // Olive yellow
    }else{
        glColor4f(0.6, 0.8, 1.0, 0.5);
    }
    glVertex2f(115,230);
    glVertex2f(115,250);
    glVertex2f(135,250);//5
   glVertex2f(145,230);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    float wheelRadius = 15.0f;


    glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float angle = i * 3.14159 / 180;
            glVertex2f(90 + cos(angle) * wheelRadius, 200 + sin(angle) * wheelRadius);
        }
    glEnd();

    glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float angle = i * 3.14159 / 180;
            glVertex2f(140 + cos(angle) * wheelRadius, 200 + sin(angle) * wheelRadius);
        }
    glEnd();
    glColor3f(0.75, 0.75, 0.75);
    float hubRadius = 7.0f;

    glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float angle = i * 3.14159 / 180;
            glVertex2f(90 + cos(angle) * hubRadius, 200 + sin(angle) * hubRadius);
        }
    glEnd();

    // Silver circle (hub) in the middle of the right wheel
    glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float angle = i * 3.14159 / 180;
            glVertex2f(140 + cos(angle) * hubRadius, 200 + sin(angle) * hubRadius);
        }
    glEnd();

glPopMatrix();
     ////////////car-2/////////
        glPushMatrix();
    glTranslatef(carpos2, 0.0f, 0.0f);
if(isNight){
    glColor3f(0.3f, 0.0f, 0.3f);  // Deep purple at night
}else{
      glColor3f(0.5, 0.0, 0.5); // Red car body
}

    glBegin(GL_POLYGON);
        glVertex2f(210, 195); // 1 for car 2
        glVertex2f(210, 230); // 2 for car 2
        glVertex2f(230, 230); // 3 for car 2
        glVertex2f(245, 255); // 4 for car 2
        glVertex2f(285, 255); // 5 for car 2
        glVertex2f(300, 230); // 6 for car 2
        glVertex2f(320, 230); // 7 for car 2
        glVertex2f(320, 195); // 8 for car 2
    glEnd();
    glBegin(GL_QUADS);
    if (isNight) {
    glColor4f(1.0f, 1.0f, 0.0f, 0.6f);  // Yellow with some transparency for glowing effect
} else {
     glColor4f(0.6, 0.8, 1.0, 0.5);
}    glVertex2f(320, 212); // 8 for car 2
    glVertex2f(320, 217); // 8 for car 2
     glVertex2f(317, 217); // 7 for car 2
     glVertex2f(317, 212); // 8 for car 2

    glEnd();

    glBegin(GL_QUADS);
     if(isNight){
   glColor3f(0.72f, 0.53f, 0.04f);  // Dark golden yellow

    }else{
        glColor4f(0.6, 0.8, 1.0, 0.5);
    }

        glVertex2f(235, 230);
        glVertex2f(262, 230);
        glVertex2f(262, 250);
        glVertex2f(245, 250);
    glEnd();

    glBegin(GL_QUADS);
     if(isNight){
   glColor3f(0.72f, 0.53f, 0.04f);  // Dark golden yellow

    }else{
        glColor4f(0.6, 0.8, 1.0, 0.5);
    }

        glVertex2f(265, 230);
        glVertex2f(265, 250);
        glVertex2f(285, 250);
        glVertex2f(295, 230);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    wheelRadius = 15.0f;


    glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float angle = i * 3.14159 / 180;
            glVertex2f(240 + cos(angle) * wheelRadius, 200 + sin(angle) * wheelRadius);
        }
    glEnd();


    glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float angle = i * 3.14159 / 180;
            glVertex2f(290 + cos(angle) * wheelRadius, 200 + sin(angle) * wheelRadius);
        }
    glEnd();

    glColor3f(0.75, 0.75, 0.75);


    glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float angle = i * 3.14159 / 180;
            glVertex2f(240 + cos(angle) * 7.0f, 200 + sin(angle) * 7.0f);
        }
    glEnd();


    glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float angle = i * 3.14159 / 180;
            glVertex2f(290 + cos(angle) * 7.0f, 200 + sin(angle) * 7.0f);
        }
    glEnd();

glPopMatrix();

     //////////////////////////


}
void updateCarPosition(int value) {

        if (isGreen) {
        carpos += 1.0f;
        if(!isNight){
        carpos += carSpeed;


        if (carpos > 900) {
            carpos = -200;
        }
         glutPostRedisplay();
        }
        if (carpos > 900) {
            carpos = -200;
        }
}

    glutPostRedisplay();

    glutTimerFunc(20, updateCarPosition, 0);

}
void updateCarPosition2(int value) {
         if (isGreen) {
        carpos2 += 2.0f;
        if(!isNight){
        carpos2 += carSpeed;
        }

        if (carpos2 > 900) {
            carpos2 = -200;
        }
}

    glutPostRedisplay();
    glutTimerFunc(25, updateCarPosition2, 0);
}

/////////////
void DisplayStars() {//------------------------------------------>Stars
    glPointSize(2.3f); // Adjust star size
    glBegin(GL_POINTS);

    glColor3f(1.0f, 1.0f, 1.0f); // Bright white color for stars
    glVertex2f(60,800);
    glVertex2f(90,830);
    glVertex2f(100,850);
    glVertex2f(120,800);
    glVertex2f(150,780);
    glVertex2f(180,760);
    glVertex2f(200,810);
    glVertex2f(210,700);
    glVertex2f(400,850);
    glVertex2f(420,800);
    glVertex2f(450,780);
    glVertex2f(480,760);
    glVertex2f(500,810);
    glVertex2f(510,700);
    glVertex2f(530,850);
    glVertex2f(580,800);
    glVertex2f(550,780);
    glVertex2f(680,760);
    glVertex2f(600,810);
    glVertex2f(610,700);

    glVertex2f(900,780);
    glVertex2f(930,760);
    glVertex2f(980,810);
    glVertex2f(990,700);

    glEnd();
}
//------------------------------------->>Ferrieswhelll


void updateRotation(int value) {
    if(isNight){
    rotationAngle += 2.0f;
    if (rotationAngle > 360.0f) {
        rotationAngle -= 360.0f;
    }
    glutPostRedisplay();
    } // Redraw the scene
    glutTimerFunc(100, updateRotation, 0);

}
///////////mouse motion////////
void mouseMotion(int x, int y) {
    if(!isNight){
    if (prevMouseX == -1) {
        prevMouseX = x;
        return;
    }
    if (x > prevMouseX) {
        rotationAngle -= 1.0f; // Move clockwise
    } else if (x < prevMouseX) {
        rotationAngle += 1.0f; // Move counterclockwise
    }

    prevMouseX = x; // Update previous position
    glutPostRedisplay(); // Redraw scene
    }
}


////////////////
void DrawRoad(){
        // Draw the road
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.2f, 0.3f); // Road color
    glVertex2f(0, 180);
    glVertex2f(70, 270);
    glVertex2f(900, 270);
    glVertex2f(900, 180);
    glEnd();

    // Draw white road segments
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int x = 31; x <= 900; x += 50) {
        glBegin(GL_QUADS);
        glVertex2f(x, 225);
        glVertex2f(x + 25, 225);   // Width of the white segment
        glVertex2f(x + 29, 228);
        glVertex2f(x + 4, 228);
        glEnd();
    }
    //glColor3f(0.1f, 0.2f, 0.3f); // Road color
    for (int x = 70; x <= 900; x += 50) {
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.2f, 0.3f); // Bar color
    glVertex2f(x, 270);
    glVertex2f(x, 288);
    glVertex2f(x + 4, 288);
    glVertex2f(x + 4, 270);
    glEnd();
    }

    if (isNight) {
    for (int x = 70; x <= 900; x += 50){
        float lightX = x + 2.0f;
        float lightY = 279.0f;
        glPointSize(3.0f);
        glColor3f(1.0f, 1.0f, 0.0f);
        glBegin(GL_POINTS);
        glVertex2f(lightX, lightY);
        glEnd();
    }
}


    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.2f, 0.3f);
    glVertex2f(70, 288);
    glVertex2f(73, 294);
    glVertex2f(900, 294);
    glVertex2f(900, 288);
    glEnd();

}

void traficlight(){
    //Stand of the lamp post
   glBegin(GL_QUADS);
   glColor3f(0.1f, 0.2f, 0.3f);
   glVertex2f(820,288);
   glVertex2f(824,288);
 glVertex2f(824,345);
   glVertex2f(820,345);
    glEnd();

//where i will place the lights
    glBegin(GL_POLYGON);
   glColor3f(0.1f, 0.2f, 0.3f);
    glVertex2f(820,345);
   glVertex2f(814,350);
   glVertex2f(814,390);
    glVertex2f(830,390);
   glVertex2f(830,350);
   glVertex2f(824,345);
    glEnd();

    //Green color bulb
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        if(isGreen){
             glColor4f(0.0f, 1.0f, 0.0f, 1.0f);  // Green color
        }else{
            glColor4f(0.6, 0.8, 1.0, 0.5);
        }

        float angle = i * 3.14159 / 180;
        float x = 822 + cos(angle) * 4.5f;
        float y = 355 + sin(angle) * 4.5f;
        glVertex2f(x,y);
    }

    glEnd();
    //red color bulb
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        if(isRed){
            glColor4f(1.0f, 0.0f, 0.0f, 1.0f);  // Red color
        }else{
            glColor4f(0.6, 0.8, 1.0, 0.5);
        }

        float angle = i * 3.14159 / 180;
        float x = 822 + cos(angle) * 4.5f;
        float y = 375 + sin(angle) * 4.5f;
        glVertex2f(x,y);
    }

    glEnd();

}
void DisplaySea(){
        glBegin(GL_POLYGON);
        if(isNight){
        glColor3f(0.1f, 0.3f, 0.5f);  // Softer blue-green for water at night
        }else{
    glColor3f(0.0f, 0.5f, 1.0f); // Sea water color (bright blue)
        }
    glVertex2f(0, 0);  // Start at a reasonable position
    glVertex2f(30, 25);
    glVertex2f(60, 35);
    glVertex2f(90, 55);
    glVertex2f(120, 68);
    glVertex2f(150, 72);
    glVertex2f(180, 78);
    glVertex2f(210, 82);
    glVertex2f(240, 90);
    glVertex2f(270, 98);
    glVertex2f(300, 108);
    glVertex2f(330, 120);
    glVertex2f(360, 160);
    glVertex2f(390, 170);
    glVertex2f(420, 180);
    glVertex2f(450, 180);
    glVertex2f(900, 180);
    glVertex2f(900, 0);
    glEnd();
//upper sea
    glBegin(GL_POLYGON);
    if(isNight){
        glColor3f(0.1f, 0.3f, 0.5f);  // Softer blue-green for water at night
        }else{
    glColor3f(0.0f, 0.5f, 1.0f); // Sea water color (bright blue)
        }
    glVertex2f(580,270);
    glVertex2f(650,320);
    glVertex2f(680,330);
    glVertex2f(710,390);
    glVertex2f(740,440);
    glVertex2f(770,450);
    glVertex2f(800,400);
    glVertex2f(830,500);

    glVertex2f(900,600);
    glVertex2f(900,270);
      glEnd();
//<--------------sea End---------------------->
}

void DisplayPillers(){
        glBegin(GL_QUADS);
        if(isNight){
            glColor3f(0.4f, 0.3f, 0.1f);
        }else{
    glColor3f(0.6f, 0.4f, 0.2f); // Brown
        }
    for (int x = 450; x <= 810; x += 90) {
        glVertex2f(x, 0);
        glVertex2f(x + 30, 0);
        glVertex2f(x + 30, 150);
        glVertex2f(x, 150);
    }
    glEnd();

    glBegin(GL_QUADS);
    if(isNight){
            glColor3f(0.4f, 0.3f, 0.1f);
        }else{
    glColor3f(0.6f, 0.4f, 0.2f); // Brown
        }
    for (int x = 450; x <= 810; x += 90) {
        glVertex2f(x, 150);
        glVertex2f(x + 30, 150);
        glVertex2f(x + 37, 182);
        glVertex2f(x - 7, 182);
    }
    glEnd();
}
void DsiplaySand(){
  glBegin(GL_POLYGON);
  if(isNight){
         glColor3f(0.6f, 0.5f, 0.3f); // Dim orange
  }else{

       glColor3f(0.96f, 0.87f, 0.70f); // Light beige
  }
    glVertex2f(0, 0);
    glVertex2f(30, 25);
    glVertex2f(60, 35);
    glVertex2f(90, 55);
    glVertex2f(120, 68);
    glVertex2f(150, 72);
    glVertex2f(180, 78);
    glVertex2f(210, 82);
    glVertex2f(240, 90);
    glVertex2f(270, 98);
    glVertex2f(300, 108);
    glVertex2f(330, 120);
    glVertex2f(360, 160);
    glVertex2f(390, 170);
    glVertex2f(420, 180);
    glVertex2f(450, 180);
    glVertex2f(0, 180);
    glEnd();
    glBegin(GL_POLYGON);

    if(isNight){
         glColor3f(0.6f, 0.5f, 0.3f); // Dim orange
  }else{

       glColor3f(0.96f, 0.87f, 0.70f); // Light beige
  }
    glVertex2f(0, 510);
    glVertex2f(30, 520);
    glVertex2f(60, 530);
    glVertex2f(90, 540);
    glVertex2f(120, 530);
    glVertex2f(150, 520);
    glVertex2f(180, 510);
    glVertex2f(190, 540);
    glVertex2f(220, 520);
    glVertex2f(270, 520);
    glVertex2f(300, 530);
    glVertex2f(330, 540);
    glVertex2f(360, 500);
    glVertex2f(390, 520);
    glVertex2f(420, 540);
    glVertex2f(450, 550);
    glVertex2f(480, 520);
    glVertex2f(510, 510);
    glVertex2f(540, 500);
    glVertex2f(570, 510);
    glVertex2f(600, 520);
    glVertex2f(630, 530);
    glVertex2f(660, 540);
    glVertex2f(690, 530);
    glVertex2f(720, 520);
    glVertex2f(750, 510);
    glVertex2f(780, 530);
    glVertex2f(810, 550);
    glVertex2f(840, 560);
    glVertex2f(870, 580);
    glVertex2f(900, 600);
    glVertex2f(570, 270);
    glVertex2f(0, 270);
    glEnd();

    glBegin(GL_POLYGON);
    if(isNight){
         glColor3f(0.6f, 0.5f, 0.3f); // Dim orange
  }else{

       glColor3f(0.96f, 0.87f, 0.70f); // Light beige
  }
    glVertex2f(0, 270);
    glVertex2f(70, 270);
    glVertex2f(0, 180);
    glEnd();
}

void DisplaySun(){
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.65f, 0.0f);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 180;
        float r = 45;
        float x = 690.0f + r * cos(A);
        float y = sunY + r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();

}
void updateSun(int value) {
    if (sunMoving && isSunset) {
        sunY -= 2.0f; // Move the sun down
        if (sunY <= 470.0f) {
            isSunset = false;
            isNight = true;
            glutPostRedisplay(); // Redraw the scene
        }
    }

    glutPostRedisplay();
    glutTimerFunc(50, updateSun, 0);
}

void Displaytables(){

    glColor3f(0.9f, 0.8f, 0.7f); // Softer Beige
glBegin(GL_QUADS);
glVertex2f(555,390);
glVertex2f(570,420);
glVertex2f(585,390);
glVertex2f(570,360);
glEnd();
glLineWidth(3.0f);
glBegin(GL_LINES);
 glColor3f(0.5f, 0.3f, 0.2f); // Darker Brown for legs
glVertex2f(614,379);
glVertex2f(614,367);
glEnd();
glColor3f(0.8f, 0.6f, 0.4f); // Wooden Brown
glBegin(GL_QUADS);
glVertex2f(585,390);
glVertex2f(615,381);
glVertex2f(600,350);
glVertex2f(570,360);

glEnd();


glBegin(GL_LINES);
 glColor3f(0.5f, 0.3f, 0.2f); // Darker Brown for legs
glVertex2f(599,350);
glVertex2f(599,340);
glEnd();
glBegin(GL_LINES);
 glColor3f(0.5f, 0.3f, 0.2f); // Darker Brown for legs
glVertex2f(572,360);
glVertex2f(572,350);
glEnd();

//////////////

glLineWidth(1.0f);
}
////////////////



void DisplayBuildings(){
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.94f); // Ivory
    glVertex2f(50,480);
    glVertex2f(120,480);
    glVertex2f(120,660);
    glVertex2f(50,660);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.94f);
    glVertex2f(120,480);
    glVertex2f(120,660);
    glVertex2f(133,670);
    glVertex2f(133,490);
    glEnd();
//roof
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.4f, 0.2f); // Terracotta
     glVertex2f(50,660);
     glVertex2f(75,670);
     glVertex2f(133,670);
      glVertex2f(120,660);
      glEnd();

    if(isNight){
         glBegin(GL_QUADS);
    glColor3f(1.0f, 0.9f, 0.6f); // Warm yellow-orange

    for(int y=500; y<=640; y+=25){
        glVertex2f(50,y);
        glVertex2f(120,y);
        glVertex2f(120,y+10);
        glVertex2f(50,y+10);

}
    glEnd();
    }else{
           glBegin(GL_QUADS);
    glColor4f(0.2f, 0.2f, 0.2f, 1.0f); // Charcoal Gray
    for(int y=500; y<=640; y+=25){
        glVertex2f(50,y);
        glVertex2f(120,y);
        glVertex2f(120,y+10);
        glVertex2f(50,y+10);

}
     glEnd();
    }


     //Building -2
    glBegin(GL_QUADS);
glColor4f(0.604f, 0.796f, 0.816f, 1.0f);


     glVertex2f(133,670);
    glVertex2f(133,490);
     glVertex2f(240,490);
      glVertex2f(240,670);
      glEnd();

      //side part
       glBegin(GL_QUADS);
glColor4f(0.827f, 0.733f, 0.627f, 1.0f);

    glVertex2f(240,490);
      glVertex2f(240,670);
     glVertex2f(250,660);
      glVertex2f(250,490);
      glEnd();


      if(isNight){
        glBegin(GL_QUADS);
 glColor3f(1.0f, 0.9f, 0.6f); // Warm yellow-orange


    for(int y=500; y<=640; y+=25){
        glVertex2f(133,y);
        glVertex2f(240,y);
        glVertex2f(240,y+10);
        glVertex2f(133,y+10);

    }
    glEnd();



    }else{
           glBegin(GL_QUADS);
    glColor4f(0.2f, 0.2f, 0.2f, 1.0f); // Charcoal Gray
    for(int y=500; y<=640; y+=25){
        glVertex2f(133,y);
        glVertex2f(240,y);
        glVertex2f(240,y+10);
        glVertex2f(133,y+10);

}
     glEnd();
    }
//////building--3//////
glBegin(GL_QUADS);
    glColor3f(0.239f, 0.239f, 0.239f); // Dark Gra
    //glColor3f(0.651f, 0.804f, 0.776f); // RGB equivalent of #A6CDC6

    glVertex2f(500,540);
    glVertex2f(500,680);
    glVertex2f(575,680);
    glVertex2f(575,540);
    glEnd();
    ////baranda///////
     glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.f, 0.f, 0.f); // Frosted Glass
    glVertex2f(495,715);
    glVertex2f(577,715);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    for(int x = 500; x<575; x+=20){
    glColor3f(0.f, 0.f, 0.f); // Frosted Glass
    glVertex2f(x,680);
    glVertex2f(x,715);
    }
    glEnd();
//////////glass/////////
glBegin(GL_QUADS);
if(isNight){
    glColor4f(0.9f, 0.8f, 0.6f, 0.5f); // Slightly warmer, with light coming through

}else{
      glColor4f(0.8f, 0.8f, 0.8f, 0.5f); // Frosted Glass
}
    glVertex2f(510,550);
    glVertex2f(510,670);
    glVertex2f(565,670);
    glVertex2f(565,550);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.f, 0.f, 0.f); // Frosted Glass
    glVertex2f(510,550);
    glVertex2f(510,670);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.086f, 0.251f, 0.302f); // Deep Teal Blue
    for(int x = 530; x<565; x+=19 ){
    glVertex2f(x,550);
    glVertex2f(x,670);
    }
    glEnd();

   glLineWidth(2);
    glBegin(GL_LINES);
   glColor3f(0.086f, 0.251f, 0.302f); // Deep Teal Blue
    glVertex2f(510,610);
    glVertex2f(565,610);
    glEnd();



    glBegin(GL_LINES);
    glColor3f(0.f, 0.f, 0.f); // Frosted Glass
glVertex2f(510,670);
    glVertex2f(565,670);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.f, 0.f, 0.f);
glVertex2f(510,670);
    glVertex2f(565,670);
    glEnd();
    glLineWidth(1);

        glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.f, 0.f, 0.f);
  glVertex2f(565,670);
    glVertex2f(565,550);
    glEnd();
    glLineWidth(1);

         glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.f, 0.f, 0.f);
glVertex2f(510,550);
 glVertex2f(565,550);
    glEnd();
    glLineWidth(1);


/////learg part///////////
    glBegin(GL_QUADS);
    glColor3f(0.239f, 0.239f, 0.239f); // Dark Gray
     glVertex2f(575,540);
    glVertex2f(575,780);
    glVertex2f(675,780);
    glVertex2f(675,540);
    glEnd();

      glBegin(GL_QUADS);
   if(isNight){
    glColor4f(0.9f, 0.8f, 0.6f, 0.5f); // Slightly warmer, with light coming through

}else{
      glColor4f(0.8f, 0.8f, 0.8f, 0.5f); // Frosted Glass
}
     glVertex2f(610,710);
    glVertex2f(610,760);
    glVertex2f(650,760);
    glVertex2f(650,710);
    glEnd();
    glLineWidth(2);
     glBegin(GL_LINES);
    glColor3f(0.f, 0.f, 0.f);
    for(int x=610; x<=650; x+=20){
    glVertex2f(x,710);
    glVertex2f(x,760);
    }
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.f, 0.f, 0.f);
    for(int y=710; y<=760; y+=25){
    glVertex2f(610,y);
    glVertex2f(650,y);
    }
    glEnd();

    ////glass at learch part////
     glBegin(GL_QUADS);
    if(isNight){
    glColor4f(0.9f, 0.8f, 0.6f, 0.5f); // Slightly warmer, with light coming through

}else{
      glColor4f(0.8f, 0.8f, 0.8f, 0.5f); // Frosted Glass
}
     glVertex2f(610,540);
    glVertex2f(610,660);
    glVertex2f(650,660);
    glVertex2f(650,540);
    glEnd();

    ////border at leargs glass pert//
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.f, 0.f, 0.f);
    glVertex2f(610,540);
    glVertex2f(610,660);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.f, 0.f, 0.f);
    glVertex2f(610,660);
    glVertex2f(650,660);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.f, 0.f, 0.f);
    glVertex2f(650,660);
    glVertex2f(650,540);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.f, 0.f, 0.f);
   glVertex2f(630,540);
   glVertex2f(630,660);
    glEnd();

     ///////////lest to right border/////
    glBegin(GL_QUADS);
glColor3f(0.341f, 0.557f, 0.494f); // Muted Teal-Green

    glVertex2f(495,680);
    glVertex2f(495,685);
    glVertex2f(675,685);
    glVertex2f(675,680);
    glEnd();
    //////left top to botom////////
      glBegin(GL_QUADS);
glColor3f(0.341f, 0.557f, 0.494f); // Muted Teal-Green
    glVertex2f(575,540);
    glVertex2f(575,780);
    glVertex2f(580,780);
    glVertex2f(580,540);
    glEnd();

    //top right to left//////
    glBegin(GL_QUADS);
glColor3f(0.341f, 0.557f, 0.494f); // Muted Teal-Green

    glVertex2f(575,780);
    glVertex2f(575,785);
    glVertex2f(675,785);
    glVertex2f(675,780);
    glEnd();
    ////left top to bottom border
      glBegin(GL_QUADS);
glColor3f(0.341f, 0.557f, 0.494f); // Muted Teal-Green
    glVertex2f(675,785);
    glVertex2f(680,785);
    glVertex2f(680,540);
    glVertex2f(675,540);

    glEnd();

    //////////////////
     glBegin(GL_QUADS);
   glColor3f(0.302, 0.627, 0.659);
    glVertex2f(50,340);
    glVertex2f(50,480);
    glVertex2f(240,480);
    glVertex2f(240,340);
    glEnd();
    ////borders
      glBegin(GL_QUADS);
    glColor3f(0.475, 0.843, 0.745);
    glVertex2f(45,472);
    glVertex2f(45,480);
    glVertex2f(245,480);
    glVertex2f(245,472);
    glEnd();

 glBegin(GL_QUADS);
 if(isNight){
    glColor4f(0.9f, 0.8f, 0.6f, 0.5f); // Slightly warmer, with light coming through

}else{
      glColor4f(0.8f, 0.8f, 0.8f, 0.5f); // Frosted Glass
}
    glVertex2f(200,340);//1
    glVertex2f(200,440);//2
    glVertex2f(230,440);//3
    glVertex2f(230,340);//4
    glEnd();

     glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
     glVertex2f(200,340);//1
    glVertex2f(200,440);//2
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
 glVertex2f(200,440);//2
    glVertex2f(230,440);//3
    glEnd();

      glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(230,440);//3
    glVertex2f(230,340);//4
    glEnd();


      glBegin(GL_QUADS);
 if(isNight){
    glColor4f(0.9f, 0.8f, 0.6f, 0.5f); // Slightly warmer, with light coming through

}else{
      glColor4f(0.8f, 0.8f, 0.8f, 0.5f); // Frosted Glass
}
    glVertex2f(70,360);
    glVertex2f(70,460);
    glVertex2f(165,460);
    glVertex2f(165,360);
    glEnd();

    glLineWidth(2);
    for(int x = 70; x<=165; x+= 19){
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(x,360);
    glVertex2f(x,460);
    glEnd();
    }

    glLineWidth(2);
    for(int y = 360; y<=460; y+= 50){
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(70,y);
    glVertex2f(165,y);
    glEnd();
    }

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(185,340);
    glVertex2f(185,480);
    glEnd();

    //////////////

    ////large part of building -4///////
    glBegin(GL_QUADS);
    glColor3f(0.729, 0.847, 0.714);
    glVertex2f(690,540);
    glVertex2f(690,760);
    glVertex2f(780,760);
    glVertex2f(780,540);
    glEnd();

    glBegin(GL_QUADS);
    if(isNight){
             glColor3f(1.0f, 0.9f, 0.6f); // Warm yellow-orange

    }else{
     glColor4f(0.2f, 0.2f, 0.2f, 1.0f); // Charcoal Gray
    }

    for(int y=540; y<=760; y+=30){
        glVertex2f(690,y+10);
        glVertex2f(690,y+20);
        glVertex2f(780,y+20);
        glVertex2f(780,y+10);

    }
    glEnd();

    //////////////small part of building 4//////////
      glBegin(GL_QUADS);
    glColor3f(0.816, 0.867, 0.816);
    glVertex2f(780,540);
    glVertex2f(780,690);
    glVertex2f(840,690);
    glVertex2f(840,540);
    glEnd();

     glBegin(GL_QUADS);
     if(isNight){
             glColor3f(1.0f, 0.9f, 0.6f); // Warm yellow-orange
             }else{
                glColor3f(0.678, 0.847, 0.902); // Light Sky Blue
             }
    glVertex2f(795,540);
    glVertex2f(795,660);
    glVertex2f(825,660);
    glVertex2f(825,540);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(795,540);
    glVertex2f(795,660);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(795,660);
    glVertex2f(825,660);
    glEnd();

      glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
   glVertex2f(825,660);
    glVertex2f(825,540);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
  glVertex2f(810,540);
    glVertex2f(810,660);
    glEnd();



}

void FerriesWheel(){
    glPushMatrix();

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(300,480);
    glVertex2f(310,480);
    glVertex2f(363,630);
    glVertex2f(350,630);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(410,480);
    glVertex2f(420,480);

    glVertex2f(370,630);
    glVertex2f(360,630);
    glEnd();

//third circle
glLineWidth(1.0f);
glBegin(GL_POLYGON);
    glColor3f(0.243f, 0.345f, 0.475f);
for (int i = 0; i < 360; i++) {
    float pi = 3.1416;
    float angle = (i * 2 * pi) / 180;
    float x = 360.0f + 22 * cos(angle);
    float y = 630.0f + 22 * sin(angle);
    glVertex2f(x, y);
}
glEnd();

//second  circle
    glBegin(GL_POLYGON);
glColor3f(0.867f, 0.659f, 0.325f); // RGB values for #DDA853
for (int i = 0; i < 360; i++) {
    float pi = 3.1416;
    float angle = (i * 2 * pi) / 180;
    float x = 360.0f + 15 * cos(angle);
    float y = 630.0f + 15 * sin(angle);
    glVertex2f(x, y);
}
glEnd();
//first circle
    glBegin(GL_POLYGON);
glColor3f(0.086f, 0.251f, 0.302f);
for (int i = 0; i < 360; i++) {
    float pi = 3.1416;
    float angle = (i * 2 * pi) / 180;
    float x = 360.0f + 10 * cos(angle);
    float y = 630.0f + 10 * sin(angle);
    glVertex2f(x, y);
}
glEnd();

    glTranslatef(360.0f, 630.0f, 0.0f);
    glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-360.0f, -630.0f, 0.0f);
    //fourth circel
    glLineWidth(4.0f);
    glBegin(GL_LINE_LOOP);
   glColor3f(1.0f, 0.839f, 0.353f);
    for (int i = 0; i < 360; i++) {
    float pi = 3.1416;
    float angle = (i * 2 * pi) / 180;
    float x = 360.0f + 48 * cos(angle);
    float y = 630.0f + 48 * sin(angle);
    glVertex2f(x, y);
}
glEnd();
glLineWidth(1.0f);
int gap = 20;
//////////////////////
    for (int i = 0; i < 360; i += gap) {
    float pi = 3.1416;
    float angle = (i * 2 * pi) / 180;


    float x2 = 360.0f + 75 * cos(angle);
    float y2 = 630.0f + 75 * sin(angle);


    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    float seatX = 10.0f;
    float seatY = 10.0f;

    glVertex2f(x2 - seatX , y2 - seatY );
    glVertex2f(x2 + seatX , y2 - seatY );
    glVertex2f(x2 + seatX , y2 + seatY );
    glVertex2f(x2 - seatX , y2 + seatY );
    glEnd();
}

/////////////////////
for (int i = 0; i < 360; i += gap) {
    float pi = 3.1416;
    float angle = (i * 2 * pi) / 180;

    // First Circle's outer edge
    float x1 = 360.0f + 22 * cos(angle);
    float y1 = 630.0f + 22 * sin(angle);

    // Second Circle's outer edge
    float x2 = 360.0f + 75 * cos(angle);
    float y2 = 630.0f + 75 * sin(angle);


    glBegin(GL_LINES);
    glColor3f(0.243f, 0.345f, 0.475f);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}


//last circle
    glLineWidth(4.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.494f, 0.361f, 0.678f);
    for (int i = 0; i < 360; i++) {
    float pi = 3.1416;
    float angle = (i * 2 * pi) / 180;
    float x = 360.0f + 75 * cos(angle);
    float y = 630.0f + 75 * sin(angle);
    glVertex2f(x, y);

}
 glEnd();
 glLineWidth(1.0f);
glPopMatrix();
glutSwapBuffers();
}

void DisplayCloud(){
    glBegin(GL_POLYGON);
glColor3f(0.9f, 0.9f, 0.9f); // Light gray (cloud color)
for (int i = 0; i < 360; i++) {
    float pi = 3.1416;
    float A = (i * 2 * pi) / 180;
    float r = 25;
    float x = 650.0f + r * cos(A);
    float y = 820.0f + r * sin(A);
    glVertex2f(x, y);
}
glEnd();

glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
    float pi = 3.1416;
    float A = (i * 2 * pi) / 180;
    float r = 20;
    float x = 670.0f + r * cos(A);
    float y = 830.0f + r * sin(A);
    glVertex2f(x, y);
}
glEnd();

glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
    float pi = 3.1416;
    float A = (i * 2 * pi) / 180;
    float r = 30;
    float x = 690.0f + r * cos(A);
    float y = 820.0f + r * sin(A);
    glVertex2f(x, y);
}
glEnd();

// Cloud 2
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
    float pi = 3.1416;
    float A = (i * 2 * pi) / 180;
    float r = 20;
    float x = 730.0f + r * cos(A);
    float y = 790.0f + r * sin(A);
    glVertex2f(x, y);
}
glEnd();

glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
    float pi = 3.1416;
    float A = (i * 2 * pi) / 180;
    float r = 25;
    float x = 750.0f + r * cos(A);
    float y = 800.0f + r * sin(A);
    glVertex2f(x, y);
}
glEnd();

glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
    float pi = 3.1416;
    float A = (i * 2 * pi) / 180;
    float r = 18;
    float x = 710.0f + r * cos(A);
    float y = 805.0f + r * sin(A);
    glVertex2f(x, y);
}
glEnd();

// Cloud at ortho(300, 750)
glPushMatrix();
glTranslatef(cloudX-300,0.0f, 0.0f);  // Move the cloud in x-direction
glBegin(GL_POLYGON);
glColor3f(0.9f, 0.9f, 0.9f); // Light Gray for the cloud
for (int i = 0; i < 360; i++) {
    float angle = i * 3.1416 / 180.0;
    float x = 300 + 40 * cos(angle); // Central part of the cloud
    float y = 750 + 40 * sin(angle);
    glVertex2f(x, y);
}
glEnd();

glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
    float angle = i * 3.1416 / 180.0;
    float x = 350 + 40 * cos(angle); // Right part of the cloud
    float y = 750 + 40 * sin(angle);
    glVertex2f(x, y);
}
glEnd();

glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
    float angle = i * 3.1416 / 180.0;
    float x = 310 + 40 * cos(angle); // Left part of the cloud
    float y = 790 + 40 * sin(angle);
    glVertex2f(x, y);
}
glEnd();

glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
    float angle = i * 3.1416 / 180.0;
    float x = 360 + 40 * cos(angle); // Top part of the cloud
    float y = 790 + 40 * sin(angle);
    glVertex2f(x, y);
}
glEnd();
glPopMatrix();
//////////////////////////////////////////////////
 glBegin(GL_POLYGON);


    // Draw a cloud as a series of circles around the center (120, 750)
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416;
        float angle = (i * 2 * pi) / 180;
        float x = 120 + 30 * cos(angle); // Change 30 for cloud size
        float y = 750 +30 * sin(angle); // Change 15 for cloud height
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_POLYGON);


    // Draw a cloud as a series of circles around the center (120, 750)
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416;
        float angle = (i * 2 * pi) / 180;
        float x = 90 + 30 * cos(angle); // Change 30 for cloud size
        float y = 750 +30 * sin(angle); // Change 15 for cloud height
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_POLYGON);


    // Draw a cloud as a series of circles around the center (120, 750)
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416;
        float angle = (i * 2 * pi) / 180;
        float x = 140 + 30 * cos(angle); // Change 30 for cloud size
        float y = 780 +30 * sin(angle); // Change 15 for cloud height
        glVertex2f(x, y);
    }
    glEnd();
glBegin(GL_POLYGON);


    // Draw a cloud as a series of circles around the center (120, 750)
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416;
        float angle = (i * 2 * pi) / 180;
        float x = 100 + 30 * cos(angle); // Change 30 for cloud size
        float y = 770 +30 * sin(angle); // Change 15 for cloud height
        glVertex2f(x, y);
    }
    glEnd();



}

void updatecloud(int value) {
 if (isNight && isCloudMoving ) {
        if (cloudX > 120) {
            cloudX -= 0.5f;
        }
    }

    glutPostRedisplay();  // Request a redraw
    glutTimerFunc(16, updatecloud, 0);  // Call the update function again after 16 ms (~60 FPS)
}



void drawline(){
      float gridSize = 900.0f / 30.0f;
    for (int i = 0; i <= 30; ++i) {
        float x = i * gridSize;
        if (i % 5 == 0) {
            glColor3f(1.0f, 0.0f, 0.0f); // Red for every 5th line
        } else {
            glColor3f(0.5f, 0.5f, 0.5f); // Grey for other lines
        }
        glBegin(GL_LINES);
        glVertex2f(x, 0);
        glVertex2f(x, 900);
        glEnd();
    }

    for (int i = 0; i <= 30; ++i) {
        float y = i * gridSize;
        if (i % 5 == 0) {
            glColor3f(1.0f, 0.0f, 0.0f); // Red for every 5th line
        } else {
            glColor3f(0.5f, 0.5f, 0.5f); // Grey for other lines
        }
        glBegin(GL_LINES);
        glVertex2f(0, y);
        glVertex2f(900, y);
        glEnd();
    }
}

void displayBirds(){
    glPushMatrix();
    glTranslatef(birdX, 0.0f, 0.0f);  // Move birds horizontally
glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(30,840);
glVertex2f(26,844);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(30,840);
glVertex2f(36,844);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(30,846);
glVertex2f(26,850);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(30,846);
glVertex2f(36,850);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(35,846);
glVertex2f(31,850);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(35,846);
glVertex2f(39,850);
glEnd();

// Birds 4
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(50, 855);
    glVertex2f(46, 859);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(50, 855);
    glVertex2f(56, 859);
    glEnd();

    // Birds 5
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(55, 845);
    glVertex2f(51, 849);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(55, 845);
    glVertex2f(59, 849);
    glEnd();

    // Birds 6
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(65, 860);
    glVertex2f(61, 864);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(65, 860);
    glVertex2f(69, 864);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(75, 850);
    glVertex2f(71, 854);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(75, 850);
    glVertex2f(79, 854);
    glEnd();

    // Birds 8
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(85, 845);
    glVertex2f(81, 849);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(85, 845);
    glVertex2f(89, 849);
    glEnd();

    // Birds 9
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(95, 860);
    glVertex2f(91, 864);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(95, 860);
    glVertex2f(99, 864);
    glEnd();

    // Birds 10
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(105, 855);
    glVertex2f(101, 859);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(105, 855);
    glVertex2f(109, 859);
    glEnd();
    glPopMatrix();
}
void updateBirds(int value) {
    if (!isNight) {  // Move only in the daytime
        birdX += 2.0f;  // Adjust speed here
        if (birdX >= 900) {  // Reset when it reaches ortho 900
            birdX = -100;  // Restart from left
        }
    }
    glutPostRedisplay();
    glutTimerFunc(50, updateBirds, 0);  // Call again after 50ms
}


void displayMoon(){
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 180;
        float r = 45;
        float x = 690.0f + r * cos(A);
        float y = moonY + r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();

}
void displaytext(){

glColor3f(0.0f, 0.0f, 0.0f);
glRasterPos2f(65, 640);
const char *text = "Sea View";
for (const char *c = text; *c != '\0'; c++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
}
    glColor3f(0.0f, 0.0f, 0.0f);
glRasterPos2f(199, 450);
const char *text2 = "OPEN";
for (const char *c = text2; *c != '\0'; c++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);

}
}
void displaySeaView() {

    if (isNight) {
        glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Night color (dark blue)
    } else {
        glClearColor(0.5f, 0.8f, 1.0f, 1.0f); // Day color (light blue)
    }

     glClear(GL_COLOR_BUFFER_BIT);  // Clear the screen with the background color
    glLoadIdentity();
    if(isNight){
        displayMoon();
        DisplayStars();
        DisplayAirplane();
    }else{
         DisplaySun();
    }

    DisplaySea();
    DisplayBoats();
    DisplayPillers();
    displayBirds();
    DsiplaySand();
    DrawRoad();

    DisplayBuildings();
    displaytext();
    FerriesWheel();
    traficlight();

   DisplayCar();
    DisplayCloud();
    Displaytables();
     //drawline();


glFlush();


}

void Print(){
    cout<<"Press 9 for Seaview scenario, 8 for the Mountain view and 7 for the city view"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<"----------------------1 to 10 commands  for Sea view scenario-------------------- "<<endl;
    cout<<"----------------------11 to 17 commands for Mountain view scenario--------------"<<endl;
    cout<<"----------------------18 to 23 commands for Mountain view scenario--------------"<<endl;


    cout<<"1.Press d for sun set"<<endl;
    cout<<"2.Press N for toggle between Day and Night"<<endl;
    cout<<"3.press Right arrow key to increase the car speed"<<endl;
    cout<<"4.press left arrow key to decrease the car speed"<<endl;
    cout<<"5.press mouse left key hold and drag to left or right to rotate the wheel "<<endl;
    cout<<"6.Press R to turn on the red signal this will stop the cars movement"<<endl;
    cout<<"7.Press G to turn on the green signal cars will start moving"<<endl;
    cout<<"8.Press right arrow key at night to increase the airplane speed"<<endl;
    cout<<"9.Press left arrow key at night to decrease the airplane speed"<<endl;
    cout<<"10.Press mouse right key to move the cloud at night"<<endl;
    cout <<"11.Press 1 for night view" << endl;
    cout <<"12.Press 0 for day view" << endl;
    cout <<"13.Press Right Arrow red car spreed increase" << endl;
    cout <<"14.Press left Arrow red car spreed decrease" << endl;
    cout <<"15.Press UP Arrow Bus spreed increase" << endl;
    cout <<"16.Press Down Arrow Bus spreed decrease" << endl;
    cout<<"17.left click in mouse the bus vehicles will be stop in senario"<<endl;
    cout<<"18.Press left key for night mode"<<endl;
    cout<<"19.Press up key for day mode"<<endl;
    cout<<"20.Press right key for toggle car movement"<<endl;
    cout<<"21.Press down key for toggle boat movement"<<endl;
    cout<<"22.Press left key of mouse for toggle cloud movement"<<endl;
    cout<<"23.Press right key of mouse for toggle plan movement"<<endl;

}

void initSea() {
//glLoadIdentity();
    gluOrtho2D(0, 900, 0, 900);

     glMatrixMode(GL_PROJECTION);

    glMatrixMode(GL_MODELVIEW);


}

void handleSpecialKeys(int key, int x, int y) {
    if (currentScenario == 8) {  // Village scenario
        if (key == GLUT_KEY_RIGHT) {
            carSpeed += 1.0f; // Increase speed red car
        }
        else if (key == GLUT_KEY_LEFT) {
            carSpeed -= 1.0f; // Decrease speed red car
        }
        else if (key == GLUT_KEY_UP) {
            carSpeed1 += 1.0f; // Increase speed bus
        }
        else if (key == GLUT_KEY_DOWN) {
            carSpeed1 -= 1.0f; // Decrease speed bus
        }
    }
    else if (currentScenario == 9) {  // Sea view scenario
        if (!isNight) {  // If it's day
            if (key == GLUT_KEY_RIGHT) {
                carSpeed += 2.1f;  // Increase car speed
            }
            else if (key == GLUT_KEY_LEFT && carSpeed > 0) {
                carSpeed -= 1.1f;  // Decrease car speed
            }
        }
        else {  // If it's night
            if (key == GLUT_KEY_RIGHT) {
                planeSpeed += 1.0f;  // Increase plane speed
            }
            else if (key == GLUT_KEY_LEFT && planeSpeed > 0) {
                planeSpeed -= 1.0f;  // Decrease plane speed
            }
        }
    }
    else if (currentScenario == 7) {  // City scenario
        if (key == GLUT_KEY_UP) {
            glutDisplayFunc(displayCity); // City Day Mode
            glutPostRedisplay();
        }


        else if (key == GLUT_KEY_LEFT) {
            glutDisplayFunc(displayCity2); // City Night Mode
             glutPostRedisplay();
        }


        else if (key == GLUT_KEY_DOWN) {  // Toggle boat movement
            BoatMoving = !BoatMoving;
            if (BoatMoving) {
                MoveBoat(0);
            }
        }
        else if (key == GLUT_KEY_RIGHT) {  // Toggle car movement
            CarMoving = !CarMoving;
            if (CarMoving) {
                MoveCar(0);
            }
        }
    }

    glutPostRedisplay(); // Refresh screen
}


void display() {

    if (currentScenario == 8) {//villlage scene

       initVillage();
    displayVillage();

    } else if (currentScenario == 9) {//seaview scene
        initSea();
    displaySeaView();
    }
    else if(currentScenario ==7){
    init();
    //displayCity();
    }
    glFlush();
}
void handleMouse(int button, int state, int x, int y) {
    if (currentScenario == 8) {  // Village scenario
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            carSpeed = 0.0f;   // Stop red car
            carSpeed1 = 0.0f;  // Stop bus
        }
    }
    else if (currentScenario == 9) {  // Sea view scenario
        if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
            isCloudMoving = true; // Start cloud movement
        }
    }
    else if (currentScenario == 7) {  // City scenario
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            CloudMoving = !CloudMoving; // Toggle cloud movement
        }
        else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
            PlaneMoving = !PlaneMoving; // Toggle plane movement
        }
    }

    glutPostRedisplay(); // Refresh screen
}


void handleKeypress(unsigned char key, int x, int y) {
    if (key == '1') { // Night mode for village
        isNightVill = true;
    }
    else if (key == '0') { // Day mode for village
        isNightVill = false;
    }
    else if (key == '8') { // Switch to village scenario
        currentScenario = 8;
        glutDisplayFunc(displayVillage);
    }
    else if (key == '9') { // Switch to sea view scenario
        currentScenario = 9;
        glutDisplayFunc(displaySeaView);
    }
    else if(key == '7'){
        currentScenario =7;
         glutDisplayFunc(displayCity);
         //glutPostRedisplay();
    }
    else if (key == 'n' || key == 'N') { // Toggle night mode for sea view
        isNight = !isNight;
        glutPostRedisplay();
    }
    else if (key == 'd' || key == 'D') { // Start sunset movement
        if (!sunMoving) {
            sunMoving = true;
            isSunset = true;
            updateSun(0);
        }
    }
    else if (key == 'r' || key == 'R') { // Set traffic light to red
        isRed = true;
        isGreen = false;
    }
    else if (key == 'g' || key == 'G') { // Set traffic light to green
        isGreen = true;
        isRed = false;
    }

    glutPostRedisplay(); // Ensure the screen updates
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1100, 650);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Final Project");
    Print();
    glutDisplayFunc(display);

    //glutSpecialFunc(specialKeys);
    // glutKeyboardFunc(keyboard);
    glutTimerFunc(50, updateSun, 0);
    glutTimerFunc(10, updateRotation, 0);
    glutMotionFunc(mouseMotion);
    glutTimerFunc(20, updateCarPosition, 0);
    glutTimerFunc(20, updateCarPosition2, 0);
    glutTimerFunc(0, updateAriplane, 0);
    glutTimerFunc(0, updateBoat, 0);
     //glutMouseFunc(mouseright);
    glutTimerFunc(0, updatecloud, 0);
    glutTimerFunc(50, updateBirds, 0);
//////////////////////////////////////city scenario /////////////////
    init();//this init is for city view
    glutTimerFunc(100,MoveCar,0);
    glutTimerFunc(100,MoveBoat,0);
    glutTimerFunc(100,MoveCloud,0);
    glutTimerFunc(100,MovePlane,0);
    //glutSpecialFunc(SpecialInput);
   //glutMouseFunc(mouse);



    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(0, updateCar, 0);
    glutTimerFunc(0, updateCar2, 0);
    glutMouseFunc(handleMouse);
    glutSpecialFunc(handleSpecialKeys);
    glutTimerFunc(0, movewind, 0);
    /////////////////////////////////////////////////////
    glutMainLoop();
    return 0;
}

