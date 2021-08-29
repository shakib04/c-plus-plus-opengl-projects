#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

float c1xp=0.0,c1yp=0.0,c1zp=0.0;
float c2xp=0.0,c2yp=0.0,c2zp=0.0;
float p1xp=0.0,p1yp=0.0,p1zp=0.0;
float p1sxp=0.0,p1syp=0.0,p1szp=0.0;
float x=1.0;
float rxp=0.0,ryp=0.0,rzp=0.0;
float r=0.0;

float width=-940,width2=600,width3=2000;

int dnr=103,dng=155,dnb=176;
//int dnr=105,dng=105,dnb=105;
int ldr=255,ldg=255,ldb=255;
int sdr=26,sdg=71,sdb=26;
int cdr=230,cdg=234,cdb=237;
int gdr=100,gdg=171,gdb=55;
int m1r=103,m1g=155,m1b=176;
int m2r=103,m2g=155,m2b=176;
int m=0;

char school[] = "School";
char hospital[] = "Hospital";
char hotel[] = "Hotel";
char b[] = "b = Move & Speed";
char n[] = "n = Night/Day";
char e[] = "e = Exit.";
char rain[] = "Right click for Rain";

void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 902.0, 0.0, 684.0);
}

void print( float x, float y, char *st)
{
    int l,i;

    l=strlen( st ); // see how many characters are in text string.
    glColor3f(0.2,1.0,0.7);
    //glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
    }
}
//1000
void Sky( )
{
    glPushMatrix();
    glColor3ub(dnr,dng,dnb);
    glBegin(GL_QUADS);
    glVertex2i(0,684);
    glVertex2i(902,684);
    glVertex2i(902,0);
    glVertex2i(0,0);
    glEnd();
    glPopMatrix();

    glutPostRedisplay();
}
//1001
void homeWindow(int x,int y)
{
    glPushMatrix();
    glColor3ub(156,178,189);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+10,y);
    glVertex2i(x+10,y+12);
    glVertex2i(x,y+12);
    glEnd();
    glPopMatrix();
}
//1002
void homeWindow2(int x,int y)
{
    glPushMatrix();
    glColor3ub(96,131,135);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+4,y);
    glVertex2i(x+4,y+17);
    glVertex2i(x,y+17);
    glEnd();
    glPopMatrix();
}
//1003
void homeWindow3(int x,int y)
{
    glPushMatrix();
    glColor3ub(140,148,148);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+14,y);
    glVertex2i(x+14,y+13);
    glVertex2i(x,y+13);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex2i(x,y+17);
    glVertex2i(x+14,y+17);
    glVertex2i(x+14,y+30);
    glVertex2i(x,y+30);
    glEnd();
    glPopMatrix();
}
//1004
void Home()
{
    glPushMatrix();
    glColor3ub(235,214,184);
    glBegin(GL_QUADS);
    glVertex2i(20,385);
    glVertex2i(118,385);
    glVertex2i(118,398);
    glVertex2i(20,398);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(127,10,20);
    glBegin(GL_QUADS);
    glVertex2i(20,379);
    glVertex2i(118,379);
    glVertex2i(118,385);
    glVertex2i(20,385);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(235,214,184);
    glBegin(GL_QUADS);
    glVertex2i(28,370);
    glVertex2i(110,370);
    glVertex2i(110,379);
    glVertex2i(28,379);
    glEnd();

    glColor3ub(235,214,184);
    glBegin(GL_QUADS);
    glVertex2i(10,330);
    glVertex2i(130,330);
    glVertex2i(130,370);
    glVertex2i(10,370);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(235,214,184);
    glBegin(GL_QUADS);
    glVertex2i(0,309);
    glVertex2i(141,309);
    glVertex2i(141,331);
    glVertex2i(0,331);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(235,214,184);
    glBegin(GL_QUADS);
    glVertex2i(5,257);
    glVertex2i(137,257);
    glVertex2i(137,309);
    glVertex2i(5,309);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(52,257);
    glVertex2i(87,257);
    glVertex2i(87,287);
    glVertex2i(52,287);
    glEnd();
    glPopMatrix();

    //Bottom Block

    int HomeStripe1=-5;
    for(int i=9; i>=0; i--)
    {
        HomeStripe1+=13;
        homeWindow(HomeStripe1,292);
    }

    //Bottom up block
    int HomeStripe2=-5;
    for(int i=16; i>=0; i--)
    {
        HomeStripe2+=8;
        homeWindow2(HomeStripe2,312);
    }

    //next Bottom up block
    int HomeStripe3=-1;
    for(int i=5; i>=0; i--)
    {
        HomeStripe3+=18;
        homeWindow3(HomeStripe3,335);
    }

    glutPostRedisplay();
}


//*********HOSPITAL PART***********

//WINDOW PART
//1005
void HospitalWindow1(int x,int y)
{
    glPushMatrix();
    glColor3ub(0,227,227);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+16,y);
    glVertex2i(x+16,y+30);
    glVertex2i(x,y+30);
    glEnd();
    glPopMatrix();
}

//1006
//MIDDLE WINDOW PART
void HospitalMidWindow1(int x,int y)
{
    glPushMatrix();
    glColor3ub(0,227,227);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+12,y);
    glVertex2i(x+12,y+18);
    glVertex2i(x,y+18);
    glEnd();
    glPopMatrix();
}
//1007
void Hospital()

