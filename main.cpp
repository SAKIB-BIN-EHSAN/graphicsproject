#ifdef __APPLE
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <math.h>

float counter = 0.0,counter2 = 0.0,boat_counter = 0.0,sp = 0.0,circle_counter_one = 0.0,circle_counter_two = 0.0;
float circle_counter_three = 0.0,circle_counter_four = 0.0;
float ball_one_counter = 0.0;

void *currentfont;

void setFont(void *font)
{
	currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
	char *ct;
	glRasterPos3f(x,y,z);

	for(ct=string;*ct!='\0';ct++)
	{
	    glColor3f(0.0,0.0,0.0);   // text color
		glutBitmapCharacter(currentfont,*ct);
	}
}

void road()
{
    glBegin( GL_POLYGON );

        glColor3f( 0.2 , 0.2 , 0.2 );
        glVertex2f( 0,0);
        glVertex2f( 900,0 );
        glVertex2f( 900,300 );
        glVertex2f( 0,300 );

    glEnd();


    // ----  white spots of the road  ---
    glBegin( GL_POLYGON );

        glColor3f( 1.0 , 1.0 , 1.0 );
        glVertex2f( 100,120);
        glVertex2f( 200,120 );
        glVertex2f( 200,130 );
        glVertex2f( 100,130 );

    glEnd();

    glBegin( GL_POLYGON );

        glColor3f( 1.0 , 1.0 , 1.0 );
        glVertex2f( 400,120);
        glVertex2f( 500,120 );
        glVertex2f( 500,130 );
        glVertex2f( 400,130 );

    glEnd();

    glBegin( GL_POLYGON );

        glColor3f( 1.0 , 1.0 , 1.0 );
        glVertex2f( 700,120);
        glVertex2f( 800,120 );
        glVertex2f( 800,130 );
        glVertex2f( 700,130 );

    glEnd();
}

void circle(int x,int y)
{
   float th;                // here x and y are the coordinates of the center of the circle

   glBegin(GL_POLYGON);

        glColor3f(0.0 , 0.01 , 0.0);
        for(int i=0;i<360;i++)
        {
            th = i*(3.1416/180);
            glVertex2f( x+20*cos(th), y+20*sin(th));
        }

   glEnd();

}

void car1()
{
    glLoadIdentity();

    counter += 0.1;

    if(counter > 950)
        counter = -200.0;

    glTranslated( counter , 30.0 , 0.0 );

    // creating main structure of car1
    glBegin( GL_POLYGON );

        glColor3f( 0.0 , 0.0 , 0.9 );
        glVertex2f( 0,200);
        glVertex2f( 150,200 );
        glVertex2f( 140,250 );
        glVertex2f( 0,250 );

        glVertex2f( 10,200 );
        glVertex2f( 140,200 );
        glVertex2f( 110,280 );
        glVertex2f( 30,280 );

    glEnd();

    // creating left window
    glBegin(GL_POLYGON);

        glColor3f( 1.0 , 1.0 , 1.0 );
        glVertex2f(35,255);
        glVertex2f(55,255);
        glVertex2f(55,267);
        glVertex2f(35,267);

    glEnd();

    // creating right window
    glBegin(GL_POLYGON);

        glColor3f( 1.0 , 1.0 , 1.0 );
        glVertex2f(80,255);
        glVertex2f(100,255);
        glVertex2f(100,267);
        glVertex2f(80,267);

    glEnd();

}


// front wheel of car1
void wheel_one()
{
    glLoadIdentity();

    circle_counter_one += 0.1;

    if(circle_counter_one > 950)
        circle_counter_one = -200.0;

    glColor3f(0.0, 0.0, 0.0);
    glTranslated(circle_counter_one , 30.0 , 0.0);

    circle(120,190);

}

// backward wheel of car1
void wheel_two()
{
    glLoadIdentity();

    circle_counter_two += 0.1;

    if(circle_counter_two > 950)
        circle_counter_two = -200.0;

    glColor3f(0.0, 0.0, 0.0);
    glTranslated(circle_counter_two , 30.0 , 0.0);

    circle(30,190);
}

