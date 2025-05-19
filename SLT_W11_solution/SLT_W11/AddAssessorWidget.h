#include <qwidget.h>
#include "x64/Debug/qt/uic/ui_AddAssessorWidget.h"

namespace Ui {
	class AddAssessorWidget;
}

class AddAssessorWidget : public QWidget
{
	Q_OBJECT

public:
	explicit AddAssessorWidget(QWidget* parent = nullptr);
	~AddAssessorWidget();

private:
	Ui::AddAssessorWidget* ui;
};
