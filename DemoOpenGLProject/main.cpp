//sir
#include <iostream>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h> 
#include <conio.h>
#include <math.h> 

using namespace std;

void  reshapeLine(int w, int h);
void  reshapePoint(int w, int h);
void DrawPointFunctionSet();
void DrawLineFunctionSet();

class ObjectMovment 
{
public:

	int x_axis;
	int y_axis;
	float x;
	float y;
	float points[10][2];
	int rowSize;
	int columSize;
	float translation_dx_value;
	float translation_dy_value;
	int rotationAngle;

	ObjectMovment (){}
	~ObjectMovment ();

	//ObjectMovment(int , int, float, float,float * ,int,int,float,float);
	void setNecessaryPointValue(int , int, float, float,float * ,int,int,float,float);
	void setNecessaryLineValue(int , int, float, float,float * ,int,int,int);

	void drawAxis();
	void printPoint(int,int);

	void DrawPointFunction();
	void pointPlot();
	void translation();

	void DrawLineFunction();
	void linePlot();
	void rotation();

private:

};

ObjectMovment ::~ObjectMovment ()
{
}

void ObjectMovment :: printPoint(int rowSize,int columSize)
{
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < columSize; j++)
		{
			//this->points[i][j] = *((points+i*columSize) + j);
			  cout<< this->points[i][j]<<"  "; //*((points+i*columSize) + j)<<"--";
		}
	}
}


//ObjectMovment ::ObjectMovment (int x_axis, int y_axis, float x, float y,float * points, int rowSize,int columSize,float translation_dx_value = 0.0,float translation_dy_value = 0.0)
void	ObjectMovment :: setNecessaryPointValue (int x_axis, int y_axis, float x, float y,float * points, int rowSize,int columSize,float translation_dx_value = 0.0,float translation_dy_value = 0.0)
{
	this->x_axis = x_axis;
	this->y_axis = y_axis;
	this->x = x;
	this->y = y;

	this->rowSize = rowSize;
	this->columSize = columSize;

	this->translation_dx_value = translation_dx_value;
	this->translation_dy_value = translation_dy_value;

	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < columSize; j++)
		{
			this->points[i][j] = *((points+i*columSize) + j);
		}
	}

	
}



void	ObjectMovment :: setNecessaryLineValue (int x_axis, int y_axis, float x, float y,float * points, int rowSize,int columSize,int rotationAngle = 0)
{
	this->x_axis = x_axis;
	this->y_axis = y_axis;
	this->x = x;
	this->y = y;

	this->rowSize = rowSize;
	this->columSize = columSize;
	 
	this->rotationAngle = rotationAngle;

	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < columSize; j++)
		{
			this->points[i][j] = *((points+i*columSize) + j);
		}
	}

	
}




void ObjectMovment :: drawAxis()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glColor3d(1.0, 0.0, 0.0);
	glLineWidth(5.0);

	glBegin(GL_LINES);
	glVertex2i(0, this->y_axis);
	glVertex2i(0, -this->y_axis);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(-this->x_axis, 0);
	glVertex2i(this->x_axis, 0);
	glEnd();


	glFlush();
}

void ObjectMovment :: translation()
{
	glColor3d(0.0, 1.0, 0.0);

	glPointSize(10.0);

	glBegin(GL_POINTS);
	//vertex

	for (int i = 0; i < this->rowSize; i++)
		glVertex2f(this->points[i][0]+this->translation_dx_value,this->points[i][1]+this->translation_dy_value);
	 

	glEnd();

	glFlush();

	cout << "this is translation function"<<endl;
}

void ObjectMovment :: rotation()
{
	//X = xcosA - ysinA
      //    Y = xsinA + ycosA,
}

void drawPoint(float x, float y) 
{ 
    glPointSize(7.0); 
    //glColor3f(0.0f, 0.0f, 1.0f); 
    glBegin(GL_POINTS); 
    glVertex2f(x, y); 
    glEnd(); 
} 

void drawLine(float x1, float y1,float x2, float y2) 
{ 
	cout << "this is new rotate line"<<endl;
    glPointSize(7.0); 
    //glColor3f(0.0f, 0.0f, 1.0f); 
    glBegin(GL_LINES); 
    glVertex2f(x1, y1); 
	glVertex2f(x2, y2); 
    glEnd(); 
} 
 