void car2()
{
    glLoadIdentity();

    counter2 += 0.1;

    if(counter2 > 950)
        counter2 = -200.0;

    glTranslated( counter2 , 30.0 , 0.0 );

    // creating main structure of car2
    glBegin( GL_POLYGON );

        glColor3f( 0.2 , 0.0 , 0.0 );
        glVertex2f( 100,50);
        glVertex2f( 270,50 );
        glVertex2f( 270,90 );
        glVertex2f( 100,90 );

        glVertex2f( 110,90 );
        glVertex2f( 250,90 );
        glVertex2f( 220,130 );
        glVertex2f( 130,130 );

    glEnd();

    // creating left window
    glBegin(GL_POLYGON);

        glColor3f( 0.0 , 0.6 , 0.0 );
        glVertex2f( 140,100 );
        glVertex2f( 160,100 );
        glVertex2f( 160,120 );
        glVertex2f( 140,120 );

    glEnd();

    // creating right window
    glBegin(GL_POLYGON);

        glColor3f( 0.0 , 0.6 , 0.0 );
        glVertex2f( 190,100 );
        glVertex2f( 210,100 );
        glVertex2f( 210,120 );
        glVertex2f( 190,120 );

    glEnd();

}

// front wheel of car2
void wheel_three()
{
    glLoadIdentity();

    circle_counter_three += 0.1;

    if(circle_counter_three > 950)
        circle_counter_three = -200.0;

    glColor3f(0.0, 0.0, 0.0);
    glTranslated(circle_counter_three , 30.0 , 0.0);

    circle(230,50);

}


// backward wheel of car2
void wheel_four()
{
    glLoadIdentity();

    circle_counter_four += 0.1;

    if(circle_counter_four > 950)
        circle_counter_four = -200.0;

    glColor3f(0.0, 0.0, 0.0);
    glTranslated(circle_counter_four , 30.0 , 0.0);

    circle(140,50);
}

void soil()
{
    glLoadIdentity();
    glColor3f(0.9,0.4,0.0);

    glBegin(GL_POLYGON);

        glVertex2f (0,500);
        glVertex2f (900, 500);
        glVertex2f (900, 600);

    glEnd();

}

void field()
{
    glLoadIdentity();
    glColor3f (.02, 0.6, 0.2);

    glBegin(GL_POLYGON);

        glVertex2f (0,300);
        glVertex2f (900, 300);
        glVertex2f (900, 500);
        glVertex2f (0, 500);

    glEnd();
}

void head(int x,int y)
{
   // here x and y are the coordinates of the center of the circle
   float th;

   glBegin(GL_POLYGON);

        glColor3f(1.0 , 1.0 , 1.0);
        for(int i=0;i<360;i++)
        {
            th = i*(3.1416/180);
            glVertex2f( x+20*cos(th), y+20*sin(th));
        }

   glEnd();

}

void ball()
{
    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);

    if(ball_one_counter >= 250)
    {
        ball_one_counter = ball_one_counter + 0.0000000000001;
        glTranslated(ball_one_counter , 20.0 , 0.0);
    }

    else
    {
        ball_one_counter = ball_one_counter + 0.04;
        glTranslated(ball_one_counter , 20.0 , 0.0);
    }

    circle(90,330);
}

void player()
{
    glLoadIdentity();
    glScaled(0.7,0.7,0.7);

    // head of left man
    head(100,640);

    // body of left side man
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);

        glVertex2f(80,500);
        glVertex2f(80,620);
        glVertex2f(120,620);
        glVertex2f(120,500);

    glEnd();

    // left leg of left side man
    glBegin(GL_LINE_LOOP);

        glVertex2f(90,460);
        glVertex2f(90,500);

    glEnd();

    // right leg of left side man
    glBegin(GL_LINE_LOOP);

        glVertex2f(110,460);
        glVertex2f(110,500);

    glEnd();

    // hands of left man
    glBegin(GL_POLYGON);

        glVertex2f(50,570);
        glVertex2f(150,570);
        glVertex2f(150,590);
        glVertex2f(50,590);

    glEnd();
}

