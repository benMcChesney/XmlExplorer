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
    
    string d_string = "__" ; 
    float d_float = 0.01f ; 
    int d_int = -1 ; 
    
    float xmlFloat = d_float ; 
    string xmlString = d_string ;
    int xmlInt = d_int ; 
    
    for ( int i = 0 ; i < numItems ; i++ ) 
    {
        bool bSet = false ; 
        VisualNode vn ; 
        vn.setup( ) ; 
        vn.bounds = bounds ; 
        vn.bounds.y = i * ( bounds.height  + padding ) + offsetY ; 
        vn.name = tagName ; 
        
        /*
        xmlFloat = xml.getValue( tagName, d_float, i ) ; 
        if ( xmlFloat == d_float ) 
            cout << i << " is not a float! " << endl ;
        else
            vn.setToFloat( xmlFloat ) ; 
        */
        xmlString = xml.getValue( tagName, d_string, i ) ; 
        if ( xmlString == d_string ) 
            cout << i << " is not a string! " << endl ; 
        else
            vn.setToString( xmlString ) ; 
        /*
        xmlInt = xml.getValue( tagName , d_int ) ; 
        if ( xmlInt == d_int ) 
            cout << i << " is not an int! " << endl ; 
        else
            vn.setToInt( xmlInt ) ; 
*/
        nodes.push_back( vn ) ; 
 //       xml.popTag() ; 
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
                    cout << "fullPath is : " << fullPath << endl ; 
                    string dataString = "/data/" ; 
                    int dataIndex = fullPath.find( dataString ) + 6 ; 
                    int shortLength = fullPath.size() - dataIndex ; 
                    string relativePath = fullPath.substr( dataIndex , shortLength ) ; 
                    cout << "relativePath : " << relativePath << endl ; 
                                                          
                    currentNode->setToString( relativePath ) ; 
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
        if ( hitTest( x , y , nodes[i].bounds ) == true ) 
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