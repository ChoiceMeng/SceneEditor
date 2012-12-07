#ifndef SCENEEDITOR_H
#define SCENEEDITOR_H

#include <QtGui/QMainWindow>
#include "ui_sceneeditor.h"

class SceneEditor : public QMainWindow
{
	Q_OBJECT

public:
	SceneEditor(QWidget *parent = 0, Qt::WFlags flags = 0);
	~SceneEditor();

private:
	Ui::SceneEditorClass ui;
};

#endif // SCENEEDITOR_H
