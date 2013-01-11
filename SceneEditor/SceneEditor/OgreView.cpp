#include "OgreView.h"
#include "QEvent.h"

OgreViewWidget::OgreViewWidget(QWidget* parent) : QWidget(parent,Qt::WFlags(Qt::MSWindowsOwnDC))  
{
	mRenderWindow = NULL;  
	mSceneMgr = NULL;  
	mVp = NULL;  
	mainEnt = NULL;  
	mainNode = NULL;  
	//....还有一些控制变量的初始化  
	setupResources();  
}   
OgreViewWidget::~OgreViewWidget()  
{  
	// destroy Viewport and RenderWindow  
	if( mVp )  {    
		mRenderWindow->removeViewport(mVp->getZOrder());    
		mVp = 0;  
	}   
	Ogre::Root::getSingleton().detachRenderTarget(mRenderWindow);  
	mRenderWindow = 0;   
	if(mRoot != NULL){    
		delete mRoot;    
		mRoot = 0;  
	}  
} 

void OgreViewWidget::setupResources()  
{  
	mRoot = new Ogre::Root();  
	Ogre::ConfigFile cf;  
	cf.load("resources.cfg");   
	Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();  
	Ogre::String secName, typeName, archName;  
	while(seci.hasMoreElements())  
	{    
		secName = seci.peekNextKey();    
		Ogre::ConfigFile::SettingsMultiMap* settings = seci.getNext();    
		Ogre::ConfigFile::SettingsMultiMap::iterator i;    
		for(i=settings->begin(); i!=settings->end(); ++i)
		{     
			typeName = i->first;    
			archName = i->second;     
			Ogre::ResourceGroupManager::getSingleton().addResourceLocation(archName, typeName, secName);    
		}  
	}   
	if(!mRoot->restoreConfig())    
	{     
		mRoot->showConfigDialog();    
	}  
	mRoot->initialise(false);        
	//以上都是从Ogre普通程序照搬  
}  
//没啥说的，代码比注释更明白  
void OgreViewWidget::createScene() 
{    
	mainEnt = mSceneMgr->createEntity("Head", "ogrehead.mesh");    
	mainNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();    
	mainNode->attachObject(mainEnt);  
}   
void OgreViewWidget::createLight()  
{       
	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));     
	mainLight = mSceneMgr->createLight("MainLight");      
	mainLight->setPosition(20,80,50);  
}

void OgreViewWidget::setupView()  
{      
	if(mRenderWindow)          
		return;    
	//createRenderWindow,当然必须得自己手工建窗口了，把窗口句柄扒出来....   
	Ogre::NameValuePairList params;  
	params["externalWindowHandle"] = Ogre::StringConverter::toString((size_t)(HWND)winId());  
	mRenderWindow = mRoot->createRenderWindow("View", width(), height(), false);  
	//SceneManager    
	mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC);    
	//setup camera & viewport     
	mCamera = mSceneMgr->createCamera("PlayerCam");    
	mCamera->setPosition(Ogre::Vector3(0,0,80));    
	mCamera->lookAt(Ogre::Vector3(0,0,-300));    
	mCamera->setNearClipDistance(5);    
	mVp = mRenderWindow->addViewport(mCamera);    
	mVp->setBackgroundColour(Ogre::ColourValue(0, 0.0, 0.0, 1));  
	mCamera->setAspectRatio(Ogre::Real(mVp->getActualWidth()) / Ogre::Real(mVp->getActualHeight()));    
	//resource  
	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();     
	createScene();     
	createLight();     
	startTimer(2);  
}   

void OgreViewWidget::paintEvent(QPaintEvent *evt)  
{  
	Q_UNUSED(evt);      
	if(mRenderWindow == NULL)          
		setupView();    
	update();  
}   

void OgreViewWidget::timerEvent(QTimerEvent* evt)  
{  
	Q_UNUSED(evt);  
	update();   
}   

void OgreViewWidget::update()  
{  
	//手工更新场景内容，而不是进入到连续的循环中          
	if(mRenderWindow != NULL){    
		mRoot->_fireFrameStarted();    
		mRenderWindow->update();     
		mCamera->moveRelative(mDirection);    
		mCamera->yaw(Ogre::Radian(angleX));    
		mCamera->pitch(Ogre::Radian(angleY));     
		mRoot->_fireFrameEnded();  
	}  
} 

void OgreViewWidget::resizeEvent(QResizeEvent *evt)  
{  
	Q_UNUSED(evt);  
	if (mRenderWindow != NULL)
	{    
		mRenderWindow->windowMovedOrResized();    
		mCamera->setAspectRatio(Ogre::Real(mVp->getActualWidth()) / Ogre::Real(mVp->getActualHeight()));  
	}  
} 

void OgreViewWidget::keyPressEvent(QKeyEvent* evt)  
{  
	if(mainEnt != NULL && mainNode != NULL){    
		switch(evt->key())
		{     
		case Qt::Key_W:     
		case Qt::Key_Up:      
			rotX = -0.1;      
			mainNode->pitch(Ogre::Radian(rotX));      
			break;     
		case Qt::Key_S:     
		case Qt::Key_Down:      
			rotX = 0.1;      
			mainNode->pitch(Ogre::Radian(rotX));      
			break;     
		case Qt::Key_A:     
		case Qt::Key_Left:      
			rotY = -0.1;      
			mainNode->yaw(Ogre::Radian(rotY));      
			break;     
		case Qt::Key_D:     
		case Qt::Key_Right:      
			rotY = 0.1;      
			mainNode->yaw(Ogre::Radian(rotY));      
			break;    
		}  
	}  
}   

void OgreViewWidget::mousePressEvent(QMouseEvent* evt)  
{  
	if(evt->button() == Qt::LeftButton)    
		mouseLeftPressed = true;  
	if(evt->button() == Qt::RightButton)
	{    
		mouseRightPressed = true;    
		mousePos = Ogre::Vector2(evt->x(), evt->y());  
	}  
	if(evt->button() == Qt::MidButton)    
		mouseMiddleBtn = true;  
}  

void OgreViewWidget::wheelEvent(QWheelEvent* evt)  
{  
	mDirection.z = -evt->delta()/12;  
	update();  
	mDirection.z = 0;  
} 