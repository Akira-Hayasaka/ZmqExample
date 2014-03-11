#include "testApp.h"


void testApp::setup()
{
    string remoteZMQHostIP = "localhost";
    int rcvport = 9999;
    receiver.connect("tcp://" + remoteZMQHostIP + ":" + ofToString(rcvport));
}

void testApp::update()
{
    while (receiver.hasWaitingMessage())
    {
        ofBuffer data;
        ofPixels px;
        receiver.getNextMessage(data);
        ofLoadImage(px, data);
        img.setFromPixels(px);
    }
}

void testApp::draw()
{
    if (img.isAllocated())
    {
        img.draw(0, 0);
    }
}
void testApp::keyPressed(int key){}
void testApp::keyReleased(int key){}
void testApp::mouseMoved(int x, int y){}
void testApp::mouseDragged(int x, int y, int button){}
void testApp::mousePressed(int x, int y, int button){}
void testApp::mouseReleased(int x, int y, int button){}
void testApp::windowResized(int w, int h){}
void testApp::gotMessage(ofMessage msg){}
void testApp::dragEvent(ofDragInfo dragInfo){}