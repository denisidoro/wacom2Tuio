#pragma once

#include "ofMain.h"
#include "ofEvents.h"

#include "ofxWacomFeelMultiTouch.h"
#include "ofxTuioServer.h"
//#include "../obj/Release/addons/ofxGestures/ofxGestures.h"

//--------------------------------------------------------------
class ofApp : public ofBaseApp
{

	public:

		void setup();
		void update();
		void draw();

		void touchDown(ofTouchEventArgs & touch);
		void touchMoved(ofTouchEventArgs & touch);
		void touchUp(ofTouchEventArgs & touch);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofxWacomFeelMultiTouch wacomTablet;
		int maxFingers;

        ofxTuioServer myTuioServer;
        TuioCursor* cursors[16] = {0};

        vector<string> arguments;
        bool verbose;

};
