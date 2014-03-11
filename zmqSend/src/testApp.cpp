#include "testApp.h"


void testApp::setup()
{
    sender = ofPtr<ofxZmqPublisher>(new ofxZmqPublisher);
    sender->setHighWaterMark(2);
    sender->bind(string("tcp://*:") + "9999");
    
    test.loadImage("test.jpg");
}

void testApp::send(ofImage img)
{
    ofBuffer imgbuf;
    ofSaveImage(img.getPixelsRef(), imgbuf);
    sender->send(imgbuf);
}

void testApp::draw()
{
    test.draw(0, 0);
}

void testApp::keyPressed(int key)
{
    if (key == ' ')
    {
        send(test);
    }
}

void testApp::update(){}
void testApp::keyReleased(int key){}
void testApp::mouseMoved(int x, int y){}
void testApp::mouseDragged(int x, int y, int button){}
void testApp::mousePressed(int x, int y, int button){}
void testApp::mouseReleased(int x, int y, int button){}
void testApp::windowResized(int w, int h){}
void testApp::gotMessage(ofMessage msg){}
void testApp::dragEvent(ofDragInfo dragInfo){}