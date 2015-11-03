// traffic.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<GL/glut.h>
#include<stdio.h>
#include<string.h>
#define ESCAPE 27
int view=0;

void text(int x,int y,char *string,int font)
{
	int i=0;
	glColor3f(0.0,0.5,0.8);
	glRasterPos2f(x,y);
	for(i=0;i<strlen(string);i++)
	{
		if(font==1)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
		else if(font==2)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
		else if(font==3)
		{
			glColor3f(1.0,0.0,0.0);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
		}
	}
}
void First_win()
{
	glClearColor(1.0,1.0,0.6,1.0);
	text(290,700,"TRAFFIC LIGHT SIMULATOR",1);
	text(350,660,"Using OpenGL",1);
	text(400,620,"Made By:",2);
	text(300,580,"Zeya Umayya & Zishan Ahmad",1);
	text(100,540,"INSTRUCTIONS::",2);
	text(300,100,"!!!!PRESS SPACEBAR TO ENTER INTO THE ARENA!!!!",3);
	glutPostRedisplay();
	//glutSwapBuffers();
}
void init()
{
	glClearColor(0,0,0,0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,1000,0.0,800,50.0,-50.0);
	glutPostRedisplay();
}
void road_strips()
{
	//first bottom green strip
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.8,0.0);
		glVertex2d(0,200);
		glVertex2d(0,250);
		glVertex2d(1000,250);
		glVertex2d(1000,200);
	glEnd();
	glPopMatrix();

	//second grey strip
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.5,0.5,0.5);
		glVertex2d(0,250);
		glVertex2d(0,500);
		glVertex2d(1000,500);
		glVertex2d(1000,250);
	glEnd();
	glPopMatrix();

	//tilted grey strip
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.5,0.5,0.5);
		glVertex2d(300,500);
		glVertex2d(200,800);
		glVertex2d(350,800);
		glVertex2d(500,500);
	glEnd();
	glPopMatrix();

	//Dotted strips


	//traffic signal controller
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.7,0.3,0.0);
		glVertex2d(600,350);  //1
		glVertex2d(650,350);  //2
		glVertex2d(650,370);  //3..
		glVertex2d(600,370);//12
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.6,0.2,0.0);
		glVertex2d(630,370);  //4
		glVertex2d(630,500);  //5
		glVertex2d(620,500);//10
		glVertex2d(620,370);//11
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.7,0.3,0.0);
		glVertex2d(640,500);  //6
		glVertex2d(640,700);  //7
		glVertex2d(610,700);  //8
		glVertex2d(610,500); //9		
	glEnd();
	glPopMatrix();

}
void main_display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if(view==0)
	{
		init();
		First_win();
	}
	else
	{
		//---------CONSTANT PARTS
		//ROAD STRIP
		road_strips();
	}
	glutSwapBuffers();
}
void traffic_start()
{}
void keyboard(unsigned char key,int x,int y)
{
	
	switch(key)
	{
		case ESCAPE:exit(1);
		case ' ':view=1;
				glClearColor(0,0,0,0);
				traffic_start();
				break;
		default:printf("You pressed %c\n",key);
		
	}
}
void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	printf("Width=%d height=%d \n",w,h);

}
int main(int argc,char** argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
	glutInitWindowSize(1000,800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("My_carr");
	
	//glutFullScreen();
	glutDisplayFunc(main_display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	//glutMouseFunc();
	glutMainLoop();
	return 0;
}
