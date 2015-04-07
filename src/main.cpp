#line 1 "Quiz_2_1_1-2"

#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:

#line 1 "Quiz_2_1_1-2"
ofPolyline polyline;
ofPolyline movePolyline;

void setup() {
    //Set the size of the window "aquatic plant"
    ofSetWindowShape(500, 500); 
    //set the position of the 
    for (int i=250; i>=-200; i-=8) polyline.addVertex(ofVec2f(0,i));
    movePolyline = polyline;
}

void draw() {
    // Set the background color
    ofBackground(127);
    //Set the the color of "aquatic plant"
    ofSetColor(77,204,0);
    
    // To create the horizontal line on each point of tangency
    for (int i=0; i<polyline.size(); i++) {
        ofVec3f normal = polyline.getNormalAtIndexInterpolated(i); 
        
        // Create the Vertical Line
        ofPushMatrix();
            ofTranslate(250,250);
            movePolyline.draw();        
        ofPopMatrix();
    
        // Create a lot of horizontal line 
        ofPushMatrix();
            ofTranslate(250, 250);
            ofLine(movePolyline[i]-normal*(polyline.size() -i), movePolyline[i]+normal*(polyline.size() -i));
        ofPopMatrix();
    }
}

};

int main()
{
    ofSetupOpenGL(320, 240, OF_WINDOW);
    ofRunApp(new ofApp());
}

