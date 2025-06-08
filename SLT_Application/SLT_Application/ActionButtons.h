#ifndef ACTION_BUTTONS
#define ACTION_BUTTONS

#include <QWidget>
#include "ui_ActionButtons.h"

namespace silver {
	class ActionButtons : public QWidget {
		Q_OBJECT
	public:
		explicit ActionButtons(QWidget* parent = nullptr);

		QToolButton* viewButton() const { return ui.btView; }
		QToolButton* editButton() const { return ui.btEdit; }
		QToolButton* deleteButton() const { return ui.btDelete; }

	private:
		Ui::actionButtons ui;
	};
}

#endif // !ACTION_BUTTONS

