//
//  VisualNode.h
//  emptyExample
//
//  Created by Ben McChesney on 5/3/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef emptyExample_VisualNode_h
#define emptyExample_VisualNode_h

#include "ofMain.h"

#include "ofxTextSuite.h"

/* Goal is to store tagname, tagIndex , and path with children ? */
class VisualNode
{
    public :
        VisualNode ( ) { } 
    
        void setup ( ) ; 
        void update( ) ;
        void draw( ) ;
        void drawSelected( ) ;
    
        void setPath ( string _path ) ; 
        string getPath( ) {return path ; }  
    
        void setTag( string _tagName , int _tagIndex ) ;
    
        ofRectangle getBounds ( ) { return bounds ; } 
        void setBounds ( ofRectangle _bounds ) { bounds = _bounds ; }
        void setDefaultFontStyle( ) ; 
    
        ofColor fillColor_off ;
        ofColor textColor_off ;
        ofColor fillColor_on ;
        ofColor textColor_on ;
    
        string getTagName() { return tagName ; }
        int getTagIndex() { return tagIndex ; }
    
        //cannot change values
        bool bLocked ; 
    
    
    
    private :
        string path; 
        string tagString ;
        string tagName ; 
        int tagIndex ; 
    
        ofRectangle bounds ;
        ofxTextBlock tagBlock ;
        ofxTextBlock pathBlock ;
};
#endif
