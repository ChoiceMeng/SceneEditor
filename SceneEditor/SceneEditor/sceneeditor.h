#ifndef SCENEEDITOR_H
#define SCENEEDITOR_H

#include <QtGui/QMainWindow>
#include "ui_sceneeditor.h"

static const int         WINDOW_WIDTH = 1024;  

static const int         WINDOW_HEIGHT = 768;  

class OgreViewWidget;
class SceneEditor : public QMainWindow
{
	Q_OBJECT

public:
	SceneEditor(QWidget *parent = 0, Qt::WFlags flags = 0);
	~SceneEditor();

private:
	Ui::SceneEditorClass ui;

	QDockWidget* m_LeftWidget;

	QAction* m_pFileNew;
	QToolBar* m_FileToolBar;

	OgreViewWidget* m_pOgreView;
};

#endif // SCENEEDITOR_H
