#include "SLT_Application.h"
#include "Assessor.h"
#include "ManageAssessor.h"
#include "Client.h"
#include "ManageClient.h"

using namespace silver;

SLT_Application::SLT_Application(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

SLT_Application::~SLT_Application()
{
}

void SLT_Application::on_actionAdd_a_new_assessor_triggered()
{
    Assessor* window = new Assessor(this);
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->setWindowFlags(Qt::Window);
    window->setFixedSize(utils::DEFAULT_WINDOW_WIDTH, utils::DEFAULT_WINDOW_HEIGHT);
    window->show();
}

void SLT_Application::on_actionManage_assessor_triggered()
{
    ManageAssessor* window = new ManageAssessor(this);
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->setWindowFlags(Qt::Window);
    window->setFixedSize(utils::DEFAULT_WINDOW_WIDTH, utils::DEFAULT_WINDOW_HEIGHT);
    window->show();
}

void silver::SLT_Application::on_actionAdd_a_new_client_triggered()
{
    Client* window = new Client(this);
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->setWindowFlags(Qt::Window);
    window->setFixedSize(utils::DEFAULT_WINDOW_WIDTH, utils::DEFAULT_WINDOW_HEIGHT);
	window->show();
}

void silver::SLT_Application::on_actionManage_client_triggered()
{
    ManageClient* window = new ManageClient(this);
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->setWindowFlags(Qt::Window);
    window->setFixedSize(utils::DEFAULT_WINDOW_WIDTH, utils::DEFAULT_WINDOW_HEIGHT);
	window->show();
}
