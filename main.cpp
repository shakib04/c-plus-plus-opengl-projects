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
int sdr=246,sdg=171,sdb=26;
int cdr=230,cdg=234,cdb=237;
int gdr=100,gdg=171,gdb=55;
int m1r=103,m1g=155,m1b=176;
int m2r=103,m2g=155,m2b=176;
int m=0;


void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 902.0, 0.0, 684.0);
}

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

float cdxp1=0.0;
float cdxp2=0.0;
float cdxp3=0.0;

float cloud_speed_x = 0.0;
float cloud_speed_y = 0.0;

void cloudUpdate_1(int value)
{
    cloud_speed_x += .001;
    if(cloud_speed_x > 700)
    {
        cloud_speed_x = -5.0;
    }

    glutPostRedisplay();
    glutTimerFunc(20, cloudUpdate_1, 0);
    //cout<<"cloud speed: "<<cloud_speed_x<<endl;
}

void Cloud()
{
    cout<<"cloud speed: "<<cloud_speed_x<<endl;
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

void Rain()
{
    glPushMatrix();
    glTranslatef(c1xp,(-1)*p1yp,0);
    cout << "Rain speed: "  << c1xp*1 << endl;
    //glColor3ub(103,155,176);
    glColor3ub(0,0,0);
    for(int j=0; j<20*160; j+=20)
    {
        for(int i=0; i<20*160; i+=20)
        {
            glBegin(GL_LINES);
            glVertex2f(0+i+j,0+i);
            glVertex2f(-5.5+i+j,10+i);
            glEnd();

            glBegin(GL_LINES);
            //glVertex2f(0+i-j,0+i);
            glVertex2f(i-j, i);
            glVertex2f(-5.5+i-j,10+i);
            glEnd();
        }
    }
    glPopMatrix();
}

void Raining()
{
    if(r==0)
    {
        r=1;
        //Rain();
    }
    else
    {
        r=0;
    }
    cout<<"value of r in Raining() "<<r<<endl;
}

void mouse(int button,int state,int x,int y)
{
    switch(button)
    {
    case GLUT_RIGHT_BUTTON:
        if(state==GLUT_DOWN)
        {
            cout<<"mouse right clicked"<<endl;
            Raining();
        }
        break;
    default:
        break;
    }
}

void keyboard(unsigned char key, int x, int y)
{
    if(key=='b')
    {
        //CarTranslate(0);
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


void Sky()
{
    glPushMatrix();
    glColor3ub(dnr,dng,dnb);
    glBegin(GL_QUADS);
    glVertex2f(0.0,684.0);
    glVertex2f(902,684.0);
    glVertex2f(902.0,0.0);
    glVertex2f(0.0,0.0);
    glEnd();
    glPopMatrix();

    glutPostRedisplay();
}

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

void Sun()
{
    glColor3ub(sdr,sdg,sdb);
    drawCircle(824.0f,615.0f,40.0f);
    glutPostRedisplay();
}

//**********School part***********

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

void School()
{
    glPushMatrix();
    glColor3ub(214,130,5);
    glBegin(GL_QUADS);
    glVertex2i(643,257);
    glVertex2i(884,257);
    glVertex2i(884,351);
    glVertex2i(643,351);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(73,3,5);
    glBegin(GL_QUADS);
    glVertex2i(640,351);
    glVertex2i(887,351);
    glVertex2i(887,358);
    glVertex2i(640,358);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(80,149,146);
    glBegin(GL_QUADS);
    glVertex2i(648,265);
    glVertex2i(719,265);
    glVertex2i(719,275);
    glVertex2i(648,275);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(80,149,146);
    glBegin(GL_QUADS);
    glVertex2i(808,265);
    glVertex2i(879,265);
    glVertex2i(879,275);
    glVertex2i(808,275);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(217,132,3);
    glBegin(GL_POLYGON);
    glVertex2i(713,358);
    glVertex2i(813,358);
    glVertex2i(813,381);
    glVertex2i(763,402);
    glVertex2i(713,381);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(75,3,4);
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

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    Sky();
    Moon();
    Cloud();
    Cloud2();
    SchoolDoor();
    School();

    glutTimerFunc(50,cloudUpdate_1,0);

    if(r == 0)
    {
        Sun();
    }
    else if(r==1)
    {
        Rain();
    }

    //cout<<"main is calling"<<endl;

    if(ldr==255 && ldg==244 && ldb==78)
    {
        Moon();
    }

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
    myInit();

    glutMainLoop();
}