{
    //LEFT PILLAR

    glPushMatrix();
    glColor3ub(128,128,128);
    glBegin(GL_QUADS);
    glVertex2i(151,257);
    glVertex2i(181,257);
    glVertex2i(181,424);
    glVertex2i(151,424);
    glEnd();
    glPopMatrix();

    //RIGHT PILLAR
    glPushMatrix();
    glColor3ub(128,128,128);
    glBegin(GL_QUADS);
    glVertex2i(449,257);
    glVertex2i(449,424);
    glVertex2i(420,424);
    glVertex2i(420,257);
    glEnd();
    glPopMatrix();

    //UPPER BUILDING SIDE
    glPushMatrix();
    glColor3ub(128,128,128);
    glBegin(GL_QUADS);
    glVertex2i(181,381);
    glVertex2i(420,381);
    glVertex2i(420,400);
    glVertex2i(181,400);
    glEnd();
    glPopMatrix();

    //MIDDLE PART OF BUILDING
    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(181,258);
    glVertex2i(420,258);
    glVertex2i(420,381);
    glVertex2i(181,381);
    glEnd();
    glPopMatrix();


    //2 borders

    glPushMatrix();
    glColor3ub(0,0,255);
    glBegin(GL_QUADS);
    glVertex2i(151,390);
    glVertex2i(181,390);
    glVertex2i(181,401);
    glVertex2i(151,401);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0,0,255);
    glBegin(GL_QUADS);
    glVertex2i(420,390);
    glVertex2i(449,390);
    glVertex2i(449,401);
    glVertex2i(420,401);
    glEnd();
    glPopMatrix();

    int HospitalStripe1=163;
    for(int i=11; i>=0; i--)
    {
        HospitalStripe1+=20;
        HospitalWindow1(HospitalStripe1,349);
    }

    int HospitalStripe2=163;
    for(int i=11; i>=0; i--)
    {
        HospitalStripe2+=20;
        HospitalWindow1(HospitalStripe2,315);
    }

    int HospitalStripe3=163;
    for(int i=11; i>=0; i--)
    {
        HospitalStripe3+=20;
        HospitalWindow1(HospitalStripe3,281);
    }

    glPushMatrix(); //middle long stripe
    glColor3ub(128,128,128);
    glBegin(GL_QUADS);
    glVertex2i(263,257);
    glVertex2i(339,257);
    glVertex2i(339,400);
    glVertex2i(263,400);
    glEnd();
    glPopMatrix();

    int HospitalStripe4=260;
    for(int i=3; i>=0; i--)
    {
        HospitalStripe4+=14;
        HospitalMidWindow1(HospitalStripe4,370);
    }

    int HospitalStripe5=260;
    for(int i=3; i>=0; i--)
    {
        HospitalStripe5+=14;
        HospitalMidWindow1(HospitalStripe5,340);
    }

    int HospitalStripe6=260;
    for(int i=3; i>=0; i--)
    {
        HospitalStripe6+=14;
        HospitalMidWindow1(HospitalStripe6,310);
    }

    glPushMatrix();  //Door
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(286,257);
    glVertex2i(318,257);
    glVertex2i(318,298);
    glVertex2i(286,298);
    glEnd();
    glPopMatrix();

    glutPostRedisplay();
}

//******Circle******
//1008
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 50; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.1416;

    glColor3ub(252,222,66);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2d(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glPushMatrix();
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2i(295,395);
    glVertex2i(307,395);
    glVertex2i(307,426);
    glVertex2i(295,426);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2i(284,408);
    glVertex2i(318,408);
    glVertex2i(318,418);
    glVertex2i(284,418);
    glEnd();
    glPopMatrix();
}

//*********Hotel part******
//1009
//window part
void HotelBelowWindow1(int x,int y)
{
    glPushMatrix();
    glColor3ub(5,150,155);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+19,y);
    glVertex2i(x+19,y+13);
    glVertex2i(x,y+13);
    glEnd();
    glPopMatrix();
}
//1010
void HotelAboveWindow1(int x,int y)
{
    glPushMatrix();
    glColor3ub(5,150,155);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+17,y);
    glVertex2i(x+17,y+21);
    glVertex2i(x,y+21);
    glEnd();
    glPopMatrix();
}
//1011
void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 50; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.1416;

    //glColor3ub(23,60,43);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2d(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}
