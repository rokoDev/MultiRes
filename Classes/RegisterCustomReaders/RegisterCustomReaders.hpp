//
//  RegisterCustomReaders.hpp
//  MightyClickers
//
//  Created by jam on 1/12/16.
//
//

#ifndef RegisterCustomReaders_hpp
#define RegisterCustomReaders_hpp

#include <stdio.h>
#include "CocoStudio.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

#define READER_HEADER_FOR(Class_Name) \
class Class_Name##Reader : public cocostudio::NodeReader \
{ \
public:\
Class_Name##Reader() {};\
~Class_Name##Reader() {};\
static Class_Name##Reader* getInstance();\
static void purge();\
cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* node##Class_Name);\
};

#define READER_DEFINITION_FOR(Class_Name) \
static Class_Name##Reader* _instance##Class_Name##Reader = nullptr;\
Class_Name##Reader* Class_Name##Reader::getInstance()\
\
{\
if (!_instance##Class_Name##Reader)\
{\
_instance##Class_Name##Reader = new Class_Name##Reader();\
}\
return _instance##Class_Name##Reader;\
}\
\
void Class_Name##Reader::purge()\
{\
CC_SAFE_DELETE(_instance##Class_Name##Reader);\
}\
\
Node* Class_Name##Reader::createNodeWithFlatBuffers(const flatbuffers::Table *node##Class_Name)\
{\
Class_Name* node = Class_Name::create();\
Class_Name::setStaticInstance(node);\
setPropsWithFlatBuffers(node, node##Class_Name);\
return node;\
}

#define READERTYPES  \
X(MainScene)     \


#define X(a) READER_HEADER_FOR(a);
READERTYPES
#undef X

void registerCustomReaders(void);

#endif /* RegisterCustomReaders_hpp */
