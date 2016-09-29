#include "ofApp.h"
#include <time.h>

using namespace math;
Vector2D global_camera;

//--------------------------------------------------------------
void ofApp::setup() {
	srand(time(NULL));
	spaceship.load("saucer.png");
	position.set(ofGetWidth() / 2, ofGetHeight() / 2);
	halfSize = Vector2D(spaceship.getWidth(), spaceship.getHeight()) / 2;
	velocity = Vector2D(300, 0);
	mouse.set(position);

	for (int i = 0; i < STAR_AMOUNT; i++) {
		starPosion[i] = Vector2D(rand() % ofGetWidth(), rand() % ofGetHeight());
	}

}

//--------------------------------------------------------------
void ofApp::update() {
	position += velocity * ofGetLastFrameTime();
	global_camera += velocity * ofGetLastFrameTime();

	if (distanceSqr(position, destination) < 3 * 3) {
		
		velocity.set(0, 0);
	}

	velocity = (mouse - position) / 0.5f;
	destination = mouse;

	for (int i = 0; i < STAR_AMOUNT; i++){
		Vector2D& pos = starPosion[i];

		if (pos.x > ofGetWidth() + global_camera.x)
			pos.x = global_camera.x;
		else if (pos.x < global_camera.x)
			pos.x = ofGetWidth() + global_camera.x;

		if (pos.y > ofGetHeight() + global_camera.y)
			pos.y = global_camera.y;
		else if (pos.y < global_camera.y)
			pos.y = ofGetHeight() + global_camera.y;
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetBackgroundColor(0, 0, 0);

	for (int i = 0; i < STAR_AMOUNT; i++){
		drawStar(starPosion[i]);
	}

	drawImage(spaceship, Vector2D(ofGetWidth(), ofGetHeight()) / 2);
}

void ofApp::drawImage(ofImage& image, Vector2D& position) {
	Vector2D tmp = position + global_camera;
	image.draw(tmp.x, tmp.y);
}

void ofApp::drawStar(Vector2D star) {
	Vector2D tmp = star - global_camera;
	ofDrawCircle(tmp.x, tmp.y, 1);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	mouse.set(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