//1012
void Hotel()
{
    glPushMatrix();
    glColor3ub(0,0,255);
    glBegin(GL_QUADS);
    glVertex2i(449,257);
    glVertex2i(644,257);
    glVertex2i(644,289);
    glVertex2i(449,289);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0,0,255);
    glBegin(GL_QUADS);
    glVertex2i(473,289);
    glVertex2i(500,289);
    glVertex2i(500,413);
    glVertex2i(473,413);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(128,0,255);
    glBegin(GL_QUADS);
    glVertex2i(500,289);
    glVertex2i(517,289);
    glVertex2i(517,435);
    glVertex2i(500,435);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(128,0,255);
    glBegin(GL_QUADS);
    glVertex2i(517,289);
    glVertex2i(617,289);
    glVertex2i(617,408);
    glVertex2i(517,408);
    glEnd();
    glPopMatrix();

    glPushMatrix();  // above name plate
    glColor3ub(30,72,230);
    glBegin(GL_QUADS);
    glVertex2i(526,408);
    glVertex2i(600,408);
    glVertex2i(600,430);
    glVertex2i(526,430);
    glEnd();
    glPopMatrix();

    glColor3ub(128,0,255);  // side circle
    drawCircle(475.0f,310.0f,18.0f);
    drawCircle(475.0f,348.0f,18.0f);
    drawCircle(475.0f,383.0f,18.0f);

    int HotelBelowStripe1=430;
    for(int i=7; i>=0; i--)
    {
        HotelBelowStripe1+=24;
        HotelBelowWindow1(HotelBelowStripe1,267);
    }

    int HotelAboveStripe1=498;
    for(int i=3; i>=0; i--)
    {
        HotelAboveStripe1+=24;
        HotelAboveWindow1(HotelAboveStripe1,377);
    }

    int HotelAboveStripe2=498;
    for(int i=3; i>=0; i--)
    {
        HotelAboveStripe2+=24;
        HotelAboveWindow1(HotelAboveStripe2,350);
    }

    int HotelAboveStripe3=498;
    for(int i=3; i>=0; i--)
    {
        HotelAboveStripe3+=24;
        HotelAboveWindow1(HotelAboveStripe3,323);
    }

    int HotelAboveStripe4=498;
    for(int i=3; i>=0; i--)
    {
        HotelAboveStripe4+=24;
        HotelAboveWindow1(HotelAboveStripe4,295);
    }
}
//1013
void Door()
{
    glColor3ub(8,32,19);
    drawCircle(547.0f,282.0f,22.0f);

    glPushMatrix();     // door
    glColor3ub(119,81,70);
    glBegin(GL_QUADS);
    glVertex2i(524,258);
    glVertex2i(570,258);
    glVertex2i(570,281);
    glVertex2i(524,281);
    glEnd();
    glPopMatrix();

    glPushMatrix();     // door middle
    glColor3ub(70,113,106);
    glBegin(GL_QUADS);
    glVertex2i(528,280);
    glVertex2i(546,280);
    glVertex2i(546,257);
    glVertex2i(528,257);
    glEnd();
    glPopMatrix();

    glPushMatrix();     // door middle
    glColor3ub(70,113,106);
    glBegin(GL_QUADS);
    glVertex2i(548,257);
    glVertex2i(565,257);
    glVertex2i(565,280);
    glVertex2i(548,280);
    glEnd();
    glPopMatrix();

}