void player2()
{
    glLoadIdentity();
    glScaled(0.7,0.7,0.7);

    // head of right man
    head(500,640);

    glColor3f(1.0,1.0,1.0);

    // body of right side man
    glBegin(GL_POLYGON);

        glVertex2f(480,500);
        glVertex2f(480,620);
        glVertex2f(520,620);
        glVertex2f(520,500);

    glEnd();


    // left leg of right side man
    glBegin(GL_LINE_LOOP);

        glVertex2f(490,460);
        glVertex2f(490,500);

    glEnd();


    // right leg of right side man
    glBegin(GL_LINE_LOOP);

        glVertex2f(510,460);
        glVertex2f(510,500);

    glEnd();

    // hands of right man
    glBegin(GL_POLYGON);

        glVertex2f(450,570);
        glVertex2f(550,570);
        glVertex2f(550,590);
        glVertex2f(450,590);

    glEnd();

}

void house()
{
    glLoadIdentity();

    // main structure of house
    glBegin(GL_POLYGON);

        glColor3f(0.4 , 0.0 , 0.0);
        glVertex2f (700,315);
        glVertex2f (820, 315);
        glVertex2f (820, 440);
        glVertex2f (700, 440);

    glEnd();


    // creating stair
    glBegin(GL_POLYGON);

        glColor3f(1.0 , 1.0 , 1.0);
        glVertex2f (680,300);
        glVertex2f (840, 300);
        glVertex2f (835, 315);
        glVertex2f (685, 315);

    glEnd();

    // creating door
    glBegin(GL_POLYGON);

        glColor3f(0.8 , 0.01 , 0.0);
        glVertex2f (730,315);
        glVertex2f (790, 315);
        glVertex2f (790, 390);
        glVertex2f (730, 390);

    glEnd();

    // middle line of door
    glBegin(GL_POLYGON);

        glColor3f(0.0 , 0.01 , 0.0);
        glVertex2f (755,315);
        glVertex2f (760, 315);
        glVertex2f (760, 390);
        glVertex2f (755, 390);

    glEnd();

    // shade of house
    glBegin(GL_POLYGON);

        glColor3f(124.0 , 124.0 , 0.0);
        glVertex2f (680,390);
        glVertex2f (840, 390);
        glVertex2f (810, 480);
        glVertex2f (710, 480);

    glEnd();

}

void tree()
{
    glLoadIdentity();

    // ----   creating the right tree     ----

    // creating tree
    glBegin(GL_TRIANGLES);

        glColor3f( 0.0 , 0.4 , 0.0 );
        glVertex2f (600,600);
        glVertex2f (700, 600);
        glVertex2f (650, 700);

    glEnd();

    glBegin(GL_TRIANGLES);

        glColor3f( 0.0 , 0.4 , 0.0 );
        glVertex2f (600,650);
        glVertex2f (700, 650);
        glVertex2f (650, 750);

    glEnd();

    // creating roots of tree
    glBegin(GL_POLYGON);

        glColor3f(0.7,0.2, 0.0);
        glVertex2f(640,500);
        glVertex2f(660,500);
        glVertex2f(660,600);
        glVertex2f(640,600);

    glEnd();

    // ------   creating the left tree     ----

    // creating tree
    glBegin(GL_TRIANGLES);

        glColor3f( 0.0 , 0.4 , 0.0 );
        glVertex2f(400,600);
        glVertex2f(500,600);
        glVertex2f(450,700);

    glEnd();

    glBegin(GL_TRIANGLES);

        glColor3f( 0.0 , 0.4 , 0.0 );
        glVertex2f(400,650);
        glVertex2f(500,650);
        glVertex2f(450,750);

    glEnd();

    // creating roots of tree
    glBegin(GL_POLYGON);

        glColor3f(0.7,0.2, 0.0);
        glVertex2f(440,500);
        glVertex2f(460,500);
        glVertex2f(460,600);
        glVertex2f(440,600);

    glEnd();
}

