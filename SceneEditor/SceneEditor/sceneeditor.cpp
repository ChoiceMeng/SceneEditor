#include "sceneeditor.h"
#include "QDockWidget"
#include "QTextEdit"
#include "OgreView.h"

SceneEditor::SceneEditor(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	setWindowTitle("Editor");       //设置窗口标题  
	  
	resize( WINDOW_WIDTH, WINDOW_HEIGHT);// 设置窗口大小  

	/*
	m_LeftWidget = new QDockWidget(tr("Enitity"), this);
	m_LeftWidget->setAllowedAreas(Qt::LeftDockWidgetArea);
	addDockWidget(Qt::LeftDockWidgetArea, m_LeftWidget);

	QTextEdit *te1=new QTextEdit();  
	te1->setText(tr("Window1,The dock widget can be moved between docks by the user"));  
	m_LeftWidget->setWidget(te1);

	m_pFileNew = new QAction(QIcon(":/images/new.png"), tr("&New"), this);  	
	m_pFileNew -> setShortcuts(QKeySequence::New);  	
	m_pFileNew -> setStatusTip(tr("Create a new map"));  	

	m_FileToolBar = addToolBar(tr("file"));
	*/

	m_pOgreView = new OgreViewWidget(this);
	setCentralWidget(m_pOgreView);
}

SceneEditor::~SceneEditor()
{

}
