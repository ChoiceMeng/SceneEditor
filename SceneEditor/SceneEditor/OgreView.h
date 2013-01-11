#pragma once
#include "kernel\qwidget.h"
#include "Pre.h"

class OgreViewWidget : public QWidget  
{  
	Q_OBJECT   
public:  
	OgreViewWidget(QWidget* parent);  
	~OgreViewWidget();  
	//QSize minimumSizeHint() const;  
	//QSize sizeHint() const;  
protected:    
	void setupView();//创建Ogre使用的内容，场景内容;  
	void update();//通过它，手动更新场景内容  
	void setupResources();
	void createScene();  
	void createLight();  
	void resizeEvent(QResizeEvent* evt);//窗口可能缩放  
	void timerEvent(QTimerEvent* evt);//可以设一时钟来更新窗口  
	void paintEvent(QPaintEvent* evt);//呵，当然得处理了          
	//消息响应  
	void keyPressEvent(QKeyEvent* evt);  
	void keyReleaseEvent(QKeyEvent* evt){}  
	void mousePressEvent(QMouseEvent* evt);  
	void mouseReleaseEvent(QMouseEvent* evt){}  
	void mouseMoveEvent(QMouseEvent* evt){}  
	void wheelEvent(QWheelEvent* evt);   
	//有关Ogre  
	Ogre::RenderWindow* mRenderWindow;  
	Ogre::SceneManager* mSceneMgr;  
	Ogre::Camera* mCamera;  
	Ogre::Viewport* mVp;  
	Ogre::Root* mRoot;  
	Ogre::Light* mainLight;    
	Ogre::Entity* mainEnt;  
	Ogre::SceneNode* mainNode;  
	//一些控制变量，没有完全列出  
	Ogre::Vector3 mDirection;  
	Ogre::Real mRotate;   
	Ogre::Real angleX;
	Ogre::Real angleY;
	Ogre::Real rotX;
	Ogre::Real rotY;
	bool mouseLeftPressed;
	bool mouseRightPressed;
	bool mouseMiddleBtn;
	Ogre::Vector2 mousePos;
};  