void road_side_tree()
{
    glLoadIdentity();

    // creating tree1
    glBegin(GL_TRIANGLES);

        glColor3f( 0.0 , 0.4 , 0.0 );
        glVertex2f(10,330);
        glVertex2f(40,330);
        glVertex2f(25,370);

    glEnd();

    // creating root1
    glBegin(GL_POLYGON);

        glColor3f(0.7,0.2, 0.0);
        glVertex2f(20,300);
        glVertex2f(30,300);
        glVertex2f(30,330);
        glVertex2f(20,330);

    glEnd();


    // creating tree2
    glBegin(GL_TRIANGLES);

        glColor3f( 0.0 , 0.4 , 0.0 );
        glVertex2f(10,30);
        glVertex2f(40,30);
        glVertex2f(25,70);

    glEnd();

    // creating root2
    glBegin(GL_POLYGON);

        glColor3f(0.7,0.2, 0.0);
        glVertex2f(20,0);
        glVertex2f(30,0);
        glVertex2f(30,30);
        glVertex2f(20,30);

    glEnd();


    // creating tree3
    glBegin(GL_TRIANGLES);

        glColor3f( 0.0 , 0.4 , 0.0 );
        glVertex2f(110,330);
        glVertex2f(140,330);
        glVertex2f(125,370);

    glEnd();

    // creating root3
    glBegin(GL_POLYGON);

        glColor3f(0.7,0.2, 0.0);
        glVertex2f(120,300);
        glVertex2f(130,300);
        glVertex2f(130,330);
        glVertex2f(120,330);

    glEnd();


    // creating tree4
    glBegin(GL_TRIANGLES);

        glColor3f( 0.0 , 0.4 , 0.0 );
        glVertex2f(110,30);
        glVertex2f(140,30);
        glVertex2f(125,70);

    glEnd();

    // creating root4
    glBegin(GL_POLYGON);

        glColor3f(0.7,0.2, 0.0);
        glVertex2f(120,0);
        glVertex2f(130,0);
        glVertex2f(130,30);
        glVertex2f(120,30);

    glEnd();


    // creating tree5
    glBegin(GL_TRIANGLES);

        glColor3f( 0.0 , 0.4 , 0.0 );
        glVertex2f(210,330);
        glVertex2f(240,330);
        glVertex2f(225,370);

    glEnd();

    // creating root5
    glBegin(GL_POLYGON);

        glColor3f(0.7,0.2, 0.0);
        glVertex2f(220,300);
        glVertex2f(230,300);
        glVertex2f(230,330);
        glVertex2f(220,330);

    glEnd();


    // creating tree6
    glBegin(GL_TRIANGLES);

        glColor3f( 0.0 , 0.4 , 0.0 );
        glVertex2f(210,30);
        glVertex2f(240,30);
        glVertex2f(225,70);

    glEnd();

    // creating root6
    glBegin(GL_POLYGON);

        glColor3f(0.7,0.2, 0.0);
        glVertex2f(220,0);
        glVertex2f(230,0);
        glVertex2f(230,30);
        glVertex2f(220,30);

    glEnd();


    // creating tree7
    glBegin(GL_TRIANGLES);

        glColor3f( 0.0 , 0.4 , 0.0 );
        glVertex2f(310,330);
        glVertex2f(340,330);
        glVertex2f(325,370);

    glEnd();

    // creating root7
    glBegin(GL_POLYGON);

        glColor3f(0.7,0.2, 0.0);
        glVertex2f(320,300);
        glVertex2f(330,300);
        glVertex2f(330,330);
        glVertex2f(320,330);

    glEnd();

    // creating tree8
    glBegin(GL_TRIANGLES);

        glColor3f( 0.0 , 0.4 , 0.0 );
        glVertex2f(310,30);
        glVertex2f(340,30);
        glVertex2f(325,70);

    glEnd();

    // creating root8
    glBegin(GL_POLYGON);

        glColor3f(0.7,0.2, 0.0);
        glVertex2f(320,0);
        glVertex2f(330,0);
        glVertex2f(330,30);
        glVertex2f(320,30);

    glEnd();

    // creating tree9
    glBegin(GL_TRIANGLES);

        glColor3f( 0.0 , 0.4 , 0.0 );
        glVertex2f(410,330);
        glVertex2f(440,330);
        glVertex2f(425,370);

    glEnd();

    // creating root9
    glBegin(GL_POLYGON);

        glColor3f(0.7,0.2, 0.0);
        glVertex2f(420,300);
        glVertex2f(430,300);
        glVertex2f(430,330);
        glVertex2f(420,330);

    glEnd();


    // creating tree10
    glBegin(GL_TRIANGLES);

        glColor3f( 0.0 , 0.4 , 0.0 );
        glVertex2f(410,30);
        glVertex2f(440,30);
        glVertex2f(425,70);

    glEnd();

    // creating root10
    glBegin(GL_POLYGON);

        glColor3f(0.7,0.2, 0.0);
        glVertex2f(420,0);
        glVertex2f(430,0);
        glVertex2f(430,30);
        glVertex2f(420,30);

    glEnd();


    // creating tree11
    glBegin(GL_TRIANGLES);

        glColor3f( 0.0 , 0.4 , 0.0 );
        glVertex2f(510,330);
        glVertex2f(540,330);
        glVertex2f(525,370);

    glEnd();

    // creating root1
    glBegin(GL_POLYGON);

        glColor3f(0.7,0.2, 0.0);
        glVertex2f(520,300);
        glVertex2f(530,300);
        glVertex2f(530,330);
        glVertex2f(520,330);

    glEnd();


    // creating tree12
    glBegin(GL_TRIANGLES);

        glColor3f( 0.0 , 0.4 , 0.0 );
        glVertex2f(510,30);
        glVertex2f(540,30);
        glVertex2f(525,70);

    glEnd();

    // creating root12
    glBegin(GL_POLYGON);

        glColor3f(0.7,0.2, 0.0);
        glVertex2f(520,0);
        glVertex2f(530,0);
        glVertex2f(530,30);
        glVertex2f(520,30);

    glEnd();


    // creating tree13
    glBegin(GL_TRIANGLES);

        glColor3f( 0.0 , 0.4 , 0.0 );
        glVertex2f(610,330);
        glVertex2f(640,330);
        glVertex2f(625,370);

    glEnd();

    // creating root13
    glBegin(GL_POLYGON);

        glColor3f(0.7,0.2, 0.0);
        glVertex2f(620,300);
        glVertex2f(630,300);
        glVertex2f(630,330);
        glVertex2f(620,330);

    glEnd();


    // creating tree14
    glBegin(GL_TRIANGLES);

        glColor3f( 0.0 , 0.4 , 0.0 );
        glVertex2f(610,30);
        glVertex2f(640,30);
        glVertex2f(625,70);

    glEnd();

    // creating root14
    glBegin(GL_POLYGON);

        glColor3f(0.7,0.2, 0.0);
        glVertex2f(620,0);
        glVertex2f(630,0);
        glVertex2f(630,30);
        glVertex2f(620,30);

    glEnd();

    // creating tree15
    glBegin(GL_TRIANGLES);

        glColor3f( 0.0 , 0.4 , 0.0 );
        glVertex2f(710,30);
        glVertex2f(740,30);
        glVertex2f(725,70);

    glEnd();

    // creating root15
    glBegin(GL_POLYGON);

        glColor3f(0.7,0.2, 0.0);
        glVertex2f(720,0);
        glVertex2f(730,0);
        glVertex2f(730,30);
        glVertex2f(720,30);

    glEnd();


    // creating tree16
    glBegin(GL_TRIANGLES);

        glColor3f( 0.0 , 0.4 , 0.0 );
        glVertex2f(810,30);
        glVertex2f(840,30);
        glVertex2f(825,70);

    glEnd();

    // creating root16
    glBegin(GL_POLYGON);

        glColor3f(0.7,0.2, 0.0);
        glVertex2f(820,0);
        glVertex2f(830,0);
        glVertex2f(830,30);
        glVertex2f(820,30);

    glEnd();

}

