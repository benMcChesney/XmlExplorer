#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "VisualNode.h"

#include "ofxTextSuite.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofxXmlSettings xml ; 
        vector<VisualNode> nodes ;
    
        bool hitTest( float x , float y , ofRectangle r ) ; 
        VisualNode * currentNode ; 
};
