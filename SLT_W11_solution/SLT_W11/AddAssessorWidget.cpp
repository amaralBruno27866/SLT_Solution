#include "AddAssessorWidget.h"
#include "x64/Debug/qt/uic/ui_AddAssessorWidget.h"

AddAssessorWidget::AddAssessorWidget(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::AddAssessorWidget)
{
	ui->setupUi(this);
}

AddAssessorWidget::~AddAssessorWidget()
{
	delete ui;
}