void boat()
{
    glLoadIdentity();

    boat_counter += 0.1;

    if(boat_counter > 950)
        boat_counter = -200.0;

    glTranslated( boat_counter , 30.0 , 0.0 );
    glColor3f (0.0, 0.0, 0.0);

    glBegin(GL_POLYGON);

        glVertex2f(200,600);
        glVertex2f(300,600);
        glVertex2f(320,640);
        glVertex2f(180,640);

    glEnd();
}

void boat2()
{
    glLoadIdentity();
    glColor3f(0.0,0.0,0.0);

    if(sp>=330)
    {
        sp=330;
        sp += 0.4;
        glTranslated(sp,30.0,0.0);
    }
    else
    {
        sp=sp+0.04;
        glTranslated(sp,30.0,0.0);
    }

    glBegin(GL_POLYGON);

        glVertex2f (100,530);
        glVertex2f (210, 530);
        glVertex2f (230, 570);
        glVertex2f (80, 570);

    glEnd();

}

void credit()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(1,1,1);
    drawstring(350,500,0.0,"Animation");
    glColor3f(1,1,1);
    drawstring(350,460,0.0,"Developed By: Sakib Bin Ehsan");
    glColor3f(1,1,1);
    drawstring(350,420,0.0,"Roll: 133010");
    glColor3f(1,1,1);
    drawstring(350,380,0.0,"CSE, RUET");
    glColor3f(1,1,1);
    drawstring(350,340,0.0,"The animation is about village");
}

