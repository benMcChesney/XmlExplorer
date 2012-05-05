#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground( 0 , 0, 0 ) ; 
    ofEnableAlphaBlending() ; 
    xml.loadFile( "xml/test.xml" ) ; 
    
    
    string tagName = "item" ; 
    int numItems = xml.getNumTags( tagName ) ; 
    cout << "numItems" << numItems << endl ; 
    
    ofRectangle bounds  = ofRectangle( 15 , 0 , 75 , 50 ) ; 
    float padding = 20 ; 
    float offsetY = 25 ; 
    
    string path ;
    
    for ( int i = 0 ; i < numItems ; i++ ) 
    {
        bool bSet = false ; 
        VisualNode vn ; 
        bounds.y = i * ( bounds.height  + padding ) + offsetY ; 
        vn.setup( ) ;
        vn.setBounds( bounds ); 
        vn.setTag( tagName , i ) ; 
    
        path = xml.getValue( tagName, "", i ) ; 
        if ( path == "" ) 
            cout << i << " is not a string! " << endl ; 
        else
            vn.setPath( path ) ; 
        
        nodes.push_back( vn ) ; 
    }
    
    currentNode = NULL ; 
}

//--------------------------------------------------------------
void testApp::update(){
    for ( int i = 0 ; i < nodes.size() ; i++ ) 
    {
        nodes[i].update ( ) ; 
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    for ( int i = 0 ; i < nodes.size() ; i++ ) 
    {
        nodes[i].draw ( ) ; 
    }
    
    if ( currentNode != NULL ) 
    {
        currentNode->drawSelected() ; 
    }
    
   //  xml.saveFile("xml/test.xml") ; 
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch ( key ) 
    {
        case 'o':
        case 'O':
            if ( currentNode != NULL ) 
            {
                ofFileDialogResult result = ofSystemLoadDialog( "PICK YOUR CONTENT FOR X" , false ) ; 
                if ( result.bSuccess ) 
                {
                    string fullPath = result.getPath( ) ; 
                    //cout << "fullPath is : " << fullPath << endl ; 
                    string dataString = "/data/" ; 
                    int dataIndex = fullPath.find( dataString ) + 6 ; 
                    int shortLength = fullPath.size() - dataIndex ; 
                    string relativePath = fullPath.substr( dataIndex , shortLength ) ; 
                    //cout << "relativePath : " << relativePath << endl ; 
                                                         
                    string tagName = "item" ; 
                    currentNode->setPath( relativePath ) ; 
                    
                    xml.setValue( tagName, relativePath , currentNode->getTagIndex() ) ; 
//                    xml.setValue( tagName , currentNode->getTagName() ,  currentNode->getTagIndex() ) ;
                    xml.saveFile("xml/test.xml") ; 
                }
            }
            break ; 
            
    }
}

bool testApp::hitTest( float x , float y , ofRectangle r ) 
{
    if ( ( x > r.x && x < ( r.x + r.width ) ) && ( y > r.y && y < ( r.y + r.height ) )  )
        return true ; 
    else
        return false ;
    
}


//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    for ( int i = 0 ; i < nodes.size() ; i++ ) 
    {
        if (nodes[i].bLocked == false && hitTest( x , y , nodes[i].getBounds( ) ) == true ) 
        {
            currentNode = &nodes[i] ; 
            return ; 
        }
    }
    
    //Made it this far, nothing was selected
    currentNode = NULL ; 
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}