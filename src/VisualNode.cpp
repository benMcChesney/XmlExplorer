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
    
    tagBlock.init( "verdana.ttf" , 14 ) ;
    pathBlock.init( "verdana.ttf" , 14 ) ; 
    setDefaultFontStyle( ) ; 
    
    bLocked = false ; 
}

void VisualNode::setTag( string _tagName , int _tagIndex ) 
{
    tagIndex = _tagIndex ; 
    tagName = _tagName ; 
    tagString = ofToString( tagIndex ) + " :: " + tagName ; 
    tagBlock.setText( tagString ) ; 
    
    if ( tagBlock.getWidth() > pathBlock.getWidth() )
        bounds.width = tagBlock.getWidth() + 5 ;
    
}

void VisualNode::setPath ( string _path )
{
    path = _path ; 
    pathBlock.setText( path ) ; 
    pathBlock.wrapTextX( bounds.width - 20 ) ; 
    
    if ( pathBlock.getWidth() > tagBlock.getWidth() )
        bounds.width = pathBlock.getWidth() + 15 ;
} 

void VisualNode::update( ) 
{
  //  bounds.width = name.size() * 40.05f + 20 ; 
}

void VisualNode::setDefaultFontStyle( ) 
{
    fillColor_off = ofColor ( 75 , 75 , 75 ) ;
    fillColor_on = ofColor ( 245 , 245 , 245 ) ; 
    
    textColor_off = ofColor( 235 , 235 , 235 ) ; 
    textColor_on = ofColor ( 65 , 65 , 65 ) ; 
}

void VisualNode::draw( ) 
{
    ofSetColor( fillColor_off ) ;
    ofRect( bounds ) ; 
    
    ofSetColor( textColor_off ) ;
    tagBlock.draw( bounds.x , bounds.y ) ; 
    pathBlock.draw( bounds.x + 8 , bounds.y ) ;  

}

void VisualNode::drawSelected( ) 
{
    ofSetColor( fillColor_on ) ;
    ofRect( bounds ) ; 
    
    ofSetColor( textColor_on ) ;
    tagBlock.draw( bounds.x , bounds.y ) ; 
    pathBlock.draw( bounds.x + 8 , bounds.y ) ;  
 
}
