#include <iostream>
#include <stdlib.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include<cstring>
#include<string.h>
#include<windows.h>
#include<mmsystem.h>
#define PI acos(-1)

using namespace std;
char text[] = "Chemistry Lab";
char biu[] = "Biuret Test";
char step1[] = "Step1: Pour the sample on the big beaker";
char step2[] = "Step2: Pour Sodium Hydroxide on the sample";
char step3[] = "Step3: Add few drops of Copper Sulfate as the final step";
char label_1[] = "Sample";
char label_2[] = "NaOH";
char label_3[] = "CuSO4";
char PT[] = "Periodic table ";
char text1[] = "H";// name periodic table1
char text2[] = "Li";
char text3[] = "Na";
char text4[] = "K";
char text5[] = "Rh";
char text6[] = "Cs";
char text7[] = "Fr";
char text8[] = "Be";// name periodic table2
char text9[] = "Mg";
char text10[] = "Ca";
char text11[] = "Sr";
char text12[] = "Ba";
char text13[] = "Ra";
char text14[] = "Sc";// name periodic table3
char text15[] = "Y";
char text16[] = "Lc";
char text17[] = "Ac";
char text18[] = "Ti";// name periodic table4
char text19[] = "Zr";
char text20[] = "Hf";
char text21[] = "Rf";
char text22[] = "V";// name periodic table5
char text23[] = "Nb";
char text24[] = "Ta";
char text25[] = "Db";
char text26[] = "B";// name periodic table6
char text27[] = "Ai";
char text28[] = "Ga";
char text29[] = "In";
char text30[] = "Ti";
char text31[] = "Nh";
char text32[] = "C";// name periodic table7
char text33[] = "Si";
char text34[] = "Ge";
char text35[] = "Sn";
char text36[] = "Pb";
char text37[] = "Fl";
char text38[] = "O";// name periodic table8
char text39[] = "S";
char text40[] = "Se";
char text41[] = "Te";
char text42[] = "Po";
char text43[] = "Lv";
char text44[] = "F";// name periodic table9
char text45[] = "Cl";
char text46[] = "Br";
char text47[] = "I";
char text48[] = "At";
char text49[] = "Ts";
char text50[] = "He";// name periodic table10
char text51[] = "Ne";
char text52[] = "Ar";
char text53[] = "Kr";
char text54[] = "Xe";
char text55[] = "Rn";
char text56[] = "Og";

void update(int);
float _angle1 = 0.0f;
float _angle2 = 0.0f;
float _angle3 = 0.0f;
bool droplet = false;
GLfloat position = 0.0f;
GLfloat speed = 5;

GLfloat timeChange=0;

void update(int value) {

  if(timeChange>0 && timeChange<40)
 {

  _angle1 += 1.6f;

    if(_angle1 > 20.0f){

        _angle1 = 20.0f;
        droplet = true;

    }
 }
 else if(timeChange>40 && timeChange<60)
 {
     _angle1 -=1.6f;
     if(_angle1<1.0f){

        _angle1 = 0.f;
        droplet= false;
     }
 }

if(timeChange>60 && timeChange<100)
 {

  _angle2 += 1.6f;

    if(_angle2 > 25.0f){

        _angle2 = 25.0f;
        droplet = true;

    }
 }
 else if(timeChange>100 && timeChange<120)
 {
     _angle2 -=1.6f;
     if(_angle2<1.0f){

        _angle2 = 0.f;
        droplet= false;
     }
 }

 if(timeChange>120 && timeChange<160)
 {

  _angle3 += 1.6f;

    if(_angle3 > 27.0f){

        _angle3 = 27.0f;
        droplet = true;

    }
 }
 else if(timeChange>160 && timeChange<180)
 {
     _angle3 -=1.6f;
     if(_angle3<1.0f){

        _angle3 = 0.f;
        droplet= false;
     }
 }




	glutPostRedisplay();

	glutTimerFunc(100, update, 0);

}

///bubble
void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_LINE_LOOP);
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
}

