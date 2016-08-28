//
//  MainScene.hpp
//  MultiRes
//
//  Created by roko on 8/27/16.
//
//

#ifndef MainScene_hpp
#define MainScene_hpp

#include <stdio.h>

#include "cocos2d.h"

#include "cocostudio/CocoStudio.h"

#include "cocostudio/WidgetCallBackHandlerProtocol.h"

#include "CocosGUI.h"

class MainScene : public cocos2d::ui::Layout, public cocostudio::WidgetCallBackHandlerProtocol {
    friend class MainSceneReader;
private:
    CC_DISALLOW_COPY_AND_ASSIGN(MainScene);
protected:
    static MainScene * sm_pTmpInstance;
    static void setStaticInstance(MainScene * pInstance);
    
    MainScene();
    virtual bool init() override;
    
    bool determineAndSetMemberVarFromNode(cocos2d::Ref * pNode);
    
    CC_SYNTHESIZE(cocos2d::ui::Layout *, m_pMainPanel, MainPanel);
    CC_SYNTHESIZE(cocos2d::ui::Button *, m_pBuySkillButton, BuySkillButton);
    CC_SYNTHESIZE(cocos2d::ui::Text *, m_pCountText, CountText);
    
public:
    virtual ~MainScene();
    static cocos2d::ccNodeLoadCallback sm_nodeLoadCallback;
    
    static cocos2d::Scene* createScene();
    
    CREATE_FUNC(MainScene)
    
#pragma mark WidgetCallBackHandlerProtocol methods
    cocos2d::ui::Widget::ccWidgetTouchCallback onLocateTouchCallback(const std::string &callBackName) override;
    cocos2d::ui::Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName) override;
    
    static MainScene * createDefault(void);
    
    virtual void onEnter() override;
    virtual void onExit() override;
    
    void refreshMemberVariables(void);
    
#pragma mark Button' callbacks
    void onPlayDownAct(cocos2d::Ref * sender, cocos2d::ui::Widget::TouchEventType type);
    void onPlayLeftAct(cocos2d::Ref * sender, cocos2d::ui::Widget::TouchEventType type);
    void onPlayRightAct(cocos2d::Ref * sender, cocos2d::ui::Widget::TouchEventType type);
    void onPlayTopAct(cocos2d::Ref * sender, cocos2d::ui::Widget::TouchEventType type);
};

#endif /* MainScene_hpp */