void rotateAroundPt(float px, float py, float cx, float cy,int theta) 
{ 
    //float theta = 0.0; 
   
        //glClear(GL_COLOR_BUFFER_BIT); 
        int xf, yf; 
  
        xf = cx + ((float)(px - cx) * cos(theta)) 
             - ((float)(py - cy) * sin(theta)); 
        yf = cy + ((float)(px - cx) * sin(theta)) 
             + ((float)(py - cy) * cos(theta)); 
		
		glColor3f(0.0f, 0.0f, 0.0f); 

        // drawing the centre point 
        drawPoint(cx, cy); 
		
		glColor3f(0.0f, 1.0f, 0.0f);
        // drawing the rotating point 
        drawPoint(xf, yf); 
        
		drawLine(cx,cy,xf,yf);
		
		glFlush(); 
        
    
} 

void ObjectMovment :: DrawPointFunction()
{
	drawAxis();
	
	//glClear(GL_COLOR_BUFFER_BIT);
	//glLoadIdentity();

	glColor3d(0.0, 0.0, 0.0);

	glPointSize(10.0);

	glBegin(GL_POINTS);
	//vertex

	for (int i = 0; i < this->rowSize; i++)
		glVertex2f(this->points[i][0],this->points[i][1]);
	 

	glEnd();

	glFlush();

	if( !((this->translation_dx_value == 0.0) && (this->translation_dy_value == 0.0)))
		translation();

}

void ObjectMovment :: DrawLineFunction()
{
	drawAxis();

	cout << "this is draw line function"<<endl;
	
	//glClear(GL_COLOR_BUFFER_BIT);
	//glLoadIdentity();

	glColor3d(0.0, 0.0, 1.0);

	//glLineWidth(5.0);

	
	//vertex

	for (int i = 0; i < this->rowSize; i+=2)
	{
		glBegin(GL_LINES);
		glVertex2f(this->points[i][0],this->points[i][1]);
		glVertex2f(this->points[i+1][0],this->points[i+1][1]);
		glEnd();
	}



	//glEnd();

	glFlush();

	//if( !((this->translation_dx_value == 0.0) && (this->translation_dy_value == 0.0)))
	//	translation();

	rotateAroundPt(this->points[1][0],this->points[1][1],this->points[0][0],this->points[0][1],this->rotationAngle);
	//rotateAroundPt(this->points[0][0],this->points[0][1],this->points[1][0],this->points[1][1],this->rotationAngle);

}




void ObjectMovment :: pointPlot()
{
	int argc = 1;
	char *argv[1] = {(char*)"Something"};

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Open GL");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
	//glutDisplayFunc(lineSegment);

	glutDisplayFunc(DrawPointFunctionSet);
	
	//glutDisplayFunc(drawAxis);
	glutReshapeFunc(reshapePoint);
	glutMainLoop();
}



void ObjectMovment :: linePlot()
{
	int argc = 1;
	char *argv[1] = {(char*)"Something"};

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Open GL");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
	//glutDisplayFunc(lineSegment);

	glutDisplayFunc(DrawLineFunctionSet);
	
	//glutDisplayFunc(drawAxis);
	glutReshapeFunc(reshapeLine);
	glutMainLoop();
}





ObjectMovment point;

ObjectMovment line;



int main()
{
	float dot[][2] = {
		0,3,3,7
		
	};

	//point.setNecessaryPointValue(10,10,4.0,6.0,(float*)dot,(sizeof(dot)/sizeof(dot[0])),(sizeof(dot[0])/sizeof(dot[0][0])),1.0,1.0);

	//point.pointPlot();

	line.setNecessaryLineValue(10,10,4.0,6.0,(float*)dot,(sizeof(dot)/sizeof(dot[0])),(sizeof(dot[0])/sizeof(dot[0][0])),45);

	line.linePlot();

	//line.printPoint((sizeof(dot)/sizeof(dot[0])),(sizeof(dot[0])/sizeof(dot[0][0])));



	cout << "this is main function"<<endl;

	getch();
	return 0;
}




void  reshapePoint(int w, int h)
{
	//view port v
	//porjection

	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-point.x_axis,point.x_axis,-point.y_axis,point.y_axis);
	//gluPerspective(60,1,2.0,50.0);//angle,ratio,z_near,z_far
	glMatrixMode(GL_MODELVIEW);
}


void  reshapeLine(int w, int h)
{
	//view port v
	//porjection

	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-line.x_axis,line.x_axis,-line.y_axis,line.y_axis);
	//gluPerspective(60,1,2.0,50.0);//angle,ratio,z_near,z_far
	glMatrixMode(GL_MODELVIEW);
}



void DrawPointFunctionSet()
{
	point.DrawPointFunction();
}

void DrawLineFunctionSet()
{
	line.DrawLineFunction();
}
