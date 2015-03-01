#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofBackground(0, 0, 0);
	//ofSetLogLevel(OF_LOG_VERBOSE);

	wacomTablet.init(true);
	wacomTablet.listAttachedDevices();

	ofAddListener(ofEvents().touchDown, this, &ofApp::touchDown);
	ofAddListener(ofEvents().touchUp, this, &ofApp::touchUp);
	ofAddListener(ofEvents().touchMoved, this, &ofApp::touchMoved);

	string domain = (arguments.size() > 1) ? arguments.at(1) : "127.0.0.1";
	int port = (arguments.size() > 2) ? atoi(arguments.at(2).c_str()) : 3333;
    verbose = (arguments.size() > 3) ? arguments.at(3) == "true" : true;
	ofLogNotice() << "Sending data to " << domain << ":" << port;

	myTuioServer.start(&domain[0u], port);
	myTuioServer.setVerbose(true);

}

//--------------------------------------------------------------
void ofApp::update(){

	myTuioServer.run();

}

//--------------------------------------------------------------
void ofApp::draw() {}

//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch) {

    if (verbose) ofLogNotice() << "Touchdown\t" << touch.id << "\t(" << touch.x << ", " << touch.y << ")";
    cursors[touch.id] = myTuioServer.addCursor(touch.x*ofGetWidth(), touch.y*ofGetHeight());

}

//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch) {

    //ofLogNotice() << touch.x << ", " << touch.y;
    myTuioServer.updateCursor(cursors[touch.id], touch.x*ofGetWidth(), touch.y*ofGetHeight());

}

//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch) {

    if (verbose) ofLogNotice() << "Touchup\t" << touch.id << "\t(" << touch.x << ", " << touch.y << ")";
    myTuioServer.removeCursor(cursors[touch.id]);

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
