//Created by Jiteng Liu (Leo)

#line 1 "Quiz_2_1_1-2"

#include "ofMain.h"

class ofApp: public ofBaseApp
{
public:

#line 1 "Quiz_2_1_1-2"

ofPolyline polyline;        //set up a polyline
ofPolyline movePolyline;        //set up a polyline

void setup() {      //to define the basic environment conditions before the program starts
    ofSetWindowShape(500, 500);     //Set the size of the window "aquatic plant"
    for (int i=250; i>=-200; i-=8) polyline.addVertex(ofVec2f(0,i));        //set the position of the
    movePolyline = polyline;        //make the polyline equal to movepolyline
}

void draw() {       //to excute the code
    ofBackground(127);      // Set the background color
    ofSetColor(77,204,0);       //Set the the color of "aquatic plant"
    
    for (int i=0; i<polyline.size(); i++) {     // To create the horizontal line on each point of tangency
        ofVec3f normal = polyline.getNormalAtIndexInterpolated(i); 
        
        ofPushMatrix();     // Create the Vertical Line
            ofTranslate(250,250);       //the parameter of translate
            movePolyline.draw();        
        ofPopMatrix();      //finish the push matrix
    
        ofPushMatrix();     // Create a lot of horizontal line 
            ofTranslate(250, 250);      //the parameter of translate
            ofLine(movePolyline[i]-normal*(polyline.size() -i), movePolyline[i]+normal*(polyline.size() -i));
        ofPopMatrix();      //finish the push matrix
    }
}
};

int main()      //hand out "main"
{
    ofSetupOpenGL(320, 240, OF_WINDOW);     //set up the GL
    ofRunApp(new ofApp());      //run the project
}