//**********School part***********
//1014
void SchoolWindow1(int x,int y)
{
    glPushMatrix();
    glColor3ub(190,202,200);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+20,y);
    glVertex2i(x+20,y+17);
    glVertex2i(x,y+17);
    glEnd();
    glPopMatrix();
}
//1015
void School()
{

    //school sca leton
    glPushMatrix();
    glColor3ub(214,130,5);
    glBegin(GL_QUADS);
    glVertex2i(643,257);
    glVertex2i(884,257);
    glVertex2i(884,351);
    glVertex2i(643,351);
    glEnd();
    glPopMatrix();


//top border
    glPushMatrix();
    glColor3ub(73,3,5);
    glBegin(GL_QUADS);
    glVertex2i(640,351);
    glVertex2i(887,351);
    glVertex2i(887,358);
    glVertex2i(640,358);
    glEnd();
    glPopMatrix();

    //window bottom left border line
    glPushMatrix();
    glColor3ub(80,149,255);
    glBegin(GL_QUADS);
    glVertex2i(648,265);
    glVertex2i(719,265);
    glVertex2i(719,275);
    glVertex2i(648,275);
    glEnd();
    glPopMatrix();

    //window bottom right border line
    glPushMatrix();
    glColor3ub(80,149,255);
    glBegin(GL_QUADS);
    glVertex2i(808,265);
    glVertex2i(879,265);
    glVertex2i(879,275);
    glVertex2i(808,275);
    glEnd();
    glPopMatrix();


//school triangle bottom
    glPushMatrix();
    glColor3ub(217,132,130);
    glBegin(GL_POLYGON);
    glVertex2i(713,358);
    glVertex2i(813,358);
    glVertex2i(813,381);
    glVertex2i(763,402);
    glVertex2i(713,381);
    glEnd();
    glPopMatrix();

    //school top triangle
    glPushMatrix();
    glColor3ub(75,3,140);
    glBegin(GL_TRIANGLES);
    glVertex2i(707,381);
    glVertex2i(819,381);
    glVertex2i(763,409);
    glEnd();
    glPopMatrix();

    glColor3ub(200,200,240);
    drawCircle(762.0f,369.0f,10.0f);

    int SchoolStripe1=623;
    for(int i=2; i>=0; i--)
    {
        SchoolStripe1+=25;
        SchoolWindow1(SchoolStripe1,328);
    }

    int SchoolStripe2=623;
    for(int i=2; i>=0; i--)
    {
        SchoolStripe2+=25;
        SchoolWindow1(SchoolStripe2,304);
    }

    int SchoolStripe3=623;
    for(int i=2; i>=0; i--)
    {
        SchoolStripe3+=25;
        SchoolWindow1(SchoolStripe3,281);
    }

    int SchoolStripe4=783;
    for(int i=2; i>=0; i--)
    {
        SchoolStripe4+=25;
        SchoolWindow1(SchoolStripe4,328);
    }

    int SchoolStripe5=783;
    for(int i=2; i>=0; i--)
    {
        SchoolStripe5+=25;
        SchoolWindow1(SchoolStripe5,304);
    }

    int SchoolStripe6=783;
    for(int i=2; i>=0; i--)
    {
        SchoolStripe6+=25;
        SchoolWindow1(SchoolStripe6,282);
    }

}
//1016
void SchoolDoor()
{
    glPushMatrix();
    glColor3ub(72,2,4);
    glBegin(GL_QUADS);
    glVertex2i(728,257);
    glVertex2i(797,257);
    glVertex2i(797,321);
    glVertex2i(728,321);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(75,3,4);
    glBegin(GL_TRIANGLES);
    glVertex2i(722,321);
    glVertex2i(803,321);
    glVertex2i(763,347);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(100,150,100);
    glBegin(GL_QUADS);
    glVertex2i(733,304);
    glVertex2i(792,304);
    glVertex2i(792,321);
    glVertex2i(733,321);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(89,107,121);
    glBegin(GL_QUADS);
    glVertex2i(743,257);
    glVertex2i(782,257);
    glVertex2i(782,295);
    glVertex2i(743,295);
    glEnd();
    glPopMatrix();
}
//1017
void HouseFrontTree()
{
    for(float i=0; i<7*130; i+=245)
    {
        glPushMatrix();
        glColor3ub(156,112,63);
        glBegin(GL_QUADS);
        glVertex2i(140+i,256);
        glVertex2i(148+i,256);
        glVertex2i(148+i,285);
        glVertex2i(140+i,285);
        glEnd();
        glPopMatrix();

        glColor3ub(37,90,27);
        drawCircle(144.0f+i,288.0f,10.0f);
        drawCircle(150.0f+i,281.0f,9.0f);
        drawCircle(157.0f+i,286.0f,7.0f);
        drawCircle(146.0f+i,232.0f,12.0f);
        drawCircle(134.0f+i,291.0f,12.0f);
        drawCircle(138.0f+i,300.0f,13.0f);
        drawCircle(144.0f+i,299.0f,7.0f);
        drawCircle(150.0f+i,299.0f,10.0f);
    }
}
//1018
void Moon()
{
    glPushMatrix();
    //glTranslatef(0.0,(-1)*c1xp,0.0);
    glColor3ub(m1r,m1g,m1b);
    drawCircle(730.0f,620.0f,40.0f);
    glColor3ub(m2r,m2g,m2b);
    drawCircle(740.0f,640.0f,40.0f);
    glPopMatrix();
}
//1019
void Sun()
{
    glColor3ub(sdr,sdg,sdb);
    drawCircle(824.0f,615.0f,40.0f);
    glutPostRedisplay();
}

float cdxp1=0.0;
float cdxp2=0.0;
float cdxp3=0.0;

float cloud_speed_x = 0.0;
float cloud_speed_y = 0.0;

//2025
void cloudUpdate_1(int value)
{
    cloud_speed_x += .01;
    if(cloud_speed_x > 700)
    {
        cloud_speed_x = -5.0;
    }

    glutPostRedisplay();
    glutTimerFunc(20, cloudUpdate_1, 0);
    //cout<<"cloud speed: "<<cloud_speed_x<<endl;
}

//1020
void Cloud()
{
    //cout<<"cloud speed: "<<cloud_speed_x<<endl;
    //glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    //glTranslatef(c1xp+cdxp2,0,0);
    glTranslatef(cloud_speed_x,0,0);
    glColor3ub(cdr,cdg,cdb);
    drawCircle(393.0f,577.0f,20.0f);
    drawCircle(370.0f,585.0f,28.0f);
    drawCircle(339.0f,583.0f,35.0f);
    drawCircle(311.0f,565.0f,20.0f);
    glPopMatrix();

    glPushMatrix();
    //glTranslatef(c1xp+cdxp3,0,0);
    glTranslatef(cloud_speed_x,0,0);
    drawCircle(193.0f,607.0f,20.0f);
    drawCircle(170.0f,615.0f,28.0f);
    drawCircle(139.0f,613.0f,35.0f);
    drawCircle(111.0f,595.0f,20.0f);
    glPopMatrix();

    glutPostRedisplay();

    glutSwapBuffers();

}
//add number here
//1050
void Cloud2()
{
    glPushMatrix();
    //glTranslatef(c1xp+cdxp1,0,0);
    glTranslatef(cloud_speed_x,0,0);
    glColor3ub(cdr,cdg,cdb);
    drawCircle(594.0f,586.0f,20.0f);
    drawCircle(572.0f,595.0f,28.0f);
    //drawCircle(539.0f,595.0f,35.0f);
    //drawCircle(513.0f,575.0f,20.0f);

    drawCircle(660.0f,595.0f,35.0f);
    drawCircle(670.0f,575.0f,20.0f);
    glPopMatrix();
}

//1021

