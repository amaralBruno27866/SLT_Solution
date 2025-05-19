#pragma once

#include <QWidget.h>
#include "ui_ManageAssessor.h"

class ManageAssessor : public QWidget
{
	Q_OBJECT

public:
	explicit ManageAssessor(QWidget* parent = nullptr)
		: QWidget(parent)
	{
		ui.setupUi(this);
	}

private:
	Ui::Form ui;
};