void drawHollowCircle1(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_LINE_LOOP);
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + ((radius*2.5) * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
}


void drawFilledCircleRoad(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 200; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x - ((radius*2) * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

///print function
void Sprint( float x, float y, char *st)
{
    int l,i;
    l=strlen(st);
    glRasterPos2f(x, y); // location to start printing text
    for(i=0;i<l;i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]); //font and print
    }
}
void init(){
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0,1000,0,800);
}


void backg(){

    glColor3ub(255,0,0);
    glPointSize(4.0);
    glColor3f (0.91, 0.80, 0.93);
    glBegin(GL_POLYGON); //backgound
    glVertex2i(10, 220);
    glVertex2i(10, 770);
    glVertex2i(990, 770);
    glVertex2i(990, 220);
    glEnd();

}

 void floor(){

     glColor3ub(255,0,0);
    glPointSize(4.0);
    glColor3f (0.98, 0.98, 0.55);
    glBegin(GL_POLYGON); //backgound
    glVertex2i(10, 0);
    glVertex2i(10, 200);
    glVertex2i(990, 200);
    glVertex2i(990, 0);
    glEnd();


 }

void big_beaker(){

    glColor3f (0.5, 0.0, 0.5);
    glBegin(GL_POLYGON); //big beaker
    glVertex2i(250, 200);
    glVertex2i(250, 320);
    glVertex2i(350, 320);
    glVertex2i(350, 200);
    glEnd();
    glColor3f (1, 1.0, 1);

    drawFilledCircleRoad(300,375,60);
    glEnd();

    glColor3f (0.5, 0, 0.5);
    drawHollowCircle1(300,315,20);
    glEnd();

}

void table(){

    glColor3ub(255,0,0);
    glPointSize(4.0);
    Sprint(500,750,biu);
    glColor3f (0.0, 0.5, 0.5);
    glBegin(GL_POLYGON); //tablebody
    glVertex2i(50, 100);
    glVertex2i(200, 300);
    glVertex2i(800, 300);
    glVertex2i(950, 100);
    glEnd();

     glColor3ub(255,0,0);
    glPointSize(4.0);
    Sprint(500,750,biu);
    glColor3f (0.0, 0.5, 0.5);
    glBegin(GL_POLYGON); //table leg1
    glVertex2i(70, 0);
    glVertex2i(70, 100);
    glVertex2i(120, 100);
    glVertex2i(120, 0);
    glEnd();

    glColor3ub(255,0,0);
    glPointSize(4.0);
    Sprint(500,750,biu);
    glColor3f (0.0, 0.5, 0.5);
    glBegin(GL_POLYGON); //table leg2
    glVertex2i(880, 0);
    glVertex2i(880, 100);
    glVertex2i(930, 100);
    glVertex2i(930, 0);
    glEnd();
}

void sample_beaker(){

      Sprint(500,700,step1);
      Sprint(390,180,label_1);

     Sprint(500,180,label_2);
    Sprint(640,180,label_3);


    glPushMatrix();
//glTranslatef(0.0f,position, 0.0f);
//glTranslatef(position,0.0f, 0.0f);
glRotatef(_angle1, 0.0, 0.0, 1.0);
glColor3f (0.1, 0.0, 0.5);
    glBegin(GL_POLYGON); //sample beaker
    glVertex2i(400, 200);
    glVertex2i(400, 250);
    glVertex2i(450, 250);
    glVertex2i(450, 200);
    glEnd();
    glColor3f (0.1, 0.0, 0.5);
    drawHollowCircle1(425,250,10);
    glEnd();


glPopMatrix();
}



