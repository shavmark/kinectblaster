#include "ofApp.h"

//========================================================================
int main( ){
	ofGLWindowSettings settings;
	settings.setGLVersion(4, 5);
	do {
		settings.width = 800;
		settings.height = 800;
		settings.windowMode = ofWindowMode::OF_WINDOW;
		// this kicks off the running of my app    
		if (ofCreateWindow(settings)) {
			break;
		}
		if (settings.glVersionMinor > 0) {
			settings.glVersionMinor = 0;
			continue;
		}
		if (settings.glVersionMinor > 3) {
			settings.glVersionMajor = 3;
			continue;//bugbug keep trying on crappy devices to see how low things need to go
		}
	} while (settings.glVersionMajor < 3);
	string s = "ver " + ofToString(settings.glVersionMajor) + "." + ofToString(settings.glVersionMinor);
	ofLog(OF_LOG_NOTICE, s);

//	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
