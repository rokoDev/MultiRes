//
//  MainScene.cpp
//  MultiRes
//
//  Created by roko on 8/27/16.
//
//

#include "MainScene.hpp"

USING_NS_CC;

using namespace cocos2d::ui;

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::createDefault();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

MainScene * MainScene::sm_pTmpInstance = nullptr;

cocos2d::ccNodeLoadCallback MainScene::sm_nodeLoadCallback = [](Ref * pNodeRef) {
    if (MainScene::sm_pTmpInstance) {
        MainScene::sm_pTmpInstance->determineAndSetMemberVarFromNode(pNodeRef);
    }
};

void MainScene::setStaticInstance(MainScene * pInstance)
{
    sm_pTmpInstance = pInstance;
}

MainScene::~MainScene()
{
    CCLOG("%d, %s", __LINE__, __FUNCTION__);
}

MainScene::MainScene(): m_pMainPanel(nullptr), m_pBuySkillButton(nullptr), m_pCountText(nullptr)
{
    
}

MainScene * MainScene::createDefault(void)
{
    const std::string fileName = "MainScene.csb";
    auto data = FileUtils::getInstance()->getDataFromFile(fileName);
    auto rootNode = static_cast<MainScene*>(CSLoader::createNode(data, MainScene::sm_nodeLoadCallback));
    
    rootNode->setContentSize(Director::getInstance()->getWinSize());
    ui::Helper::doLayout(rootNode);
    
    return (MainScene*)rootNode;
}

#pragma mark WidgetCallBackHandlerProtocol methods

Widget::ccWidgetTouchCallback MainScene::onLocateTouchCallback(const std::string &callBackName)
{
    if (callBackName == "onMainButton")
    {
        return CC_CALLBACK_2(MainScene::onBuySkill, this);
    }
    return nullptr;
}

bool MainScene::init()
{
    if (Layout::init()) {
        return true;
    }
    return false;
}

void MainScene::onEnter()
{
    Layout::onEnter();
}

void MainScene::onExit()
{
    Layout::onExit();
}

bool MainScene::determineAndSetMemberVarFromNode(cocos2d::Ref * pNode)
{
    Button * pButton = dynamic_cast<Button *>(pNode);
    if (pButton) {
        if ("BuySkillButton" == pButton->getName()) {
            this->setBuySkillButton(pButton);
        }
        return false;
    }
    
    Text * pText = dynamic_cast<Text *>(pNode);
    if (pText) {
        if ("CountText" == pText->getName()) {
            this->setCountText(pText);
        }
        return false;
    }
    
    Layout * pLayout = dynamic_cast<Layout *>(pNode);
    if (pLayout) {
        if ("MainPanel" == pLayout->getName()) {
            this->setMainPanel(pLayout);
        }
        return false;
    }
    
    return false;
}

void MainScene::refreshMemberVariables(void)
{
    this->enumerateChildren("//[[:alnum:]]+", [this](Node * pNode) -> bool {
        return this->determineAndSetMemberVarFromNode(pNode);
    });
}

#pragma mark Button' callbacks
void MainScene::onBuySkill(cocos2d::Ref * sender, cocos2d::ui::Widget::TouchEventType type)
{
    CCLOG("%d, %s", __LINE__, __FUNCTION__);
    switch (type) {
        case Widget::TouchEventType::BEGAN:
        {
            break;
        }
        case Widget::TouchEventType::MOVED:
            break;
        case Widget::TouchEventType::ENDED:
        {
            CCLOG("Buy_Skill");
            break;
        }
        case Widget::TouchEventType::CANCELED:
            break;
            
        default:
            break;
    }
}