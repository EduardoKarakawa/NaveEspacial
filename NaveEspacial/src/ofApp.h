#pragma once

#include "ofMain.h"
#include <Vector2D.h>

#define STAR_AMOUNT 500

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	void drawImage(ofImage& image, math::Vector2D& position);

	ofImage spaceship;

	math::Vector2D position, velocity, mouse;
	math::Vector2D halfSize, destination;
	math::Vector2D starPosion[STAR_AMOUNT];
	
	void drawStar(math::Vector2D star);

};