void Road()
{
    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(0,148);
    glVertex2i(902,148);
    glVertex2i(902,47);
    glVertex2i(0,47);
    glEnd();
    glPopMatrix();

    for(int i=0; i<120*8; i+=120)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,95);
        glVertex2i(35+i,95);
        glVertex2i(35+i,100);
        glVertex2i(0+i,100);
        glEnd();
        glPopMatrix();
    }
}
//1022
void RoadCorner1()
{
    for(int i=0; i<16*60; i+=30)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,148);
        glVertex2i(16+i,148);
        glVertex2i(16+i,157);
        glVertex2i(0+i,157);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(16+i,148);
        glVertex2i(39+i,148);
        glVertex2i(39+i,157);
        glVertex2i(16+i,157);
        glEnd();
        glPopMatrix();
    }
}
//1023
void RoadCorner2()
{
    for(int i=0; i<16*60; i+=30)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,148-100);
        glVertex2i(16+i,148-100);
        glVertex2i(16+i,157-100);
        glVertex2i(0+i,157-100);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(16+i,148-100);
        glVertex2i(39+i,148-100);
        glVertex2i(39+i,157-100);
        glVertex2i(16+i,157-100);
        glEnd();
        glPopMatrix();
    }
}
//1024
void RoadGrash()
{
    glPushMatrix();
    glColor3ub(gdr,gdg,gdb);
    glBegin(GL_QUADS);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(902.0,0.0,0.0);
    glVertex3f(902.0,47.0,0.0);
    glVertex3f(0.0,47.0,0.0);
    glEnd();
    glPopMatrix();
}
//1025
void BetweenRoadAndBuldings()
{
    glPushMatrix();
    glColor3ub(gdr,gdg,gdb);
    //glColor3ub(100,171,55);
    glBegin(GL_QUADS);
    glVertex3f(0.0,157.0,0.0);
    glVertex3f(902.0,157.0,0.0);
    glVertex3f(902.0,258.0,0.0);
    glVertex3f(0.0,258.0,0.0);
    glEnd();
    glPopMatrix();
}
//1026
void Tree()
{
//    glPushMatrix();
//    glColor3ub(37,90,27);
//    glBegin(GL_TRIANGLES);
//    glVertex2i(24,78);
//    glVertex2i(67,78);
//    glVertex2i(46,110);
//    glEnd();
//    glPopMatrix();
//
//    glPushMatrix();
//    glColor3ub(37,90,27);
//    glBegin(GL_TRIANGLES);
//    glVertex2i(24,70);
//    glVertex2i(67,70);
//    glVertex2i(46,102);
//    glEnd();
//    glPopMatrix();

//    glPushMatrix();
//    glColor3ub(37,90,27);
//    glBegin(GL_TRIANGLES);
//    glVertex2i(24,62);
//    glVertex2i(67,62);
//    glVertex2i(46,94);
//    glEnd();
//    glPopMatrix();
//
//    glPushMatrix();
//    glColor3ub(37,90,27);
//    glBegin(GL_TRIANGLES);
//    glVertex2i(24,78-24);
//    glVertex2i(67,78-24);
//    glVertex2i(46,110-24);
//    glEnd();
//    glPopMatrix();

    for(int i=0; i<7*130; i+=130)
    {
        glPushMatrix();
        glColor3ub(37,90,207);
        glBegin(GL_TRIANGLES);
        glVertex2i(24+i,46);
        glVertex2i(67+i,46);
        glVertex2i(46+i,78);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(37,190,27);
        glBegin(GL_TRIANGLES);
        glVertex2i(24+i,40);
        glVertex2i(67+i,40);
        glVertex2i(46+i,72);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(161,189,61);
        glBegin(GL_QUADS);
        glVertex2i(39+i,40);
        glVertex2i(52+i,40);
        glVertex2i(52+i,0);
        glVertex2i(39+i,0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(37,190,27);
        glBegin(GL_TRIANGLES);
        glVertex2i(24+i,32);
        glVertex2i(67+i,32);
        glVertex2i(46+i,64);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(137,90,27);
        glBegin(GL_TRIANGLES);
        glVertex2i(24+i,24);
        glVertex2i(67+i,24);
        glVertex2i(46+i,56);
        glEnd();
        glPopMatrix();
    }
}

//1027
void LampPost()
{
    for(int i=0; i<8*115; i+=115)
    {
        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(34+i,158);
        glVertex2i(51+i,158);
        glVertex2i(51+i,160);
        glVertex2i(34+i,160);
        glEnd();
        glPopMatrix();



        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(37+i,160);
        glVertex2i(48+i,160);
        glVertex2i(48+i,162);
        glVertex2i(37+i,162);
        glEnd();
        glPopMatrix();


        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(40+i,162);
        glVertex2i(45+i,162);
        glVertex2i(45+i,206);
        glVertex2i(40+i,206);
        glEnd();
        glPopMatrix();



        glPushMatrix();
        glColor3ub(255,0,0);
        glBegin(GL_QUADS);
        glVertex2i(38+i,206);
        glVertex2i(48+i,206);
        glVertex2i(48+i,209);
        glVertex2i(38+i,209);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(ldr,ldg,ldb);
        drawCircle(43+i,218,9);
        glPopMatrix();

        if(ldr==255 && ldg==244 && ldb==78)
        {

            glPushMatrix();
            glColor3ub(255,244,78);
            glBegin(GL_LINES);
            glVertex2i(43+i,210);
            glVertex2i(70+i,220);
            glEnd();

            glColor3ub(255,244,78);
            glBegin(GL_LINES);
            glVertex2i(43+i,210);
            glVertex2i(60+i,220);
            glEnd();

            glColor3ub(255,244,78);
            glBegin(GL_LINES);
            glVertex2i(43+i,210);
            glVertex2i(40+i,220);
            glEnd();

            glColor3ub(255,244,78);
            glBegin(GL_LINES);
            glVertex2i(43+i,210);
            glVertex2i(20+i,220);
            glEnd();

            glColor3ub(255,244,78);
            glBegin(GL_LINES);
            glVertex2i(43+i,210);
            glVertex2i(25+i,213);
            glEnd();
            glPopMatrix();
        }
    }
}

//1028

void Car1()
{
    glPushMatrix();

    glTranslatef(c1xp,c1yp,c1zp);
    glColor3ub(153,0,204);
    glTranslatef(c1xp,c1yp,c1zp);
    glBegin(GL_QUADS);
    glVertex2i(311-500,112);//Body
    glVertex2i(414-500,112);
    glVertex2i(414-500,174);
    glVertex2i(311-500,174);
    glEnd();
    //glPopMatrix();

    glColor3ub(105,105,105);
    //glTranslatef(c1xp,c1yp,c1zp);
    glBegin(GL_QUADS);
    /* glVertex2i(311-500,112);//Body
     glVertex2i(414-500,112);
     glVertex2i(414-500,174);
     glVertex2i(311-500,174);
     glEnd();*/

    glVertex2i(315-500,150);//window1
    glVertex2i(330-500,150);
    glVertex2i(330-500,170);
    glVertex2i(315-500,170);

    glVertex2i(335-500,150);//window2
    glVertex2i(350-500,150);
    glVertex2i(350-500,170);
    glVertex2i(335-500,170);

    glVertex2i(355-500,150);//window3
    glVertex2i(370-500,150);
    glVertex2i(370-500,170);
    glVertex2i(355-500,170);

    glVertex2i(375-500,150);//Door
    glVertex2i(395-500,150);
    glVertex2i(395-500,170);
    glVertex2i(375-500,170);


    glEnd();






    //glPopMatrix();*/

    //glPushMatrix();
    glColor3ub(139,0,139);//Front side
    glBegin(GL_TRIANGLE_FAN);


    glVertex2i(414-500,174);
    glVertex2i(445-500,174);
    glVertex2i(473-500,134);
    glVertex2i(473-500,112);
    glVertex2i(414-500,112);
    glEnd();
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(75,89,89);
    glBegin(GL_TRIANGLE_FAN);
    /* glVertex2i(417-500,158);
     glVertex2i(444-500,158);
     glVertex2i(463-500,139);
     glVertex2i(463-500,134);
     glVertex2i(417-500,134);
     glEnd();*/

    glVertex2i(417-500,158);
    glVertex2i(444-500,158);
    glVertex2i(463-500,139);
    glVertex2i(463-500,134);
    glVertex2i(417-500,134);
    glEnd();
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);


    glVertex2i(417-500,158);
    glVertex2i(444-500,158);
    glVertex2i(463-500,139);
    glVertex2i(463-500,134);
    glVertex2i(417-500,134);
    glEnd();
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);


    glVertex2i(419-500,126);
    glVertex2i(431-500,126);
    glVertex2i(431-500,129);
    glVertex2i(419-500,129);
    glEnd();
    //glPopMatrix();
    glColor3ub(48,48,46); //back wheel
    drawCircle(342-500,116,15);
    glColor3ub(255,255,255);
    drawCircle(342-500,116,10);
    glColor3ub(0,0,0);
    drawCircle(342-500,116,8);

    //drawCircle(342-500,110,15);
    //drawCircle(342-500,110,15);
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(48,48,46);  //Front Wheel
    drawCircle(434-500,116,15);
    glColor3ub(255,255,255);
    drawCircle(434-500,116,10);
    glColor3ub(0,0,0);
    drawCircle(434-500,116,8);



    glPopMatrix();
}
//1029