void intro()
{
    // clears the window
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor( 0.0 , 0.0 , 0.0 , 1.0 );

    // student information
    credit();
    glutSwapBuffers();
    glFlush();

}

void sky()
{
    glLoadIdentity();

    glBegin(GL_POLYGON);

        glColor3f(0.0 , 0.4, 1.0 );
        glVertex2f(0 , 700);
        glVertex2f(900 , 700);
        glVertex2f(900 , 900);
        glVertex2f(0 , 900);

    glEnd();
}

void river()
{
    glLoadIdentity();

    glBegin(GL_POLYGON);

        glColor3f(0.0 , 1.0, 1.0);
        glVertex2f(0 , 500);
        glVertex2f(900 , 600);
        glVertex2f(900 , 700);
        glVertex2f(0 , 700);

    glEnd();
}


void display()
{
    glClear( GL_COLOR_BUFFER_BIT );
    glLoadIdentity();

    // funtions are declared here
    sky();
    road();
    soil();
    field();
    player();
    player2();
    ball();
    road_side_tree();
    house();
    car1();
    wheel_one();
    wheel_two();
    car2();
    wheel_three();
    wheel_four();
    river();
    boat();
    boat2();
    tree();

    glutSwapBuffers();
}

void reshape( int w, int h )
{
    glViewport( 0 , 0, w, h );
}

void initOpenGL()
{
    /*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,900,0,900);
    glMatrixMode(GL_MODELVIEW);

}

void MyTimerFunc(int value)
{
   if(value == 0)
   {
     glutDisplayFunc(display);
     glutIdleFunc(display);
   }
}

int main(int argc , char **argv)
{

    glutInit( &argc , argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize( 900 , 600 );
    glutInitWindowPosition(100 , 100);
    glutCreateWindow("Opengl Project");

    initOpenGL();

    glutDisplayFunc( intro );
    glutIdleFunc( intro );
    glutTimerFunc(3000, MyTimerFunc, 0);
    glutReshapeFunc( reshape );
    glutMainLoop();


    return 0;
}
