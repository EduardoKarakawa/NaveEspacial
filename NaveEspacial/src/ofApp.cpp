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

	//Gerando as posições das estrelas
	for (int i = 0; i < STAR_AMOUNT; i++) {
		starPosion[i] = Vector2D(rand() % ofGetWidth(), rand() % ofGetHeight());
	}

}

//--------------------------------------------------------------
void ofApp::update() {

	position += velocity * ofGetLastFrameTime();
	//Atualizando a posicao da "camera"
	global_camera += velocity * ofGetLastFrameTime();
	
	//Zerando a velocidade de movimentacao da nave e da camera
	if (distanceSqr(position, destination) < 3 * 3) {
		
		velocity.set(0, 0);
	}

	//Gerando uma velocidade para que a nave percorra o caminha em 0.5 segundo
	//em qualquer distancia
	velocity = (mouse - position) / 0.5f;
	destination = mouse;

	//Fazendo as estrelas que chegarem ao limite da tela serem reposicionadas no lado oposto da tela 
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

	//Imprimindo as estrelas
	for (int i = 0; i < STAR_AMOUNT; i++){
		drawStar(starPosion[i]);
	}
	//Imprimendo a nave
	drawImage(spaceship, Vector2D(ofGetWidth(), ofGetHeight()) / 2);
}

//Funcao para imprimir a nave
void ofApp::drawImage(ofImage& image, Vector2D& position) {
	Vector2D tmp = position + global_camera;
	image.draw(tmp.x, tmp.y);
}

//Funcao para imprimir as estrelas
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
