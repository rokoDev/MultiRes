//
//  RegisterCustomReaders.cpp
//  MightyClickers
//
//  Created by jam on 1/12/16.
//
//

#include "RegisterCustomReaders.hpp"

// Macro for adding quotes
#define STRINGIFY(X) STRINGIFY2(X)
#define STRINGIFY2(X) #X

// Macros for concatenating tokens
#define CAT(X,Y) CAT2(X,Y)
#define CAT2(X,Y) X##Y
#define CAT_2 CAT
#define CAT_3(X,Y,Z) CAT(X,CAT(Y,Z))
#define CAT_4(A,X,Y,Z) CAT(A,CAT_3(X,Y,Z))

#include "MainScene.hpp"

USING_NS_CC;

using namespace cocos2d::ui;

#define X(a) READER_DEFINITION_FOR(a);
READERTYPES
#undef X

#define REGISTER_READER(readerClassName)\
CSLoader::getInstance()->registReaderObject(#readerClassName,(ObjectFactory::Instance)readerClassName::getInstance);

void registerCustomReaders(void)
{
    CCLOG("%s, line:%d, func:%s", __FILE__, __LINE__, __FUNCTION__);
#define X(a) REGISTER_READER(a##Reader);
    READERTYPES
#undef X
}