void cuso4()
{
    glPushMatrix();
//glTranslatef(0.0f,position, 0.0f);
//glTranslatef(position,0.0f, 0.0f);
//glRotatef(_angle1, 0.0, 0.0, 1.0);
    glColor3f (0.8, 0.7, 0.1);
    glBegin(GL_POLYGON); //CuSo4 big polygon
    glVertex2i(620, 200);
    glVertex2i(650, 250);
    glVertex2i(690, 250);
    glVertex2i(720, 200);
    glEnd();
    glBegin(GL_POLYGON); //CuSo4 small polygon
    glVertex2i(650, 250);
    glVertex2i(650, 280);
    glVertex2i(690, 280);
    glVertex2i(690, 250);
    glEnd();
    glColor3f (0.8, 0.7, 0.1);
    drawHollowCircle1(670,280,8);
    glEnd();
    glPopMatrix();


}


void cuso4_R()
{
    Sprint(500,600,step3);

    glPushMatrix();
//glTranslatef(0.0f,position, 0.0f);
//glTranslatef(position,0.0f, 0.0f);
glRotatef(_angle3, 0.0, 0.0, 1.0);
    glColor3f (0.8, 0.7, 0.1);
    glBegin(GL_POLYGON); //CuSo4 big polygon
    glVertex2i(620, 200);
    glVertex2i(650, 250);
    glVertex2i(690, 250);
    glVertex2i(720, 200);
    glEnd();
    glBegin(GL_POLYGON); //CuSo4 small polygon
    glVertex2i(650, 250);
    glVertex2i(650, 280);
    glVertex2i(690, 280);
    glVertex2i(690, 250);
    glEnd();
    glColor3f (0.8, 0.7, 0.1);
    drawHollowCircle1(670,280,8);
    glEnd();
    glPopMatrix();


}

void naOH(){

    glPushMatrix();
//glTranslatef(0.0f,position, 0.0f);
//glTranslatef(position,0.0f,0.0f);
//glRotatef(_angle1, 0.0, 0.0, 1.0);
    glColor3f (0.5, 0.0, 0.1);
    glBegin(GL_POLYGON); //NaoH big polygon
    glVertex2i(470, 200);
    glVertex2i(500, 250);
    glVertex2i(540, 250);
    glVertex2i(570, 200);
    glEnd();

    glBegin(GL_POLYGON); //NaoH small polygon
    glVertex2i(500, 250);
    glVertex2i(500, 280);
    glVertex2i(540, 280);
    glVertex2i(540, 250);
    glEnd();
    glColor3f (0.5, 0.0, 0.1);
    drawHollowCircle1(520,280,8);
    glEnd();
glPopMatrix();
}

void naOH_R(){

    Sprint(500,650,step2);

    glPushMatrix();
//glTranslatef(0.0f,position, 0.0f);
//glTranslatef(position,0.0f,0.0f);
glRotatef(_angle2, 0.0, 0.0, 1.0);
    glColor3f (0.5, 0.0, 0.1);
    glBegin(GL_POLYGON); //NaoH big polygon
    glVertex2i(470, 200);
    glVertex2i(500, 250);
    glVertex2i(540, 250);
    glVertex2i(570, 200);
    glEnd();

    glBegin(GL_POLYGON); //NaoH small polygon
    glVertex2i(500, 250);
    glVertex2i(500, 280);
    glVertex2i(540, 280);
    glVertex2i(540, 250);
    glEnd();
    glColor3f (0.5, 0.0, 0.1);
    drawHollowCircle1(520,280,8);
    glEnd();
glPopMatrix();
}

