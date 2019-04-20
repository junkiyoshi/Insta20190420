#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetLineWidth(2);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	ofColor color;

	for (int r = 100; r >= 10; r -= 10) {

		ofRotate(ofGetFrameNum() * 0.5);

		int v_start = ofGetFrameNum();
		for (int v = v_start; v < v_start + 60; v += 10) {

			for (int u = 0; u < 360; u += 20) {

				ofSetColor(239);
				ofFill();

				ofBeginShape();
				ofVertex(this->make_point(300, r, u - 9.9, v - 4.9));
				ofVertex(this->make_point(300, r, u + 9.9, v - 4.9));
				ofVertex(this->make_point(300, r, u + 9.9, v + 4.9));
				ofVertex(this->make_point(300, r, u - 9.9, v + 4.9));
				ofEndShape(true);

				ofSetColor(39);
				ofNoFill();

				ofBeginShape();
				ofVertex(this->make_point(300, r, u - 10, v - 5));
				ofVertex(this->make_point(300, r, u + 10, v - 5));
				ofVertex(this->make_point(300, r, u + 10, v + 5));
				ofVertex(this->make_point(300, r, u - 10, v + 5));
				ofEndShape(true);
			}
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
glm::vec3 ofApp::make_point(float R, float r, float u, float v) {

	// ���w�f�b�T������ �`���Ċy���ސ��w�����@P.31

	u *= DEG_TO_RAD;
	v *= DEG_TO_RAD;

	float x = (R + r * cos(u)) * cos(v);
	float y = (R + r * cos(u)) * sin(v);
	float z = r * sin(u);

	return glm::vec3(x, y, z);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}