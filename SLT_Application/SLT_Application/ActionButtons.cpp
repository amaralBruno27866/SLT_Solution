#define _CRT_SECURE_NO_WARNINGS

#include <QWidget>
#include <QPushButton>

#include "ActionButtons.h"

namespace silver {
	ActionButtons::ActionButtons(QWidget* parent) : QWidget(parent)
	{
		ui.setupUi(this);
	}
}