void periodic_table(){
    glColor3f (0.74, 0.72, 0.73);
    glBegin(GL_POLYGON); // periodic table polygon
    glVertex2i(20, 500);
    glVertex2i(20, 750);
    glVertex2i(380, 750);
    glVertex2i(380, 500);
    glEnd();

    glColor3f (1.0, 1.0, 0.4);
    glBegin(GL_POLYGON); // periodic table1
    glVertex2i(50, 520);
    glVertex2i(50, 720);
    glVertex2i(80, 720);
    glVertex2i(80, 520);
    glEnd();

    glColor3f (0.73, 0.73, 0.0);
    glBegin(GL_POLYGON); // periodic table2
    glVertex2i(80, 520);
    glVertex2i(80, 690);
    glVertex2i(110,690);
    glVertex2i(110,520);
    glEnd();

    glColor3f (0.61, 0.87, 1.0);
    glBegin(GL_POLYGON); // periodic table3
    glVertex2i(110, 520);
    glVertex2i(110, 630);
    glVertex2i(140, 630);
    glVertex2i(140, 520);
    glEnd();

    glColor3f (0.0, 0.5, 0.75);
    glBegin(GL_POLYGON); // periodic table4
    glVertex2i(140, 520);
    glVertex2i(140, 630);
    glVertex2i(170, 630);
    glVertex2i(170, 520);
    glEnd();

    glColor3f (0.0, 0.35, 0.52);
    glBegin(GL_POLYGON); // periodic table5
    glVertex2i(170, 520);
    glVertex2i(170, 630);
    glVertex2i(200, 630);
    glVertex2i(200, 520);
    glEnd();

    glColor3f (1.0, 0.02, 1.0);
    glBegin(GL_POLYGON); // periodic table6
    glVertex2i(200, 520);
    glVertex2i(200, 690);
    glVertex2i(230, 690);
    glVertex2i(230, 520);
    glEnd();

    glColor3f (1.0, 0.3, 1.0);
    glBegin(GL_POLYGON); // periodic table7
    glVertex2i(230, 520);
    glVertex2i(230, 690);
    glVertex2i(260, 690);
    glVertex2i(260, 520);
    glEnd();

    glColor3f (1.0, 0.02, 0.5);
    glBegin(GL_POLYGON); // periodic table8
    glVertex2i(260, 520);
    glVertex2i(260, 690);
    glVertex2i(290, 690);
    glVertex2i(290, 520);
    glEnd();

    glColor3f (0.8, 0.0, 0.8);
    glBegin(GL_POLYGON); // periodic table9
    glVertex2i(290, 520);
    glVertex2i(290, 690);
    glVertex2i(320, 690);
    glVertex2i(320, 520);
    glEnd();

    glColor3f (0.65, 0.29, 1.0);
    glBegin(GL_POLYGON); // periodic table10
    glVertex2i(320, 520);
    glVertex2i(320, 720);
    glVertex2i(350, 720);
    glVertex2i(350, 520);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    Sprint(380,780,text); //chemistry lab text
    Sprint(20,730,PT);// periodic table
    Sprint(55,700,text1);// periodic table1
    Sprint(55,670,text2);
    Sprint(55,640,text3);
    Sprint(55,610,text4);
    Sprint(55,580,text5);
    Sprint(55,550,text6);
    Sprint(55,520,text7);
    Sprint(85,670,text8);// periodic table2
    Sprint(85,640,text9);
    Sprint(85,610,text10);
    Sprint(85,580,text11);
    Sprint(85,550,text12);
    Sprint(85,520,text13);
     Sprint(115,610,text14);// periodic table3
     Sprint(115,580,text15);
     Sprint(115,550,text16);
     Sprint(115,520,text17);
      Sprint(145,610,text18);// periodic table4
      Sprint(145,580,text19);
      Sprint(145,550,text20);
      Sprint(145,520,text21);
      Sprint(175,610,text22);// periodic table5
       Sprint(175,580,text23);
       Sprint(175,550,text24);
       Sprint(175,520,text25);
       Sprint(205,670,text26);// periodic table6
       Sprint(205,640,text27);
        Sprint(205,610,text28);
        Sprint(205,580,text29);
        Sprint(205,550,text30);
        Sprint(205,520,text31);
        Sprint(235,670,text32);// periodic table7
                 Sprint(235,640,text33);
                 Sprint(235,610,text34);
                 Sprint(235,580,text35);
                 Sprint(235,550,text36);
                 Sprint(235,520,text37);
          Sprint(265,670,text38);// periodic table8
          Sprint(265,640,text39);
          Sprint(265,610,text40);
          Sprint(265,580,text41);
          Sprint(265,550,text42);
          Sprint(265,520,text43);
          Sprint(295,670,text44);// periodic table9
          Sprint(295,640,text45);
           Sprint(295,610,text46);
           Sprint(295,580,text47);
           Sprint(295,550,text48);
           Sprint(295,520,text49);
           Sprint(325,700,text50);// periodic table10
           Sprint(325,670,text51);
            Sprint(325,640,text52);
            Sprint(325,610,text53);
            Sprint(325,580,text54);
            Sprint(325,550,text55);
            Sprint(325,520,text56);
}

