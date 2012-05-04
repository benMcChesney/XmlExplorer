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

enum xmlType
{
    STRING = 0 , 
    FLOAT = 1 , 
    DOUBLE = 2 , 
    INT = 3
};

class VisualNode
{
    public :
        VisualNode ( ) 
        {
            _type = STRING ; 
        } 
    
        void setup ( ) ; 
        void update( ) ;
        void draw( ) ;
        void drawSelected( ) ;
    
        void setToString( string s ) 
        {
            _type = STRING ;
            s_value = s ;
        }
        
        void setToInt( int i ) 
        {
            _type = INT ;
            i_value = i ;
        }
    
        void setToFloat( float f ) 
        {
            _type = FLOAT ; 
            f_value = f ; 
        }
    
        ofRectangle bounds ; 
        string name ; 
        
        int i_value ;
        float f_value ;
        string s_value ; 
        
        xmlType _type ; 
    
        
};
#endif