void Car2()
{
    glPushMatrix();
    glTranslatef(c2xp,c2yp,c2zp);
    glColor3ub(0,0,255);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(459+500,154-70);
    glVertex2i(466+500,160-70);
    glVertex2i(491+500,160-70);
    glVertex2i(510+500,182-70);
    glVertex2i(568+500,182-70);
    glVertex2i(580+500,162-70);
    glVertex2i(580+500,141-70);
    glVertex2i(459+500,141-70);

    glEnd();
    //glPopMatrix();

    glColor3ub(155,186,189);
    glBegin(GL_TRIANGLE_FAN);

    glVertex2i(503+500,169-70);
    glVertex2i(512+500,177-70);
    glVertex2i(525+500,177-70);
    glVertex2i(521+500,163-70);
    glVertex2i(503+500,163-70);
    glEnd();

    glColor3ub(155,186,189);
    glBegin(GL_TRIANGLE_FAN);

    glVertex2i(526+500,163-70);
    glVertex2i(530+500,177-70);
    glVertex2i(547+500,177-70);
    glVertex2i(547+500,163-70);
    glEnd();

    glColor3ub(155,186,189);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(552+500,163-70);
    glVertex2i(551+500,177-70);
    glVertex2i(561+500,177-70);
    glVertex2i(570+500,163-70);
    glEnd();

    //glPushMatrix();
    glColor3ub(51,53,50);
    drawCircle(474+500,142-70,10);
    glColor3ub(255,0,0);
    drawCircle(474+500,142-70,8);
    glColor3ub(0,0,0);
    drawCircle(474+500,142-70,7);
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(51,53,50);
    drawCircle(551+500,142-70,10);
    glColor3ub(255,0,0);
    drawCircle(551+500,142-70,8);
    glColor3ub(0,0,0);
    drawCircle(551+500,142-70,7);

    glPopMatrix();
}
//1030
void Car3()
{
    glPushMatrix();
    glColor3ub(128,0,128);
    //glTranslatef(c1xp,c1yp,c1zp);
    glBegin(GL_QUADS);
    glVertex2i(311-150,112+100);
    glVertex2i(414-150,112+100);
    glVertex2i(414-150,174+100);
    glVertex2i(311-150,174+100);
    glEnd();
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(75,0,130);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(414-150,162+100);
    glVertex2i(445-150,162+100);
    glVertex2i(473-150,134+100);
    glVertex2i(473-150,112+100);
    glVertex2i(414-150,112+100);
    glEnd();
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(75,89,89);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(417-150,158+100);
    glVertex2i(444-150,158+100);
    glVertex2i(463-150,139+100);
    glVertex2i(463-150,134+100);
    glVertex2i(417-150,134+100);
    glEnd();
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2i(464-150,128+100);
    glVertex2i(472-150,128+100);
    glVertex2i(472-150,113+100);
    glVertex2i(464-150,113+100);
    glEnd();
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(419-150,126+100);
    glVertex2i(431-150,126+100);
    glVertex2i(431-150,129+100);
    glVertex2i(419-150,129+100);
    glEnd();
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(48,48,46);
    drawCircle(342-150,116+100,15);
    glColor3ub(255,255,255);
    drawCircle(342-150,116+100,10);
    glColor3ub(0,0,0);
    drawCircle(342-150,116+100,8);

    //drawCircle(342-500,110,15);
    //drawCircle(342-500,110,15);
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(48,48,46);
    drawCircle(434-150,116+100,15);
    glColor3ub(255,255,255);
    drawCircle(434-150,116+100,10);
    glColor3ub(0,0,0);
    drawCircle(434-150,116+100,8);

    //drawCircle(434-500,110,15);
    //drawCircle(434-500,110,15);

    glColor3ub(255,255,255);
    glBegin(GL_LINES);
    glVertex2i(342-200,200);
    glVertex2i(434-100,200);
    glEnd();

    glColor3ub(255,255,255);
    glBegin(GL_LINES);
    glVertex2i(342-200,200);
    glVertex2i(434-100,200);
    glEnd();

    glColor3ub(0,0,0);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(370-200,260);
    glVertex2i(370-200,230);

    glVertex2i(370-200,260);
    glVertex2i(390-200,260);

    glVertex2i(370-200,230);
    glVertex2i(390-200,230);

    glVertex2i(390-200,260);
    glVertex2i(390-200,230);

    glVertex2i(400-200,260);
    glVertex2i(400-200,230);

    glVertex2i(410-200,260);
    glVertex2i(410-200,230);

    glVertex2i(410-200,230);
    glVertex2i(425-200,230);
    glEnd();

    glPopMatrix();
}
//1031
void Rain()
{
    glPushMatrix();
    glTranslatef(c1xp,(-1)*p1yp,0);
    cout << "Rain speed: "  << c1xp*1 << endl;
    glColor3ub(103,155,176);
    for(int j=0; j<20*160; j+=20)
    {
        for(int i=0; i<20*160; i+=20)
        {
            glBegin(GL_LINES);
            glVertex2f(0+i+j,0+i);
            glVertex2f(-5.5+i+j,10+i);
            glEnd();

            glBegin(GL_LINES);
            glVertex2f(0+i-j,0+i);
            glVertex2f(-5.5+i-j,10+i);
            glEnd();
        }
    }
    glPopMatrix();
}
//1032
void Plane1()
{
    glPushMatrix();

    glTranslatef(p1xp,p1yp,p1zp);
    glScalef(x-p1sxp,x-p1syp,0.0-p1szp); //for white plane

    glColor3ub(222,231,255);
    glBegin(GL_QUADS);
    glVertex2i(937,440);
    glVertex2i(1010,420);
    glVertex2i(1025,437);
    glVertex2i(956,458);
    glEnd();

    //glColor3ub(222,231,255);
    glBegin(GL_QUADS);
    glVertex2i(1000,407);
    glVertex2i(979,407);
    glVertex2i(966,436);
    glVertex2i(979,433);
    glEnd();

    //glColor3ub(222,231,255);
    glBegin(GL_QUADS);
    glVertex2i(1007,443);
    glVertex2i(1028,469);
    glVertex2i(1032,468);
    glVertex2i(1019,439);
    glEnd();

    int y=0;
    for(int i=0; i<4*15; i+=15)
    {
        glColor3ub(120,55,96);
        drawCircle(960+i,445+y,3);
        y-=4;
    }

    glPopMatrix();
}
//1033
void Plane2()
{
    glPushMatrix();
    glTranslatef(c1xp,0.0,0.0);
    glColor3ub(0,78,168);
    glBegin(GL_QUADS);
    glVertex2i(7-200,307+350);
    glVertex2i(76-200,318+350);
    glVertex2i(95-200,312+350);
    glVertex2i(22-200,290+350);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(13-200,305+350);
    glVertex2i(0-200,338+350);
    glVertex2i(4-200,339+350);
    glVertex2i(25-200,313+350);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(32-200,277+350);
    glVertex2i(49-200,301+350);
    glVertex2i(64-200,306+350);
    glVertex2i(37-200,279+350);
    glEnd();

    int j=0;
    for(int i=0; i<5*10; i+=10)
    {
        glColor3ub(249,190-j,0);
        drawCircle(73-i-200,312.5-j+350,2);
        j+=2;
    }

    glPopMatrix();
}
//2000
void CarTranslate(int value)
{
    width+=1.0;
    width2-=1.0;
    //width3-=0.01;

    if(width<10093)
    {
        cdxp1+=0.09;
        cdxp2+=0.1;
        cdxp3+=0.0001; //CloudsT variable

        c1xp+=0.1;
        if(width>10091)
        {
            width=-940;
            c1xp=0.0;
        }
        if(width==1295)
        {
            cdxp1=0.0;
        }
        cout << "Width: " << width << endl;
    }
    if(width2>-1614)
    {
        c2xp-=0.5;
        p1xp-=0.001;
        p1yp+=0.6;
        if(width2==-1613)
        {
            width2=600;
            c2xp=0;

            p1xp=0;
            p1yp=0;
            p1sxp=0;
            p1syp=0;
            x=1.0;
            glutPostRedisplay();
        }
        if(width2<1200)
        {
            p1sxp+=0.001;
            p1syp+=0.001;
            glutPostRedisplay();
        }
        cout << "Width2: " << p1xp << endl;
    }

    glutTimerFunc(0,CarTranslate,25);
}
//2001
void keyboard(unsigned char key, int x, int y)
{
    if(key=='b')
    {
        CarTranslate(0);
        glutPostRedisplay();
    }
    if(key=='e')
    {
        exit(1);
    }
    /*if(key=='r')
    {
        if(r==0)
        {
            r=1;
        }else
        {
            r=0;
        }
    }*/
    if(key=='n')
    {
        if(dnr==103 && dng==155 && dnb==176)
            //if(dnr==105 && dng==105 && dnb==105)


        {
            dnr=0;
            dng=50;
            dnb=59;

            ldr=255;
            ldg=244;
            ldb=78;

            sdr=0;
            sdg=50;
            sdb=59;

            cdr=0;
            cdg=50;
            cdb=59;

            gdr=29;
            gdg=96;
            gdb=17;

            m1r=246;
            m1g=171;
            m1b=26;

            m2r=0;
            m2g=50;
            m2b=59;

        }
        else if(dnr==0 && dng==50 && dnb==59)

        {
            dnr=103;
            dng=155;
            dnb=176;

            //dnr=105;
            //dng=105;
            //dnb=105;

            ldr=255;
            ldg=255;
            ldb=255;

            sdr=246;
            sdg=171;
            sdb=26;

            cdr=230;
            cdg=234;
            cdb=237;

            gdr=100;
            gdg=171;
            gdb=55;

            m1r=103;
            m1g=155;
            m1b=176;

            m2r=103;
            m2g=155;
            m2b=176;

            //100,171,55

            //glColor3ub(230,234,237);
        }
    }
}
//2002
void Raining()
{
    if(r==0)
    {
        r=1;
    }
    else
    {
        r=0;
    }
}
//2003
void mouse(int button,int state,int x,int y)
{
    switch(button)
    {
    case GLUT_RIGHT_BUTTON:
        if(state==GLUT_DOWN)
            Raining();
        break;
    default:
        break;
    }
}
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    Sky();
    Home();
    drawFilledCircle(300.0f,400.0f,40.0f);
    Hospital();

    Hotel();
    Door();

    School();
    SchoolDoor();
    HouseFrontTree();

    Cloud();
    Cloud2();

    BetweenRoadAndBuldings();
    Road();
    Car3();
    LampPost();
    RoadCorner1();
    RoadCorner2();
    RoadGrash();
    Car1();
    Car2();
    Plane1();
    Tree();

    print(732,306,school);
    print(540,410,hotel);
    print(267,300,hospital);

    print(30,530,b);
    print(30,500,n);
    print(30,470,rain);
    print(30,440,e);

    if(ldr==255 && ldg==244 && ldb==78)
    {
        Moon();
    }

    glutTimerFunc(50,cloudUpdate_1,0);

    if(r == 0)
    {
        Sun();
    }
    else if(r==1)
    {
        Rain();
    }
    Plane2();
    glFlush ();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (902,684);
    glutInitWindowPosition (250, 30);
    glutCreateWindow ("City Road View");
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    myInit ();
    glutMainLoop();
}