void drop1(){
    //glClear(GL_COLOR_BUFFER_BIT);
    //glLoadIdentity();
    glColor3ub(255,0,0);
    glPointSize(4.0);
    //Sprint(600,700,step1);
    glColor3f (0.0, 0.5, 0.5);
    drawHollowCircle(280,330,6);
    drawHollowCircle(265,330,6);
    drawHollowCircle(295,330,5);
    drawHollowCircle(280,350,5);
    drawHollowCircle(265,350,7);
    drawHollowCircle(280,370,8);
    glEnd();



}

void drop2(){
    //glClear(GL_COLOR_BUFFER_BIT);
    //glLoadIdentity();
    glColor3ub(255,0,0);
    glPointSize(4.0);
    //Sprint(600,700,step1);
    glColor3f (0.0, 0.5, 0.5);
    drawHollowCircle(300,400,5);
    drawHollowCircle(285,400,5);
    drawHollowCircle(315,400,7);
    drawHollowCircle(300,420,5);
    drawHollowCircle(285,420,5);
    drawHollowCircle(300,450,6);
    drawHollowCircle(280,330,6);
    drawHollowCircle(265,330,5);
    drawHollowCircle(295,330,5);
    drawHollowCircle(280,350,7);
    drawHollowCircle(265,350,7);
    drawHollowCircle(280,370,5);
    glEnd();



}

void drop3(){
    //glClear(GL_COLOR_BUFFER_BIT);
    //glLoadIdentity();
    glColor3ub(255,0,0);
    glPointSize(4.0);
    //Sprint(600,700,step1);
    glColor3f (0.0, 0.5, 0.5);
    drawHollowCircle(400,500,5);
    drawHollowCircle(420,520,5);
    drawHollowCircle(440,540,7);
    drawHollowCircle(300,400,7);
    drawHollowCircle(285,400,5);
    drawHollowCircle(315,400,5);
    drawHollowCircle(300,420,8);
    drawHollowCircle(285,420,8);
    drawHollowCircle(300,450,5);
    drawHollowCircle(280,330,5);
    drawHollowCircle(265,330,5);
    drawHollowCircle(295,330,7);
    drawHollowCircle(280,350,7);
    drawHollowCircle(265,350,5);
    drawHollowCircle(280,370,5);
    glEnd();



}





void page1()
{
    backg();
    floor();
    table();
    big_beaker();
    sample_beaker();
    naOH();
    cuso4();
    periodic_table();





}

void page2(){
     backg();
     floor();
    table();
    big_beaker();
    sample_beaker();
    naOH_R();
    cuso4();
    periodic_table();


}

 void page3(){

      backg();
      floor();
    table();
    big_beaker();
    sample_beaker();
    naOH_R();
    cuso4_R();
    periodic_table();

}

/* void page 4(){

} */



void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    //glLoadIdentity();

    if(timeChange>0){

       page1();
       if(droplet == true){
        drop1();}
    }
    if(timeChange>60){
            page2();
             if(droplet == true){
        drop2();}

    }

    if(timeChange>120){
            page3();
             if(droplet == true){
        drop3();}

    }



    timeChange++;
    cout<<timeChange<<endl;
    glFlush();
}

int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000,800);
    glutInitWindowPosition(100,30);
    sndPlaySound("chemical.wav",SND_ASYNC);//Play background music
    glutCreateWindow("Biuret Test");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(100, update, 0);
    glutMainLoop();

}
