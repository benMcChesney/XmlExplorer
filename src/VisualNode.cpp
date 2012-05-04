//
//  VisualNode.cpp
//  emptyExample
//
//  Created by Ben McChesney on 5/3/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "VisualNode.h"

void VisualNode::setup( ) 
{
    bounds = ofRectangle( 50 , 50 , 50 , 50 ) ; 
}

void VisualNode::update( ) 
{
  //  bounds.width = name.size() * 40.05f + 20 ; 
}

void VisualNode::draw( ) 
{
    ofSetColor ( 255 , 255 , 255 , 125 ) ; 
    ofRect( bounds ) ; 
    ofSetColor ( 255 , 255 , 255 , 255 ) ; 
    ofDrawBitmapString( name , bounds.x , bounds.y + 15 ) ; 
    ofSetColor ( 255 , 255 , 255 , 255 ) ; 
    
   // if ( _type == STRING )
        ofDrawBitmapString( s_value , bounds.x + 10 , bounds.y + 25 ) ; 
   // if ( _type == INT ) 
   //     ofDrawBitmapString( ofToString( i_value ) , bounds.x , bounds.y + 25 ) ; 
   // if ( _type == FLOAT ) 
   //     ofDrawBitmapString( ofToString( f_value ) , bounds.x , bounds.y + 25 ) ; 
}

void VisualNode::drawSelected( ) 
{
    ofSetColor ( 255 , 255 , 255 , 215 ) ; 
    ofRect( bounds ) ; 
    ofSetColor ( 45 , 45 , 45 , 255 ) ; 
    ofDrawBitmapString( name , bounds.x , bounds.y + 15 ) ; 
    //ofSetColor ( 255 , 255 , 255 , 255 ) ; 
    
    // if ( _type == STRING )
    ofDrawBitmapString( s_value , bounds.x , bounds.y + 25 ) ; 
    // if ( _type == INT ) 
    //     ofDrawBitmapString( ofToString( i_value ) , bounds.x , bounds.y + 25 ) ; 
    // if ( _type == FLOAT ) 
    //     ofDrawBitmapString( ofToString( f_value ) , bounds.x , bounds.y + 25 ) ; 
}
